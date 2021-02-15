/* Copyright 2021 icesoup
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     QMKBEST = SAFE_RANGE,
//     QMKURL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
<<<<<<< HEAD
        KC_A, 
        KC_B, KC_C, KC_D, 
        KC_E, KC_F, KC_G, 
        KC_H, KC_I, KC_J),
=======
        KC_F13, 
        KC_F14, KC_F15, KC_F16, 
        KC_F17, KC_F18, KC_F19, 
        KC_F20, KC_F21, KC_F22),
>>>>>>> 9db8823a8fcc3f8d39a53f0a8e57d5d8925498c2

    [_FN] = LAYOUT(
        RESET, 
        KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS)
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case QMKBEST:
//             if (record->event.pressed) {
//                 // when keycode QMKBEST is pressed
//                 SEND_STRING("QMK is the best thing ever!");
//             } else {
//                 // when keycode QMKBEST is released
//             }
//             break;
//         case QMKURL:
//             if (record->event.pressed) {
//                 // when keycode QMKURL is pressed
//                 SEND_STRING("https://qmk.fm/\n");
//             } else {
//                 // when keycode QMKURL is released
//             }
//             break;
//     }
//     return true;
// }
