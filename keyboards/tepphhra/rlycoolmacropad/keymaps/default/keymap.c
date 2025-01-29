/* Copyright 2024 Mikhail Filippov 
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
    [0] = LAYOUT(

    /*
     * ┌───┬───┬───┬──-─┐
     * │ 0 │ / │ * │ -  │
     * ├───┼───┼───┼──-─┤
     * │ 7 │ 8 │ 9 │ +  │
     * ├───┼───┼───┼──-─┤
     * │ 4 │ 5 │ 6 │ <- │
     * ├───┼───┼───┼──-─┤
     * │ 1 │ 2 │ 3 │ENTR│
     * └───────┴───┴──-─┘
     */

        KC_KP_0,   KC_KP_SLASH,   KC_KP_ASTERISK,   KC_KP_MINUS,
        KC_KP_7,   KC_KP_8,   KC_KP_9,   KC_KP_PLUS,
        KC_KP_4,   KC_KP_5,   KC_KP_6,   KC_BACKSPACE,
        KC_KP_1,   KC_KP_2,   KC_KP_3,   KC_KP_ENTER
    )
};
