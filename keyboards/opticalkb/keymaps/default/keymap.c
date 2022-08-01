// Copyright 2022 Girish Palya (@girishji)
// SPDX-License-Identifier: GPL-2.0-or-later

// see https://github.com/qmk/qmk_firmware/blob/e1203a222bb12ab9733916164a000ef3ac48da93/keyboards/alu84/keymaps/default/keymap.c
//

#include QMK_KEYBOARD_H

bool     is_cmd_grv_active = false;
uint16_t cmd_grv_timer     = 0;

bool     is_cmd_tab_active = false;
uint16_t cmd_tab_timer     = 0;

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { QMKBEST = SAFE_RANGE, CMD_GRV, CMD_TAB };

// Defines names for use in layer keycodes and the keymap
enum layer_names { _BASE, _FN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(CMD_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_PGUP, KC_PGDN, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, OSL(_FN), OSM(MOD_LCTL), KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, OSM(MOD_RALT), OSM(MOD_LSFT), KC_GRV, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), KC_UP, KC_1, OSM(MOD_LALT), KC_BTN1, KC_CAPS, OSM(MOD_LSFT), OSM(MOD_LGUI), KC_BSPC, OSL(_FN), KC_SPC, KC_ENT, LGUI(KC_LEFT), LGUI(KC_RIGHT), OSM(MOD_RALT), KC_LEFT, KC_DOWN, KC_RIGHT),
    [_FN]   = LAYOUT(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_HOME, KC_END, _______, DYN_REC_STOP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DYN_REC_START1, DYN_MACRO_PLAY1, _______, _______, _______, LCMD(KC_LEFT), KC_PGDN, KC_PGUP, LCMD(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DYN_REC_START2, DYN_MACRO_PLAY2, _______, _______, _______, _______, _______, KC_WH_U, _______, RESET, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D, _______, RESET)};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            return false; // no more processing necessary

        case CMD_GRV:
            if (record->event.pressed) {
                if (!is_cmd_grv_active) {
                    is_cmd_grv_active = true;
                    register_code(KC_LGUI);
                }
                cmd_grv_timer = timer_read();
                register_code(KC_GRV);
            } else {
                unregister_code(KC_GRV);
            }
            return true;
        case CMD_TAB:
            if (record->event.pressed) {
                if (!is_cmd_tab_active) {
                    is_cmd_tab_active = true;
                    register_code(KC_LGUI);
                }
                cmd_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return true;
        case KC_CAPS:
            if (record->event.pressed) {
                ATOMIC_BLOCK_FORCEON {
                    setPinOutput(LED_CAPS_LOCK_PIN);
                    writePinHigh(LED_CAPS_LOCK_PIN);
                }
            } else {
                ATOMIC_BLOCK_FORCEON {
                    setPinOutput(LED_CAPS_LOCK_PIN);
                    writePinLow(LED_CAPS_LOCK_PIN);
                }
            }
            return true; // Let QMK process this further
        default:
            return true; // Process all other keycodes normally
    }
}

void matrix_scan_user(void) { // The very important timer.
    if (is_cmd_grv_active) {
        if (timer_elapsed(cmd_grv_timer) > 700) {
            unregister_code(KC_LGUI);
            is_cmd_grv_active = false;
        }
    } else if (is_cmd_tab_active) {
        if (timer_elapsed(cmd_tab_timer) > 700) {
            unregister_code(KC_LGUI);
            is_cmd_tab_active = false;
        }
    }
}

