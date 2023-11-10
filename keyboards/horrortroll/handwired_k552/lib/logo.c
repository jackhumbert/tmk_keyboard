/* Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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

#include "quantum.h"

# define ANIM_SIZE 636  // number of bytes in array, minimize for adequate firmware size, max is 1024

void render_logo(void) {
    static const char PROGMEM redragon[][ANIM_SIZE] = {
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0x80,
        0x80, 0xc0, 0xe0, 0x80, 0xc0, 0xe0, 0x30, 0x8c, 0x83, 0xc0, 0x60, 0x18, 0x04, 0x00, 0x01, 0x03,
        0x0e, 0x3e, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x10, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xf6, 0xf3, 0x31, 0xfc, 0xff, 0xff, 0x3f,
        0x9f, 0x5f, 0x5f, 0x5f, 0xcf, 0xcf, 0xcf, 0xcb, 0xc9, 0x8c, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xe0, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xf0, 0xe0, 0x60, 0x60, 0xc0, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x40, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0xf0, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x03, 0xcf, 0xff, 0x0c,
        0x02, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xf9, 0xff, 0xff, 0xff, 0xff, 0x1c, 0x00, 0x00, 0x00, 0x00,
        0x03, 0xfe, 0xf8, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x3f, 0x7f, 0xff, 0xff,
        0xfc, 0x80, 0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 0xff, 0xff, 0x20, 0x60, 0xd9, 0x9f, 0x0f, 0x00,
        0x01, 0xff, 0xff, 0x23, 0x21, 0x21, 0x73, 0x00, 0xff, 0xff, 0x03, 0x22, 0x1e, 0xfc, 0xf8, 0x41,
        0xff, 0xff, 0xe3, 0xb2, 0x3e, 0x1c, 0x00, 0xe0, 0xfe, 0x7f, 0x43, 0x4f, 0x7d, 0xf0, 0x80, 0x70,
        0xfc, 0x9e, 0x22, 0x03, 0x43, 0x43, 0xc6, 0xcc, 0x80, 0x78, 0xfc, 0x06, 0x23, 0x22, 0x06, 0x9c,
        0xf8, 0x40, 0x20, 0xff, 0xff, 0xff, 0x07, 0x1f, 0x7c, 0xf8, 0xe0, 0xff, 0xff, 0xff, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf1, 0xf9, 0xfd, 0xff, 0xfe,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x97, 0x87, 0xc1, 0xe3, 0xf0, 0x78, 0x7e, 0x7f, 0x38,
        0x3e, 0x3f, 0x9f, 0x6f, 0x3f, 0x1f, 0x07, 0x00, 0x03, 0x7f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x03,
        0x0f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0e, 0x0f, 0x0f, 0x08, 0x00, 0x01, 0x03, 0x0f, 0x1e,
        0x3c, 0x77, 0x67, 0x44, 0x04, 0x04, 0x04, 0x02, 0x07, 0x07, 0x06, 0x06, 0x03, 0x03, 0x01, 0x04,
        0x07, 0x07, 0x00, 0x03, 0x07, 0x04, 0x06, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x06,
        0x05, 0x03, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x00, 0x00, 0x03, 0x07, 0x06, 0x06, 0x06, 0x07,
        0x01, 0x00, 0x04, 0x07, 0x07, 0x07, 0x04, 0x00, 0x00, 0x01, 0x03, 0x0f, 0x3f, 0xff, 0x00, 0x00
        }
    };

    oled_write_raw_P(redragon[0], ANIM_SIZE);
}
