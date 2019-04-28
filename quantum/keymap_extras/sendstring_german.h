/* Copyright 2018 Patrick Hener
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
/* Sendstring definitions for the German layout */
#ifndef SENDSTRING_GERMAN
#define SENDSTRING_GERMAN

#include "keymap_german.h"

const bool ascii_to_shift_lut[0x80] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,

    0, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 0
};

/* Until an ALT table/functionality is added, the following symbols will not work:
* § @ [ ] { } \ ~ äA öÖ ß ´
* Following characters can be printed using other characters like so:
* [ in makro will be ü
* { in makro will be Ü
* ~ in makro will be °
*/
const uint8_t ascii_to_keycode_lut[0x80] PROGMEM = {
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_BSPC, KC_TAB,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    KC_SPC,  KC_1,    KC_2,    DE_HASH, KC_4,    KC_5,    KC_6,    DE_HASH,
    KC_8,    KC_9,    DE_PLUS, DE_PLUS, KC_COMM, DE_MINS, KC_DOT,  KC_7,
    KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,
    KC_8,    KC_9,    KC_DOT,  KC_COMM, DE_LESS, KC_0,    DE_LESS, KC_MINS,
    KC_2,    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,
    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,    KC_M,    KC_N,    KC_O,
    KC_P,    KC_Q,    KC_R,    KC_S,    KC_T,    KC_U,    KC_V,    KC_W,
    KC_X,    DE_Y,    DE_Z,    KC_LBRC, KC_BSLS, KC_RBRC, DE_CIRC, DE_MINS,
    DE_ACUT, KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,
    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,    KC_M,    KC_N,    KC_O,
    KC_P,    KC_Q,    KC_R,    KC_S,    KC_T,    KC_U,    KC_V,    KC_W,
    KC_X,    DE_Y,    DE_Z,    KC_LBRC, KC_BSLS, KC_RBRC, KC_GRV,  KC_DEL
};

#endif
