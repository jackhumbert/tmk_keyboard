#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_5x6_5( \
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
              L42, L43,      L44, L55, L53,      R52, R50, R41,      R42, R43, \
                                  L54, L52,      R53, R51 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { XXX, XXX, L42, L43, L44, XXX }, \
    { XXX, XXX, L52, L53, L54, L55 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { XXX, R41, R42, R43, XXX, XXX }, \
    { R50, R51, R52, R53, XXX, XXX } \
}

#define LAYOUT_split_3x5_3( \
    L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, \
    L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, \
    L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, \
                        L44, L55, L53,      R52, R50, R41 \
) { \
    { XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, L11, L12, L13, L14, L15 }, \
    { XXX, L21, L22, L23, L24, L25 }, \
    { XXX, L31, L32, L33, L34, L35 }, \
    { XXX, XXX, XXX, XXX, L44, XXX }, \
    { XXX, XXX, XXX, L53, XXX, L55 }, \
\
    { XXX, XXX, XXX, XXX, XXX, XXX }, \
    { R10, R11, R12, R13, R14, XXX }, \
    { R20, R21, R22, R23, R24, XXX }, \
    { R30, R31, R32, R33, R34, XXX }, \
    { XXX, R41, XXX, XXX, XXX, XXX }, \
    { R50, XXX, R52, XXX, XXX, XXX } \
}