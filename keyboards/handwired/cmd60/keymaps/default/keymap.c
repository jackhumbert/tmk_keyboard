#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* CMD60 - QWERTY */
      KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
      KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
      LT(3, KC_ENT), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
      KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, \
      KC_LCTL,       KC_LGUI, KC_LALT,                            LT(2, KC_SPC),                      MO(3),   MO(4),   MO(5),   TG(1)    \
  ),
  [1] = LAYOUT( /* CMD60 - GameMode */
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
      KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_RSFT, \
      _______, XXXXXXX, _______,                            KC_SPC,                             _______, _______, _______, _______  \
  ),
  [2] = LAYOUT( /* CMD60 - Arrows */
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
      _______, KC_BSPC, KC_UP,   KC_DEL,  _______, _______, _______, KC_BSPC, KC_UP,   KC_DEL,  KC_PSCR, KC_SLCK, KC_PAUS, _______, \
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______, \
      _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, _______,                   _______, \
      _______, _______, _______,                            _______,                            _______, _______, _______, _______  \
  ),
  [3] = LAYOUT( /* CMD60 - Functions */
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
      KC_MUTE, KC_BSPC, KC_PGUP, KC_DEL,  _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, KC_PAUS, KC_SLCK, KC_PSCR, \
      _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_INS,           _______, \
      _______, _______, _______, _______, _______, _______, KC_END,  _______, _______, _______, _______,                   _______, \
      _______, _______, _______,                            _______,                            _______, _______, _______, _______  \
  ),
  [4] = LAYOUT( /* CMD60 - Mouse */
      KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,          _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN3, KC_WH_D,                   _______, \
      _______, _______, _______,                            _______,                            _______, _______, _______, _______  \
  ),
  [5] = LAYOUT( /* CMD60 - Media */
      KC_WAKE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT,          KC_MPLY, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WBAK, KC_WFWD,                   KC_WREF, \
      _______, _______, _______,                            _______,                            _______, _______, _______, _______  \
  ),
};
