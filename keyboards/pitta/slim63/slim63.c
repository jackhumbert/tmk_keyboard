#include "slim63.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
 	{0, K_1,    J_1,    L_1},
    {0, K_2,    J_2,    L_2},
    {0, K_3,    J_3,    L_3},
    {0, K_4,    J_4,    L_4},
    {0, K_5,    J_5,    L_5},
    {0, K_6,    J_6,    L_6},
    {0, K_7,    J_7,    L_7},
    {0, K_8,    J_8,    L_8},
    {0, K_9,    J_9,    L_9},
    {0, K_10,   J_10,   L_10},
    {0, K_11,   J_11,   L_11},
    {0, K_12,   J_12,   L_12},
    {0, K_13,   J_13,   L_13},
	{0, K_14,   J_14,   L_14},
	{0, K_15,   J_15,   L_15},
    {0, K_16,   J_16,   L_16},
	
    {0, H_1,    G_1,    I_1},
    {0, H_2,    G_2,    I_2},
    {0, H_3,    G_3,    I_3},
    {0, H_4,    G_4,    I_4},
    {0, H_5,    G_5,    I_5},
    {0, H_6,    G_6,    I_6},
    {0, H_7,    G_7,    I_7},
    {0, H_8,    G_8,    I_8},
    {0, H_9,    G_9,    I_9},
    {0, H_10,   G_10,   I_10},
    {0, H_11,   G_11,   I_11},
    {0, H_12,   G_12,   I_12},
    {0, H_13,   G_13,   I_13},
    {0, H_14,   G_14,   I_14},
    {0, H_15,   G_15,   I_15},
	{0, H_16,   G_16,   I_16},
		
    {0, E_1,    D_1,    F_1},
    {0, E_2,    D_2,    F_2},
    {0, E_3,    D_3,    F_3},
    {0, E_4,    D_4,    F_4},
    {0, E_5,    D_5,    F_5},
    {0, E_6,    D_6,    F_6},
    {0, E_7,    D_7,    F_7},
    {0, E_8,    D_8,    F_8},
    {0, E_9,    D_9,    F_9},
    {0, E_10,   D_10,   F_10},
    {0, E_11,   D_11,   F_11},
    {0, E_12,   D_12,   F_12},
	{0, E_13,   D_13,   F_13},
    {0, E_14,   D_14,   F_14},
    {0, E_15,   D_15,   F_15},
    {0, E_16,   D_16,   F_16},	

    {0, B_1,    A_1,    C_1},
    {0, B_2,    A_2,    C_2},
    {0, B_3,    A_3,    C_3},
    {0, B_4,    A_4,    C_4},
    {0, B_5,    A_5,    C_5},
    {0, B_6,    A_6,    C_6},
    {0, B_7,    A_7,    C_7},
    {0, B_8,    A_8,    C_8},
    {0, B_9,    A_9,    C_9},
    {0, B_10,   A_10,   C_10},
    {0, B_11,   A_11,   C_11},
    {0, B_12,   A_12,   C_12},
    {0, B_13,   A_13,   C_13},
    {0, B_14,   A_14,   C_14},
    {0, B_15,   A_15,   C_15},
    //{0, B_16,   A_16,   C_16},	
};

led_config_t g_led_config = { {
	{  0 , 1, 2, 3, 4,5 , 6, 7, 8, 9,10,11,12,13 },
	{  16,17,18,19,20,21,22,23,24,25,26,27,28,29 },
    {  32,33,34,35,36,37,38,39,40,41,42,43,NO_LED,44},
	{  48,49,50,51,52,53,54,55,56,57,NO_LED,59,60,61},
    {  14,15,30,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED },
	{  NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,58,31,45,46,47,62,63,}
}, {
	
	{ 0 ,  0} , { 17 ,  0} , { 34 ,  0} , { 51 ,  0} , { 68 ,  0} , { 85 ,  0} , { 102 ,  0} , { 119 ,  0} , { 136 ,  0} , { 153 ,  0} , { 170 ,  0} , { 187 ,  0} , { 204 ,  0} , { 221 ,  0} ,
	{ 0 , 16} , { 17 , 16} , { 34 , 16} , { 51 , 16} , { 68 , 16} , { 85 , 16} , { 102 , 16} , { 119 , 16} , { 136 , 16} , { 153 , 16} , { 170 , 16} , { 187 , 16} , { 204 , 16} , { 221 , 16} ,
	{ 0 , 32} , { 17 , 32} , { 34 , 32} , { 51 , 32} , { 68 , 32} , { 85 , 32} , { 102 , 32} , { 119 , 32} , { 136 , 32} , { 153 , 32} , { 170 , 32} , { 187 , 32} , { 204 , 32} , 
	{ 0 , 48} , { 17 , 48} , { 34 , 48} , { 51 , 48} , { 68 , 48} , { 85 , 48} , { 102 , 48} , { 119 , 48} , { 136 , 48} , { 153 , 48} , { 170 , 48} , { 187 , 48} , { 204 , 48} , 
	{ 0 , 64} , { 17 , 64} , { 34 , 64} ,                           { 85 , 64} ,                             { 136 , 64} , { 153 , 64} , { 170 , 64} , { 187 , 64} , { 204 , 64} ,
	{ 221 , 64} ,

}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 4,	1, 1, 1, 1, 1, 
	//1
} };

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

__attribute__ ((weak))
void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_all(0xFF,0xFF,0xFF);
    }
}
#endif

void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(DEBOUNCE * 2);
    matrix_scan();

    if (matrix_get_row(4) & (1 << 0) && matrix_get_row(4) & (1 << 2)) {
      // Jump to bootloader.
      bootloader_jump();
    }
}
