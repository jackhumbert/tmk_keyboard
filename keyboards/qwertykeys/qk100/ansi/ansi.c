/* 
Copyright 2023 Qwertykeys

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
#include "ansi.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led g_is31_leds[RGB_MATRIX_LED_COUNT] = {
    {0, CS2_SW1,  CS3_SW1,  CS1_SW1},  /* RGB0-ESC ROW0*/
    {0, CS5_SW1,  CS6_SW1,  CS4_SW1},  /* RGB1-F1 */
    {0, CS8_SW1,  CS9_SW1,  CS7_SW1},  /* RGB2-F2 */
    {0, CS11_SW1,  CS12_SW1,  CS10_SW1},  /* RGB3-F3 */
    {0, CS14_SW1,  CS15_SW1,  CS13_SW1},  /* RGB4-F4 */
    {0, CS17_SW1,  CS18_SW1,  CS16_SW1},  /* RGB5-F5 */
    {0, CS20_SW1,  CS21_SW1,  CS19_SW1},  /* RGB6-F6 */
    {0, CS23_SW1,  CS24_SW1,  CS22_SW1},  /* RGB7-F7 */
    {0, CS26_SW1,  CS27_SW1,  CS25_SW1},  /* RGB8-F8 */
    {0, CS29_SW1,  CS30_SW1,  CS28_SW1},  /* RGB9-F9 */
    {0, CS32_SW1,  CS33_SW1,  CS31_SW1},  /* RGB10-F10 */
    {0, CS35_SW1,  CS36_SW1,  CS34_SW1},  /* RGB11-F11 */
    {0, CS38_SW1,  CS39_SW1,  CS37_SW1},  /* RGB12-F12 */
    {0, CS29_SW7,  CS30_SW7,  CS28_SW7},  /* RGB13-Delete */
    {0, CS32_SW7,  CS33_SW7,  CS31_SW7},  /* RGB14-End */
    {0, CS35_SW7,  CS36_SW7,  CS34_SW7},  /* RGB15-Insert */
    {0, CS38_SW7,  CS39_SW7,  CS37_SW7}, /* RGB16-Home */

    {0, CS2_SW2,  CS3_SW2,  CS1_SW2},  /* RGB17-~ ----ROW1*/
    {0, CS5_SW2,  CS6_SW2,  CS4_SW2},  /* RGB18-1 */
    {0, CS8_SW2,  CS9_SW2,  CS7_SW2},  /* RGB19-2 */
    {0, CS11_SW2,  CS12_SW2,  CS10_SW2},  /* RGB20-3 */
    {0, CS14_SW2,  CS15_SW2,  CS13_SW2},  /* RGB21-4 */
    {0, CS17_SW2,  CS18_SW2,  CS16_SW2},  /* RGB22-5 */
    {0, CS20_SW2,  CS21_SW2,  CS19_SW2},  /* RGB23-6 */
    {0, CS23_SW2,  CS24_SW2,  CS22_SW2},  /* RGB24-7 */
    {0, CS26_SW2,  CS27_SW2,  CS25_SW2},  /* RGB25-8 */
    {0, CS29_SW2,  CS30_SW2,  CS28_SW2},  /* RGB26-9 */
    {0, CS32_SW2,  CS33_SW2,  CS31_SW2},  /* RGB27-0 */
    {0, CS35_SW2,  CS36_SW2,  CS34_SW2},  /* RGB28--- */
    {0, CS38_SW2,  CS39_SW2,  CS37_SW2},  /* RGB29-+= */
    {0, CS26_SW7,  CS27_SW7,  CS25_SW7},  /* RGB30-BS */
    {0, CS29_SW8,  CS30_SW8,  CS28_SW8},  /* RGB31-Num Lock */
    {0, CS32_SW8,  CS33_SW8,  CS31_SW8},  /* RGB32- / */
    {0, CS35_SW8,  CS36_SW8,  CS34_SW8},  /* RGB33- * */
    {0, CS38_SW8,  CS39_SW8,  CS37_SW8},  /* RGB34- - */

    {0, CS2_SW3,  CS3_SW3,  CS1_SW3},  /* RGB35-TAB ----ROW2*/
    {0, CS5_SW3,  CS6_SW3,  CS4_SW3}, /* RGB36-Q */
    {0, CS8_SW3,  CS9_SW3,  CS7_SW3}, /* RGB37-W */
    {0, CS11_SW3,  CS12_SW3,  CS10_SW3}, /* RGB38-E */
    {0, CS14_SW3,  CS15_SW3,  CS13_SW3}, /* RGB39-R */
    {0, CS17_SW3,  CS18_SW3,  CS16_SW3}, /* RGB40-T */
    {0, CS20_SW3,  CS21_SW3,  CS19_SW3}, /* RGB41-Y */
    {0, CS23_SW3,  CS24_SW3,  CS22_SW3}, /* RGB42-U */
    {0, CS26_SW3,  CS27_SW3,  CS25_SW3}, /* RGB43-I */
    {0, CS29_SW3,  CS30_SW3,  CS28_SW3}, /* RGB44-O */
    {0, CS32_SW3,  CS33_SW3,  CS31_SW3}, /* RGB45-P */
    {0, CS35_SW3,  CS36_SW3,  CS34_SW3}, /* RGB46-[ */
    {0, CS38_SW3,  CS39_SW3,  CS37_SW3}, /* RGB47-] */
    {0, CS26_SW9,  CS27_SW9,  CS25_SW9}, /* RGB48-\ */
    {0, CS29_SW9,  CS30_SW9,  CS28_SW9},  /* RGB49-page up */
    {0, CS32_SW9,  CS33_SW9,  CS31_SW9},  /* RGB50-7 */
    {0, CS35_SW9,  CS36_SW9,  CS34_SW9},  /* RGB51-8 */
    {0, CS38_SW9,  CS39_SW9,  CS37_SW9},  /* RGB52-9 */

    {0, CS2_SW4,  CS3_SW4,  CS1_SW4},  /* RGB53-CAPS---ROW3*/
    {0, CS5_SW4,  CS6_SW4,  CS4_SW4},  /* RGB54-A-- */
    {0, CS8_SW4,  CS9_SW4,  CS7_SW4},  /* RGB55-S-- */
    {0, CS11_SW4,  CS12_SW4,  CS10_SW4},  /* RGB56-D */
    {0, CS14_SW4,  CS15_SW4,  CS13_SW4},  /* RGB57-F */
    {0, CS17_SW4,  CS18_SW4,  CS16_SW4},  /* RGB58-G */
    {0, CS20_SW4,  CS21_SW4,  CS19_SW4},  /* RGB59-H */
    {0, CS23_SW4,  CS24_SW4,  CS22_SW4},  /* RGB60-J */
    {0, CS26_SW4,  CS27_SW4,  CS25_SW4},  /* RGB61-K */
    {0, CS29_SW4,  CS30_SW4,  CS28_SW4},  /* RGB62-L */
    {0, CS32_SW4,  CS33_SW4,  CS31_SW4},  /* RGB63-;: */
    {0, CS35_SW4,  CS36_SW4,  CS34_SW4},  /* RGB64-'" */
    {0, CS38_SW4,  CS39_SW4,  CS37_SW4},  /* RGB65-ENTER */
    {0, CS11_SW7,  CS12_SW7,  CS10_SW7}, /* RGB66-Page Down */
    {0, CS14_SW7,  CS15_SW7,  CS13_SW7},  /* RGB67-4 */
    {0, CS17_SW7,  CS18_SW7,  CS16_SW7},  /* RGB68-5 */
    {0, CS20_SW7,  CS21_SW7,  CS19_SW7},  /* RGB69-6 */
    {0, CS23_SW7,  CS24_SW7,  CS22_SW7},  /* RGB70-+ */

    {0, CS2_SW5,  CS3_SW5,  CS1_SW5},  /* RGB71-LSF --ROW4*/
    {0, CS5_SW5,  CS6_SW5,  CS4_SW5},  /* RGB72-Z */
    {0, CS8_SW5,  CS9_SW5,  CS7_SW5},  /* RGB73-X */
    {0, CS11_SW5,  CS12_SW5,  CS10_SW5},  /* RGB74-C */
    {0, CS14_SW5,  CS15_SW5,  CS13_SW5},  /* RGB75-V */
    {0, CS17_SW5,  CS18_SW5,  CS16_SW5},  /* RGB76-B */
    {0, CS20_SW5,  CS21_SW5,  CS19_SW5},  /* RGB77-N */
    {0, CS23_SW5,  CS24_SW5,  CS22_SW5},  /* RGB78-M */
    {0, CS26_SW5,  CS27_SW5,  CS25_SW5},  /* RGB79-,< */
    {0, CS29_SW5,  CS30_SW5,  CS28_SW5},  /* RGB80->. */
    {0, CS32_SW5,  CS33_SW5,  CS31_SW5},  /* RGB81-?/ */
    {0, CS35_SW5,  CS36_SW5,  CS34_SW5},  /* RGB82-RSF */
    {0, CS38_SW5,  CS39_SW5,  CS37_SW5},  /* RGB83-UP */
    {0, CS14_SW8,  CS15_SW8,  CS13_SW8},  /* RGB84-1*/
    {0, CS17_SW8,  CS18_SW8,  CS16_SW8},  /* RGB85-2 */
    {0, CS20_SW8,  CS21_SW8,  CS19_SW8},  /* RGB86-3 */
    {0, CS23_SW8,  CS24_SW8,  CS22_SW8},  /* RGB87-Enter */

    {0, CS2_SW6, CS3_SW6, CS1_SW6}, /* RGB88-lct-- ROW5*/
    {0, CS5_SW6, CS6_SW6, CS4_SW6}, /* RGB89-lwin */
    {0, CS8_SW6, CS9_SW6, CS7_SW6}, /* RGB90-lalt */
    {0, CS11_SW6, CS12_SW6, CS10_SW6}, /* RGB91-sp0 */
    {0, CS17_SW6, CS18_SW6, CS16_SW6}, /* RGB92-sp */
    {0, CS26_SW6, CS27_SW6, CS25_SW6}, /* RGB93-sp2 */
    {0, CS29_SW6, CS30_SW6, CS28_SW6}, /* RGB94-ralt */
    {0, CS32_SW6, CS33_SW6, CS31_SW6}, /* RGB95- fn */
    {0, CS35_SW6, CS36_SW6, CS34_SW6}, /* RGB96-left */
    {0, CS38_SW6, CS39_SW6, CS37_SW6}, /* RGB97-down */
    {0, CS11_SW9, CS12_SW9, CS10_SW9}, /* RGB98-right */
    {0, CS14_SW9, CS15_SW9, CS13_SW9},  /* RGB99- 0 */
    {0, CS20_SW9, CS21_SW9, CS19_SW9}  /* RGB100- . */
};

led_config_t g_led_config = { {
    { 0,   1,   2,   3,      4,      5,  6,      7,      8,      9,  10,  11,     12,      NO_LED, NO_LED, 13, 14,     15, 16 },    
	{ 17,  18,  19,  20,     21,     22, 23,     24,     25,     26, 27,  28,     29,      30,     NO_LED, 31, 32,     33, 34 },    
	{ 35,  36,  37,  38,     39,     40, 41,     42,     43,     44, 45,  46,     47,      48,     49,     50, 51,     52, NO_LED}, 
	{ 53,  54,  55,  56,     57,     58, 59,     60,     61,     62, 63,  64,     NO_LED,  65,     66,     67, 68,     69, 70 },    
	{ 71,  72,  73,  74,     75,     76, 77,     78,     79,     80, 81,  82,     NO_LED,  83,     NO_LED, 84, 85,     86, 87 },    
	{ 88,  89,  90,  91, NO_LED,     92, NO_LED, NO_LED, 93,     94, 95,  NO_LED, 96,      97,     98,     99, NO_LED, 100,NO_LED} 
}, {
    { 0, 0 },  { 18, 0 },  { 30, 0 },  { 42, 0 },  { 54, 0 },  { 72, 0 },  { 84, 0 },  { 96, 0 },   { 108, 0 }, { 126, 0 },  { 138, 0 },  { 150, 0 },  { 162, 0 },                            { 188, 0 },  { 200, 0 },  { 212, 0 }, { 224, 0 }, 
    { 0, 13 }, { 12, 13 }, { 24, 13 }, { 36, 13 }, { 48, 13 }, { 60, 13 }, { 72, 13},  { 84, 13 },  { 96, 13 }, { 108, 13 }, { 120, 13 }, { 132, 13 }, { 144, 13 }, { 156, 13 },              { 188, 13 }, { 200, 13 }, { 212, 13 },{ 224, 13 }, 
    { 0, 26 }, { 18, 26 }, { 30, 26 }, { 42, 26 }, { 54, 26 }, { 66, 26 }, { 78, 26 }, { 90, 26 },  { 102, 26}, { 114, 26 }, { 126, 26 }, { 138, 26 }, { 150, 26 }, { 162, 26 }, { 176, 26 }, { 188, 26 }, { 200, 26 }, { 212, 26 },
    { 0, 39 }, { 20, 39 }, { 32, 39 }, { 44, 39 }, { 56, 39 }, { 68, 39 }, { 80, 39 }, { 92, 39 },  { 104, 39 }, { 120, 39 }, { 132, 39 }, { 132, 39 },             { 144, 39 }, { 176, 39 }, { 188, 39 }, { 200, 39 }, { 212, 39 },{ 224, 39 }, 
    { 0, 52 }, { 26, 52 }, { 38, 52 }, { 50, 52 }, { 62, 52 }, { 74, 52 }, { 86, 52 }, { 98, 52 },  { 110, 52 }, { 122, 52 }, { 134, 52 }, { 150, 52 },             { 170, 52 },              { 188, 52 }, { 200, 52 }, { 212, 52 },{ 224, 52 }, 
    { 0, 64 }, { 14, 64 }, { 28, 64 }, { 42, 64 },             { 74, 64 },                          { 108, 64 }, { 122, 64 }, { 140, 64 },             { 158, 64 }, { 170, 64 }, { 182, 64 }, { 196, 64 },              { 212, 64 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,       1, 1, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    1, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1, 1, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    1,    4, 4, 4, 1,
    1, 1, 1, 4,    4,       4, 1, 1,    1, 1, 1, 4,    4
    }
};



bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {

        case KC_F14:
        rgb_matrix_toggle(); 
        break;

        case KC_F15:
        rgb_matrix_step(); 
        break;

        case KC_F16:  
        rgb_matrix_step_reverse();  
        break;

        case KC_F17:
        rgb_matrix_increase_hue();  //Increase the hue for effect range LEDs
        break;

        case KC_F18:
        rgb_matrix_decrease_hue(); //Decrease the hue for effect range LEDs
        break;

        case KC_F19:
        rgb_matrix_increase_sat(); //Increase the saturation for effect range LEDs
        break;

        case KC_F20:
        rgb_matrix_decrease_sat(); //Decrease the saturation for effect range LEDs
        break;

        case KC_F21:
        rgb_matrix_increase_val(); //Increase the value for effect range LEDs
        break;

        case KC_F22:
        rgb_matrix_decrease_val();//Decrease the value for effect range LEDs
        break;
        
        case KC_F23:
        rgb_matrix_increase_speed();//Increase the speed of the animations
        break;

        case KC_F24:
        rgb_matrix_decrease_speed();//Decrease the speed of the animations
        break;
   
        default:
        break;
    }
  }
  return process_record_user(keycode, record);
}

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

#endif


const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_WHITE}       
);


const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 3, HSV_WHITE}      
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_numlock_layer
);


void keyboard_post_init_kb(void) {
    rgblight_layers = my_rgb_layers;
    keyboard_post_init_user();
}

bool led_update_kb(led_t led_state) {  
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, !led_state.num_lock);
    return false; 
}