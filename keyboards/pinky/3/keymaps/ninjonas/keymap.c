/* Copyright 2019 @ninjonas
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
#include "ninjonas.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
  //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
            _____________________QWERTY_L1______________________,  KC_MPLY,     KC_MUTE, _____________________QWERTY_R1______________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
            _____________________QWERTY_L2______________________,   T_LBRC,      T_RBRC, _____________________QWERTY_R2______________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
            _____________________QWERTY_L3______________________,   LT_RAI,      LT_LOW, _____________________QWERTY_R3______________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                   ________MOD_LEFT_________,       K_LAPP,   K_RAPP,   ________MOD_RIGHT________
                                //`---------------------------------------'  `---------------------------------------'
  ),

  [_DVORAK] = LAYOUT_wrapper(
  //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
            _____________________DVORAK_L1______________________,  KC_MPLY,     KC_MUTE, _____________________DVORAK_R1______________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
            _____________________DVORAK_L2______________________,   T_LBRC,      T_RBRC, _____________________DVORAK_R2______________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
            _____________________DVORAK_L3______________________,   LT_RAI,      LT_LOW, _____________________DVORAK_R3______________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                   ________MOD_LEFT_________,       K_LAPP,   K_RAPP,   ________MOD_RIGHT________
                                //`---------------------------------------'  `---------------------------------------'
  ),

  [_COLEMAK] = LAYOUT_wrapper(
  //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
            _____________________COLEMAK_L1_____________________,  KC_MPLY,     KC_MUTE, _____________________COLEMAK_R1_____________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
            _____________________COLEMAK_L2_____________________,   T_LBRC,      T_RBRC, _____________________COLEMAK_R2_____________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
            _____________________COLEMAK_L3_____________________,   LT_RAI,      LT_LOW, _____________________COLEMAK_R3_____________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                   ________MOD_LEFT_________,       K_LAPP,   K_RAPP,   ________MOD_RIGHT________
                                //`---------------------------------------'  `---------------------------------------'
  ),

  [_LOWER] = LAYOUT_wrapper(
  //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
       XXXXXXX,  XXXXXXX,  _________MEDIA_1_________,    XXXXXXX,   K_CSCN,     XXXXXXX, _______________NAV_1______________,      XXXXXXX,  K_MDSH,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  _________MEDIA_2_________,    XXXXXXX,  XXXXXXX,     XXXXXXX, _______________NAV_2______________,       K_LOCK,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        M_SHFT,  XXXXXXX,  _________MEDIA_3_________,    XXXXXXX,  _______,     _______,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,   M_ZOOM,   M_PYNV,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                        __________________________________,     _______,  _______,   M_CODE,  _______
                                //`---------------------------------------'  `---------------------------------------'
  ),

  [_RAISE] = LAYOUT_wrapper(
  //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
            _____________________NUM_LEFT_______________________,  XXXXXXX,     XXXXXXX,  _____________________NUM_RIGHT______________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
            _____________________SYM_LEFT_______________________,  XXXXXXX,     XXXXXXX,  _____________________SYM_RIGHT______________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
            _____________________FUNC_LEFT______________________,  _______,     _______,  _____________________FUNC_RIGHT_____________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                        __________________________________,     __________________________________
                                //`---------------------------------------'  `---------------------------------------'
  ),

  [_ADJUST] = LAYOUT_wrapper(
  //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
        M_MAKE,  EEP_RST,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  COLEMAK,   DVORAK,   QWERTY,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        M_VRSN,   M_MALL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  _____________________XXXXXXX________________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        M_FLSH,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,     _______,  _____________________XXXXXXX________________________,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                        __________________________________,     __________________________________
                                //`---------------------------------------'  `---------------------------------------'
  ),

  /*
  [_TEMPLATE] = LAYOUT(
  //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
       _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                     _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______
                                //`---------------------------------------'  `---------------------------------------'
  )
  */
};