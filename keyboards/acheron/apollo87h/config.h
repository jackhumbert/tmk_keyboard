/*
Copyright 2022 Álvaro "Gondolindrim" Volpato <alvaro.volpato@usp.br>

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4150 // AP for AcheronProject
#define PRODUCT_ID      0x8772 // For 87H
#define DEVICE_VER      0x0004 // Revision Delta
#define MANUFACTURER    AcheronProject
#define PRODUCT         Apollo87H

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

//                        C0 , C1 , C2 , C3 , C4 , C5 , C6 , C7 , C8 , C9 , C10, C11, C12, C13, C14, C15, C16 } 
#define MATRIX_COL_PINS { C8 , C9 , A8 , A10, C7 , C6 , B14, B12, B10, B1 , C5 , C4 , A7 , B0 , C11, A3 , B4  }
//                        R0 , R1 , R2 , R3 , R4 , R5 
#define MATRIX_ROW_PINS { B3 , D2 , C12, A6 , A5 , A4 }
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define EEPROM_I2C_24LC256
//#define I2C1_CLOCK_SPEED 400000
//#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE

#define STM32_HSECLK 8000000

#define RGB_DI_PIN B15
#define RGBLED_NUM 87
#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_DEFAULT_VAL 120
#define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_RAINBOW_SWIRL + 2)

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

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
