/* Copyright 2023 @ Mike Killewald (https://github.com/mkillewald)
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

#pragma once

#define EECONFIG_USER_DATA_SIZE 15

#ifdef CAPS_WORD_ENABLE
#   define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#   define CAPS_WORD_INDICATOR_COLOR RGB_RED
#   define CAPS_WORD_LIGHT_LOWER_LEFT_CORNER
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING
#   define RGB_MATRIX_DEFAULT_SPD 127
#   define RGB_MATRIX_DEFAULT_HUE 170 // HSV blue hue
#   define RGB_MATRIX_DEFAULT_SAT 255
#   define RGB_MATRIX_DEFAULT_VAL 255

#   define HUE_WIN_BASE  80 // HSV green hue

#   define CAPS_LOCK_INDICATOR_COLOR RGB_RED
#   define FN1_LAYER_COLOR 0xFE, 0x23, 0x00  // RGB orange
#   define FN2_LAYER_COLOR RGB_YELLOW
#endif