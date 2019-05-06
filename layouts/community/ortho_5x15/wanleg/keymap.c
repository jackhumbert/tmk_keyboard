#include QMK_KEYBOARD_H
#include "wanleg.h"

#define _________________BLANK_50__________________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

#if defined(PADC)
#define LAYOUT_75_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, \
	K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e  \
  ) \
   LAYOUT_ortho_5x15_wrapper( \
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    QWERTY, GHERKIN, FUNCTION,	KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NLCK,  \
     K00, K01, K02, K03, K04, K05, 		K0c,  K0d,  K0e,		K06, K07, K08, K09, K0a, K0b, \
     K10, K11, K12, K13, K14, K15, 		K1c,  K1d,  K1e,		K16, K17, K18, K19, K1a, K1b, \
     K20, K21, K22, K23, K24, K25, 		K2c,  K2d,  K2e,		K26, K27, K28, K29, K2a, K2b, \
     K30, K31, K32, K33, K34, K35, 		K3c,  K3d,  K3e,	    K36, K37, K38, K39, K3a, K3b  \
  )

#elif defined(PADL)
#define LAYOUT_75_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, \
	K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e  \
  ) \
   LAYOUT_ortho_5x15_wrapper( \
     QWERTY, GHERKIN, FUNCTION,	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NLCK,  \
     K0c,  K0d,  K0e,		K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, \
     K1c,  K1d,  K1e, 		K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, \
     K2c,  K2d,  K2e, 		K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2a, K2b, \
     K3c,  K3d,  K3e,  		K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3a, K3b 	\
  )
  
#else
#define LAYOUT_75_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, \
	K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e  \
  ) \
   LAYOUT_ortho_5x15_wrapper( \
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NLCK,  QWERTY, GHERKIN, FUNCTION, \
     K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, 		K0c,  K0d,  K0e, \
     K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, 		K1c,  K1d,  K1e, \
     K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2a, K2b, 		K2c,  K2d,  K2e, \
     K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3a, K3b, 		K3c,  K3d,  K3e  \
  )
#endif  

#define LAYOUT_75_base_wrapper(...)       LAYOUT_75_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if defined(KEYBOARD_40percentclub_5x5)
[_GK] = LAYOUT_75_base_wrapper(
  _______________GherkinLike_0_______________, KC_7, KC_8, KC_9,
  _______________GherkinLike_1_______________, KC_4, KC_5, KC_6,
  TD(TD_SFT_CAPS), SFT_T(KC_Z), KC_X, KC_C, LT(NUM, KC_V), LT(ETC, KC_B), KC_N, LT(DIR, KC_M), GUI_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_BSPC), SFT_T(KC_ENT), KC_1, KC_2, KC_3,
  TD(RST_TAP_DANCE), GHERKIN50, KC_LALT, NUMPAD, NUMBER, ETCETERA, KC_SPC,DIRECTION, KC_RGUI, KC_RALT, KC_DEL, KC_RCTL, KC_0, KC_0, KC_DOT
),

[GK50] = LAYOUT_ortho_5x10_wrapper(
  KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,
  _______________Gherkin_Row_0_______________,
  _______________Gherkin_Row_1_______________,
  _______________Gherkin_Row_2_______________,
  TD(RST_TAP_DANCE), GHERKIN, NUMPAD, gNUMBER, gETCETERA, KC_SPC,gDIRECTION, KC_RGUI, KC_RALT, KC_RGUI
),

[gNUM] = LAYOUT_ortho_5x10_wrapper(
  _________________BLANK_50__________________,
  _______________Gherkin_NUM_0_______________,
  _______________Gherkin_NUM_1_______________,
  _______________Gherkin_NUM_2_______________,
  _______, _______, _______, _______, _______, KC_ENT, KC_RSFT, KC_RGUI, _______, _______
),

[gDIR] = LAYOUT_ortho_5x10_wrapper(
  _________________BLANK_50__________________,
  _______________Gherkin_DIR_0_______________,
  _______________Gherkin_DIR_1_______________,
  _______________Gherkin_DIR_2_______________,
  _________________BLANK_50__________________
),

[gETC] = LAYOUT_ortho_5x10_wrapper(
  _________________BLANK_50__________________,
  _______________Gherkin_ETC_0_______________,
  _______________Gherkin_ETC_1_______________,
  _______________Gherkin_ETC_2_______________,
  _______, KC_CAPS, _______, _______, _______, LALT(LCTL(KC_DEL)), _______, _______, _______, _______
),

#if defined(BLUEFRUIT)
[PAD] = LAYOUT_ortho_5x5_wrapper(
  _______, _______, _______, OUT_BT, OUT_USB,
  _______________NUMPAD_Row__0_______________, _______,
  _______________NUMPAD_Row__1_______________, _______,
  _______________NUMPAD_Row__2_______________, _______,
  KC_KP_0, TD(LYR50_TAP_DANCE), KC_KP_DOT, KC_PMNS, _______
),
#else
 [PAD] = LAYOUT_ortho_5x5_wrapper(
  _______, _______, _______, _______, _______,
  _______________NUMPAD_Row__0_______________, _______,
  _______________NUMPAD_Row__1_______________, _______,
  _______________NUMPAD_Row__2_______________, _______,
  KC_KP_0, TD(LYR50_TAP_DANCE), KC_KP_DOT, KC_PMNS, _______
),
#endif
#else
 /* Gherkin-Like
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | NUMLOCK| qwerty | gherkin| FN     |
 * |-----------------------------------------------------------------------------------------------------------+--------+--------+--------|
 * |                                                                                                           |   7    |   8    |   9    |
 * |                                                                                                           |--------+--------+--------|
 * |                                            4x12 GHERKIN LAYOUT                                            |   4    |   5    |   6    |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |   1    |   2    |   3    |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |   0    |   0    |   .    |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[_GK] = LAYOUT_75_base_wrapper(
  _______________GherkinLike_0_______________, KC_7, KC_8, KC_9,
  _______________GherkinLike_1_______________, KC_4, KC_5, KC_6,
  _______________GherkinLike_2_______________, KC_1, KC_2, KC_3,
  _______________GherkinLike_3_______________, KC_0, KC_0, KC_DOT
),
#endif
/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | NUMLOCK| qwerty | gherkin| FN     |
 * |-----------------------------------------------------------------------------------------------------------+--------+--------+--------|
 * |                                                                                                           |   7    |   8    |   9    |
 * |                                                                                                           |--------+--------+--------|
 * |                                             4x12 QWERTY LAYOUT                                            |   4    |   5    |   6    |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |   1    |   2    |   3    |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |   0    |   0    |   .    |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[_QW] = LAYOUT_75_base_wrapper(
  _______________Qwerty_Row__0_______________, KC_7, KC_8, KC_9,
  _______________Qwerty_Row__1_______________, KC_4, KC_5, KC_6,
  _______________Qwerty_Row__2_______________, KC_1, KC_2, KC_3,
  _______________Qwerty_Row__3_______________, KC_0, KC_0, KC_DOT
),

 /* SUBTER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------+--------+-----------------|
 * |                                                                                                           |   /    |   *    |   -    |
 * |                                                                                                           |--------+--------+--------|
 * |                                            4x12 SUBTER LAYOUT                                             |        |        |   +    |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        | ENTER  |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[SUB] = LAYOUT_75_base_wrapper(
  _______________SUBTER_Row__0_______________, KC_PSLS, KC_PAST, KC_PMNS,
  _______________SUBTER_Row__1_______________, _______, _______, KC_PPLS, 
  _______________SUBTER_Row__2_______________, _______, _______, KC_PENT,
  _______________SUBTER_Row__3_______________, _______,	_______, _______
),

/* SUPRA
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |                                                                                                           |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                             4x12 SUPRA LAYOUT                                             |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[SUP] = LAYOUT_75_base_wrapper(
  ________________SUPRA_Row_0________________, _______, _______, _______,
  ________________SUPRA_Row_1________________, _______, _______, _______,
  ________________SUPRA_Row_2________________, _______, _______, _______,
  ________________SUPRA_Row_3________________, _______, _______, _______
),

/* Gherkin-Like Numbers
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|--------+-----------------|
 * |                                                                                                           |   /    |   *    |   -    |
 * |                                                                                                           |--------+--------+--------|
 * |                                            4x12 NUMBERS LAYOUT                                            |        |        |   +    |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        | ENTER  |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[NUM] = LAYOUT_75_base_wrapper(
  _______________NUMBERS_Row_0_______________, KC_PSLS, KC_PAST, KC_PMNS,
  _______________NUMBERS_Row_1_______________, _______, _______, KC_PPLS,
  _______________NUMBERS_Row_2_______________, _______, _______, KC_PENT,
  _______________NUMBERS_Row_3_______________, _______, _______, _______
),

/* Gherkin-Like Et Cetera
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|--------+-----------------|
 * |                                                                                                           |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                           4x12 ETCETERA LAYOUT                                            |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[ETC] = LAYOUT_75_base_wrapper(
  ______________ETCETERA_Row__0______________, _______, _______, _______,
  ______________ETCETERA_Row__1______________, _______, _______, _______,
  ______________ETCETERA_Row__2______________, _______, _______, _______,
  ______________ETCETERA_Row__3______________, _______, _______, _______
),

/* Gherkin-Like Directional Keys
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|--------+-----------------|
 * |                                                                                                           |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                          4x12 DIRECTIONAL LAYOUT                                          |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[DIR] = LAYOUT_75_base_wrapper(
  _____________DIRECTIONS_Row__0_____________, _______, _______, _______,
  _____________DIRECTIONS_Row__1_____________, _______, _______, _______,
  _____________DIRECTIONS_Row__2_____________, _______, _______, _______,
  _____________DIRECTIONS_Row__3_____________, _______, _______, _______
),

/* Gherkin FN/Lighting
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|--------+-----------------|
 * |                                                                                                           |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                          4x12 FN/Lighting LAYOUT                                          |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * |                                                                                                           |--------+--------+--------|
 * |                                                                                                           |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

[_FN] = LAYOUT_75_base_wrapper(
  _______, _______________Gherkin_FN_0________________, _______, _______, _______, _______, 
  _______, _______________Gherkin_FN_1________________, _______, _______, _______, _______, 
  _______, _______________Gherkin_FN_2________________, _______, _______, _______, _______, 
  _______, _________________BLANK_50__________________, _______, _______, _______, _______
),

};
