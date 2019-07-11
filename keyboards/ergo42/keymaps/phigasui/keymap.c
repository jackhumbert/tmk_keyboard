#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Check keycodes references at https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |      |   |      |  Y   |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | RCtrl|   A  |   S  |   D  |   F  |   G  |      |   |      |  H   |   J  |   K  |   L  |   -  | Enter|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LSft |   Z  |   X  |   C  |   V  |   B  |      |   |      |  N   |   M  |   ,  |   .  |   /  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | META |      |      | LAlt | LGUI | SYMB | Space|   | Space| SYMB | RGUI | RAlt |      |      | META |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_TAB,   KC_Q,     KC_W,   KC_E,    KC_R,     KC_T,    XXXXXXX,    XXXXXXX, KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_BSPC, \
    KC_LCTL,  KC_A,     KC_S,   KC_D,    KC_F,     KC_G,    KC_ESC,     KC_ESC,  KC_H,    KC_J,     KC_K,    KC_L,   KC_MINS, KC_ENT,  \
    KC_LSFT,  KC_Z,     KC_X,   KC_C,    KC_V,     KC_B,    KC_ESC,     KC_ESC,  KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
    MO(META), MO(GAME), KC_SPC, KC_RALT, MO(SYMB), KC_LGUI, KC_SPC,     KC_SPC,  KC_RGUI, MO(SYMB), KC_RALT, KC_SPC, KC_SPC,  MO(META) \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |      |   |      |   6  |   7  |   8  |   9  |      |      |
   * |------+------+------+------+------+------+------|   |------+-------------+------+------+------+------|
   * |      |      |      |      |  F11 |  F12 |      |   |      | Left |   4  |   5  |   6  |      |      |
   * |------+------+------+------+------+------+------|   |------+------|------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |   |      |  F6  |   1  |   2  |   3  | F10  |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |   0  |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,    _______, KC_UP,   KC_7, KC_8, KC_9,   KC_MINS, _______, \
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______,    _______, KC_DOWN, KC_4, KC_5, KC_6,   KC_PLUS, _______, \
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,    _______, KC_LEFT, KC_1, KC_2, KC_3,   KC_SLSH, _______, \
    _______, _______, _______, _______, _______, _______, _______,    _______, KC_RGHT, KC_0, KC_0, KC_DOT, KC_ASTR, _______  \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |      |   |      |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |   ;  |   `  |   '  |      |      |   |      |      |   \  |   =  |   [  |   ]  |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |   :  |   ~  |   "  |      |      |   |      |      |   |  |   +  |   {  |   }  |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, _______, KC_GRV,  KC_SCLN, KC_QUOT, _______, _______,     _______, _______, KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
    _______, _______, KC_TILD, KC_COLN, KC_DQT,  _______, _______,     _______, _______, KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______  \
  )
};
