/* Copyright 2023 deddia permana (@depermana12)
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
#include "quantum.h"

#define LOGO_TIMEOUT 3000
#define CUSTOM_OLED_TIMEOUT 30000

static uint32_t logo_timer = 0;
static bool display_logo = true;

void dp3000_logo(void) {
    static const char PROGMEM dp3000_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x60, 0x7c, 0x7c, 0x60, 0x60, 0x60, 0x60,
        0x7c, 0x7c, 0x60, 0x60, 0x60, 0x60, 0x7c, 0x7c, 0x60, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x86, 0x86, 0x86, 0xff, 0xff, 0x00, 0x00, 0xf8, 0xf8, 0x18, 0x18, 0xf0, 0xe0,
        0x00, 0x00, 0xf8, 0xf8, 0x18, 0x18, 0xf8, 0xf0, 0x00, 0x00, 0xff, 0xff, 0x86, 0x86, 0x86, 0x00,
        0x00, 0x00, 0x00, 0x18, 0x18, 0x98, 0x98, 0xf8, 0xf0, 0x00, 0xf0, 0xf8, 0x18, 0x18, 0xf8, 0xf0,
        0x00, 0xf0, 0xf8, 0x18, 0x18, 0xf8, 0xf0, 0x00, 0xf0, 0xf8, 0x18, 0x18, 0xf8, 0xf0, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x61, 0x61, 0x61, 0xff, 0xff, 0x00, 0x00, 0x1f, 0x1f, 0x18, 0x18, 0x0f, 0x07,
        0x00, 0x00, 0x1f, 0x1f, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0xff, 0xff, 0x61, 0x61, 0x61, 0x00,
        0x00, 0x00, 0x00, 0x18, 0x18, 0x19, 0x19, 0x1f, 0x0f, 0x00, 0x0f, 0x1f, 0x18, 0x18, 0x1f, 0x0f,
        0x00, 0x0f, 0x1f, 0x18, 0x18, 0x1f, 0x0f, 0x00, 0x0f, 0x1f, 0x18, 0x18, 0x1f, 0x0f, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x06, 0x3e, 0x3e, 0x06, 0x06, 0x06, 0x06,
        0x3e, 0x3e, 0x06, 0x06, 0x06, 0x06, 0x3e, 0x3e, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
    oled_write_raw_P(dp3000_logo, sizeof(dp3000_logo));
}

void default_status(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("LAYER: "), false);
    oled_write_char('0' + get_highest_layer(layer_state), false);
    oled_set_cursor(0, 1);
    oled_write_P(PSTR("LOCK: "), false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (timer_elapsed32(logo_timer) > LOGO_TIMEOUT) {
        display_logo = false;
        oled_clear();
        logo_timer = timer_read32();
    }
    if (last_input_activity_elapsed() > CUSTOM_OLED_TIMEOUT) {
        oled_off();
    }else {
        oled_on();
    }
    if (display_logo) {
        dp3000_logo();
    } else {
        default_status();
    }

    return false;
}
