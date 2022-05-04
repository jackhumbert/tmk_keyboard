/* Copyright 2022 durken (https://github.com/durken1/)
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

enum layers { 
    BASE, 
    MBO, 
    SYM, 
    NUM, 
    FN
};

#define NUM_SPC LT(NUM, KC_SPC)
#define FN_ENT LT(FN, KC_ENT)
#define SYM_BSP LT(SYM, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
  // Base
  //,--------------------------------------------,                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_ESC, NUM_SPC,  KC_TAB,     FN_ENT, SYM_BSP,  KC_DEL
                             //`--------------------------'  '--------------------------'

  ),


  [SYM] = LAYOUT(
  // Symbols
  //,--------------------------------------------,                    ,--------------------------------------------.
      _______, _______, KC_SLSH, KC_TILD, _______,                      _______, KC_PIPE, KC_BSLS, KC_CIRC, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_EXLM,  KC_DLR, KC_LPRN, KC_LBRC, _______,                      _______, KC_RBRC, KC_RPRN, KC_HASH, KC_QUES,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, KC_PERC, KC_LCBR, KC_LABK, _______,                      _______, KC_RABK, KC_RCBR, KC_AMPR, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   KC_AT,  KC_EQL, KC_DQUO,    _______, _______, _______
                             //`--------------------------'  '--------------------------'
  ),

  [NUM] = LAYOUT(
  // Numbers
  //,--------------------------------------------,                    ,--------------------------------------------.
      _______, _______, _______, _______, _______,                      _______,    KC_7,    KC_8,    KC_9, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,                      _______,    KC_4,    KC_5,    KC_6, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, KC_VOLD, KC_VOLU, _______,                       KC_SPC,    KC_1,    KC_2,    KC_3, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______,    KC_COMM,   KC_0,  KC_DOT
                             //`--------------------------'  '--------------------------'
  ),

  [FN] = LAYOUT(
  // FN
  //,--------------------------------------------,                    ,--------------------------------------------.
      _______, _______, _______, _______, _______,                      _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,                      _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_PSCR, KC_CAPS, _______,    _______, _______, _______
                             //`--------------------------'  '--------------------------'
  )
};
