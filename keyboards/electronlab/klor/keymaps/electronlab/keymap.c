/*
Copyright 2024 ElectronLab

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.



                                        █         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
                                        █        █     █          ▄▀            ▀▄      █          █
                                        █       █      █        ▄▀                ▀▄    █          █
                                        █      █       █        █                  █    █          █
                                        █     █        █       █                    █   █          █
                                        █    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
                                        █   █ █        █       █                    █   █      █
                                        █  █   █       █        █                  █    █       █
                                        █ █     █      █        ▀▄                ▄▀    █        █
                                        ██       █     █          ▀▄            ▄▀      █         █
                                        █         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █

                                        ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
                                        D E F A U L T

*/
#include QMK_KEYBOARD_H


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘ 

enum klor_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    OS_SWAP,
    MAKE_H,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_R MT(MOD_LALT, KC_R)
#define CTL_S MT(MOD_LCTL, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define SHT_N MT(MOD_RSFT, KC_N)
#define CTL_E MT(MOD_LCTL, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define GUI_O MT(MOD_LGUI, KC_O)


// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   s o u n d s                                 │
// └───────────────────────────────────────────────────────────┘

#ifdef AUDIO_ENABLE
  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
  #define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)
 
  float winxp_song[][2] = SONG(WINXP_SOUND);
  float mac_song[][2] = SONG(MAC_SOUND);
#endif // AUDIO_ENABLE

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ q w e r t y                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    E    │    R    │    T    │                    │    Y    │    U    │    I    │    O    │    P    │   
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   TAB   │    A    │    S    │    D    │    F    │    G    │                    │    H    │    J    │    K    │    L    │    ;    │    '    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   CTRL  │    Z    │    X    │    C    │    V    │    B    ││  MUTE  ││PLY/PSE ││    N    │    M    │    ,    │    .    │    /    │    \    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  LALT   │  LOWER  │  RALT   │  SPACE  ││  BSPCE  │  ENTER  │  RAISE  │    DEL  │  
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */ 

   [_QWERTY] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_Q,    KC_W,      KC_E,       KC_R,    KC_T,                          KC_Y,    KC_U,      KC_I,     KC_O,    KC_P,
      KC_TAB,  KC_A,    KC_S,      KC_D,       KC_F,    KC_G,                          KC_H,    KC_J,      KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
      KC_LCTL, KC_Z,    KC_X,      KC_C,       KC_V,    KC_B,     KC_MUTE,   KC_MPLY,  KC_N,    KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,  KC_BSLS,
                                   KC_LALT,    LOWER,   KC_RALT,  KC_SPC,    KC_BSPC,  KC_ENT,  RAISE,     KC_DEL
 ),

/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌───────────────────────────────────────────────────────────┐
   │ l o w e r                                                 │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │   F1    │   F2    │   F3    │   F4    │   F5    │                    │   F6    │   F7    │   F8    │   F9    │   F10   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    -    │    !    │    @    │    #    │    $    │    %    │                    │    ^    │    &    │    `    │    ~    │    =    │    +    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │    _    │    1    │    2    │    3    │    4    │    5    ││  MUTE  ││PLY/PASE││    6    │    7    │    8    │    9    │    0    │    *    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │  LSHIFT ││  RSHIFT │         │         │         │  
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */ 

   [_LOWER] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,                         KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
      KC_MINS,  KC_EXLM, KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                       KC_CIRC,  KC_AMPR,  KC_GRV,   KC_TILD,  KC_EQL,   KC_PLUS,
      KC_UNDS,  KC_1,    KC_2,     KC_3,     KC_4,     KC_5,    KC_MUTE,   KC_MPLY,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_ASTR,
                                   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_LSFT,   KC_RSFT,   KC_TRNS,  KC_TRNS,  KC_TRNS
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌───────────────────────────────────────────────────────────┐
   │ r a i s e                                                 │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │ RGB_SPI │ RGB_HUI │ HF_NEXT │  CK_UP  │    {    │                    │    }    │   LEFT  │   UP    │  RIGHT  │   HOME  │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │ RGB_VAI │ RGB_MOD │ RGB_M_B │ HF_TOGG │ CK_TOGG │    [    │                    │    ]    │         │  DOWN   │         │  PSCRN  │  P UP   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │ RGB_VAD │ RGB_SPD │ RGB_HUD │ HF_PREV │ CK_DOWN │    (    ││  MUTE  ││PLY/PASE││    )    │         │         │         │   END   │ P DOWN  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │  LSHIFT ││  RSHIFT │         │         │         │  
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */ 

   [_RAISE] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               RGB_SPI,  RGB_HUI,  HF_NEXT,  CK_UP,    KC_LCBR,                       KC_RCBR,  KC_LEFT,  KC_UP,    KC_RGHT,  KC_HOME,
     RGB_VAI,  RGB_MOD,  RGB_M_B,  HF_TOGG,  CK_TOGG,  KC_LBRC,                       KC_RBRC,  XXXXXXX,  KC_DOWN,  XXXXXXX,  KC_PSCR,  KC_PGUP,
     RGB_VAD,  RGB_SPD,  RGB_HUD,  HF_PREV,  CK_DOWN,  KC_LPRN,  KC_MUTE,   KC_MPLY,  KC_RPRN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_END,   KC_PGDN,
                                   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LSFT,   KC_RSFT, XXXXXXX,  XXXXXXX, XXXXXXX
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌───────────────────────────────────────────────────────────┐
   │ a d j u s t                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │ AUDIO   │ HAPTIC  │ RGB HUE │ RGB MOD │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │   F7    │   F8    │   F9    │   F14   │   
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │  RESET  │ DEBUG   │ QWERTY  │ RGB SAT │         │         ├─╯                ╰─┤         │   F4    │   F5    │   F6    │   F12   │   F13   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │  MAKE   │ OS SWAP │         │ RGB VAL │         │         ││  MUTE  ││PLY/PSE ││         │   F1    │   F2    │   F3    │   F10   │   F11   │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │         ││         │         │         │         │  
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */ 

   [_ADJUST] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              AU_TOGG,   HF_TOGG,  RGB_HUI,  RGB_MOD,  XXXXXXX,                       XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F14,   
    QK_BOOT,  DB_TOGG,   QWERTY,   RGB_SAI,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F12,   KC_F13,
    MAKE_H,   OS_SWAP,   XXXXXXX,  RGB_VAI,  XXXXXXX,  XXXXXXX,  KC_MUTE,   KC_MPLY,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F10,   KC_F11,
                                   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌───────────────────────────────────────────────────────────┐
   │ t e m p l a t e   p o l y d a c t y l                     │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │   
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ├─╯                ╰─┤         │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││        ││        ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │         ││         │         │         │         │  
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ 

   [_TEMPLATE] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
 )

   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌───────────────────────────────────────────────────────────┐
   │ t e m p l a t e   k o n r a d                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │   
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ├─╯                ╰─┤         │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││        ││        ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤╰────────╯╰────────╯├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │                    │         │         │         │  
                                 └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ 

   [_TEMPLATE] = LAYOUT_konrad(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,                       _______,  _______,  _______
 )

   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌─────────────────────────────────────────────────┐
   │ t e m p l a t e   y u b i t s u m e             │
   └─────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │   
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         ├─╯                ╰─┤         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         ││        ││        ││         │         │         │         │         │
   └─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┘
                       │         │         │         │         ││         │         │         │         │  
                       └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ 

   [_TEMPLATE] = LAYOUT_yubitsume(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
 )


   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌─────────────────────────────────────────────────┐
   │ t e m p l a t e   s a e g e w e r k             │
   └─────────────────────────────────────────────────┘
   ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
   │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │   
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         ├─╯                ╰─┤         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         ││        ││        ││         │         │         │         │         │
   └─────────┴─────────┼─────────┼─────────┼─────────┤╰────────╯╰────────╯├─────────┼─────────┼─────────┼─────────┴─────────┘
                       │         │         │         │                    │         │         │         │  
                       └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ 

   [_TEMPLATE] = LAYOUT_saegewerk(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,                       _______,  _______,  _______
 )

 */
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef OLED_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ d y n a m i c   m a c r o                                 │
// └───────────────────────────────────────────────────────────┘

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0; 

#ifdef DYNAMIC_MACRO_ENABLE
    char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
    static uint16_t dmacro_timer;
    const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
    const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
    const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};


    // DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
    bool dynamic_macro_record_start_user(int8_t direction) {
          dmacro_num = 1;
        return false;
    }

    // DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
    bool dynamic_macro_record_end_user(int8_t direction) {
          dmacro_num = 2;
          dmacro_timer = timer_read();
        return false;
    }

    // DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
    bool dynamic_macro_play_user(int8_t direction) {
          dmacro_num = 3;
          dmacro_timer = timer_read();
        return false;
    }
#endif //DYNAMIC_MACRO_ENABLE


void matrix_scan_user(void) {
  #ifdef DYNAMIC_MACRO_ENABLE
    // DynMacroTimer
    if(dmacro_num > 0){
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy ( o_text, dmacro_text[dmacro_num] );
          }    
        else {
            if (dmacro_num == 1) {
                strcpy ( o_text, dmacro_text[1] );
              }
            else {
                strcpy ( o_text, layer_state_str );
                dmacro_num = 0;
              }
          }
      }
   #endif //DYNAMIC_MACRO_ENABLE
}


// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0xE1, 0};  
    static const char PROGMEM face_2[] = {0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xE1, 0};
    static const char PROGMEM face_3[] = {0xE1, 0xE1, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xE1, 0};
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef AUDIO_ENABLE  
      static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
      static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
    #endif
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
      static const char PROGMEM hap_di[] = {0xCF, 0xD0, 0};
    #endif

// os mode status ────────────────────────────────────────┐

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false); // ──── MAC
    } else {
        oled_write_P(os_w_1, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false); // ──── MAC
    } else {
        oled_write_P(os_w_2, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_P(sep_h1, false);
    oled_write_P(face_3, false);

    
// lock key layer status ─────────────────────────────────┐

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

// hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

    #ifndef AUDIO_ENABLE 
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE 
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE // ────────────────── AUDIO
        if (is_audio_on()) { 
            oled_write_P(aud_en, false); 
        } else {
            oled_write_P(aud_di, false);
        }
    #endif // AUDIO ENABLE

     #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
//        oled_write_P(hap_en, false);
        if (haptic_get_enable()) { 
            oled_write_P(hap_en, false);
        } else {
            oled_write_P(hap_di, false);
        }

     #endif // HAPTIC ENABLE
}


// layer status ──────────────────────────────────────────┐

int layerstate = 0;

layer_state_t layer_state_set_kb(layer_state_t state) {
      switch (get_highest_layer(layer_state | default_layer_state)) {
            case 0:
                strcpy ( layer_state_str, "BASE QWERTY");
                break;
            case 1:
                strcpy ( layer_state_str, "LOWER");
                break;
            case 2:
                strcpy ( layer_state_str, "RAISE");
                break;
            case 3:
                strcpy ( layer_state_str, "ADJUST");
                break;
            default:
                strcpy ( layer_state_str, "XXXXXX");
        }
      if (dmacro_num < 1) {
          strcpy ( o_text, layer_state_str );
    }
  //return state;
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE

        // layer status ──────────────────────────────────────────────────┐
        #ifdef DYNAMIC_MACRO_ENABLE
            if(dmacro_num == 1){ oled_write_P(rec_ico, false); }
            if(dmacro_num == 2){ oled_write_P(stop_ico, false); }
            if(dmacro_num == 3){ oled_write_P(play_ico, false); }
        #endif //DYNAMIC_MACRO_ENABLE

        oled_write_ln(o_text, false);
        render_os_lock_status();

    } else {  // ─────────────────────────────────────────── SECONDARY SIDE

        // KLOR face ─────────────────────────────────────────────────────┐

        static const char PROGMEM klor_face[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0x60, 0x30, 0x18, 0x88, 0xf0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x30, 0x0c, 0xc6, 
0xe3, 0xfa, 0xdc, 0x80, 0x40, 0x40, 0x40, 0x20, 0x20, 0xa0, 0xa0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x20, 
0x18, 0x8c, 0xc3, 0xf1, 0xf8, 0xfe, 0xff, 0xff, 0xf7, 0xf2, 0xf2, 0xfb, 0xf9, 0xf9, 0xfd, 0xfc, 
0xfc, 0xff, 0x7f, 0x06, 0x00, 0x00, 0x20, 0x70, 0x88, 0x86, 0xc3, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 
0xff, 0x7f, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 
0x0e, 0x07, 0x07, 0x07, 0x07, 0x87, 0xe3, 0x9b, 0xef, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x83, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x40, 0x40, 0x20, 0x38, 
0xfc, 0x73, 0x7c, 0xbf, 0x3f, 0x3f, 0x3f, 0xbf, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfa, 0xfa, 0xf3, 
0xe3, 0xe3, 0xc3, 0xc1, 0x81, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x18, 0x0c, 0x04, 0x06, 0x06, 0x06, 0x86, 0xc6, 0x3c, 0x1c, 0x8e, 0xc3, 
0xf1, 0xf8, 0xfe, 0x97, 0x90, 0x98, 0xc8, 0xcf, 0xcf, 0xe7, 0xe4, 0xe4, 0xf8, 0x78, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 
0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 
0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x12, 0x21, 0x70, 0x3c, 0x3e, 0x3f, 0x3f, 
0x3f, 0x1f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
0x04, 0x09, 0x19, 0x13, 0xb3, 0xa7, 0xcf, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xdf, 0xbf, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 
0xf0, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x1f, 0x11, 0x19, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 
0x08, 0x08, 0x05, 0x00, 0x0f, 0x1f, 0x33, 0x27, 0x47, 0xcf, 0x9f, 0x9f, 0x3f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x1f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x2c, 0x24, 0x26, 0x27, 0x27, 0x27, 0x27, 0x27, 
0x27, 0x27, 0x27, 0x23, 0x23, 0x33, 0x13, 0x13, 0x1f, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 
0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(klor_face, sizeof(klor_face));
    }
    return false;
}
#endif // OLED_ENABLE



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHT_T:
            return TAPPING_TERM - 150; 
        case SHT_N:
            return TAPPING_TERM - 150;
        default:
            return TAPPING_TERM;
    }
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP: 
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE        
                }
//              #ifdef HAPTIC_ENABLE
//                drv2605l_pulse(52);
//              #endif // HAPTIC_ENABLE
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys    
            return false;
          }


// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
//                #ifdef HAPTIC_ENABLE
//                  drv2605l_pulse(64);
//                #endif // HAPTIC_ENABLE
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
//                #ifdef HAPTIC_ENABLE
//                  drv2605l_pulse(17);
//                #endif // HAPTIC_ENABLE
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
//                #ifdef HAPTIC_ENABLE
//                  drv2605l_pulse(17);
//                #endif // HAPTIC_ENABLE
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
//                #ifdef HAPTIC_ENABLE
//                  drv2605l_pulse(17);
//                #endif // HAPTIC_ENABLE
            } else {
                layer_off(_ADJUST);
            }
            return false;

// ┌───────────────────────────────────────────────────────────┐
// │ q m k                                                     │
// └───────────────────────────────────────────────────────────┘

        case MAKE_H:
          if (record->event.pressed) {
            #ifdef KEYBOARD_klor_kb2040
              SEND_STRING ("qmk compile -kb klor/2040 -km default");
            #else 
              SEND_STRING ("qmk compile -kb klor -km default");
            #endif
            tap_code(KC_ENTER); 
          } 
          break;

// ┌───────────────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                                   │
// └───────────────────────────────────────────────────────────┘

      case KC_MPLY:
        if (record->event.pressed) {
//          #ifdef HAPTIC_ENABLE
//                  drv2605l_pulse(4);
//          #endif // HAPTIC_ENABLE
        }
        break;
    }
    return true;
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_WBAK, KC_WFWD) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif


// ┌───────────────────────────────────────────────────────────┐
// │ c o m b o keys                                            │
// └───────────────────────────────────────────────────────────┘

#ifdef COMBO_ENABLE

enum combos {
  QW_ESC,
  WE_CLOSETAB,
  ER_LASTTAB,
  RT_PRTSCR,
  WR_TERMINAL,
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};

combo_t key_combos[] = {
  [QW_ESC] = COMBO(qw_combo, KC_ESC),
  [WE_CLOSETAB] = COMBO(we_combo, LCTL(KC_F4)),
  [ER_LASTTAB] = COMBO(er_combo, LCTL(LSFT(KC_T))),
  [RT_PRTSCR] = COMBO(rt_combo, KC_PSCR),
  [WR_TERMINAL] = COMBO(wr_combo, LCTL(LALT(KC_T))),
};

#endif // COMBO_ENABLE
/*

                                                       ▐█    ▟▛ ▐█     ▄▆▀▀▀▀▀▀▆▄  ▐█▀▀▀▀▀█▌
                                                       ▐█   ▟▛  ▐█    ▟▛        ▜▙ ▐█     █▌
                                                       ▐█  ▟▛   ▐█   ▐█          █▋▐█     █▌
                                                       ▐█ ▟█▙   ▐█   ▐█          █▋▐█▀▀▜█▀▀▘
                                                       ▐█▟▛ ▜▙  ▐█    ▜▙        ▟▛ ▐█   ▜▙
                                                       ▐█▛   ▜▙ ▐█▄▄▄▄ ▀▜▆▄▄▄▄▆▛▀  ▐█    ▜▙

                                                                 ▄██████████████▄
                                                                 ████████████████
                                                            ▄██████▀  ▀████▀  ▀██████▄
                                                            ███████▄  ▄████▄  ▄███████
                                                            ███████████▀▀▀▀███████████
                                                            ▀█████████▀ ▄▄ ▀█████████▀
                                                                 ████▀ ▄██▄ ▀████
                                                                 ████▄▄████▄▄████

*/



