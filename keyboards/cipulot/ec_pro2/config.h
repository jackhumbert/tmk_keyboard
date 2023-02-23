/* Copyright 2023 Cipulot
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

/* Custom matrix pins and port select array */
#define MATRIX_ROW_PINS \
    { B15, A8, B0, A7, B1 }
#define MATRIX_COL_CHANNELS \
    { 0, 3, 1, 2, 5, 7, 6, 4 }
#define MUX_SEL_PINS \
    { B6, B5, B4 }

/* Hardware peripherals pins */
#define APLEX_EN_PIN_0 B7
#define APLEX_EN_PIN_1 B3
#define DISCHARGE_PIN A6
#define ANALOG_PORT A3

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// This is the size of the EEPROM for the custom VIA-specific data
#define EECONFIG_KB_DATA_SIZE 4

#define DEFAULT_ACTUATION_LEVEL 550
#define DEFAULT_RELEASE_LEVEL 500
