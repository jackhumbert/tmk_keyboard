#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer [0]
   * ,-------------------------------------------------------------------------------.
   * |Esc |1   |2   |3   |4   |5   |6   |7   |8   |9   |0   |-   |=   |Backspace|Del |
   * |-------------------------------------------------------------------------------+
   * |Tab   |Q   |W   |E   |R   |T   |Y   |U   |I   |O   |P   |[   |]   |\      |Pg U|
   * |-------------------------------------------------------------------------------+
   * |Caps Lck|A   |S   |D   |F   |G   |H   |J   |K   |L   |;   |'   |Return    |Pg D|
   * |-------------------------------------------------------------------------------+
   * |Shift     |Z   |X   |C   |V   |B   |N   |M   |,   |.   |/   |Shift   |↑   |Fn  |
   * |-------------------------------------------------------------------------------+
   * |Ctrl |Opt  |Cmd  |             Space             |Cmd  |Opt  |██|←   |↓   |→   |
   * `-------------------------------------------------------------------------------'
   */

  [0] = LAYOUT_65_ansi_blocker(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL,
	                           KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
							   KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
							   KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, MO(1),
							   KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Layer [1]
   * ,-------------------------------------------------------------------------------.
   * |`   | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|         |    |
   * |-------------------------------------------------------------------------------+
   * |Bri Up|    |    |End |Rst |    |    |    |Ins |    |Pr S|    |    |Eject  |    |
   * |-------------------------------------------------------------------------------+
   * |Bri Down|    |Sc L|    |    |    |Home|    |    |    |    |    |Mute      |    |
   * |-------------------------------------------------------------------------------+
   * |Vol +     |    |    |Calc|    |    |Nm L|Mail|    |    |    |Pause   |    |    |
   * |-------------------------------------------------------------------------------+
   * |Vol -|Rwd  |F Fd |             Play              |M Stp|     |██|Prev|    |Next|
   * `-------------------------------------------------------------------------------'
   */
 
  [1] = LAYOUT_65_ansi_blocker(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
                               KC_BRIU, _______, _______, KC_END, RESET, _______, _______, _______, KC_INS, _______, KC_PSCR, _______, _______, KC_EJCT, _______,
							   KC_BRID, _______, KC_SLCK, _______, _______, _______, KC_HOME, _______, _______, _______, _______, _______, KC_MUTE, _______,
							   KC_VOLU, _______, _______, KC_CALC, _______, _______, KC_NLCK, KC_MAIL, _______, _______, _______, KC_PAUS, _______, _______,
							   KC_VOLD, KC_MRWD, KC_MFFD, KC_MPLY, KC_MSTP, KC_NO, KC_MPRV, KC_NO, KC_MNXT)
}
