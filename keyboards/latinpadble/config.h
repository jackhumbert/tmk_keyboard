/*
Copyright 2021 haierwangwei2005

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#pragma once

#include "config_common.h"
#define VENDOR_ID       0x7C88 // "hw" = haierwangwei2005
#define PRODUCT_ID      0x7C98 // "lp" = latinpadble
#define DEVICE_VER      0x0001
#define MANUFACTURER    haierwangwei2005
#define PRODUCT         latinpadble
#define DESCRIPTION     Panasonic rotary encoder BLE pad

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { F0, F6, F5, F4, F1 }
#define MATRIX_COL_PINS { D6, D7, B5, B6 }
#define UNUSED_PINS

#define DIODE_DIRECTION ROW2COL

#define SSD1306OLED
#define RGB_DI_PIN B7

#define RGBLED_NUM 4
#define DRIVER_LED_TOTAL RGBLED_NUM

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

     #define RGBLIGHT_HUE_STEP 8
     #define RGBLIGHT_SAT_STEP 8
     #define RGBLIGHT_VAL_STEP 8
//   #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
//   #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== all animations enable ==*/
     #define RGBLIGHT_ANIMATIONS
#define OLED_FONT_H "./lib/glcdfont.c"

#define ENCODERS_PAD_A { C7 }
#define ENCODERS_PAD_B { F7 }

#define ENCODER_RESOLUTION 4
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
