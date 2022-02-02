#include QMK_KEYBOARD_H

#include "chrisgve.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY_MAC] = LAYOUT(
    KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CU_BSPC,
    TAB_CTL, A_MOUSE, KC_S,    M_NAV_1, M_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, QUT_SFT,
    ADJ_M,   TD_ADJM, KC_LALT, KC_LGUI, LOWER,   SPC_RSE, SPC_RSE, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  /*  BASE LAYER
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │ GEsc │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │ Bspc │
   * └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *  │TabCtl│   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │ Enter│
   *  └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *   │ SFT  │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │ '-SFT│
   *   └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *    │ Fn   │      │ LAlt │ LGUI │Lower │    Space    │ Raise│ Left │ Down │  Up  │ Right│
   *    └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
   */
  [FN]   = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_PGUP, KC_HOME, _______, _______,
    RGB_VAI, RGB_VAD, RESET,   KC_PSCR, _______, _______, _______, _______, KC_PGDN, KC_END,  _______, KC_DEL
  )
};  
  /*  FN LAYER
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │      │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │      │
   * └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *  │      │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │   -  │   =  │   [  │   ]  │   \  │
   *  └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *   │      │  F7  │  F8  │   F9 │  F10 │  F11 │  F12 │      │ PgUp │ Home │      │      │
   *   └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *    │LED V+│LED V-│ Reset│ PScr │      │             │      │ PgDn │ End  │      │ Del  │
   *    └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
   */
