#include QMK_KEYBOARD_H
#include "csc027.h"

#define LAYOUT_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_wrapper(
        _____________________QWERTY_L1_____________________, _____________________QWERTY_R1_____________________,
        _____________________QWERTY_L2_____________________, _____________________QWERTY_R2_____________________,
        _____________________QWERTY_L3_____________________, _____________________QWERTY_R3_____________________,
        _____________________QWERTY_L4_____________________, _____________________QWERTY_R4_____________________
    ),

    [_RS] = LAYOUT_wrapper(
        ______________________RAISE_L1_____________________, ______________________RAISE_R1_____________________,
        ______________________RAISE_L2_____________________, ______________________RAISE_R2_____________________,
        ______________________RAISE_L3_____________________, ______________________RAISE_R3_____________________,
        ______________________RAISE_L4_____________________, ______________________RAISE_R4_____________________
    ),

    [_LW] = LAYOUT_wrapper(
        ______________________LOWER_L1_____________________, ______________________LOWER_R1_____________________,
        ______________________LOWER_L2_____________________, ______________________LOWER_R2_____________________,
        ______________________LOWER_L3_____________________, ______________________LOWER_R3_____________________,
        ______________________LOWER_L4_____________________, ______________________LOWER_R4_____________________
    ),

    [_MS] = LAYOUT_wrapper(
        ______________________MOUSE_L1_____________________, ______________________MOUSE_R1_____________________,
        ______________________MOUSE_L2_____________________, ______________________MOUSE_R2_____________________,
        ______________________MOUSE_L3_____________________, ______________________MOUSE_R3_____________________,
        ______________________MOUSE_L4_____________________, ______________________MOUSE_R4_____________________
    ),

    [_GT] = LAYOUT_wrapper(
        _______________________GIT_L1______________________, _______________________GIT_R1______________________,
        _______________________GIT_L2______________________, _______________________GIT_R2______________________,
        _______________________GIT_L3______________________, _______________________GIT_R3______________________,
        _______________________GIT_L4______________________, _______________________GIT_R4______________________
    ),

    [_CN] = LAYOUT_wrapper(
        ___________________CONVENIENCE_L1__________________, ___________________CONVENIENCE_R1__________________,
        ___________________CONVENIENCE_L2__________________, ___________________CONVENIENCE_R2__________________,
        ___________________CONVENIENCE_L3__________________, ___________________CONVENIENCE_R3__________________,
        ___________________CONVENIENCE_L4__________________, ___________________CONVENIENCE_R4__________________
    ),

    /* Guild Wars 2 Layer
     *
     * ,-----------------------------------------------------------------------.
     * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |BkSpc|
     * |-----------------------------------------------------------------------|
     * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  \  |
     * |-----------------------------------------------------------------------|
     * |Sf/Ec|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |Enter|
     * |-----------------------------------------------------------------------|
     * | Ctl |  Z  | Alt |  X  |  C  |Space|Space|  M  |  B  |  .  |Nxt L|Rst L|
     * `-----------------------------------------------------------------------'
     */

    [_GW] = LAYOUT_ortho_4x12(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        MC_LSEC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
        KC_LCTL, KC_Z,    KC_LALT, KC_X,    KC_C,    KC_SPC,  KC_SPC,  KC_M,    KC_B,    KC_DOT,  TO(_CS), TO(_QW)
    ),

    /* CS:GO Layer
     *
     * ,-----------------------------------------------------------------------.
     * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |BkSpc|
     * |-----------------------------------------------------------------------|
     * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  4  |  5  |  6  |     |NmLck|
     * |-----------------------------------------------------------------------|
     * |Shift|  A  |  S  |  D  |  F  |  G  |  H  |  1  |  2  |  3  |Enter| Esc |
     * |-----------------------------------------------------------------------|
     * | Ctl |  Z  | Alt |  X  |  B  |Space|Space|  0  |  0  |  .  |Nxt L|Rst L|
     * `-----------------------------------------------------------------------'
     */

    [_CS] = LAYOUT_ortho_4x12(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_P7,   KC_P8,   KC_P9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_P4,   KC_P5,   KC_P6,   XXXXXXX, KC_NLCK,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_ESC ,
        KC_LCTL, KC_Z,    KC_LALT, KC_X,    KC_B,    KC_SPC,  KC_SPC,  KC_P0,   KC_P0,   KC_PDOT, TO(_QW), TO(_QW)
    )
};
