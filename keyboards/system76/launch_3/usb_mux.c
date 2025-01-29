/*
 *  Copyright (C) 2021  System76
 *  Copyright (C) 2021  Jimmy Cassis <KernelOops@outlook.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "usb_mux.h"

#include <stdbool.h>

#include "gpio.h"
#include "i2c_master.h"
#include "wait.h"

#define GPIO_RESET_USB GP20

#define REG_PF1_CTL 0xBF800C04
#define REG_PIO64_OEN 0xBF800908
#define REG_PIO64_OUT 0xBF800928
#define REG_VID 0xBF803000
#define REG_PRT_SWAP 0xBF8030FA
#define REG_USB3_HUB_VID 0xBFD2E548
#define REG_RUNTIME_FLAGS2 0xBFD23408
#define REG_I2S_FEAT_SEL 0xBFD23412

struct USB7206 {
    uint8_t addr;
};

struct USB7206 usb_hub = {.addr = 0x2D};

// Perform USB7206 register access.
// Returns zero on success or a negative number on error.
i2c_status_t usb7206_register_access(struct USB7206* self) {
    uint8_t register_access[3] = {
        0x99,
        0x37,
        0x00,
    };

    return i2c_transmit(self->addr << 1, register_access, sizeof(register_access), I2C_TIMEOUT);
}

// Read 32-bit value from USB7206 register region.
// Returns number of bytes read on success or a negative number on error.
i2c_status_t usb7206_read_reg_32(struct USB7206* self, uint32_t addr, uint32_t* data) {
    i2c_status_t status;

    uint8_t register_read[9] = {
        0x00,                   // Buffer address MSB: always 0
        0x00,                   // Buffer address LSB: always 0
        0x06,                   // Number of bytes to write to command block buffer area
        0x01,                   // Direction: 0 = write, 1 = read
        4,                      // Number of bytes to read from register
        (uint8_t)(addr >> 24),  // Register address byte 3
        (uint8_t)(addr >> 16),  // Register address byte 2
        (uint8_t)(addr >> 8),   // Register address byte 1
        (uint8_t)(addr >> 0),   // Register address byte 0
    };

    // First byte is available length
    uint8_t bytes[5] = {0, 0, 0, 0, 0};

    status = i2c_transmit(self->addr << 1, register_read, sizeof(register_read), I2C_TIMEOUT);
    if (status < 0) {
        return status;
    }

    status = usb7206_register_access(self);
    if (status < 0) {
        return status;
    }

    status = i2c_readReg16(
        (self->addr << 1),
        0x006, // 6 to skip header
        bytes,
        sizeof(bytes),
        I2C_TIMEOUT
    );
    if (status < 0) {
        return status;
    }

    //TODO: check bytes[0] length

    // Convert from little endian
    *data =
        (((uint32_t)bytes[1]) << 0) |
        (((uint32_t)bytes[2]) << 8) |
        (((uint32_t)bytes[3]) << 16) |
        (((uint32_t)bytes[4]) << 24);

    return 4;
}

// Write 8-bit value to USB7206 register region.
// Returns number of bytes written on success or a negative number on error.
i2c_status_t usb7206_write_reg_8(struct USB7206* self, uint32_t addr, uint8_t data) {
    i2c_status_t status;

    uint8_t register_write[9 + 1] = {
        0x00,                   // Buffer address MSB: always 0
        0x00,                   // Buffer address LSB: always 0
        1 + 6,                  // Number of bytes to write to command block buffer area
        0x00,                   // Direction: 0 = write, 1 = read
        1,                      // Number of bytes to write to register
        (uint8_t)(addr >> 24),  // Register address byte 3
        (uint8_t)(addr >> 16),  // Register address byte 2
        (uint8_t)(addr >> 8),   // Register address byte 1
        (uint8_t)(addr >> 0),   // Register address byte 0
        data
    };

    status = i2c_transmit((self->addr << 1), register_write, sizeof(register_write), I2C_TIMEOUT);
    if (status < 0) {
        return status;
    }

    status = usb7206_register_access(self);
    if (status < 0) {
        return status;
    }

    return 1;
}

// Write 32-bit value to USB7206 register region.
// Returns number of bytes written on success or a negative number on error.
i2c_status_t usb7206_write_reg_32(struct USB7206* self, uint32_t addr, uint32_t data) {
    i2c_status_t status;

    uint8_t register_write[9 + 4] = {
        0x00,                   // Buffer address MSB: always 0
        0x00,                   // Buffer address LSB: always 0
        4 + 6,                  // Number of bytes to write to command block buffer area
        0x00,                   // Direction: 0 = write, 1 = read
        4,                      // Number of bytes to write to register
        (uint8_t)(addr >> 24),  // Register address byte 3
        (uint8_t)(addr >> 16),  // Register address byte 2
        (uint8_t)(addr >> 8),   // Register address byte 1
        (uint8_t)(addr >> 0),   // Register address byte 0
        (uint8_t)(data >> 0),
        (uint8_t)(data >> 8),
        (uint8_t)(data >> 16),
        (uint8_t)(data >> 24),
    };

    status = i2c_transmit((self->addr << 1), register_write, sizeof(register_write), I2C_TIMEOUT);
    if (status < 0) {
        return status;
    }

    status = usb7206_register_access(self);
    if (status < 0) {
        return status;
    }

    return 4;
}

// Initialize USB7206.
// Returns zero on success or a negative number on error.
int usb7206_init(struct USB7206* self) {
    i2c_status_t status;
    uint32_t     data;

    // DM and DP are swapped on ports 2 and 3
    status = usb7206_write_reg_8(self, REG_PRT_SWAP, 0x0C);
    if (status < 0) {
        return status;
    }

    // Disable audio
    status = usb7206_write_reg_8(self, REG_I2S_FEAT_SEL, 0);
    if (status < 0) {
        return status;
    }

    // Set HFC_DISABLE
    data   = 0;
    status = usb7206_read_reg_32(self, REG_RUNTIME_FLAGS2, &data);
    if (status < 0) {
        return status;
    }
    data |= 1;
    status = usb7206_write_reg_32(self, REG_RUNTIME_FLAGS2, data);
    if (status < 0) {
        return status;
    }

    // Set Vendor ID and Product ID of USB 2 hub
    status = usb7206_write_reg_32(self, REG_VID, 0x00033384);
    if (status < 0) {
        return status;
    }

    // Set Vendor ID and Product ID of USB 3 hub
    status = usb7206_write_reg_32(self, REG_USB3_HUB_VID, 0x00043384);
    if (status < 0) {
        return status;
    }

    return 0;
}

// Attach USB7206.
// Returns bytes written on success or a negative number on error.
i2c_status_t usb7206_attach(struct USB7206* self) {
    uint8_t data[3] = {
        0xAA,
        0x56,
        0x00,
    };

    return i2c_transmit(self->addr << 1, data, sizeof(data), I2C_TIMEOUT);
}

struct USB7206_GPIO {
    struct USB7206* usb7206;
    uint32_t        pf;
};

struct USB7206_GPIO usb_gpio_sink         = {.usb7206 = &usb_hub, .pf = 29};  // UP_SEL = PF29 = GPIO93
struct USB7206_GPIO usb_gpio_source_left  = {.usb7206 = &usb_hub, .pf = 10};  // CL_SEL = PF10 = GPIO74
struct USB7206_GPIO usb_gpio_source_right = {.usb7206 = &usb_hub, .pf = 25};  // CR_SEL = PF25 = GPIO88

// Set USB7206 GPIO to specified value.
// Returns zero on success or negative number on error.
i2c_status_t usb7206_gpio_set(struct USB7206_GPIO* self, bool value) {
    i2c_status_t status;
    uint32_t     data;

    data   = 0;
    status = usb7206_read_reg_32(self->usb7206, REG_PIO64_OUT, &data);
    if (status < 0) {
        return status;
    }

    if (value) {
        data |= (((uint32_t)1) << self->pf);
    } else {
        data &= ~(((uint32_t)1) << self->pf);
    }
    status = usb7206_write_reg_32(self->usb7206, REG_PIO64_OUT, data);
    if (status < 0) {
        return status;
    }

    return 0;
}

// Initialize USB7206 GPIO.
// Returns zero on success or a negative number on error.
i2c_status_t usb7206_gpio_init(struct USB7206_GPIO* self) {
    i2c_status_t status;
    uint32_t     data;

    // Set programmable function to GPIO
    status = usb7206_write_reg_8(self->usb7206, REG_PF1_CTL + (self->pf - 1), 0);
    if (status < 0) {
        return status;
    }

    // Set GPIO to false by default
    usb7206_gpio_set(self, false);

    // Set GPIO to output
    data   = 0;
    status = usb7206_read_reg_32(self->usb7206, REG_PIO64_OEN, &data);
    if (status < 0) {
        return status;
    }

    data |= (((uint32_t)1) << self->pf);
    status = usb7206_write_reg_32(self->usb7206, REG_PIO64_OEN, data);
    if (status < 0) {
        return status;
    }

    return 0;
}

#define TCPC_CC_STATUS 0x1D
#define TCPC_ROLE_CONTROL 0x1A
#define TCPC_COMMAND 0x23

enum TCPC_TYPE {
    TCPC_TYPE_SINK,
    TCPC_TYPE_SOURCE,
};

struct PTN5110 {
    enum TCPC_TYPE type;
    uint8_t addr;
    uint8_t cc;
    struct USB7206_GPIO * gpio;
};

struct PTN5110 usb_sink = { .type = TCPC_TYPE_SINK, .addr = 0x51, .gpio = &usb_gpio_sink };
struct PTN5110 usb_source_left = { .type = TCPC_TYPE_SOURCE, .addr = 0x52, .gpio = &usb_gpio_source_left };
struct PTN5110 usb_source_right = { .type = TCPC_TYPE_SOURCE, .addr = 0x50, .gpio = &usb_gpio_source_right };

// Read PTN5110 CC_STATUS
// Returns bytes read on success or negative number on error
int ptn5110_get_cc_status(struct PTN5110 * self, uint8_t * cc) {
    return i2c_readReg(self->addr << 1, TCPC_CC_STATUS, cc, 1, I2C_TIMEOUT);
}

// Write PTN5110 ROLE_CONTROL
// Returns bytes written on success or negative number on error
int ptn5110_set_role_control(struct PTN5110 * self, uint8_t role_control) {
    return i2c_writeReg(self->addr << 1, TCPC_ROLE_CONTROL, &role_control, 1, I2C_TIMEOUT);
}

// Set PTN5110 SSMUX orientation.
// Returns zero on success or a negative number on error.
i2c_status_t ptn5110_set_ssmux(struct PTN5110* self, bool orientation) { return usb7206_gpio_set(self->gpio, orientation); }

// Write PTN5110 COMMAND.
// Returns zero on success or negative number on error.
i2c_status_t ptn5110_command(struct PTN5110* self, uint8_t command) { return i2c_writeReg(self->addr << 1, TCPC_COMMAND, &command, 1, I2C_TIMEOUT); }

// Set orientation of PTN5110 operating as a sink, call this once.
// Returns zero on success or a negative number on error.
i2c_status_t ptn5110_sink_set_orientation(struct PTN5110* self) {
    i2c_status_t status;
    uint8_t      cc;

    status = ptn5110_get_cc_status(self, &cc);
    if (status < 0) {
        return status;
    }

    if ((cc & 0x03) == 0) {
        status = ptn5110_set_ssmux(self, false);
        if (status < 0) {
            return status;
        }
    } else {
        status = ptn5110_set_ssmux(self, true);
        if (status < 0) {
            return status;
        }
    }

    return 0;
}

// Update PTN5110 operating as a source, call this repeatedly.
// Returns zero on success or a negative number on error.
i2c_status_t ptn5110_source_update(struct PTN5110* self) {
    i2c_status_t status;
    uint8_t      cc;

    status = ptn5110_get_cc_status(self, &cc);
    if (status < 0) {
        return status;
    }

    if (cc != self->cc) {
        // WARNING: Setting this here will disable retries
        self->cc = cc;

        bool connected   = false;
        bool orientation = false;
        if ((cc & 0x03) == 2) {
            connected   = true;
            orientation = true;
        } else if (((cc >> 2) & 0x03) == 2) {
            connected   = true;
            orientation = false;
        }

        if (connected) {
            // Set SS mux orientation
            status = ptn5110_set_ssmux(self, orientation);
            if (status < 0) {
                return status;
            }

            // Enable source Vbus command
            status = ptn5110_command(self, 0b01110111);
            if (status < 0) {
                return status;
            }
        } else {
            // Disable source Vbus command
            status = ptn5110_command(self, 0b01100110);
            if (status < 0) {
                return status;
            }
        }
    }

    return 0;
}

// Initialize PTN5110
// Returns zero on success or negative number on error
int ptn5110_init(struct PTN5110 * self) {
    int res;

    // Set last cc to invalid value, to force update
    self->cc = 0xFF;

    // Initialize GPIO
    res = usb7206_gpio_init(self->gpio);
    if (res < 0) return res;

    switch (self->type) {
        case TCPC_TYPE_SINK:
            res = ptn5110_sink_set_orientation(self);
            if (res < 0) return res;
            break;
        case TCPC_TYPE_SOURCE:
            res = ptn5110_set_role_control(self, 0x05);
            if (res < 0) return res;
            break;
    }

    return 0;
}

void usb_mux_event(void) {
    // Run this on every 1000th matrix scan
    static int cycle = 0;
    if (cycle >= 1000) {
        cycle = 0;
        ptn5110_source_update(&usb_source_left);
        ptn5110_source_update(&usb_source_right);
    } else {
        cycle += 1;
    }
}

void usb_mux_init(void) {
    // Put the USB hub in reset
    setPinOutput(GPIO_RESET_USB);
    writePinLow(GPIO_RESET_USB);

    // Run I2C bus at 100 kHz
    i2c_init();

    // Wait for power stable
    wait_ms(10);

    // Take the USB hub out of reset
    writePinHigh(GPIO_RESET_USB);

    // Wait for USB hub to come out of reset
    wait_ms(100);

    // Set up hub
    usb7206_init(&usb_hub);

    // Set up sink
    ptn5110_init(&usb_sink);

    // Set up sources
    ptn5110_init(&usb_source_left);
    ptn5110_init(&usb_source_right);

    // Attach hub
    usb7206_attach(&usb_hub);

    // Ensure orientation is correct after attaching hub
    // TODO: Find reason why GPIO for sink orientation is reset
    for (int i = 0; i < 100; i++) {
        ptn5110_sink_set_orientation(&usb_sink);
        wait_ms(10);
    }
}
