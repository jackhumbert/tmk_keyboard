/* Copyright 2020 Pete Curt
 * Based on code by Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,	// 0
  _COLEMAK,	// 1
  _DVORAK,	// 2
  _NUMPAD,	// 3
  _SYMBOL,	// 4
  _ADJUST	// 5
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  BACKLIT,
  ABKPAIR,
  RBKPAIR,
  SBKPAIR,
  CBKPAIR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty 0
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * | LCtl |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |osl(5)|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Up   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | osm  | RCtl | Opt  | Cmd  |osl(4)| Entr | Spc  | tt(3)| Caps | Left | Rght | Down |
 * | Lsft |      |      |      |      |      |      |      | Rsft |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  LCTL_T(KC_ESC),
           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  OSL(_ADJUST),
           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
  OSM(MOD_LSFT),
           KC_RCTL, KC_LOPT, KC_LCMD, OSL(_SYMBOL),
                                               KC_ENT,  KC_SPC,  TT(_NUMPAD), RSFT_T(KC_CAPS),
                                                                                   KC_LEFT, KC_RGHT, KC_DOWN
),

/* Colemak 1
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * | LCtl |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |osl(5)|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Up   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | osm  | RCtl | Opt  | Cmd  |osl(4)| Entr | Spc  | tt(3)| Caps | Left | Rght | Down |
 * | Lsft |      |      |      |      |      |      |      | Rsft |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  LCTL_T(KC_ESC),
           KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  OSL(_ADJUST),
           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
  OSM(MOD_LSFT),
           KC_RCTL, KC_LOPT, KC_LCMD, OSL(_SYMBOL),
                                               KC_ENT,  KC_SPC,  TT(_NUMPAD), RSFT_T(KC_CAPS),
                                                                                   KC_LEFT, KC_RGHT, KC_DOWN
),

/* Dvorak 2
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * | LCtl |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |osl(5)|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Up   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | osm  | RCtl | Opt  | Cmd  |osl(4)| Entr | Spc  | tt(3)| Caps | Left | Rght | Down |
 * | Lsft |      |      |      |      |      |      |      | Rsft |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL,
  LCTL_T(KC_ESC),
           KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  OSL(_ADJUST),
           KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_UP,
  OSM(MOD_LSFT),
           KC_RCTL, KC_LOPT, KC_LCMD, OSL(_SYMBOL),
                                               KC_ENT,  KC_SPC,  TT(_NUMPAD), RSFT_T(KC_CAPS),
                                                                                   KC_LEFT, KC_RGHT, KC_DOWN
),

/* Numpad 3
 * ,-----------------------------------------------------------------------------------.
 * | ____ |      |      |   <  |   >  |  <|> |  =+  |   7  |   8  |   9  |   ^  | ____ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ____ |      |      |   (  |   )  |  (|) |  -_  |   4  |   5  |   6  |   %  | ____ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ____ |      |      |   [  |   ]  |  [|] |  *   |   1  |   2  |   3  | ____ | ____ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | ____ |      |  3   |   {  |   }  |  {|} |  /   |   0  | ____ | ____ | ____ | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      | Home | End  | PgDn |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_grid(
  _______, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, ABKPAIR, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_CIRC, _______,
  _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, RBKPAIR, KC_MINS, KC_4,    KC_5,    KC_6,    KC_PERC, _______,
  _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, SBKPAIR, KC_ASTR, KC_1,    KC_2,    KC_3,    _______, _______,
  _______, XXXXXXX, KC_3,    KC_LCBR, KC_RCBR, CBKPAIR, KC_SLSH, KC_0,    _______, _______, _______, KC_PGUP,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_HOME, KC_END,  KC_PGDN
),

/* Symbol 4
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |   =  |      |   !  |      |      |      |   _  |   |  |      |   %  | ____ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ____ |   @  |   *  |   $  |      |      |   #  |      |      |   +  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   4  |   ^  |      |   \  |   -  |   &  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ |      | ____ | ____ |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_grid(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_EQL,  _______, KC_EXLM, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PIPE, XXXXXXX, KC_PERC, _______,
  _______, KC_AT,   KC_ASTR, KC_DLR,  XXXXXXX, XXXXXXX, KC_HASH, XXXXXXX, XXXXXXX, KC_PLUS, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_4,    KC_CIRC, XXXXXXX, KC_BSLS, KC_MINS, KC_AMPR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust 5
 * Some of these are highly personal.  Please change to adapt to your own system.
 * ,-----------------------------------------------------------------------------------.
 * |      | F11  | F12  | F13  | F14  | F15  | F16  | F17  | F18  | F19  | F20  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |Print |      |
 * |      |      |      |      |      |      |      |      |      |      |screen|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ____ |      |Sleep |show  |      |      |finder|      |      |Lock  | rgb  |      |
 * |      |      |      |Dsktp |      |      |Hddn  |      |      |screen| 0/1  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |RESET |   5  |      |Virus |      |      | Mute | vol+ | rbg+ | rgb  | dsp+ |
 * |      |RESET |      |      |scan  |      |      |      |      |      | mode+|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ |      |      |      |      | vol- | rbg- | rgb  | dsp- |
 * |      |      |      |      |      |      |      |      |      |      | mode-|      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  XXXXXXX, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  XXXXXXX,
  _______, QWERTY,  COLEMAK, DVORAK,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SCMD(KC_5), XXXXXXX,
  XXXXXXX, XXXXXXX, C(LCMD(KC_PAUSE)),
                             LCMD(KC_F4),
                                      XXXXXXX, XXXXXXX, SCMD(KC_DOT),
                                                                 XXXXXXX, XXXXXXX, C(LCMD(KC_Q)), RGB_TOG, XXXXXXX,
  XXXXXXX, RESET,   KC_5,    XXXXXXX, SCMD(KC_V),
                                               XXXXXXX, XXXXXXX, KC__MUTE, KC__VOLUP,   RGB_VAI, RGB_MODE_FORWARD, LCAG(KC_UP),
  _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC__VOLDOWN, RGB_VAD, RGB_MODE_REVERSE, LCAG(KC_DOWN)
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
        case ABKPAIR:
          if (record->event.pressed) {
              SEND_STRING("<>"SS_TAP(X_LEFT));
          }
          break;
        case RBKPAIR:
          if (record->event.pressed) {
              SEND_STRING("()"SS_TAP(X_LEFT));
          }
          break;
        case SBKPAIR:
          if (record->event.pressed) {
              SEND_STRING("[]"SS_TAP(X_LEFT));
          }
          break;
        case CBKPAIR:
          if (record->event.pressed) {
              SEND_STRING("{}"SS_TAP(X_LEFT));
          }
          break;
      }
    return true;
};

