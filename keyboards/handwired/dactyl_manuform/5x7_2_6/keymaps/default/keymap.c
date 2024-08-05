/*
Copyright 2012 Jun Wako <wakojun@gmail.com> Nikolai Grigoriev @ngrigoriev

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

#define _BASE       0   // default layer
#define _MAGIC      1
#define _NUMPAD     2
#define _FN         3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_5x7_2_6(
        // left hand
        KC_GRV,         KC_1,       KC_2,    KC_3,   KC_4,   KC_5,   MO(_MAGIC),
        KC_TAB,         KC_Q,       KC_W,    KC_E,   KC_R,   KC_T,   MO(_NUMPAD),
        KC_LCTL,        KC_A,       KC_S,    KC_D,   KC_F,   KC_G,   _______,
        OSM(MOD_LSFT),  KC_Z,       KC_X,    KC_C,   KC_V,   KC_B,
                        KC_PGUP,  KC_PGDN,
                                                KC_LCTL, LT(_FN, KC_ESC),
                                                            KC_UP, KC_DOWN,
                                                            KC_LCMD, KC_LALT,
        // right hand
                          KC_EQL,       KC_6,    KC_7,    KC_8,     KC_9,   KC_0,       KC_BSPC,
                          KC_MINUS,     KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,       KC_BSLS,
                          KC_DEL,       KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,    KC_QUOT,
                                        KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,    OSM(MOD_RSFT),
                                            KC_LBRC, KC_RBRC,
                        KC_ENTER, KC_SPC,
             KC_LEFT, KC_RIGHT,
             KC_RCTL, KC_RALT
    ),

    [_FN] = LAYOUT_5x7_2_6(
        // left hand
        _______,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,    MO(_MAGIC),
        _______,   _______,   _______,    KC_UP,    _______,   _______,  _______,
        _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RGHT,   _______,  QK_BOOT,
        _______,   _______,   _______,   _______,   _______,   _______,
                              KC_MPRV,   KC_MNXT,
                                    _______, _______,
                                        _______, _______,
                                        _______, _______,
        // right hand
                          _______,     KC_F6,     KC_F7,     KC_F8,    KC_F9,    KC_F10,    KC_F11,
                          _______,   _______,   _______,   _______,   _______,   _______,   KC_F12,
                          _______,   KC_LEFT,   KC_DOWN,    KC_UP,   KC_RIGHT,   _______,   _______,
                                     _______,   _______,   _______,   _______,   _______,   _______,
                                                           _______,   _______,
                KC_DEL, _______,
             _______, _______,
             _______, _______
    ),

    [_NUMPAD] = LAYOUT_5x7_2_6(
        // left hand
        _______,   _______,   _______,   _______,   _______,   _______,  MO(_MAGIC),
        _______,   _______,   _______,   _______,   _______,   _______,  _______,
        _______,   _______,   _______,   _______,   _______,   _______,  _______,
        _______,   _______,   _______,   _______,   _______,   _______,
                              _______,   _______,
                                    _______, _______,
                                        _______, _______,
                                        _______, _______,
        // right hand
                          _______,   _______,   KC_NUM,    _______,   KC_PMNS,   KC_PPLS,   _______,
                          _______,   _______,   KC_P7,     KC_P8,     KC_P9,     _______,   _______,
                          _______,   _______,   KC_P4,     KC_P5,     KC_P6,     KC_PAST,   _______,
                                     _______,   KC_P1,     KC_P2,     KC_P3,     KC_PSLS,   _______,
                                                           KC_P0,     KC_PDOT,
                _______, KC_PENT,
             _______, _______,
             _______, _______
    ),

    [_MAGIC] = LAYOUT_5x7_2_6(
        // left hand
        _______,   _______,   _______,   _______,   _______,   _______,     _______,
        _______,   _______,   _______,   _______,   _______,   _______,     _______,
        _______,   _______,   _______,   _______,   _______,   _______,     _______,
        _______,   _______,   _______,   _______,   _______,   _______,
                              _______,   _______,
                                    _______, _______,
                                        _______, _______,
                                        _______, _______,
        // right hand
                          CG_SWAP,   _______,   _______,    _______,   _______,   _______,   QK_REBOOT,
                          CG_NORM,   _______,   _______,     _______,     _______,     _______,   _______,
                          _______,   _______,   _______,     _______,     _______,     _______,   QK_BOOTLOADER,
                                     _______,   _______,     _______,     _______,     _______,   _______,
                                                           _______,     _______,
                _______, _______,
             _______, _______,
             _______, _______
    )
};

