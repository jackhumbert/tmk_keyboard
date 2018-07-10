/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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

/*
  Bottom Row Pins to columns group as:
  0 (LCtl) | 1 (LGui) | 2 (LAlt) | 3 (1u**) | 4 (LSplt) | 5 (Spc) | 6 (RSplt) | 8 (RAlt) |  9 (RGui)  |  10 (RCtrl) | 11 (1.25 Menu) | 12 (Left) | 13 (Down) | 14 (Right)
  1-3      |   4-6    |   7-10   |   11     |  12-13    | 14-18   |  19-20    | 21-23,25 |  24,26,29  | 27,28,32,33 |      30        |     31    |    34     |    35

  ** Can seemingly be used if all the bottom row keys besides space are 1u
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT( /* Base */
    KC_ESC,  RESET,   KC_F2,   KC_F3,  KC_F4, KC_F5,  KC_F6, KC_F7,   KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_DEL,  \
    KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,  KC_5,   KC_6,  KC_7,    KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NO,   KC_HOME, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,    KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, \
    KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,    KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,  KC_PGDN, \
    KC_LSFT, KC_NO,   KC_Z,    KC_X,   KC_C,  KC_V,   KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   LT(1, KC_END), \
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO,  KC_NO, KC_SPC, KC_NO, KC_RALT, KC_NO, KC_RCTL, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT \
  ),

  [1] = LAYOUT( /* Base */
    RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_NO,   KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  )

};
