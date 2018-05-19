#include QMK_KEYBOARD_H

#define __x__ KC_NO

// Keymap layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_60_all( /* Base */
    KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, __x__,   KC_ENT,  \
    KC_LSFT, __x__,   KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, __x__,   \
    KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                          KC_RALT, KC_RGUI, MO(1),   KC_RCTL  \
  ),

  [1] = LAYOUT_60_all( /* System layer to have access to RESET button */
      RESET,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,   __x__, \
      __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,   __x__, \
      __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,   __x__, \
      __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,   __x__, \
      __x__,  __x__,  __x__,                  __x__,                                  __x__,  __x__,  KC_TRNS, __x__  \
  ),
};

const uint16_t PROGMEM fn_actions[] = {

};
