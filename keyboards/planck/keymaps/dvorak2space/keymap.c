#include QMK_KEYBOARD_H
#include "passwords.c" //Instead of extern just to cut down on compile time.
#define MOUSEL KC_BTN1
#define MOUSER KC_BTN2
#define CTRLL LCTL(KC_LEFT)
#define CTRLR LCTL(KC_RGHT)
#define CAD LCTL(LALT(KC_DEL))
#define IS_LAYER_ON(layer)  (layer_state & (1UL << (layer)))

enum {
	HK_SLP = SAFE_RANGE,
	HK_IF,
	HK_ELSE
};

enum {
	FB = 0,
	LPN,
	RPN,
	BCK,
	DSH
};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //Distinguishes between double tapping and typing, "tapping", for example
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   p  |   y  |   f  |   g  |   c  |   r  |   l  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Nav  |   a  |   o  |   e  |   u  |   i  |   d  |   h  |   t  |   n  |   s  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |   ;  |   q  |   j  |   k  |   x  |   b  |   m  |   w  |   v  |   z  | Shft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | RClk | LClk | Ctrl |    Space    |   Modifier  |  GUI | VolD | VolU |Macros|
 * `-----------------------------------------------------------------------------------'
 */
	[0] = LAYOUT_planck_2x2u(
		KC_TAB,	KC_QUOT,KC_COMM,KC_DOT,	KC_P,		KC_Y,		KC_F,		KC_G,		KC_C,		KC_R,		KC_L,		TD(BCK),
		TT(3),	KC_A,		KC_O,		KC_E,		KC_U,		KC_I,		KC_D,		KC_H,		KC_T,		KC_N,		KC_S,		KC_ENT,
		KC_LSFT,KC_SCLN,KC_Q,		KC_J,		KC_K,		KC_X,		KC_B,		KC_M,		KC_W,		KC_V,		KC_Z,		KC_RSFT,
		KC_ESC,	MOUSER,	MOUSEL,	KC_LCTL,				KC_SPC,	TT(2),					KC_LGUI,KC_VOLD,KC_VOLU,OSL(4)
	),
/* Custom Shifts
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   ?  |   !  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
	[1] = LAYOUT_planck_2x2u(
		KC_TRNS,KC_TRNS,KC_SLSH,KC_1,		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_NO,	KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,				KC_TRNS,KC_NO,					KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
	),
/* Modifier
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |   +  |   -  |   *  |  / \ |  if  | else |  ( [ |  ) ] |   {  |   }  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   <  |   >  |   &  |   |  |   _  |   $  |   @  |   #  |   %  |   ^  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |    Space    |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
	[2] = LAYOUT_planck_2x2u(
		KC_TAB,	KC_PLUS,KC_PMNS,KC_ASTR,TD(FB),	HK_IF,	HK_ELSE,TD(LPN),TD(RPN),KC_LCBR,KC_RCBR,TD(BCK),
		KC_PEQL,KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_ENT,
		KC_NO,	KC_LT,	KC_GT,	KC_AMPR,KC_PIPE,KC_UNDS,KC_DLR,	KC_AT,	KC_HASH,KC_PERC,KC_CIRC,KC_NO,
		KC_NO,	KC_NO,	KC_NO,	KC_NO,					KC_SPC,	KC_TRNS,				KC_NO,	KC_NO,	KC_NO,	KC_NO
	),
//Nav
	[3] = LAYOUT_planck_2x2u(
		KC_TAB,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_HOME,KC_UP,	KC_END,	KC_NO,	TD(BCK),
		KC_TRNS,KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	CTRLL,	KC_LEFT,KC_DOWN,KC_RGHT,CTRLR,	KC_ENT,
		KC_LSFT,KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
		KC_NO,	KC_NO,	KC_NO,	KC_NO,					KC_SPC,	KC_NO,					KC_NO,	KC_NO,	KC_NO,	KC_NO
	),
//AHK-Bindable Macros
	[4] = LAYOUT_planck_2x2u(
		KC_F13,			 KC_F14,			KC_F15,			 KC_F16,			KC_F17,			 KC_F18,			KC_F19,			 KC_F20,			KC_F21,			 KC_F22,			KC_F23,			 KC_F24,
		LCTL(KC_F13),LCTL(KC_F14),LCTL(KC_F15),LCTL(KC_F16),LCTL(KC_F17),LCTL(KC_F18),LCTL(KC_F19),LCTL(KC_F20),LCTL(KC_F21),LCTL(KC_F22),LCTL(KC_F23),LCTL(KC_F24),
		LSFT(KC_F13),LSFT(KC_F14),LSFT(KC_F15),LSFT(KC_F16),LSFT(KC_F17),LSFT(KC_F18),LSFT(KC_F19),LSFT(KC_F20),LSFT(KC_F21),LSFT(KC_F22),LSFT(KC_F23),LSFT(KC_F24),
		RESET,			 LALT(KC_F14),LALT(KC_F15),TG(6),															CAD,LALT(KC_F19),							LALT(KC_F21),LALT(KC_F22),HK_SLP,      KC_TRNS
	),
//Locked Screen
	[5] = LAYOUT_planck_2x2u(
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
		KC_NO,	KC_NO,	KC_NO,	KC_NO,					KC_NO,	KC_NO,					KC_NO,	KC_NO,	HK_SLP,	KC_NO
	),
//Passwords (by first letter of service name, at least better than just 1)
	[6] = LAYOUT_planck_2x2u(
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_P,		KC_Y,		KC_F,		KC_G,		KC_C,		KC_R,		KC_L,		KC_NO,
		KC_NO,	KC_A,		KC_O,		KC_E,		KC_U,		KC_I,		KC_D,		KC_H,		KC_T,		KC_N,		KC_S,		KC_NO,
		KC_NO,	KC_NO,	KC_Q,		KC_J,		KC_K,		KC_X,		KC_B,		KC_M,		KC_W,		KC_V,		KC_Z,		KC_NO,
		KC_NO,	KC_NO,	KC_NO,	KC_NO,					KC_NO,	KC_NO,					KC_NO,	KC_NO,	KC_NO,	TG(6)
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) { //X_KEY doesn't support aliases
	switch(keycode) {
		//if shift pressed and not shift layer or released and other shift not pressed
		//in separate things because MOD_BIT probably isn't toggled until after this returns true and shift is actually toggled
		case KC_LSFT: //if pressed and not shift layer or released and other shift not pressed
			if((record->event.pressed && !IS_LAYER_ON(3)) || (!record->event.pressed && !(keyboard_report->mods & (MOD_BIT(KC_RSFT)))))
				layer_invert(1);
			break;
		case KC_RSFT:
			if((record->event.pressed && !IS_LAYER_ON(3)) || (!record->event.pressed && !(keyboard_report->mods & (MOD_BIT(KC_LSFT)))))
				layer_invert(1);
			break;
		case KC_ENT: //won't repeat on hold and I can't find a solution other than hardcoding timers but I kinda prefer it anyway. Swaps enter and shift enter
			if(record->event.pressed) {
				if(IS_LAYER_ON(3)) { //if shifted release correct shift, send, and press same shift
					if(keyboard_report->mods & (MOD_BIT(KC_LSFT)))
						SEND_STRING(SS_UP(X_LSHIFT) SS_TAP(X_ENTER) SS_DOWN(X_LSHIFT));
					else
						SEND_STRING(SS_UP(X_RSHIFT) SS_TAP(X_ENTER) SS_DOWN(X_RSHIFT));
				}
				else
					SEND_STRING(SS_LSFT(SS_TAP(X_ENTER)));
			}
			return false;
		case HK_IF:
			if(record->event.pressed) SEND_STRING("if");
			return false;
		case HK_ELSE:
			if(record->event.pressed) SEND_STRING("else");
			return false;
		case HK_SLP:
			if(record->event.pressed && IS_LAYER_ON(5))
				SEND_STRING(SS_LALT(SS_TAP(X_F23)));
			if(!record->event.pressed) {
				if(!IS_LAYER_ON(5))
					SEND_STRING(SS_LALT(SS_TAP(X_F24)));
				layer_invert(5);
			}
			return false;
		default:
			if(IS_LAYER_ON(6) && keycode <= KC_Z) {
				SEND_STRING(passwords[keycode - KC_A]);
				layer_invert(6);
				return false;
			}
	}
	return true;
};

//tapdance state evaluation
int cur_dance(qk_tap_dance_state_t *state) {
  if(state->count == 1) {
    if(state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  else if(state->count == 2) { return DOUBLE_TAP; }
	else if(state->count == 3) { return TRIPLE_TAP; }
  else { return false; }
}

void back_tap(qk_tap_dance_state_t *state, void *user_data) { tap_code(KC_BSPACE); }

void back_finished(qk_tap_dance_state_t *state, void *user_data) {
  int td_state = cur_dance(state);
  switch(td_state) {
    case SINGLE_HOLD:
      tap_code16(LCTL(KC_BSPACE));
      break;
  }
}

void dash_finished(qk_tap_dance_state_t *state, void *user_data) {
  int td_state = cur_dance(state);
  switch(td_state) {
    case SINGLE_TAP:
      tap_code(KC_PMNS);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LALT));
			tap_code(KC_KP_0);
			tap_code(KC_KP_1);
			tap_code(KC_KP_5);
			tap_code(KC_KP_1);
			unregister_mods(MOD_BIT(KC_LALT));
      break;
    case DOUBLE_TAP:
      tap_code(KC_PMNS);
      tap_code(KC_PMNS);
			break;
		case TRIPLE_TAP:
      tap_code(KC_PMNS);
      tap_code(KC_PMNS);
			tap_code(KC_PMNS);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[FB] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_NUBS),
	[LPN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LCBR),
	[RPN] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RCBR),
	[BCK] = ACTION_TAP_DANCE_FN_ADVANCED(back_tap, back_finished, NULL), //each tap, on finished, and reset. Normally register_code on press unregister on reset so keys
	[DSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dash_finished, NULL) //can be held down, but in both cases a trigger I'm using is holding them down so no point.
};
