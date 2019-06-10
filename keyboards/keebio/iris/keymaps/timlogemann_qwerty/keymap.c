#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _OTHER 1

#define SHFT_CPS LSFT_T(KC_CAPS)
#define SHFT_QT RSFT_T(KC_QUOT)
#define L_ALT KC_LAPO
#define R_ALT KC_RAPC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SHFT_CPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SHFT_QT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_GRAVE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,            KC_NO,  KC_B,     KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     L_ALT,  KC_LGUI, KC_SFTENT,                 KC_SPC,   TT(1),  R_ALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_OTHER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_PLUS,    KC_1,    KC_2,    KC_3,    KC_5,                              KC_NO,   KC_NO,   KC_NO, KC_LBRC, KC_RBRC, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_MINUS, KC_4,     KC_5,   KC_6,   KC_PLUS,                             KC_NO,   KC_NO,    KC_UP,   KC_NO,  KC_MFFD, KC__VOLUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,   KC_LBRC,  KC_7,     KC_8,   KC_9, KC_MINUS,                              KC_NO,  KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC__VOLDOWN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,   KC_RBRC,  KC_NO,    KC_0,   KC_NO,   KC_LALT, KC_NO,            KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_MRWD, KC__MUTE,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LALT_T(KC_LBRC), KC_TRNS, KC_TRNS,                   KC_TRNS,  KC_TRNS, RALT_T(KC_RBRC)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
