/*
Copyright 2020 David Doan

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4152 // "AR"
#define PRODUCT_ID      0x4F46 // "OF"
#define DEVICE_VER      0x0001
#define MANUFACTURER    Array Peripherals
#define PRODUCT         [1x4] + 1 Macropad

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 5


#define DIRECT_PINS {   \
    { C7, B7, D6, F5, F7} \
}
#define UNUSED_PINS

/* rotary encoder*/
#define ENCODERS_PAD_A {F0}
#define ENCODERS_PAD_B {F1}

//This is for VIA configurator
#define DYNAMIC_KEYMAP_LAYER_COUNT 2
