#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// help for fast typist+dual function keys?
#define PERMISSIVE_HOLD

// where is the cord plugged in?
#define MASTER_RIGHT

/* speed up mousekeys a bit */
#define MOUSEKEY_DELAY             50
#define MOUSEKEY_INTERVAL          20
#define MOUSEKEY_MAX_SPEED         8
#define MOUSEKEY_TIME_TO_MAX       30
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// because I'm lazy and didn't case out the rgb support
#define RGBLED_NUM 2

#define BACKLIGHT_PIN B7
#define BACKLIGHT_LEVELS 3

#endif
