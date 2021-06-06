/* Copyright 2021 Cutie Club
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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_all( \
    k00_00, k00_01, k00_02, k00_03, k00_04, k00_05, k00_06, k00_07, k00_08, k00_09, k00_10, k00_11, k00_12, k00_13, k00_14, k00_15, k00_16, k00_17, k00_18, k00_19, \
    k01_00, k01_01, k01_02, k01_03, k01_04, k01_05, k01_06, k01_07, k01_08, k01_09, k01_10, k01_11, k01_12, k01_13, k01_14, k01_15, k01_16, k01_17, k01_18, k01_19, \
    k02_00, k02_01, k02_02, k02_03, k02_04, k02_05, k02_06, k02_07, k02_08, k02_09, k02_10, k02_11, k02_12, k02_13, k02_14, k02_15, k02_16, k02_17, k02_18, k02_19, \
    k03_00, k03_01, k03_02, k03_03, k03_04, k03_05, k03_06, k03_07, k03_08, k03_09, k03_10, k03_11, k03_12, k03_13, k03_14, k03_15, k03_16, k03_17, k03_18, k03_19, \
    k04_00, k04_01, k04_02, k04_03, k04_04, k04_05, k04_06, k04_07, k04_08, k04_09, k04_10, k04_11, k04_12, k04_13, k04_14, k04_15, k04_16, k04_17, k04_18, k04_19, \
    k05_00, k05_01, k05_02, k05_03, k05_04, k05_05, k05_06, k05_07, k05_08, k05_09, k05_10, k05_11, k05_12, k05_13, k05_14, k05_15, k05_16, k05_17, k05_18, k05_19, \
    k06_00, k06_01, k06_02, k06_03, k06_04, k06_05, k06_06, k06_07, k06_08, k06_09, k06_10, k06_11, k06_12, k06_13, k06_14, k06_15, k06_16, k06_17, k06_18, k06_19, \
    k07_00, k07_01, k07_02, k07_03, k07_04, k07_05, k07_06, k07_07, k07_08, k07_09, k07_10, k07_11, k07_12, k07_13, k07_14, k07_15, k07_16, k07_17, k07_18, k07_19, \
    k08_00, k08_01, k08_02, k08_03, k08_04, k08_05, k08_06, k08_07, k08_08, k08_09, k08_10, k08_11, k08_12, k08_13, k08_14, k08_15, k08_16, k08_17, k08_18, k08_19, \
    k09_00, k09_01, k09_02, k09_03, k09_04, k09_05, k09_06, k09_07, k09_08, k09_09, k09_10, k09_11, k09_12, k09_13, k09_14, k09_15, k09_16, k09_17, k09_18, k09_19, \
    k10_00, k10_01, k10_02, k10_03, k10_04, k10_05, k10_06, k10_07, k10_08, k10_09, k10_10, k10_11, k10_12, k10_13, k10_14, k10_15, k10_16, k10_17, k10_18, k10_19, \
    k11_00, k11_01, k11_02, k11_03, k11_04, k11_05, k11_06, k11_07, k11_08, k11_09, k11_10, k11_11, k11_12, k11_13, k11_14, k11_15, k11_16, k11_17, k11_18, k11_19, \
    k12_00, k12_01, k12_02, k12_03, k12_04, k12_05, k12_06, k12_07, k12_08, k12_09, k12_10, k12_11, k12_12, k12_13, k12_14, k12_15, k12_16, k12_17, k12_18, k12_19, \
    k13_00, k13_01, k13_02, k13_03, k13_04, k13_05, k13_06, k13_07, k13_08, k13_09, k13_10, k13_11, k13_12, k13_13, k13_14, k13_15, k13_16, k13_17, k13_18, k13_19, \
    k14_00, k14_01, k14_02, k14_03, k14_04, k14_05, k14_06, k14_07, k14_08, k14_09, k14_10, k14_11, k14_12, k14_13, k14_14, k14_15, k14_16, k14_17, k14_18, k14_19, \
    k15_00, k15_01, k15_02, k15_03, k15_04, k15_05, k15_06, k15_07, k15_08, k15_09, k15_10, k15_11, k15_12, k15_13, k15_14, k15_15, k15_16, k15_17, k15_18, k15_19, \
    k16_00, k16_01, k16_02, k16_03, k16_04, k16_05, k16_06, k16_07, k16_08, k16_09, k16_10, k16_11, k16_12, k16_13, k16_14, k16_15, k16_16, k16_17, k16_18, k16_19, \
    k17_00, k17_01, k17_02, k17_03, k17_04, k17_05, k17_06, k17_07, k17_08, k17_09, k17_10, k17_11, k17_12, k17_13, k17_14, k17_15, k17_16, k17_17, k17_18, k17_19, \
    k18_00, k18_01, k18_02, k18_03, k18_04, k18_05, k18_06, k18_07, k18_08, k18_09, k18_10, k18_11, k18_12, k18_13, k18_14, k18_15, k18_16, k18_17, k18_18, k18_19, \
    k19_00, k19_01, k19_02, k19_03, k19_04, k19_05, k19_06, k19_07, k19_08, k19_09, k19_10, k19_11, k19_12, k19_13, k19_14, k19_15, k19_16, k19_17, k19_18, k19_19 \
) \
{ \
    { k00_00, k00_01, k00_02, k00_03, k00_04, k00_05, k00_06, k00_07, k00_08, k00_09, k00_10, k00_11, k00_12, k00_13, k00_14, k00_15, k00_16, k00_17, k00_18, k00_19 }, \
    { k01_00, k01_01, k01_02, k01_03, k01_04, k01_05, k01_06, k01_07, k01_08, k01_09, k01_10, k01_11, k01_12, k01_13, k01_14, k01_15, k01_16, k01_17, k01_18, k01_19 }, \
    { k02_00, k02_01, k02_02, k02_03, k02_04, k02_05, k02_06, k02_07, k02_08, k02_09, k02_10, k02_11, k02_12, k02_13, k02_14, k02_15, k02_16, k02_17, k02_18, k02_19 }, \
    { k03_00, k03_01, k03_02, k03_03, k03_04, k03_05, k03_06, k03_07, k03_08, k03_09, k03_10, k03_11, k03_12, k03_13, k03_14, k03_15, k03_16, k03_17, k03_18, k03_19 }, \
    { k04_00, k04_01, k04_02, k04_03, k04_04, k04_05, k04_06, k04_07, k04_08, k04_09, k04_10, k04_11, k04_12, k04_13, k04_14, k04_15, k04_16, k04_17, k04_18, k04_19 }, \
    { k05_00, k05_01, k05_02, k05_03, k05_04, k05_05, k05_06, k05_07, k05_08, k05_09, k05_10, k05_11, k05_12, k05_13, k05_14, k05_15, k05_16, k05_17, k05_18, k05_19 }, \
    { k06_00, k06_01, k06_02, k06_03, k06_04, k06_05, k06_06, k06_07, k06_08, k06_09, k06_10, k06_11, k06_12, k06_13, k06_14, k06_15, k06_16, k06_17, k06_18, k06_19 }, \
    { k07_00, k07_01, k07_02, k07_03, k07_04, k07_05, k07_06, k07_07, k07_08, k07_09, k07_10, k07_11, k07_12, k07_13, k07_14, k07_15, k07_16, k07_17, k07_18, k07_19 }, \
    { k08_00, k08_01, k08_02, k08_03, k08_04, k08_05, k08_06, k08_07, k08_08, k08_09, k08_10, k08_11, k08_12, k08_13, k08_14, k08_15, k08_16, k08_17, k08_18, k08_19 }, \
    { k09_00, k09_01, k09_02, k09_03, k09_04, k09_05, k09_06, k09_07, k09_08, k09_09, k09_10, k09_11, k09_12, k09_13, k09_14, k09_15, k09_16, k09_17, k09_18, k09_19 }, \
    { k10_00, k10_01, k10_02, k10_03, k10_04, k10_05, k10_06, k10_07, k10_08, k10_09, k10_10, k10_11, k10_12, k10_13, k10_14, k10_15, k10_16, k10_17, k10_18, k10_19 }, \
    { k11_00, k11_01, k11_02, k11_03, k11_04, k11_05, k11_06, k11_07, k11_08, k11_09, k11_10, k11_11, k11_12, k11_13, k11_14, k11_15, k11_16, k11_17, k11_18, k11_19 }, \
    { k12_00, k12_01, k12_02, k12_03, k12_04, k12_05, k12_06, k12_07, k12_08, k12_09, k12_10, k12_11, k12_12, k12_13, k12_14, k12_15, k12_16, k12_17, k12_18, k12_19 }, \
    { k13_00, k13_01, k13_02, k13_03, k13_04, k13_05, k13_06, k13_07, k13_08, k13_09, k13_10, k13_11, k13_12, k13_13, k13_14, k13_15, k13_16, k13_17, k13_18, k13_19 }, \
    { k14_00, k14_01, k14_02, k14_03, k14_04, k14_05, k14_06, k14_07, k14_08, k14_09, k14_10, k14_11, k14_12, k14_13, k14_14, k14_15, k14_16, k14_17, k14_18, k14_19 }, \
    { k15_00, k15_01, k15_02, k15_03, k15_04, k15_05, k15_06, k15_07, k15_08, k15_09, k15_10, k15_11, k15_12, k15_13, k15_14, k15_15, k15_16, k15_17, k15_18, k15_19 }, \
    { k16_00, k16_01, k16_02, k16_03, k16_04, k16_05, k16_06, k16_07, k16_08, k16_09, k16_10, k16_11, k16_12, k16_13, k16_14, k16_15, k16_16, k16_17, k16_18, k16_19 }, \
    { k17_00, k17_01, k17_02, k17_03, k17_04, k17_05, k17_06, k17_07, k17_08, k17_09, k17_10, k17_11, k17_12, k17_13, k17_14, k17_15, k17_16, k17_17, k17_18, k17_19 }, \
    { k18_00, k18_01, k18_02, k18_03, k18_04, k18_05, k18_06, k18_07, k18_08, k18_09, k18_10, k18_11, k18_12, k18_13, k18_14, k18_15, k18_16, k18_17, k18_18, k18_19 }, \
    { k19_00, k19_01, k19_02, k19_03, k19_04, k19_05, k19_06, k19_07, k19_08, k19_09, k19_10, k19_11, k19_12, k19_13, k19_14, k19_15, k19_16, k19_17, k19_18, k19_19 }  \
}
