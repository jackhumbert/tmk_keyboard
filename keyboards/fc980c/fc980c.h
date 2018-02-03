/*
Copyright 2017 Balz Guenat

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
#ifndef FC980C_H
#define FC980C_H

#include "quantum.h"
// #include "quantum_keycodes.h"

/*
----------------------------------------------------------------------------------------------------------------------
| K0D |     | K2D | K5D | K3D | K6D |  | K7D | K7F | K7E | K7C |  | K72 | K71 | K70 | K73 |  | K74 | K76 | K77 | K75 |
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
| K0A | K69 | K59 | K58 | K5B | K6F | K5F | K5E | K6C | K5C | K52 | K51 | K50 |    K55    |  | K54 | K56 | K57 | K65 |
----------------------------------------------------------------------------------------------------------------------
|  K6A   | K39 | K68 | K6B | K3B | K3F | K6E | K3E | K3C | K62 | K61 | K60 | K33 |  K53   |  | K64 | K66 | K67 |     |
---------------------------------------------------------------------------------------------------------------| K25 |
|   K3A   | K29 | K38 | K28 | K2B | K2F | K2E | K2C | K1C | K32 | K31 | K20 |     K63     |  | K24 | K26 | K27 |     |
----------------------------------------------------------------------------------------------------------------------
|     K2A    | K18 | K08 | K1B | K0B | K1F | K1E | K0E | K22 | K11 | K21 |    K30    || K34 || K14 | K16 | K17 |     |
---------------------------------------------------------------------------------------------------------------| K15 |
| K1A  | K09 | K19  |                   K0F                | K02  | K01 | K10  || K00 | K04 | K06 || K07 | K05 |     |
----------------------------------------------------------------------------------------------------------------------
*/

#define KEYMAP(                                                                           \
    K0D,    K2D,K5D,K3D,K6D,K7D,K7F,K7E,K7C,K72,K71,K70,K73,             K74,K76,K77,K75, \
    K0A,K69,K59,K58,K5B,K6F,K5F,K5E,K6C,K5C,K52,K51,K50,K55,             K54,K56,K57,K65, \
    K6A,K39,K68,K6B,K3B,K3F,K6E,K3E,K3C,K62,K61,K60,K33,K53,             K64,K66,K67,K25, \
    K3A,K29,K38,K28,K2B,K2F,K2E,K2C,K1C,K32,K31,K20,    K63,             K24,K26,K27,     \
    K2A,    K18,K08,K1B,K0B,K1F,K1E,K0E,K22,K11,K21,    K30,     K34,    K14,K16,K17,K15, \
    K1A,K09,K19,            K0F,                K02,K01,K10, K00,K04,K06,    K07,K05      \
) {                                                                                       \
    { K00,  K01,  K02,  KC_NO,K04,  K05,  K06,  K07   ,  \
      K08,  K09,  K0A,  K0B,  KC_NO,K0D,  K0E,  K0F   }, \
    { K10,  K11,  KC_NO,KC_NO,K14,  K15,  K16,  K17   ,  \
      K18,  K19,  K1A,  K1B,  K1C,  KC_NO,K1E,  K1F   }, \
    { K20,  K21,  K22,  KC_NO,K24,  K25,  K26,  K27   ,  \
      K28,  K29,  K2A,  K2B,  K2C,  K2D,  K2E,  K2F   }, \
    { K30,  K31,  K32,  K33,  K34,  KC_NO,KC_NO,KC_NO ,  \
      K38,  K39,  K3A,  K3B,  K3C,  K3D,  K3E,  K3F   }, \
    { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO ,  \
      KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO }, \
    { K50,  K51,  K52,  K53,  K54,  K55,  K56,  K57   ,  \
      K58,  K59,  KC_NO,K5B,  K5C,  K5D,  K5E,  K5F   }, \
    { K60,  K61,  K62,  K63,  K64,  K65,  K66,  K67   ,  \
      K68,  K69,  K6A,  K6B,  K6C,  K6D,  K6E,  K6F   }, \
    { K70,  K71,  K72,  K73,  K74,  K75,  K76,  K77   ,  \
      KC_NO,KC_NO,KC_NO,KC_NO,K7C,  K7D,  K7E,  K7F   }  \
}
/*
KEYMAP(
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,                         _______,_______,_______,    
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,         _______,        _______,_______,_______,_______,
    _______,_______,_______,                           _______,                             _______,_______,_______, _______,_______,_______,        _______,_______     
)
*/

#endif
