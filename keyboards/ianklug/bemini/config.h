/*
Copyright 2022 Ian Klug

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

#define VENDOR_ID    0x4B4C // "KL" = klug
#define PRODUCT_ID   0x424D // "BM" = bemini
#define DEVICE_VER   0x0001
#define MANUFACTURER ianklug
#define PRODUCT      bemini

#define MATRIX_ROWS 1
#define MATRIX_COLS 13

/* switch wiring (direct, no diodes) */
#define DIRECT_PINS { \
    { C7, C6, B6, B5, B4, D7, D6, D4, D3, D2, D1, D0, F5 } \
}
#define UNUSED_PINS

/* encoder pins */
#define ENCODERS_PAD_A { F7 }
#define ENCODERS_PAD_B { F6 }

/* debounce */
#define DEBOUNCE 5

/* gamepad buttons and axes */
#define JOYSTICK_BUTTON_COUNT 16
#define JOYSTICK_AXES_COUNT 2

/* n-key rollover */
#define FORCE_NKRO
