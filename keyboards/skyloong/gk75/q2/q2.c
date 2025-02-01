//  Copyright 2023 NaturalZh (@NaturalZh)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

const aw20216s_led_t PROGMEM g_aw20216s_leds[AW20216S_LED_COUNT] = {
/* Each AW20216 channel is controlled by a register at some offset between 0x00
 * and 0xD7 inclusive.
 * See drivers/awinic/aw20216.h for the mapping between register offsets and
 * driver pin locations.
 *   driver
 *   |  R location
 *   |  |          G location
 *   |  |          |          B location
 *   |  |          |          | */
    {0, SW1_CS1,   SW1_CS2,   SW1_CS3},  //ESC
    {0, SW3_CS1,   SW3_CS2,   SW3_CS3},  //F1
    {0, SW4_CS1,   SW4_CS2,   SW4_CS3},
    {0, SW5_CS1,   SW5_CS2,   SW5_CS3},  //F3
    {0, SW6_CS1,   SW6_CS2,   SW6_CS3},
    {0, SW7_CS1,   SW7_CS2,   SW7_CS3},  //F5
    {0, SW8_CS1,   SW8_CS2,   SW8_CS3},
    {0, SW9_CS1,   SW9_CS2,   SW9_CS3},  //F7
    {0, SW10_CS1,  SW10_CS2,  SW10_CS3},
    {0, SW11_CS1,  SW11_CS2,  SW11_CS3},  //F9
    {0, SW12_CS1,  SW12_CS2,  SW12_CS3},  //F10
    {0, SW2_CS10,  SW2_CS11,  SW2_CS12},
    {0, SW3_CS10,  SW3_CS11,  SW3_CS12},  //F12
    //encoder no led

    {0, SW1_CS4,   SW1_CS5,   SW1_CS6},   //`~
    {0, SW2_CS4,   SW2_CS5,   SW2_CS6},   //1
    {0, SW3_CS4,   SW3_CS5,   SW3_CS6},   //2
    {0, SW4_CS4,   SW4_CS5,   SW4_CS6},
    {0, SW5_CS4,   SW5_CS5,   SW5_CS6},   //4
    {0, SW6_CS4,   SW6_CS5,   SW6_CS6},
    {0, SW7_CS4,   SW7_CS5,   SW7_CS6},   //6
    {0, SW8_CS4,   SW8_CS5,   SW8_CS6},
    {0, SW9_CS4,   SW9_CS5,   SW9_CS6},   //8
    {0, SW10_CS4,  SW10_CS5,  SW10_CS6},
    {0, SW11_CS4,  SW11_CS5,  SW11_CS6},  //0
    {0, SW12_CS4,  SW12_CS5,  SW12_CS6},  //-_
    {0, SW2_CS13,  SW2_CS14,  SW2_CS15},  //=+
    {0, SW3_CS13,  SW3_CS14,  SW3_CS15},  //BS
    {0, SW4_CS13,  SW4_CS14,  SW4_CS15},  //Home

    {0, SW1_CS7,   SW1_CS8,   SW1_CS9},   //Tab
    {0, SW2_CS7,   SW2_CS8,   SW2_CS9},   //Q
    {0, SW3_CS7,   SW3_CS8,   SW3_CS9},   //W
    {0, SW4_CS7,   SW4_CS8,   SW4_CS9},   //E
    {0, SW5_CS7,   SW5_CS8,   SW5_CS9},   //R
    {0, SW6_CS7,   SW6_CS8,   SW6_CS9},   //T
    {0, SW7_CS7,   SW7_CS8,   SW7_CS9},   //Y
    {0, SW8_CS7,   SW8_CS8,   SW8_CS9},   //U
    {0, SW9_CS7,   SW9_CS8,   SW9_CS9},   //I
    {0, SW10_CS7,  SW10_CS8,  SW10_CS9},   //O
    {0, SW11_CS7,  SW11_CS8,  SW11_CS9},   //P
    {0, SW12_CS7,  SW12_CS8,  SW12_CS9},   //[
    {0, SW2_CS16,  SW2_CS17,  SW2_CS18},   //]
    {0, SW3_CS16,  SW3_CS17,  SW3_CS18},   //|
    {0, SW4_CS16,  SW4_CS17,  SW4_CS18},   //DEL

    {1, SW1_CS1,   SW1_CS2,   SW1_CS3},   //Cap
    {1, SW2_CS1,   SW2_CS2,   SW2_CS3},   //A
    {1, SW3_CS1,   SW3_CS2,   SW3_CS3},   //S
    {1, SW4_CS1,   SW4_CS2,   SW4_CS3},   //D
    {1, SW5_CS1,   SW5_CS2,   SW5_CS3},   //F
    {1, SW6_CS1,   SW6_CS2,   SW6_CS3},   //G
    {1, SW7_CS1,   SW7_CS2,   SW7_CS3},   //H
    {1, SW8_CS1,   SW8_CS2,   SW8_CS3},   //J
    {1, SW9_CS1,   SW9_CS2,   SW9_CS3},   //K
    {1, SW10_CS1,  SW10_CS2,  SW10_CS3},   //L
    {1, SW11_CS1,  SW11_CS2,  SW11_CS3},   //;
    {1, SW12_CS1,  SW12_CS2,  SW12_CS3},   //.
    {1, SW3_CS10,  SW3_CS11,  SW3_CS12},   //Ent
    {1, SW4_CS10,  SW4_CS11,  SW4_CS12},   //PgUp

    {1, SW1_CS4,   SW1_CS5,   SW1_CS6},   //Shift
    {1, SW2_CS4,   SW2_CS5,   SW2_CS6},   //Z
    {1, SW3_CS4,   SW3_CS5,   SW3_CS6},   //X
    {1, SW4_CS4,   SW4_CS5,   SW4_CS6},   //C
    {1, SW5_CS4,   SW5_CS5,   SW5_CS6},   //V
    {1, SW6_CS4,   SW6_CS5,   SW6_CS6},   //B
    {1, SW7_CS4,   SW7_CS5,   SW7_CS6},   //N
    {1, SW8_CS4,   SW8_CS5,   SW8_CS6},   //M
    {1, SW9_CS4,   SW9_CS5,   SW9_CS6},   //,
    {1, SW10_CS4,  SW10_CS5,  SW10_CS6},   //.
    {1, SW11_CS4,  SW11_CS5,  SW11_CS6},   //?
    {1, SW2_CS13,  SW2_CS14,  SW2_CS15},   //Shift
    {1, SW3_CS13,  SW3_CS14,  SW3_CS15},   //Up

    {1, SW1_CS7,   SW1_CS8,   SW1_CS9},   //Ctrl
    {1, SW2_CS7,   SW2_CS8,   SW2_CS9},   //Com
    {1, SW3_CS7,   SW3_CS8,   SW3_CS9},   //Alt
    {1, SW5_CS7,   SW5_CS8,   SW5_CS9},   //SPAC1
    {1, SW6_CS7,   SW6_CS8,   SW6_CS9},   //SPAC
    {1, SW8_CS7,   SW8_CS8,   SW8_CS9},   //SPAC2
    {1, SW10_CS7,  SW10_CS8,  SW10_CS9},   //Alt
    {1, SW11_CS7,  SW11_CS8,  SW11_CS9},   //Fn
    {1, SW12_CS7,  SW12_CS8,  SW12_CS9},   //Menu
    {1, SW2_CS16,  SW2_CS17,  SW2_CS18},   //Left
    {1, SW3_CS16,  SW3_CS17,  SW3_CS18},   //Down
    {1, SW4_CS16,  SW4_CS17,  SW4_CS18},   //Right
};

void suspend_power_down_kb() {
    gpio_write_pin_low(AW20216S_EN_PIN);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb() {
    gpio_write_pin_high(AW20216S_EN_PIN);
    suspend_wakeup_init_user();
}
void board_init(void) {
    // JTAG-DP Disabled and SW-DP Disabled
    AFIO->MAPR = (AFIO->MAPR & ~AFIO_MAPR_SWJ_CFG_Msk) | AFIO_MAPR_SWJ_CFG_DISABLE;
}

#if defined(RGB_MATRIX_ENABLE)  /*&& defined(CAPS_LOCK_INDEX)*/
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX, 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX, 0, 0, 0);
        }
    }
    return true;
};
#endif
