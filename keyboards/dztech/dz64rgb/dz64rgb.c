/* Copyright 2021 DZTECH <moyi4681@Live.cn>
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

#include "dz64rgb.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    { 0, K_14, J_14, L_14 },
    { 0, K_13, J_13, L_13 },
    { 0, K_12, J_12, L_12 },
    { 0, K_11, J_11, L_11 },
    { 0, K_10, J_10, L_10 },
    { 0, K_9,  J_9,  L_9 },
    { 0, K_8,  J_8,  L_8 },
    { 0, K_7,  J_7,  L_7 },
    { 0, K_6,  J_6,  L_6 },
    { 0, K_5,  J_5,  L_5 },
    { 0, K_4,  J_4,  L_4 },
    { 0, K_3,  J_3,  L_3 },
    { 0, K_2,  J_2,  L_2 },
    { 0, K_1,  J_1,  L_1 },

    { 0, H_14, G_14, I_14 },
    { 0, H_13, G_13, I_13 },
    { 0, H_12, G_12, I_12 },
    { 0, H_11, G_11, I_11 },
    { 0, H_10, G_10, I_10 },
    { 0, H_9,  G_9,  I_9 },
    { 0, H_8,  G_8,  I_8 },
    { 0, H_7,  G_7,  I_7 },
    { 0, H_6,  G_6,  I_6 },
    { 0, H_5,  G_5,  I_5 },
    { 0, H_4,  G_4,  I_4 },
    { 0, H_3,  G_3,  I_3 },
    { 0, H_2,  G_2,  I_2 },
    { 0, H_1,  G_1,  I_1 },

    { 0, E_14, D_14, F_14 },
    { 0, E_12, D_12, F_12 },
    { 0, E_11, D_11, F_11 },
    { 0, E_10, D_10, F_10 },
    { 0, E_9,  D_9,  F_9 },
    { 0, E_8,  D_8,  F_8 },
    { 0, E_7,  D_7,  F_7 },
    { 0, E_6,  D_6,  F_6 },
    { 0, E_5,  D_5,  F_5 },
    { 0, E_4,  D_4,  F_4 },
    { 0, E_3,  D_3,  F_3 },
    { 0, E_2,  D_2,  F_2 },
    { 0, E_1,  D_1,  F_1 },

    { 0, B_14, A_14, C_14 },
    { 0, B_13, A_13, C_13 },
    { 0, B_12, A_12, C_12 },
    { 0, B_11, A_11, C_11 },
    { 0, B_10, A_10, C_10 },
    { 0, B_9,  A_9,  C_9 },
    { 0, B_8,  A_8,  C_8 },
    { 0, B_7,  A_7,  C_7 },
    { 0, B_6,  A_6,  C_6 },
    { 0, B_5,  A_5,  C_5 },
    { 0, B_4,  A_4,  C_4 },
    { 0, B_3,  A_3,  C_3 },
    { 0, B_2,  A_2,  C_2 },
    { 0, B_1,  A_1,  C_1 },

    { 0, B_15, A_15, C_15 },
    { 0, E_13, D_13, F_13 },
    { 0, K_15, J_15, L_15 },
    { 0, E_15, D_15, F_15 },
    { 0, H_15, G_15, I_15 },
    { 0, B_16, A_16, C_16 },
    { 0, E_16, D_16, F_16 },
    { 0, H_16, G_16, I_16 },
    { 0, K_16, J_16, L_16 }
};

led_config_t g_led_config = {
    {
        { 13, 12, 11,     10,      9,  8,      7,      6,  5,  4,  3,  2,      1,  0 },
        { 27, 26, 25,     24,     23, 22,     21,     20, 19, 18, 17, 16,     15, 14 },
        { 40, 39, 38,     37,     36, 35,     34,     33, 32, 31, 30, 29, NO_LED, 28 },
        { 54, 53, 52,     51,     50, 49,     48,     47, 46, 45, 44, 43, 42,     41 },
        { 63, 62, 61, NO_LED, NO_LED, 60, NO_LED, NO_LED, 59, 58, 57, 56, NO_LED, 55 }
    }, {
        { 216,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 }, { 144,   0 }, { 128,   0 }, { 112,   0 }, {  96,   0 }, {  80,   0 }, {  64,   0 }, {  48,   0 }, {  32,   0 }, {  16,   0 }, {   0,   0 },
        { 220,  16 }, { 200,  16 }, { 184,  16 }, { 168,  16 }, { 152,  16 }, { 136,  16 }, { 120,  16 }, { 104,  16 }, {  88,  16 }, {  72,  16 }, {  56,  16 }, {  40,  16 }, {  24,  16 }, {   4,  16 },
        { 214,  32 }, { 188,  32 }, { 172,  32 }, { 156,  32 }, { 140,  32 }, { 124,  32 }, { 108,  32 }, {  92,  32 }, {  76,  32 }, {  60,  32 }, {  44,  32 }, {  28,  32 },               {   6,  32 },
        { 224,  48 }, { 218,  48 }, { 192,  48 }, { 176,  48 }, { 160,  48 }, { 144,  48 }, { 128,  48 }, { 112,  48 }, {  96,  48 },{80, 48},  {  64,  48 }, {  48,  48 }, {  32,  48 }, {   8,  48 },
        { 224,  64 }, { 208,  64 }, { 192,  64 },                                           { 176,  64 },                             { 160,  64 }, { 102,  64 }, {  42,  64 }, {  22,  64 }, {   2,  64 }
    }, {
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 1, 1,          1,       1, 1, 1, 1, 1
    }
};


bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
    }
    return true;
}
#endif
