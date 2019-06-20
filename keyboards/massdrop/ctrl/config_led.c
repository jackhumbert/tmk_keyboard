#ifdef RGB_MATRIX_ENABLE
#include "ctrl.h"

#include "led_matrix.h"
#include "rgb_matrix.h"
#include "config_led.h"

rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
  // KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS
  { { 0|(0<<4) }, { 7, 5 }, 4 },
  { { 0|(1<<4) }, { 31, 5 }, 4 },
  { { 0|(2<<4) }, { 43, 5 }, 4 },
  { { 0|(3<<4) }, { 55, 5 }, 4 },
  { { 0|(4<<4) }, { 67, 5 }, 4 },
  { { 0|(5<<4) }, { 85, 5 }, 4 },
  { { 0|(6<<4) }, { 97, 5 }, 4 },
  { { 0|(7<<4) }, { 109, 5 }, 4 },
  { { 6|(0<<4) }, { 121, 5 }, 4 },
  { { 6|(1<<4) }, { 139, 5 }, 4 },
  { { 6|(2<<4) }, { 151, 5 }, 4 },
  { { 6|(3<<4) }, { 163, 5 }, 4 },
  { { 6|(4<<4) }, { 175, 5 }, 4 },
  { { 6|(5<<4) }, { 193, 5 }, 4 },
  { { 6|(6<<4) }, { 205, 5 }, 1 },
  { { 6|(7<<4) }, { 217, 5 }, 4 },
  // KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP
  { { 1|(0<<4) }, { 7, 20 }, 4 },
  { { 1|(1<<4) }, { 19, 20 }, 4 },
  { { 1|(2<<4) }, { 31, 20 }, 4 },
  { { 1|(3<<4) }, { 43, 20 }, 4 },
  { { 1|(4<<4) }, { 55, 20 }, 4 },
  { { 1|(5<<4) }, { 67, 20 }, 4 },
  { { 1|(6<<4) }, { 79, 20 }, 4 },
  { { 1|(7<<4) }, { 91, 20 }, 4 },
  { { 7|(0<<4) }, { 103, 20 }, 4 },
  { { 7|(1<<4) }, { 115, 20 }, 4 },
  { { 7|(2<<4) }, { 127, 20 }, 4 },
  { { 7|(3<<4) }, { 139, 20 }, 4 },
  { { 7|(4<<4) }, { 151, 20 }, 4 },
  { { 7|(5<<4) }, { 169, 20 }, 4 },
  { { 7|(6<<4) }, { 193, 20 }, 4 },
  { { 7|(7<<4) }, { 205, 20 }, 4 },
  { { 9|(7<<4) }, { 217, 20 }, 4 },
  // KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN
  { { 2|(0<<4) }, { 10, 30 }, 4 },
  { { 2|(1<<4) }, { 25, 30 }, 4 },
  { { 2|(2<<4) }, { 37, 30 }, 4 },
  { { 2|(3<<4) }, { 49, 30 }, 4 },
  { { 2|(4<<4) }, { 61, 30 }, 4 },
  { { 2|(5<<4) }, { 73, 30 }, 4 },
  { { 2|(6<<4) }, { 85, 30 }, 4 },
  { { 2|(7<<4) }, { 97, 30 }, 4 },
  { { 8|(0<<4) }, { 109, 30 }, 4 },
  { { 8|(1<<4) }, { 121, 30 }, 4 },
  { { 8|(2<<4) }, { 133, 30 }, 4 },
  { { 8|(3<<4) }, { 145, 30 }, 4 },
  { { 8|(4<<4) }, { 157, 30 }, 4 },
  { { 8|(5<<4) }, { 172, 30 }, 4 },
  { { 8|(6<<4) }, { 193, 30 }, 4 },
  { { 8|(7<<4) }, { 205, 30 }, 4 },
  { { 9|(6<<4) }, { 217, 30 }, 4 },
  // KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT
  { { 3|(0<<4) }, { 11, 39 }, 1 },
  { { 3|(1<<4) }, { 28, 39 }, 4 },
  { { 3|(2<<4) }, { 40, 39 }, 4 },
  { { 3|(3<<4) }, { 52, 39 }, 4 },
  { { 3|(4<<4) }, { 64, 39 }, 4 },
  { { 3|(5<<4) }, { 76, 39 }, 4 },
  { { 3|(6<<4) }, { 88, 39 }, 4 },
  { { 3|(7<<4) }, { 100, 39 }, 4 },
  { { 9|(0<<4) }, { 112, 39 }, 4 },
  { { 9|(1<<4) }, { 124, 39 }, 4 },
  { { 9|(2<<4) }, { 136, 39 }, 4 },
  { { 9|(3<<4) }, { 148, 39 }, 4 },
  { { 9|(4<<4) }, { 168, 39 }, 4 },
  // KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP
  { { 4|(0<<4) }, { 14, 49 }, 4 },
  { { 4|(1<<4) }, { 34, 49 }, 4 },
  { { 4|(2<<4) }, { 46, 49 }, 4 },
  { { 4|(3<<4) }, { 58, 49 }, 4 },
  { { 4|(4<<4) }, { 70, 49 }, 4 },
  { { 4|(5<<4) }, { 82, 49 }, 4 },
  { { 4|(6<<4) }, { 94, 49 }, 4 },
  { { 4|(7<<4) }, { 106, 49 }, 4 },
  { { 10|(0<<4) }, { 118, 49 }, 4 },
  { { 10|(1<<4) }, { 130, 49 }, 4 },
  { { 10|(2<<4) }, { 142, 49 }, 4 },
  { { 10|(3<<4) }, { 165, 49 }, 4 },
  { { 9|(5<<4) }, { 205, 49 }, 4 },
  // KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_APP, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  { { 5|(0<<4) }, { 8, 59 }, 4 },
  { { 5|(1<<4) }, { 23, 59 }, 4 },
  { { 5|(2<<4) }, { 38, 59 }, 4 },
  { { 5|(3<<4) }, { 83, 59 }, 4 },
  { { 5|(4<<4) }, { 129, 59 }, 4 },
  { { 5|(5<<4) }, { 144, 59 }, 4 },
  { { 5|(6<<4) }, { 159, 59 }, 4 },
  { { 5|(7<<4) }, { 174, 59 }, 4 },
  { { 10|(4<<4) }, { 193, 59 }, 4 },
  { { 10|(5<<4) }, { 205, 59 }, 4 },
  { { 10|(6<<4) }, { 217, 59 }, 4 },
  // Underglow / Border
  { { 0xFF }, { 222, 64 }, 2 },
  { { 0xFF }, { 204, 64 }, 2 },
  { { 0xFF }, { 186, 64 }, 2 },
  { { 0xFF }, { 167, 64 }, 2 },
  { { 0xFF }, { 149, 64 }, 2 },
  { { 0xFF }, { 130, 64 }, 2 },
  { { 0xFF }, { 112, 64 }, 2 },
  { { 0xFF }, { 94, 64 }, 2 },
  { { 0xFF }, { 75, 64 }, 2 },
  { { 0xFF }, { 57, 64 }, 2 },
  { { 0xFF }, { 38, 64 }, 2 },
  { { 0xFF }, { 20, 64 }, 2 },
  { { 0xFF }, { 0, 64 }, 2 },
  { { 0xFF }, { 0, 47 }, 2 },
  { { 0xFF }, { 0, 32 }, 2 },
  { { 0xFF }, { 0, 17 }, 2 },
  { { 0xFF }, { 0, 0 }, 2 },
  { { 0xFF }, { 20, 0 }, 2 },
  { { 0xFF }, { 38, 0 }, 2 },
  { { 0xFF }, { 57, 0 }, 2 },
  { { 0xFF }, { 75, 0 }, 2 },
  { { 0xFF }, { 94, 0 }, 2 },
  { { 0xFF }, { 112, 0 }, 2 },
  { { 0xFF }, { 130, 0 }, 2 },
  { { 0xFF }, { 149, 0 }, 2 },
  { { 0xFF }, { 167, 0 }, 2 },
  { { 0xFF }, { 186, 0 }, 2 },
  { { 0xFF }, { 204, 0 }, 2 },
  { { 0xFF }, { 222, 1 }, 2 },
  { { 0xFF }, { 224, 17 }, 2 },
  { { 0xFF }, { 224, 32 }, 2 },
  { { 0xFF }, { 224, 47 }, 2 },
};

#ifdef USB_LED_INDICATOR_ENABLE
void rgb_matrix_indicators_kb(void)
{
  led_matrix_indicators();
}
#endif // USB_LED_INDICATOR_ENABLE

#endif
