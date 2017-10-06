#include "xd60.h"
#include "action_layer.h"

#define BASE 0
#define FN 1

#define CTL_SLSH CTL_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  [BASE] = KEYMAP(
      KC_ESC,    KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_BSPC,   \
      KC_TAB,    KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_BSLS,   \
      CTL_SLSH,  KC_A,    KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,              KC_ENT,    \
      KC_LSPO,   KC_NO,   KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_NO,    KC_RSPC,  KC_UP,    MO(FN),    \
      MO(FN),    KC_LGUI, KC_LALT,                              KC_SPC,                              KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RIGHT
      ),
  // 1: Function Layer
  [FN] = KEYMAP(
      KC_GRV,    KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_DEL,    \
      KC_TRNS,   RGB_MOD, RGB_VAI,  KC_TRNS,  KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_DEL,    \
      KC_TRNS,   RGB_TOG, RGB_VAD,  KC_MUTE,  KC_VOLU, KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,  KC_TRNS,  KC_NO,              KC_ENT,    \
      KC_TRNS,   KC_NO,   KC_TRNS,  KC_TRNS,  KC_CIRC, KC_AMPR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_TRNS,   \
      KC_TRNS,   KC_TRNS, KC_TRNS,                              KC_SPC,                              KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDOWN,KC_END
      ),

};
