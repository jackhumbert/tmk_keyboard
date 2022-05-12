// Copyright 2022 Jean Bernard (@jn-bernard)
// SPDX-License-Identifier: GPL-2.0-or-later

##pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
#define NO_DEBUG

/* disable print */
#define NO_PRINT

//#define DEBUG_MATRIX_SCAN_RATE
#define BOOTMAGIC_LITE_ROW 4
#define BOOTMAGIC_LITE_COLUMN 13

/* disable action features */
#define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 18
