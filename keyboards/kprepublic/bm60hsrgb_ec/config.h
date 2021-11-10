
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4B50 // "KP"
#define PRODUCT_ID      0xEF9C
#define DEVICE_VER      0x0001
#define MANUFACTURER    KP Republic
#define PRODUCT         BM60HSRGB_EC
#define DESCRIPTION     A 60% hotswap inswitch rgb board

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14
#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 2

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

//                         0   1   2   3   4   5   6   7   8   9   A   B   C   D
#define MATRIX_ROW_PINS { B0, B1, B2, B3, E6 }
#define MATRIX_COL_PINS { D0, D1, D2, D3, D5, D4, D6, D7, B4, B5, B6, C6, C7, F7 }

#define DIODE_DIRECTION COL2ROW
#define FORCE_NKRO

#define RGB_DI_PIN E2
#define DRIVER_LED_TOTAL 69
#ifdef RGB_DI_PIN
    #define RGBLED_NUM 69
    #define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 140
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_BAND_SAT
#endif

