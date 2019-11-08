#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, \
	      K011, K012, K013, K014, K015, K016, K017,       \
	K020, K021, K022, K023, K024, K025, K026, K027, K028, \
	K030, K031, K032, K033, K034, K035, K036, K037,       \
	K040, K041, K042, K043, K044, K045, K046, K047, K048, \
	K050, K051, K052, K053, K054, K055, K056, K057,       \
	K060, K061, K062, K063, K064, K065, K066,             \
	K070, K071, K072, K073, K074, K075, K076,             \
	K080, K081, K082, K083, K084, K085, K086,             \
	K090, K091, K092, K093, K094, K095, K096, K097,       \
	K100, K101,       K103,             K106, K107, K108, \
	K110,       K112,       K114, K115, K116, K117  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008 }, \
	{ KC_NO, K011,  K012,  K013,  K014,  K015,  K016,  K017,  KC_NO }, \
	{ K020,  K021,  K022,  K023,  K024,  K025,  K026,  K027,  K028 }, \
	{ K030,  K031,  K032,  K033,  K034,  K035,  K036,  K037,  KC_NO }, \
	{ K040,  K041,  K042,  K043,  K044,  K045,  K046,  K047,  K048 }, \
	{ K050,  K051,  K052,  K053,  K054,  K055,  K056,  K057,  KC_NO }, \
	{ K060,  K061,  K062,  K063,  K064,  K065,  K066,  KC_NO, KC_NO }, \
	{ K070,  K071,  K072,  K073,  K074,  K075,  K076,  KC_NO, KC_NO }, \
	{ K080,  K081,  K082,  K083,  K084,  K085,  K086,  KC_NO, KC_NO }, \
	{ K090,  K091,  K092,  K093,  K094,  K095,  K096,  K097,  KC_NO }, \
	{ K100,  K101,  KC_NO, K103,  KC_NO, KC_NO, K106,  K107,  K108 }, \
	{ K110,  KC_NO, K112,  KC_NO, K114,  K115,  K116,  K117,  KC_NO }  \
}

#endif