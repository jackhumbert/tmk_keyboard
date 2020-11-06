#include QMK_KEYBOARD_H

#include "stdio.h"
// #include "raw_hid.h"
#include <unistd.h>
#include <string.h>

#define ANIM_SIZE 384

bool rgbToggled = false;
bool altToggled = false;

enum layer_codes {
  RGB_LAYER = SAFE_RANGE,
  ALT_LAYER
};

enum my_keycodes {
    Z0 = SAFE_RANGE, Z1, Z2, \
    Z3, Z4, Z5, \
    Z6, Z7, Z8, \
    Z9, Z10, Z11, \
    Z12, Z13, Z14
};

#define MAC_1 LCTL(LALT(KC_MINS))
#define MAC_2 LCTL(LALT(KC_EQL))
#define MAC_3 LCTL(LALT(KC_LBRC))
#define MAC_4 LCTL(LALT(KC_RBRC))
#define MAC_5 LCTL(LALT(KC_BSLS))
#define MAC_6 LCTL(LALT(KC_SCLN))
#define MAC_7 LCTL(LALT(KC_QUOT))
#define MAC_8 LCTL(LALT(KC_COMM))
#define MAC_9 LCTL(LALT(KC_SLSH))

#define MAC_10 LCTL(LSFT(KC_MINS))
#define MAC_11 LCTL(LSFT(KC_EQL))
#define MAC_12 LCTL(LSFT(KC_SLSH))
#define MAC_13 LCTL(LSFT(KC_LBRC))
#define MAC_14 LCTL(LSFT(KC_RBRC))
#define MAC_15 LCTL(LSFT(KC_BSLS))
#define MAC_16 LCTL(LSFT(KC_SCLN))
#define MAC_17 LCTL(LSFT(KC_QUOT))
#define MAC_18 LCTL(LSFT(KC_COMM))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
      KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
      MAC_1, MAC_2, MAC_3,
      MAC_4, MAC_5, MAC_6,
      MAC_7, MAC_8, MAC_9,
      RGB_LAYER, ALT_LAYER
  ),
  [1] = LAYOUT(
      RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW,
      RGB_MODE_SWIRL, RGB_SPD, RGB_SPI,
      RGB_MOD, RGB_SAD, RGB_SAI,
      RGB_RMOD, RGB_HUI, RGB_HUD,
      RGB_TOG, RGB_VAD, RGB_VAI,
      RGB_LAYER, ALT_LAYER
  ),
  [2] = LAYOUT(
      MAC_10, MAC_11, MAC_12,
      KC_UNDO, KC_CUT, KC_COPY,
      KC_PASTE, KC_FIND, KC_PSCR,
      MAC_13, MAC_14, MAC_15,
      MAC_16, MAC_17, MAC_18,
      RGB_LAYER, ALT_LAYER
  )
};

static void render_logo(void) {
   static const char PROGMEM ducky_logo[ANIM_SIZE] = {
      0, 0, 0, 0,128,128,128,128,128, 0, 0,252,252,252, 0, 0, 0,128,128,128, 0, 0, 0, 0, 0,128,128,128, 0, 0, 0, 0, 0,128,128,128,128,128, 0, 0, 0, 0, 0,252,252,252, 0, 0, 0, 0, 0,128,128,128,128,128,128, 0, 0, 0, 0, 0, 0,128,128,128,128, 0,248,248,248, 56, 56, 56, 56, 56, 56,120,240,224,192, 0, 0,128,128,128,128,128,128, 0, 0, 0, 0, 0, 0, 0, 0,128,128,128,128,128, 0, 0,252,252,252, 0, 0, 0, 0, 0,232, 24, 24,232, 0, 24, 48, 48, 24, 0,232, 24, 24,232, 0, 0,
      0,248,254,255,143, 7, 3, 3, 3, 7,142,255,255,255, 0, 0, 0,255,255,255, 0, 0, 0, 0, 0,255,255,255, 0,248,254,255,143, 7, 3, 3, 3, 3,143, 7, 2, 0, 0,255,255,255,240,120,252,254,231,131, 1, 0, 1, 7, 63,254,240,192, 0,224,252,127, 31, 3, 0, 0,255,255,255,112,112,112,112,112,112, 56, 63, 31, 15,193,231,243,115, 51, 51, 51, 55,255,255,252, 0, 0,248,254,255,143, 7, 3, 3, 3, 7,142,255,255,255, 0, 0, 0, 0, 0, 21,127,127,252,252,252,253,253,252,252,252,255,255,255, 0, 0, 
      0, 0, 3, 7, 15, 15, 14, 14, 14, 7, 3, 15, 15, 15, 0, 0, 0, 3, 7, 15, 15, 14, 14, 6, 3, 15, 15, 15, 0, 0, 3, 7, 7, 15, 14, 14, 14, 14, 7, 7, 2, 0, 0, 15, 15, 15, 0, 0, 0, 1, 3, 15, 15, 12,136,224,224,224,247,127,127, 31, 3, 0, 0, 0, 0, 0, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, 15, 14, 14, 14, 6, 3, 15, 15, 15, 0, 0, 0, 3, 7, 15, 15, 14, 14, 14, 7, 3, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 11, 3, 11, 7, 11, 7, 7, 31, 0, 0
   };
   oled_write_raw_P(ducky_logo, ANIM_SIZE);
}

/* void raw_hid_receive(uint8_t *data, uint8_t length) {
  uint8_t cmd[33] = {0, 0, 3, 0, 45, 66, 6, 6, 4, 32, 24, 77, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  raw_hid_send(cmd, RAW_EPSIZE);
} */

char* make_menu_text(void){
  char *s = malloc((30 * 3) * sizeof(*s));
  int width = 3;
  sprintf(s, "%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s",
    width, MT_0_0, width, MT_0_1, width, MT_0_2,
    width, MT_0_3, width, MT_0_4, width, MT_0_5,
    width, MT_0_6, width, MT_0_7, width, MT_0_8,
    width, MT_0_9, width, MT_0_10, width,MT_0_11,
    width, MT_0_12, width, MT_0_13, width, MT_0_14
  );
  return s;
};

char* make_rgb_text(void){
  char *s = malloc((30 * 3) * sizeof(*s));
  int width = 3;
  sprintf(
    s, "%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s",
    width, MT_1_0, width, MT_1_1, width, MT_1_2,
    width, MT_1_3, width, MT_1_4, width, MT_1_5,
    width, MT_1_6, width, MT_1_7, width, MT_1_8,
    width, MT_1_9, width, MT_1_10, width,MT_1_11,
    width, MT_1_12, width, MT_1_13, width, MT_1_14
  );
  return s;
};

char* make_alt_text(void){
  char *s = malloc((30 * 3) * sizeof(*s));
  int width = 3;
  sprintf(
    s, "%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s\n%-*s %-*s %-*s",
    width, MT_2_0, width, MT_2_1, width, MT_2_2,
    width, MT_2_3, width, MT_2_4, width, MT_2_5,
    width, MT_2_6, width, MT_2_7, width, MT_2_8,
    width, MT_2_9, width, MT_2_10, width,MT_2_11,
    width, MT_2_12, width, MT_2_13, width, MT_2_14
  );
  return s;
};

void oled_task_user(void) {
  render_logo();
  oled_set_cursor(0,3);
  if (rgbToggled) {
    char *s = make_rgb_text();
    oled_write_ln_P(s, false);
    free(s);
  } else if (altToggled) {
    char *s = make_alt_text();
    oled_write_ln_P(s, false);
    free(s);
  } else {
    char *s = make_menu_text();
    oled_write_ln_P(s, false);
    free(s);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_LAYER:
      if (record->event.pressed) {
        if (rgbToggled) {
          layer_off(1);
          rgbToggled = !rgbToggled;
        } else if (altToggled) {
          layer_off(2);
          layer_on(1);
          altToggled = !altToggled;
        } else {
          layer_on(1);
          rgbToggled = !rgbToggled;
        }
      }
      return false;
    case ALT_LAYER:
      if (record->event.pressed) {
        if (altToggled) {
          layer_off(2);
          altToggled = !altToggled;
        } else if (rgbToggled) {
          layer_off(1);
          layer_on(2);
          rgbToggled = !rgbToggled;
        } else {
          layer_on(1);
          altToggled = !altToggled;
        }
      }
      return false;
    default:
      return true;
  }
  return false;
}