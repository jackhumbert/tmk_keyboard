#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "layers.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    OS_SWAP
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_G RALT_T(KC_G)

// RIGHT HAND HOME ROW MODS ├──────────────────────────────────┐
#define HM_H RALT_T(KC_H)
#define HM_J RSFT_T(KC_J)
#define HM_K LCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN LGUI_T(KC_SCLN)

// CTRL + ARROWS ├─────────────────────────────────────────────┐
#define CT_LEFT LCTL(KC_LEFT)
#define CT_DOWN LCTL(KC_DOWN)
#define CT_UP LCTL(KC_UP)
#define CT_RGHT LCTL(KC_RGHT)

// THUMB KEY LAYER TAPS ├──────────────────────────────────────┐
#define TB_TAB LT(_MEDIA, KC_TAB)
#define TB_ENT LT(_NAVIGATION, KC_ENT)
#define TB_SPC LT(_NUMBERS, KC_SPC)
#define TB_BSPC LT(_FUNCTION, KC_BSPC)

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   c o m b o s                                 │
// └───────────────────────────────────────────────────────────┘
// vertical combos for umlauts
const uint16_t PROGMEM ae_combo[] = {KC_Q, HM_A, COMBO_END};
const uint16_t PROGMEM ss_combo[] = {KC_W, HM_S, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {KC_U, HM_J, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, HM_L, COMBO_END};
// horizontal combos for mods
const uint16_t PROGMEM del_combo[] = {HM_H, HM_J, COMBO_END};
const uint16_t PROGMEM bsp_combo[] = {HM_J, HM_K, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {HM_K, HM_L, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {HM_F, HM_D, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {HM_D, HM_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(ae_combo, RALT(KC_Q)),
    COMBO(ss_combo, RALT(KC_S)),
    COMBO(ue_combo, RALT(KC_Y)),
    COMBO(oe_combo, RALT(KC_P)),
    COMBO(del_combo, KC_DEL),
    COMBO(bsp_combo, KC_BSPC),
    COMBO(ent_combo, KC_ENT),
    COMBO(tab_combo, KC_TAB),
    COMBO(esc_combo, KC_ESC)
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ q w e r t y                                               │
   └───────────────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    ;    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    Z    │    X    │    C    │    V    │    B    ││        ││        ││    N    │    M    │    ,    │    .    │    /    │
   └─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┘
                       │   ESC   │   TAB   │  ENTER  │                    │  SPACE  │ BSPACE  │   DEL   │
                       └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */

   [_QWERTY] = LAYOUT_36(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    HM_A,     HM_S,     HM_D,     HM_F,     HM_G,                          HM_H,     HM_J,     HM_K,     HM_L,     HM_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                        KC_ESC,   TB_TAB,   TB_ENT,       KC_MPLY,         TB_SPC,   TB_BSPC,  KC_DEL
  ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ c o l e m a k                                             │
   └───────────────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │    Q    │    W    │    F    │    P    │    G    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    J    │    L    │    U    │    Y    │    ;    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    A    │    R    │    S    │    T    │    D    ├─╯                ╰─┤    H    │    N    │    E    │    I    │    O    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    Z    │    X    │    C    │    V    │    B    ││        ││        ││    K    │    M    │    ,    │    .    │    /    │
   └─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┘
                       │   ESC   │   TAB   │  ENTER  │                    │  SPACE  │ BSPACE  │   DEL   │
                       └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */

   [_COLEMAK] = LAYOUT_36(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,                          KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
    KC_A,     KC_R,     KC_S,     KC_T,     KC_D,                          KC_H,     KC_N,     KC_E,     KC_I,     KC_O,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                        KC_ESC,   TB_TAB,   TB_ENT,       _______,         TB_SPC,   TB_BSPC,  KC_DEL
  ),

  /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ n a v i g a t i o n                                       │
   └───────────────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │         │         │         │         │    {    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    }    │ CTRL ←  │ CTRL ↓  │ CTRL ↑  │ CTRL →  │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │    (    ├─╯                ╰─┤    )    │    ←    │    ↓    │    ↑    │    →    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │    [    ││        ││        ││    ]    │  HOME   │    PG↓  │   PG↑   │   END   │
   └─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┘
                       │         │         │         │                    │         │         │         │
                       └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */

   [_NAVIGATION] = LAYOUT_36(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    _______,  _______,  _______,  _______,  KC_LCBR,                       KC_RCBR,  CT_LEFT,  CT_DOWN,    CT_UP,  CT_RGHT,
    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_LPRN,                       KC_RPRN,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,
    _______,  _______,  _______,  _______,  KC_LBRC,                       KC_RBRC,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,
                        _______,  _______,  _______,       _______,        _______,  _______,  _______
  ),

  /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ m e d i a   &   s y m b o l                               │
   └───────────────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │    _    │    &    │    *    │    (    │    )    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    +    │    $    │    %    │    ^    │    "    ├─╯                ╰─┤         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    ~    │    !    │    @    │    #    │    |    ││        ││        ││         │         │         │         │         │
   └─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┘
                       │         │         │         │                    │         │         │         │
                       └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */

   [_MEDIA] = LAYOUT_36(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    KC_UNDS,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,                       RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,
    KC_PLUS,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_DQUO,                       RGB_M_P,  RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,                       QWERTY,   COLEMAK,  _______,  _______,  QK_BOOTLOADER,
                        _______,  _______,  _______,       _______,        _______,  _______,  _______
  ),

  /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ n u m b e r s                                             │
   └───────────────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │    -    │    7    │    8    │    9    │    0    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    =    │    4    │    5    │    6    │    '    ├─╯                ╰─┤         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    `    │    1    │    2    │    3    │    \    ││        ││        ││         │         │         │         │         │
   └─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┘
                       │         │         │         │                    │         │         │         │
                       └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */

   [_NUMBERS] = LAYOUT_36(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    KC_MINS,  KC_7,     KC_8,     KC_9,     KC_0,                          _______,  _______,  _______,  _______,  _______,
    KC_EQL,   KC_4,     KC_5,     KC_6,     KC_QUOT,                       KC_RALT,  KC_RSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_BSLS,                       _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,       _______,        _______,  _______,  _______
  ),

  /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ f u n t i o n                                             │
   └───────────────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │   F12   │   F7    │   F8    │   F9    │ PRT SCR │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │   F11   │   F4    │   F5    │   F6    │         ├─╯                ╰─┤         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │   F10   │   F1    │   F2    │   F3    │   INS   ││        ││        ││         │         │         │         │         │
   └─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┘
                       │         │         │         │                    │         │         │         │
                       └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */

   [_FUNCTION] = LAYOUT_36(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    KC_F12,   KC_F7,    KC_F8,    KC_F9,    KC_PSCR,                       _______,  _______,  _______,  _______,  _______,
    KC_F11,   KC_F4,    KC_F5,    KC_F6,    _______,                       KC_RALT,  KC_RSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
    KC_F10,   KC_F1,    KC_F2,    KC_F3,    KC_INS,                        _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,       _______,        _______,  _______,  _______
  ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ t e m p l a t e                                           │
   └───────────────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         ├─╯                ╰─┤         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         ││        ││        ││         │         │         │         │         │
   └─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┘
                       │         │         │         │                    │         │         │         │
                       └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */
/*
   [_TEMPLATE] = LAYOUT_saegewerk(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,       _______,        _______,  _______,  _______
 )*/
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D I E S  U N D  D A S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case SHT_T:
        //     return TAPPING_TERM - 150; // Recommended
        // case SHT_N:
        //     return TAPPING_TERM - 150; // Recommended
        default:
            return TAPPING_TERM;
    }
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_MINS:
    case KC_UNDS:
    case KC_LSFT:
    case KC_RSFT:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H A P T I C   F E E D B A C K                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
void keyboard_post_init_user(void) {
  // Call the post init code.
  #if RGB_MATRIX_ENABLE
    rgblight_enable_noeeprom();
    //rgblight_sethsv_noeeprom(35, 255, 255); // set default RGB color to yellow
  #endif //RGB_MATRIX_ENABLE
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE
                }
              #ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
              #endif // HAPTIC_ENABLE
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
          }


// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
    }
    return true;
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
#ifdef ENCODER_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r                                             │
// └───────────────────────────────────────────────────────────┘

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_NAVIGATION] =  { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [_QWERTY] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_COLEMAK] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MEDIA] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUMBERS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FUNCTION] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif // ENCODER_ENABLE

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) { tap_code(KC_MUTE); }
            break;
    }
    return true;
}
#endif //




