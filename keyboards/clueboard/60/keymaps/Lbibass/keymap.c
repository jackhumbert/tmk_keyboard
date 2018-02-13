#include "60.h"

#define _______ KC_TRNS

enum keyboard_layers {
  _BL,
  _FL,
<<<<<<< HEAD
=======
  _CL
>>>>>>> Addition to clueboard 60 layout.
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc/fn|1| 2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   BkSp|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Fn/ \|
     * |-----------------------------------------------------------|
     * |GUI|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|   Enter|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|     Shift|
     * |-----------------------------------------------------------'
     * |Caps |alt|crtl |         Space               |gui|alt|Ctrl |
     * `-----------------------------------------------------------'
     */
    [_BL] = KEYMAP_AEK(
      LT(_FL, KC_ESC), KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,  KC_BSPC,  \
<<<<<<< HEAD
      KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, LT(_FL, KC_BSLASH),\
      KC_LGUI,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,    KC_ENT,   \
      KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH,     KC_RSFT,     \
      KC_LCAP,  KC_LALT,  KC_LCTL,                        KC_SPC,                           KC_RGUI,  KC_RALT,   KC_RCTL),
    [_FL] = KEYMAP_AEK(
      KC_GRAVE, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,  KC_DELETE,  \
      _______,   KC_BTN1,KC_MS_UP,KC_BTN2,RESET,KC_MS_WH_UP,_______,_______,_______,_______,_______,KC_UP,_______,_______,\
      _______,     KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,_______,KC_MS_WH_DOWN,_______,_______,_______,_______,KC_LEFT,KC_RIGHT,    _______,  \
      _______,       _______,_______,_______,_______,_______,_______,_______,_______,_______,KC_DOWN,       _______,     \
      _______,  _______,  _______,                        _______,                          _______, KC_RALT,   _______),
=======
      KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC, LT(_FL, KC_BSLASH),\
      KC_LGUI,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,    KC_ENT,   \
      KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,     KC_RSFT,     \
      KC_LCAP,  KC_LALT,  KC_LCTL,                        KC_SPC,                           KC_RGUI,  KC_RALT,   KC_RCTL),
    [_FL] = KEYMAP_AEK(
      KC_GRAVE, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,  KC_DELETE,  \
      _______,   _______,_______,_______,RESET,_______,_______,_______,_______,_______,_______,KC_UP,_______,_______,\
      _______,     _______,MO(_CL),_______,_______,_______,_______,_______,_______,_______,KC_LEFT,KC_RIGHT,    _______,  \
      _______,       _______,_______,_______,_______,_______,_______,_______,_______,_______,KC_DOWN,       _______,     \
      _______,  _______,  _______,                        _______,                          _______, KC_RALT,   _______),
    [_CL] = KEYMAP_AEK(
      BL_STEP,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   \
      _______,   _______,_______,_______,RESET,  _______,_______,_______,_______,_______,_______,_______,_______,_______,\
      _______,     _______,MO(_CL),_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,    \
      _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,      \
      _______,  _______,  _______,                        _______,                          _______,  MO(_FL),   _______)
>>>>>>> Addition to clueboard 60 layout.
};
