/*
Copyright 2017 Danny Nguyen <danny@hexwire.com>

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

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3061
#define DEVICE_VER      0x0002
#define MANUFACTURER    Legonut
#define PRODUCT         "Project Zen"
#define DESCRIPTION     "Split gaming keyboard"

/* key matrix size */
// Rows are doubled-up

// wiring of each half
#ifdef CONVERT_TO_PROTON_C
  #define MATRIX_ROWS 5
  #define MATRIX_COLS 7
#else
  #define MATRIX_ROWS 10
  #define MATRIX_COLS 7
#endif

// Proton-C does pin conversion
#define MATRIX_ROW_PINS { C6, E6, B5, D7, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B3, B1, B2 }

#define NUMBER_OF_ENCODERS 1

#define ENCODERS_PAD_A  { D4 }
#define ENCODERS_PAD_B  { D2 }

#define RGB_DI_PIN         B6
#define SOFT_SERIAL_PIN    D3

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGBLED_NUM 34    // Number of LEDs

// If using 90 Degree rotation, increase block cout
#ifdef OLED_ROTATE90
  #define OLED_DISPLAY_CUSTOM
  #define OLED_DISPLAY_WIDTH 128
  #define OLED_DISPLAY_HEIGHT 32
  #define OLED_MATRIX_SIZE (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH) // 512 (compile time mathed)
  #define OLED_BLOCK_TYPE uint16_t // Type to use for segmenting the oled display for smart rendering, use unsigned types only
  #define OLED_BLOCK_COUNT (sizeof(OLED_BLOCK_TYPE) * 8) // 8 (compile time mathed)
  #define OLED_BLOCK_SIZE (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT) // 32 (compile time mathed)
  #define OLED_SOURCE_MAP { 0, 8, 16, 24 }
  #define OLED_TARGET_MAP { 24, 16, 8, 0 }
#endif

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
