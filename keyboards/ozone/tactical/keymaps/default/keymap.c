/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Philip Mourdjis
Copyright 2023 Pablo Martinez Bernal

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include "sendstring_spanish.h"

#define XXXXX KC_NO

enum layer_names {
    _QWERTY,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_iso(
                    KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,    ES_QUOT, ES_IEXL, KC_BSPC, ES_MORD,
                    KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,    ES_GRV,  ES_PLUS,          KC_DEL,
                    KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    ES_NTIL, ES_ACUT, ES_CCED, KC_ENT,  KC_VOLU,
                    KC_LSFT, ES_LABK, KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, ES_COMM, ES_DOT,  ES_MINS, KC_RSFT, KC_UP,   KC_VOLD,
                    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,             KC_ALGR, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
                ),

    [_FN] = LAYOUT_65_iso(
                QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  XXXXX,   KC_PSCR,
                XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,   XXXXX, XXXXX,            XXXXX,
                XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,   XXXXX, RGB_MOD, XXXXX,   XXXXX,
                XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, RGB_HUI, XXXXX, XXXXX,   RGB_VAI, XXXXX,
                XXXXX,   XXXXX, XXXXX,                      XXXXX,               XXXXX, KC_TRNS, XXXXX, RGB_SPD, RGB_VAD, RGB_SPI
            )
};

bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(29, RGB_WHITE);
    }
    return true;
}
