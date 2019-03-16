#include <string.h>
#include <stdio.h>
#include "oled.h"

// NOTE: Redefined to avoid to use snprintf(); It makes size of firmware big.
const char *read_mode_icon(bool windows_mode) {
  static const char logo[][2][3] = {{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}};
  static char mode_icon[10];

  int mode_number = windows_mode ? 1 : 0;
  strcpy(mode_icon, logo[mode_number][0]);

  strcat(mode_icon, "\n");
  strcat(mode_icon, logo[mode_number][1]);

  return mode_icon;
}

const char *read_layer_state(void) {
  static char layer_state_str[24];
  char layer_name[17];

  switch (biton32(layer_state)) {
    case L_BASE:
      strcpy(layer_name, "Default");
      break;
    case _RAISE:
      strcpy(layer_name, "Raise");
      break;
    case _LOWER:
      strcpy(layer_name, "Lower");
      break;
    default:
      snprintf(layer_name, sizeof(layer_name), "Undef-%ld", layer_state);
  }

  strcpy(layer_state_str, "Layer: ");

  strcat(layer_state_str, layer_name);
  strcat(layer_state_str, "\n");
  return layer_state_str;
}

const char *read_host_led_state(void) {
  static char led_str[24];
  strcpy(led_str, (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NMLK" : "    ");
  strcat(led_str, (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? " CAPS" : "    ");
  strcat(led_str, (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? " SCLK" : "     ");
  return led_str;
}

void oled_task_user(void) {
#ifdef MASTER_RIGHT
  if (!is_master) {
#else
  if (is_master) {
#endif // MASTER_RIGHT
    oled_write(read_mode_icon(!get_enable_kc_lang()), false);
    oled_write(" ", false);
    oled_write(read_layer_state(), false);
    oled_write(read_host_led_state(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
