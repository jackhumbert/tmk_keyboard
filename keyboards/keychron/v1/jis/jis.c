/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

const snled27351_led_t PROGMEM g_snled27351_leds[SNLED27351_LED_COUNT] = {
/* Refer to SNLED27351 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, C_1,    A_1,    B_1},
    {0, C_2,    A_2,    B_2},
    {0, C_3,    A_3,    B_3},
    {0, C_4,    A_4,    B_4},
    {0, C_5,    A_5,    B_5},
    {0, C_6,    A_6,    B_6},
    {0, C_7,    A_7,    B_7},
    {0, C_8,    A_8,    B_8},
    {0, C_9,    A_9,    B_9},
    {0, C_10,   A_10,   B_10},
    {0, C_11,   A_11,   B_11},
    {0, C_12,   A_12,   B_12},
    {0, C_13,   A_13,   B_13},
    {0, C_14,   A_14,   B_14},
    {0, C_16,   A_16,   B_16},

    {0, I_1,    G_1,    H_1},
    {0, I_2,    G_2,    H_2},
    {0, I_3,    G_3,    H_3},
    {0, I_4,    G_4,    H_4},
    {0, I_5,    G_5,    H_5},
    {0, I_6,    G_6,    H_6},
    {0, I_7,    G_7,    H_7},
    {0, I_8,    G_8,    H_8},
    {0, I_9,    G_9,    H_9},
    {0, I_10,   G_10,   H_10},
    {0, I_11,   G_11,   H_11},
    {0, I_12,   G_12,   H_12},
    {0, I_13,   G_13,   H_13},
    {0, I_14,   G_14,   H_14},
    {0, I_15,   G_15,   H_15},
    {0, I_16,   G_16,   H_16},

    {0, F_1,    D_1,    E_1},
    {0, F_2,    D_2,    E_2},
    {0, F_3,    D_3,    E_3},
    {0, F_4,    D_4,    E_4},
    {0, F_5,    D_5,    E_5},
    {0, F_6,    D_6,    E_6},
    {0, F_7,    D_7,    E_7},
    {0, F_8,    D_8,    E_8},
    {0, F_9,    D_9,    E_9},
    {0, F_10,   D_10,   E_10},
    {0, F_11,   D_11,   E_11},
    {0, F_12,   D_12,   E_12},
    {0, F_13,   D_13,   E_13},
    {0, F_16,   D_16,   E_16},

    {1, I_1,    G_1,    H_1},
    {1, I_2,    G_2,    H_2},
    {1, I_3,    G_3,    H_3},
    {1, I_4,    G_4,    H_4},
    {1, I_5,    G_5,    H_5},
    {1, I_6,    G_6,    H_6},
    {1, I_7,    G_7,    H_7},
    {1, I_8,    G_8,    H_8},
    {1, I_9,    G_9,    H_9},
    {1, I_10,   G_10,   H_10},
    {1, I_11,   G_11,   H_11},
    {1, I_12,   G_12,   H_12},
    {1, I_14,   G_14,   H_14},
    {0, F_14,   D_14,   E_14},
    {1, I_16,   G_16,   H_16},

    {1, F_1,    D_1,    E_1},
    {1, F_3,    D_3,    E_3},
    {1, F_4,    D_4,    E_4},
    {1, F_5,    D_5,    E_5},
    {1, F_6,    D_6,    E_6},
    {1, F_7,    D_7,    E_7},
    {1, F_8,    D_8,    E_8},
    {1, F_9,    D_9,    E_9},
    {1, F_10,   D_10,   E_10},
    {1, F_11,   D_11,   E_11},
    {1, F_12,   D_12,   E_12},
    {1, F_13,   D_13,   E_13},
    {1, F_14,   D_14,   E_14},
    {1, F_15,   D_15,   E_15},

    {1, C_1,    A_1,    B_1},
    {1, C_2,    A_2,    B_2},
    {1, C_3,    A_3,    B_3},
    {1, C_4,    A_4,    B_4},
    {1, C_7,    A_7,    B_7},
    {1, C_10,   A_10,   B_10},
    {1, C_11,   A_11,   B_11},
    {1, C_12,   A_12,   B_12},
    {1, C_13,   A_13,   B_13},
    {1, C_14,   A_14,   B_14},
    {1, C_15,   A_15,   B_15},
    {1, C_16,   A_16,   B_16},
};

#define __ NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, __, 14 },
        { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 },
        { 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 58, __, 44 },
        { 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, __, 57, __, 59 },
        { 60, __, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, __ },
        { 74, 75, 76, 77, __, __, 78, __, __, 79, 80, 81, 82, 83, 84, 85 },
    },
    {
        // LED Index to Physical Position
        {0,  0},           {18,  0}, {33,  0}, {48,  0}, {62,  0}, {81,  0}, {95,   0}, {110,  0}, {125,  0}, {143,  0}, {158,  0}, {173,  0}, {187,  0}, {205,  0}, {224,  0},
        {0, 15}, {15, 15}, {29, 15}, {44, 15}, {59, 15}, {73, 15}, {88, 15}, {103, 15}, {117, 15}, {132, 15}, {147, 15}, {161, 15}, {176, 15}, {191, 15}, {205, 15}, {224, 15},
        {4, 28}, {22, 28}, {37, 28}, {51, 28}, {66, 28}, {81, 28}, {95, 28}, {110, 28}, {125, 28}, {139, 28}, {154, 28}, {169, 28}, {183, 28},                       {224, 28},
        {6, 40}, {26, 40}, {40, 40}, {55, 40}, {70, 40}, {84, 40}, {99, 40}, {114, 40}, {128, 40}, {143, 40}, {158, 40}, {172, 40}, {187, 40}, {207, 36},            {224, 40},
        {9, 52},           {33, 52}, {48, 52}, {62, 52}, {77, 52}, {92, 52}, {106, 52}, {121, 52}, {136, 52}, {150, 52}, {165, 52}, {180, 52}, {194, 52}, {209, 52},
        {2, 64}, {18, 64}, {35, 64},                     {51, 64},                      { 92, 64}, {134, 64}, {150, 64}, {165, 64}, {180, 64}, {194, 64}, {209, 64}, {224, 64},
    },
    {
        // RGB LED Index to Flag
        1,    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,       1,
        8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    1,
        1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
        1, 1, 1, 1,       4,       1, 1, 1, 1, 1, 1, 1,
    }
};

#endif // RGB_MATRIX_ENABLE
