/* Copyright 2020 Rustam Zagirov
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)

#define E_NUMBERS LT(_3_NUMBERS,KC_E)
#define R_MOUSE LT(_4_MOUSE,KC_R)
#define O_NUMBERS LT(_3_NUMBERS,KC_O)
#define U_MOUSE LT(_4_MOUSE,KC_U)
#define R_NUMBERS LT(_3_NUMBERS,KC_R)
#define W_MOUSE LT(_4_MOUSE,KC_W)
#define LEFT_NUMBERS LT(_3_NUMBERS, KC_LEFT)
#define RIGHT_MOUSE LT(_4_MOUSE, KC_RIGHT)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ALT_TAB,
};

bool is_alt_tab_active = false;    // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;        // we will be using them soon.

enum layers {
  _0_BASE,
  _1_BEAKL,
  _2_WORKMAN,
  _3_NUMBERS,
  _4_MOUSE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_0_BASE] = LAYOUT_ergodox(
  KC_NONUS_BSLASH,      KC_EXLM,              KC_AT,         KC_HASH,       KC_DLR,             KC_PERC,   KC_AUDIO_MUTE,
  KC_LEAD,              KC_Q,                 KC_W,          E_NUMBERS,     R_MOUSE,            KC_T,      TG(_1_BEAKL),
  LCTL(KC_B),           LSFT_T(KC_A),         LCTL_T(KC_S),  LALT_T(KC_D),  LGUI_T(KC_F),       KC_G,
  KC_BSLASH,            KC_Z,                 KC_X,          KC_C,          KC_V,               KC_B,      TG(_2_WORKMAN),
  ALT_TAB,              XXXXXXX,              XXXXXXX,       LEFT_NUMBERS,  RIGHT_MOUSE,
  KC_AUDIO_VOL_DOWN,    KC_AUDIO_VOL_UP,
  XXXXXXX,
  KC_ENTER,             KC_TAB,               KC_ESCAPE,
  KC_CAPSLOCK,          KC_CIRC,              KC_AMPR,       KC_ASTR,       KC_LPRN,            KC_RPRN,   KC_MINUS,
  XXXXXXX,              KC_Y,                 KC_U,          KC_I,          KC_O,               KC_P,      KC_LBRACKET,
  KC_H,                 RGUI_T(KC_J),         RALT_T(KC_K),  RCTL_T(KC_L),  RSFT_T(KC_SCOLON),  KC_QUOTE,
  KC_RBRACKET,          KC_N,                 KC_M,          KC_COMMA,      KC_DOT,             KC_SLASH,  KC_EQUAL,
  KC_DOWN,              KC_UP,                XXXXXXX,       XXXXXXX,       XXXXXXX,
  KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_NEXT_TRACK,
  XXXXXXX,
  KC_ESCAPE,            KC_BSPACE,            KC_SPACE
),
[_1_BEAKL] = LAYOUT_ergodox(
  _______,  _______,       _______,       _______,           _______,         _______,    _______,
  _______,  _______,       KC_H,          O_NUMBERS,  U_MOUSE,  KC_X,       _______,
  _______,  LSFT_T(KC_Y),  LCTL_T(KC_I),  LALT_T(KC_E),      LGUI_T(KC_A),    KC_DOT,
  _______,  KC_J,          KC_SLASH,      KC_COMMA,          KC_K,            KC_QUOTE,   _______,
  _______,  _______,       _______,       _______,           _______,
                                                              _______,         _______,
                                                              _______,
                                                              _______,         _______,    _______,

  _______,  _______,       _______,       _______,           _______,         _______,    _______,
  _______,  KC_G,          KC_C,          KC_R,              KC_F,            KC_Z,       _______,
  KC_D,     RGUI_T(KC_S),  RALT_T(KC_T),  RCTL_T(KC_N),      RSFT_T(KC_B),    KC_SCOLON,
  _______,  KC_W,          _______,       KC_L,              KC_P,            KC_V,       _______,
  _______,  _______,       _______,       _______,           _______,
  _______,  _______,
  _______,
  _______,  _______,       _______
),
[_2_WORKMAN] = LAYOUT_ergodox(
  _______,  _______,       _______,       _______,           _______,         _______,    _______,
  _______,  _______,       KC_D,          R_NUMBERS,  W_MOUSE,  KC_B,       _______,
  _______,  _______,       _______,       LALT_T(KC_H),      LGUI_T(KC_T),    _______,
  _______,  _______,       _______,       KC_M,              KC_C,            KC_V,       _______,
  _______,  _______,       _______,       _______,           _______,
                                                              _______,         _______,
                                                              _______,
                                                              _______,         _______, _______,

  _______,  _______,       _______,       _______,           _______,         _______,    _______,
  _______,  KC_J,          KC_F,          KC_U,              KC_P,            KC_SCOLON,  _______,
  KC_Y,     RGUI_T(KC_N),  RALT_T(KC_E),  RCTL_T(KC_O),      RSFT_T(KC_I),    _______,
  _______,  KC_K,          KC_L,          _______,           _______,         _______,    _______,
  _______,  _______,       _______,       _______,           _______,
  _______,  _______,
  _______,
  _______,  _______,       _______
),
[_3_NUMBERS] = LAYOUT_ergodox(
  _______,  KC_F1,      KC_F2,    KC_F3,     KC_F4,    KC_F5,      _______,
  _______,  _______,    _______,  _______,   _______,  _______,    _______,
  _______,  _______,    _______,  _______,   _______,  _______,
  _______,  _______,    _______,  _______,   _______,  _______,    _______,
  RESET,    _______,    _______,  _______,   _______,
                                              _______,  _______,
                                              _______,
                                              _______,  _______,    _______,

  _______,  KC_F6,      KC_F7,    KC_F8,     KC_F9,    KC_F10,     KC_F11,
  _______,  _______,    KC_7,     KC_8,      KC_9,     KC_ASTR,    KC_F12,
  _______,  KC_4,       KC_5,     KC_6,      KC_PLUS,  _______,
  _______,  _______,    KC_1,     KC_2,      KC_3,     KC_BSLASH,  _______,
  KC_0,     KC_KP_DOT,  _______,  KC_EQUAL,  _______,
  _______,  _______,
  _______,
  _______,  _______,    _______
),
[_4_MOUSE] = LAYOUT_ergodox(
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,

                                      RGB_HUI,        RGB_HUD,
                                      _______,
                                      _______, _______, _______,

  _______,            _______, _______,     _______,    _______,       _______, _______,
  RGB_MOD,            RGB_TOG, KC_MS_BTN1,  KC_MS_UP,   KC_MS_BTN2,    _______, _______,
                      RGB_SLD, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   _______, _______,
  TOGGLE_LAYER_COLOR, _______, KC_MS_WH_UP, _______,    KC_MS_WH_DOWN, _______, _______,
  _______,            _______, _______,     _______,    _______,

  RGB_VAD, RGB_VAI,
  _______,
  _______, _______,
),
};


/* bool suspended = false; */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LGUI);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_led_all_off();
    switch (get_highest_layer(state)) {
      case _1_BEAKL:
        ergodox_right_led_1_on();
        break;
      case _2_WORKMAN:
        ergodox_right_led_2_on();
        break;
      case _3_NUMBERS:
        ergodox_right_led_3_on();
        break;
      case _4_MOUSE:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      /* case 6: */
      /*   ergodox_right_led_2_on(); */
      /*   ergodox_right_led_3_on(); */
      /*   break; */
      /* case 7: */
      /*   ergodox_right_led_1_on(); */
      /*   ergodox_right_led_2_on(); */
      /*   ergodox_right_led_3_on(); */
      /*   break; */
      default:
        break;
    }
    return state;

};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* case SFT_T(KC_SPC): */
    /*   return TAPPING_TERM + 1250; */
    case LT(_3_NUMBERS, KC_E):
      return 200;
    case LT(_4_MOUSE, KC_R):
      return 200;
    /* case LGUI_T(KC_F): */
    /*   return 50; */
    default:
      return TAPPING_TERM;
  }
}
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(_3_NUMBERS, KC_E):
    case LT(_4_MOUSE, KC_R):
    case LSFT_T(KC_A):
    case LCTL_T(KC_S):
    case LALT_T(KC_D):
    case LGUI_T(KC_F):
    case RGUI_T(KC_J):
    case RALT_T(KC_K):
    case RCTL_T(KC_L):
    case RSFT_T(KC_SCOLON):
    case LEFT_NUMBERS:
    case RIGHT_MOUSE:
      return true;
    default:
      return false;
  }
}


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(_3_NUMBERS, KC_E):
    case LT(_4_MOUSE, KC_R):
    case LSFT_T(KC_A):
    case LCTL_T(KC_S):
    case LALT_T(KC_D):
    case LGUI_T(KC_F):
    case RGUI_T(KC_J):
    case RALT_T(KC_K):
    case RCTL_T(KC_L):
    case RSFT_T(KC_SCOLON):
    case LEFT_NUMBERS:
    case RIGHT_MOUSE:
      return false;
    default:
      return true;
  }
}



LEADER_EXTERNS();

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING ("sudo -i\n");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LGUI("ac"));
      /* SEND_STRING(SS_LGUI("a") SS_LGUI("c")); */
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}
