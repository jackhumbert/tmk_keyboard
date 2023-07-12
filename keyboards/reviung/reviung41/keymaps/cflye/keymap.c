/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cflye.h"
#include "features/achordion.h"

#define LAYOUT_reviung41_wrapper(...) LAYOUT(__VA_ARGS__)

#define LAYOUT_reviung41_base(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
) \
LAYOUT_reviung41_wrapper(\
   KC_DEL,  K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, KC_BSPC, \
   KC_LSFT, K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, KC_RSFT, \
   KC_LCTL, K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, KC_RCTL, \
                          K33, K34, KC_SPC, K36, K37 \
)

#define LAYOUT_base_wrapper(...) LAYOUT_reviung41_base(__VA_ARGS__)

#undef  _________________THUMB_LEFT________________
#define _________________THUMB_LEFT________________     KC_NO,            KC_NO,              KC_NO,               LT(_MEDIA,KC_TAB),   LT(_NAV,KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        _________________COLEMAK_L1_________________, _________________COLEMAK_R1_________________,
        _________________COLEMAK_L2_________________, _________________COLEMAK_R2_________________,
        _________________COLEMAK_L3_________________, _________________COLEMAK_R3_________________,
        _________________THUMB_LEFT________________,  _________________THUMB_RIGHT_______________
    ),
    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1__________________, _________________QWERTY_R1__________________,
        _________________QWERTY_L2__________________, _________________QWERTY_R2__________________,
        _________________QWERTY_L3__________________, _________________QWERTY_R3__________________,
        _________________THUMB_LEFT________________,  _________________THUMB_RIGHT_______________
    ),
    [_SYM] = LAYOUT_base_wrapper(
        ___________________SYM_L1___________________, ___________________SYM_R1___________________,
        ___________________SYM_L2___________________, ___________________SYM_R2___________________,
        ___________________SYM_L3___________________, ___________________SYM_R3___________________,
        ___________________BLANK___________________,  ___________________BLANK___________________
    ),
    [_NUM] = LAYOUT_base_wrapper(
        ___________________NUM_L1___________________, ___________________NUM_R1___________________,
        ___________________NUM_L2___________________, ___________________NUM_R2___________________,
        ___________________NUM_L3___________________, ___________________NUM_R3___________________,
        ___________________NUM_L4___________________,  ___________________BLANK___________________
    ),
    [_NAV] = LAYOUT_base_wrapper(
        ___________________NAV_L1___________________, ___________________NAV_R1___________________,
        ___________________NAV_L2___________________, ___________________NAV_R2___________________,
        ___________________NAV_L3___________________, ___________________NAV_R3___________________,
        ___________________NAV_L4___________________, ___________________NAV_R4___________________
    ),
    [_MEDIA] = LAYOUT_base_wrapper(
        __________________MEDIA_L1__________________, __________________MEDIA_R1__________________,
        __________________MEDIA_L2__________________, __________________MEDIA_R2__________________,
        __________________MEDIA_L3__________________, __________________MEDIA_R3__________________,
        __________________MEDIA_L4__________________, __________________MEDIA_R4__________________
    ),
    [_FUN] = LAYOUT_base_wrapper(
        ___________________FUN_L1___________________, ___________________FUN_R1___________________,
        ___________________FUN_L2___________________, ___________________FUN_R2___________________,
        ___________________FUN_L3___________________, ___________________FUN_R3___________________,
        ___________________FUN_L4___________________, ___________________FUN_R4___________________
    ),
    [_MOUSE] = LAYOUT_base_wrapper(
        __________________MOUSE_L1__________________, __________________MOUSE_R1__________________,
        __________________MOUSE_L2__________________, __________________MOUSE_R2__________________,
        __________________MOUSE_L3__________________, __________________MOUSE_R3__________________,
        __________________MOUSE_L4__________________, __________________MOUSE_R4__________________
    ),
};

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  uprintf("achordion_chord: kc: 0x%04X, col: %2u, row: %2u, kc: 0x%04X, col: %2u, row: %2u, res %2u\n", other_keycode, other_record->event.key.col, other_record->event.key.row, tap_hold_keycode, tap_hold_record->event.key.col, tap_hold_record->event.key.row, tap_hold_record->event.key.row % (MATRIX_ROWS / 2) >= 4);

  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Dvorak.
  switch (tap_hold_keycode) {
    case HOME_S:  // S + D and S + W.
      if (other_keycode == KC_D || other_keycode == KC_W || other_keycode == KC_P) { return true; }
      break;
  }
  
  // Thumb keys
  if (other_record->event.key.row == 6 || tap_hold_record->event.key.row == 6 ) { return true; }
  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM, _MEDIA, _MOUSE);
    state = update_tri_layer_state(state, _NAV, _SYM, _FUN);
    return state;
}
