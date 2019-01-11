#pragma once

#include "quantum.h"
#ifdef TAP_DANCE_ENABLE
  #include "tap_dance.h"
#endif
#ifdef UNICODE_ENABLE
  #include "unicode.h"
#endif

#ifdef LAYER_FN
  #define FN      MO(L_FN)
  #define FN_CAPS LT(L_FN, KC_CAPS)
  #define FN_FNLK TT(L_FN)
#endif

#define TOP     LCTL(KC_HOME)
#define BOTTOM  LCTL(KC_END)
#define LCT_CPS LCTL_T(KC_CAPS)

enum layers_user {
  L_BASE,
#ifdef LAYER_FN
  L_FN,
#endif
#ifdef LAYER_NUMPAD
  L_NUMPAD,
#endif

  L_RANGE_KEYMAP,
};

enum custom_keycodes_user {
  CLEAR = SAFE_RANGE,
#ifdef LAYER_NUMPAD
  NUMPAD,
#endif

  SAFE_RANGE_KEYMAP,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
