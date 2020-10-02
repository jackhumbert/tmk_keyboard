#include "cwebster2.h"

userspace_config_t userspace_config;

__attribute__((weak)) void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
    static bool has_ran_yet;
    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }

    matrix_scan_keymap();
}

void keyboard_post_init_rgb(void) {
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_STARTUP_ANIMATION)
    /*if (userspace_config.rgb_layer_change) { rgblight_enable_noeeprom(); }*/
    /*if (rgblight_config.enable) {*/
        /*layer_state_set_user(layer_state);*/
        /*uint16_t old_hue = rgblight_config.hue;*/
        uint16_t old_hue = 170;
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        for (uint16_t i = 255; i > 0; i--) {
            rgblight_sethsv_noeeprom( ( i + old_hue) % 255, 255, 255);
            matrix_scan();
            wait_ms(10);
        }
    /*}*/
#endif
    /*layer_state_set_user(layer_state);*/
}

__attribute__((weak)) void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) {
    userspace_config.raw              = 0;
    userspace_config.rgb_layer_change = true;
    eeconfig_update_user(userspace_config.raw);
    eeconfig_init_keymap();
    keyboard_init();
}

bool hasAllBitsInMask(uint8_t value, uint8_t mask) {
    value &= 0xF;
    mask &= 0xF;

    return (value & mask) == mask;
}
