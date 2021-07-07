#ifndef AMJ60_H
#define AMJ60_H

#include "quantum.h"

// readability
#define XXX KC_NO

/* AMJ60 layout to the best of my knowledge matrix layout
   * ,-----------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d| 49|
   * |-----------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d |
   * |-----------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2d    |
   * |-----------------------------------------------------------|
   * | 30 | 31| 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b|  3d  |3c |
   * |-----------------------------------------------------------|
   * | 40 | 41 | 42 |        45             | 4a | 4b | 4c | 4d  |
   * `-----------------------------------------------------------'
 */
#define LAYOUT_all( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k49,\
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3c, \
    k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d}, \
    {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d}, \
    {k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, k49, k4a, k4b, k4c, k4d}  \
}

/*
   * ANSI
   * ,-----------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c|   0d  |
   * |-----------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d |
   * |-----------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2d    |
   * |-----------------------------------------------------------|
   * | 30     | 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b|   3d     |
   * |-----------------------------------------------------------|
   * | 40 | 41 | 42 |        45             | 4a | 4b | 4c | 4d  |
   * `-----------------------------------------------------------'
 */
#define LAYOUT_60_ansi( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,      k2d, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,      k3d, \
    k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, XXX, k2d}, \
    {k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, XXX, k3d}, \
    {k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, XXX, k4a, k4b, k4c, k4d}  \
}

/* AMJ60 HHKB matrix layout
   * ,------------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d| 49 |
   * |------------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d  |
   * |------------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b|   2d   |
   * |------------------------------------------------------------|
   * | 30     | 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b| 3d   | 3c |
   * |------------------------------------------------------------|
   * | 40 | 41 | 42 |        45              | 4a | 4b | 4c | 4d  |
   * `------------------------------------------------------------'
 */

#define LAYOUT_hhkb( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k49, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,      k2d, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3c, \
    k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, XXX, k2d}, \
    {k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d}, \
    {k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, k49, k4a, k4b, k4c, k4d}  \
}

/* ISO
   * ,-----------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d    |
   * |-----------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d |
   * |-----------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2c|2d |
   * |-----------------------------------------------------------|
   * | 30 | 31| 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b|   3d     |
   * |-----------------------------------------------------------|
   * | 40 | 41 | 42 |        45             | 4a | 4b | 4c | 4d  |
   * `-----------------------------------------------------------'
 */
#define LAYOUT_60_iso( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c,      \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,      k3d, \
    k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, XXX}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d}, \
    {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, XXX, k3d}, \
    {k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, XXX, k4a, k4b, k4c, k4d}  \
}

#define LAYOUT_60_ansi_split_bs_rshift( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k49,\
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,      k2d, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3c, \
    k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, XXX, k2d}, \
    {k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d}, \
    {k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, k49, k4a, k4b, k4c, k4d}  \
}

void matrix_init_user(void);
void matrix_scan_user(void);

#endif
