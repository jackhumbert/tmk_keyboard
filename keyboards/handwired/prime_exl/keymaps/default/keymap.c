/* Copyright 2018 Holten Campbell
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
		KC_F7, TO(2), KC_P0, 
		KC_F5, KC_P1, KC_P3, KC_LCTL, KC_LBRC, MO(1), KC_SPC, KC_EQL, MO(4), 
		KC_F3, KC_P4, KC_P6, KC_LSFT, KC_X, KC_V, KC_N, KC_COMM, KC_SLSH, 
		KC_F1, KC_P7, KC_P9, KC_TAB, KC_S, KC_F, KC_H, KC_K, KC_QUOT, 
		KC_NLCK, KC_RPRN, KC_PAST, KC_ESC, KC_W, KC_R, KC_Y, KC_I, KC_P, 
		KC_LPRN, KC_PSLS, KC_BSPC, KC_Q, KC_E, KC_T, KC_U, KC_O, KC_BSPC, 
		KC_F2, KC_P8, KC_DEL, KC_A, KC_D, KC_G, KC_J, KC_L, KC_ENT, 
		KC_F4, KC_P5, KC_PMNS, KC_Z, KC_C, KC_B, KC_M, KC_DOT, KC_LSFT, 
		KC_F6, KC_P2, KC_PPLS, KC_LALT, KC_RBRC, MO(3), KC_MINS, KC_LGUI, 
		KC_F8, KC_PDOT, KC_PENT
    ),

	[1] = LAYOUT(
		BL_TOGG, KC_TRNS, KC_TRNS, 
		KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, 
		KC_SLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_SCLN, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_2, KC_4, KC_TRNS, KC_UP, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_3, KC_5, KC_TRNS, KC_TRNS, KC_DEL, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_RGHT, KC_BSLS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, 
		BL_STEP, KC_TRNS, KC_TRNS
    ),
	
		[2] = LAYOUT(
		KC_LCTL, TO(0), KC_H, 
		KC_LSFT, KC_X, KC_V, KC_LCTL, KC_LBRC, MO(5), KC_SPC, KC_EQL, MO(4), 
		KC_TAB, KC_S, KC_F, KC_LSFT, KC_X, KC_V, KC_N, KC_COMM, KC_SLSH, 
		KC_TAB, KC_W, KC_R, KC_TAB, KC_S, KC_F, KC_H, KC_K, KC_QUOT, 
		KC_ESC, KC_2, KC_4, KC_ESC, KC_W, KC_R, KC_Y, KC_I, KC_P, 
		KC_1, KC_3, KC_F9, KC_Q, KC_E, KC_T, KC_U, KC_O, KC_BSPC, 
		KC_Q, KC_E, KC_T, KC_A, KC_D, KC_G, KC_J, KC_L, KC_ENT, 
		KC_A, KC_D, KC_G, KC_Z, KC_C, KC_B, KC_M, KC_DOT, KC_LSFT, 
		KC_Z, KC_C, KC_B, KC_LALT, KC_RBRC, MO(3), KC_MINS, KC_LGUI, 
		KC_LALT, KC_P, KC_SPC
    ),
	
		[3] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_2, KC_4, KC_6, KC_8, KC_0, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_3, KC_5, KC_7, KC_9, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS
    ),
	
		[4] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F3, KC_F5, KC_F7, KC_F9, KC_F11, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_F2, KC_F4, KC_F6, KC_F8, KC_F10, KC_F12, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS
    ),
	
		[5] = LAYOUT(
		BL_TOGG, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_SCLN, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_2, KC_4, KC_TRNS, KC_UP, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_3, KC_5, KC_TRNS, KC_TRNS, KC_DEL, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_RGHT, KC_BSLS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, 
		BL_STEP, KC_TRNS, KC_TRNS
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  DDRC |= (1 << 6);
  PORTC &= ~(1 << 6);
  // set NumLock LED to output and low
  DDRB |= (1 << 6);
  PORTB &= ~(1 << 6);
  // set ScrollLock LED to output and low
  DDRB |= (1 << 5);
  PORTB &= ~(1 << 5);
}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_NUM_LOCK)) {
    PORTB |= (1<<6);
  } else {
    PORTB &= ~(1<<6);
  }
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    PORTB |= (1<<5);
  } else {
    PORTB &= ~(1<<5);
  }
  /*
  if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
    PORTC |= (1<<6);
  } else {
    PORTC &= ~(1<<6);
  }
  */
}

uint32_t layer_state_set_user(uint32_t state)
{
    if (biton32(state) == 2) {
        PORTC |= (1<<6);
	} else {
		PORTC &= ~(1<<6);
    }
    return state;
}
