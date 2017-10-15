/*
This is the keymap for the keyboard
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

// Define layer names 
#define QWERTY 0
#define COLEMAK 1
#define DVORAK 2
#define WORKMAN 3
#define SYMB 8
#define OVERWATCH 9
#define DIABLO 10
#define MOUS 12
<<<<<<< HEAD

//Leader Key stuff
#ifdef LEADER_TIMEOUT
#undef LEADER_TIMEOUT
#endif
#define LEADER_TIMEOUT 1500
=======
>>>>>>> Updated macros and added workman keymaps
<<<<<<< HEAD

=======
>>>>>>> Updated macros and added workman keymaps



//define modifiers
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated RGB Underglow info
=======
>>>>>>> Updated macros and added workman keymaps
=======

//define macro keycodes
#define M_VERSION M(0)
#define M_MAKE M(1)
>>>>>>> Updated RGB Underglow info
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Updated RGB Underglow info
=======
=======
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
 
=======

>>>>>>> Fixed formatting to fall in line with official standards
//define layer change stuff for underglow indicator
bool skip_leds = false;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Tweaked RGB lighting stuff
#ifdef RGBLIGHT_ENABLE
#define rgblight_set_blue        rgblight_sethsv (0xFF,  0xFF, 0xFF);
#define rgblight_set_red         rgblight_sethsv (0x00,  0xFF, 0xFF);
#define rgblight_set_green       rgblight_sethsv (0x78,  0xFF, 0xFF);
#define rgblight_set_orange      rgblight_sethsv (0x1E,  0xFF, 0xFF);
#define rgblight_set_teal        rgblight_sethsv (0xC3,  0xFF, 0xFF);
#define rgblight_set_magenta     rgblight_sethsv (0x12C, 0xFF, 0xFF);
#define rgblight_set_yellow      rgblight_sethsv (0x3C,  0xFF, 0xFF);
#define rgblight_set_purple      rgblight_sethsv (0x10E, 0xFF, 0xFF);
<<<<<<< HEAD
#endif
=======
=======
#ifdef RGBLIGHT_ENABLE
>>>>>>> Fix makefile toggle code in ez keymap
#define rgblight_set_blue rgblight_sethsv (0xFF, 0xFF, 0xFF);
#define rgblight_set_red rgblight_sethsv(0x00, 0xFF, 0xFF);
#define rgblight_set_green rgblight_sethsv (0x78, 0xFF, 0xFF);
#define rgblight_set_orange rgblight_sethsv (0x1E, 0xFF, 0xFF);
#define rgblight_set_teal rgblight_sethsv (0xC3, 0xFF, 0xFF);
#define rgblight_set_magenta rgblight_sethsv (0x12C, 0xFF, 0xFF);
#define rgblight_set_urine rgblight_sethsv (0x3C, 0xFF, 0xFF);
#define rgblight_set_purple rgblight_sethsv (0x10E, 0xFF, 0xFF);
#endif
<<<<<<< HEAD
//This is both for underglow, and Diablo 3 macros

static uint8_t current_layer = 0;
>>>>>>> Tweaked RGB lighting stuff
=======
#endif
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function
=======
=======
#define rgblight_set_blue rgblight_sethsv (0xFF, 0xFF, 0xFF);
#define rgblight_set_red rgblight_sethsv(0x00, 0xFF, 0xFF);
#define rgblight_set_green rgblight_sethsv (0x78, 0xFF, 0xFF);
#define rgblight_set_orange rgblight_sethsv (0x1E, 0xFF, 0xFF);
#define rgblight_set_teal rgblight_sethsv (0xC3, 0xFF, 0xFF);
#define rgblight_set_magenta rgblight_sethsv (0x12C, 0xFF, 0xFF);
#define rgblight_set_urine rgblight_sethsv (0x3C, 0xFF, 0xFF);
#define rgblight_set_aqua rgblight_sethsv (0x10E, 0xFF, 0xFF);
//This is both for underglow, and Diablo 3 macros

static uint8_t current_layer = 0;
>>>>>>> Tweaked RGB lighting stuff
>>>>>>> Tweaked RGB lighting stuff

//define diablo macro timer variables
static uint16_t diablo_timer[4];
static uint8_t diablo_times[] = { 0, 1, 3, 5, 10, 30 };
static uint8_t diablo_key_time[4];

bool check_dtimer(uint8_t dtimer) {
  // has the correct number of seconds elapsed (as defined by diablo_times)
  return (timer_elapsed(diablo_timer[dtimer]) < (diablo_key_time[dtimer] * 1000)) ? false : true;
};


enum custom_keycodes {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Tweaked RGB lighting stuff
=======
=======
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD,
    RGB_0000FF,
    RGB_008000,
    RGB_FF0000,
    RGB_800080,
    RGB_00FF90,
<<<<<<< HEAD
    KC_DIABLO_CLEAR,
    KC_QWERTY,
    KC_COLEMAK,
    KC_DVORAK,
    KC_WORKMAN,
    KC_MAKEQMK
=======
	PLACEHOLDER = SAFE_RANGE, // can always be here
	EPRM,
	VRSN,
	RGB_SLD,
	RGB_0000FF,
	RGB_008000,
	RGB_FF0000,
	RGB_800080,
	RGB_00FF90,
    KC_DIABLO_CLEAR,
    KC_QWERTY,
    KC_COLEMAK,
    KC_DVORAK
>>>>>>> Tweaked RGB lighting stuff
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
    KC_DIABLO_CLEAR,
    KC_QWERTY,
    KC_COLEMAK,
    KC_DVORAK,
    KC_WORKMAN,
    KC_MAKEQMK
>>>>>>> Updated macros and added workman keymaps
<<<<<<< HEAD
=======
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  RGB_0000FF,
  RGB_008000,
  RGB_FF0000,
  RGB_800080,
  RGB_00FF90,
  KC_DIABLO_CLEAR,
  KC_QWERTY,
  KC_COLEMAK,
  KC_DVORAK,
  KC_WORKMAN,
<<<<<<< HEAD
  KC_MAKEQMK
>>>>>>> Fixed formatting to fall in line with official standards
=======
  KC_MAKEQMK,
  KC_RESET
>>>>>>> Tweak reset code
=======
>>>>>>> Tweaked RGB lighting stuff
=======
>>>>>>> Updated macros and added workman keymaps
};

#ifdef TAP_DANCE_ENABLE
enum {
  TD_FLSH = 0,
  TD_DIABLO_1,
  TD_DIABLO_2,
  TD_DIABLO_3,
  TD_DIABLO_4
};




// on each tap, light up one led, from right to left
// on the forth tap, turn them off from right to left

void dance_flsh_each(qk_tap_dance_state_t *state, void *user_data) {
  if (!skip_leds) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    skip_leds = true;
  }
  switch (state->count) {
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_2_on();
    break;
  case 3:
    ergodox_right_led_3_on();
    break;
  case 4:
    ergodox_right_led_1_off();
    _delay_ms(50);
    ergodox_right_led_2_off();
    _delay_ms(50);
    ergodox_right_led_3_off();

  }
}

// on the fourth tap, set the keyboard on flash state
// and set the underglow to red, because red == bad
void dance_flsh_finished(qk_tap_dance_state_t *state, void *user_data) {
<<<<<<< HEAD
    if (state->count >= 4) {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
  if (state->count >= 4) {
>>>>>>> Fixed formatting to fall in line with official standards
#ifdef RGBLIGHT_ENABLE
    rgblight_enable();
    rgblight_mode(1);
    rgblight_setrgb(0xff, 0x00, 0x00);
#endif
<<<<<<< HEAD
<<<<<<< HEAD
        reset_tap_dance(state);
        reset_keyboard();
=======
=======
=======
>>>>>>> Updated macros and added workman keymaps
#ifdef RGBLIGHT_ENABLE
>>>>>>> Fix makefile toggle code in ez keymap
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(0xff,0x00,0x00);
#endif
        reset_keyboard();
        reset_tap_dance(state);
>>>>>>> Updated macros and added workman keymaps
=======
        reset_tap_dance(state);
        reset_keyboard();
<<<<<<< HEAD
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function
=======
=======
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(0xff,0x00,0x00);
        reset_keyboard();
        reset_tap_dance(state);
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
    }
=======
    reset_tap_dance(state);
    reset_keyboard();
  }
>>>>>>> Fixed formatting to fall in line with official standards
}

// Cycle through the times for the macro, starting at 0, for disabled.
// Max of six values, so don't exceed
void diablo_tapdance_master(qk_tap_dance_state_t *state, void *user_data, uint8_t diablo_key) {
  if (state->count >= 7) {
    diablo_key_time[diablo_key] = diablo_times[0];
    reset_tap_dance(state);
  }
  else {
    diablo_key_time[diablo_key] = diablo_times[state->count - 1];
  }
}


// Would rather have one function for all of this, but no idea how to do that...
void diablo_tapdance1(qk_tap_dance_state_t *state, void *user_data) {
  diablo_tapdance_master(state, user_data, 0);
}

void diablo_tapdance2(qk_tap_dance_state_t *state, void *user_data) {
  diablo_tapdance_master(state, user_data, 1);
}

void diablo_tapdance3(qk_tap_dance_state_t *state, void *user_data) {
  diablo_tapdance_master(state, user_data, 2);
}

void diablo_tapdance4(qk_tap_dance_state_t *state, void *user_data) {
  diablo_tapdance_master(state, user_data, 3);
}


// if the flash state didnt happen, then turn off leds, left to right
void dance_flsh_reset(qk_tap_dance_state_t *state, void *user_data) {
  _delay_ms(200);
  ergodox_right_led_3_off();
  _delay_ms(200);
  ergodox_right_led_2_off();
  _delay_ms(200);
  ergodox_right_led_1_off();
  _delay_ms(500);
  skip_leds = false;
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Once for Blue, Twice for Green, Thrice for Red, and four to flash
  [TD_FLSH] = ACTION_TAP_DANCE_FN_ADVANCED(dance_flsh_each, dance_flsh_finished, dance_flsh_reset),
  // tap once to disable, and more to enable timed micros
  [TD_DIABLO_1] = ACTION_TAP_DANCE_FN(diablo_tapdance1),
  [TD_DIABLO_2] = ACTION_TAP_DANCE_FN(diablo_tapdance2),
  [TD_DIABLO_3] = ACTION_TAP_DANCE_FN(diablo_tapdance3),
  [TD_DIABLO_4] = ACTION_TAP_DANCE_FN(diablo_tapdance4),

};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * 
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   = +  |  1 ! | 2 @  | 3 #  | 4 $  | 5 %  | TG(4)|           | TG(4)| 6 ^  | 7 &  |  8 * | 9 (  |  0 ) |  - _   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  | TG(3)|           |TG(3) |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Bksp  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  ' "   |
 * |--------+------+------+------+------+------| TG(2)|           | TG(2)|------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  , < |  . > |  ? / | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | `/SYM|  ' " | LGUI |  [ { | ] }  |                                       | LEFT | DOWN |  UP  |RIGHT | SYMB |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,--------------.
 *                                        |Alt/Ap|  Win  |       | Alt  |Ctl/Esc|
 *                                 ,------|------|-------|       |------+-------+------.
 *                                 |      |      | Home  |       | PgUp |       |      |
 *                                 | Space| Bksp |-------|       |------|  DEL  |Enter |
 *                                 |      |      | End   |       | PgDn |       |      |
 *                                 `---------------------'       `---------------------'
 */
  [QWERTY] = KEYMAP(
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Tweaked RGB lighting stuff
=======
>>>>>>> Updated macros and added workman keymaps
                KC_EQUAL,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       TG(MOUS),
                KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       TG(DIABLO),
                KC_BSPACE,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
                KC_LSHIFT,      LCTL_T(KC_Z),KC_X,       KC_C,       KC_V,       KC_B,       TG(OVERWATCH),
                LT(SYMB,KC_GRAVE),KC_QUOTE, KC_LGUI,    KC_LBRACKET,KC_RBRACKET,
=======
				KC_EQUAL,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       TG(MOUS),
				KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       TG(DIABLO),
				KC_BSPACE,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
                KC_LSHIFT,      CTL_T(KC_Z),KC_X,       KC_C,       KC_V,       KC_B,       TG(OVERWATCH),
				LT(SYMB,KC_GRAVE),KC_QUOTE, KC_LGUI,    KC_LBRACKET,KC_RBRACKET,
>>>>>>> Tweaked RGB lighting stuff
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
                KC_EQUAL,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       TG(MOUS),
                KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       TG(DIABLO),
                KC_BSPACE,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
<<<<<<< HEAD
                KC_LSHIFT,      LCTL_T(KC_Z),KC_X,       KC_C,       KC_V,       KC_B,       TG(OVERWATCH),
                LT(SYMB,KC_GRAVE),KC_QUOTE, KC_LGUI,    KC_LBRACKET,KC_RBRACKET,
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Tweaked RGB lighting stuff
=======
                KC_LSHIFT,      CTL_T(KC_Z),KC_X,       KC_C,       KC_V,       KC_B,       TG(OVERWATCH),
                LT(SYMB,KC_GRAVE),KC_QUOTE, KC_LGUI,    KC_LBRACKET,KC_RBRACKET,
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
                
                                    ALT_T(KC_APPLICATION),  KC_LGUI,
                                                            KC_HOME,
                                    KC_SPACE,   KC_BSPACE,  KC_END,
                                    
                TG(MOUS),       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,           KC_MINUS,
                TG(DIABLO),     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,           KC_BSLASH,
                                KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,      GUI_T(KC_QUOTE),
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
                TG(OVERWATCH),  KC_N,       KC_M,       KC_COMMA,   KC_DOT,     RCTL_T(KC_SLASH),KC_RSHIFT,
                                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       TT(SYMB),
<<<<<<< HEAD
<<<<<<< HEAD
                KC_LEAD,    CTL_T(KC_ESCAPE),
=======
                TG(OVERWATCH),  KC_N,       KC_M,       KC_COMMA,   KC_DOT,     CTL_T(KC_SLASH),KC_RSHIFT,
=======
                TG(OVERWATCH),  KC_N,       KC_M,       KC_COMMA,   KC_DOT,     RCTL_T(KC_SLASH),KC_RSHIFT,
>>>>>>> Add Viterbi one handed layout and minor tweaks to others
                                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       KC_FN1,
<<<<<<< HEAD
                KC_LALT,    CTL_T(KC_ESCAPE),
>>>>>>> Updated macros and added workman keymaps
=======
=======
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function
                KC_LEAD,    CTL_T(KC_ESCAPE),
<<<<<<< HEAD
>>>>>>> Clean up and updates of drashna keymaps
=======
                KC_RGUI,    CTL_T(KC_ESCAPE),
>>>>>>> Tweak reset code
=======
=======
                TG(OVERWATCH),  KC_N,       KC_M,       KC_COMMA,   KC_DOT,     CTL_T(KC_SLASH),KC_RSHIFT,
                                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       KC_FN1,
                KC_LALT,    CTL_T(KC_ESCAPE),
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
                KC_PGUP,
                KC_PGDOWN,  KC_DELETE,  KC_ENTER
            ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L1  |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |O / L2|   '    |
 * |--------+------+------+------+------+------| OVER |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[COLEMAK] = KEYMAP(  
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(MOUS),
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        KC_TAB,         KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   TG(DIABLO),
=======
        KC_TAB,        KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   TG(DIABLO),
>>>>>>> Updated macros and added workman keymaps
=======
        KC_TAB,         KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   TG(DIABLO),
>>>>>>> Add Viterbi one handed layout and minor tweaks to others
=======
        KC_TAB,         KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   TG(DIABLO),
=======
        KC_TAB,        KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   TG(DIABLO),
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
        KC_BSPC,        KC_A,         KC_R,   KC_S,   KC_T,   KC_D,
        KC_LSFT,        LCTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   TG(OVERWATCH),
        LT(SYMB,KC_GRV),KC_QUOT,      KC_LGUI,    KC_LBRACKET,KC_RBRACKET,
                                              ALT_T(KC_APP),  KC_LEAD,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
             TG(MOUS),    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(DIABLO),  KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,          KC_BSLS,
                          KC_H,   KC_N,   KC_E,   KC_I,   KC_O,             GUI_T(KC_QUOTE),
             TG(OVERWATCH),KC_K,  KC_M,   KC_COMM,KC_DOT, RCTL_T(KC_SLASH), KC_RSHIFT,
                          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       TT(SYMB),
=======
             KC_TRNS,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(DVORAK),  KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,          KC_BSLS,
                          KC_H,   KC_N,   KC_E,   KC_I,   LT(MOUS, KC_O),   KC_QUOTE,
             TG(COLEMAK), KC_K,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLASH),KC_RSHIFT,
						  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       KC_FN1,
>>>>>>> Tweaked RGB lighting stuff
=======
=======
>>>>>>> Tweaked RGB lighting stuff
=======
>>>>>>> Updated macros and added workman keymaps
             TG(MOUS),    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(DIABLO),  KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,          KC_BSLS,
                          KC_H,   KC_N,   KC_E,   KC_I,   KC_O,             GUI_T(KC_QUOTE),
             TG(OVERWATCH),KC_K,  KC_M,   KC_COMM,KC_DOT, RCTL_T(KC_SLASH), KC_RSHIFT,
<<<<<<< HEAD
                          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       KC_FN1,
>>>>>>> Updated macros and added workman keymaps
=======
                          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       TT(SYMB),
<<<<<<< HEAD
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function
=======
=======
             KC_TRNS,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(DVORAK),  KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,          KC_BSLS,
                          KC_H,   KC_N,   KC_E,   KC_I,   LT(MOUS, KC_O),   KC_QUOTE,
             TG(COLEMAK), KC_K,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLASH),KC_RSHIFT,
						  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       KC_FN1,
>>>>>>> Tweaked RGB lighting stuff
<<<<<<< HEAD
>>>>>>> Tweaked RGB lighting stuff
=======
=======
             TG(MOUS),    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(DIABLO),  KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,          KC_BSLS,
                          KC_H,   KC_N,   KC_E,   KC_I,   LT(MOUS, KC_O),   KC_QUOTE,
             TG(OVERWATCH),KC_K,  KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLASH),  KC_RSHIFT,
                          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       KC_FN1,
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_DELETE, KC_ENT
    ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   '  |   ,  |   .  |   P  |   Y  |  L1  |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[DVORAK] = KEYMAP(  
        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   TG(MOUS),
        KC_TAB,        KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,   TG(DIABLO),
        KC_BSPC,        KC_A,           KC_O,    KC_E,   KC_U,   KC_I,
        KC_LSFT,        LCTL_T(KC_SCLN), KC_Q,    KC_J,   KC_K,   KC_X,   TG(OVERWATCH),
        LT(SYMB,KC_GRV),KC_QUOT, KC_LGUI, KC_LBRACKET, KC_RBRACKET,
                                              ALT_T(KC_APP),  KC_LEAD,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Tweaked RGB lighting stuff
=======
>>>>>>> Updated macros and added workman keymaps
             TG(MOUS),     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,        KC_BSLS,
             TG(DIABLO),   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,        KC_SLSH,
                           KC_D,   KC_H,   KC_T,   KC_N,   KC_S,        KC_MINS,
             TG(OVERWATCH),KC_B,   KC_M,   KC_W,   KC_V,   RCTL_T(KC_Z), KC_RSHIFT,
                                   KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,    TT(SYMB),
=======
             KC_TRNS,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSLS,
             TG(DVORAK),  KC_F,   KC_G,   KC_C,   KC_R,   KC_L,             KC_SLSH,
                          KC_D,   KC_H,   KC_T,   KC_N,   LT(MOUS, KC_S),   KC_MINS,
             TG(COLEMAK), KC_B,   KC_M,   KC_W,   KC_V,   CTL_T(KC_Z),      KC_RSHIFT,
	                       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_FN1,
>>>>>>> Tweaked RGB lighting stuff
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
             TG(MOUS),     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,        KC_BSLS,
             TG(DIABLO),   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,        KC_SLSH,
                           KC_D,   KC_H,   KC_T,   KC_N,   KC_S,        KC_MINS,
<<<<<<< HEAD
             TG(OVERWATCH),KC_B,   KC_M,   KC_W,   KC_V,   RCTL_T(KC_Z), KC_RSHIFT,
<<<<<<< HEAD
                                   KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,    KC_FN1,
>>>>>>> Updated macros and added workman keymaps
=======
                                   KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,    TT(SYMB),
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function
=======
>>>>>>> Tweaked RGB lighting stuff
=======
             TG(OVERWATCH),KC_B,   KC_M,   KC_W,   KC_V,   CTL_T(KC_Z), KC_RSHIFT,
                                   KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,    KC_FN1,
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_DELETE, KC_ENT
    ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L1  |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |O / L2|   '    |
 * |--------+------+------+------+------+------| OVER |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[WORKMAN] = KEYMAP(  
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(MOUS),
        KC_TAB,         KC_Q,         KC_D,   KC_R,   KC_W,   KC_B,   TG(DIABLO),
        KC_BSPC,        KC_A,         KC_S,   KC_H,   KC_T,   KC_G,
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        KC_LSFT,        LCTL_T(KC_Z),  KC_X,   KC_M,   KC_C,   KC_V,   TG(OVERWATCH),
        LT(SYMB,KC_GRV),KC_QUOT,      KC_LGUI,    KC_LBRACKET,KC_RBRACKET,
                                              ALT_T(KC_APP),  KC_LEAD,
=======
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_M,   KC_C,   KC_V,   TG(OVERWATCH),
=======
=======
>>>>>>> Updated macros and added workman keymaps
        KC_LSFT,        LCTL_T(KC_Z),  KC_X,   KC_M,   KC_C,   KC_V,   TG(OVERWATCH),
>>>>>>> Add Viterbi one handed layout and minor tweaks to others
        LT(SYMB,KC_GRV),KC_QUOT,      KC_LGUI,    KC_LBRACKET,KC_RBRACKET,
<<<<<<< HEAD
                                              ALT_T(KC_APP),  KC_LGUI,
>>>>>>> Updated macros and added workman keymaps
=======
                                              ALT_T(KC_APP),  KC_LEAD,
<<<<<<< HEAD
>>>>>>> Add leader keys
=======
=======
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_M,   KC_C,   KC_V,   TG(OVERWATCH),
        LT(SYMB,KC_GRV),KC_QUOT,      KC_LGUI,    KC_LBRACKET,KC_RBRACKET,
                                              ALT_T(KC_APP),  KC_LGUI,
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             TG(MOUS),    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(DIABLO),  KC_J,   KC_F,   KC_U,   KC_P,   KC_SCLN,          KC_BSLS,
                          KC_Y,   KC_N,   KC_E,   KC_O,   KC_I,             KC_QUOTE,
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
             TG(OVERWATCH),KC_K,  KC_L,   KC_COMM,KC_DOT, RCTL_T(KC_SLASH), KC_RSHIFT,
                          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       TT(SYMB),
<<<<<<< HEAD
=======
             TG(OVERWATCH),KC_K,  KC_L,   KC_COMM,KC_DOT, CTL_T(KC_SLASH),  KC_RSHIFT,
=======
             TG(OVERWATCH),KC_K,  KC_L,   KC_COMM,KC_DOT, RCTL_T(KC_SLASH), KC_RSHIFT,
>>>>>>> Add Viterbi one handed layout and minor tweaks to others
                          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       KC_FN1,
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function
=======
             TG(OVERWATCH),KC_K,  KC_L,   KC_COMM,KC_DOT, RCTL_T(KC_SLASH), KC_RSHIFT,
                          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       TT(SYMB),
=======
             TG(OVERWATCH),KC_K,  KC_L,   KC_COMM,KC_DOT, CTL_T(KC_SLASH),  KC_RSHIFT,
                          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,       KC_FN1,
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_DELETE, KC_ENT
    ),

    /* Keymap 3: Symbol Layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |   F11  |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* | VERSION|   !  |   @  |  {   |   }  |  |   |      |           |      |  +   |   7  |   8  |   9  |  *   |   F12  |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |  MAKE  |   #  |   $  |  (   |   )  |  `   |------|           |------|  -   |   4  |   5  |   6  |  /   | PrtSc  |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |  RESET |   %  |   ^  |  [   |   ]  |  ~   |      |           |      | NUM  |   1  |   2  |   3  |  =   |  PAUSE |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |  LT0 |   &  |   *  |  :   |   ;  |                                       |      |   0  | NUM. | ENT  |  ENT |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        | RGBM | RED  |       | OFF  | SOLID|
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      | GREEN|       |      |      |      |
*                                 | RGB  | RGB  |------|       |------| NUM0 | NUME |
*                                 | DARK |BRITE | BLUE |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
  [SYMB] = KEYMAP(
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Add forced NKRO
=======
=======
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
                KC_ESCAPE,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_WORKMAN,
                VRSN,           KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_DVORAK,
                KC_MAKEQMK,     KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRAVE,
<<<<<<< HEAD
                TD(TD_FLSH),    KC_PERC,    KC_CIRC,    KC_LBRACKET,KC_RBRACKET,KC_TILD,    KC_COLEMAK,
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
                KC_TRNS,          KC_AMPR,    KC_ASTR,    KC_COLN,    KC_SCOLON,
=======
                KC_NO,          KC_AMPR,    KC_ASTR,    KC_COLN,    KC_SCOLON,
>>>>>>> Updated macros and added workman keymaps
=======
                KC_TRNS,          KC_AMPR,    KC_ASTR,    KC_COLN,    KC_SCOLON,
>>>>>>> Clean up and updates of drashna keymaps
=======
                KC_TRNS,          KC_AMPR,    KC_ASTR,    KC_COLN,    KC_SCOLON,
=======
                KC_NO,          KC_AMPR,    KC_ASTR,    KC_COLN,    KC_SCOLON,
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
                                                                  KC_TRNS, KC_TRNS,
=======
                KC_RESET,       KC_PERC,    KC_CIRC,    KC_LBRACKET,KC_RBRACKET,KC_TILD,    KC_COLEMAK,
                KC_TRNS,          KC_AMPR,    KC_ASTR,    KC_COLN,    KC_SCOLON,
    RGB_MODE_RAINBOW, KC_TRNS,
>>>>>>> Tweak reset code
                                                                  KC_TRNS,
                                                                  KC_TRNS, KC_TRNS, KC_TRNS,
                
                KC_QWERTY,   KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,         KC_F11,
                KC_DVORAK,   KC_KP_PLUS, KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_ASTERISK, KC_F12,
                             KC_KP_MINUS,KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_SLASH,    KC_PSCREEN,
                KC_COLEMAK,  KC_NUMLOCK, KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_EQUAL,       KC_PAUSE,
                                         KC_KP_0,    KC_KP_0,    KC_KP_DOT,  KC_KP_ENTER,    KC_TRNS,
                RGB_TOG,    RGB_SLD,
                KC_NO,
                KC_KP_DOT, KC_KP_0, KC_KP_ENTER
            ),
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Add forced NKRO
=======
>>>>>>> Updated macros and added workman keymaps
=======
				KC_ESCAPE,KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_TRNS,
				M_VERSION,      KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_TRNS,
				M_MAKE,         KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRAVE,
				TD(TD_FLSH),    KC_PERC,    KC_CIRC,    KC_LBRACKET,KC_RBRACKET,KC_TILD,    KC_TRNS,
				KC_NO,          KC_AMPR,    KC_ASTR,    KC_COLN,    KC_SCOLON,
	                                                              KC_TRNS, KC_TRNS,
	                                                              KC_TRNS,
	                                                              KC_TRNS, KC_TRNS, KC_TRNS,
				
				KC_QWERTY, KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,         KC_F11,
				KC_DVORAK, KC_KP_PLUS, KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_ASTERISK, KC_F12,
				KC_KP_MINUS,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_SLASH,KC_PSCREEN,
				KC_COLEMAK, KC_NUMLOCK, KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_EQUAL,       KC_PAUSE,
	                                 KC_KP_0,    KC_KP_0,    KC_KP_DOT,  KC_KP_ENTER,    KC_TRNS,
				RGB_TOG,    RGB_SLD,
				KC_NO,
				KC_KP_DOT, KC_KP_0, KC_KP_ENTER
			),
>>>>>>> Add forced NKRO
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Add forced NKRO
=======
=======
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps

/* Keymap 4: Customized Overwatch Layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |      |      |      |      |      |      |           |      |  F9  | F10  | F11  |  F12 |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   F1   |  K   |  Q   |  W   |  E   |  R   |  T   |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   TAB  |  G   |  A   |  S   |  D   |  F   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
 * |  LCTR  | LSHFT|  Z   |  X   |  C   |  V   |      |           |      |   N  |  M   |      |      |      |        |
=======
 * |  LCTR  | LSHFT|  Z   |  X   |  C   |  V   |      |           |      |   O  |   M  |      |      |      |        |
>>>>>>> Cleanup macros
=======
 * |  LCTR  | LSHFT|  Z   |  X   |  C   |  V   |      |           |      |   N  |  M   |      |      |      |        |
>>>>>>> Tweaked RGB lighting stuff
=======
=======
>>>>>>> Tweaked RGB lighting stuff
 * |  LCTR  | LSHFT|  Z   |  X   |  C   |  V   |      |           |      |   N  |  M   |      |      |      |        |
=======
 * |  LCTR  | LSHFT|  Z   |  X   |  C   |  V   |      |           |      |   O  |   M  |      |      |      |        |
>>>>>>> Cleanup macros
<<<<<<< HEAD
>>>>>>> Cleanup macros
=======
=======
 * |  LCTR  | LSHFT|  Z   |  X   |  C   |  V   |      |           |      |   N  |  M   |      |      |      |        |
>>>>>>> Tweaked RGB lighting stuff
>>>>>>> Tweaked RGB lighting stuff
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   J  |  U   |  I   |  Y   |  T   |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  O   |  P   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LGUI |       |      |      |      |
 *                                 |  V   | SPACE|------        |------|      | Enter|
 *                                 |      |      |  H   |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [OVERWATCH] = KEYMAP(
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Updated RGB Underglow info
=======
=======
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
                KC_ESCAPE,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_F1,          KC_K,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
                KC_TAB,         KC_G,       KC_A,       KC_S,       KC_D,       KC_F,
                KC_LCTL,        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_TRNS,
                KC_G,           KC_U,       KC_I,       KC_Y,       KC_T,
<<<<<<< HEAD
                                            KC_O,   KC_P,
                                                    KC_LGUI,
                                KC_V,   KC_SPACE,   KC_H,
                                    
                KC_TRNS,        KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,
                KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                TG(OVERWATCH),  KC_N,       KC_M,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
=======
				KC_ESCAPE,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
				KC_F1,          KC_K,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
				KC_TAB,         KC_G,       KC_A,       KC_S,       KC_D,       KC_F,
				KC_LCTL,        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_TRNS,
				KC_G,           KC_U,       KC_I,       KC_Y,       KC_T,
                                            KC_O,   KC_P,
                                                    KC_LGUI,
                                KC_V,   KC_SPACE,   KC_H,
									
				KC_NO,          KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,
				KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
<<<<<<< HEAD
				KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
<<<<<<< HEAD
				KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
>>>>>>> Updated RGB Underglow info
=======
				                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
				KC_NO,          KC_O,      KC_M,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
>>>>>>> Cleanup macros
=======
				KC_NO,          KC_N,       KC_M,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
>>>>>>> Tweaked RGB lighting stuff
                                            KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
<<<<<<< HEAD
                KC_NO,          KC_NO,
                KC_NO,
                KC_PGDOWN,      KC_DELETE, KC_ENTER
            ),
=======
				KC_NO,          KC_NO,
				KC_NO,
                KC_PGDOWN,      KC_DELETE, KC_ENTER
			),
>>>>>>> Added default layer (qwerty/colemak/dvorak) detection to RGB Underglow
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
                                            KC_O,   KC_P,
                                                    KC_LGUI,
                                KC_V,   KC_SPACE,   KC_H,
                                    
                KC_TRNS,        KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,
                KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                TG(OVERWATCH),  KC_N,       KC_M,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
<<<<<<< HEAD
=======
				KC_ESCAPE,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
				KC_F1,          KC_K,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
				KC_TAB,         KC_G,       KC_A,       KC_S,       KC_D,       KC_F,
				KC_LCTL,        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_TRNS,
				KC_G,           KC_U,       KC_I,       KC_Y,       KC_T,
                                            KC_O,   KC_P,
                                                    KC_LGUI,
                                KC_V,   KC_SPACE,   KC_H,
									
				KC_NO,          KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,
				KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
<<<<<<< HEAD
				KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
				KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
>>>>>>> Updated RGB Underglow info
=======
				                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
				KC_NO,          KC_O,      KC_M,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
>>>>>>> Cleanup macros
=======
>>>>>>> Updated macros and added workman keymaps
                                            KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_NO,          KC_NO,
                KC_NO,
                KC_PGDOWN,      KC_DELETE, KC_ENTER
            ),
>>>>>>> Updated macros and added workman keymaps
<<<<<<< HEAD
=======
>>>>>>> Added default layer (qwerty/colemak/dvorak) detection to RGB Underglow
=======
>>>>>>> Updated macros and added workman keymaps

/* Keymap 3:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |  V   |  D   | ALT  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |  S   |  I   |  F   |  M   |  T   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    Q   |  1   |  2   |  3   |  4   |  G   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | NUMLOCK| NUM1 | NUM2 | NUM3 | NUM4 |  Z   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | MAC1 | MAC2 | MAC3 | MAC4 |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   L  |  J   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  G   |       |      |      |      |
 *                                 | SPACE|  Q   |------        |------|      |      |
 *                                 | SHIFT| ALT  | 0MAC |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [DIABLO] = KEYMAP(
                KC_ESCAPE,  KC_V,       KC_D,       KC_LALT,    KC_NO,      KC_NO,      KC_NO,
                KC_TAB,     KC_S,       KC_F,       KC_I,       KC_M,       KC_T,       KC_TRNS,
                KC_Q,       KC_1,       KC_2,       KC_3,       KC_4,       KC_G,
                KC_LCTL, TD(TD_DIABLO_1), TD(TD_DIABLO_2), TD(TD_DIABLO_3), TD(TD_DIABLO_4), KC_Z,       KC_NO,
                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                KC_L,   KC_J,
                                                        KC_F,
                    SFT_T(KC_SPACE),    ALT_T(KC_Q),    KC_DIABLO_CLEAR,
                                    
                                    
                                    
                KC_TRNS,        KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,
                KC_TRNS,        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_NO,          KC_N,       KC_M,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                            KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_NO,          KC_NO,
                KC_NO,
                KC_PGDOWN,      KC_DELETE, KC_ENTER
            ),

/* Keymap 4: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|      |      | Acc0 | Acc1 | Acc2 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Acc0 | Acc1 | Acc2 |      |      |      |           |      |      | Mute |VolDn |VolUp |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Play | Stop |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | MWUp |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------| MBn4 | MBn5 |
 *                                 |      |      | MWDn |       | Mclk |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [MOUS] = KEYMAP(
                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
                KC_NO,      KC_NO,      KC_MS_U,    KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
                KC_NO,      KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_NO,      KC_NO,
                KC_NO,      KC_ACL0,    KC_ACL1,    KC_ACL2,    KC_NO,      KC_NO,      KC_TRNS,
                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                                            KC_NO,      KC_NO,
                                                                                        KC_WH_U,
                                                                KC_BTN1,    KC_BTN2,    KC_WH_D,
                
                KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                            KC_NO,      KC_ACL0,    KC_ACL1,    KC_ACL2,    KC_NO,      KC_NO,
                KC_TRNS,    KC_NO,      KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_NO,      KC_NO,
                                        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_NO,KC_NO,
                KC_NO,
                KC_MS_BTN3,KC_MS_BTN4,KC_MS_BTN5
            ),

};

<<<<<<< HEAD

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

<<<<<<< HEAD

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
<<<<<<< HEAD
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_mode(1);
#endif
            }
            return false;
            break;

        case RGB_0000FF:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00,0x00,0xff);
                #endif
            }
            return false;
            break;

        case RGB_008000:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00,0x80,0x00);
                #endif
            }
            return false;
            break;
=======
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function

        case RGB_FF0000:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0xff,0x00,0x00);
                #endif
            }
            return false;
            break;

        case RGB_800080:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x80,0x00,0x80);
                #endif
            }
            return false;
            break;
=======
                // make ergodox-ez-drashna-custom-teensy
                return MACRO(I(5), T(M), T(A), T(K), T(E), T(SPACE), T(E), T(R), T(G), T(O), T(D), T(O), T(X), D(LSFT), T(MINUS), U(LSFT), T(E), T(Z), T(MINUS), T(D), T(R), T(A), T(S), T(H), T(N), T(A), T(MINUS), T(C), T(U), T(S), T(T), T(O), T(M), T(MINUS), T(T), T(E), T(E), T(N), T(S), T(Y), T(ENTER), END);
            }				
    }
    return MACRO_NONE;
};
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Updated macros and added workman keymaps

<<<<<<< HEAD
>>>>>>> Updated RGB Underglow info
=======
void persistent_default_layer_set(uint16_t default_layer) {
<<<<<<< HEAD
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
=======

>>>>>>> Updated RGB Underglow info
>>>>>>> Updated RGB Underglow info

>>>>>>> Start to merge orthodox/ergodox keymaps (persistant layers)

<<<<<<< HEAD
=======
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  switch (keycode) {
    // dynamically generate these.
  case EPRM:
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;
  case RGB_SLD:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
<<<<<<< HEAD
            }
            return false;
            break;

        case RGB_0000FF:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00,0x00,0xff);
                #endif
            }
            return false;
            break;

        case RGB_008000:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00,0x80,0x00);
                #endif
            }
            return false;
            break;

        case RGB_FF0000:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0xff,0x00,0x00);
                #endif
            }
            return false;
            break;

        case RGB_800080:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x80,0x00,0x80);
                #endif
            }
            return false;
            break;
=======
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

>>>>>>> Start to merge orthodox/ergodox keymaps (persistant layers)
>>>>>>> Start to merge orthodox/ergodox keymaps (persistant layers)

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
            break;

        case RGB_0000FF:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00,0x00,0xff);
                #endif
            }
            return false;
            break;

        case RGB_008000:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00,0x80,0x00);
                #endif
            }
            return false;
            break;

        case RGB_FF0000:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0xff,0x00,0x00);
                #endif
            }
            return false;
            break;

        case RGB_800080:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x80,0x00,0x80);
                #endif
            }
            return false;
            break;

>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
        case RGB_00FF90:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00,0xff,0x90);
                #endif
            }
            return false;
            break;
        case KC_DIABLO_CLEAR:  // reset all Diable timers, disabling them
            if (record->event.pressed) {
                uint8_t dtime;
                
                for (dtime = 0; dtime < 4; dtime++) {
                    diablo_key_time[dtime] = diablo_times[0];
                }
            }
            return false;
            break;
        case KC_QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << QWERTY);
            }
            return false;
            break;
        case KC_COLEMAK:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << COLEMAK);
            }
            return false;
            break;
        case KC_DVORAK:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << DVORAK);
            }
            return false;
            break;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated macros and added workman keymaps
=======
>>>>>>> Start to merge orthodox/ergodox keymaps (persistant layers)
=======
=======
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
        case KC_WORKMAN:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << WORKMAN);
            }
            return false;
            break;
        case KC_MAKEQMK:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
            if (!record->event.pressed) {
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP ":teensy"SS_TAP(X_ENTER));
            }
            return false;
            break;
=======
    }
    return false;
    break;
>>>>>>> Fixed formatting to fall in line with official standards

  case RGB_0000FF:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable();
      rgblight_mode(1);
      rgblight_setrgb(0x00, 0x00, 0xff);
#endif
    }
    return false;
    break;

  case RGB_008000:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable();
      rgblight_mode(1);
      rgblight_setrgb(0x00, 0x80, 0x00);
#endif
    }
    return false;
    break;

  case RGB_FF0000:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable();
      rgblight_mode(1);
      rgblight_setrgb(0xff, 0x00, 0x00);
#endif
    }
    return false;
    break;

  case RGB_800080:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable();
      rgblight_mode(1);
      rgblight_setrgb(0x80, 0x00, 0x80);
#endif
    }
    return false;
    break;

  case RGB_00FF90:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable();
      rgblight_mode(1);
      rgblight_setrgb(0x00, 0xff, 0x90);
#endif
    }
    return false;
    break;
  case KC_DIABLO_CLEAR:  // reset all Diable timers, disabling them
    if (record->event.pressed) {
      uint8_t dtime;

      for (dtime = 0; dtime < 4; dtime++) {
        diablo_key_time[dtime] = diablo_times[0];
      }
    }
<<<<<<< HEAD
    return true;
=======

	}
	return true;
>>>>>>> Start to merge orthodox/ergodox keymaps (persistant layers)
=======
            if (record->event.pressed) {
=======
=======
>>>>>>> Updated macros and added workman keymaps
            if (!record->event.pressed) {
>>>>>>> Clean up and updates of drashna keymaps
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP ":teensy"SS_TAP(X_ENTER));
            }
            return false;
            break;

    }
    return true;
<<<<<<< HEAD
>>>>>>> Updated macros and added workman keymaps
=======
    return false;
    break;
  case KC_QWERTY:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL << QWERTY);
    }
    return false;
    break;
  case KC_COLEMAK:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL << COLEMAK);
    }
    return false;
    break;
  case KC_DVORAK:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL << DVORAK);
    }
    return false;
    break;
  case KC_WORKMAN:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL << WORKMAN);
    }
    return false;
    break;
  case KC_MAKEQMK:
    if (!record->event.pressed) {
      SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP ":teensy"SS_TAP(X_ENTER));
      debug_enable = true;
    }
    return false;
    break;
  case KC_RESET:
    if (!record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable();
      rgblight_mode(1);
      rgblight_setrgb(0xff, 0x00, 0x00);
#endif
      reset_keyboard();
    }
    return false;
    break;

  }
  return true;
>>>>>>> Fixed formatting to fall in line with official standards
=======
=======

	}
	return true;
>>>>>>> Start to merge orthodox/ergodox keymaps (persistant layers)
<<<<<<< HEAD
>>>>>>> Start to merge orthodox/ergodox keymaps (persistant layers)
=======
=======
            if (record->event.pressed) {
                SEND_STRING("make ergodox_ez-drashna-custom-teensy"SS_TAP(X_ENTER));
            }
            return false;
            break;

    }
    return true;
>>>>>>> Updated macros and added workman keymaps
>>>>>>> Updated macros and added workman keymaps
}

#ifdef TAP_DANCE_ENABLE

// Sends the key press to system, but only if on the Diablo layer
void send_diablo_keystroke(uint8_t diablo_key) {
  if (biton32(layer_state) == DIABLO) {
    switch (diablo_key) {
    case 0:
      SEND_STRING("1");
      break;
    case 1:
      SEND_STRING("2");
      break;
    case 2:
      SEND_STRING("3");
      break;
    case 3:
      SEND_STRING("4");
      break;
    }
  }
}

// Checks each of the 4 timers/keys to see if enough time has elapsed
// Runs the "send string" command if enough time has passed, and resets the timer.
void run_diablo_macro_check(void) {
  uint8_t dtime;

  for (dtime = 0; dtime < 4; dtime++) {
    if (check_dtimer(dtime) && diablo_key_time[dtime]) {
      diablo_timer[dtime] = timer_read();
      send_diablo_keystroke(dtime);
    }
  }

}

#endif


void matrix_init_user(void) { // Runs boot tasks for keyboard
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Add forced NKRO
#ifdef RGBLIGHT_ENABLE
<<<<<<< HEAD
    uint8_t default_layer = eeconfig_read_default_layer();
=======
<<<<<<< HEAD
=======
#ifdef RGBLIGHT_ENABLE
    uint8_t default_layer = eeconfig_read_default_layer();
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function

    rgblight_enable();
    if (default_layer & (1UL << COLEMAK)) {
        rgblight_set_magenta;
    }
    else if (default_layer & (1UL << DVORAK)) {
        rgblight_set_green;
    }
    else if (default_layer & (1UL << WORKMAN)) {
        rgblight_set_purple;
    }
    else {
        rgblight_set_teal;
    }
=======
  uint8_t default_layer = eeconfig_read_default_layer();

  rgblight_enable();
  if (default_layer & (1UL << COLEMAK)) {
    rgblight_set_magenta;
  }
  else if (default_layer & (1UL << DVORAK)) {
    rgblight_set_green;
  }
  else if (default_layer & (1UL << WORKMAN)) {
    rgblight_set_purple;
  }
  else {
    rgblight_set_teal;
  }
>>>>>>> Fixed formatting to fall in line with official standards
#endif
=======

>>>>>>> Add forced NKRO
};
>>>>>>> Add forced NKRO

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    rgblight_enable();
    if (default_layer & (1UL << COLEMAK)) {
        rgblight_set_magenta;
    }
    else if (default_layer & (1UL << DVORAK)) {
        rgblight_set_green;
    }
    else if (default_layer & (1UL << WORKMAN)) {
        rgblight_set_purple;
    }
    else {
        rgblight_set_teal;
    }
#endif
};

=======
>>>>>>> Add leader keys
=======
#ifdef LEADER_KEYS
>>>>>>> Finishing up Viterbi keyboard layout, and NKRO tweaks to other layouts
=======
>>>>>>> Clean up and updates of drashna keymaps
LEADER_EXTERNS();
=======
>>>>>>> Removed Leader Keys from Ergodox EZ Keymap

void matrix_scan_user(void) {  // runs frequently to update info
<<<<<<< HEAD
    uint8_t modifiders = get_mods();
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Add forced NKRO

    if (!skip_leds) {
        ergodox_board_led_off();
        ergodox_right_led_1_off();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
=======
    uint8_t layer = biton32(layer_state);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    static bool has_layer_changed = true;
=======
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function

<<<<<<< HEAD

<<<<<<< HEAD
=======
    bool dvorak = false;
    bool colemak = false;
	static bool has_layer_changed = true;
>>>>>>> Add forced NKRO
=======
    bool l_dvorak = false;
    bool l_colemak = false;
	static bool has_layer_changed = true;


>>>>>>> Added default layer (qwerty/colemak/dvorak) detection to RGB Underglow
=======
    static bool has_layer_changed = true;


<<<<<<< HEAD
>>>>>>> Updated macros and added workman keymaps
	if (!skip_leds) {
		ergodox_board_led_off();
		ergodox_right_led_1_off();
		ergodox_right_led_2_off();
		ergodox_right_led_3_off();
>>>>>>> Add forced NKRO
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> Add leader keys
=======
=======
>>>>>>> Updated macros and added workman keymaps
    if (!skip_leds) {
        ergodox_board_led_off();
        ergodox_right_led_1_off();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
>>>>>>> Updated macros and added workman keymaps
<<<<<<< HEAD
=======
>>>>>>> Add forced NKRO
=======
>>>>>>> Updated macros and added workman keymaps
        
        // Since we're not using the LEDs here for layer indication anymore,
        // then lets use them for modifier indicators.  Shame we don't have 4...
        // Also, no "else", since we want to know each, independantly. 
        if ( modifiders & MODS_SHIFT_MASK) {
            ergodox_right_led_2_on();
        }
        if ( modifiders & MODS_CTRL_MASK) {
            ergodox_right_led_1_on();
        }
        if ( modifiders & MODS_ALT_MASK) {
            ergodox_right_led_3_on();
        }
        
    }
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Updated RGB Underglow info
=======
>>>>>>> Tweaked RGB lighting stuff

    // Run Diablo 3 macro checking code.
#ifdef TAP_DANCE_ENABLE
    run_diablo_macro_check();
#endif
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        SEQ_ONE_KEY(KC_C) {
            SEND_STRING("Covecube");
        }
        SEQ_ONE_KEY(KC_D) {
            SEND_STRING("StableBit CloudDrive");
        }
        SEQ_ONE_KEY(KC_L) {
            register_code(KC_LGUI);
            register_code(KC_L);
            unregister_code(KC_L);
            unregister_code(KC_LGUI);
        }
        SEQ_TWO_KEYS(KC_S, KC_D) {
            SEND_STRING("StableBit DrivePool");
        }
        SEQ_TWO_KEYS(KC_S, KC_C) {
            SEND_STRING("StableBit Scanner");
        }
        SEQ_TWO_KEYS(KC_S, KC_T) {
            SEND_STRING("StableBit Troubleshooter");
        }
    }
};

uint32_t layer_state_set_kb(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    uint8_t default_layer = eeconfig_read_default_layer();

    switch (biton32(state)) {
        case SYMB:
            rgblight_set_blue;
            rgblight_mode(2);
            break;
        case OVERWATCH:
            rgblight_set_orange;
            rgblight_mode(17);
            break;
        case DIABLO:
            rgblight_set_red;
            rgblight_mode(5);
            break;
        case MOUS:
            rgblight_set_yellow;
            rgblight_mode(1);
            break;
        default:
            if (default_layer & (1UL << COLEMAK)) {
                rgblight_set_green;
            }
            else if (default_layer & (1UL << DVORAK)) {
                rgblight_set_magenta;
            }
            else if (default_layer & (1UL << WORKMAN)) {
                rgblight_set_purple;
            }
            else {
                rgblight_set_teal;
            }
            rgblight_mode(1);
            break;
    }
#endif
   return state;
}
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Tweaked RGB lighting stuff
=======
    if (layer != current_layer) {
        has_layer_changed = true;
        current_layer = layer;
    }
>>>>>>> Tweaked RGB lighting stuff
<<<<<<< HEAD
    // Check layer, and apply color if its changed since last check
    if (has_layer_changed) {
 #ifdef RGBLIGHT_ENABLE
       uint8_t default_layer = 0;
        default_layer = eeconfig_read_default_layer();

        switch (layer) {
            case SYMB:
                rgblight_set_blue;
                rgblight_mode(2);
                break;
            case OVERWATCH:
                rgblight_set_orange;
                rgblight_mode(17);
                break;
            case DIABLO:
                rgblight_set_red;
                rgblight_mode(5);
                break;
            case MOUS:
                rgblight_set_urine;
                rgblight_mode(1);
                break;
            case 7:
                rgblight_sethsv (255,255,255);
                rgblight_mode(1);
                break;
            default:
                if (default_layer & (1UL << COLEMAK)) {
                    rgblight_set_green;
                }
                else if (default_layer & (1UL << DVORAK)) {
                    rgblight_set_magenta;
                }
                else if (default_layer & (1UL << WORKMAN)) {
                    rgblight_set_purple;
                }
                else {
                    rgblight_set_teal;
                }
                rgblight_mode(1);
                break;
        }
#endif
        has_layer_changed = false;
    }
=======
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function
=======
  uint8_t modifiders = get_mods();

  if (!skip_leds) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    // Since we're not using the LEDs here for layer indication anymore,
    // then lets use them for modifier indicators.  Shame we don't have 4...
    // Also, no "else", since we want to know each, independantly. 
    if (modifiders & MODS_SHIFT_MASK) {
      ergodox_right_led_2_on();
    }
    if (modifiders & MODS_CTRL_MASK) {
      ergodox_right_led_1_on();
    }
    if (modifiders & MODS_ALT_MASK) {
      ergodox_right_led_3_on();
    }

  }
>>>>>>> Fixed formatting to fall in line with official standards

  // Run Diablo 3 macro checking code.
#ifdef TAP_DANCE_ENABLE
  run_diablo_macro_check();
#endif
};

<<<<<<< HEAD
>>>>>>> Updated RGB Underglow info
=======
uint32_t layer_state_set_kb(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
  uint8_t default_layer = eeconfig_read_default_layer();

  switch (biton32(state)) {
  case SYMB:
    rgblight_set_blue;
    rgblight_mode(2);
    break;
  case OVERWATCH:
    rgblight_set_orange;
    rgblight_mode(17);
    break;
  case DIABLO:
    rgblight_set_red;
    rgblight_mode(5);
    break;
  case MOUS:
    rgblight_set_yellow;
    rgblight_mode(1);
    break;
  default:
    if (default_layer & (1UL << COLEMAK)) {
      rgblight_set_green;
    }
    else if (default_layer & (1UL << DVORAK)) {
      rgblight_set_magenta;
    }
    else if (default_layer & (1UL << WORKMAN)) {
      rgblight_set_purple;
    }
    else {
      rgblight_set_teal;
    }
    rgblight_mode(1);
    break;
  }
#endif
  return state;
}
>>>>>>> Updated RGB Underglow layer indication code due to discovery of the layer_state_set_kb function
=======
=======
>>>>>>> Tweaked RGB lighting stuff
    // Check layer, and apply color if its changed since last check
    if (has_layer_changed) {
        uint8_t default_layer = 0;
        default_layer = eeconfig_read_default_layer();

        switch (layer) {
            case SYMB:
                rgblight_set_blue;
                rgblight_mode(2);
                break;
            case OVERWATCH:
                rgblight_set_orange;
                rgblight_mode(17);
                break;
            case DIABLO:
                rgblight_set_red;
                rgblight_mode(5);
                break;
            case MOUS:
                rgblight_set_urine;
                rgblight_mode(1);
                break;
            case 7:
                rgblight_sethsv (255,255,255);
                rgblight_mode(1);
                break;
            default:
                if (default_layer & (1UL << COLEMAK)) {
                    rgblight_set_green;
                }
                else if (default_layer & (1UL << DVORAK)) {
                    rgblight_set_magenta;
                }
                else if (default_layer & (1UL << WORKMAN)) {
                    rgblight_set_aqua;
                }
                else {
                    rgblight_set_teal;
                }
                rgblight_mode(1);
                break;
        }
        has_layer_changed = false;
    }

    // Run Diablo 3 macro checking code.
    run_diablo_macro_check();
};

>>>>>>> Updated RGB Underglow info
>>>>>>> Updated RGB Underglow info
