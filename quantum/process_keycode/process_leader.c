/* Copyright 2016 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef LEADER_ENABLE

#    include "process_leader.h"
#    include <string.h>

#    ifndef LEADER_TIMEOUT
#        define LEADER_TIMEOUT 300
#    endif

#    ifndef LEADER_ABORT
#        define LEADER_ABORT KC_LEAD
#    endif

__attribute__((weak)) void leader_start(void) {}

__attribute__((weak)) void leader_end(void) {}

__attribute__((weak)) bool leader_process_user(uint16_t *leader_sequence, bool is_timeout) { return true; }

// Leader key stuff
bool     leading     = false;
uint16_t leader_time = 0;

uint16_t leader_sequence[5]   = {0, 0, 0, 0, 0};
uint8_t  leader_sequence_size = 0;

void qk_leader_start(void) {
    if (leading) {
        return;
    }
    leader_start();
    leading              = true;
    leader_time          = timer_read();
    leader_sequence_size = 0;
    memset(leader_sequence, 0, sizeof(leader_sequence));
}

void matrix_scan_leader(void) {
#    ifdef LEADER_ON_KEY_PROCESSING
    if (leading && timer_elapsed(leader_time) > LEADER_TIMEOUT) {
        leader_process_user(leader_sequence, true);
        leading = false;
        leader_end();
    }
#    endif
}

bool process_leader(uint16_t keycode, keyrecord_t *record) {
    // Leader key set-up
    if (record->event.pressed) {
        if (leading) {
            if (timer_elapsed(leader_time) < LEADER_TIMEOUT) {
#    ifndef LEADER_KEY_STRICT_KEY_PROCESSING
                if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
                    keycode = keycode & 0xFF;
                }
#    endif  // LEADER_KEY_STRICT_KEY_PROCESSING
                if (keycode == LEADER_ABORT) {
                    leading = false;
                    leader_end();
                    return false;
                }
                if (leader_sequence_size < (sizeof(leader_sequence) / sizeof(leader_sequence[0]))) {
                    leader_sequence[leader_sequence_size] = keycode;
                    leader_sequence_size++;
#    ifdef LEADER_ON_KEY_PROCESSING
                    if (!leader_process_user(leader_sequence, false)) {
                        leading = false;
                        leader_end();
                        return false;
                    }
#    endif // LEADER_ON_KEY_PROCESSING
                } else {
                    leading = false;
                    leader_end();
                }
#    ifdef LEADER_PER_KEY_TIMING
                leader_time = timer_read();
#    endif
                return false;
            }
        } else {
            if (keycode == KC_LEAD) {
                qk_leader_start();
            }
        }
    }
    return true;
}

#endif
