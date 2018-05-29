/* Copyright 2018 Lbibass /u/Lbibass
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xCA40
#define DEVICE_VER      0x0002
#define MANUFACTURER    LBIBASS
#undef PRODUCT
#define PRODUCT         Mechmicro
#undef DESCRIPTION
#define DESCRIPTION     40% keyboard clone.

/* key matrix size */
#undef MATRIX_COLS
#undef MATRIX_ROWS
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS {B6, B3, B1, F5}
#define MATRIX_COL_PINS {B5, B4, E6, D7, C6, D4, D0, D1, F6, F4, F7}
#define UNUSED_PINS
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL
#define MATRIX_ROW_PINS {B6, B2, B3, B1}
#define MATRIX_COL_PINS {B5, B4, E6, D7, C6, D4, D0, D1, F6, F4, F7}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#define BACKLIGHT_PIN B6
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5
#endif
