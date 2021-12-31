/*
  Copyright 2019 @foostan
  Copyright 2020 Drashna Jaelre <@drashna>

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

#include "config_common.h"

#define MASTER_LEFT

/* #define MASTER_RIGHT */
/* #define EE_HANDS */

/* otherwise the other promicro v3 isn't found */

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

#define FORCED_SYNC_THROTTLE_MS 100

#define OLED_DISPLAY_128X64


/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x6060
#define DEVICE_VER   0x0001
#define MANUFACTURER gebhart
#define PRODUCT      Morpho

/* key matrix size */
/* Rows are doubled-up */
/* wiring of each half */
#define MATRIX_ROWS  12
#define MATRIX_COLS  7
#define MATRIX_ROW_PINS                         \
  { D4, C6, D7, E6, B4, B5}

#define MATRIX_COL_PINS                         \
  { F4, F5, F6, F7, B1, B3, B2 }

/* #define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order */


/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
/* #define NO_DEBUG */

/* disable print */
/* #define NO_PRINT */

/* disable action features */
/* #define NO_ACTION_LAYER */
/* #define NO_ACTION_TAPPING */
/* #define NO_ACTION_ONESHOT */
/* #define NO_ACTION_MACRO */
/* #define NO_ACTION_FUNCTION */

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION


/* ws2812 RGB LED */
#define RGB_DI_PIN      D3

#define DIODE_DIRECTION ROW2COL

//#define DIODE_DIRECTION COL2ROW
