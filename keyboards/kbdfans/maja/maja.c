#include "maja.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
	{0, C2_1,  C3_1,  C4_1},  // LA0
    {0, C1_1,  C3_2, C4_2},   // LA1
    {0, C1_2,  C2_2, C4_3},   // LA2
    {0, C1_3,  C2_3, C3_3},   // LA3
    {0, C1_4,  C2_4, C3_4},   // LA4
    {0, C1_5,  C2_5, C3_5},   // LA5
    {0, C1_6,  C2_6, C3_6},   // LA6
    {0, C1_15, C2_15, C3_15}, // LB7
	{0, C1_14, C2_14, C3_14}, // LB6
    {0, C1_13, C2_13, C3_13}, // LB5
    {0, C1_12, C2_12, C3_12}, // LB4
    {0, C1_11, C2_11, C3_11}, // LB3
    {0, C1_10, C2_10, C4_11}, // LB2
    {0, C1_9,  C3_10, C4_10}, // LB1	
	{0, C2_9,  C3_9,  C4_9},  // LB0

    {0, C9_4,  C8_4, C7_4},   // LA12
    {0, C9_3,  C8_3, C7_3},   // LA11
    {0, C9_2,  C8_2, C7_2},   // LA10
    {0, C9_1,  C8_1, C7_1},   // LA9
    {0, C1_8,  C2_8, C3_8},   // LA8
    {0, C1_7,  C2_7, C3_7},   // LA7
    {0, C1_16, C2_16, C3_16}, // LB8
    {0, C9_9,  C8_9,  C7_9},  // LB9
    {0, C9_10, C8_10, C7_10}, // LB10
    {0, C9_11, C8_11, C7_11}, // LB11
    {0, C9_12, C8_12, C7_12}, // LB12
    {0, C9_13, C8_13, C7_13}, // LB13
    {0, C9_14, C8_14, C7_14}, // LB14
    {0, C9_15, C8_15, C6_14}, // LB15
    {0, C9_16, C7_15, C6_15}, // LB16

    {0, C9_5,  C8_5, C7_5},   // LA13
    {0, C9_6,  C8_6, C7_6},   // LA14
    {0, C9_7,  C8_7, C6_6},   // LA15
    {0, C9_8,  C7_7, C6_7},   // LA16
    {0, C8_8,  C7_8, C6_8},   // LA17
    {1, C2_1,  C3_1,  C4_1},  // LC0
    {1, C1_15, C2_15, C3_15}, // LD7	
    {1, C1_14, C2_14, C3_14}, // LD6	
    {1, C1_13, C2_13, C3_13}, // LD5	
    {1, C1_12, C2_12, C3_12}, // LD4	
    {1, C1_11, C2_11, C3_11}, // LD3
    {1, C1_10, C2_10, C4_11}, // LD2
    {1, C1_9,  C3_10, C4_10}, // LD1
    {0, C8_16, C7_16, C6_16}, // LB17

    {1, C1_6,  C2_6, C3_6},   // LC6
    {1, C1_5,  C2_5, C3_5},   // LC5	
    {1, C1_4,  C2_4, C3_4},   // LC4	
    {1, C1_3,  C2_3, C3_3},   // LC3
    {1, C1_2,  C2_2, C4_3},   // LC2	
    {1, C1_1,  C3_2, C4_2},   // LC1
    {1, C1_16, C2_16, C3_16}, // LD8
    {1, C9_9,  C8_9,  C7_9},  // LD9
    {1, C9_10, C8_10, C7_10}, // LD10
    {1, C9_11, C8_11, C7_11}, // LD11
    {1, C9_12, C8_12, C7_12}, // LD12
    {1, C9_13, C8_13, C7_13}, // LD13
    {1, C9_14, C8_14, C7_14}, // LD14
    {1, C2_9,  C3_9,  C4_9},  // LD0

    {1, C1_7,  C2_7, C3_7},   // LC7
    {1, C1_8,  C2_8, C3_8},   // LC8
    {1, C9_1,  C8_1,  C7_1},  // LC9
    {1, C9_2,  C8_2, C7_2},   // LC10
    {1, C9_3,  C8_3, C7_3},   // LC11
    {1, C9_4,  C8_4, C7_4},   // LC12
    {1, C9_15, C8_15, C6_14}, // LD15
    {1, C9_16, C7_15, C6_15}, // LD16
    {1, C8_16, C7_16, C6_16} // LD17
};

led_config_t g_led_config = { {
    {  0,   1,      2,   3,   4,      5,   6,      7,   8,      9,   10,     11,     12,     13,  14},
    {  15,  16,     17,  18,  19,     20,  21,     22,  23,     24,  25,     26,     27,     28,  29,},
    {  30,  31,     32,  33,  34,     35,  36,     37,  38,     39,  40,     41,     NO_LED, 42,  43},
    {  44,  45,     46,  47,  48,     49,  50,     51,  52,     53,  54,     55,     56,     57,  NO_LED},
	{  58,  NO_LED, 59,  60,  NO_LED, 61,  NO_LED, 62,  NO_LED, 63,  NO_LED, NO_LED, 64,     65,  66}
}, { 
    {4,1},{18,1},{31,0},{46,3},{59,5},{73,7},{86,10},{107,9},{121,7},{134,4},{148,2},{162,0},{176,2},{196,2},{224,0},
	{5,15},{22,15},{37,15},{50,17},{64,20},{77,22},{103,23},{117,21},{130,19},{143,16},{158,15},{171,16},{186,16},{202,16},{224,16},
	{4,28},{23,28},{38,29},{51,31},{65,34},{78,36},{109,36},{122,34},{136,32},{150,29},{164,29},{177,29},{200,29},{224,29},
	{5,42},{27,42},{42,43},{55,46},{69,48},{82,51},{104,51},{118,48},{131,46},{145,44},{159,43},{173,43},{192,43},{214,46},
	{0,55},{40,58},{62,61},{86,64},{119,62},{147,58},{201,60},{214,60},{224,60}
}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 
	4, 4, 4, 1, 4, 4, 1, 1, 1
} };

void matrix_init_kb(void) {
    matrix_init_user();
}
void matrix_scan_kb(void) {
    matrix_scan_user();
}
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
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
