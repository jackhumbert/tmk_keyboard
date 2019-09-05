#pragma once

#include "quantum.h" 

enum keycodes {
	QWERTY = SAFE_RANGE,
	DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define ____ KC_NO

/* Every possible switch positions on the PCB. Depending on plate and keycap choice, some of these positions will be blocked by other keys. */
#define LAYOUT_all( \
	K101, K102,   K103,       K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,   K117, K118, K119,   K120, K121, K122, K123, \
	K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
	K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316,   K317, K318, K319,   K320, K321, K322, K323, \
	K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, K415, K416,   K417, K418, K419,   K420, K421, K422, K423, \
	K501, K502,   K503, K504, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523, \
	K601, K602,   K603, K604, K605,                         K610,             K613, K614, K615, K616,   K617, K618, K619,   K620,       K622        \
) { \
 	{ K101, K102,   K103, ____, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,   K117, K118, K119,   K120, K121, K122, K123 }, \
	{ K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, K415, K416,   K417, K418, K419,   K420, K421, K422, K423 }, \
	{ K501, K502,   K503, K504, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523 }, \
	{ K601, K602,   K603, K604, K605, ____, ____, ____, ____, K610, ____, ____, K613, K614, K615, K616,   K617, K618, K619,   K620, ____, K622, ____ } \
}

/* Northgate Factory Plates. Most are based on internet research, user beware. */ 
#define LAYOUT_101( \
					K103,       K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,   K117, K118, K119, \
					K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
					K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316,   K317, K318, K319,   K320, K321, K322, K323, \
					K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,    K416,                          K420, K421, K422,       \
					K503,       K505, K506, K507, K508, K509, K510, K511, K512, K513, K514,    K515,            K518,         K520, K521, K522, K523, \
					K603,       K605,                               K610,       K613,             K616,   K617, K618, K619,   K620,       K622  \
) { \
	{ ____, ____,   K103, ____, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,   K117, K118, K119,   ____, ____, ____, ____ }, \
	{ ____, ____,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ ____, ____,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ ____, ____,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, ____, K416,   ____, ____, ____,   K420, K421, K422, ____ }, \
	{ ____, ____,   K503, ____, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, ____,   ____, K518, ____,   K520, K521, K522, K523 }, \
	{ ____, ____,   K603, ____, K605, ____, ____, ____, ____, K610, ____, ____, K613, ____, ____, K616,   K617, K618, K619,   K620, ____, K622, ____ } \
}

#define LAYOUT_102_rev1( \
	K101, K102,              																			K117, K118, K119, \
	K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
	K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315,         K317, K318, K319,   K320, K321, K322, K323, \
	K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,    K416,                          K420, K421, K422, K423, \
	K501, K502,   K503,       K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,         K518,         K520, K521, K522, K523, \
	K601, K602,   K603, K604, K605,                         K610,             K613, K614,       K616,   K617, K618, K619,   K620,       K622  \
) { \
 	{ K101, K102,   ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,   K117, K118, K119,   ____, ____, ____, ____ }, \
	{ K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, ____,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, ____, K416,   ____, ____, ____,   K420, K421, K422, K423 }, \
	{ K501, K502,   K503, ____, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   ____, K518, ____,   K520, K521, K522, K523 }, \
	{ K601, K602,   K603, K604, K605, ____, ____, ____, ____, K610, ____, ____, K613, K614, ____, K616,   K617, K618, K619,   K620, ____, K622, ____ } \
}

#define LAYOUT_102_rev3( \
	K101, K102,   K103,       																			K117, K118, K119, \
	K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
	K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315,         K317, K318, K319,   K320, K321, K322, K323, \
	K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,    K416,                          K420, K421, K422, K423, \
	K501, K502,   K503,       K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,         K518,         K520, K521, K522, K523, \
	K601, K602,   K603, K604, K605,                         K610,             K613, K614,       K616,   K617, K618, K619,   K620,       K622  \
) { \
 	{ K101, K102,   K103, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,   K117, K118, K119,   ____, ____, ____, ____ }, \
	{ K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, ____,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, ____, K416,   ____, ____, ____,   K420, K421, K422, K423 }, \
	{ K501, K502,   K503, ____, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   ____, K518, ____,   K520, K521, K522, K523 }, \
	{ K601, K602,   K603, K604, K605, ____, ____, ____, ____, K610, ____, ____, K613, K614, ____, K616,   K617, K618, K619,   K620, ____, K622, ____ } \
}

#define LAYOUT_plus_rev1( \
	K101, K102,              																			K117, K118, K119, \
	K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
	K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315,         K317, K318, K319,   K320, K321, K322, K323, \
	K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,    K416,      K417, K418, K419,   K420, K421, K422, K423, \
	K501, K502,   K503,       K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523, \
	K601, K602,   K603, K604, K605,                         K610,             K613, K614,       K616,      K617, K619,      K620,       K622  \
) { \
 	{ K101, K102,   ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,   K117, K118, K119,   ____, ____, ____, ____ }, \
	{ K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, ____,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, ____, K416,   K417, K418, K419,   K420, K421, K422, K423 }, \
	{ K501, K502,   K503, ____, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523 }, \
	{ K601, K602,   K603, K604, K605, ____, ____, ____, ____, K610, ____, ____, K613, K614, ____, K616,   K617, ____, K619,   K620, ____, K622, ____ } \
}

#define LAYOUT_plus_rev3( \
	K101, K102,   K103,       																			K117, K118, K119, \
	K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
	K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315,         K317, K318, K319,   K320, K321, K322, K323, \
	K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,    K416,      K417, K418, K419,   K420, K421, K422, K423, \
	K501, K502,   K503,       K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523, \
	K601, K602,   K603, K604, K605,                         K610,             K613, K614,       K616,      K617, K619,      K620,       K622  \
) { \
 	{ K101, K102,   K103, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,   K117, K118, K119,   ____, ____, ____, ____ }, \
	{ K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, ____,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, ____, K416,   K417, K418, K419,   K420, K421, K422, K423 }, \
	{ K501, K502,   K503, ____, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523 }, \
	{ K601, K602,   K603, K604, K605, ____, ____, ____, ____, K610, ____, ____, K613, K614, ____, K616,   K617, ____, K619,   K620, ____, K622, ____ } \
}

#define LAYOUT_ultra_rev1( \
	K101, K102,               K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,	K117, K118, K119, \
	K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
	K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315,         K317, K318, K319,   K320, K321, K322, K323, \
	K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,    K416,      K417, K418, K419,   K420, K421, K422, K423, \
	K501, K502,   K503,       K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523, \
	K601, K602,   K603, K604, K605,                         K610,             K613, K614,       K616,      K617, K619,      K620,       K622  \
) { \
 	{ K101, K102,   ____, ____, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,   K117, K118, K119,   ____, ____, ____, ____ }, \
	{ K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, ____,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, ____, K416,   K417, K418, K419,   K420, K421, K422, K423 }, \
	{ K501, K502,   K503, ____, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523 }, \
	{ K601, K602,   K603, K604, K605, ____, ____, ____, ____, K610, ____, ____, K613, K614, ____, K616,   K617, ____, K619,   K620, ____, K622, ____ } \
}

#define LAYOUT_ultra_rev3( \
	K101, K102,   K103,       K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,	K117, K118, K119, \
	K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
	K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315,         K317, K318, K319,   K320, K321, K322, K323, \
	K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,    K416,      K417, K418, K419,   K420, K421, K422, K423, \
	K501, K502,   K503,       K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523, \
	K601, K602,   K603, K604, K605,                         K610,             K613, K614,       K616,      K617, K619,      K620,       K622  \
) { \
 	{ K101, K102,   K103, ____, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,   K117, K118, K119,   ____, ____, ____, ____ }, \
	{ K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, ____,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, ____, K416,   K417, K418, K419,   K420, K421, K422, K423 }, \
	{ K501, K502,   K503, ____, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   K517, K518, K519,   K520, K521, K522, K523 }, \
	{ K601, K602,   K603, K604, K605, ____, ____, ____, ____, K610, ____, ____, K613, K614, ____, K616,   K617, ____, K619,   K620, ____, K622, ____ } \
}

#define LAYOUT_ultra_t( \
	K101, K102,   K103,       K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,   K117, K118, K119, \
	K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223, \
	K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315,         K317, K318, K319,   K320, K321, K322, K323, \
	K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,    K416,                          K420, K421, K422, K423, \
	K501, K502,   K503,       K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,         K518,         K520, K521, K522, K523, \
	K601, K602,   K603, K604, K605,                         K610,             K613, K614,       K616,   K617, K618, K619,   K620,       K622  \
) { \
 	{ K101, K102,   K103, ____, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,   K117, K118, K119,   ____, ____, ____, ____ }, \
	{ K201, K202,   K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,   K217, K218, K219,   K220, K221, K222, K223 }, \
	{ K301, K302,   K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, ____,   K317, K318, K319,   K320, K321, K322, K323 }, \
	{ K401, K402,   K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, ____, K416,   ____, ____, ____,   K420, K421, K422, K423 }, \
	{ K501, K502,   K503, ____, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,   ____, K518, ____,   K520, K521, K522, K523 }, \
	{ K601, K602,   K603, K604, K605, ____, ____, ____, ____, K610, ____, ____, K613, K614, ____, K616,   K617, K618, K619,   K620, ____, K622, ____ } \
}

