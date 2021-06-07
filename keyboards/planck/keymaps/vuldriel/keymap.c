/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  CTRLA, 
  ALT_TAB, 
  CTRLC, 
  CTRLV, 
  CTRLE, 
  ALTF4,
  CTRLW, 
  CTRLTAB,
  GIRAFFACT
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2
};

//tap dance enums
enum {
  X_ONE = 1,
  X_TWO = 2,
  X_THR = 3,
  X_FOR = 4,
  X_FIV = 5,
  X_SIX = 6,
  X_SEV = 7,
  X_EIG = 8,
  X_NIN = 9,
  X_ZED = 0
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void one_finished (qk_tap_dance_state_t *state, void *user_data);
void one_reset (qk_tap_dance_state_t *state, void *user_data);
void two_finished (qk_tap_dance_state_t *state, void *user_data);
void two_reset (qk_tap_dance_state_t *state, void *user_data);
void thr_finished (qk_tap_dance_state_t *state, void *user_data);
void thr_reset (qk_tap_dance_state_t *state, void *user_data);
void for_finished (qk_tap_dance_state_t *state, void *user_data);
void for_reset (qk_tap_dance_state_t *state, void *user_data);
void fiv_finished (qk_tap_dance_state_t *state, void *user_data);
void fiv_reset (qk_tap_dance_state_t *state, void *user_data);
void six_finished (qk_tap_dance_state_t *state, void *user_data);
void six_reset (qk_tap_dance_state_t *state, void *user_data);
void sev_finished (qk_tap_dance_state_t *state, void *user_data);
void sev_reset (qk_tap_dance_state_t *state, void *user_data);
void eig_finished (qk_tap_dance_state_t *state, void *user_data);
void eig_reset (qk_tap_dance_state_t *state, void *user_data);
void nin_finished (qk_tap_dance_state_t *state, void *user_data);
void nin_reset (qk_tap_dance_state_t *state, void *user_data);
void zed_finished (qk_tap_dance_state_t *state, void *user_data);
void zed_reset (qk_tap_dance_state_t *state, void *user_data);

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  , KC_Y  , KC_U , KC_I   , KC_O   , KC_P   , KC_BSPC,
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_H  , KC_J , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_MPLY, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_N  , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Caps |NumLck|Insert| Calc |REnter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |OShift|RCtrl | Ralt | RGUI |      |             |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV       , TD(X_ONE), TD(X_TWO), TD(X_THR), TD(X_FOR), TD(X_FIV), TD(X_SIX), TD(X_SEV), TD(X_EIG), TD(X_NIN), TD(X_ZED), KC_BSPC,
    KC_DEL       , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    , KC_MINS  , KC_EQL   , KC_LBRC  , KC_RBRC  , KC_BSLS,
    _______      , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12   , KC_CAPS  , KC_NLCK  , KC_INS   , KC_CALC  , KC_PENT,
    OSM(MOD_LSFT), KC_RCTL  , KC_RALT  , KC_RGUI  , _______  , _______  , _______  , _______  , KC_MPRV  , KC_VOLD  , KC_VOLU  , KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  | Left | Down |  Up  |Right |CtrlW |CtrlTb|   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |CtrlA |AltTab|CtrlC |CtrlV |CtrlE |ALTF4 | Caps |Scroll|Print | Menu |REnter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift|RCtrl | Ralt | RGUI |      |             |      | Home |Pg Up |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR  , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL , KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, CTRLW  , CTRLTAB, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, CTRLA  , ALT_TAB, CTRLC  , CTRLV   , CTRLE  , ALTF4  , KC_CAPS, KC_SLCK, KC_PSCR, KC_APP , KC_PENT,
    KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______ , _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1   , KC_1   , KC_1   , KC_1, KC_1, KC_1   , KC_1   , KC_1, KC_1, KC_1   , KC_1   , KC_1   ,
    XXXXXXX, KC_Q   , KC_W   , KC_E, KC_R, KC_T   , KC_Y   , KC_U, KC_I, KC_O   , KC_P   , KC_LBRC,
    XXXXXXX, KC_A   , KC_S   , KC_D, KC_F, KC_G   , KC_H   , KC_J, KC_K, KC_L   , KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C, KC_V, XXXXXXX, XXXXXXX, KC_N, KC_M, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *               v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |Reset | Debug| Hue+ | Hue- | Sat+ | Sat- | Bri+ | Bri- |Mode +|RGBTog|Plover| Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BL Bth|MouseL|MouseD|MouseU|MouseR|Dacro1|Dacro2|Mouse1|Mouse2|Mouse3|Mouse4| LOCK |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BL Cyc|Beeps-|Beeps+|Mus on|Musoff|Rec 1 |Rec 2 |MWhelL|MWhelD|MWhelU|MWhelR|Sleep |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BL Tog|MUSmod|AudTog|Clicky|      |             |      |GIRAFF|Macro2|Macro3|Macro4|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET  , DEBUG  , RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD        , RGB_VAI        , RGB_VAD, RGB_MODE_FORWARD, RGB_TOG, PLOVER , KC_BSPC,
    BL_BRTG, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_BTN1, KC_BTN2         , KC_BTN3, KC_BTN4, KC_LOCK,
    BL_STEP, CK_DOWN, CK_UP  , MU_ON  , MU_OFF , DYN_REC_START1 , DYN_REC_START2 , KC_WH_L, KC_WH_D         , KC_WH_U, KC_WH_R, KC_SLEP,
    BL_TOGG, MU_MOD , AU_TOG , CK_TOGG, _______, _______        , _______        , _______, GIRAFFACT       , XXXXXXX, XXXXXXX, XXXXXXX
)

};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  } 
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void one_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_1); break;
    case SINGLE_HOLD: register_code(KC_P1); break;
  }
}

void one_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_1); break;
    case SINGLE_HOLD: unregister_code(KC_P1); break;
  }
  xtap_state.state = 0;
}

void two_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_2); break;
    case SINGLE_HOLD: register_code(KC_P2); break;
  }
}

void two_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_2); break;
    case SINGLE_HOLD: unregister_code(KC_P2); break;
  }
  xtap_state.state = 0;
}

void thr_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_3); break;
    case SINGLE_HOLD: register_code(KC_P3); break;
  }
}

void thr_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_3); break;
    case SINGLE_HOLD: unregister_code(KC_P3); break;
  }
  xtap_state.state = 0;
}

void for_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_4); break;
    case SINGLE_HOLD: register_code(KC_P4); break;
  }
}

void for_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_4); break;
    case SINGLE_HOLD: unregister_code(KC_P4); break;
  }
  xtap_state.state = 0;
}

void fiv_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_5); break;
    case SINGLE_HOLD: register_code(KC_P5); break;
  }
}

void fiv_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_5); break;
    case SINGLE_HOLD: unregister_code(KC_P5); break;
  }
  xtap_state.state = 0;
}

void six_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_6); break;
    case SINGLE_HOLD: register_code(KC_P6); break;
  }
}

void six_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_6); break;
    case SINGLE_HOLD: unregister_code(KC_P6); break;
  }
  xtap_state.state = 0;
}

void sev_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_7); break;
    case SINGLE_HOLD: register_code(KC_P7); break;
  }
}

void sev_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_7); break;
    case SINGLE_HOLD: unregister_code(KC_P7); break;
  }
  xtap_state.state = 0;
}

void eig_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_8); break;
    case SINGLE_HOLD: register_code(KC_P8); break;
  }
}

void eig_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_8); break;
    case SINGLE_HOLD: unregister_code(KC_P8); break;
  }
  xtap_state.state = 0;
}

void nin_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_9); break;
    case SINGLE_HOLD: register_code(KC_P9); break;
  }
}

void nin_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_9); break;
    case SINGLE_HOLD: unregister_code(KC_P9); break;
  }
  xtap_state.state = 0;
}

void zed_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_0); break;
    case SINGLE_HOLD: register_code(KC_P0); break;
  }
}

void zed_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_0); break;
    case SINGLE_HOLD: unregister_code(KC_P0); break;
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_ONE]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,one_finished, one_reset),
  [X_TWO]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,two_finished, two_reset),
  [X_THR]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,thr_finished, thr_reset),
  [X_FOR]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,for_finished, for_reset),
  [X_FIV]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,fiv_finished, fiv_reset),
  [X_SIX]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,six_finished, six_reset),
  [X_SEV]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,sev_finished, sev_reset),
  [X_EIG]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,eig_finished, eig_reset),
  [X_NIN]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,nin_finished, nin_reset),
  [X_ZED]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,zed_finished, zed_reset)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif
        
/*const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{14, 2, HSV_TEAL},
	{20, 2, HSV_TEAL}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{16, 2, HSV_GREEN},
	{22, 1, HSV_GREEN},
	{19, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{14, 2, HSV_TEAL},
	{20, 2, HSV_TEAL},
	{16, 2, HSV_GREEN},
	{22, 1, HSV_GREEN},
	{19, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM plover_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{14, 9, HSV_GOLD}
);

const rgblight_segment_t PROGMEM lock_caps[] = RGBLIGHT_LAYER_SEGMENTS(
	{18, 1, HSV_CORAL}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	lower_layer,  //0
	raise_layer,  //1
	adjust_layer, //2
	plover_layer, //3
	lock_caps     //4
);

void keyboard_post_init_user(void) {
	rgblight_layers = my_rgb_layers;
}*/

layer_state_t layer_state_set_user(layer_state_t state) {
	/*rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(2, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(3, layer_state_cmp(state, _PLOVER));*/
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/*void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (IS_LAYER_ON(_ADJUST)) {
		rgblight_blink_layer(_ADJUST, 500);
	}
}

bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(4, led_state.caps_lock);
	return true;
}*/

void shutdown_user() {
  #ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_setrgb(RGB_RED);
  #endif
}

void rgb_matrix_indicators_user(void) {
  switch (get_highest_layer(layer_state)) {
     /*Planck rev6 LED index position:
       6   5   4   3
             0
       7   8   1   2 
  	   Planck rev6 LED physical position:
  	   14  15  16  17
  	         18
  	   20  21  22  19*/
    case _LOWER:
        rgb_matrix_set_color(6, 0x3A, 0x00, 0xFF);
        rgb_matrix_set_color(5, 0x3A, 0x00, 0xFF);
        rgb_matrix_set_color(7, 0x3A, 0x00, 0xFF);
        rgb_matrix_set_color(8, 0x3A, 0x00, 0xFF);
      if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, RGB_RED);
      }
      if (host_keyboard_led_state().num_lock) {
      } else {
        rgb_matrix_set_color(7, RGB_ORANGE);
        rgb_matrix_set_color(8, RGB_ORANGE);
      }
      if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(1, RGB_CORAL);
        rgb_matrix_set_color(2, RGB_CORAL);
      }
    break;
    case _RAISE:
        rgb_matrix_set_color(4, RGB_GREEN);
        rgb_matrix_set_color(3, RGB_GREEN);
        rgb_matrix_set_color(1, RGB_GREEN);
        rgb_matrix_set_color(2, RGB_GREEN);
      if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, RGB_RED);
      }
      if (host_keyboard_led_state().num_lock) {
      } else {
        rgb_matrix_set_color(7, RGB_ORANGE);
        rgb_matrix_set_color(8, RGB_ORANGE);
      }
      if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(1, RGB_CORAL);
        rgb_matrix_set_color(2, RGB_CORAL);
      }
    break;
    case _ADJUST:
        rgb_matrix_set_color(4, RGB_GREEN);
        rgb_matrix_set_color(3, RGB_GREEN);
        rgb_matrix_set_color(1, RGB_GREEN);
        rgb_matrix_set_color(2, RGB_GREEN);
        rgb_matrix_set_color(6, 0x3A, 0x00, 0xFF);
        rgb_matrix_set_color(5, 0x3A, 0x00, 0xFF);
        rgb_matrix_set_color(7, 0x3A, 0x00, 0xFF);
        rgb_matrix_set_color(8, 0x3A, 0x00, 0xFF);
      if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, RGB_RED);
      }
      if (host_keyboard_led_state().num_lock) {
      } else {
        rgb_matrix_set_color(7, RGB_ORANGE);
        rgb_matrix_set_color(8, RGB_ORANGE);
      }
      if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(1, RGB_CORAL);
        rgb_matrix_set_color(2, RGB_CORAL);
      }
    break;
    case _PLOVER:
        rgb_matrix_set_color(6, RGB_CHARTREUSE);
        rgb_matrix_set_color(5, RGB_CHARTREUSE);
        rgb_matrix_set_color(4, RGB_GOLDENROD);
        rgb_matrix_set_color(3, RGB_GOLDENROD);
        rgb_matrix_set_color(0, RGB_WHITE);
        rgb_matrix_set_color(7, RGB_GOLDENROD);
        rgb_matrix_set_color(8, RGB_GOLDENROD);
        rgb_matrix_set_color(1, RGB_CHARTREUSE);
        rgb_matrix_set_color(2, RGB_CHARTREUSE);
    break;
    case _QWERTY:
      if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, RGB_RED);
      }
      if (host_keyboard_led_state().num_lock) {
      } else {
        rgb_matrix_set_color(7, RGB_ORANGE);
        rgb_matrix_set_color(8, RGB_ORANGE);
      }
      if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(1, RGB_CORAL);
        rgb_matrix_set_color(2, RGB_CORAL);
      }
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GIRAFFACT:
      if (record->event.pressed) {
        SEND_STRING("Did you know that if you submerge a giraffe up to the point where its head is the only thing sticking out of the water, it will still suffocate due to the air-water pressure differential?");
      } else {
      }
      return true;
      break;
    case CTRLA:
      if (record->event.pressed) {
      	tap_code16(C(KC_A));
      } else {
      }
      return true;
      break;
    case ALT_TAB:
      if (record->event.pressed) {
      	if (!is_alt_tab_active) {
          is_alt_tab_active =  true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return true;
      break; 
    case CTRLC:
      if (record->event.pressed) {
      	tap_code16(C(KC_C));
      } else {
      }
      return true;
      break;
    case CTRLV:
      if (record->event.pressed) {
      	tap_code16(C(KC_V));
      } else {
      }
      return true;
      break;
    case CTRLE:
      if (record->event.pressed) {
      	tap_code16(C(KC_E));
      } else {
      }
      return true;
      break; 
    case CTRLW:
      if (record->event.pressed) {
      	tap_code16(C(KC_W));
      } else {
      }
      return true;
      break;
    case ALTF4:
      if (record->event.pressed) {
      	tap_code16(A(KC_F4));
      } else {
      }
      return true;
      break;
    case CTRLTAB:
      if (record->event.pressed) {
      	tap_code16(C(KC_TAB));
      } else {
      }
      return true;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (IS_LAYER_ON(_QWERTY)) {
      if (clockwise) {
       tap_code(KC_VOLU);
      } else {
       tap_code(KC_VOLD);
      }
    } else if (IS_LAYER_ON(_PLOVER)) {
      if (clockwise) {
       tap_code(KC_VOLU);
      } else {
       tap_code(KC_VOLD);
      }
    } else if (IS_LAYER_ON(_ADJUST)) {      
      if (clockwise) {
       rgb_matrix_increase_speed();
      } else {
       rgb_matrix_decrease_speed();
      }
    } else if (IS_LAYER_ON(_LOWER)) {
      if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
          tap_code(KC_MS_WH_DOWN);
        #else
          tap_code(KC_PGDN);
        #endif
      } else {
        #ifdef MOUSEKEY_ENABLE
          tap_code(KC_MS_WH_UP);
        #else
        tap_code(KC_PGUP);
        #endif
      }  
    } else if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
       tap_code16(C(KC_RIGHT));
      } else {
       tap_code16(C(KC_LEFT));
      }
    }
  }
    return true;
}

/*void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}*/

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
    if (is_alt_tab_active) {
    	if (timer_elapsed(alt_tab_timer) > 500) {
    		unregister_code(KC_LALT);
    		is_alt_tab_active = false;
    	}
    }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

float tone_caps_on[][2]    = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]   = SONG(CAPS_LOCK_OFF_SOUND);
float tone_numlk_on[][2]   = SONG(NUM_LOCK_ON_SOUND);
float tone_numlk_off[][2]  = SONG(NUM_LOCK_OFF_SOUND);
float tone_scroll_on[][2]  = SONG(SCROLL_LOCK_ON_SOUND);
float tone_scroll_off[][2] = SONG(SCROLL_LOCK_OFF_SOUND);

#ifdef AUDIO_ENABLE

void matrix_init_user(void)
{
    set_voice(default_voice);
    startup_user();
    println("Matrix Init"); 
}

void led_set_user(uint8_t usb_led)
{
    static uint8_t old_usb_led = 0;

    //_delay_ms(10); // gets rid of tick
    if (!is_playing_notes())
    {
        if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK)))
        {
          // If CAPS LK LED is turning on...
          stop_all_notes();
          PLAY_SONG(tone_caps_on);
        }
        else if (!(usb_led & (1<<USB_LED_CAPS_LOCK)) && (old_usb_led & (1<<USB_LED_CAPS_LOCK)))
        {
                // If CAPS LK LED is turning off...
          stop_all_notes();
          PLAY_SONG(tone_caps_off);
        }
        if ((usb_led & (1<<USB_LED_NUM_LOCK)) && !(old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
          // If NUM LK LED is turning on...
          stop_all_notes();
          PLAY_SONG(tone_numlk_on);
        }
        else if (!(usb_led & (1<<USB_LED_NUM_LOCK)) && (old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
          // If NUM LED is turning off...
          stop_all_notes();
          PLAY_SONG(tone_numlk_off);
        }
        if ((usb_led & (1<<USB_LED_SCROLL_LOCK)) && !(old_usb_led & (1<<USB_LED_SCROLL_LOCK)))
        {
          // If SCROLL LK LED is turning on...
          stop_all_notes();
          PLAY_SONG(tone_scroll_on);
        }
        else if (!(usb_led & (1<<USB_LED_SCROLL_LOCK)) && (old_usb_led & (1<<USB_LED_SCROLL_LOCK)))
        {
          // If SCROLL LED is turning off...
          stop_all_notes();
          PLAY_SONG(tone_scroll_off);
        }
    }

    old_usb_led = usb_led;
}
    #endif
