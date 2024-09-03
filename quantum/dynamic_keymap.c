/* Copyright 2017 Jason Williams (Wilba)
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

#include "dynamic_keymap.h"
#include "keymap_introspection.h"
#include "action.h"
#include "eeprom.h"
#include "progmem.h"
#include "send_string.h"
#include "keycodes.h"
#include "nvm_dynamic_keymap.h"

#ifdef ENCODER_ENABLE
#    include "encoder.h"
#else
#    define NUM_ENCODERS 0
#endif

#ifndef DYNAMIC_KEYMAP_MACRO_DELAY
#    define DYNAMIC_KEYMAP_MACRO_DELAY TAP_CODE_DELAY
#endif

uint8_t dynamic_keymap_get_layer_count(void) {
    return DYNAMIC_KEYMAP_LAYER_COUNT;
}

uint16_t dynamic_keymap_get_keycode(uint8_t layer, uint8_t row, uint8_t column) {
    return nvm_dynamic_keymap_read_keycode(layer, row, column);
}

void dynamic_keymap_set_keycode(uint8_t layer, uint8_t row, uint8_t column, uint16_t keycode) {
    nvm_dynamic_keymap_update_keycode(layer, row, column, keycode);
}

#ifdef ENCODER_MAP_ENABLE
uint16_t dynamic_keymap_get_encoder(uint8_t layer, uint8_t encoder_id, bool clockwise) {
    return nvm_dynamic_keymap_read_encoder(layer, encoder_id, clockwise);
}

void dynamic_keymap_set_encoder(uint8_t layer, uint8_t encoder_id, bool clockwise, uint16_t keycode) {
    nvm_dynamic_keymap_update_encoder(layer, encoder_id, clockwise, keycode);
}
#endif // ENCODER_MAP_ENABLE

void dynamic_keymap_reset(void) {
    // Reset the keymaps in EEPROM to what is in flash.
    for (int layer = 0; layer < DYNAMIC_KEYMAP_LAYER_COUNT; layer++) {
        for (int row = 0; row < MATRIX_ROWS; row++) {
            for (int column = 0; column < MATRIX_COLS; column++) {
                dynamic_keymap_set_keycode(layer, row, column, keycode_at_keymap_location_raw(layer, row, column));
            }
        }
#ifdef ENCODER_MAP_ENABLE
        for (int encoder = 0; encoder < NUM_ENCODERS; encoder++) {
            dynamic_keymap_set_encoder(layer, encoder, true, keycode_at_encodermap_location_raw(layer, encoder, true));
            dynamic_keymap_set_encoder(layer, encoder, false, keycode_at_encodermap_location_raw(layer, encoder, false));
        }
#endif // ENCODER_MAP_ENABLE
    }
}

void dynamic_keymap_get_buffer(uint16_t offset, uint16_t size, uint8_t *data) {
    nvm_dynamic_keymap_read_buffer(offset, size, data);
}

void dynamic_keymap_set_buffer(uint16_t offset, uint16_t size, uint8_t *data) {
    nvm_dynamic_keymap_update_buffer(offset, size, data);
}

uint16_t keycode_at_keymap_location(uint8_t layer_num, uint8_t row, uint8_t column) {
    if (layer_num < DYNAMIC_KEYMAP_LAYER_COUNT && row < MATRIX_ROWS && column < MATRIX_COLS) {
        return dynamic_keymap_get_keycode(layer_num, row, column);
    }
    return KC_NO;
}

#ifdef ENCODER_MAP_ENABLE
uint16_t keycode_at_encodermap_location(uint8_t layer_num, uint8_t encoder_idx, bool clockwise) {
    if (layer_num < DYNAMIC_KEYMAP_LAYER_COUNT && encoder_idx < NUM_ENCODERS) {
        return dynamic_keymap_get_encoder(layer_num, encoder_idx, clockwise);
    }
    return KC_NO;
}
#endif // ENCODER_MAP_ENABLE

uint8_t dynamic_keymap_macro_get_count(void) {
    return DYNAMIC_KEYMAP_MACRO_COUNT;
}

uint16_t dynamic_keymap_macro_get_buffer_size(void) {
    return (uint16_t)nvm_dynamic_keymap_macro_size();
}

void dynamic_keymap_macro_get_buffer(uint16_t offset, uint16_t size, uint8_t *data) {
    nvm_dynamic_keymap_macro_read_buffer(offset, size, data);
}

void dynamic_keymap_macro_set_buffer(uint16_t offset, uint16_t size, uint8_t *data) {
    nvm_dynamic_keymap_macro_update_buffer(offset, size, data);
}

void dynamic_keymap_macro_reset(void) {
    nvm_dynamic_keymap_macro_reset();
}

static uint8_t dynamic_keymap_read_byte(uint32_t offset) {
    uint8_t d;
    nvm_dynamic_keymap_macro_read_buffer(offset, 1, &d);
    return d;
}

void dynamic_keymap_macro_send(uint8_t id) {
    if (id >= DYNAMIC_KEYMAP_MACRO_COUNT) {
        return;
    }

    // Check the last byte of the buffer.
    // If it's not zero, then we are in the middle
    // of buffer writing, possibly an aborted buffer
    // write. So do nothing.
    if (dynamic_keymap_read_byte(nvm_dynamic_keymap_macro_size() - 1) != 0) {
        return;
    }

    // Skip N null characters
    // p will then point to the Nth macro
    uint32_t offset = 0;
    uint32_t end    = nvm_dynamic_keymap_macro_size();
    while (id > 0) {
        // If we are past the end of the buffer, then there is
        // no Nth macro in the buffer.
        if (offset == end) {
            return;
        }
        if (dynamic_keymap_read_byte(offset) == 0) {
            --id;
        }
        ++offset;
    }

    // Send the macro string by making a temporary string.
    char data[8] = {0};
    // We already checked there was a null at the end of
    // the buffer, so this cannot go past the end
    while (1) {
        data[0] = dynamic_keymap_read_byte(offset++);
        data[1] = 0;
        // Stop at the null terminator of this macro string
        if (data[0] == 0) {
            break;
        }
        if (data[0] == SS_QMK_PREFIX) {
            // Get the code
            data[1] = dynamic_keymap_read_byte(offset++);
            // Unexpected null, abort.
            if (data[1] == 0) {
                return;
            }
            if (data[1] == SS_TAP_CODE || data[1] == SS_DOWN_CODE || data[1] == SS_UP_CODE) {
                // Get the keycode
                data[2] = dynamic_keymap_read_byte(offset++);
                // Unexpected null, abort.
                if (data[2] == 0) {
                    return;
                }
                // Null terminate
                data[3] = 0;
            } else if (data[1] == SS_DELAY_CODE) {
                // Get the number and '|'
                // At most this is 4 digits plus '|'
                uint8_t i = 2;
                while (1) {
                    data[i] = dynamic_keymap_read_byte(offset++);
                    // Unexpected null, abort
                    if (data[i] == 0) {
                        return;
                    }
                    // Found '|', send it
                    if (data[i] == '|') {
                        data[i + 1] = 0;
                        break;
                    }
                    // If haven't found '|' by i==6 then
                    // number too big, abort
                    if (i == 6) {
                        return;
                    }
                    ++i;
                }
            }
        }
        send_string_with_delay(data, DYNAMIC_KEYMAP_MACRO_DELAY);
    }
}
