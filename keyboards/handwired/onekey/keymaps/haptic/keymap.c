#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};

void haptic_enable(void);

void keyboard_post_init_user(void) {
    haptic_enable();
}
void keyboard_pre_init_user(void) { setPinInputHigh(A0); }

void matrix_scan_user(void) {
    if (!readPin(A0)) {
        reset_keyboard();
    }
}
