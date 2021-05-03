#include QMK_KEYBOARD_H

enum planck_layers {
    _DVORAK,
    _NUMBERS,
    _SYMBOLS,
    _ACTIONS,
    _SPECIAL
  };

enum planck_keycodes {
    DVORAK,
    NUMBERS,
    SYMBOLS,
    ACTIONS,
    SPECIAL
};

enum tap_dance_codes {
    CT_SC_LP = 0,
    CT_Q_LBRC,
    CT_J_LBRK,
    CT_W_RBRK,
    CT_V_RBRC,
    CT_Z_RP,
    CT_DEL_ESC
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [0] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_LPRN),
    [1] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_LCBR),
    [2] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_LBRC),
    [3] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_RBRC),
    [4] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_RCBR),
    [5] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_RPRN)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Dvorak
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |  '"  |  ,<  |  .>  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  BS  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /?  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |LShift| ;:/( |  Q/{ |  J/[ |   K  |   X  |   B  |   M  |  W/] |  V/} |  Z/) |RS/Ent|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Action| Ctrl |  GUI | Alt  |Number| Space/Enter |Symbol| Left | Down |  Up  | Right|
    * `-----------------------------------------------------------------------------------'
    */
    [_DVORAK] = LAYOUT_planck_grid(
        KC_TAB,        KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,   KC_Y,      KC_F,        KC_G,   KC_C,    KC_R,    KC_L,  KC_BSPACE,
        KC_ESC,        KC_A,       KC_O,       KC_E,       KC_U,   KC_I,      KC_D,        KC_H,   KC_T,    KC_N,    KC_S,  KC_SLASH,
        KC_LSFT,       TD(0),      TD(1),      TD(2),      KC_K,   KC_X,      KC_B,        KC_M,   TD(3),   TD(4),   TD(5), MT(MOD_RSFT, KC_ENT),
        MO(ACTIONS),   KC_LCTRL,   KC_LGUI,    KC_LALT,    NUMBERS,    KC_SPACE, KC_SPACE,         SYMBOLS,KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),

    /* Numbers
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   7  |   8  |   9  |   *  |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   4  |   5  |   6  |   -  |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |   0  |   1  |   2  |   3  |   +  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_NUMBERS] = LAYOUT_planck_grid(
        _______,   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_7,       KC_8,       KC_9,       KC_KP_ASTERISK, _______,
        _______,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_4,       KC_5,       KC_6,       KC_KP_MINUS,    _______,
        _______,   _______,    _______,    _______,    _______,    _______,    KC_0,       KC_1,       KC_2,       KC_3,       KC_KP_PLUS,     _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______
    ),

    /* Symbols
    * ,-----------------------------------------------------------------------------------.
    * | `~   |  !   |  @   |  #   |   $  |   %  |   ^  |   &  |   *  |      |      | Del  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Caps |      |  Ins | Pgup |      |      |      |   _  |   +  |      |      |  \|  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      | Home |  End | Pgdn |      |      |      |   -  |   =  |      |      |        |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_SYMBOLS] = LAYOUT_planck_grid(
        KC_GRV,    KC_EXCLAIM, KC_AT,      KC_HASH,    KC_DOLLAR,  KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    _______,    KC_DEL,
        KC_CAPS,   _______,    KC_INS,     KC_PGUP,    _______,    _______,    _______,    KC_UNDS,    KC_PLUS,    _______,    _______,    KC_BSLS,
        _______,   KC_HOME,    KC_END,     KC_PGDN,    _______,    _______,    _______,    KC_MINUS,   KC_EQL,     _______,    _______,    _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    /* Actions
    * ,-----------------------------------------------------------------------------------.
    * |  LED |      |      |      |      | Sleep|Reset |      |      |      |      | Del  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      | Redo |      |      |      |      |      | Play |  <<  |  >>  |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      | Undo | Cut  | Copy | Paste|      |      | Mute | Vol- | Vol+ |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ACTIONS] = LAYOUT_planck_grid(
        BL_STEP,   _______,    _______,    _______,    _______,    KC_SLEP,    RESET,      _______,    _______,    _______,    _______,    KC_DEL,
        _______,   LCTL(KC_Y),     _______,    _______,    _______,    _______,    _______,    KC_MPLY,    KC_MPRV,    KC_MNXT,    _______,    _______,
        _______,   LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     _______,    _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    /* Special
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_SPECIAL] = LAYOUT_planck_grid(
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case DVORAK:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_DVORAK);
        }
        return false;
        break;
      case SYMBOLS:
        if (record->event.pressed) {
          layer_on(_SYMBOLS);
          update_tri_layer(_NUMBERS, _SYMBOLS, _SPECIAL);
        } else {
          layer_off(_SYMBOLS);
          update_tri_layer(_NUMBERS, _SYMBOLS, _SPECIAL);
        }
        return false;
        break;
      case NUMBERS:
        if (record->event.pressed) {
          layer_on(_NUMBERS);
          update_tri_layer(_NUMBERS, _SYMBOLS, _SPECIAL);
        } else {
          layer_off(_NUMBERS);
          update_tri_layer(_NUMBERS, _SYMBOLS, _SPECIAL);
        }
        return false;
        break;
    }
    return true;
}
