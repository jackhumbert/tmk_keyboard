/* Copyright 2020 bemeier
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
   [0] = LAYOUT_all(
/* Default layer
┌─────┐ ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ F13 │ │ ESC │  1  │  2  │  3  │  4  │  5  │  6  │    │  7  │  8  │  9  │  0  │  -  │  =  │  \  │  `  │
├─────┤ ├─────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┘  ┌─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴─────┤
│ F14 │ │  TAB  │  Q  │  W  │  E  │  R  │  T  │      │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  BSPC │
├─────┤ ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     └─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤
│ F15 │ │  CTRL  │  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │  ;  │  '  │   ENTER   │
├─────┤ ├───────┬┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     ┌┴────┬┴────┬┴────┬┴────┬┴────┬┴────┬┴──────┬────┤
│ F16 │ │ SHFT  │`│  Z  │  X  │  C  │  V  │  B  │     │  B  │  N  │  M  │  ,  │  .  │  /  │  SHFT │ Fn │
└─────┘ └───────┴─┼─────┼─────┴┬────┴─────┴─────┤     ├─────┴─────┴────┬┴─────┼─────┼─────┴───────┴────┘
                  │ GUI │ ALT  │     SPACE      │     │   SPACE/Fn_1   │  ALT │ CTL │
                  └─────┴──────┴────────────────┘     └────────────────┴──────┴─────┘
*/
  KC_F13,  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  KC_F14,  KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_BSPC,
  KC_F15, KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,         KC_ENT,
  KC_F16, KC_LSFT,  KC_GRV,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,    MO(1),
                     KC_LGUI, KC_LALT,                KC_SPC,           LT(1, KC_SPC),          KC_RALT, KC_RCTL
), [1] = LAYOUT_all(
/* Function Layer 1: Nav
┌─────┐ ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ RST │ │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │    │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ INS │ DEL │
├─────┤ ├─────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┘  ┌─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴─────┤
│     │ │       │ END │  ^  │HOME │PGUP │     │      │     │     │     │     │ |>  │ <<  │ >>  │       │
├─────┤ ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     └─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤
│     │ │        │ <-  │  v  │ ->  │PGDN │     │       │ <-  │  v  │  ^  │ ->  │ o)  │ o)} │           │
├─────┤ ├───────┬┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     ┌┴────┬┴────┬┴────┬┴────┬┴────┬┴────┬┴──────┬────┤
│     │ │       │ │     │     │ CFG │     │ NUM │     │     │     │     │LDSKT│RDSKT│  Ø  │       │    │
└─────┘ └───────┴─┼─────┼─────┴┬────┴─────┴─────┤     ├─────┴─────┴────┬┴─────┼─────┼─────┴───────┴────┘
                  │     │      │                │     │                │      │     │
                  └─────┴──────┴────────────────┘     └────────────────┴──────┴─────┘
*/
 QK_BOOT, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
 _______, _______,    KC_END,   KC_UP, KC_HOME, KC_PGUP, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT,  _______,
 _______, _______,    KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,          KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_VOLD, KC_VOLU,        _______,
 _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, TG(4), XXXXXXX, XXXXXXX, TG(2), XXXXXXX, XXXXXXX, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)), KC_MUTE, _______,  _______,
                     _______, _______,               _______,                 _______,          _______, _______
), [2] = LAYOUT_all(
/* Function Layer 2: Numpad example
┌─────┐ ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │ │     │     │     │     │     │     │     │    │  7  │  8  │  9  │  0  │  -  │  +  │     │     │
├─────┤ ├─────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┘  ┌─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴─────┤
│     │ │       │     │     │     │     │     │      │  4  │  5  │  6  │     │  /  │  *  │     │       │
├─────┤ ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     └─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤
│     │ │        │     │     │     │     │     │       │  1  │  2  │  3  │     │     │     │ KP_ENTER  │
├─────┤ ├───────┬┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     ┌┴────┬┴────┬┴────┬┴────┬┴────┬┴────┬┴──────┬────┤
│     │ │       │ │     │     │     │     │     │     │ ___ │  0  │  .  │     │     │     │       │    │
└─────┘ └───────┴─┼─────┼─────┴┬────┴─────┴─────┤     ├─────┴─────┴────┬┴─────┼─────┼─────┴───────┴────┘
                  │     │      │                │     │                │      │     │
                  └─────┴──────┴────────────────┘     └────────────────┴──────┴─────┘
*/
 _______, _______, _______, _______, _______, _______, _______, _______,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_PMNS, KC_PPLS, _______, _______,
 _______, _______,   _______, _______, _______, _______, _______,        KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, KC_PSLS, KC_PAST, _______,  _______,
 _______, _______,    _______, _______, _______, _______, _______,          KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, _______, _______,        KC_PENT,
 _______, _______, _______, _______, _______, _______, _______, _______,   TG(2), KC_KP_0, KC_PDOT, _______, _______, _______, _______,  _______,
                     _______, _______,               _______,                 _______,          _______, _______
), [3] = LAYOUT_all(
/* Function Layer 3
┌─────┐ ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │ │     │     │     │     │     │     │     │    │     │     │     │     │     │     │     │     │
├─────┤ ├─────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┘  ┌─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴─────┤
│     │ │       │     │     │     │     │     │      │     │     │     │     │     │     │     │       │
├─────┤ ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     └─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤
│     │ │        │     │     │     │     │     │       │     │     │     │     │     │     │           │
├─────┤ ├───────┬┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     ┌┴────┬┴────┬┴────┬┴────┬┴────┬┴────┬┴──────┬────┤
│     │ │       │ │     │     │     │     │     │     │     │     │     │     │     │     │       │    │
└─────┘ └───────┴─┼─────┼─────┴┬────┴─────┴─────┤     ├─────┴─────┴────┬┴─────┼─────┼─────┴───────┴────┘
                  │     │      │                │     │                │      │     │
                  └─────┴──────┴────────────────┘     └────────────────┴──────┴─────┘
*/
 _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______,   _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,  _______,
 _______, _______,    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,        _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
                     _______, _______,               _______,                 _______,          _______, _______
), [4] = LAYOUT_all(
/* Function Layer 4: Firmware Config
┌─────┐ ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ RST │ │     │     │     │     │     │     │     │    │     │     │     │     │     │     │     │     │
├─────┤ ├─────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┘  ┌─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴───┬─┴─────┤
│     │ │       │ RGB │RGB+ │RGB- │HUE+ │HUE- │      │     │     │     │     │     │     │     │       │
├─────┤ ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     └─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤
│     │ │        │     │SPD+ │SPD- │SAT+ │SAT- │       │     │     │     │     │     │     │           │
├─────┤ ├───────┬┴┬────┴┬────┴┬────┴┬────┴┬────┴┐     ┌┴────┬┴────┬┴────┬┴────┬┴────┬┴────┬┴──────┬────┤
│     │ │       │ │     │     │ ___ │VAL+ │VAL- │     │     │     │     │     │     │     │       │    │
└─────┘ └───────┴─┼─────┼─────┴┬────┴─────┴─────┤     ├─────┴─────┴────┬┴─────┼─────┼─────┴───────┴────┘
                  │     │      │                │     │                │      │     │
                  └─────┴──────┴────────────────┘     └────────────────┴──────┴─────┘
*/
 QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 XXXXXXX, XXXXXXX,  UG_TOGG, UG_NEXT, UG_PREV,  UG_HUEU, UG_HUED,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
 XXXXXXX, XXXXXXX,    XXXXXXX, UG_SPDU, UG_SPDD, UG_SATU, UG_SATD,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TG(4), UG_VALU, UG_VALD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
                     XXXXXXX, XXXXXXX,               XXXXXXX,                 _______,          XXXXXXX, XXXXXXX
) };
