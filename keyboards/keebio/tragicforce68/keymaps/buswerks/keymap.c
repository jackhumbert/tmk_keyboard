#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _FN1 2

#define WORD_L LALT(KC_LEFT)
#define WORD_R LALT(KC_RGHT)
#define LINE_L LGUI(KC_LEFT)
#define LINE_R LGUI(KC_RGHT)

#define DESK_L LCTL(KC_LEFT)
#define DESK_R LCTL(KC_RGHT)
#define MSN_CTL LCTL(KC_UP)

#define LT_FN LT(_FN1, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────────────┐ ┌────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,       KC_BSPC,      KC_INS,  KC_PGUP,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────────────┤ ├────────┼────────┤
     KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,    KC_BSLS,    KC_DEL,  KC_PGDN,
  //├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┤ └────────┴────────┘
     LT_FN,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENTER,
  //├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤ ┌────────┐
     KC_LSPO,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC,          KC_UP,
  //├──────────┬───────┴──┬─────┴────┬───┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼────────┴─┬──────────┬────┬──────┴─┬────────┼────────┐
     KC_LCTL,   KC_LGUI,   KC_LALT,                        KC_SPACE,                          KC_RALT,   KC_CAPS,   KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT
  //└──────────┴──────────┴──────────┴───────────────────────────────────────────────────────┴──────────┴──────────┴──────────┘    └────────┴────────┴────────┘
  ),

    [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────────────┐ ┌────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,       KC_BSPC,      KC_INS,  KC_PGUP,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────────────┤ ├────────┼────────┤
     KC_TAB,      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,    KC_BSLS,    KC_DEL,  KC_PGDN,
  //├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┤ └────────┴────────┘
     LT_FN,         KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,       KC_ENTER,
  //├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤ ┌────────┐
     KC_LSPO,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC,          KC_UP,
  //├──────────┬───────┴──┬─────┴────┬───┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼────────┴─┬──────────┬────┬──────┴─┬────────┼────────┐
     KC_LCTL,   KC_LGUI,   KC_LALT,                        KC_SPACE,                          KC_RALT,   KC_CAPS,   KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT
  //└──────────┴──────────┴──────────┴───────────────────────────────────────────────────────┴──────────┴──────────┴──────────┘    └────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────────────┐ ┌────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       _______,      RESET,   KC_HOME,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────────────┤ ├────────┼────────┤
     _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, KC_END,
  //├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┤ └────────┴────────┘
     _______,       DESK_L,  MSN_CTL, DESK_R,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,       _______,
  //├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤ ┌────────┐
     _______,           _______, _______, _______, _______, _______, LINE_L,  WORD_L,  WORD_R,  LINE_R,  _______,          _______,          BL_INC,
  //├──────────┬───────┴──┬─────┴────┬───┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼────────┴─┬──────────┬────┬──────┴─┬────────┼────────┐
     _______,   _______,   _______,                        KC_BSPC,                           _______,   _______,   KC_MENU,        BL_BRTG, BL_DEC,  BL_TOGG
  //└──────────┴──────────┴──────────┴───────────────────────────────────────────────────────┴──────────┴──────────┴──────────┘    └────────┴────────┴────────┘
  )
};