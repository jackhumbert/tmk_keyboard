/* Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "tractyl_manuform.h"
#include "transactions.h"
#include <string.h>

// i moved the charybdis config into here so we don't have duplicate 'void pointing_device_init_kb' calls
void pointing_device_init_kb(void) {
#ifdef PMW3360_CPI
    pointing_device_set_cpi(PMW3360_CPI);
#endif
    maybe_update_pointing_device_cpi(&g_charybdis_config);
}

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif  // CONSOLE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
// Fixed DPI for drag-scroll.
#    ifndef CHARYBDIS_DRAGSCROLL_DPI
#        define CHARYBDIS_DRAGSCROLL_DPI 100
#    endif  // CHARYBDIS_DRAGSCROLL_DPI

#    ifndef CHARYBDIS_DRAGSCROLL_BUFFER_SIZE
#        define CHARYBDIS_DRAGSCROLL_BUFFER_SIZE 6
#    endif  // !CHARYBDIS_DRAGSCROLL_BUFFER_SIZE

#    ifndef CHARYBDIS_POINTER_ACCELERATION_FACTOR
#        define CHARYBDIS_POINTER_ACCELERATION_FACTOR 24
#    endif  // !CHARYBDIS_POINTER_ACCELERATION_FACTOR

typedef union {
    uint8_t raw;
    struct {
        bool    is_dragscroll_enabled : 1;
    } __attribute__((packed));
} charybdis_config_t;

static charybdis_config_t g_charybdis_config = {0};

/**
 * \brief Set the value of `config` from EEPROM.
 *
 * Note that `is_dragscroll_enabled` and `is_sniping_enabled` are purposefully
 * ignored since we do not want to persist this state to memory.  In practice,
 * this state is always written to maximize write-performances.  Therefore, we
 * explicitly set them to `false` in this function.
 */
static void read_charybdis_config_from_eeprom(charybdis_config_t* config) {
    config->raw                   = eeconfig_read_kb() & 0xff;
    config->is_dragscroll_enabled = false;
}

/**
 * \brief Save the value of `config` to eeprom.
 *
 * Note that all values are written verbatim, including whether drag-scroll
 * and/or sniper mode are enabled.  `read_charybdis_config_from_eeprom(…)`
 * resets these 2 values to `false` since it does not make sense to persist
 * these across reboots of the board.
 */
static void write_charybdis_config_to_eeprom(charybdis_config_t* config) { eeconfig_update_kb(config->raw); }

/** \brief Set the appropriate DPI for the input config. */
static void maybe_update_pointing_device_cpi(charybdis_config_t* config) {
    if (config->is_dragscroll_enabled) {
        // all this does is overwrite the default dpi during dragscroll events
        pointing_device_set_cpi(CHARYBDIS_DRAGSCROLL_DPI);
    }
}

// check the config to see if dragscroll is turned on
bool charybdis_get_pointer_dragscroll_enabled(void) { return g_charybdis_config.is_dragscroll_enabled; }

// This is how we turn on dragscroll
void charybdis_set_pointer_dragscroll_enabled(bool enable) {
    // first, set config so that any further scans have dragscroll on
    g_charybdis_config.is_dragscroll_enabled = enable;
    // update the configured trackball dpi
    maybe_update_pointing_device_cpi(&g_charybdis_config);
}

// what does this do?? oh, tied to accel, which is presumably part of dragscroll
#    ifndef CONSTRAIN_HID
#        define CONSTRAIN_HID(value) ((value) < -127 ? -127 : ((value) > 127 ? 127 : (value)))
#    endif  // !CONSTRAIN_HID

/**
 * \brief Add optional acceleration effect.
 *
 * If `CHARYBDIS_ENABLE_POINTER_ACCELERATION` is defined, add a simple and naive
 * acceleration effect to the provided value.  Return the value unchanged
 * otherwise.
 */
#    ifndef DISPLACEMENT_WITH_ACCELERATION
        // only run this block if we've defined charybdis pointer accel
#        ifdef CHARYBDIS_POINTER_ACCELERATION_ENABLE
#            define DISPLACEMENT_WITH_ACCELERATION(d) (CONSTRAIN_HID(d > 0 ? d * d / CHARYBDIS_POINTER_ACCELERATION_FACTOR + d : -d * d / CHARYBDIS_POINTER_ACCELERATION_FACTOR + d))
#        else  // !CHARYBDIS_POINTER_ACCELERATION_ENABLE
#            define DISPLACEMENT_WITH_ACCELERATION(d) (d)
#        endif  // CHARYBDIS_POINTER_ACCELERATION_ENABLE
#    endif      // !DISPLACEMENT_WITH_ACCELERATION

/**
 * \brief Augment the pointing device behavior.
 *
 * Implement the Charybdis-specific features for pointing devices:
 *   - Drag-scroll
 *   - Sniping
 *   - Acceleration
 */
// function that pulls in the mouse_report data
static void pointing_device_task_charybdis(report_mouse_t* mouse_report) {
    static int16_t scroll_buffer_x = 0;
    static int16_t scroll_buffer_y = 0;
    // here it checks the charybdis config to see if dragscroll is enabled...
    // how would it be? ---> by 'charybdis_set_pointer_dragscroll_enabled' being executed
    if (g_charybdis_config.is_dragscroll_enabled) {
        // ok so if it's enabled...do this stuff
#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_X
        scroll_buffer_x -= mouse_report->x;
#    else
        scroll_buffer_x += mouse_report->x;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_X
#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_Y
        scroll_buffer_y -= mouse_report->y;
#    else
        scroll_buffer_y += mouse_report->y;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_Y
        mouse_report->x = 0;
        mouse_report->y = 0;
        // scroll accordingly
        if (abs(scroll_buffer_x) > CHARYBDIS_DRAGSCROLL_BUFFER_SIZE) {
            mouse_report->h = scroll_buffer_x > 0 ? 1 : -1;
            scroll_buffer_x = 0;
        }
        if (abs(scroll_buffer_y) > CHARYBDIS_DRAGSCROLL_BUFFER_SIZE) {
            mouse_report->v = scroll_buffer_y > 0 ? 1 : -1;
            scroll_buffer_y = 0;
        }
    }
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    // during the pointing device task function call, also exec the charybdis pointing task
    // if we have set dragscroll enabled, we'll get our dragscroll execution here
    pointing_device_task_charybdis(&mouse_report);
    // reset mouse_report
    mouse_report = pointing_device_task_user(mouse_report);

    return mouse_report;
}

// not sure what this is for...
#    if defined(POINTING_DEVICE_ENABLE) && !defined(NO_CHARYBDIS_KEYCODES)
/** \brief Whether SHIFT mod is enabled. */
static bool has_shift_mod(void) {
#        ifdef NO_ACTION_ONESHOT
    return mod_config(get_mods()) & MOD_MASK_SHIFT;
#        else
    return mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
#        endif  // NO_ACTION_ONESHOT
}
#    endif  // POINTING_DEVICE_ENABLE && !NO_CHARYBDIS_KEYCODES

/**
 * \brief Outputs the Charybdis configuration to console.
 *
 * Prints the in-memory configuration structure to console, for debugging.
 * Includes:
 *   - raw value
 *   - drag-scroll: on/off
 *   - sniping: on/off
 *   - default DPI: internal table index/actual DPI
 *   - sniping DPI: internal table index/actual DPI
 */
__attribute__((unused)) static void debug_charybdis_config_to_console(charybdis_config_t* config) {
#    ifdef CONSOLE_ENABLE
    dprintf("(charybdis) process_record_kb: config = {\n"
            "\traw = 0x%04X,\n"
            "\t{\n"
            "\t\tis_dragscroll_enabled=%b\n"
            "\t}\n"
            "}\n",
            config->raw, config->is_dragscroll_enabled);
#    endif  // CONSOLE_ENABLE
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
#    ifndef NO_CHARYBDIS_KEYCODES
    switch (keycode) {
        case DRAGSCROLL_MODE:
            //rgb_matrix_set_color_all(0, 90, 0);
            debug_charybdis_config_to_console(&g_charybdis_config);
            charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
            break;
        case DRAGSCROLL_MODE_TOGGLE:
            if (record->event.pressed) {
                //rgb_matrix_set_color_all(0, 90, 0);
                #ifdef CONSOLE_ENABLE
                    debug_enable = true;
                    dprintf("dragscroll mode toggled");
                    print("testing output");
                    debug_charybdis_config_to_console(&g_charybdis_config);
                #endif
                charybdis_set_pointer_dragscroll_enabled(!charybdis_get_pointer_dragscroll_enabled());
            }
            break;
    }
#    endif  // !NO_CHARYBDIS_KEYCODES
#    ifndef MOUSEKEY_ENABLE
    // Simulate mouse keys if full support is not enabled (reduces firmware size
    // while maintaining support for mouse keys).
    if (IS_MOUSEKEY_BUTTON(keycode)) {
        report_mouse_t mouse_report = pointing_device_get_report();
        mouse_report.buttons        = pointing_device_handle_buttons(mouse_report.buttons, record->event.pressed, keycode - KC_MS_BTN1);
        pointing_device_set_report(mouse_report);
        pointing_device_send();
    }
#    endif  // !MOUSEKEY_ENABLE
    return true;
}

void eeconfig_init_kb(void) {
    g_charybdis_config.raw = 0;
    write_charybdis_config_to_eeprom(&g_charybdis_config);
    maybe_update_pointing_device_cpi(&g_charybdis_config);
    eeconfig_init_user();
}

void matrix_power_up(void) { pointing_device_task(); }

void charybdis_config_sync_handler(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(g_charybdis_config)) {
        memcpy(&g_charybdis_config, initiator2target_buffer, sizeof(g_charybdis_config));
    }
}

void keyboard_post_init_kb(void) {
    transaction_register_rpc(RPC_ID_KB_CONFIG_SYNC, charybdis_config_sync_handler);
    #ifdef CONSOLE_ENABLE
        debug_enable = true;
        dprintf("dragscroll mode toggled");
    #endif
    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave
        static charybdis_config_t last_charybdis_config = {0};
        static uint32_t           last_sync             = 0;
        bool                      needs_sync            = false;

        // Check if the state values are different
        if (memcmp(&g_charybdis_config, &last_charybdis_config, sizeof(g_charybdis_config))) {
            needs_sync = true;
            memcpy(&last_charybdis_config, &g_charybdis_config, sizeof(g_charybdis_config));
        }
        // Send to slave every 500ms regardless of state change
        if (timer_elapsed32(last_sync) > 500) {
            needs_sync = true;
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_KB_CONFIG_SYNC, sizeof(g_charybdis_config), &g_charybdis_config)) {
                last_sync = timer_read32();
            }
        }
    }
    // no need for user function, is called already
}

#endif  // POINTING_DEVICE_ENABLE

__attribute__((weak)) void matrix_init_sub_kb(void) {}
void                       matrix_init_kb(void) {
#ifdef POINTING_DEVICE_ENABLE
    read_charybdis_config_from_eeprom(&g_charybdis_config);
#endif  // POINTING_DEVICE_ENABLE
    matrix_init_sub_kb();
    matrix_init_user();
}

__attribute__((weak)) void matrix_scan_sub_kb(void) {}
void                       matrix_scan_kb(void) {
    matrix_scan_sub_kb();
    matrix_scan_user();
}
