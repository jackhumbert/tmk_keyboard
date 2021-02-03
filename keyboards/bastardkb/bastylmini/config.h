/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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
#include "config_common.h"
#define VENDOR_ID 0xA8F8
#define PRODUCT_ID 0x1828
#define DEVICE_VER 0x0001
#define MANUFACTURER Bastard Keyboards
#define PRODUCT Bastyl Mini

#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define DIODE_DIRECTION ROW2COL
#define MATRIX_ROW_PINS { B5, F7, F6, B6 }
#define MATRIX_COL_PINS { B4, E6, C6, B1, B3, B2 }
#define RGB_DI_PIN D2
#define RGBLED_NUM 21
#define RGBLIGHT_SPLIT
#define RGBLIGHT_ANIMATIONS
#define DEBOUNCE 5
#define SOFT_SERIAL_PIN D0
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define MASTER_RIGHT
