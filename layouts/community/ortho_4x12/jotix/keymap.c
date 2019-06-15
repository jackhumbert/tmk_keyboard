#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)

static bool is_ctl_pressed;
static bool is_esc_pressed;
static bool is_bspc_pressed;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* qwerty
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |   esc  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    P   |  bspc  |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |   tab  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    ;   |    '   |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * | lshift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  enter |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |  lctrl |  lgui  |  lalt  |  ralt  |  lower |  space |  space |  raise |  right |  down  |   up   |  right | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 */
[_QWERTY] = LAYOUT_ortho_4x12 ( 
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* lower
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |        | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |  vol-  |  mute  |  vol+  |  caps  |  home  |  pgup  |    -   |   =    |    [   |    ]   |    \   | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |  prev  |  play  |  next  |   del  |   end  |  pgdn  |    `   |        |        |        |        | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |        |        |        |        |        |        |        |        |        |        |        | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 */
[_LOWER] = LAYOUT_ortho_4x12 (
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_VOLD, KC_MUTE, KC_VOLU, KC_CAPS, KC_HOME, KC_PGUP, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_DEL,  KC_END,  KC_PGDN, KC_GRV,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* raise
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |    !   |    @   |    #   |    $   |    %   |    ^   |    &   |    *   |    (   |    )   |        | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |    _   |    +   |    {   |    }   |    |   | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |   F7   |   F8   |   F9   |   F10  |   F11  |   F12  |    ~   |        |        |        |        | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |        |        |        |        |        |        |        |        |        |        |        | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 */
[_RAISE] = LAYOUT_ortho_4x12 (
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILD, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

uint32_t layer_state_set_user(uint32_t state) {
  #ifdef JOTANCK_LEDS
  switch (biton32(state)) { 
  case _LOWER:
    writePinHigh(JOTANCK_LED1);
    writePinLow(JOTANCK_LED2);
    break;
  case _RAISE:
    writePinLow(JOTANCK_LED1);
    writePinHigh(JOTANCK_LED2);
    break;
  default:
    writePinLow(JOTANCK_LED1);
    writePinLow(JOTANCK_LED2);
    break; 
  };
  #endif
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LCTL:
      is_ctl_pressed = record->event.pressed;
      break;
    case KC_ESC:
      is_esc_pressed = record->event.pressed;
      break;
    case KC_BSPC:
      is_bspc_pressed = record->event.pressed;
      break;
  };
  return true;
}

void matrix_scan_user(void) {
  if (is_ctl_pressed && is_esc_pressed && is_bspc_pressed) {
    reset_keyboard();
  }
}
