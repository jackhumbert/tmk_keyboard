/* Copyright 2023 Gondolindrim <gondolindrim@acheronproject.com>
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
#include "print.h"

// This function gets called when caps, num, scroll change
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        led_state.caps_lock ? sethsv( HSV_RED, (rgb_led_t *)&led[0]) : sethsv( HSV_BLACK, (rgb_led_t *)&led[0]);
    }
    return res;
}

// This function is called when layers change
layer_state_t layer_state_set_kb(layer_state_t state) {
    switch(get_highest_layer(state)) {
        case 1:   
            sethsv(HSV_GREEN, (rgb_led_t *)&led[1]);
            break;
        case 2:   
            sethsv(HSV_BLUE, (rgb_led_t *)&led[2]);
            break;
        default:
            sethsv(HSV_BLACK, (rgb_led_t *)&led[1]);
            sethsv(HSV_BLACK, (rgb_led_t *)&led[2]);
            break;
    }
    return state;
}
