#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty
     * ,-----------------------------------------------------------------------------------------.
     * | `   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  \     |
     * |-----------------------------------------------------------------------------------------+
     * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RShift          |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl  |LGUI | LAlt  |               Space                        | RAlt   | FN  | RCtrl |
     * `-----------------------------------------------------------------------------------------'
     */
  [0] = LAYOUT_all( \
    KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   _______, KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, \
    KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,  \
    KC_LSFT, _______, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  _______,  \
    KC_LCTL, KC_LGUI, KC_LALT,                 KC_SPC,                                  _______,  KC_RALT,  MO(1),    KC_RCTL
  ),

  /* FN Layer (Based on Poker 3 FN layout)
     * ,-----------------------------------------------------------------------------------------.
     * | Esc | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Delete    |
     * |-----------------------------------------------------------------------------------------+
     * |        |     |     |     |     |     | Calc| PgUp|  Up | PgDn|PrtSc|Scrlk|Pause|        |
     * |-----------------------------------------------------------------------------------------+
     * |         | Vol-| Vol+| Mute|     |     | Home| Left| Down|Right| Ins | Del |             |
     * |-----------------------------------------------------------------------------------------+
     * |           | App |     |     |     |     | End |     |     |     |     |                 |
     * |-----------------------------------------------------------------------------------------+
     * |       |     |       |                                            |        |     |       |
     * `-----------------------------------------------------------------------------------------'
     */
  [1] = LAYOUT_all( \
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______, KC_DEL, \
    _______,  _______,  _______,  _______,  _______,  _______,  KC_CALC,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_PSCR,  KC_SLCK,  KC_PAUS,  _______, \
    _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,  _______,  _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_INS,   KC_DEL,   _______, \
    _______,  _______,  KC_APP,   _______,  _______,  _______,  _______,  KC_END,   _______,  _______,  _______,  _______,  _______,  _______, \
    _______,  _______,  _______,                      _______,                                          _______,  _______,  _______,  _______
    )
};
