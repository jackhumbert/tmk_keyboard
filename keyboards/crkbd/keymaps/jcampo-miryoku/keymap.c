#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT, KC_LSFT, KC_Z, RALT_T(KC_X), KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, RALT_T(KC_DOT), KC_SLSH, KC_RSFT, KC_BSPC, MO(1), KC_SPC, KC_ENT, MO(2), KC_DEL),
	[1] = LAYOUT_split_3x6_3(KC_BSPC, KC_NO, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_TAB, KC_LGUI, LALT_T(KC_4), LCTL_T(KC_5), LSFT_T(KC_6), KC_NO, KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TAB, KC_LSFT, KC_0, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RSFT, KC_BSPC, KC_TRNS, KC_SPC, KC_ENT, MO(3), KC_DEL),
	[2] = LAYOUT_split_3x6_3(KC_BSPC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_PIPE, KC_TAB, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_MINS, RSFT_T(KC_EQL), RCTL_T(KC_LBRC), RALT_T(KC_RBRC), RGUI_T(KC_BSLS), KC_SLSH, KC_LSFT, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_GRV, KC_TILD, KC_BSPC, MO(3), KC_SPC, KC_ENT, KC_TRNS, KC_DEL),
	[3] = LAYOUT_split_3x6_3(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, RGB_MOD, RGB_TOG, RGB_VAI, RGB_VAD, KC_NO, KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_NO, KC_NO, KC_NO, BL_TOGG, BL_UP, BL_DOWN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_DEL)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)





