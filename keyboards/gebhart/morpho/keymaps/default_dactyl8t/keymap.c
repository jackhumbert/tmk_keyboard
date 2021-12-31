/*
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
#include <stdio.h>
#include "morpho.h"

#define _BASE 0 // Base qwerty
#define _RAISE 1 // function keys, symbols, numbers

#define ___ KC_TRNS
#define xxx KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY
   * ,------------------------------------------------.      ,------------------------------------------------.
   * |  Ins |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |   -  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |   =  | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * | Pg Up| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Home | End  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * | Pg Dn| Pg Up| Ctrl | Alt  | GUI  |bkspc |Space |      |Space |Raise | Left | Down |  Up  | Right|   \  |
   * `------------------------------------------------'      `------------------------------------------------'
   */
  [_BASE] = LAYOUT_split_4x6_5_8(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
    KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_RBRC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,
    KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,
    KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_MINS,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,
    KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_HOME,

    KC_LSFT, CTL_T(KC_X), CTL_T(KC_C), KC_DOWN, KC_UP,
    KC_LEFT, KC_RIGHT, CTL_T(KC_V), xxx, KC_RSFT,

    KC_LALT, KC_LCTL,                KC_PGUP, KC_RALT,
    SFT_T(KC_TAB), KC_HOME, KC_END,  KC_PGDN, KC_RCTL, KC_TAB,
    KC_DEL, KC_BSPC, KC_ESC,         LT(_RAISE, KC_ENTER), KC_SPC, TT(_RAISE)
                           ),




  [_RAISE] = LAYOUT_split_4x6_5_8(
        KC_LBRC, KC_EXLM,   KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,
        KC_CIRC,  KC_AMPR,  KC_ASTR,   KC_LPRN,  KC_RPRN, KC_RBRC,
        ___, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_6, KC_7, KC_8, KC_9, KC_0, ___,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_NUHS, KC_NUBS, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___,
        KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE,
        ___,___,___,___,___,
        ___,___,___,___,___,___,___,___,
        ___,___,___,___,___,___,___,___
                                  ),

};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

void oled_render_layer_state(void) {
oled_write_P(PSTR("Layer: "), false);
 switch (layer_state) {
 case _BASE:
   oled_write_ln_P(PSTR("Default"), false);
   break;
 case _RAISE:
   oled_write_ln_P(PSTR("Raise"), false);
   break;
 }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
  oled_write(keylog_str, false);
}

void add_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
      (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode = keycode & 0xFF;
  }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
  oled_render_keylog();
}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}


__attribute__((weak)) void oled_render_logo(void) {
  // clang-format off
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
  // clang-format on
  oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    add_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
