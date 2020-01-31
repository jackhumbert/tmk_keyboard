/* Copyright 2020 ninjonas
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper(
//  ,------—————————-------------------------------------.                                ,--------—————————-----------------------------------.
     _____________________QWERTY_L1______________________,                                 _____________________QWERTY_R1______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----|                                |------—+——------+——------+——------+——------+--------|
     _____________________QWERTY_L2______________________,                                 _____________________QWERTY_R2______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----+———-----------.  ,——————————————+------—+——------+——------+——------+——------+--------|
     _____________________QWERTY_L3______________________,XXXXXXX,KC_LALT,  M_COPA,XXXXXXX,_____________________QWERTY_R3______________________,
//  `--------------------------+--------+--------+-------+-------+------|  |------+-------+-------+--------+--------+--------+--------+--------'
                                _____________MOD_LEFT_____________,T_LBRC,  T_RBRC,________MOD_RIGHT________,KC_MUTE
//                             `----------------------------------------'  `----------------------------------------'
  ),

  [_DVORAK] = LAYOUT_wrapper(
//  ,------—————————-------------------------------------.                                ,--------—————————-----------------------------------.
     _____________________DVORAK_L1______________________,                                 _____________________DVORAK_R1______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----|                                |------—+——------+——------+——------+——------+--------|
     _____________________DVORAK_L2______________________,                                 _____________________DVORAK_R2______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----+———-----------.  ,——————————————+------—+——------+——------+——------+——------+--------|
     _____________________DVORAK_L3______________________,XXXXXXX,KC_LALT,  M_COPA,XXXXXXX,_____________________DVORAK_R3______________________,
//  `--------------------------+--------+--------+-------+-------+------|  |------+-------+-------+--------+--------+--------+--------+--------'
                                _____________MOD_LEFT_____________,T_LBRC,  T_RBRC,________MOD_RIGHT________,KC_MUTE
//                             `----------------------------------------'  `----------------------------------------'
  ),

  [_COLEMAK] = LAYOUT_wrapper(
//  ,------—————————-------------------------------------.                                ,--------—————————-----------------------------------.
     _____________________COLEMAK_L1_____________________,                                 _____________________COLEMAK_R1_____________________,
//  |--------+-----——-+——------+-——-----+——------+——-----|                                |------—+——------+——------+——------+——------+--------|
     _____________________COLEMAK_L2_____________________,                                 _____________________COLEMAK_R2_____________________,
//  |--------+-----——-+——------+-——-----+——------+——-----+———-----------.  ,——————————————+------—+——------+——------+——------+——------+--------|
     _____________________COLEMAK_L3_____________________,XXXXXXX,KC_LALT,  M_COPA,XXXXXXX,_____________________COLEMAK_R3_____________________,
//  `--------------------------+--------+--------+-------+-------+------|  |------+-------+-------+--------+--------+--------+--------+--------'
                                _____________MOD_LEFT_____________,T_LBRC,  T_RBRC,________MOD_RIGHT________,KC_MUTE
//                             `----------------------------------------'  `----------------------------------------'
  ),

  [_LOWER] = LAYOUT_wrapper(
//  ,------—————————-------------------------------------.                                ,--------—————————-----------------------------------.
     _____________________LOWER_L1_______________________,                                 _____________________LOWER_R1_______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----|                                |------—+——------+——------+——------+——------+--------|
     _____________________LOWER_L2_______________________,                                 _____________________LOWER_R2_______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----+———-----------.  ,——————————————+------—+——------+——------+——------+——------+--------|
     _____________________LOWER_L3_______________________,_______,_______, _______,_______,_____________________LOWER_R3_______________________,
//  `--------------------------+--------+--------+-------+-------+------|  |------+-------+-------+--------+--------+--------+--------+--------'
                                _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
//                             `----------------------------------------'  `----------------------------------------'
  ),

  [_RAISE] = LAYOUT_wrapper(
//  ,------—————————-------------------------------------.                                ,--------—————————-----------------------------------.
     _____________________NUM_LEFT_______________________,                                 _____________________NUM_RIGHT______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----|                                |------—+——------+——------+——------+——------+--------|
     _____________________SYM_LEFT_______________________,                                 _____________________SYM_RIGHT______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----+———-----------.  ,——————————————+------—+——------+——------+——------+——------+--------|
     _____________________FUNC_LEFT______________________,_______,_______, _______,_______,_____________________FUNC_RIGHT_____________________,
//  `--------------------------+--------+--------+-------+-------+------|  |------+-------+-------+--------+--------+--------+--------+--------'
                                _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
//                             `----------------------------------------'  `----------------------------------------'
  ),

  [_ADJUST] = LAYOUT_wrapper(
//  ,------—————————-------------------------------------.                                ,--------—————————-----------------------------------.
     _____________________ADJUST_L1______________________,                                 _____________________ADJUST_R1______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----|                                |------—+——------+——------+——------+——------+--------|
     _____________________ADJUST_L2______________________,                                 _____________________ADJUST_R2______________________,
//  |--------+-----——-+——------+-——-----+——------+——-----+———-----------.  ,——————————————+------—+——------+——------+——------+——------+--------|
     _____________________ADJUST_L3______________________,_______,_______, _______,_______,_____________________ADJUST_R3______________________,
//  `--------------------------+--------+--------+-------+-------+------|  |------+-------+-------+--------+--------+--------+--------+--------'
                                _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
//                             `----------------------------------------'  `----------------------------------------'
  ),
/*
  [_TEMPLATE] = LAYOUT_wrapper(
//  ,------—————————-------------------------------------.                                ,--------—————————-----------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  |--------+-----——-+——------+-——-----+——------+——-----|                                |------—+——------+——------+——------+——------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  |--------+-----——-+——------+-——-----+——------+——-----+———-----------.  ,——————————————+------—+——------+——------+——------+——------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  `--------------------------+--------+--------+-------+-------+------|  |------+-------+-------+--------+--------+--------+--------+--------'
                                 XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX
//                             `----------------------------------------'  `----------------------------------------'
  ),
*/
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
    // Converter: https://javl.github.io/image2cpp/
    // Image Dimensions: 128x64
    // Code Output Format: Plain Bytes
    // Draw Mode: Vertical, 1 bit per pixel
0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x00, 0x00, 0xe0, 
0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x80, 0xe0, 0xe0, 0xe0, 0xe0, 0x80, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 
0xe0, 0x00, 0x60, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0x80, 0x00, 0x00, 
0xc0, 0xe0, 0xe0, 0xe0, 0x20, 0x60, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 
0xe0, 0x00, 0x00, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 
0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0xe0, 0xe0, 0xfc, 0xfe, 
0xfe, 0xfe, 0xee, 0xee, 0x0e, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 
0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x79, 0xfd, 0xfd, 0xfd, 0xec, 0xee, 0x76, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
0x07, 0x3f, 0xff, 0xfc, 0xf8, 0xff, 0x7f, 0x07, 0x0f, 0x7f, 0xff, 0xf8, 0xfc, 0xff, 0x3f, 0x07, 
0x00, 0x00, 0x00, 0x03, 0x1f, 0xff, 0xfe, 0xf0, 0xff, 0x7f, 0x0f, 0x07, 0x3f, 0xff, 0xfc, 0xf8, 
0xff, 0x7f, 0x0f, 0x01, 0x00, 0x00, 0x01, 0x0f, 0x3f, 0xff, 0xfe, 0xf8, 0xff, 0xff, 0x1f, 0x03, 
0x00, 0x00, 0x1f, 0x7f, 0x7f, 0xff, 0xf6, 0xe6, 0xe6, 0xf7, 0xf7, 0x77, 0x37, 0x17, 0x00, 0x30, 
0x79, 0xfd, 0xfd, 0xfd, 0xee, 0xee, 0x76, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 
0xff, 0xff, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x7f, 0xff, 0xf1, 0xe0, 0xe0, 0xff, 0xff, 0x7f, 0x3f, 
0x0e, 0x00, 0x0e, 0x3f, 0x7f, 0xff, 0xff, 0xe0, 0xe0, 0xe1, 0xff, 0x7f, 0x7f, 0x3f, 0x04, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x0c, 0x3c, 0xfc, 0xfc, 0xfc, 0xc0, 0x00, 0xe0, 0xfc, 0xfc, 0x7c, 0x1c, 0x00, 0xf0, 0xf8, 
0xf8, 0xfc, 0xdc, 0xdc, 0xdc, 0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0x30, 0xb8, 0xbc, 0xbc, 
0xdc, 0xdc, 0xdc, 0xfc, 0xfc, 0xf8, 0xf0, 0x00, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0x1d, 0x1d, 
0x00, 0xf0, 0xf8, 0xf8, 0xfc, 0x3c, 0x1c, 0x1c, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0xe0, 0xf0, 
0xf8, 0xfc, 0x3c, 0x1c, 0x1c, 0x3c, 0xfc, 0xf8, 0xf8, 0xe0, 0x00, 0x00, 0x20, 0xb8, 0xbc, 0xbc, 
0xbc, 0xdc, 0xdc, 0xfc, 0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x0c, 0x7c, 0xfc, 0xfc, 0xc0, 0x00, 0xe0, 
0xfc, 0xfc, 0xfc, 0xfc, 0xf0, 0x80, 0x00, 0xf8, 0xfc, 0xfc, 0x3c, 0x04, 0x0c, 0x7c, 0xfc, 0xfc, 
0xf0, 0x00, 0xc0, 0xfc, 0xfc, 0x7c, 0xfc, 0xf8, 0xc0, 0x00, 0xf0, 0xfc, 0xfc, 0x7c, 0x0c, 0x00, 
0x00, 0x00, 0xc0, 0xc1, 0xc7, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x03, 0x00, 0x00, 0x00, 0x07, 0x0f, 
0x1f, 0x1f, 0x1e, 0x1c, 0x1c, 0x1e, 0x1e, 0x0e, 0x06, 0x00, 0x00, 0x06, 0x0f, 0x1f, 0x1f, 0x1f, 
0x1d, 0x1d, 0x0e, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 
0x00, 0x07, 0x0f, 0x0f, 0x1f, 0x1e, 0x1c, 0x1c, 0x1f, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x03, 0x07, 
0x0f, 0x1f, 0x1e, 0x1c, 0x1c, 0x1e, 0x1f, 0x0f, 0x0f, 0x03, 0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x1f, 
0x1d, 0x1d, 0x0c, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x1f, 0x1e, 0x1f, 
0x0f, 0x01, 0x00, 0x07, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 
0x1f, 0x1e, 0x1f, 0x1f, 0x03, 0x00, 0x03, 0x1f, 0x1f, 0x1e, 0x1f, 0x0f, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x80, 0xc1, 0xf1, 0xf9, 0xf9, 0xf9, 0xb8, 0xb8, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 
0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 
0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x7c, 0xfe, 0xff, 0xff, 0xc7, 0x83, 0x83, 
0xc7, 0xff, 0xff, 0xff, 0x7c, 0x00, 0x00, 0x7c, 0xff, 0xff, 0xff, 0xc7, 0x83, 0x83, 0xc7, 0xff, 
0xff, 0xfe, 0x7c, 0x00, 0xc0, 0xe6, 0xf7, 0xf7, 0xf7, 0xbb, 0xbb, 0xdb, 0xff, 0xff, 0xff, 0xfe, 
0x00, 0x00, 0x03, 0x1f, 0xff, 0xff, 0xf0, 0xe0, 0xfe, 0xff, 0x1f, 0x3f, 0xff, 0xfe, 0xe0, 0xf0, 
0xff, 0xff, 0x1f, 0x03, 0x00, 0x01, 0x0f, 0x7f, 0xff, 0xf8, 0xc0, 0xfc, 0xff, 0x3f, 0x1f, 0xff, 
0xfe, 0xf0, 0xe0, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x01, 0x07, 0x3f, 0xff, 0xff, 0xf8, 0xe0, 0xfc, 
0xff, 0x7f, 0x0f, 0x03, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xdb, 0x9b, 0x9b, 0xdf, 0xdf, 0xdf, 0xde, 
0x1c, 0x00, 0xc0, 0xe6, 0xf7, 0xf7, 0xf7, 0xbb, 0xbb, 0xdb, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 
0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 
0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 
0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x3f, 0x3f, 0x1f, 0x0f, 
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00
    };
    oled_write_raw_P(logo, sizeof(logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

void oled_white_space(void){
  oled_write_P(PSTR(" "), false);
}

static void render_status(void) {
     oled_write_P(PSTR("\nLayer: "), false);
     oled_write_P(PSTR("LOW"), (layer_state_is(_LOWER) & !layer_state_is(_ADJUST)));
     oled_white_space();
     oled_write_P(PSTR("RAI"), (layer_state_is(_RAISE) & !layer_state_is(_ADJUST)));
     oled_white_space();
     oled_write_P(PSTR("ADJ"), layer_state_is(_ADJUST));
}

void render_default_layer_state(void) {
  oled_write_P(PSTR("\nLayout: "), false);
  switch (biton32(default_layer_state)) {
      case _COLEMAK:
        oled_write_P(PSTR("Colemak"), false);
        break;
      case _DVORAK:
        oled_write_P(PSTR("Dvorak"), false);
        break;
      case _QWERTY:
        oled_write_P(PSTR("Qwerty"), false);
        break;
      default:
        oled_write_ln_P(PSTR("Undefined"), false);
  }
}

void render_mod_status(uint8_t modifiers) {
  oled_write_P(PSTR("\nMods: "), false);
  oled_write_P(PSTR("SHF"), (modifiers & MOD_MASK_SHIFT));
  oled_white_space();
  oled_write_P(PSTR("CTL"), (modifiers & MOD_MASK_CTRL));
  oled_white_space();
  oled_write_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
  oled_white_space();
  oled_write_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_qmk_logo();
        render_default_layer_state();
        render_status();
        render_mod_status(get_mods()|get_oneshot_mods());
    } else {
        render_logo();
        oled_scroll_left();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _LOWER:
                if (clockwise) {
                    tap_code16(SGUI(KC_TAB));
                } else {
                    tap_code16(LGUI(KC_TAB));
                }
                break;
            case _RAISE:
                if (clockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDN);
                }
                break;
            case _ADJUST:
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
                break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case _LOWER:
                if (!clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
                break;
            case _RAISE:
                if (!clockwise) {
                    tap_code16(LCTL(KC_TAB));
                } else {
                    tap_code16(LCTL(LSFT(KC_TAB)));
                }
                break;
            case _ADJUST:
                if (!clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
                break;
            default:
                if (!clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
}
#endif