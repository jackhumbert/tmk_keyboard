/*
Copyright 2012,2013 gezhaoyou <gezhaoyou@126.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QK_USER_1:
        if (record->event.pressed) {            
            tap_code16(LGUI(KC_SPACE));
            wait_ms(1000);
            tap_code(KC_LEFT_GUI);
            wait_ms(1000);
            SEND_STRING("terminal");
            wait_ms(1000);
            tap_code(KC_ENTER);
            wait_ms(1000);
            SEND_STRING("open https://veilid.com\n");
            wait_ms(1000);
            SEND_STRING("start https://veilid.com\n");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_1x1(QK_USER_1),
};