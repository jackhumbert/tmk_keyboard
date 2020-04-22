#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_base_kit_all( \
    k01,  k02, k03, k04, k05, k06, k07, k08, k09, k010, k011, k012, k013, k014, \
    k11,  k12, k13, k14, k15, k16, k17, k18, k19, k110, k111, k112, k113, k114, \
    k21,  k22, k23, k24, k25, k26, k27, k28, k29, k210, k211, k212, k213, k214, \
    k31,     k32,   k33,    k34,      k36, k38,    k310, k311,   k313,   k314   \
) \
{ \
    { k01, k02, k03, k04, k05, k06, k07, k08, k09, k010, k011, k012, k013, k014 }, \
    { k11, k12, k13, k14, k15, k16, k17, k18, k19, k110, k111, k112, k113, k114 }, \
    { k21, k22, k23, k24, k25, k26, k27, k28, k29, k210, k211, k212, k213, k214 }, \
    { k31, k32, k33, k34, XXX, k36, XXX, k38, XXX, k310, k311, XXX,  k313, k314 }  \
}
   