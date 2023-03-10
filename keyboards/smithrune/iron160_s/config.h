/*
Copyright 2022 Gondolindrim

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


/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

//                        C0 , C1 , C2 , C3 , C4 , C5 , C6 , C7 , C8 , C9 , C10, C11, C12, C13 
#define MATRIX_COL_PINS { A3 , B9 , B8 , B5 , B4 , B3 , A6 , A5 , A4 , A2 , A1 , A0 , C15, C14}
//                        R0 , R1 , R2 , R3 , R4
#define MATRIX_ROW_PINS { A10, A15, C13, B1 , B10}
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN           A7
#define BACKLIGHT_PWM_DRIVER    PWMD3
#define BACKLIGHT_PWM_CHANNEL   2
#define BACKLIGHT_PAL_MODE      1
#define BACKLIGHT_LEVELS 20
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 3
#define BACKLIGHT_ON_STATE 1
#define LED_CAPS_LOCK_PIN B0
/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
