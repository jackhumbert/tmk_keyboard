/* Copyright 2020 W. Alex Ronke, a.k.a. NoPunIn10Did (w.alex.ronke@gmail.com)
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

#define CUT     LCTL(KC_X)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
/* Left Block */
   KC_SLCK,KC_PAUS,KC_ESC ,KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_MINS,  
   KC_PSCR,KC_BSPC,        KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_LBRC,
   KC_CAPS,                KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_PGUP,
   CUT    ,                KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_PGDN,
   COPY   ,PASTE  ,        KC_LCTL,KC_LGUI,KC_LALT,KC_NUBS,KC_SPC ,KC_DEL ,
/* Center Block */
   KC_F1  ,KC_F5  ,KC_F9  ,
   KC_F2  ,KC_F6  ,KC_F10 , 
   KC_F3  ,KC_F7  ,KC_F11 , 
   KC_F4  ,KC_F8  ,KC_F12 , 
/* Right Block */
   KC_EQL ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,        KC_INS ,KC_ESC , 
   KC_RBRC,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,        KC_DEL ,/*ISO*/   
   KC_HOME,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,        KC_ENT ,KC_ENT , 
   KC_END ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,        KC_UP  ,
           KC_CALC,KC_SPC ,KC_NUHS,KC_ALGR,KC_RCTL,        KC_LEFT,KC_DOWN,KC_RGHT 
  )

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    //keyevent_t event = record->event;

    switch (id) {

    }
    return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

    if (usb_led & (1 << USB_LED_NUM_LOCK)) {

    } else {

    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

    } else {

    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

    } else {

    }

    if (usb_led & (1 << USB_LED_COMPOSE)) {

    } else {

    }

    if (usb_led & (1 << USB_LED_KANA)) {

    } else {

    }

}
