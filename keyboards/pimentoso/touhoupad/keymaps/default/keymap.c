/* Copyright 2019 Arda Kilicdagi
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT( /* Base */
        KC_LSFT, KC_Z, KC_C, KC_X, KC_LEFT, KC_DOWN, KC_RIGHT, KC_UP, KC_ENT, LT(1, KC_ESC)
    ),
    LAYOUT( /* RGB controls */
        KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_VAD, RGB_MOD, RGB_VAI, KC_NO, KC_NO
    )
};


void matrix_init_user(void) { }
