#pragma once

#include "config_common.h"

#define VENDOR_ID    0x4A4B 
#define PRODUCT_ID   0xEF6A
#define DEVICE_VER   0x0001
#define MANUFACTURER JadooKB
#define PRODUCT      JKB65 RGB

#define MATRIX_ROWS 5
#define MATRIX_COLS 16

#define MATRIX_ROW_PINS { E6, B7, F7, F4, F5 }
#define MATRIX_COL_PINS { F6,B1,F1,C7,C6,B6,B5,B4,D7,B3,D4,D5,D3,D2,D1,D0 }

#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN F0

#define DRIVER_LED_TOTAL 67
#ifdef RGB_DI_PIN
    #define RGBLED_NUM 67

    #define RGB_DISABLE_WHEN_USB_SUSPENDED true
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_SLEEP
    #define RGB_DISABLE_TIMEOUT 0 
    #define RGB_DISABLE_AFTER_TIMEOUT 0
    #define RGBLIGHT_TIMEOUT 60000
#endif

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#endif

#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

