/* Copyright 2017 skully <skullydazed@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CLUEBOARD60_H
#define CLUEBOARD60_H

#include "quantum.h"

/*
 * These are shortcuts to help you work with the various layout options. If your
 * keymap works with one of the LAYOUT_...() macros you are encouraged to use that
 * and to contribute your keymap to the corresponding layout in
 * `qmk_firmware/layouts/community`.
 */

/* The fully-featured LAYOUT_all() that has every single key available in the matrix.
 */
#define LAYOUT_all(\
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, \
     k10,   k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c,   k1e, \
     k20,    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c,  k2e, \
    k30, k31,  k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,     k3c, k3e, \
    k40,  k41,  k42,               k47,                    k4a, k4b, k4c, k4e \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, KC_NO, k1e, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, KC_NO, k2e, }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, KC_NO, k3e, }, \
    { k40, k41, k42, KC_NO, KC_NO, KC_NO, KC_NO, k47, KC_NO, KC_NO, k4a, k4b, k4c, KC_NO, k4e, }, \
}

/* A layout that matches the Apple Extended Keyboard's main area. No split keys,
 * 3 mods on either side of the spacebar.
 */
#define LAYOUT_aek(\
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,   k0e, \
     k10,   k11, k12, k13, k14, k15, k16, k17, k18, k19, k1b,k1a,  k1c,   k1e, \
     k20,    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2b,k2a,     k2e, \
       k30,   k32, k33, k34, k35, k36, k37, k38, k39, k3b, k3a,       k3c, \
    k40,  k41,  k42,               k47,                         k4b, k4c, k4e \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, KC_NO, k0e, }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, KC_NO, k1e, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, KC_NO, KC_NO, k2e, }, \
    { k30, KC_NO, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, KC_NO, KC_NO, }, \
    { k40, k41, k42, KC_NO, KC_NO, KC_NO, KC_NO, k47, KC_NO, KC_NO, KC_NO, k4b, k4c, KC_NO, k4e, }, \
}

/* Standard 60% ANSI layout */
#define LAYOUT_60_ansi(\
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,   k0e, \
     k10,   k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c,   k1e, \
     k20,    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,    k2e, \
       k30, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,        k3c, \
    k40,  k41,  k42,               k47,                    k4a, k4b, k4c, k4e \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, KC_NO, k0e, }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, KC_NO, k1e, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, KC_NO, KC_NO, k2e, }, \
    { k30, KC_NO, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, KC_NO, KC_NO, }, \
    { k40, k41, k42, KC_NO, KC_NO, KC_NO, KC_NO, k47, KC_NO, KC_NO, k4a, k4b, k4c, KC_NO, k4e, }, \
}

/* Standard 60% ISO layout */
#define LAYOUT_60_iso(\
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,   k0e, \
     k10,   k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c,   \
     k20,    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c,  k2e, \
    k30, k31,  k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,     k3c, \
    k40,  k41,  k42,               k47,                    k4a, k4b, k4c, k4e \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, KC_NO, k0e, }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, KC_NO, KC_NO, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, KC_NO, k2e, }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, KC_NO, KC_NO, }, \
    { k40, k41, k42, KC_NO, KC_NO, KC_NO, KC_NO, k47, KC_NO, KC_NO, k4a, k4b, k4c, KC_NO, k4e, }, \
}

/* Split Backspace and Right Shift ANSI layout. */
#define LAYOUT_60_ansi_split_bs_rshift(\
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, \
     k10,   k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c,   k1e, \
     k20,    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,    k2e, \
       k30,    k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,     k3c, k3e, \
    k40,  k41,  k42,               k47,                    k4a, k4b, k4c, k4e \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, KC_NO, k1e, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, KC_NO, KC_NO, k2e, }, \
    { k30, KC_NO, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, KC_NO, k3e, }, \
    { k40, k41, k42, KC_NO, KC_NO, KC_NO, KC_NO, k47, KC_NO, KC_NO, k4a, k4b, k4c, KC_NO, k4e, }, \
}

#define LAYOUT LAYOUT_all
#define KEYMAP LAYOUT_all
#endif
