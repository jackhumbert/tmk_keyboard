#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _LEFTHAND,
  _FUNC
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LEFTHAND,
  FUNC
};

#define SPC_LFT LT(_LEFTHAND, KC_SPC)
#define BSP_FUNC LT(_FUNC, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base/Qwerty layer
 * .----------------------------------------.     .-----------------------------------------.
 * |  ~  |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |  -   |
 * |-----+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Tab |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |-----+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Esc |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |-----+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Lsft(|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |  /   |Rsft) |
 * |-----+------+------+------+------+------|     |------+------+------+------+------+------|
 * |LCtrl| LGui | LAlt | Del  |  Spc/LftHnd |     |  Bckpc/Func | Left | Down |  Up  |Right |
 * `----------------------------------------'     '-----------------------------------------'
 */
	
	[_QWERTY] = LAYOUT(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                        KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, 
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                                        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
		KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B,                                       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, 
		LCTL_T(KC_MPRV), LGUI_T(KC_MPLY), LALT_T(KC_MNXT), KC_DEL, SPC_LFT, SPC_LFT, BSP_FUNC, BSP_FUNC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
	),

/* Left hand layer 
 * .-----------------------------------------.    .-----------------------------------------.
 * |   +  |      |      |      |      | Rst  |    | NumLk|  /   |  *   |  -   |      |   \  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      | Home |  [   |   ]  |  Up  | PgUp |    |   7  |  8   |  9   |  +   |      |   ]  |  
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |  End | Left | Down | Right| PgDn |    |   4  |  5   |  6   |  ,   |      | Enter|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      | Calc | MyPC |PrtScr| Enter|BckSpc|    |   1  |  2   |  3   |  =   | PgUp | Home |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      | Mute |      |      |      |      |    |      0      |  .   | Enter| PgDn |  End |
 * `-----------------------------------------'    `-----------------------------------------'
 */	

	[_LEFTHAND] = LAYOUT(
		KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS, KC_BSLS, 
		KC_TRNS, KC_TRNS, KC_LBRC, KC_UP, KC_RBRC, KC_TRNS,   KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS, KC_RBRC, 
		KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PCMM, KC_TRNS, KC_ENT, 
		KC_TRNS, KC_CALC, KC_MYCM, KC_PSCR, KC_ENT, KC_BSPC,  KC_P1, KC_P2, KC_P3, KC_PEQL, KC_PGUP, KC_HOME, 
		KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P0, KC_PDOT, KC_PENT, KC_PGDN, KC_END
	),

/* Func/Numpad layer
 * .-----------------------------------------.    .-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | RGBtg|      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      | Rst  |
 * `-----------------------------------------'    `-----------------------------------------'
*/	


	[_FUNC] = LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,             KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
		RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET
	),
};
