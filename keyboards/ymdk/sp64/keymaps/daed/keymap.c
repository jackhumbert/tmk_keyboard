#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _GAMER,
    _FN,
    _RAISE,
    _MODE,
    _GACROS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │ Esc │  1  │  2  │  3  │  4  │  5  │  6  │    │  7  │  8  │  9  │  0  │  -  │  =  │ BkSp     │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │ Tab    │  Q  │  W  │  E  │  R  │  T  │    │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │ \     │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │ Ctrl    │  A  │  S  │  D  │  F  │  G  │    │  H  │  J  │  K  │  L  │  ;  │  '  │ Enter      │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │ LShift   │  Z  │  X  │  C  │  V  │  B  │    │  N  │  M  │  <  │  >  │  ?  │ Sft │ Up  │ _MO │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │ _FN  │ Win │ Alt  │             │ _RA │    │               │ Alt   │ Win  │ Lft │ Dwn │ Rgt │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_BASE] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,     KC_6,               KC_7, KC_8,    KC_9,    KC_0,      KC_MINUS,    KC_EQUAL,    KC_BSPACE,
  KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,               KC_Y,     KC_U, KC_I,    KC_O,    KC_P,      KC_LBRACKET, KC_RBRACKET, KC_BSLS,
  KC_LCTL, KC_A,    KC_S,    KC_D,     KC_F,    KC_G,               KC_H,     KC_J, KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,                 KC_ENTER,
  KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,               KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,     KC_UP,       MO(_MODE),
  MO(_FN), KC_LGUI, KC_LALT, KC_SPACE,      MO(_RAISE),             KC_SPACE,           KC_RALT,      KC_RCTL,   KC_LEFT,     KC_DOWN,     KC_RIGHT
  ),
/* Keymap 1: Gamer layer
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │ Esc │  1  │  2  │  3  │  4  │  5  │  6  │    │  7  │  8  │  9  │  0  │  -  │  =  │ BkSp     │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │ Tab    │  Q  │  W  │  E  │  R  │  T  │    │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │ \     │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │ Ctrl    │  A  │  S  │  D  │  F  │  G  │    │  H  │  J  │  K  │  L  │  ;  │  '  │ Enter      │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │ LShift   │  Z  │  X  │  C  │  V  │  B  │    │  N  │  M  │  <  │  >  │  ?  │ Sft │ Up  │ _MO │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │ _FN  │ F13 │ Alt  │             │ _GA │    │               │ Alt   │ Win  │ Lft │ Dwn │ Rgt │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_GAMER] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,     KC_6,               KC_7, KC_8,    KC_9,    KC_0,      KC_MINUS,    KC_EQUAL,    KC_BSPACE,
  KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,               KC_Y,     KC_U, KC_I,    KC_O,    KC_P,      KC_LBRACKET, KC_RBRACKET, KC_BSLS,
  KC_LCTL, KC_A,    KC_S,    KC_D,     KC_F,    KC_G,               KC_H,     KC_J, KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,                 KC_ENTER,
  KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,               KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,     KC_UP,       MO(_MODE),
  MO(_FN), KC_F13,  KC_LALT, KC_SPACE,      MO(_GACROS),             KC_SPACE,           KC_RALT,      KC_RCTL,   KC_LEFT,     KC_DOWN,     KC_RIGHT
  ),

/* Keymap 2: Function
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │  `  │ F1  │  F2 │ F3  │ F4  │ F5  │ F6  │    │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │     │     │    │     │     │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │    │Left │ Up  │Down │Right│     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │    │     │     │     │     │     │     │     │     │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │      │     │      │             │     │    │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_FN] = LAYOUT(
  KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
  _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______,        KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,          _______,
  _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
  _______, _______, _______, _______,          _______,        _______,          _______, _______,          KC_HOME, KC_PGDN, KC_END
  ),
/* Keymap 3: Raise / Quality of life
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │  `  │ F1  │  F2 │ F3  │ F4  │ F5  │ F6  │    │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │     │     │    │     │     │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │    │Left │ Up  │Down │Right│     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │    │     │     │     │     │     │     │     │     │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │      │     │      │             │     │    │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_RAISE] = LAYOUT(
  KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
  _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______,        KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,          _______,
  _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,  _______, KC_PGUP, _______,
  _______, _______, _______, _______,          _______,        _______,          _______, _______,           KC_HOME, KC_PGDN, KC_END
  ),
/* Keymap 4: Mode switching
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │  `  │ F1  │  F2 │ F3  │ F4  │ F5  │ F6  │    │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │ RGB 0/1│RGBM-│RGBB+│RGBM+│     │     │    │     │     │     │     │     │     │     │ Reset │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │RGBS-│RGBB-│RGBS+│     │     │    │Left │ Up  │Down │Right│     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │    │     │     │     │ GAME| BASE│     │     │     │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │      │     │      │             │     │    │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_MODE] = LAYOUT(
  KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  RGB_TOG, RGB_RMOD, RGB_VAI, RGB_MOD, _______, _______,        _______, _______, _______, _______, _______, _______, _______, RESET,
  _______, RGB_SPD,  RGB_VAD, RGB_SPI, _______, _______,        KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,          _______,
  _______, _______,  _______, _______, _______, _______,        _______, _______, _______, TO(_GAMER), TO(_BASE), _______, _______, _______,
  _______, _______,  _______, _______,          _______,        _______,          _______, _______,          _______, _______, _______
  ),
/* Keymap 5: Gaming macros
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │  `  │ F1  │  F2 │ F3  │ F4  │ F5  │ F6  │    │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │ PUSH│     │     │     │    │     │     │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │ FALL│     │     │     │    │Left │ Up  │Down │Right│     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │ CAP │     │     │     │    │     │     │     │ GAME| BASE│     │     │     │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │      │     │      │             │     │    │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_GACROS] = LAYOUT(
  KC_GRAVE, KC_F1,        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  _______, _______,  _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______,  _______, _______, _______, _______,            KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,          _______,
  _______, _______,  _______, _______, _______, _______,          _______, _______, _______, TO(_GAMER), TO(_BASE), _______, _______, _______,
  _______, _______,       _______, _______,        _______, _______,                                _______, _______,          _______, _______, _______
  ),
};
