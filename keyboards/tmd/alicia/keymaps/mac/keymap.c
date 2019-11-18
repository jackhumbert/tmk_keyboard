/* Copyright 2019 themillerdave
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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { 
                      TMDMSG = SAFE_RANGE, 
                      TMDURL 
                    };

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_default(
    KC_ESC,  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
    KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_PGDN, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
             KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RGUI,
             KC_LALT,          KC_LGUI, KC_SPC,  MO(_FN1),                          KC_SPC,           KC_RALT,          KC_RCTL
  ),

  [_FN1] = LAYOUT_default(
    RGB_TOG,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
    RGB_MOD,  _______,  _______, KC_UP,  _______, RESET,   _______,          RGB_SAI, RGB_HUI, RGB_VAI, _______, _______, _______, _______, _______,
    RGB_RMOD, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          RGB_SAD, RGB_HUD, RGB_VAD, _______, _______, _______,          _______,
              _______, BL_INC,  BL_DEC,  BL_TOGG, BL_BRTG, _______,          _______, _______, _______, _______, _______, TMDMSG, _______, _______,
              _______,          _______, _______, _______,                            _______,          _______,          RESET
  )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMDMSG:
            if (record->event.pressed) {
                // when keycode TMDMSG is pressed
                SEND_STRING("Alicia v0.1 - November 17, 2019 - a TGR Alice Homage, brought to you by themillerdave (TMD Keyboards)");
            } else {
                // when keycode TMDMSG is released
            }
            break;
        case TMDURL:
            if (record->event.pressed) {
                // when keycode TMDURL is pressed
                SEND_STRING("https://themillerdave.com/" SS_TAP(X_ENTER));
            } else {
                // when keycode TMDURL is released
            }
            break;
    }
    return true;
}
