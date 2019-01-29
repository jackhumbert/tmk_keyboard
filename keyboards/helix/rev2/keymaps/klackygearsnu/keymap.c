#include QMK_KEYBOARD_H
//#include "klackygears.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _DVORAK = 0,
    _SYMB,
    _NUMB,
    _MDIA
};

enum custom_keycodes {

  DVORAK = SAFE_RANGE,
  SYMB,
  NUMB,
  MDIA,
  BACKLIT,
  EISU,
  KANA,
  //RGBRST,
  DYNAMIC_MACRO_RANGE,
};

 #include "dynamic_macro.h"

enum macro_keycodes {
  KC_SAMPLEMACRO,
};


enum {
  TD_MCROTOG,
  TD_MCROTG2,
  TD_BTK,
  TD_TDE,
  TD_LPRN,
  TD_RPRN,
  TD_MIN,
  TD_USC,
  TD_CMWN,
  TD_ATSH,
  TD_PSTI,
  TD_PTSP,
  TD_FNDR,
  TD_CCPY,
  TD_DDEL,
  TD_ACCW,
  TD_CAPESC,
  TD_DTEX,
  TD_COMQUES,
  TD_MINPLS,
  TD_DIVMLT,
  TD_DOTEQL,
  TD_LSHSYM,
  TD_RSHSYM,
  TD_SCNSP,
  TD_MCCCPY,
  TD_MCPSTIN,
};


#define KC________ KC_TRNS
#define KC_XXXXX KC_NO


//#if HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



  [_DVORAK] = LAYOUT( \
      RGB_MOD,   KC________,           KC________,        KC________,         KC________, KC________,                                            KC________,       KC________, KC________,        KC________,        KC________,     KC________, \
      KC_ESC,    KC_QUOT,              TD(TD_COMQUES),    TD(TD_DTEX),        KC_P,       KC_Y,                                                  KC_F,             KC_G,       KC_C,              KC_R,              KC_L,           KC________, \
      KC_LSFT,   KC_A,                 KC_O,              KC_E,               KC_U,       KC_I,                                                  KC_D,             KC_H,       KC_T,              KC_N,              KC_S,           KC_RSFT, \
      KC_LSFT,   MT(MOD_LCTL,KC_SCLN), MT(MOD_LALT,KC_Q), MT(MOD_LGUI, KC_J), KC_K,       KC_X,             TD(TD_MCROTG2),    TD(TD_MCROTOG),   KC_B,             KC_M,       MT(MOD_LGUI,KC_W), MT(MOD_LALT,KC_V), LT(_MDIA,KC_Z), KC_RSFT, \
      MO(_MDIA), KC_ENT,               KC_LALT,           KC_ENT,             KC_ENT,     LT(_SYMB,KC_SPC), LT(_NUMB,KC_BSPC), LT(_NUMB,KC_TAB), LT(_SYMB,KC_ENT), KC_LCTL,    KC_LEFT,           KC_DOWN,           KC_UP,          KC_RGHT \
      ),



  [_SYMB] = LAYOUT( \
      KC________, KC________, KC________, KC________, KC________, KC________,                         KC________, KC________, KC________, KC________, KC________, KC________, \
      KC________, KC_BSLS,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                            KC________, KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC________, \
      KC________, KC_PLUS,    KC_MINS,    KC_ASTR,    KC_SLSH,    KC_EQL,                             KC________, KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC________, \
      KC________, KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    KC_AMPR,    KC________, KC________, KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC________, \
      KC________, KC________, KC________, KC________, KC_SPC,     KC_DEL,     KC________, KC________, KC_CAPS,    KC________, KC________, KC________, KC________, KC________ \
      ),


  [_NUMB] = LAYOUT( \
      KC_GRV,     KC_1,       KC_2,       KC_3,          KC_4,           KC_5,                               KC_6,          KC_7,       KC_8,       KC_9,              KC_0,           KC________, \
      KC________, KC_PGUP,    KC_PGDN,    KC_HOME,       KC_END,         KC________,                         TD(TD_MINPLS), KC_7,       KC_8,       KC_9,              KC_COLN,        KC________, \
      KC________, KC_LEFT,    KC_UP,      KC_DOWN,       KC_RIGHT,       KC________,                         TD(TD_DIVMLT), KC_4,       KC_5,       KC_6,              C_S_T(KC_COLN), KC________, \
      KC________, KC________, LGUI(KC_A), TD(TD_MCCCPY), TD(TD_MCPSTIN), KC_DEL,     KC________, KC________, TD(TD_DOTEQL), KC_1,       KC_2,       MT(MOD_LGUI,KC_3), KC_LCTRL,       KC________, \
      KC________, KC________, KC________, KC________,    KC_SPC,         KC_BSPC,    KC________, KC________, KC________,    KC_0,       KC_0,       KC________,        KC________,     KC________ \
      ),


  [_MDIA] =  LAYOUT( \
      KC________, KC________, KC________, KC________, KC________, KC________,                         KC________, KC________, KC________, KC________, KC________, KC________, \
      KC________, KC________, KC________, KC________, KC________, KC________,                         KC________, RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_SPI,    KC________, \
      KC________, KC________, KC________, KC________, KC________, KC________,                         RGB_MOD,    RGB_HUD,    RGB_SAD,    RGB_VAD,    RGB_SPD,    KC________, \
      KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC_MPLY,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC________, KC________, \
      KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC________, KC________ \
      )
};

//#else
//#error "undefined keymaps"
//#endif


#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif




void macroTogKey(qk_tap_dance_state_t *state, void *user_data) {
  keyrecord_t kr;

  if (state->count == 1)
  {
    kr.event.pressed = false;
    process_record_dynamic_macro( DYN_MACRO_PLAY1, &kr );
  }
  else if (state->count == 2)
  {
    kr.event.pressed = true;
    process_record_dynamic_macro( DYN_REC_STOP, &kr );
  }
  else if (state->count == 3)
  {
    kr.event.pressed = false;
    process_record_dynamic_macro( DYN_REC_START1, &kr );
  }
}

void macroTogKey2(qk_tap_dance_state_t *state, void *user_data) {
  keyrecord_t kr;

  if (state->count == 1)
  {
    kr.event.pressed = false;
    process_record_dynamic_macro( DYN_MACRO_PLAY2, &kr );
  }
  else if (state->count == 2)
  {
    kr.event.pressed = true;
    process_record_dynamic_macro( DYN_REC_STOP, &kr );
  }
  else if (state->count == 3)
  {
    kr.event.pressed = false;
    process_record_dynamic_macro( DYN_REC_START2, &kr );
  }
}



void pstinsrt(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LALT);
    register_code(KC_I);
    unregister_code(KC_I);
    register_code(KC_E);
    unregister_code(KC_E);
    unregister_code(KC_LALT);
  }
  else
  {
    register_code(KC_LCTL);
    register_code(KC_V);
    unregister_code(KC_V);
    unregister_code(KC_LCTL);
  }
  reset_tap_dance(state);
}

void ccopy(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LCTL);
    register_code(KC_X);
    unregister_code(KC_X);
    unregister_code(KC_LCTL);
  }
  else
  {
    register_code(KC_LCTL);
    register_code(KC_C);
    unregister_code(KC_C);
    unregister_code(KC_LCTL);
  }
  reset_tap_dance(state);
}

void pstspecial(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LALT);
    register_code(KC_E);
    unregister_code(KC_E);
    register_code(KC_S);
    unregister_code(KC_S);
    unregister_code(KC_LALT);
    register_code(KC_V);
    unregister_code(KC_V);
  }
  else
  {
    register_code(KC_LALT);
    register_code(KC_E);
    unregister_code(KC_E);
    register_code(KC_S);
    unregister_code(KC_S);
    unregister_code(KC_LALT);
    register_code(KC_T);
    unregister_code(KC_T);
  }
  reset_tap_dance(state);
}

void deldel(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LALT);
    register_code(KC_E);
    unregister_code(KC_E);
    register_code(KC_D);
    unregister_code(KC_D);
    unregister_code(KC_LALT);
  }
  else
  {
    register_code(KC_DEL);
    unregister_code(KC_DEL);
  }
  reset_tap_dance(state);
}

void findreplace(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LCTL);
    register_code(KC_H);
    unregister_code(KC_H);
    unregister_code(KC_LCTL);
  }
  else
  {
    register_code(KC_LCTL);
    register_code(KC_F);
    unregister_code(KC_F);
    unregister_code(KC_LCTL);
  }
  reset_tap_dance(state);
}

void cyclawin(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LCTL);
    register_code(KC_LSFT);
    register_code(KC_F6);
    unregister_code(KC_F6);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
  }
  else
  {
    register_code(KC_LCTL);
    register_code(KC_F6);
    unregister_code(KC_F6);
    unregister_code(KC_LCTL);
  }
  reset_tap_dance(state);
}


void SCRNSNP(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LALT);
    register_code(KC_PSCR);
    unregister_code(KC_PSCR);
    unregister_code(KC_LALT);
  }
  else
  {
    SEND_STRING(SS_TAP(X_LGUI));
    SEND_STRING("SN");
    register_code(KC_LCTL);
    register_code(KC_N);
    unregister_code(KC_N);
    unregister_code(KC_LCTL);
  }
  reset_tap_dance(state);
}


void mcccpy(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LGUI);
    register_code(KC_X);
    unregister_code(KC_X);
    unregister_code(KC_LGUI);
  }
  else
  {
    register_code(KC_LGUI);
    register_code(KC_C);
    unregister_code(KC_C);
    unregister_code(KC_LGUI);
  }
  reset_tap_dance(state);
}

void mcpstin(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LGUI);
    register_code(KC_I);
    unregister_code(KC_I);
    unregister_code(KC_LGUI);
  }
  else
  {
    register_code(KC_LGUI);
    register_code(KC_V);
    unregister_code(KC_V);
    unregister_code(KC_LGUI);
  }
  reset_tap_dance(state);
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
// Other declarations would go here, separated by commas, if you have them
  [TD_MCROTOG]  = ACTION_TAP_DANCE_FN(macroTogKey),
  [TD_MCROTG2] = ACTION_TAP_DANCE_FN(macroTogKey2),
  [TD_PSTI] = ACTION_TAP_DANCE_FN(pstinsrt),
  [TD_PTSP] = ACTION_TAP_DANCE_FN(pstspecial),
  [TD_FNDR] = ACTION_TAP_DANCE_FN(findreplace),
  [TD_CCPY] = ACTION_TAP_DANCE_FN(ccopy),
  [TD_DDEL] = ACTION_TAP_DANCE_FN(deldel),
  [TD_ACCW] = ACTION_TAP_DANCE_FN(cyclawin),
  [TD_CAPESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC,KC_CAPS),
  [TD_DTEX] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_EXLM),
  [TD_COMQUES] = ACTION_TAP_DANCE_DOUBLE(KC_COMM,KC_QUES),
  [TD_MINPLS] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS,KC_PPLS),
  [TD_DIVMLT] = ACTION_TAP_DANCE_DOUBLE(KC_PSLS,KC_PAST),
  [TD_DOTEQL] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_EQL),
  [TD_SCNSP]  = ACTION_TAP_DANCE_FN(SCRNSNP),
  [TD_MCCCPY] = ACTION_TAP_DANCE_FN(mcccpy),
  [TD_MCPSTIN] = ACTION_TAP_DANCE_FN(mcpstin)
};


// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting MDIA layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

 if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
/*
  switch (keycode) {

      return false;
      break;

    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_SYMB);
        update_tri_layer_RGB(_SYMB, _NUMB, _MDIA);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_SYMB);
        update_tri_layer_RGB(_SYMB, _NUMB, _MDIA);
      }
      return false;
      break;
    case NUMB:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE);
          #endif
        }
        layer_on(_NUMB);
        update_tri_layer_RGB(_SYMB, _NUMB, _MDIA);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_NUMB);
        TOG_STATUS = false;
        update_tri_layer_RGB(_SYMB, _NUMB, _MDIA);
      }
      return false;
      break;
    case MDIA:
        if (record->event.pressed) {
          layer_on(_MDIA);
        } else {
          layer_off(_MDIA);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;

    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  */
  return true;


}
void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
   // #ifdef RGBLIGHT_ENABLE
   //   RGB_current_mode = rgblight_config.mode;
   // #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

/*
#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
*/

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// hook point for 'led_test' keymap
//   'default' keymap's led_test_init() is empty function, do nothing
//   'led_test' keymap's led_test_init() force rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
__attribute__ ((weak))
void led_test_init(void) {}


void matrix_scan_user(void) {
  //  rgblight_setrgb_at(0,255,0,0);
  //  rgblight_setrgb_at(0,255,0,1);
  //  rgblight_setrgb_at(0,255,0,2);
  //  rgblight_setrgb_at(0,255,0,3);
  //  rgblight_setrgb_at(0,255,0,4);
  //  rgblight_setrgb_at(0,255,0,5);
  //    rgblight_setrgb_at(0,0,255,6);
  //    rgblight_setrgb_at(10,0,255,17);
  //    rgblight_setrgb_at(10,0,230,18);
  //    rgblight_setrgb_at(20,0,220,31);

     led_test_init();
     iota_gfx_task();  // this is what updates the display continuously

}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_SYMB (1<<_SYMB)
#define L_NUMB (1<<_NUMB)
#define L_MDIA (1<<_MDIA)
#define L_MDIA_TRI (L_MDIA|L_NUMB|L_SYMB)

static void render_logo(struct CharacterMatrix *matrix) {

  static char logo[]={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write(matrix, logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}



void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static char logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[0][1]);
  }else{
    matrix_write(matrix, logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[1][1]);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(matrix, PSTR("\nLayer: "));
    switch (layer_state) {
        case L_BASE:
           matrix_write_P(matrix, PSTR("Dvorak"));
           break;
        case L_NUMB:
           matrix_write_P(matrix, PSTR("Numeric"));
           break;
        case L_SYMB:
           matrix_write_P(matrix, PSTR("Punctuation"));
           break;
        case L_MDIA:
        case L_MDIA_TRI:
           matrix_write_P(matrix, PSTR("MDIA"));
           break;
        default:
           matrix_write(matrix, buf);
    }

  // Host Keyboard LED Status
  char led[40];
    snprintf(led, sizeof(led), "\n%s  %s  %s",
            (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NUMLOCK" : "       ",
            (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPS" : "    ",
            (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    ");
  matrix_write(matrix, led);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
