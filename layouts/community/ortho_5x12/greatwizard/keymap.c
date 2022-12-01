/* Copyright 2020 Guillaume Gérard
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
#include "greatwizard.h"

#define LAYOUT_ortho_5x12_wrapper(...)            LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_base( \
        K00,     K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A, \
                 K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A, \
                 K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     K2B, \
        K30,     K31,     K32,     K33,     K34,     K35,     K36,     K37,     K38,     K39,     K3A  \
    ) \
    LAYOUT_ortho_5x12_wrapper( \
        K00,     K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A,     KC_BSPC, \
        KC_TAB,  K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A,     KC_DEL, \
        KC_ESC,  K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     K2B, \
        K30,     K31,     K32,     K33,     K34,     K35,     K36,     K37,     K38,     K39,     K3A,     KC_ENT, \
        FN,      KC_LCTL, TD_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
    )
#define LAYOUT_ortho_5x12_base_wrapper(...)       LAYOUT_ortho_5x12_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x12_base_wrapper(
        KC_GRV,  _______________NUMBER_LEFT_________________, _______________NUMBER_RIGHT________________,
                 _______________QWERTY_LEFT1________________, _______________QWERTY_RIGHT1_______________,
                 _______________QWERTY_LEFT2________________, _______________QWERTY_RIGHT2_______________, KC_QUOT,
        TD_LSCP, _______________QWERTY_LEFT3________________, _______________QWERTY_RIGHT3_______________
    ),

    /* Qwerty Programmer
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY_PROGRAMMER] = LAYOUT_ortho_5x12_base_wrapper(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                 _______________QWERTY_LEFT1________________, _______________QWERTY_RIGHT1_______________,
                 _______________QWERTY_LEFT2________________, _______________QWERTY_RIGHT2_______________, KC_QUOT,
        PG_LSCP, _______________QWERTY_LEFT3________________, _______________QWERTY_RIGHT3_______________
    ),

    /* Workman
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_WORKMAN] = LAYOUT_ortho_5x12_base_wrapper(
        KC_GRV,  _______________NUMBER_LEFT_________________, _______________NUMBER_RIGHT________________,
                 _______________WORKMAN_LEFT1_______________, _______________WORKMAN_RIGHT1______________,
                 _______________WORKMAN_LEFT2_______________, _______________WORKMAN_RIGHT2______________, KC_QUOT,
        TD_LSCP, _______________WORKMAN_LEFT3_______________, _______________WORKMAN_RIGHT3______________
    ),

    /* Workman Programmer
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_WORKMAN_PROGRAMMER] = LAYOUT_ortho_5x12_base_wrapper(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                 _______________WORKMAN_LEFT1_______________, _______________WORKMAN_RIGHT1______________,
                 _______________WORKMAN_LEFT2_______________, _______________WORKMAN_RIGHT2______________, KC_QUOT,
        PG_LSCP, _______________WORKMAN_LEFT3_______________, _______________WORKMAN_RIGHT3______________
    ),

    /* Colemak
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_ortho_5x12_base_wrapper(
        KC_GRV,  _______________NUMBER_LEFT_________________, _______________NUMBER_RIGHT________________,
                 _______________COLEMAK_LEFT1_______________, _______________COLEMAK_RIGHT1______________,
                 _______________COLEMAK_LEFT2_______________, _______________COLEMAK_RIGHT2______________, KC_QUOT,
        TD_LSCP, _______________COLEMAK_LEFT3_______________, _______________COLEMAK_RIGHT3______________
    ),

    /* Colemak Programmer
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_PROGRAMMER] = LAYOUT_ortho_5x12_base_wrapper(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                 _______________COLEMAK_LEFT1_______________, _______________COLEMAK_RIGHT1______________,
                 _______________COLEMAK_LEFT2_______________, _______________COLEMAK_RIGHT2______________, KC_QUOT,
        PG_LSCP, _______________COLEMAK_LEFT3_______________, _______________COLEMAK_RIGHT3______________
    ),

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_ortho_5x12_base_wrapper(
        KC_GRV,  _______________NUMBER_LEFT_________________, _______________NUMBER_RIGHT________________,
                 _______________DVORAK_LEFT1________________, _______________DVORAK_RIGHT1_______________,
                 _______________DVORAK_LEFT2________________, _______________DVORAK_RIGHT2_______________, KC_SLSH,
        TD_LSCP, _______________DVORAK_LEFT3________________, _______________DVORAK_RIGHT3_______________
    ),

    /* Dvorak Programmer
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK_PROGRAMMER] = LAYOUT_ortho_5x12_base_wrapper(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                 _______________DVORAK_LEFT1________________, _______________DVORAK_RIGHT1_______________,
                 _______________DVORAK_LEFT2________________, _______________DVORAK_RIGHT2_______________, KC_SLSH,
        PG_LSCP, _______________DVORAK_LEFT3________________, _______________DVORAK_RIGHT3_______________
    ),

    /* X Programmer Shifted
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_PROGRAMMER_SHIFTED] = LAYOUT_ortho_5x12_wrapper(
        PG_GRV,  PG_1,    PG_2,    PG_3,    PG_4,    PG_5,    PG_6,    PG_7,    PG_8,    PG_9,    PG_0,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Game
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise |   /  | Left | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_GAME] = LAYOUT_ortho_5x12_wrapper(
        KC_GRV,  _______________NUMBER_LEFT_________________, _______________NUMBER_RIGHT________________, KC_BSPC,
        KC_TAB,  _______________QWERTY_LEFT1________________, _______________QWERTY_RIGHT1_______________, KC_DEL,
        KC_ESC,  _______________QWERTY_LEFT2________________, _______________QWERTY_RIGHT2_______________, KC_QUOT,
        TD_LSCP, _______________QWERTY_LEFT3________________, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
        FN,      KC_LCTL, TD_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_5x12_wrapper(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |PageUp|PageDn|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_5x12_wrapper(
        KC_GRV,  _______________NUMBER_LEFT_________________, _______________NUMBER_RIGHT________________, _______,
        KC_GRV,  _______________NUMBER_LEFT_________________, _______________NUMBER_RIGHT________________, _______,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Reset|EP_RST|      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |CPSLCK|      |      |      |      |      | Game |Qwerty|Workmn|Colemk|Dvorak|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |QwertP|WrkmnP|ColmkP|DvorkP|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_5x12_wrapper(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, QK_BOOT, EE_CLR,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, GAME,    QWERTY,  WORKMAN, COLEMAK, DVORAK,  _______,
        _______, _______, _______, _______, _______, _______, _______, QWERTYP, WORKMNP, COLEMKP, DVORAKP, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Fn (rgblight and backlight layout)
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |RGBVA-|RGBVA+|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |RGBSA-|RGBSA+|RGBLYR|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |RGBTOG|RGBHU-|RGBHU+|RGBMOD|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |BLTOGG|  BL- |  BL+ |BLBRTG|
     * `-----------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x12_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, RGB_LYR,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUD, RGB_HUI, RGB_MOD,
        _______, _______, _______, _______, _______, _______, _______, _______, BL_TOGG, BL_DOWN, BL_UP,   BL_BRTG
    ),

   /* GIT
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |CHRPCK| SHOW |REBASE|QK_BOOT | TAG  |      | PULL | INIT |REMOTE| PUSH |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | ADD  |STATUS| DIFF |FETCH | GREP |STASH |      |CHECKT| LOG  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |COMMIT|  MV  |BRANCH|      |MERGE |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_GIT] = LAYOUT_ortho_5x12_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _________________GIT_LEFT1_________________, _________________GIT_RIGHT1________________, _______,
        _______, _________________GIT_LEFT2_________________, _________________GIT_RIGHT2________________, _______,
        _______, _________________GIT_LEFT3_________________, _________________GIT_RIGHT3________________, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
