/*
Copyright 2017 Balz Guenat

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
#include "fc980c.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP(
    KC_ESC,      KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,                          KC_DEL, KC_INS, KC_PGUP,KC_PGDN,
    KC_GRV, KC_1,KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,                         KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,
    KC_TAB, KC_Q,KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,                         KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
    MO(1) , KC_A,KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,   KC_SCLN,KC_QUOT,        KC_ENT,                          KC_P4,  KC_P5,  KC_P6,
    KC_LSFT,     KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,         KC_UP,          KC_P1,  KC_P2,  KC_P3,  KC_PENT,
    KC_LCTL,KC_LGUI,KC_LALT,                     KC_SPC,                   KC_RALT,KC_RCTL,MO(1),   KC_LEFT,KC_DOWN,KC_RGHT,        KC_P0,  KC_PDOT
    ),
  [1] = KEYMAP(
    _______,        _______,_______,_______,_______,_______,_______,      _______,      _______,_______,_______,_______,_______,                        _______,_______,KC_HOME,KC_END,
    _______,_______,_______,_______,_______,_______,_______,_______,      _______,      _______,_______,_______,_______,_______,                        _______,_______,_______,_______,
    KC_CAPS,KC_MPRV,KC_VOLU,KC_MNXT,KC_PGUP,KC_INS,KC_HOME, LCTL(KC_LEFT),LCTL(KC_RGHT),KC_END, KC_PSCR,KC_SLCK,KC_PAUS,_______,                        _______,_______,_______,_______,
    _______,KC_MUTE,KC_VOLD,KC_MPLY,KC_PGDN,KC_DEL,KC_LEFT, KC_DOWN,      KC_UP,        KC_RGHT,_______,_______,        _______,                        _______,_______,_______,
    _______,        _______,_______,_______,_______,_______,LCTL(KC_BSPC),LCTL(KC_DEL), _______,_______,_______,        _______,         KC_PGUP,       _______,_______,_______,_______,
    _______,_______,_______,                           _______,                                         _______,KC_APP, _______, KC_HOME,KC_PGDN,KC_END,        _______,_______     
    ),
};

const uint16_t PROGMEM fn_actions[] = {
};
