#pragma once

#include "quantum.h"

#define ___ KC_NO

/* ALL: This is an odd layout that the JSON file comes preloaded with. Split left-shift and ansi enter
 * ,------.   ,-------------------------------------------------------------------------------------------------.
 * |      |   |       |     |     |     |     |     |     |     |     |     |     |     |     |           |     |
 * |------|   |-------------------------------------------------------------------------------------------------|
   |      |   |        |     |     |     |     |     |     |     |     |     |     |     |     |          |     |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |      |   |         |     |     |     |     |     |     |     |     |     |     |     |               |     |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |      |   |      |    |     |     |     |     |     |     |     |     |     |     |             |     |     |
 * |------|   |-------------------------------------------------------------------------------------------------|
 * |      |   |      |       |       |                                   |      |      |     |      |     |     |
 * `------'   `-------------------------------------------------------------------------------------------------'
 */

#define LAYOUT_all( \
    K0F,  K00,  K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K4E,  \
    K1F,  K10,  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K2C,      K1E,  \
    K2F,  K20,  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K1D,           K2E,  \
    K3F,  K30,  K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,      K3D, K3E,  \
    K4F,  K40,  K41, K42,                K46,                K48, K49, K4A, K4B, K4C, K4D   \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   ___,   K2E,   K2F   }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   K3F   }, \
    { K40,   K41,   K42,   ___,   ___,   ___,   K46,   ___,   K48,   K49,   K4A,   K4B,   K4C,   K4D,   K4E,   K4F   }  \
}

/* ANSI
 * ,---.   ,---------------------------------------------------------------.
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |       |   |
 * |---|   |---------------------------------------------------------------|
 * |   |   |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
 * |---|   |---------------------------------------------------------------|
 * |   |   |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
 * |---|   |---------------------------------------------------------------|
 * |   |   |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
 * |---|   |---------------------------------------------------------------|
 * |   |   |    |    |    |                        |   |   |   |   |   |   |
 * `---'   `---------------------------------------------------------------'
 */

#define LAYOUT_ansi_1u( \
    K0F,  K00,  K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C,    K0E,   K4E,  \
    K1F,  K10,  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K2C,      K1E,  \
    K2F,  K20,  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K1D,           K2E,  \
    K3F,    K30,     K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,      K3D, K3E,  \
    K4F,  K40,  K41, K42,                K46,                K48, K49, K4A, K4B, K4C, K4D   \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   ___,   K0E,   K0F   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   ___,   K2E,   K2F   }, \
    { K30,   ___,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   K3F   }, \
    { K40,   K41,   K42,   ___,   ___,   ___,   K46,   ___,   K48,   K49,   K4A,   K4B,   K4C,   K4D,   K4E,   K4F   }  \
}
