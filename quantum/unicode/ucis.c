// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ucis.h"
#include "unicode.h"
#include "action.h"

uint8_t count                        = 0;
bool    active                       = false;
char    input[UCIS_MAX_INPUT_LENGTH] = {0};

void ucis_start(void) {
    count  = 0;
    active = true;

    register_unicode(0x2328); // ⌨
}

bool ucis_active(void) {
    return active;
}

uint8_t ucis_count(void) {
    return count;
}

static char keycode_to_char(uint16_t keycode) {
    if (keycode >= KC_A && keycode <= KC_Z) {
        return 'a' + (keycode - KC_A);
    } else if (keycode >= KC_1 && keycode <= KC_9) {
        return '1' + (keycode - KC_1);
    } else if (keycode == KC_0) {
        return '0';
    }
    return 0;
}

bool ucis_add(uint16_t keycode) {
    char c = keycode_to_char(keycode);
    if (count < UCIS_MAX_INPUT_LENGTH - 1) {
        if (c) {
            input[count++] = c;
            input[count]   = 0;
            return true;
        }
    }
    return false;
}

bool ucis_remove_last(void) {
    if (count) {
        input[count] = 0;
        count--;
        return true;
    }

    return false;
}

static bool match_mnemonic(char *mnemonic) {
    for (uint8_t i = 0; input[i]; i++) {
        if (i > count || input[i] != mnemonic[i]) {
            return false;
        }
    }
    return true;
}

void ucis_finish(void) {
    uint8_t i     = 0;
    bool    found = false;
    for (; ucis_symbol_table[i].mnemonic; i++) {
        if (match_mnemonic(ucis_symbol_table[i].mnemonic)) {
            found = true;
            break;
        }
    }

    for (uint8_t j = 0; j <= count; j++) {
        tap_code(KC_BACKSPACE);
    }

    if (found) {
        register_ucis(i);
    }

    active = false;
}

void ucis_cancel(void) {
    for (uint8_t i = 0; i <= count; i++) {
        tap_code(KC_BACKSPACE);
    }

    count  = 0;
    active = false;
}

void register_ucis(uint8_t index) {
    const uint32_t *code_points = ucis_symbol_table[index].code_points;

    for (int i = 0; i < UCIS_MAX_CODE_POINTS && code_points[i]; i++) {
        register_unicode(code_points[i]);
    }
}
