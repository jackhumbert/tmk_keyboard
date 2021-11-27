/* Copyright 2021 Christoph Rehmann (crehmann)
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
#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _NAVR,
    _SYMR,
    _NUMR,
    _FUNL,
    _SYML,
    _ADJL
};


// Aliases for readability
#define BASE     DF(_BASE)
#define NAVR     MO(_NAVR)
#define SYMR     MO(_SYMR)
#define NUMR     MO(_NUMR)
#define FUNL     MO(_FUNL)
#define SYML     MO(_SYML)
#define ADJL     MO(_ADJL)

// Left-hand home row mods
#define RALT_X  RALT_T(KC_X)
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define CTL_D   LCTL_T(KC_D)
#define SFT_F   LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J   RSFT_T(KC_J)
#define CTL_K   RCTL_T(KC_K)
#define ALT_L   LALT_T(KC_L)
#define GUI_SCL RGUI_T(KC_SCLN)
#define RALT_DT RALT_T(KC_DOT)

// Left-hand outer column
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define SFT_TAB  MT(MOD_LSFT, KC_TAB)

// Thumbcluster
#define UC_TL1 NAVR
#define UC_TL2 LT(SYMR, KC_SPC)
#define UC_TL3 LT(NUMR, KC_TAB)

#define UC_TR3 KC_BTN1
#define UC_TR2 LT(SYML, KC_ENT)
#define UC_TR1 LT(FUNL, KC_DEL)

// Shortcuts
#define UC_COPY LCTL(KC_C)
#define UC_PSTE LCTL(KC_V)
#define UC_CUT  LCTL(KC_X)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// /*
//  * Base Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   Q  |   W  |   E  |   R  |   T  |                                               |   Y  |   U  |   I  |   O  |   P  |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |  TAB |   A  |   S  |   D  |   F  |   G  |                                               |   H  |   J  |   K  |   L  |  ; : | Bksp |
//  *          |  SFT |  GUI | LALT | LCTL | LSFT |      |                                               |      | LSFT | LCTL |  ALT |  GUI |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |  ESC |   Z  |   X  |   C  |   F  |   B  |                                               |   N  |   M  |  , < |  . > |  / ? |RShift|
//  *          |  CTL |      | RALT |      |      |      |                                               |      |      |      | RALT |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space| TAB  |                   |  BTN1| Enter| DEL  |
//  *                                             | NAVR | SYMR | NUMR |                   |  FUNL| SYML |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_BASE] = LAYOUT(
               KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
      SFT_TAB, GUI_A  , ALT_S  , CTL_D  , SFT_F  , KC_G   ,                                        KC_H   , SFT_J  , CTL_K  , ALT_L  , GUI_SCL, KC_BSPC,
      CTL_ESC, KC_Z   , RALT_X , KC_C   , KC_V   , KC_B   ,                                        KC_N   , KC_M   , KC_COMM, RALT_DT, KC_SLSH, KC_RSFT,
                                                   UC_TL1 , UC_TL2 , UC_TL3 ,    UC_TR3 , UC_TR2 , UC_TR1
    ),

// /*
//  * Navigation Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |Insert| Cut  | PgUp | PgDn |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               | Copy |   ←  |   ↑  |   ↓  |   →  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               | Paste| Home | WH_U | WH_D | End  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   |  BTN2| Enter| DEL  |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_NAVR] = LAYOUT(
               _______, _______, _______, _______, _______,                                        KC_INS , UC_CUT , KC_PGUP, KC_PGDN, _______,
      _______, _______, _______, _______, _______, _______,                                        UC_COPY, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______,                                        UC_PSTE, KC_HOME, KC_WH_U, KC_WH_D, KC_END , _______,
                                                   _______, _______, _______,    KC_BTN2, KC_BSPC, KC_ENT
    ),
// --------------------------------------------------------------------------------------------------------------------------------------------------------


// /*
//  * Symbol Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |      |   /  |   +  |   =  |   ?  |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               |   ^  |   &  |   *  |   (  |   )  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               |   }  |   ]  |   _  |   ,  |   .  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   |      | Enter|  DEL |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_SYMR] = LAYOUT(
               _______, _______, _______, _______, _______,                                        _______, KC_SLSH, KC_PLUS, KC_EQL , KC_QUES,
      _______, _______, _______, _______, _______, _______,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      _______, _______, _______, _______, _______, _______,                                        KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT , _______,
                                                   _______, _______, _______,    _______, KC_ENT , KC_BSPC 
    ),

// /*
//  * Number Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |   /  |   7  |   8  |   9  |  -   |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               |   *  |   4  |   5  |  6   |  +   |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               |   0  |   1  |   2  |  3   |  .   |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   |      | Enter|  DEL |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_NUMR] = LAYOUT(
               _______, _______, _______, _______, _______,                                        KC_SLSH, KC_7   , KC_8   , KC_9   , KC_MINS,
      _______, _______, _______, _______, _______, _______,                                        KC_ASTR, KC_4   , KC_5   , KC_6   , KC_PLUS, _______,
      _______, _______, _______, _______, _______, _______,                                        KC_0   , KC_1   , KC_2   , KC_3   , KC_DOT , _______,
                                                   _______, _______, _______,    _______, KC_ENT , KC_BSPC 
    ),

// /*
//  * Function Layer (Left)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |  F12 |  F7  |  F8  |  F9  | Pause|                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |  F11 |  F4  |  F5  |  F6  | PrScr|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |  F10 |  F1  |  F2  |  F3  | CapsL|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space|  TAB |                   |      |      |      |
//  *                                             |  ADJ |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_FUNL] = LAYOUT(
               KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS,                                        _______, _______, _______, _______, _______,
      _______, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR,                                        _______, _______, _______, _______, _______, _______,
      _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_CAPS,                                        _______, _______, _______, _______, _______, _______,
                                                   ADJL   , KC_SPC , KC_TAB  ,    _______, _______, _______
    ),

// /*
//  * Symbol Layer (Left)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   `  |   ~  |   |  |   \  |      |                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |   !  |   @  |   #  |   $  |   %  |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |   :  |   ;  |   -  |   [  |   {  |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space| TAB  |                   |      |      |      |
//  *                                             |  ADJ |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_SYML] = LAYOUT(
               KC_GRV , KC_TILD, KC_PIPE, KC_BSLS, _______,                                        _______, _______, _______, _______, _______,
      _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                        _______, _______, _______, _______, _______, _______,
      _______, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR,                                        _______, _______, _______, _______, _______, _______,
                                                   ADJL   , KC_SPC , KC_TAB  ,    _______, _______, _______
    ),

// /*
//  * Adjustment Layer (Left)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               |      |M Prev| VolDn| VolUp|M Next|      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               |      | Play | Mute |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space| TAB  |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_ADJL] = LAYOUT(
               _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                        _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
      _______, _______, _______, _______, _______, _______,                                        _______, KC_MPLY, KC_MUTE, _______, _______, _______,
                                                   _______, KC_SPC , KC_TAB  ,    _______, _______, _______
    ),

// -------------------------------------------------------- TEMPLATE -------------------------------------------------------------------------------------
// /*
//  * Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//                _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//                                                    _______, _______, _______,    _______, _______, _______
//     ),
// --------------------------------------------------------------------------------------------------------------------------------------------------------
};


#ifdef HAPTIC_ENABLE

bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BTN1 ... KC_BTN5:
            return true;
            break;
    }

    return false;
}
#endif