/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include "keyboard.h"

void platform_setup(void);

void protocol_setup(void);
void protocol_init(void);
void protocol_pre_task(void);
void protocol_post_task(void);

// Bodge as refactoring vusb sucks....
void protocol_task(void) __attribute__((weak));
void protocol_task(void) {
    protocol_pre_task();

    keyboard_task();

    protocol_post_task();
}

/** \brief Main
 *
 * FIXME: Needs doc
 */
int main(void) __attribute__((weak));
int main(void) {
    platform_setup();
    protocol_setup();
    keyboard_setup();

    protocol_init();
    keyboard_init();

    /* Main loop */
    while (true) {
        protocol_task();
        housekeeping_task();
    }
}
