#include "dz60.h"

// Make special keycodes more visible
#define ____ KC_TRNS
#define XXXX KC_NO

// Layer definition
#define BASE 0
#define CONF 1
#define GAME 2

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // ANSI QWERTY
	[BASE] = LAYOUT(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, XXXX, KC_BSPC, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_UP, KC_DEL,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(GAME), KC_SPC, KC_RALT, MO(CONF), KC_LEFT, KC_DOWN, KC_RIGHT),

	[CONF] = LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, KC_DEL, 
		____, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ____, ____, ____, ____, RESET, 
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, BL_BRTG, BL_DEC, BL_TOGG, BL_INC, BL_STEP, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____),

	[GAME] = LAYOUT(
		____, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), ____, ____, 
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

// FIXME: guess it's only needed when mapping 'F(0)' to a key. But 'KC_GESC'
// seems to supersede this function here?
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

