// Copyright 2023 xia0 (@xia0)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_mouse(KC_BTN1, KC_BTN3, KC_BTN4, KC_BTN2)
};
