
#include "unicode.h"

const uint32_t PROGMEM unicode_map[] = {
    [BUL1]		= 0x2022, // •
    [BUL2]		= 0x25E6, // ◦
    [LARR]		= 0x2190, // ←
    [RARR]		= 0x2192, // →
    [ENDASH]	= 0x2013, // –
    [EMDASH]	= 0x2014, // —
};

void matrix_init_user_unicode(void)
{
  set_unicode_input_mode(UC_LNX); // For now, hard-code to Linux style unicode entry
}


