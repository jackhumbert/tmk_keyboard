#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
    _QWERTY,
    _FN
};

enum custom_keycodes {
    EPRM = SAFE_RANGE,
};

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------.   ,-------------------------------------------------------------------------------------------------.
 * |  F1  |   | Esc`~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |Home |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |  F2  |   | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | End |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |  F3  |   | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter      | Ins |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |  F4  |   | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |    RShift   |  U  | Del |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |  F5  |   | Ctrl |  Gui  |  Alt  |              Space                |   FN    |   RCtrl   |  L  | D  |  R  |
 * `------'   `-------------------------------------------------------------------------------------------------'
 */

[_QWERTY] = LAYOUT_ansi(
KC_F1, KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,
KC_F2, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
KC_F3, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      KC_ENT,      KC_HOME,
KC_F4, KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
KC_F5, KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPC,                          MO(_FN), KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
),

/* FN
 * ,------.   ,-------------------------------------------------------------------------------------------------.
 * |Reset |   |  F1   | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | PScr |  ScrLck  |Pause|
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |      |   |        |     |     |     |     |     |     |     |     |     |     |     |     |          |     |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |      |   |         |Prev |Play |Next |     |     |     |     |VolD |Mute |VolU |     |               |PgUp |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |      |   |           |     |     |     |     |     |     |     |     |     |     |             |     |PgDn |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |EPRM  |   |      |       |       |                                   |         |           |     |    |     |
 * `------'   `-------------------------------------------------------------------------------------------------'
 */

[_FN] = LAYOUT_ansi(
RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,          KC_PGUP,
_______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN,
EPRM,    _______, _______, _______,                        _______,                       _______, _______,          _______, _______, _______
),
};

void caps_lock_indicator(void) {
    // Turn LEDs On/Off for Caps Lock
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_disable_noeeprom();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EPRM:
            if (record->event.pressed) {
                // Reset to defaults
                eeconfig_init();
            }
            return true;
            break;
        case KC_CAPS:
            if (record->event.pressed) {
                caps_lock_indicator();
            }
            return true;
            break;
    }
    return true;
}

void matrix_scan_user(void) {
     // Set the LEDs to not-too-bright white
    rgblight_sethsv(0, 0, 80);
    caps_lock_indicator();
}
