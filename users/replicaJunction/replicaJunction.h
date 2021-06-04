#pragma once
#include QMK_KEYBOARD_H
#include "rj_keycodes.h"
#include "keycode_aliases.h"
#include "version.h"

#ifdef USER_CAPS_WORD_ENABLE
#    include "features/caps_word.h"
#endif

#ifdef USER_SUPER_ALT_TAB_ENABLE
#    include "features/super_alt_tab.h"
#endif
