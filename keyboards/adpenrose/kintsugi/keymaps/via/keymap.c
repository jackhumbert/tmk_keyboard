/* Copyright 2021 adpenrose
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
#include <stdio.h>

//Constants:
char wpm_str[4]; // Used in the wpm counter function.

/* Base layout:
 * ,---------------------------------------------------------------------|
 * |`  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0   |-   |=  |Backspace| OLED|
 * |---------------------------------------------------------------      |
 * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  | ]  |   \      OLED|
 * |---------------------------------------------------------------------|
 * |Caps  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |  Enter     | ENC |
 * |---------------------------------------------------------------------|
 * |Shft    |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift       |Up| M1 |
 * |---------------------------------------------------------------------|
 * |Ctrl|GUI |Alt |     Space                    |Alt |Fn|   |Lt |Dn |Rt |
 * `---------------------------------------------------------------------|'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT_65_ansi_blocker(
          KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
          KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,   KC_ENT,           KC_MUTE,
          KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,   KC_UP,    KC_DEL,
          KC_LCTL, KC_LGUI, KC_LALT,                        KC_SPC,                   MO(2),   MO(3),             KC_LEFT, KC_DOWN,  KC_RIGHT
    ),
    [1] = LAYOUT_65_ansi_blocker(
      _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,   KC_F12,  _______,
      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, 
      RESET,    _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______,            KC_MPLY,
      _______,              _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,   _______,
      _______,  _______,    _______,                            KC_SPC,                                    _______,    _______,              _______,  _______,  _______
    ),
    [2] = LAYOUT_65_ansi_blocker(
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______,            KC_MNXT,
      _______,              _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,   _______,
      _______,  _______,    _______,                           _______,                                    _______,    _______,              _______,  _______,  _______
    ),
    [3] = LAYOUT_65_ansi_blocker(
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______,            _______,
      _______,              _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,   _______,
      _______,  _______,    _______,                           _______,                                    _______,    _______,              _______,  _______,  _______
    ),
};

// Encoder
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
/* The switch case allows for different encoder mappings on different layers, "default" map gets applied for all unspecified layers */
    switch(get_highest_layer(layer_state)){
        case 1:
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
            break;
        default:
            if (clockwise){
                tap_code(KC_VOLU);
            } else{
                tap_code(KC_VOLD);
            }
            break;
        }
    return true;
}
#endif

// Rotation of the OLED:
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Kintsugi logo render:
static void render_logo(void) {
    static const char PROGMEM logo_1[] = {
        0x83, 0x84, 0x85, 0x86, 0x87, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0x00
    };
    static const char PROGMEM logo_2[] = {
        0x88, 0x89, 0x8A, 0x8B, 0x8C, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0x00
    };
    static const char PROGMEM logo_3[] = {
        0x8D, 0x8E, 0x8F, 0x90, 0x91, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0x00
    };
    oled_set_cursor(1,3);
    oled_write_P(logo_1, false);
    oled_set_cursor(1,7);
    oled_write_P(logo_2, false);
    oled_set_cursor(1,11);
    oled_write_P(logo_3, false);
}

// Function that renders stuff on the oled:
bool oled_task_user(void) {
    // Function that renders the kintsugi logo in the desired order.
    render_logo();
    return false;
}
#endif
