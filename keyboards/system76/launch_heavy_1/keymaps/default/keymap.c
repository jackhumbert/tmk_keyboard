#include QMK_KEYBOARD_H

enum layers{
  First,
  Second,
  Third,
  Fourth
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer 0, default layer
__________________________________________________________________________________________________________________________________  ________  ___________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |            ||        || PRINT  | MEDIA  | PLAY/  | MEDIA  |
|  ESC   |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |  DELETE    ||  HOME  || SCREEN |PREVIOUS| PAUSE  | NEXT   |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________||________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |            ||        || NUM    | NUM    | NUM    | NUM    |
|  ~`    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  _ -   | =  +   | BACKSPACE  ||  PGUP  || LOCK   | SLASH  |  *     |  -     |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________||________|________|________|________|
|            |        |        |        |        |        |        |        |        |        |        |  [     |   ]    |        ||        || NUM    | NUM    | NUM    |        |
|     TAB    |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |  {     |   }    |  |   \ ||  PGDN  ||  7     |  8     |  9     |        |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|________||________||________|________|________| NUM    |
  |            |        |        |        |        |        |        |        |        |        |   ;    |   '    |            |   |        || NUM    | NUM    | NUM    |  +     |
  |    CAPS    |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   :    |   "    |   ENTER    |   |  END   ||  4     |  5     |  6     |        |
  |____________|________|________|________|________|________|________|________|________|________|________|________|____________|___|________||________|________|________|________|
  |                |        |        |        |        |        |        |        |   ,    |    .   |   /    |            |        |         | NUM    | NUM    | NUM    |        |
  |     SHIFT      |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   <    |    >   |   ?    |   SHIFT    |   UP   |         |  1     |  2     |  3     |        |
  |________________|________|________|________|________|________|________|________|________|________|________|____________|________|________ |________|________|________| NUM    |
  |            |        |       |        |                 |                 |        |        |             |   |        |        |        ||       NUM       | NUM    | ENTER  |
  |    CTRL    |  LALT  | FN    | LGUI   |    SPACE        |      SPACE      | RCTRL  |  RALT  |     FN      |   |  LEFT  |  DOWN  | RIGHT  ||        0        |  .     |        |
  |____________|________|_______|________|_________________|_________________|________|________|_____________|   |________|________|________||_________________|________|________|
*/

  [First] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,       KC_HOME,  KC_PSCR, KC_MPRV, KC_MPLY, KC_MNXT,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_PGUP,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
          KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,       KC_END,   KC_P4,   KC_P5,   KC_P6,
          KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,    KC_UP,           KC_P1,   KC_P2,   KC_P3,   KC_PENT,
          KC_LCTL, KC_LALT, MO(1),   KC_LGUI,     KC_SPC,           KC_SPC,     KC_RCTL,   KC_RALT,   MO(1),         KC_LEFT, KC_DOWN, KC_RGHT,        KC_P0,      KC_PDOT
  ),

   /* Layer 1, function layer
__________________________________________________________________________________________________________________________________  ________  ___________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |            || PLAY/  ||        |        |        |        |
| QK_BOOT|        |        |        |        |        |        |        |        |        |        |        |        |            || PAUSE  ||        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________||________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |  LED   |  LED   |  LED   |            || VOLUME ||        |        |        |        |
|        |        |        |        |        |        |        |        |        |        | TOGGLE |  DOWN  |  UP    |            ||   UP   ||        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|____________||________||________|________|________|________|
|            |        |        |        |        |        |        |        |        |        |        |        |        |        || VOLUME ||        |        |        |        |
|PRINT SCREEN|        |        |        |        |        |  HOME  |  PGDN  |  PGUP  |  END   |        |        |        |        ||  DOWN  ||        |        |        |        |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|________||________||________|________|________|        |
  |            |        |        |        |        |        |        |        |        |        |        |        |            |   |        ||        |        |        |        |
  |            |        |        |        |        |        |  LEFT  |  DOWN  |  UP    | RIGHT  |        |        |            |   |  MUTE  ||        |        |        |        |
  |____________|________|________|________|________|________|________|________|________|________|________|________|____________|___|________||________|________|________|________|
  |                |        |        |        |        |        |        |        |        |        |        |            |        |         |        |        |        |        |
  |                |        |        |        |        |        |        |        |        |        |        |            |  PGUP  |         |        |        |        |        |
  |________________|________|________|________|________|________|________|________|________|________|________|____________|________|________ |________|________|________|        |
  |            |        |       |        |                 |                 |        |        |             |   |        |        |        ||                 |        |        |
  |            |        |       |        |                 |                 |        |        |             |   |  HOME  |  PGDN  |  END   ||                 |        |        |
  |____________|________|_______|________|_________________|_________________|________|________|_____________|   |________|________|________||_________________|________|________|
  * 'QK_BOOT' resets the controller and puts the board into firmware flashing mode. If this key is hit accidentally, just unplug the board
  *        and plug it back in.
  */

  [Second] = LAYOUT(
    QK_BOOT,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_MPLY,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_VAD, RGB_VAI, KC_TRNS,      KC_VOLU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_VOLD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_MUTE,  KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_PGUP,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,        KC_HOME, KC_PGDN, KC_END,         KC_TRNS,    KC_TRNS
  ),

  [Third] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,    KC_TRNS
  ),

  [Fourth] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,    KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
