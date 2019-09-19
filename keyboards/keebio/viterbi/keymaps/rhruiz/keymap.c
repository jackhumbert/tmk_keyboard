#include QMK_KEYBOARD_H

#include "rhruiz.h"

#define KC__FN1 MO(_FN1)
#define KC__FN2 MO(_FN2)
#define KC__CFG MO(_CFG)
#define KC_RST RESET
#define KC__VUP KC__VOLUP
#define KC__VDN KC__VOLDOWN

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_ortho_5x14(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,   KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_LBRC,   KC_RBRC, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_QUOT,
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_PGUP,   KC_BSLS, KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_PGDN,   KC_ENT,  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    KC__FN1, KC_LCTL, KC_LALT, KC_LGUI, KC__FN1, KC_SPC , KC_SPC ,   KC_BSPC, KC__FN2, KC_RGUI, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),

  [_VIM_EMACS] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, KC_UP  , _______,
    _______, _______, _______, _______, KC_RGHT, _______, _______,   _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, KC_LEFT, _______,   _______, KC_DOWN, KC_ENT , _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_WH_U,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_WH_D,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______
  ),

  [_KEY_OVERRIDE] = LAYOUT_ortho_5x14(
    KC_TILD, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, KC_PIPE,
    _______, _______, _______, _______, _______, _______, KC_LCBR,   KC_RCBR, _______, _______, _______, _______, _______, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_PGUP,   KC_PIPE, _______, _______, _______, _______, KC_SCLN, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_PGDN,   KC_PENT, _______, _______, KC_LT  , KC_GT  , KC_QUES, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN1] = LAYOUT_ortho_5x14(
	_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, KC__CFG, _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT_ortho_5x14(
    _______, KC_SLCK, KC_PAUS, MISCTRL, _______, RGB_VAD, RGB_VAI,   KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC__VDN, KC__VUP, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    KC__CFG, _______, _______, _______, KC__CFG, _______, _______,   _______, _______, _______, _______, _______, _______, _______
  ),

  [_CFG] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, KC_RST ,
    _______, KC__VUP, KC__VDN, KC_MUTE, KC_EJCT, _______, _______,   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______
  )
};

// clang-format on

uint32_t layer_state_set_user(uint32_t state) { return rhruiz_layer_state_set_user(state); }
