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

#define EECONFIG_USER_DATA_SIZE 15  // size of eeprom data, do not change.

// default options applied when eeprom is cleared
#define DEFAULT_CAPS_LOCK_LIGHT_TAB      false        // true=enable, false=disable
#define DEFAULT_CAPS_LOCK_LIGHT_ALPHA    true         // true=enable, false=disable
#define DEFAULT_FN_LAYER_TRANSPARENT_OFF false        // true=enable, false=disable
#define DEFAULT_FN_LAYER_COLOR           true         // true=enable, false=disable
#define RGB_MATRIX_DEFAULT_HUE           170          // HSV blue hue  (Mac Base layer)
#define DEFAULT_HUE_WIN_BASE             80           // HSV green hue (Win Base layer)
#define RGB_MATRIX_DEFAULT_SAT           255          // Both Win/Mac Base layers
#define RGB_MATRIX_DEFAULT_VAL           25           // Both Win/Mac Base layers
#define RGB_MATRIX_DEFAULT_SPD           127          // Both Win/Mac Base layers
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING  // Both Win/Mac Base layers

// Caps Lock RGB indicator color
#define CAPS_LOCK_INDICATOR_COLOR RGB_RED

// Dynamic Fn Layer RGB indicator options
#define FN1_LAYER_COLOR 0xFE, 0x23, 0x00  // RGB orange
#define FN2_LAYER_COLOR RGB_YELLOW

// Caps Word is activated by double-tapping left Shift. Replace this with 
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD if you want to activate Caps Word 
// by single-tapping both left and right Shift togeter. 
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Caps Word RGB indicator color
#define CAPS_WORD_INDICATOR_COLOR RGB_RED

// Caps Word will light left Shift, left Control and left Option (or left Windows
// key) when acitvated. Remove this line if you want Caps Word to only light left
// Shift when enabled.
#define CAPS_WORD_LIGHT_LOWER_LEFT_CORNER