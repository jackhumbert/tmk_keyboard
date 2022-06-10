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
 * |Ctrl|GUI |Alt |     Space               |MO(2) |MO(3)|   |Lt |Dn |Rt |
 * `---------------------------------------------------------------------|'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT_65_ansi_blocker(
          KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
          KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,   KC_ENT,           KC_MUTE,
          KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,   KC_UP,    KC_DEL,
          KC_LCTL, KC_LGUI, KC_LALT,                        KC_SPC,                   MO(2), MO(3),           KC_LEFT, KC_DOWN,  KC_RIGHT
    ),
    [1] = LAYOUT_65_ansi_blocker(
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______,            _______,
      _______,              _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,   _______,
      _______,  _______,    _______,                           _______,                                    _______,    _______,              _______,  _______,  _______
    ),
    [2] = LAYOUT_65_ansi_blocker(
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______,            _______,
      _______,              _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,   _______,
      _______,  _______,    _______,                           _______,                                    _______,    _______,              _______,  _______,  _______
    ),
    [3] = LAYOUT_65_ansi_blocker(
      _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,   KC_F12,  _______,
      _______,  _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______,   
      QK_BOOT,    _______,    _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______,            KC_MPLY,
      _______,              _______,    _______,    _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,  _______, _______,   _______,
      _______,  _______,    _______,                           _______,                                    _______,    _______,              _______,  _______,  _______
    ),
};

/* Encoder */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    /* Used to change the layer using the encoder. */
    static int8_t selected_layer = 0; 

    if (clockwise){
        /* Check if left shift is pressed: */
        if (selected_layer < 4 && get_mods() & MOD_BIT(KC_LSFT)){
            selected_layer ++;
            /* If already on the last layer, jumps back to the first layer: */
            if (selected_layer == 4) {
                selected_layer = 0;
            }
            /* Move to the selected layer. */
            layer_move(selected_layer); 
        } else if (get_mods() & MOD_BIT(KC_RSFT)){ /* Check if right shift is pressed: */
            switch (get_highest_layer(layer_state)){
                default:
                    /* Go to the next track. */
                    tap_code(KC_MNXT);
                    break;
            }
        } else {
            /* If shift isn't pressed, encoder will do this stuff: */
            switch (get_highest_layer(layer_state)){
                default:
                    /* Turn up the volume of the system. */
                    tap_code(KC_VOLU);
                    break;
            }
        }
    } else {
        /* Check if left shift is pressed: */
        if (selected_layer > -1 && get_mods() & MOD_BIT(KC_LSFT)){
            selected_layer --;
            /* If already on the first layer, jumps up to the last layer: */
            if (selected_layer == -1) {
                selected_layer = 3;
            }
        /* Move to the selected layer. */
            layer_move(selected_layer);
        } else if (get_mods() & MOD_BIT(KC_RSFT)){ /* Check if right shift is pressed: */
            switch (get_highest_layer(layer_state)){
                default:
                    /* Go to the previous track. */
                    tap_code(KC_MPRV);
                    break;
            }
        } else {
            /* If shift isn't pressed, encoder will do this stuff: */
            switch (get_highest_layer(layer_state)){
                default:
                    /* Turn down the volume of the system. */
                    tap_code(KC_VOLD);
                    break;
            }
        }
    }
    return false;
}
#endif

#ifdef OLED_ENABLE
/*===========================================    OLED CONFIGURATION    ===========================================*/
bool  oled_horizontal   = true;         // OLED rotation  (true = horizontal,  false = vertical)
bool  graph_direction   = false;         // Graph movement  (true = right to left,  false = left to right)
float graph_top_wpm     = 100.0;        // Minimum WPM required to reach the top of the graph
int   graph_refresh     = 1000;         // In milliseconds, determines the graph-line frequency
int   icon_med_wpm      = 50;           // WPM required to display the medium snail
int   icon_fast_wpm     = 72;           // WPM required to display the fast snail
// Layer names:  Should be exactly 5 characters in length if vertical display, or 6 characters if horizontal
#define MA_LAYER_NAME     "QWRTY"      // Layer 0 name
#define L1_LAYER_NAME     "KICAD"      // Layer 1 name
#define L2_LAYER_NAME     "NMPAD"      // Layer 2 name
#define L3_LAYER_NAME     "FUNCT"      // Layer 3 name
// Constants required for the background render, the graph render and the WPM counter. THESE VALUES SHOULD NOT BE CHANGED.
bool  first_loop  = true;
int   timer       = 0;
int   wpm_limit   = 20;
int   max_wpm     = -1;
int   wpm_icon    = -1;
int   graph_lines[65];
/*================================================================================================================*/

/* Rotation of the OLED: */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (oled_horizontal) {
        return OLED_ROTATION_180;
    } else {
        return OLED_ROTATION_270;
    }
}

// Toggles pixel on/off, converts horizontal coordinates to vertical equivalent if necessary
static void write_pixel(int x, int y, bool onoff) {
    if (oled_horizontal) {
        oled_write_pixel(x, y, onoff);
    } else {
        oled_write_pixel(y, 127 - x, onoff);
    }
}

/*======================================    BASE KEYBOARD MATRIX IMAGES    =======================================*/
// Draw static background image to OLED (keyboard with no bottom row)
static void render_background(void) {
    if (oled_horizontal) {
        static const char PROGMEM oled_keymap_horizontal[] = {
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x84, 0x80, 0x80, 0x80, 0x80, 0x04, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x80, 0x04, 
	    0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 
	    0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 
	    0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 
	    0x80, 0x04, 0x04, 0x04, 0x04, 0x84, 0x84, 0x84, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 
	    0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
	    0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	    0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x42, 0x42, 0x02, 0x02, 0x02, 0x02, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, 0x42, 0x40, 0x00, 0x00, 
	    0x00, 0x02, 0x40, 0x40, 0x40, 0x40, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x40, 0x40, 0x40, 0x40, 
	    0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 
	    0x40, 0x40, 0x40, 0x00, 0x02, 0x00, 0x00, 0x40, 0x40, 0x02, 0x00, 0x00, 0x00, 0x40, 0x42, 0x02, 
	    0x02, 0x02, 0x02, 0x42, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00    
	};
        oled_write_raw_P(oled_keymap_horizontal, sizeof(oled_keymap_horizontal));
    } else {
        static const char PROGMEM oled_keymap_vertical[] = {
	    0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 
	    0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x87, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 
	    0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 
	    0x00, 0x43, 0x00, 0x00, 0x00, 0x00, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 
	    0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 
	    0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	    0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 
	    0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 
	    0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 
	    0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 
	    0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00    
	};
        oled_write_raw_P(oled_keymap_vertical, sizeof(oled_keymap_vertical));
    }
}
/*================================================================================================================*/


/*===============================    PIXEL'S COORDINATES FOR EACH PHYSICAL KEY    ================================*/
// Location of OLED keyboard's top left pixel, relative to the display
static const int keymap_template[2] = {46, 0};
// Location of key highlights top left pixels, relative to keymap_template  {X, Y, Key length in px}
static int keymap_coords[MATRIX_ROWS][MATRIX_COLS][3] = {
    { {0, 0, 1}, {5, 0, 1}, {10, 0, 1}, {15, 0, 1}, {20, 0, 1}, {25, 0, 1}, {30, 0, 1} },
    { {0, 5, 5}, {9, 5, 1}, {14, 5, 1}, {19, 5, 1}, {24, 5, 1}, {29, 5, 1}, {34, 5, 1} },
    { {0, 10, 6}, {10, 10, 1}, {15, 10, 1}, {20, 10, 1}, {25, 10, 1}, {30, 10, 1}, {35, 10, 1} },
    { {0, 15, 8}, {12, 15, 1}, {17, 15, 1}, {22, 15, 1}, {27, 15, 1}, {32, 15, 1}, {37, 15, 1} },
    { {0, 20, 2}, {6, 20, 2}, {12, 20, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {18, 20, 33} },
    { {35, 0, 1}, {40, 0, 1}, {45, 0, 1}, {50, 0, 1}, {55, 0, 1}, {60, 0, 1}, {65, 0, 8} },
    { {39, 5, 1}, {44, 5, 1}, {49, 5, 1}, {54, 5, 1}, {59, 5, 1}, {64, 5, 1}, {69, 5, 4} },
    { {40, 10, 1}, {45, 10, 1}, {50, 10, 1}, {55, 10, 1}, {60, 10, 1}, {65, 10, 8}, {77, 10, 1} },
    { {42, 15, 1}, {47, 15, 1}, {52, 15, 1}, {57, 15, 1}, {62, 15, 6}, {72, 15, 1}, {77, 15, 1} },
    { {0, 0, 0}, {0, 0, 0}, {55, 20, 2}, {61, 20, 2}, {67, 20, 1}, {72, 20, 1}, {77, 20, 1} },
    };

// Toggles pixels surrounding key
static void render_keymap(uint8_t key_row, uint8_t key_col, bool onoff) {
    int length = keymap_coords[key_row][key_col][2] + 4;
    int left   = keymap_coords[key_row][key_col][0] + keymap_template[0];
    int top    = keymap_coords[key_row][key_col][1] + keymap_template[1];
    int right  = left + length - 1;
    int bottom = top + 4;

    // Draw top and bottom walls (horizontal for <length>px)
    for (int x = 0; x < length; x++) {
        write_pixel(left + x, top, onoff);
        write_pixel(left + x, bottom, onoff);
    }
    // Draw left and right walls (vertical for 5px)
    for (int y = 0; y < 5; y++) {
        write_pixel(left,  top + y, onoff);
        write_pixel(right, top + y, onoff);
    }
}
/*================================================================================================================*/

/*=============================================    LAYER'S NAME    ===============================================*/
// Write active layer name
static void render_layer_state(void) {
  if (oled_horizontal) {
    oled_set_cursor(0, 0);
  } else {
    oled_set_cursor(0, 15);
  }
  switch (get_highest_layer(layer_state)) {
  case 0:
      oled_write_P(PSTR(MA_LAYER_NAME), false);
      break;
  case 1:
      oled_write_P(PSTR(L1_LAYER_NAME), false);
      break;
  case 2:
      oled_write_P(PSTR(L2_LAYER_NAME), false);
      break;
  case 3:
      oled_write_P(PSTR(L3_LAYER_NAME), false);
      break;
  default:
      oled_write("ERROR", false);
      break;
  }
}
/*================================================================================================================*/

/*====================================    WPM COUNTERS (CURRENT AND MAX)    ======================================*/    
// Update WPM counters
static void render_wpm_counters(int current_wpm) {
    int cursorposition_cur = 2;
    int cursorposition_max = 1;
    if (oled_horizontal == false) {
        cursorposition_cur = 13;
        cursorposition_max = 14;
    }

    oled_set_cursor(0, cursorposition_cur);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);

    char wpm_counter[4];
    wpm_counter[3] = '\0';
    wpm_counter[2] = '0' + current_wpm % 10;
    wpm_counter[1] = '0' + (current_wpm / 10) % 10;
    wpm_counter[0] = '0' + (current_wpm / 100) % 10;
    
    if (current_wpm > max_wpm) {
        max_wpm = current_wpm;
        wpm_limit = max_wpm + 20;
        oled_set_cursor(0, cursorposition_max);
        oled_write(wpm_counter, false);
    }
}
/*================================================================================================================*/

/*==============================================    WPM GRAPH    =================================================*/ 
// Update WPM graph
static void render_wpm_graph(int current_wpm) {
    int line_height = ((current_wpm / graph_top_wpm) * 7);
    if (line_height > 7) {
        line_height = 7;
    }
    // Count graph line pixels, return if nothing to draw
    int pixel_count = line_height;
    for (int i = 0; i < 64; i++) {
        pixel_count += graph_lines[i];
    }
    if (pixel_count == 0) {
        return;
    }
    // Shift array elements left or right depending on graph_direction, append new graph line
    if (graph_direction) {
        for (int i = 0; i < 64; i++) {
            graph_lines[i] = graph_lines[i + 1];
        }
        graph_lines[64] = line_height;
    } else {
        for (int i = 64; i > 0; i--) {
            graph_lines[i] = graph_lines[i - 1];
        }
        graph_lines[0] = line_height;
    }
    // Draw all graph lines (left to right, bottom to top)
    int draw_count, arrpos;
    for (int x = 1; x <= 127; x += 2) {
        arrpos = x / 2;
        draw_count = graph_lines[arrpos];
        for (int y = 31; y >= 25; y--) {
            if (draw_count > 0) {
                write_pixel(x, y, true);
                draw_count--;
            } else {
                write_pixel(x, y, false);
            }
        }
    }
}
/*================================================================================================================*/

/*========================================    WPM BASED SNAIL ICON    ============================================*/ 
// Update WPM snail icon
static void render_wpm_icon(int current_wpm) {
    // wpm_icon is used to prevent unnecessary redraw
    if ((current_wpm < icon_med_wpm) && (wpm_icon != 0)) {
        wpm_icon = 0;
    } else if ((current_wpm >= icon_med_wpm) && (current_wpm < icon_fast_wpm) && (wpm_icon != 1)) {
        wpm_icon = 1;
    } else if ((current_wpm >= icon_fast_wpm) && (wpm_icon != 2)) {
        wpm_icon = 2;
    } else {
        return;
    }
    static const char PROGMEM snails[][2][24] = {
        {{0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0xA0, 0x20, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x50, 0x88, 0x04, 0x00, 0x00},
         {0x40, 0x60, 0x50, 0x4E, 0x51, 0x64, 0x4A, 0x51, 0x54, 0x49, 0x41, 0x62, 0x54, 0x49, 0x46, 0x41, 0x40, 0x30, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00}},
        {{0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x04, 0x98, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00},
         {0x60, 0x50, 0x54, 0x4A, 0x51, 0x64, 0x4A, 0x51, 0x55, 0x49, 0x41, 0x62, 0x54, 0x49, 0x46, 0x41, 0x21, 0x10, 0x0A, 0x08, 0x05, 0x02, 0x00, 0x00}},
        {{0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x10, 0x10, 0x10, 0x20, 0x40, 0x40, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00},
         {0x60, 0x58, 0x54, 0x62, 0x49, 0x54, 0x52, 0x51, 0x55, 0x49, 0x62, 0x52, 0x4D, 0x45, 0x46, 0x22, 0x21, 0x11, 0x10, 0x0A, 0x08, 0x05, 0x02, 0x00}}
    };
    if (oled_horizontal) {
        oled_set_cursor(3, 1);
        oled_write_raw_P(snails[wpm_icon][0], sizeof(snails[wpm_icon][0]));
        oled_set_cursor(3, 2);
        oled_write_raw_P(snails[wpm_icon][1], sizeof(snails[wpm_icon][1]));
    } else {
        oled_set_cursor(0, 11);
        oled_write_raw_P(snails[wpm_icon][0], sizeof(snails[wpm_icon][0]));
        oled_set_cursor(0, 12);
        oled_write_raw_P(snails[wpm_icon][1], sizeof(snails[wpm_icon][1]));
    }
}
/*================================================================================================================*/

/* Function that renders stuff on the oled */
bool oled_task_user(void) {
    // Draw OLED keyboard, preventing redraw.
    if (first_loop) {
	render_background();
	first_loop = false; 
    }

    // Get current WPM
    int current_wpm = get_current_wpm(); 
    // Write active layer name to display
    render_layer_state();
    // Update WPM counters
    render_wpm_counters(current_wpm);
    // Update WPM snail icon
    render_wpm_icon(current_wpm);
    // Update WPM graph every graph_refresh milliseconds
    if (timer_elapsed(timer) > graph_refresh) {
        render_wpm_graph(current_wpm);
        timer = timer_read();
    }

    return false;
}
#endif

// Called by QMK during key processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
    // Toggle pixels surrounding key
    render_keymap(record->event.key.row, record->event.key.col, record->event.pressed);
    #endif

    return true;
}
