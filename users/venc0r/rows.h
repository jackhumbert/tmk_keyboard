// Copyright 2021 Jörg Markert (@venc0r)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "venc0r.h"

#define RAISE LT(_RAISE, KC_SPC)
#define SHIFT LSFT_T(KC_SPC)
#define LOWER LT(_LOWER, KC_BSPC)
#define CTRL  LCTL_T(KC_BSPC)

#define HOME_A GUI_T(KC_A)
#define HOME_S ALT_T(KC_S)
#define HOME_H CTL_T(KC_H)
#define HOME_T SFT_T(KC_T)
#define HOME_N RSFT_T(KC_N)
#define HOME_E CTL_T(KC_E)
#define HOME_O RALT_T(KC_O)
#define HOME_I RGUI_T(KC_I)

#define C_HOME_A GUI_T(KC_A)
#define C_HOME_R ALT_T(KC_R)
#define C_HOME_S CTL_T(KC_S)
#define C_HOME_T SFT_T(KC_T)
#define C_HOME_N RSFT_T(KC_N)
#define C_HOME_E CTL_T(KC_E)
#define C_HOME_I RALT_T(KC_I)
#define C_HOME_O RGUI_T(KC_O)

#define DEGREE RSA(KC_SCLN)
#define EURO RALT(KC_5)
#define PARA S(RALT(KC_S))
#define WORDJ C(KC_RGHT)
#define WORDJB C(KC_LEFT)
#define BSPCW C(KC_W)
#define DELWRD C(KC_DEL)

#define ST_CTAB LCTL_T(KC_TAB)
#define ST_SSPC SFT_T(KC_SPC)
#define ST_CENT LCTL_T(KC_ENT)
#define ST_SBSP SFT_T(KC_BSPC)

#define I3_PP C(A(S(G(KC_SPC))))

// stolen from drashna
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       HOME_A,  HOME_S,  HOME_H, HOME_T,   KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    HOME_N,  HOME_E,  HOME_O,  HOME_I
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH


/* COLEMAK layer
 *
 * ,-----------------------------.        ,-----------------------------.
 * |  q  |  w  |  f  |  p  |  b  |        |  j  |  l  |  u  |  z  |  ;  |
 * |-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----|
 * | w^a | a^r | c^s | s^t |  g  |        |  m  | s^n | c^e | a^i | w^o |
 * |-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----|
 * |  y  |  x  |  c  |  d  |  v  |        |  k  |  h  |  ,  |  .  |  /  |
 * `-----------------------------'        `-----------------------------'
 */
#define ______________HM_COLEMAK_L1________________       KC_Q,     KC_W,     KC_F,     KC_P,     KC_B
#define ______________HM_COLEMAK_L2________________       C_HOME_A, C_HOME_R, C_HOME_S, C_HOME_T, KC_G
#define ______________HM_COLEMAK_L3________________       KC_Y,     KC_X,     KC_C,     KC_D,     KC_V

#define ______________HM_COLEMAK_R1________________       KC_J,     KC_L,     KC_U,     KC_Z,     KC_SCLN
#define ______________HM_COLEMAK_R2________________       KC_M,     C_HOME_N, C_HOME_E, C_HOME_I, C_HOME_O
#define ______________HM_COLEMAK_R3________________       KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLASH


/* Thumb keys sweep  ,-----------.        ,-----------.
 *                   | TAB | SPC |        | BSP | ENT |
 *                   `-----------'        `-----------'
 */
#define ____THUMB_L____ KC_TAB, RAISE
#define ____THUMB_R____ LOWER, KC_ENT


/* Lower layer
 *
 * ,-----------------------------.        ,-----------------------------.
 * |  1  |  @  |  #  |  $  |  %  |        |  ^  |  |  |  &  |  §  |  0  |
 * |-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----|
 * | ESC |  [  |  (  |  {  |  ~  |        |  _  |  }  |  )  |  ]  |  *  |
 * |-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----|
 * |  !  |  °  |  "  |  '  |  `  |        |  -  |  +  |  =  |  €  |  \  |
 * `-----------------------------'        `-----------------------------'
 */
#define _________________SYMBOL_L1_________________           KC_1, S(KC_2), S(KC_3), S(KC_4), S(KC_5)
#define _________________SYMBOL_L2_________________         KC_ESC, KC_LBRC, S(KC_9), KC_LCBR, KC_TILD
#define _________________SYMBOL_L3_________________        S(KC_1),  DEGREE,  KC_DQT, KC_QUOT, KC_GRAVE

#define _________________SYMBOL_R1_________________        S(KC_6), KC_PIPE, S(KC_7),    PARA, KC_0
#define _________________SYMBOL_R2_________________        KC_UNDS, KC_RCBR, S(KC_0), KC_RBRC, S(KC_8)
#define _________________SYMBOL_R3_________________        KC_MINS, KC_PLUS,  KC_EQL,    EURO, KC_BSLS

/* Raise/nav
 * ,-----------------------------.          ,-----------------------------.
 * |     |Word |     |     |Back |          |Down |Right|  7  |  8  |  9  |
 * |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
 * | ESC |     |PGUP |BSPCW|DelW |          |     |  0  |  4  |  5  |  6  |
 * |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
 * | TAB |Home |PGDN | End | Del |          | Up  |Left |  1  |  2  |  3  |
 * `-----------------------------'          `-----------------------------'
 */
#define _________________NAV_L1____________________       _______, WORDJ,   _______, _______, WORDJB
#define _________________NAV_L2____________________       KC_ESC,  _______, KC_PGUP, BSPCW,   DELWRD
#define _________________NAV_L3____________________       KC_TAB,  KC_HOME, KC_PGDN, KC_END,  KC_DEL

#define _________________NAV_R1____________________       KC_DOWN, KC_RGHT, KC_7,    KC_8,    KC_9
#define _________________NAV_R2____________________       _______, KC_0,    KC_4,    KC_5,    KC_6
#define _________________NAV_R3____________________       KC_UP,   KC_LEFT, KC_1,    KC_2,    KC_3


/* Adjust/whatever
 * ,-----------------------------.          ,-----------------------------.
 * | F1  | F2  | F3  | F4  | F5  |          | F6  | F7  | F8  | F9  | F10 |
 * |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
 * | F11 |     |     |     |     |          | DT_U|     |     |     | F12 |
 * |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
 * |     |     |     |     | DT  |          | DT_D|     |     |     |     |
 * `-----------------------------'          `-----------------------------'
 */
#define _________________ADJUST_L1_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________ADJUST_L2_________________       KC_F11,  _______, _______, _______, _______
#define _________________ADJUST_L3_________________       _______, _______, _______, _______, DT_PRNT // DF(_ALPHA), DF(_GAME)

#define _________________ADJUST_R1_________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _________________ADJUST_R2_________________       DT_UP,   _______, _______, _______, KC_F12
#define _________________ADJUST_R3_________________       DT_DOWN, _______, _______, _______, _______


/* COLEMAK sofle layer
 *
 * ,-----------------------------------.                    ,-----------------------------------.
 * |     |  1  |  2  |  3  |  4  |  5  |                    |  6  |  7  |  8  |  9  |  0  |     |
 * |-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
 * |     |  q  |  w  |  f  |  p  |  b  |                    |  j  |  l  |  u  |  z  |  ;  |     |
 * |-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
 * |     | w^a | a^r | c^s | s^t |  g  |                    |  m  | s^n | c^e | a^i | w^o |     |
 * |-----+-----+-----+-----+-----+-----+-----.        ,-----+-----+-----+-----+-----+-----+-----|
 * |     |  y  |  x  |  c  |  d  |  v  |MUTE |        | FCK |  h  |  h  |  ,  |  .  |  /  |     |
 * `-----------------------------------------'        `-----------------------------------------'
 */
/* Thumb keys sofle
 *          ,-----------------------------.              ,-----------------------------.
 *          |     | ALT |TAB/C|SPC/L|SPC/S|              |BSP/S|BSP/R|ENT/C|ALTGr|     |
 *          `-----------------------------'              `-----------------------------'
 */
#define _______________S_COLEMAK_L0________________       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _______________S_COLEMAK_L1________________       _______, ______________HM_COLEMAK_L1________________
#define _______________S_COLEMAK_L2________________       _______, ______________HM_COLEMAK_L2________________
#define _______________S_COLEMAK_L3________________       _______, ______________HM_COLEMAK_L3________________, KC_KB_MUTE
#define __S_THUMB_L____                                                     KC_LGUI, KC_LALT, ST_CTAB,   RAISE, ST_SSPC

#define _______________S_COLEMAK_R0________________                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______
#define _______________S_COLEMAK_R1________________                ______________HM_COLEMAK_R1________________, _______
#define _______________S_COLEMAK_R2________________                ______________HM_COLEMAK_R2________________, _______
#define _______________S_COLEMAK_R3________________         I3_PP, ______________HM_COLEMAK_R3________________, _______
#define __S_THUMB_R____                                   ST_SBSP,   LOWER, ST_CENT, KC_RALT, _______

#define __S_THUMB_N____                                   _______,  _______, _______,  _______,  _______

/* LOWER sofle layer
 *
 * ,-----------------------------------.                     ,-----------------------------------.
 * |     |     |     |     |     |     |                     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----|                     |-----+-----+-----+-----+-----+-----|
 * |     |  !  |  @  |  #  |  $  |  %  |                     |  ^  |  &  |  *  |  (  |  )  |     |
 * |-----+-----+-----+-----+-----+-----|                     |-----+-----+-----+-----+-----+-----|
 * |     | ESC |  `  |  [  |  ]  |  +  |                     |  |  |  -  |  =  |  _  |  €  |     |
 * |-----+-----+-----+-----+-----+-----+-----.         ,-----+-----+-----+-----+-----+-----+-----|
 * |     | TAB |  °  |  {  |  }  |  ~  |     |         |     |  '  |  "  |  *  |  %  |  \  |     |
 * `-----------------------------------------'         `-----------------------------------------'
 */
#define _______________S_SYMBOL_L0_________________       _______, _______, _______, _______, _______, _______
#define _______________S_SYMBOL_L1_________________       _______, _________________SYMBOL_L1_________________
#define _______________S_SYMBOL_L2_________________       _______, _________________SYMBOL_L2_________________
#define _______________S_SYMBOL_L3_________________       _______, _________________SYMBOL_L3_________________, _______

#define _______________S_SYMBOL_R0_________________                _______, _______, _______, _______, _______, _______
#define _______________S_SYMBOL_R1_________________                _________________SYMBOL_R1_________________, _______
#define _______________S_SYMBOL_R2_________________                _________________SYMBOL_R2_________________, _______
#define _______________S_SYMBOL_R3_________________       _______, _________________SYMBOL_R3_________________, _______


/* RAISE sofle layer
 *
 * ,-----------------------------------.                      ,-----------------------------------.
 * |     |     |     |     |     |     |                      |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----+-----|
 * |     |     |Word |     |     |Back |                      |Down |Right|  7  |  8  |  9  |     |
 * |-----+-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----+-----|
 * |     | ESC |     |PGUP |BSPCW|DelW |                      |     |  0  |  4  |  5  |  6  |     |
 * |-----+-----+-----+-----+-----+-----+-----.          ,-----|-----+-----+-----+-----+-----+-----|
 * |     | TAB |Home |PGDN | End | Del |     |          |     | Up  |Left |  1  |  2  |  3  |     |
 * `-----------------------------------------'          `-----`-----------------------------------'
 */
#define _______________S_NAV_L0____________________       _______, _______, _______, _______, _______, _______
#define _______________S_NAV_L1____________________       _______, _________________NAV_L1____________________
#define _______________S_NAV_L2____________________       _______, _________________NAV_L2____________________
#define _______________S_NAV_L3____________________       _______, _________________NAV_L3____________________, _______

#define _______________S_NAV_R0____________________                _______, _______, _______, _______, _______, _______
#define _______________S_NAV_R1____________________                _________________NAV_R1____________________, _______
#define _______________S_NAV_R2____________________                _________________NAV_R2____________________, _______
#define _______________S_NAV_R3____________________       _______, _________________NAV_R3____________________, _______


/* Adjust/whatever sofle layer
 * ,-----------------------------------.                      ,-----------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  |                      | F6  | F7  | F8  | F9  | F10 |     |
 * |-----+-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----+-----|
 * |     | F11 |     |     |     |     |                      |     |     |     |     | F12 |     |
 * |-----+-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |                      | DT_U| V+  |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----.          ,-----|-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     | DT  |     |          |     | DT_D| V-  |     |     |     |     |
 * `-----------------------------------------'          `-----------------------------------------'
 */
#define _______________S_ADJUST_L0_________________       _______, _______, _______, _______, _______, _______
#define _______________S_ADJUST_L1_________________       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _______________S_ADJUST_L2_________________       _______, KC_F11,  _______, _______, _______, _______
#define _______________S_ADJUST_L3_________________       _______, _______, _______, _______, _______, DT_PRNT, _______

#define _______________S_ADJUST_R0_________________                _______, _______,           _______, _______, _______,    _______
#define _______________S_ADJUST_R1_________________                KC_F6,   KC_F7,             KC_F8,   KC_F9,   KC_F10,    _______
#define _______________S_ADJUST_R2_________________                KC_KB_VOLUME_UP,   _______, _______, _______, KC_F12,   _______
#define _______________S_ADJUST_R3_________________       _______, KC_KB_VOLUME_DOWN, _______, _______, _______, DF(_GAME), _______

/* Game layer
 * ,-----------------------------------.                      ,-----------------------------------.
 * |     | ESC |  1  |  2  |  3  |  4  |                      |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----+-----|
 * |     | TAB |  Q  |  W  |  E  |  R  |                      |  P  |  L  |  G  |     | CM  |     |
 * |-----+-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----+-----|
 * |     | SHI |  A  |  S  |  D  |  F  |                      |  I  | V+  |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----.          ,-----|-----+-----+-----+-----+-----+-----|
 * |     | CTL |  Y  |  X  |  C  |  V  |     |          |     |  M  | V-  |     |     |     |     |
 * `-----------------------------------------'          `-----------------------------------------'
 */
/* Thumb keys sofle
 *          ,-----------------------------.              ,-----------------------------.
 *          |     |     | BSPC|SPACE|ENTER|              |     |     |     |     |     |
 *          `-----------------------------'              `-----------------------------'
 */
#define _______________S_GAME_L0___________________       _______, KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4
#define _______________S_GAME_L1___________________       _______, KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R
#define _______________S_GAME_L2___________________       _______, KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F
#define _______________S_GAME_L3___________________       _______, KC_LCTL,  KC_Y,    KC_X,    KC_C,    KC_V, _______
#define __S_G_THUMB_L__                                                      _______, _______, KC_BSPC, KC_SPC,  KC_ENT

#define _______________S_GAME_R0___________________                _______,  _______,           _______, _______, _______,    _______
#define _______________S_GAME_R1___________________                KC_P,     KC_L,              KC_G,    _______, _______,    _______
#define _______________S_GAME_R2___________________                KC_I,     KC_KB_VOLUME_UP,   _______, _______, _______,    _______
#define _______________S_GAME_R3___________________       _______, KC_M,     KC_KB_VOLUME_DOWN, _______, _______, DF(_ALPHA), _______
#define __S_G_THUMB_R__                                   _______, _______,  _______,           _______, _______

/* COLEMAK Scylla layer
 *
 * ,-----------------------------------.        ,-----------------------------------.
 * |     |  1  |  2  |  3  |  4  |  5  |        |  6  |  7  |  8  |  9  |  0  |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     |  q  |  w  |  f  |  p  |  b  |        |  j  |  l  |  u  |  z  |  ;  |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * | ESC |  a  |  r  |  s  |  t  |  g  |        |  m  |  n  |  e  |  i  |  o  | GUI |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * | SFT |  y  |  x  |  c  |  d  |  v  |        |  h  |  h  |  ,  |  .  |  /  | SFT |
 * `-----------------------------------'        `-----------------------------------'
 */
/* Thumb keys scylla
 *          ,-----------------.              ,-----------------.
 *          | TAB | SPC | SFT |              | SFT | BSP | ENT |
 *          '-----|-----+-----|              |-----+-----+-----'
 *                | GUI | ALT |              |ALTGr| CTL |
 *                '-----------'              `-----------'
 */
#define _______________Y_COLEMAK_L0________________       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _______________Y_COLEMAK_L1________________       _______, ______________HM_COLEMAK_L1________________
#define _______________Y_COLEMAK_L2________________       KC_LSFT, ______________HM_COLEMAK_L2________________
#define _______________Y_COLEMAK_L3________________       KC_LCTL, ______________HM_COLEMAK_L3________________
#define __Y_THUMB_L0___                                   ST_CTAB,   RAISE, KC_LSFT
#define __Y_THUMB_L1___                                            KC_LGUI, KC_LALT


#define _______________Y_COLEMAK_R0________________          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______
#define _______________Y_COLEMAK_R1________________       ______________HM_COLEMAK_R1________________, _______
#define _______________Y_COLEMAK_R2________________       ______________HM_COLEMAK_R2________________, KC_LSFT
#define _______________Y_COLEMAK_R3________________       ______________HM_COLEMAK_R3________________, KC_LCTL
#define __Y_THUMB_R0___                                   KC_LSFT,   LOWER, ST_CENT
#define __Y_THUMB_R1___                                   KC_RALT, KC_LCTL

#define __Y_THUMB_N0___                                   _______,  _______, _______
#define __Y_THUMB_N1___                                   _______,  _______

/* LOWER Scylla layer
 *
 * ,-----------------------------------.        ,-----------------------------------.
 * |     |     |     |     |     |     |        |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     |  1  |  @  |  #  |  $  |  %  |        |  ^  |  |  |  &  |  §  |  0  |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     | ESC |  [  |  (  |  {  |  ~  |        |  _  |  }  |  )  |  ]  |  *  |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     |  !  |  °  |  "  |  '  |  `  |        |  -  |  +  |  =  |  €  |  \  |     |
 * `-----`-----------------------------'        `-----------------------------------'
 */
#define _______________Y_SYMBOL_L0_________________       _______, _______, _______, _______, _______, _______
#define _______________Y_SYMBOL_L1_________________       _______, _________________SYMBOL_L1_________________
#define _______________Y_SYMBOL_L2_________________       _______, _________________SYMBOL_L2_________________
#define _______________Y_SYMBOL_L3_________________       _______, _________________SYMBOL_L3_________________

#define _______________Y_SYMBOL_R0_________________       _______, _______, _______, _______, _______, _______
#define _______________Y_SYMBOL_R1_________________       _________________SYMBOL_R1_________________, _______
#define _______________Y_SYMBOL_R2_________________       _________________SYMBOL_R2_________________, _______
#define _______________Y_SYMBOL_R3_________________       _________________SYMBOL_R3_________________, _______


/* RAISE Scylla layer
 *
 * ,-----------------------------------.        ,-----------------------------------.
 * |     |     |     |     |     |     |        |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     |     |Word |     |     |Back |        |Down |Right|  7  |  8  |  9  |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     | ESC |     |PGUP |BSPCW|DelW |        |     |  0  |  4  |  5  |  6  |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     | TAB |Home |PGDN | End | Del |        | Up  |Left |  1  |  2  |  3  |     |
 * `-----------------------------------'        `-----------------------------------'
 */
#define _______________Y_NAV_L0____________________       _______, _______, _______, _______, _______, _______
#define _______________Y_NAV_L1____________________       _______, _________________NAV_L1____________________
#define _______________Y_NAV_L2____________________       _______, _________________NAV_L2____________________
#define _______________Y_NAV_L3____________________       _______, _________________NAV_L3____________________

#define _______________Y_NAV_R0____________________       _______, _______, _______, _______, _______, _______
#define _______________Y_NAV_R1____________________       _________________NAV_R1____________________, _______
#define _______________Y_NAV_R2____________________       _________________NAV_R2____________________, _______
#define _______________Y_NAV_R3____________________       _________________NAV_R3____________________, _______


/* Adjust/whatever Scylla layer
 * ,-----------------------------------.        ,-----------------------------------.
 * |     |     |     |     |     |     |        |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     | F1  | F2  | F3  | F4  | F5  |        | F6  | F7  | F8  | F9  | F10 |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     | F11 |     |     |     |     |        | V+  |     |     |     | F12 |     |
 * |-----+-----+-----+-----+-----+-----|        |-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     | DT  |        | V-  |     |     |     |GAMEL|     |
 * `-----------------------------------'        `-----------------------------------'
 */
#define _______________Y_ADJUST_L0_________________       _______,           _______, _______, _______, _______,   _______
#define _______________Y_ADJUST_L1_________________       KC_F11,            KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5
#define _______________Y_ADJUST_L2_________________       _______,           _______, _______, _______, _______,   _______
#define _______________Y_ADJUST_L3_________________       _______,           _______, _______, _______, _______,   DT_PRNT

#define _______________Y_ADJUST_R0_________________       _______,           _______, _______, _______, _______,   _______
#define _______________Y_ADJUST_R1_________________       KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F12
#define _______________Y_ADJUST_R2_________________       KC_KB_VOLUME_UP,   _______, _______, _______, _______,   _______
#define _______________Y_ADJUST_R3_________________       KC_KB_VOLUME_DOWN, _______, _______, _______, DF(_GAME), _______

/* Game layer
 * ,-----------------------------------.                      ,-----------------------------------.
 * |     | ESC |  1  |  2  |  3  |  4  |                      |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----+-----|
 * |     | TAB |  Q  |  W  |  E  |  R  |                      |  P  |  L  |  G  |     | CM  |     |
 * |-----+-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----+-----|
 * |     | SHI |  A  |  S  |  D  |  F  |                      |  I  | V+  |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----.          ,-----|-----+-----+-----+-----+-----+-----|
 * |     | CTL |  Y  |  X  |  C  |  V  |     |          |     |  M  | V-  |     |     |     |     |
 * `-----------------------------------------'          `-----------------------------------------'
 */
/* Thumb keys sofle
 *          ,-----------------------------.              ,-----------------------------.
 *          |     |     | BSPC|SPACE|ENTER|              |     |     |     |     |     |
 *          `-----------------------------'              `-----------------------------'
 */
#define _______________Y_GAME_L0___________________       _______,  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4
#define _______________Y_GAME_L1___________________       _______,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R
#define _______________Y_GAME_L2___________________       _______, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F
#define _______________Y_GAME_L3___________________       _______, KC_LCTL,    KC_Y,    KC_X,    KC_C,    KC_V
#define __Y_G_THUMB_L0_                                   ST_CTAB,   RAISE, KC_LSFT
#define __Y_G_THUMB_L1_                                            KC_LGUI, KC_LALT

#define _______________Y_GAME_R0___________________       _______,  _______, _______,  _______, _______,    KC_DEL
#define _______________Y_GAME_R1___________________       KC_P,     KC_L,    KC_UP,    _______, _______,    KC_BSPC
#define _______________Y_GAME_R2___________________       KC_I,     KC_LEFT, KC_DOWN, KC_RIGHT, _______,    KC_KB_VOLUME_UP
#define _______________Y_GAME_R3___________________       KC_M,     _______, _______,  _______, DF(_ALPHA), KC_KB_VOLUME_DOWN

#define __Y_G_THUMB_R0_                                   KC_LSFT,    LOWER, ST_CENT
#define __Y_G_THUMB_R1_                                   KC_RALT,  KC_LCTL
