/* Copyright 2021 MajorKoos <https://github.com/majorkoos>

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
#define VENDOR_ID       0x20A0
#define PRODUCT_ID      0x4152
#define DEVICE_VER      0x0100
#define MANUFACTURER    LeeKu
#define PRODUCT         LZ CLSm

/* matrix */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16
#define MATRIX_COL_PINS { A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, B2, B3, B4, B5, B6, B7 }
#define MATRIX_ROW_PINS { C2, C3, C4, C5, C6, C7 }
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

/* i2c */
#define I2C_BITRATE_KHZ 400
#define I2C_TARGET_ADDR 0xB0

/* bling */
#define BACKLIGHT_LEVELS 1
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 200
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLED_NUM 14

/* USb Config
#define USB_MAX_POWER_CONSUMPTION 400
*/

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
