/*
Copyright 2021 kb-elmo<mail@elmo.space>

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
#define VENDOR_ID    0x4D58
#define PRODUCT_ID   0x0369
#define DEVICE_VER   0x0001
#define MANUFACTURER matrix
#define PRODUCT      m12og_v1

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 3

/* Keyboard Matrix Assignments */

#define MATRIX_ROW_PINS { A0, A1 }
#define MATRIX_COL_PINS { C0, C1, C2 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Caps LED */
#define LED_CAPS_LOCK_PIN B6

/* RGB */
#define RGB_DI_PIN B8
#define RGBLIGHT_ANIMATIONS

#define RGBLED_NUM 16
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
