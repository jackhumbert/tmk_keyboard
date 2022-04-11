#include "macros.h"

// Prepend key records with macros
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        handle_left_space(keycode, record);
        if (!process_dynamic(keycode, record)) {
            return false;
        }
        if (!process_static(keycode, record)) {
            return false;
        }
    }
    return true;
}
