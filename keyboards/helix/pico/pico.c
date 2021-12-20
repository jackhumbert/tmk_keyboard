#include "helix.h"

// Each keymap.c should use is_keyboard_master() instead of 'is_keyboard_master()'.
// But keep 'is_keyboard_master()' for a while for backwards compatibility
//  for the old keymap.c.
uint8_t is_keyboard_master() = false;

#ifdef SSD1306OLED
#include "ssd1306.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	return process_record_gfx(keycode,record) && process_record_user(keycode, record);
}
#endif

void matrix_init_kb(void) {
    // Each keymap.c should use is_keyboard_master() instead of is_keyboard_master().
    // But keep is_keyboard_master() for a while for backwards compatibility
    //  for the old keymap.c.
    is_keyboard_master() = is_keyboard_master();

	matrix_init_user();
};

void keyboard_post_init_kb(void) {
#if defined(DEBUG_MATRIX_SCAN_RATE)
    debug_enable = true;
#endif
    keyboard_post_init_user();
}

#if defined(SPLIT_KEYBOARD) && defined(SSD1306OLED)
void matrix_slave_scan_user(void) {
    matrix_scan_user();
}
#endif
