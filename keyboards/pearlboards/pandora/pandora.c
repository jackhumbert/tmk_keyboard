/* Copyright 2021 Koobaczech
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

#include "pandora.h"

void matrix_init_kb(void) {
    matrix_init_user();
    led_init_ports();
};

/* Initiate indicator leds */
void led_init_ports(void) {
    setPinOutput(E6);
    writePinHigh(E6);
}

/* Activate indicator leds */
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        // writePin sets the pin high for 1 and low for 0.
        // In this implementation the pins are inverted, setting
        // it low/0 turns it on, and high/1 turns the LED off.
        // This behavior is because the LED is between the pin
        // and VCC.
        writePin(E6, !led_state.caps_lock);
    }
    return res;
}
