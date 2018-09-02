#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif

enum mitosis_layers
  {
    _xQ, // qwerty
    _xW, // workman
    _xS, // symbols
    _xN, // numbers
    _xF  // functions
  };

enum mitosis_keycodes
  {
    KC_LAYO = SAFE_RANGE
  };

// Fillers to make layering more clear
#define _______ KC_TRNS // Transparent

// I don't use Japanese myself, but I've placed henkan 変換 and muhenkan 無変換
// in my layout to act as left and right HYPER

// Momentary tri-state layers. Mitosis default keymap does this too but employs
// new keymappings and a bunch of conditional code. This simpler keymap
// accomplishes it but with a small quirk: triggering both layers then releasing
// one out-of-order will leave the tri-state triggered until the other is
// released. Which doesn't bother me.

// The weird /*,*/ comments are a hack to get slightly better automatic
// tabulation in my editor.

// We use Space Cadet KC_RSPC to get _ on right shift. See config.h for details.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_xQ] = LAYOUT(
      KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
      KC_A,    KC_S,       KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,
      KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_QUOT,
      /*,      */ KC_LGUI, KC_LCTL, TT(_xS), KC_BSPC,        KC_SPC,  TT(_xS), KC_RCTL, KC_RGUI,
      /*,      */ KC_HENK, KC_LALT, TT(_xN), LSFT_T(KC_TAB), KC_RSPC, TT(_xN), KC_RALT, KC_MHEN),
  [_xW] = LAYOUT(
      KC_Q,    KC_D,       KC_R,    KC_W,    KC_B,           KC_J,    KC_F,    KC_U,    KC_P,     KC_SCLN,
      KC_A,    KC_S,       KC_H,    KC_T,    KC_G,           KC_Y,    KC_N,    KC_E,    KC_O,     KC_I,
      KC_Z,    KC_X,       KC_M,    KC_C,    KC_V,           KC_K,    KC_L,    KC_COMM, KC_DOT,   KC_QUOT,
      /*,      */ _______, _______, _______, _______,        _______, _______, _______, _______,
      /*,      */ _______, _______, _______, _______,        _______, _______, _______, _______),
  [_xS] = LAYOUT(
      KC_ESC,  KC_GRV ,    KC_UP,   KC_EQL , KC_TILD,        KC_PLUS, KC_CIRC, KC_AMPR, KC_PERC,  KC_MINS,
      _______, KC_LEFT,    KC_DOWN, KC_RGHT, _______,        KC_PIPE, KC_AT,   KC_DLR,  KC_HASH,  KC_ENT,
      KC_BSLS, KC_LABK,    KC_LCBR, KC_LPRN, KC_LBRC,        KC_RBRC, KC_RPRN, KC_RCBR, KC_RABK,  KC_SLSH,
      /*,      */ _______, _______, _______, KC_DEL,         _______, _______, _______, _______,
      /*,      */ _______, _______, TT(_xF), _______,        _______, TT(_xF), _______, _______),
  [_xN] = LAYOUT(
      KC_PSCR, KC_F7,      KC_F8,   KC_F9,   KC_F10,         KC_PPLS, KC_7,    KC_8,    KC_9,     KC_PMNS,
      KC_SLCK, KC_F4,      KC_F5,   KC_F6,   KC_F11,         KC_NLCK, KC_4,    KC_5,    KC_6,     KC_PENT,
      KC_PAUS, KC_F1,      KC_F2,   KC_F3,   KC_F12,         KC_PAST, KC_1,    KC_2,    KC_3,     KC_PSLS,
      /*,      */ _______, _______, TT(_xF), _______,        _______, TT(_xF), KC_0,    KC_DOT,
      /*,      */ _______, _______, _______, _______,        _______, _______, _______, _______),
  [_xF] = LAYOUT(
      RESET,   KC_INS,     KC_PGUP, DEBUG,   KC_VOLU,        KC_PPLS, KC_P7,   KC_P8,   KC_P9,    KC_PMNS,
      CK_TOGG, KC_HOME,    KC_PGDN, KC_END,  KC_VOLD,        KC_NLCK, KC_P4,   KC_P5,   KC_P6,    KC_PENT,
      KC_LAYO, KC_MPRV,    KC_MPLY, KC_MNXT, KC_MUTE,        KC_PAST, KC_P1,   KC_P2,   KC_P3,    KC_PSLS,
      /*,      */ CK_UP,   MU_TOG,  _______, _______,        _______, _______, KC_P0,   KC_PDOT,
      /*,      */ CK_DOWN, MU_MOD,  _______, _______,        _______, _______, _______, _______),
};
const bool defaultlayers[] = {
  [_xQ] = true,
  [_xW] = true,
  [_xS] = false,
  [_xN] = false,
  [_xF] = false,
};
const size_t defaultlayers_n = sizeof(defaultlayers) / sizeof(defaultlayers[0]);

#ifdef AUDIO_ENABLE
void startup_user()
{
  float tone_startup[][2]        = SONG(STARTUP_SOUND);
  _delay_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}

void music_on_user(void)
{
  music_scale_user();
}

void music_scale_user(void)
{
  float music_scale[][2]         = SONG(MUSIC_SCALE_SOUND);
  PLAY_SONG(music_scale);
}

#endif


// New keycode KC_LAYO rotates between available default layers (for e.g.,
// selecting a base layout). Shift+KC_LAYO makes the current one persistent.
bool process_record_layout(uint16_t keycode, keyrecord_t *record) {
  uint32_t default_layer;
  uint8_t i;

  if (keycode != KC_LAYO || !record->event.pressed) {
    return true;
  }

  if (get_mods() & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))) { // shift pressed
    // save default layer. whatever the current default layer is, store that
    eeconfig_update_default_layer(default_layer_state);
  } else {
    // rotate default layer.
    // find the current default layer
    default_layer = biton32(default_layer_state);
    // find next valid default layer
    for (i = 1; i < defaultlayers_n; i++) {
      if (defaultlayers[(default_layer + i) % defaultlayers_n]) {
        break;
      }
    }
    if (i == defaultlayers_n) {
      // we fell out of the loop without finding another default layer to switch
      // to.
      return false;
    }
    default_layer = (default_layer + i) % defaultlayers_n;
    default_layer_set(1U<<default_layer);
    #if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
      PLAY_SONG(default_layer_songs[default_layer]);
    #endif
  }
  return false;
}

// This is a hack to place <question mark> on <shift-comma> and <exclamation
// mark> on <shift-period>, when using an operating system configured for a
// US/qwerty layout.
// cdeq = "comma dot exclamation question"
bool comm_shifted = false;
bool ques_shifted = false;
bool process_record_cdeq(uint16_t keycode, keyrecord_t *record) {
  uint8_t shifted;
  uint16_t s_keycode;
  bool *k_shifted;

  switch (keycode) {
  case KC_COMM:
    s_keycode = KC_SLSH;
    k_shifted = &comm_shifted;
    break;
  case KC_DOT:
    s_keycode = KC_1;
    k_shifted = &ques_shifted;
    break;
  default:
    return true;
  }

  shifted = get_mods() & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT));

  // Keydown. If shift is currently pressed, register its alternate keycode.
  if (record->event.pressed && shifted) {
    *k_shifted = true;
    register_code(s_keycode);
    return false;
    // Keyup. If shift was pressed back when the key was pressed, unregister
    // its alternate keycode.
  } else if (!(record->event.pressed) && *k_shifted) {
    *k_shifted = false;
    unregister_code(s_keycode);
    return false;
    // Otherwise, behave as normal.
  } else {
    return true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return \
    process_record_cdeq(keycode, record) && \
    process_record_layout(keycode, record);
}

// Set the bits of A selected by MASK to the corresponding bits of B
#define setbits(A, B, MASK) A = (A & (B | ~MASK)) | (B & MASK)
void matrix_scan_user(void) {
  //
  // Bit #            7     6     5     4     3     2     1     0
  // layer_state: [     |     |     | _xF | _xN | _xS | _xQ | _xW ]
  // usb_led      [     |     |     |kana |cmps |scrl |caps | num ]
  // PORTB:       [  NC |  10 |   9 |   8 |  14 |  16 |  15 |rxled]
  // PORTC:       [  NC |   5 |     |     |     |     |     |     ]
  // PORTD:       [   6 |  NC |txled|   4 | tx* | rx* | grn | p29 ]
  // PORTE:       [     |   7 |     |     |     |     |     |     ]
  // PORTF:       [  a0 |  a1 | red | blu |     |     |  NC |  NC ]
  //
  // PD0 is connected to the pairing switch and p29 on the wireless module.
  // PF0,PF1,PB7,PC7,PD6 are not broken out by the pro micro board. I don't understand why.
  // PB1-PB6,PD4,PD5,PD6,PF6,PF7 are not connected to the Mitosis receiver
  // board. Each may be connected to an LED by way of a resistor (4.7k to
  // match the others) for a total of 14 additional indicators.

  // A simple (but technically inaccurate) model of the momentary layer state:
  // Fn1 key makes _xS active; indicator = red
  // Fn2 key makes _xN active; indicator = blue
  // Both keys make _xF active; indicator = purple
  // Toggling QWERTY mode makes indicator include green, so (red/blue/purple becomes yellow/cyan/white)

  // negated because for ports 0=LED on.
  uint32_t portf_bits = ~(layer_state|layer_state<<1|(layer_state&0b100)<<3);
  setbits(PORTF, portf_bits, 0b00110000);
  setbits(PORTD, ~layer_state, 0b00000010);
}

// vim: set sw=2 et:
