/* Copyright 2023 Gyphae Team <https://github.com/gyphae>
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

#ifdef RGB_MATRIX_ENABLE
#define __ NO_LED
led_config_t g_led_config = {
	{
        // Key Matrix to LED Index
        {  0, __,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, __, __, __ },
        { 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13 },
        { 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46 },
        { 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, __, __, __, __ },
        { 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, __, __, __, 72, __ },
        { 83, 82, 81, __, __, 80, __, __, 79 ,78, 77, 76, __, __, 75, 74, 73 },
    },
    {
        // LED Index to Physical Position
        {0,0},           {26,0},  {39,0},  {52,0},  {65,0},  {85,0},  {98,0},   {111,0},  {124,0},  {143,0},  {156,0},  {169,0},  {182,0},
        {0,15}, {13,15}, {26,15}, {39,15}, {52,15}, {65,15}, {78,15}, {91,15},  {104,15}, {117,15}, {130,15}, {143,15}, {156,15}, {176,15}, {198,15}, {211,15}, {224,15},
        {3,28}, {20,28}, {33,28}, {46,28}, {59,28}, {72,28}, {85,28}, {98,28},  {111,28}, {124,28}, {137,28}, {150,28}, {163,28}, {179,28}, {198,28}, {211,28}, {224,28},
        {5,40}, {23,40}, {36,40}, {49,40}, {62,40}, {75,40}, {88,40}, {101,40}, {114,40}, {127,40}, {140,40}, {153,40},      {174,40},
        {8,52},          {29,52}, {42,52}, {55,52}, {68,52}, {81,52}, {94,52},  {107,52}, {120,52}, {133,52}, {146,52},     {171,52},                 {211,52},
        {2,64}, {18,64}, {34,64},                            {83,64},                               {131,64}, {148,64}, {164,64}, {180,64}, {198,64}, {211,64}, {224,64},
    },
    {
        // RGB LED Index to Flag
        1,    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1,
        8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,   1,
        1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,   1,    1,
        1, 1, 1,          4,          1, 1, 1, 1, 1, 1, 1,
    }
};
#ifdef CAPS_LOCK_LED_INDEX
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) { return false; }
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
           RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
        }
    }
    return true;
}
#endif

#endif // RGB_MATRIX_ENABLE