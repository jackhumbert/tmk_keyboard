#pragma once

#define FORCE_NKRO

#define MOUSEKEY_DELAY             50
#define MOUSEKEY_INTERVAL          15
#define MOUSEKEY_MAX_SPEED         4
#define MOUSEKEY_TIME_TO_MAX       50
#define MOUSEKEY_WHEEL_MAX_SPEED   1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 50

#define NO_ACTION_FUNCTION
#define NO_ACTION_MACRO
#define NO_ACTION_ONESHOT

#undef  RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE

#define PERMISSIVE_HOLD
#define TAPPING_TERM        200
#define TAPPING_TOGGLE      2
#define TAP_HOLD_CAPS_DELAY 50

#define UNICODE_CYCLE_PERSIST  false
#define UNICODE_SELECTED_MODES UC_WINC, UC_WIN, UC_LNX
#define UNICODE_KEY_WINC       KC_RGUI
