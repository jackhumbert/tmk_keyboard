//TO DO: 
//2.5 get working with ipad
//3 insert î UC(0xEE), ä UC(0xE4), ø UC(0xF8) keys somewhere?
//4 insert °, and math symbols/functions?



// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

//Tap Dance Declarations

enum {

  TD_DV,       //Dvorak layer tap, super hold
  TD_SFT_CAPS, //Capslock tap, shift hold
  TD_AL,       //Lower layer tap, alt hold
  TD_CR,       //Raise layer tap, ctrl hold
  TD_MA,       //Adjust layer tap, meh hold
  TD_QW,       //Qwerty layer tap, super hold
  TD_CO,       //Colemak layer tap, super hold

};



// Songlist
	//80's Voltron opening song
#define VOLTRON_CLASSIC_OPEN \
	Q__NOTE(_G5),  E__NOTE(_REST),  ED_NOTE(_B5),  S__NOTE(_REST),  \
	SD_NOTE(_C5),  QD_NOTE(_D5), E__NOTE(_REST),  \
	ED_NOTE(_C5),  S__NOTE(_REST),  ED_NOTE(_G5),  E__NOTE(_REST),  \
	WD_NOTE(_G5),  HD_NOTE(_REST),  Q__NOTE(_G5),  E__NOTE(_REST),  \
	ED_NOTE(_A5), S__NOTE(_REST), SD_NOTE(_B5),  \
	QD_NOTE(_C5),  E__NOTE(_REST),  ED_NOTE(_B5),  S__NOTE(_REST),  \
	ED_NOTE(_A5),  E__NOTE(_REST),  WD_NOTE(_G4),  \
	ED_NOTE(_F5),  ED_NOTE(_REST),  ED_NOTE(_FS5),  ED_NOTE(_REST),   WD_NOTE(_G5),

	//Voltron Legendary Defender Netflix opening song
#define VOLTRON_LD_OPEN  \
	QD_NOTE(_C4),  QD_NOTE(_G4), Q__NOTE(_F4),  \
	QD_NOTE(_AS4), QD_NOTE(_G4), Q__NOTE(_F4),  \
	H__NOTE(_G4),  H__NOTE(_B4), W__NOTE(_C5),

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  | Ctrl | Alt  | GUI  |Lower |Space | Enter|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,    KC_Q,      KC_W,      KC_E,      KC_R,            KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {CTL_T(KC_TAB), KC_A,      KC_S,      KC_D,      KC_F,            KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {TD(TD_QW), KC_Z,      KC_X,      KC_C,      KC_V,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP},
  {KC_LGUI,   TD(TD_MA), TD(TD_CR), TD(TD_AL), TD(TD_SFT_CAPS), KC_SPC,  KC_ENT,  KC_BSPC, KC_DEL,  KC_LEFT, KC_RGHT, KC_DOWN}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  | Ctrl | Alt  | GUI  |Lower |Space | Enter|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_ESC,    KC_Q,      KC_W,      KC_F,      KC_P,            KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC},
  {CTL_T(KC_TAB), KC_A,      KC_R,      KC_S,      KC_T,            KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {TD(TD_CO), KC_Z,      KC_X,      KC_C,      KC_V,            KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP},
  {KC_LGUI,   TD(TD_MA), TD(TD_CR), TD(TD_AL), TD(TD_SFT_CAPS), KC_SPC,  KC_ENT,  KC_BSPC, KC_DEL,  KC_LEFT, KC_RGHT, KC_DOWN}
},

/* Dvorak
 *      ,-----------------------------------------------------------------------------------.
 *      | Esc  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  /   |
 *      |------+------+------+------+------+-------------+------+------+------+------+------|
 *  Ctrl| Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 *      |------+------+------+------+------+------|------+------+------+------+------+------|
 *Dvorak|Super |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Up   |
 *      |------+------+------+------+------+------+------+------+------+------+------+------|
 *      | GUI  |Adjust|Raise |Lower |Caps  |Space | Enter| Bksp | Del  | Left | Down |Right |
 *      `-----------------------------------------------------------------------------------'
 *               Meh    Ctrl   Alt   Shift
 */
[_DVORAK] = {
  {KC_ESC,    KC_QUOT,    KC_COMM,   KC_DOT,    KC_P,            KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH},
  {CTL_T(KC_TAB), KC_A,       KC_O,      KC_E,      KC_U,            KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS},
  {TD(TD_DV), KC_SCLN,    KC_Q,      KC_J,      KC_K,            KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_UP},
  {KC_LGUI,   TD(TD_MA),  TD(TD_CR), TD(TD_AL), TD(TD_SFT_CAPS), KC_SPC,  KC_ENT,  KC_BSPC, KC_DEL,  KC_LEFT, KC_RGHT, KC_DOWN}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  ~   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   -  |   =  |   [  |   ]  |   _  |   +  |   {  |   }  |   `  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD},
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE},
  {_______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_GRV,  KC_BSLS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |PrtScr|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Home |Pg Up |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |SelAll| Cut  | Copy |Paste | Undo | Redo |      |      | End  |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, _______},
  {_______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, _______},
  {_______, LCTL(KC_A), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Z), LCTL(KC_Y), XXXXXXX, XXXXXXX, KC_END,  KC_PGDN, _______},
  {_______, _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Sleep | Reset|Qwerty|Colemk|Dvorak|      |      |  F1  |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      |      |  F5  |  F6  |  F7  |  F8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|  F9  |  F10 |  F11 |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_SLEP, RESET,   TD(TD_QW), TD(TD_CO), TD(TD_DV), XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______},
  {_______, XXXXXXX, XXXXXXX,   AU_ON,     AU_OFF,    XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______},
  {_______, MUV_DE,  MUV_IN,    MU_ON,     MU_OFF,    MI_ON,   MI_OFF,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______},
  {_______, _______, _______,   _______,   _______,   _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(VOLTRON_CLASSIC_OPEN);
//float tone_startup[][2]    = SONG(VOLTRON_LD_OPEN);
//float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_zelda[][2]      = SONG(ZELDA_PUZZLE);
float tone_oneup[][2]      = SONG(ONE_UP_SOUND);
float tone_coin[][2]       = SONG(COIN_SOUND);
float tone_caps[][2]       = SONG(CAPS_LOCK_OFF_SOUND);
float tone_voltld[][2]     = SONG(VOLTRON_LD_OPEN);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
		persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
	#ifdef BACKLIGHT_ENABLE
	    backlight_level(4); //start at maximum led brightness (behavior unknown for planck, setting at 3 for now)
	#endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif

//Tap Dance Definitions
typedef struct {
  bool alt;
  bool finished_once;
} td_dv_state_t;

typedef struct {
  bool alt;
  bool finished_once;
} td_sftcaps_state_t;

typedef struct {
  bool alt;
  bool finished_once;
} td_alb_state_t;

typedef struct {
  bool alt;
  bool finished_once;
} td_cr_state_t;

typedef struct {
  bool alt;
  bool finished_once;
} td_ma_state_t;

typedef struct {
  bool alt;
  bool finished_once;
} td_ct_state_t;

typedef struct {
  bool alt;
  bool finished_once;
} td_qw_state_t;

typedef struct {
  bool alt;
  bool finished_once;
} td_co_state_t;

//TD shift on hold, dvorak layer on tap
void _td_dv_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_dv_state_t *s = (td_dv_state_t *)user_data;
  
  if (s->finished_once)
    return;
    
  s->finished_once = true;
  if (state->pressed) {
    s->alt = true;
    register_code (KC_LSFT);
  } else {
    s->alt = false;
	#ifdef BACKLIGHT_ENABLE
		backlight_set(3);
	#endif
	#ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
    #endif
	layer_on(_DVORAK);
	layer_off(_QWERTY);
	layer_off(_COLEMAK);
	layer_off(_LOWER);
	layer_off(_RAISE);
	layer_off(_ADJUST);
	persistent_default_layer_set(1UL<<_DVORAK);
  }
}

void _td_dv_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_dv_state_t *s = (td_dv_state_t *)user_data;

  if (s->alt) {
	unregister_code (KC_LSFT);
  } 
  
  s->finished_once = false;
}


//TD shift on hold, capslock on tap
void _td_sftcaps_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_sftcaps_state_t *s = (td_sftcaps_state_t *)user_data;
  
  if (s->finished_once)
    return;
    
  s->finished_once = true;
  if (state->pressed) {
    s->alt = true;
    register_code (KC_LSFT);
  } else {
    s->alt = false;
    register_code (KC_CAPS);
	#ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(tone_caps, false, 0);
    #endif
  }
}

void _td_sftcaps_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_sftcaps_state_t *s = (td_sftcaps_state_t *)user_data;

  if (s->alt) {
    unregister_code (KC_LSFT);
  } else {
    unregister_code (KC_CAPS);
  }
  
  s->finished_once = false;
}


//TD alt on hold, lower on tap
void _td_alb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_alb_state_t *s = (td_alb_state_t *)user_data;
  
  if (s->finished_once)
    return;
    
  s->finished_once = true;
  if (state->pressed) {
    s->alt = true;
    register_code (KC_LALT);
  } else {
    s->alt = false;
	#ifdef BACKLIGHT_ENABLE
		backlight_set(2);
	#endif
	#ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(tone_coin, false, 0);
    #endif
	layer_on(_LOWER);
	layer_off(_RAISE);
	layer_off(_ADJUST);
  }
}

void _td_alb_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_alb_state_t *s = (td_alb_state_t *)user_data;

  if (s->alt) {
    unregister_code (KC_LALT);
  } 
  
  s->finished_once = false;
}

//TD ctrl on hold, raise on tap
void _td_cr_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_cr_state_t *s = (td_cr_state_t *)user_data;
  
  if (s->finished_once)
    return;
    
  s->finished_once = true;
  if (state->pressed) {
    s->alt = true;
    register_code (KC_LCTL);
  } else {
    s->alt = false;
	#ifdef BACKLIGHT_ENABLE
		backlight_set(1);
	#endif
	#ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(tone_oneup, false, 0);
    #endif
	layer_off(_LOWER);
	layer_on(_RAISE);
	layer_off(_ADJUST);
  }
}

void _td_cr_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_cr_state_t *s = (td_cr_state_t *)user_data;

  if (s->alt) {
    unregister_code (KC_LCTL);
  } 
  
  s->finished_once = false;
}

//TD meh on hold, adjust layer on tap
void _td_ma_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_ma_state_t *s = (td_ma_state_t *)user_data;
  
  if (s->finished_once)
    return;
    
  s->finished_once = true;
  if (state->pressed) {
    s->alt = true;
    register_code (KC_LSFT);
	register_code (KC_LALT);
	register_code (KC_LCTL);
  } else {
    s->alt = false;
	#ifdef BACKLIGHT_ENABLE
		backlight_set(0);
	#endif
	#ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(tone_zelda, false, 0);
    #endif
	layer_off(_LOWER);
	layer_off(_RAISE);
	layer_on(_ADJUST);
  }
}

void _td_ma_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_ma_state_t *s = (td_ma_state_t *)user_data;

  if (s->alt) {
	unregister_code (KC_LCTL);
	unregister_code (KC_LALT);
	unregister_code (KC_LSFT);
  } 
  
  s->finished_once = false;
}

void _td_qw_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_qw_state_t *s = (td_qw_state_t *)user_data;
  
  if (s->finished_once)
    return;
    
  s->finished_once = true;
  if (state->pressed) {
    s->alt = true;
    register_code (KC_LSFT);
  } else {
    s->alt = false;
	#ifdef BACKLIGHT_ENABLE
		backlight_set(3);
	#endif
	#ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
    #endif
	layer_off(_DVORAK);
	layer_on(_QWERTY);
	layer_off(_COLEMAK);
	layer_off(_LOWER);
	layer_off(_RAISE);
	layer_off(_ADJUST);
	persistent_default_layer_set(1UL<<_QWERTY);
  }
}

void _td_qw_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_qw_state_t *s = (td_qw_state_t *)user_data;

  if (s->alt) {
	unregister_code (KC_LSFT);
  } 
  
  s->finished_once = false;
}

//TD shift on hold, colemak layer on tap
void _td_co_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_co_state_t *s = (td_co_state_t *)user_data;
  
  if (s->finished_once)
    return;
    
  s->finished_once = true;
  if (state->pressed) {
    s->alt = true;
    register_code (KC_LSFT);
  } else {
    s->alt = false;
	#ifdef BACKLIGHT_ENABLE
		backlight_set(3);
	#endif
	#ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(tone_colemak, false, 0);
    #endif
	layer_off(_DVORAK);
	layer_off(_QWERTY);
	layer_on(_COLEMAK);
	layer_off(_LOWER);
	layer_off(_RAISE);
	layer_off(_ADJUST);
	persistent_default_layer_set(1UL<<_COLEMAK);
  }
}

void _td_co_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_co_state_t *s = (td_co_state_t *)user_data;

  if (s->alt) {
	unregister_code (KC_LSFT);
  } 
  
  s->finished_once = false;
}


//TD Actions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DV] = {
    .fn = { NULL, _td_dv_finished, _td_dv_reset },
    .user_data = (void *)&((td_dv_state_t) { false, false })
  },
  
  [TD_SFT_CAPS] = {
    .fn = { NULL, _td_sftcaps_finished, _td_sftcaps_reset },
    .user_data = (void *)&((td_sftcaps_state_t) { false, false })
  },
  
  [TD_AL]  = {
    .fn = { NULL, _td_alb_finished, _td_alb_reset },
    .user_data = (void *)&((td_alb_state_t) { false, false })
  },
  
  [TD_CR]  = {
    .fn = { NULL, _td_cr_finished, _td_cr_reset },
    .user_data = (void *)&((td_cr_state_t) { false, false })
  },
  
  [TD_MA]  = {
    .fn = { NULL, _td_ma_finished, _td_ma_reset },
    .user_data = (void *)&((td_ma_state_t) { false, false })
  },
  
  [TD_QW] = {
    .fn = { NULL, _td_qw_finished, _td_qw_reset },
    .user_data = (void *)&((td_qw_state_t) { false, false })
  },
  [TD_CO] = {
    .fn = { NULL, _td_co_finished, _td_co_reset },
    .user_data = (void *)&((td_co_state_t) { false, false })
  }
};


