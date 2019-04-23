#include "crkbd.h"


#ifdef AUDIO_ENABLE
    float tone_startup[][2] = SONG(STARTUP_SOUND);
    float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

#ifdef SSD1306OLED
void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    //led_set_user(usb_led);
}
#endif

#ifdef RGB_MATRIX_ENABLE

  // Logical Layout
  // Columns
  // Left
  // 0  1  2  3  4  5
  //                   ROWS
  // 25 24 19 18 11 10   0
  //    03    02    01
  // 26 23 20 17 12 09   1
  //    04    05    06
  // 27 22 21 16 13 08   2
  //
  //          15 14 07   3
  //
  // Right
  // 0  1  2  3  4  5
  //                    ROWS
  // 25 24 19 18 11 10   4
  //    03    02    01
  // 26 23 20 17 12 09   5
  //    04    05    06
  // 27 22 21 16 13 08   6
  //
  //          15 14 07   7
  //
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 25 24 19 18 11 10       10 11 18 19 24 25  0
  //    03    02    01       01    02    03
  // 26 23 20 17 12 09       09 12 17 20 23 26  1
  //    04                               04
  // 27 22 21 16 13 08       08 13 16 21 22 27  2
  //          05    06       06    05
  //           15 14 07     07 14 15              3

/* {row | col << 4} logical layout rows/cols
 *      |                    {x=0..224,     y=0..64} physical layout
 *      |                            |           |     modifier
 *      |                            |           |   */
#define RGB_MATRIX_LEFT_LEDS  \
    { { 0xFF           }, {  85, 16 }, 0 }, /*  1 */ \
    { { 0xFF           }, {  50, 13 }, 0 }, /*  2 */ \
    { { 0xFF           }, {  16, 20 }, 0 }, /*  3 */ \
    { { 0xFF           }, {  16, 38 }, 0 }, /*  4 */ \
    { { 0xFF           }, {  50, 48 }, 0 }, /*  5 */ \
    { { 0xFF           }, {  85, 52 }, 0 }, /*  6 */ \
    { { 3 | ( 5 << 4 ) }, {  95, 63 }, 1 }, /*  7 */ \
    { { 2 | ( 5 << 4 ) }, {  85, 39 }, 0 }, /*  8 */ \
    { { 1 | ( 5 << 4 ) }, {  85, 21 }, 0 }, /*  9 */ \
    { { 0 | ( 5 << 4 ) }, {  85,  4 }, 0 }, /* 10 */ \
    { { 0 | ( 4 << 4 ) }, {  68, 02 }, 0 }, /* 11 */ \
    { { 1 | ( 4 << 4 ) }, {  68, 19 }, 0 }, /* 12 */ \
    { { 2 | ( 4 << 4 ) }, {  68, 37 }, 0 }, /* 13 */ \
    { { 3 | ( 4 << 4 ) }, {  80, 58 }, 1 }, /* 14 */ \
    { { 3 | ( 3 << 4 ) }, {  60, 55 }, 1 }, /* 15 */ \
    { { 2 | ( 3 << 4 ) }, {  50, 35 }, 0 }, /* 16 */ \
    { { 1 | ( 3 << 4 ) }, {  50, 13 }, 0 }, /* 17 */ \
    { { 0 | ( 3 << 4 ) }, {  50,  0 }, 0 }, /* 18 */ \
    { { 0 | ( 2 << 4 ) }, {  33,  3 }, 0 }, /* 19 */ \
    { { 1 | ( 2 << 4 ) }, {  33, 20 }, 0 }, /* 20 */ \
    { { 2 | ( 2 << 4 ) }, {  33, 37 }, 0 }, /* 21 */ \
    { { 2 | ( 1 << 4 ) }, {  16, 42 }, 0 }, /* 22 */ \
    { { 1 | ( 1 << 4 ) }, {  16, 24 }, 0 }, /* 23 */ \
    { { 0 | ( 1 << 4 ) }, {  16,  7 }, 0 }, /* 24 */ \
    { { 0 | ( 0 << 4 ) }, {   0,  7 }, 1 }, /* 25 */ \
    { { 1 | ( 0 << 4 ) }, {   0, 24 }, 1 }, /* 26 */ \
    { { 2 | ( 0 << 4 ) }, {   0, 41 }, 1 }, /* 27 */

#define RGB_MATRIX_RIGHT_LEDS  \
    { { 0xFF           }, { 139, 16 }, 0 }, /*  1 */ \
    { { 0xFF           }, { 174, 13 }, 0 }, /*  2 */ \
    { { 0xFF           }, { 208, 20 }, 0 }, /*  3 */ \
    { { 0xFF           }, { 208, 38 }, 0 }, /*  4 */ \
    { { 0xFF           }, { 174, 48 }, 0 }, /*  5 */ \
    { { 0xFF           }, { 139, 52 }, 0 }, /*  6 */ \
    { { 7 | ( 5 << 4 ) }, { 129, 63 }, 1 }, /*  7 */ \
    { { 6 | ( 5 << 4 ) }, { 139, 39 }, 0 }, /*  8 */ \
    { { 5 | ( 5 << 4 ) }, { 139, 21 }, 0 }, /*  9 */ \
    { { 4 | ( 5 << 4 ) }, { 139,  4 }, 0 }, /* 10 */ \
    { { 4 | ( 4 << 4 ) }, { 156, 02 }, 0 }, /* 11 */ \
    { { 5 | ( 4 << 4 ) }, { 156, 19 }, 0 }, /* 12 */ \
    { { 6 | ( 4 << 4 ) }, { 156, 37 }, 0 }, /* 13 */ \
    { { 7 | ( 4 << 4 ) }, { 144, 58 }, 1 }, /* 14 */ \
    { { 7 | ( 3 << 4 ) }, { 164, 55 }, 1 }, /* 15 */ \
    { { 6 | ( 3 << 4 ) }, { 174, 35 }, 0 }, /* 16 */ \
    { { 5 | ( 3 << 4 ) }, { 174, 13 }, 0 }, /* 17 */ \
    { { 4 | ( 3 << 4 ) }, { 174,  0 }, 0 }, /* 18 */ \
    { { 4 | ( 2 << 4 ) }, { 191,  3 }, 0 }, /* 19 */ \
    { { 5 | ( 2 << 4 ) }, { 191, 20 }, 0 }, /* 20 */ \
    { { 6 | ( 2 << 4 ) }, { 191, 37 }, 0 }, /* 21 */ \
    { { 6 | ( 1 << 4 ) }, { 208, 42 }, 0 }, /* 22 */ \
    { { 5 | ( 1 << 4 ) }, { 208, 24 }, 0 }, /* 23 */ \
    { { 4 | ( 1 << 4 ) }, { 208,  7 }, 0 }, /* 24 */ \
    { { 4 | ( 0 << 4 ) }, { 224,  7 }, 1 }, /* 25 */ \
    { { 5 | ( 0 << 4 ) }, { 224, 24 }, 1 }, /* 26 */ \
    { { 6 | ( 0 << 4 ) }, { 224, 41 }, 1 }, /* 27 */

#ifdef RGB_MATRIX_SPLIT_RIGHT
const rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
        RGB_MATRIX_RIGHT_LEDS
        RGB_MATRIX_LEFT_LEDS
    };
#else
const rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
        RGB_MATRIX_LEFT_LEDS
        RGB_MATRIX_RIGHT_LEDS
    };
#endif

#endif
void matrix_init_kb(void) {

    #ifdef AUDIO_ENABLE
        _delay_ms(20); // gets rid of tick
        PLAY_SONG(tone_startup);
    #endif

	matrix_init_user();
};

void shutdown_kb(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_goodbye);
      	_delay_ms(150);
      	stop_all_notes();
    #endif
}
