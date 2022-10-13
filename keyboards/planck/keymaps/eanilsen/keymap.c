
/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"
#include "customkeys.h"
#include "features/swapper.h"
#include "features/select_word.h"


enum planck_layers {
  _ISRT,
  _SYMBOL,
  _FUNCTION,
  _NAV,
  _NUM
};

#define SYMBOL OSL(_SYMBOL)
#define FUNCTION OSL(_FUNCTION)
#define NAV TO(_NAV)
#define HOME TO(_ISRT)
#define NUM TO(_NUM)
#define MTLCTL MT(MOD_LCTL,KC_T)
#define MTRCTL MT(MOD_RCTL,KC_N)
#define MEH_SPC MT(MOD_MEH,KC_SPC)
#define LT_LABK LT(0,KC_C)
#define LT_RABK LT(0,KC_L)
#define LT_COMM LT(0,KC_COMM)
#define LT_DOT LT(0,KC_DOT)
#define LT_EXLM LT(0,KC_Y)
#define LT_UP LT(0,KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  /* ISRT
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Y  |   C  |   L  |   M  |   K  |   Z  |   F  |   U  |   ,  |   '  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   I  |   S  |   R  |   T  |   G  |   P  |   N  |   E  |   A  |   O  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Q  |   V  |   W  |   D  |   J  |   B  |   H  |   /  |   .  |   X  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |CPSWRD| Ctrl | Alt  | GUI  |Space | Num  | Func |Bksp  | Nav  | GUI  | Left |Right |
   * `-----------------------------------------------------------------------------------'
   */

  [_ISRT] = LAYOUT_ortho_4x12(
    KC_TAB,  LT_EXLM, LT_LABK, LT_RABK,           KC_M,    KC_K,   KC_Z,     KC_F,          KC_U,              LT_COMM, KC_QUOT, KC_DEL,
    KC_ESC,  KC_I,    KC_S,    MT(MOD_LALT,KC_R), MTLCTL,  KC_G,   KC_P,     MTRCTL,        MT(MOD_RALT,KC_E), KC_A,    KC_O,    KC_ENT,
    KC_LSFT, KC_Q,    KC_V,    KC_W,              KC_D,    KC_J,   KC_B,     KC_H,          KC_SLSH,           LT_DOT,  KC_X,    KC_RSFT,
    CAPSWRD, KC_LCTL, KC_LALT, KC_LGUI,           MEH_SPC, SYMBOL, FUNCTION, LT(0,KC_BSPC), NAV,               KC_LGUI, KC_LEFT, KC_RGHT
    ),

  /* SYMBOL
   * ,-----------------------------------------------------------------------------------.
   * |  --- |  --- |   !  |   <  |   >  |   +  |   ^  |   _  |   |  |   ~  |   %  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   {  |   }  |   (  |   )  |   @  |   #  |   &  |   *  |   "  |   $  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|  --- |   :  |   [  |   ]  |   ;  |   =  |   -  |   \  |   `  |  --- |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  --- | Ctrl | Alt  | GUI  |Space |  --- | Home |  Num |  --- |  --- |  --- | ---  |
   * `-----------------------------------------------------------------------------------'
   */

  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_NO,   KC_NO,   KC_EXLM, KC_LT,   KC_GT,   KC_PLUS, KC_CIRC, KC_UNDS, KC_PIPE, KC_TILD, KC_PERC, KC_DEL,
    KC_ESC,  KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,   KC_HASH, KC_AMPR, KC_ASTR, KC_DQUO, KC_DLR,  KC_ENT,
    KC_LSFT, KC_NO,   KC_COLN, KC_LBRC, KC_RBRC, KC_SCLN, KC_EQL,  KC_MINS, KC_BSLS, KC_GRV,  KC_NO,   KC_RSFT,
    KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_NO,   HOME,    NUM,     KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

  /* NUM
   * ,-----------------------------------------------------------------------------------.
   * | ---  |   /  |   1  |   2  |   3  |   +  | ---  | ---  | ---  | ---  | ---  | ---  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   0  |   4  |   5  |   6  |   -  | ---  | ---  | ---  | ---  | ---  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   *  |   7  |   8  |   9  |   =  | ---  | ---  | ---  | ---  | ---  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  | Ctrl | Alt  | GUI  |Space | Home | ---  |Bkspc | ---  | ---  | ---  | ---  |
   * `-----------------------------------------------------------------------------------'
   */

  [_NUM] = LAYOUT_ortho_4x12(
    KC_NO,  KC_SLSH, KC_1,    KC_2,    KC_3,   KC_PLUS, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
    KC_ESC, KC_0,    KC_4,    KC_5,    KC_6,   KC_MINS, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_ENT,
    KC_NO,  KC_ASTR, KC_7,    KC_8,    KC_9,   KC_EQL,  KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_RSFT,
    KC_NO,  KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, HOME,    KC_NO, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO
    ),

  /* FUNCTION
   * ,-----------------------------------------------------------------------------------.
   * |CG_TGL|  F1  |  F2  |  F3  |  F4  | ---  | ---  |PrScr | ---  | ---  |   �  |Reset |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  |  F5  |  F6  |  F7  |  F8  | ---  | ---  | Copy |Paste |   �  |   �  | ---  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|  F9  | F10  | F11  | F12  | ---  | ---  |SelWrd| ---  | ---  | ---  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  | Ctrl | Alt  | GUI  |Space | Home | Trns | Ctrl | ---  | ---  | ---  |  --- |
   * `-----------------------------------------------------------------------------------'
   */

  [_FUNCTION] = LAYOUT_ortho_4x12(
    CG_TOGG,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_NO, KC_NO,   KC_PSCR, KC_NO,   KC_NO,   NO_AE,   QK_BOOT,
    KC_NO,     KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_NO, KC_NO,   MW_COPY, MW_PSTE, NO_ARNG, NO_OSTR, KC_NO,
    KC_LSFT,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_NO, KC_NO,   SEL_WRD, KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
    KC_NO,     KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, HOME,  KC_TRNS, KC_RCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

  /* NAV
   * ,-----------------------------------------------------------------------------------.
   * | ---  |ScrlUp| ---  | MsUp | ---  | ---  | Mute |VolDwn|  Up  |VolUp | ---  | ---  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |ScrlDn|MsLft |MsDwn |MsRgt | ---  | Btn4 | Left | Down |Right | Btn5 |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  |SwApp |SwWin | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  | ---  | ---  | Btn3 | Btn1 | Home | ---  | Btn2 | ---  | ---  | ---  | ---  |
   * `-----------------------------------------------------------------------------------'
   */

  [_NAV] = LAYOUT_ortho_4x12(
    KC_NO,  KC_WH_U, KC_NO,   KC_MS_U, KC_NO,   KC_NO, KC_MUTE, KC_VOLD, LT_UP,   KC_VOLU, KC_NO,   KC_NO,
    KC_ESC, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_BTN4, KC_LEFT, KC_DOWN, KC_RGHT, KC_BTN5, KC_ENT,
    KC_NO,  SW_APP,  SW_WIN,  KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,  KC_NO,   KC_NO,   KC_BTN3, KC_BTN1, HOME,  KC_NO,   KC_BTN2, KC_NO,   KC_NO,   KC_NO,   KC_NO
    )
};

// Returns the value set by CG_TOGG
bool is_mac_the_default(void) { return keymap_config.swap_lctl_lgui; }

bool sw_app_active = false;
bool sw_win_active = false;

void send_mac_or_win(uint16_t mac_code, uint16_t win_code, bool is_pressed)
{
  uint16_t code = is_mac_the_default() ? mac_code : win_code;
  if (is_pressed) {
    register_code16(code);
  } else {
    unregister_code16(code);
  }
}

/* static bool process_tap_or_long_press_key(keyrecord_t *record, uint16_t long_press_keycode) */
/* { */
/*   if (!record->tap.count) { // Key is being held */
/*     if (record->event.pressed) { */
/*       tap_code16(long_press_keycode); */
/*     } */
/*     return false; */
/*   } */
/*   return true; */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  bool isPressed = record->event.pressed;
  bool isHeld = !record->tap.count && isPressed;

  {
    uint16_t mod = is_mac_the_default() ? KC_LGUI : KC_LALT;
    update_swapper(&sw_app_active, mod, KC_TAB, SW_APP, keycode, record);
  }
  update_swapper(&sw_win_active, KC_LGUI, KC_GRV, SW_WIN, keycode, record);

  if (!process_select_word(keycode, record, SEL_WRD, is_mac_the_default())) { return false; }

  switch (keycode) {
  case KC_PSCR:
    send_mac_or_win(G(S(KC_4)), KC_PSCR, isPressed);
    return false;
  case LT_UP:
    if (isHeld) {
      tap_code16(C(KC_UP));
      return false;
    }
    return true;
  case LT_EXLM:
    if (isHeld) {
      tap_code16(KC_EXLM);
      return false;
    }
    return true;
  case LT_COMM:
    if (isHeld) {
      tap_code16(KC_MINS);
      return false;
    }
    return true;
  case LT_DOT:
    if (isHeld) {
      tap_code16(S(KC_MINS));
      return false;
    }
    return true;
  case LT_LABK:
    if (isHeld) {
      tap_code16(KC_LABK);
      return false;
    }
    return true;
  case LT_RABK:
    if (isHeld) {
      tap_code16(KC_RABK);
      return false;
    }
    return true;
  case LT(0,KC_SCLN):
    if (isHeld) {
      tap_code16(KC_COLN);
      return false;
    }
    return true;
  case LT(0,KC_BSLS):
    if (isHeld) {
      tap_code16(KC_HOME);
      return false;
    }
    return true;
  case LT(0,KC_BSPC):
    if (isHeld) {
      uint16_t code = is_mac_the_default() ? A(KC_BSPC) : C(KC_BSPC);
      tap_code16(code);
      return false;
    }
    return true;
  case LT(0,CT_PIPE):
    if (record->tap.count && isPressed) {
      tap_code16(S(KC_BSLS));
    } else if (isHeld) {
      tap_code16(KC_END);
    }
    return false;
  case MW_PSTE:
    send_mac_or_win(G(KC_V), C(KC_V), isPressed);
    return false;
  case MW_UNDO:
    send_mac_or_win(G(KC_Z), C(KC_Z), isPressed);
    return false;
  case MW_CUT:
    send_mac_or_win(G(KC_X), C(KC_X), isPressed);
    return false;
  case MW_COPY:
    send_mac_or_win(G(KC_C), C(KC_C), isPressed);
    return false;
  case CLS_WIN:
    send_mac_or_win(G(KC_W), C(KC_W), isPressed);
    return false;
  case MW_REDO:
    send_mac_or_win(G(S(KC_Z)), C(KC_Y), isPressed);
    return false;
  case KC_DWRD:
    send_mac_or_win(A(KC_BSPC), C(KC_BSPC), isPressed);
    return false;
  case KC_3GRV: {
    if (isPressed) {
      for (uint8_t i = 0; i < 3; i++) tap_code16(KC_GRV);
    }
    return false;
  }
  }
  return true;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MTLCTL:
    return TAPPING_TERM + 200;
  case MTRCTL:
    return TAPPING_TERM + 200;
  case MT(MOD_LALT,KC_R):
    return TAPPING_TERM + 200;
  case LT_LABK:
    return TAPPING_TERM + 200;
  case LT_RABK:
    return TAPPING_TERM + 200;
  case LT_UP:
    return TAPPING_TERM + 200;
  case LT_EXLM:
    return TAPPING_TERM + 200;
  case MEH_SPC:
    return TAPPING_TERM + 60;
  default:
    return TAPPING_TERM;
  }
}
#endif
