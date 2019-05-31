#pragma once

<<<<<<< HEAD
/* Use I2C rather than serial communicaiton to reduce latency. */
#define USE_I2C

/* Turn off RGB lighting when the host goes to sleep. */
#define RGBLIGHT_SLEEP
=======
/*
 * I2C seems to randomly drop keystrokes. Not sure why. It seems a bit like
 * https://github.com/qmk/qmk_firmware/issues/5037, but that issue is closed,
 * and our problems happen even with underglow disabled.
 *
 * This issue occurs with multiple TRRS cables of different lengths from
 * different companies, so it's most likely not a cable issue.  It may be that
 * we are running into issues with long I2C runs, in which case stronger
 * pull-up resistors might help:
 * https://hackaday.com/2017/02/08/taking-the-leap-off-board-an-introduction-to-i2c-over-long-wires/.
 * For now, just don't use I2C.
 */
#define USE_SERIAL
>>>>>>> master

/* Use an extra LED on the right side since it's wider on the 65% PCB. */
#undef RGBLED_NUM
#define RGBLED_NUM 17

/* Set up RGB lighting so it works with either side as master. */
#define RGBLED_SPLIT { 8, 9 }
<<<<<<< HEAD

/* Make mouse operation smoother. */
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16

/* Lower mouse speed to adjust for reduced MOUSEKEY_INTERVAL. */
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_TIME_TO_MAX 150
#define MOUSEKEY_WHEEL_MAX_SPEED 4
#define MOUSEKEY_WHEEL_TIME_TO_MAX 150
=======
>>>>>>> master
