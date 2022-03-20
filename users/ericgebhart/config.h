/*
  Copyright 2018 Eric Gebhart <e.a.gebhart@gmail.com>

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
*/

#ifndef USERSPACE_CONFIG_H
#define USERSPACE_CONFIG_H

// pro-micro v3's don't always detect otherwise.
#define SPLIT_USB_DETECT

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
// Sets good default for the speed of the mouse.
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          100
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7

#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_WHEEL_MAX_SPEED    5
#define MOUSEKEY_WHEEL_TIME_TO_MAX  60
#define MOUSEKEY_WHEEL_DELAY        100

#undef TAPPING_TOGGLE
#undef TAPPING_TERM
#undef IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_TOGGLE  2
#define TAPPING_TERM    200
#define IGNORE_MOD_TAP_INTERRUPT


#define TAP_HOLD_TERM    200
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 150


/* Control switches for my keymaps. */
/* if needed, this goes in the keyboard's config.h */
/* Alternately, fix the number row in the layout template. */
/* #define BASE_NUMBER_ROW    // turn on 4 row base templates. */

// Extensions, turn them on and off.
#define USERSPACE_H "ericgebhart.h"

// OLED STUFF.
#define OLED_CUSTOM_ENABLE // custom oled here.
//#define OLED_LOGO_ENABLE // turn on/off the logo.
//#define KEYLOGGER_ENABLE // 1500 bytes, track and print keypress info to oled.

// EXTENSIONS

// Combos
#define COMBO_REF_LAYER_ENABLE
#define COMBO_REF_LAYER_TWO_ENABLE
// works if you know the number of your layer.
// otherwise set and use them later.
// #define COMBO_ONLY_FROM_LAYER 2
// #define COMBO_REF_DEFAULT 2


// Console key logging for creation of heatmaps, etc.
// CONSOLE must be enabled for this to work.
// To create Precondition's heat maps, from console key logging
// with hid_listen or qmk console
//#define CONSOLE_KEY_LOGGER_ENABLE  // turn on keylogging for heat maps.

#define ALT_LOCAL_ENABLE // alternate key combinations, with mods as needed.
//#define ACCENTED_KEYS_ENABLE // direct access to altgr keys.

#define SMART_LOCK_ENABLE // smart lock layers and mods.
//#define MOD_LOCK_ENABLE  // smart lock mods, similar/overlapping with Smart lock.
#define NSHOT_ENABLE // smart n-shot for count.
//#define ONESHOT_MOD_ENABLE  // oneshot mods, similar/overlapping with nshots

#define CAPS_WORD_ENABLE // caps word. both shifts to caps a word.
#define TAP_HOLD_ENABLE // tap for one thing, hold for tapping term to get another.
//#define SWAPPER_ENABLE // enable swapper keys.


// Turn on the layers
#define DVORAK_LAYER_ENABLE
//#define QWERTY_LAYER_ENABLE
//#define AZERTY_LAYER_ENABLE
//#define COLEMAK_LAYER_ENABLE
//#define COLEMAK_DH_LAYER_ENABLE
//#define BEAKL15_LAYER_ENABLE
//#define BEAKL19_LAYER_ENABLE
#define BEAKL27_LAYER_ENABLE
//#define BEAKLWI_LAYER_ENABLE
//#define CARPLAX_LAYER_ENABLE
//#define WORKMAN_LAYER_ENABLE
//#define NORMAN_LAYER_ENABLE
//#define MALTRON_LAYER_ENABLE
//#define EUCALYN_LAYER_ENABLE
//#define APT_LAYER_ENABLE
//#define RSTHD_LAYER_ENABLE
//#define MTGAP_LAYER_ENABLE
#define HD_NEU_LAYER_ENABLE
//#define HD_REF_LAYER_ENABLE

// Enable bepo specific layers.
// This will add bepo versions of all layers chosen.
#define BEPO_ENABLE
// So far, these are all 3x12.
//#define BEPO_LAYER_ENABLE  // Bepo only works on bepo.
//#define OPTIMOT_LAYER_ENABLE
//#define BEAKL19bis_LAYER_ENABLE

// enable transient function layers.
#define SYMBOL_LAYER_ENABLE
#define NAV_LAYER_ENABLE
#define TOPROWS_LAYER_ENABLE
#define LAYERS_LAYER_ENABLE
#define KEYPAD_LAYER_ENABLE
//#define ADJUST_LAYER_ENABLE
//#define RGB_LAYER_ENABLE

// These are bepo only.
// Extra character layers.
// Bepo has dead keys (altgr) and accented keycodes
// A layer of accented keys
// #define ACCENTED_LAYER_ENABLE
// A layer of dead keys
// #define MORTE_LAYER_ENABLE
// A layer of the most popular accented keys and dead keys
//#define ACCENTED_MORTE_LAYER_ENABLE


// Layout definitions, which language, thumb cluster, mod layer.
// Columns in and out.

// Choose a thumb cluster. undef and redef as needed.
// MODs, LAYERS, MOD_LAYERS,
// WI, WIa, TRNS, TEST
#define THUMBS_ARE DEFAULT

// the default. set it, use it, set it back.
#define LANG_IS EN // BEPO  -

// Choose a mod layer. Can be changed per layer.
// TRNS, ALT, HRM_GACS, HRM_SCAG, HRM_GASC
#define MODS_ARE ALT
#define DEFAULT_MODS MODS_ARE

// a reasonable default for most keyboards.
// give a 3x10 and get a 3x12
#define BASE_COLS_IN_OUT 5_6 // 5, 5_6, 6

// Functional layer choices.
/* configure the function layers. */
/* They have to be turned on above. */
/* Choose one of each as desired. */
/* There are reasonable defaults */
/* for each if nothing is defined. */

/* nav */
//#define NAV_FULL  // monolithic, two sided nav with mouse and arrows.
//#define NAV_FULL_LOCK_MODS // Replace left mouse buttons with lockmods.

// Just the non mouse bits, with lock mods, n-shot mods on the left.
// if mousekeys enabled, adds a mouse layer accessible via smart lock.
#define NAV_NO_MOUSE


/* keypads */
//#define KEYPAD_RIGHT
#define KEYPAD_BEAKL         // beakl doesn't have a rightside, swap hands?

// not working until there are mod keys per lang...
//#define KEYPAD_MODS   //  give mods on the other side instead of funcs.

//#define KEYPAD_BEAKL_WI   // right side with hexpad on left.
// the default if nothing chosen,
// is a functionpad on the left and keypad on the right.


/* symbols */
//#define SYMBOL_BEAKL       // original - the default if nothing else.
//#define SYMBOL_BEAKL_EXT   // extended.
#define SYMBOL_BEAKL_EXT_VI  // extended with vi keybinding in mind.
//#define SYMBOL_BEAKL_WI    // original wi


/* toprows. */
#define TOPROWS_BKL_NUMS  // center row with Beakl15 order. 40123 76598.
#define TOPROWS_MOD  // beakl 15 nums, oneshot and smart lock mods. no Fkeys.
//#define TOPROWS_BKL_19_NUMS // Beakl 19 order: 32104  76598
// the default, if not defined, is a standard qwerty set of rows.
// symbols, numbers, function keys. Numbers on the home row.

#endif
