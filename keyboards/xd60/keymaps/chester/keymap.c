#include "xd60.h"
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  KEYMAP(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      LT(1,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_RSFT,    KC_UP,      \
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RCTL, F(0),     KC_LEFT, KC_RIGHT,  KC_DOWN),

  // 1: Function Layer
  KEYMAP(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,   KC_F14,    \
      KC_TRNS,   RGB_TOG, KC_UP,   RGB_MOD, RGB_HUI,RGB_SAI,RGB_VAI,KC_TRNS,  KC_UP, KC_SLCK,   KC_PAUS, KC_HOME,  KC_END,           KC_PSCR,    \
      KC_TRNS,   KC_LEFT, KC_DOWN, KC_RIGHT,RGB_HUD, RGB_SAD, RGB_VAD,KC_LEFT,  KC_DOWN,  KC_RIGHT,   KC_PGUP, KC_PGDN,  KC_TRNS,             KC_ENT,    \
      KC_LSFT, KC_TRNS,   KC_VOLD,   KC_VOLU,  KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS, KC_INS,  KC_DEL,  KC_TRNS, KC_RSFT,  KC_VOLU,      \
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RCTL, F(0),     KC_RALT, KC_MUTE,KC_VOLD),

};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
