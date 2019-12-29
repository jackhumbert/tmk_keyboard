
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgblight.h"
#include "tominabox1.h"
#include "mini.h"

#define xxx KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space_base(
          KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
          KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,
  LCTL_T(KC_A),   KC_R,   KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,   TD(TD_O_BSLS),
  LSFT_T(KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M,   KC_COMM,KC_DOT, TD(TD_QUES_ENT),
                        KC_LALT, KC_LGUI, LT(_RAISE, KC_SPC), MO(_ARROW)
  ),

  [_RAISE] = LAYOUT_split_space_base(
    TD(TD_QUOTE),      xxx,      xxx,     xxx,     xxx,     xxx,      xxx,       xxx,     KC_PLUS,      KC_MINS,
    TD(TD_SDCOL),     KC_UP,     xxx,     xxx,     xxx,     xxx,      xxx,       xxx,      KC_EQL,      KC_UNDS,
    KC_LEFT,         KC_DOWN,  KC_RGHT,   xxx,     xxx,     xxx,     xxx,      xxx,   TD(TD_SDCOL),     xxx,
    xxx,               xxx,      xxx,     xxx,     xxx,     xxx,    KC_LCBR,   KC_RCBR,     xxx,       	KC_BSLS,
                                          xxx,  xxx,  xxx, xxx
  ),
};
