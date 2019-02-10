/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

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

#define CUSTOM_MATRIX 2

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5369
#define PRODUCT_ID      0x005B
#define DEVICE_VER      0x0814
#define MANUFACTURER    Sirius
#define PRODUCT         UniGo66
#define DESCRIPTION     UniGo66 Wireless Split keyboard


/* size of virtual matrix */
#define MATRIX_ROWS 16
#define MATRIX_COLS 16

/* matrix scanning is done in custom_matrix.cpp */
#define DIODE_DIRECTION CUSTOM_MATRIX

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
