#include QMK_KEYBOARD_H

// Fillers to make layering more clear
#define XXXXXX KC_TRNS
#define ______ KC_NO

// ISO keycodes with Swedish layout names
#define SE_PLUS KC_MINS         // +
#define SE_TCK KC_EQL           // Fronttick (´)
#define SE_DASH KC_SLSH         // -
#define SE_UML KC_RBRC          // Umlaut (¨)
#define SE_QUT KC_NUHS          // Singlequote (')
#define SE_AUML KC_QUOT     	// Ä
#define SE_ARNG KC_LBRC     	// Å
#define SE_OUML KC_SCLN     	// Ö
#define SE_LT KC_NUBS       	// <

// My common shortcuts
#define MY_PREV KC_MRWD         // Media: Previous
#define MY_NEXT KC_MFFD         // Media: Next
#define MY_PLAY KC_MPLY         // Media: Play/Pause
#define MY_VOLU KC__VOLUP       // Media: Volume Up
#define MY_VOLD KC__VOLDOWN     // Media: Volume Down
#define MY_MUTE KC__MUTE        // Media: Mute
#define MY_SLEP G(A(KC_POWER))  // Mac: Sleep
#define MY_LOCK C(A(KC_L))      // Mac: Lock


/*
TADA68 ISO physical layout
1u == 8chars
,----------------------------------------------------------------------------------------------------------------------------------------------.
|        |        |        |        |        |        |        |        |        |        |        |        |        |      2u        |        |
|----------------------------------------------------------------------------------------------------------------------------------------------|
|    1,5u    |        |        |        |        |        |        |        |        |        |        |        |        |     1,5u   |        |
|--------------------------------------------------------------------------------------------------------------------------|          |--------|
|     1,75u    |        |        |        |        |        |        |        |        |        |        |        |        |   1,25u  |        |
|----------------------------------------------------------------------------------------------------------------------------------------------|
|   1,25u  |        |        |        |        |        |        |        |        |        |        |        |     1,75u    |        |        |
|----------------------------------------------------------------------------------------------------------------------------------------------|
|   1,25u  |   1,25u  |   1,25u  |                                                       |        |        |        |        |        |        |
`----------------------------------------------------------------------------------------------------------------------------------------------'
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_iso(
//  ,----------------------------------------------------------------------------------------------------------------------------------------------.
//  |  Esc   |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |    +   |    ´   |   Backspace    |  Home  |
     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, SE_TCK,     KC_BSPC,      KC_HOME,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |    Tab     |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    P   |    Å   |    ¨   |            |  End   |
     LT(2,KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG, SE_UML,              KC_END,
//  |--------------------------------------------------------------------------------------------------------------------------|          |--------|
//  |    LCtrl     |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |   Ö    |   Ä    |   '    |   Enter  |  PgUp  |
        KC_LCTL,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   SE_OUML, SE_AUML, SE_QUT,    KC_ENT,  KC_PGUP,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |  LShift  |   <>   |    Z   |   X    |   C    |    V   |    B   |    N   |    M   |   ,    |   .    |   -    |   RShift     |   Up   |  PgDn  |
      KC_LSFT,   SE_LT,  KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  SE_DASH,    KC_RSFT,     KC_UP,  KC_PGDN,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |  LCtrl   |   LAlt   | Command  |                        Space                          |Command |  RAlt  |  Fn    |  Left  |  Down  | Right  |
      KC_LCTL,   KC_LALT,   KC_LGUI,                         KC_SPC,                          KC_LGUI, KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
//  `----------------------------------------------------------------------------------------------------------------------------------------------'
	),

	[1] = LAYOUT_iso(
//  ,----------------------------------------------------------------------------------------------------------------------------------------------.
//  |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |     Delete     |  Ins   |
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      KC_DEL,      KC_INS,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |            |        |   Up   |        |        |        |        |        |        |        |        |        |        |            |  Mute  |
        ______,    ______,  KC_UP,   ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,              KC__MUTE,
//  |--------------------------------------------------------------------------------------------------------------------------|   Lock   |--------|
//  |  Caps Lock   |  Left  |  Down  | Right  | BLight |        |        |        |        |        |        |        |        |  Screen  | VolUp  |
        KC_CAPS,    KC_LEFT, KC_DOWN, KC_RGHT, BL_BRTG, ______,   ______,  ______,  ______,  ______,  ______,  ______,  ______,  MY_LOCK,  MY_VOLU,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |          |        |        |        |  Bl-   |BLtoggle | Bl+   |        |        |        |        |        |              |  Stop  | VolDn  |
       ______,   ______,  ______,  ______, BL_DEC,  BL_TOGG, BL_INC,   ______,  ______,  ______,  ______,  ______,    ______,    KC_MSTP,  MY_VOLD,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |          |          |          |                        Sleep                          |        |        |        |  Prev  |  Play  |  Fwd   |
      ______,    ______,    ______,                          MY_SLEP,                           ______,  ______,  XXXXXX, MY_PREV, MY_PLAY, MY_NEXT
//  `----------------------------------------------------------------------------------------------------------------------------------------------'
	),

	[2] = LAYOUT_iso(
//  ,----------------------------------------------------------------------------------------------------------------------------------------------.
//  |   Esc  |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |     Delete     |        |
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      KC_DEL,     ______,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |            |        |   Up   |        |        |        |        |        |        |        |        |        |        |            |  Mute  |
        XXXXXX,      ______, KC_UP,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,              KC__MUTE,
//  |--------------------------------------------------------------------------------------------------------------------------|          |--------|
//  |              |  Left  |  Down  | Right  |        |        |  Left  |  Down  |   Up   | Right  |        |        |        |          | VolUp  |
        ______,     KC_LEFT, KC_DOWN, KC_RGHT,  ______,  ______, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  ______,  ______,  ______,   ______,  MY_VOLU,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |          |        |        |        |        |        |        |        |        |        |        |        |              | Stop   | VolDn  |
       ______,   ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,    ______,    KC_MSTP,  MY_VOLD,
//  |----------------------------------------------------------------------------------------------------------------------------------------------|
//  |          |          |          |                                                       |        |        |        |  Prev  |  Play  |  Fwd   |
      ______,    ______,    ______,                          ______,                           ______,  ______,  ______, MY_PREV, MY_PLAY, MY_NEXT
//  `----------------------------------------------------------------------------------------------------------------------------------------------'
	)
};
