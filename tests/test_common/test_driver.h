/* Copyright 2017 Fred Sundvik
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

#ifndef TESTS_TEST_COMMON_TEST_DRIVER_H_
#define TESTS_TEST_COMMON_TEST_DRIVER_H_

#include "gmock/gmock.h"
#include <stdint.h>
#include "host.h"
#include "keyboard_report_util.h"


class TestDriver {
public:
    TestDriver();
    ~TestDriver();
    MOCK_METHOD0(keyboard_leds_mock, uint8_t ());
    MOCK_METHOD1(send_keyboard_mock, void (report_keyboard_t&));
    MOCK_METHOD1(send_mouse_mock, void (report_mouse_t&));
    MOCK_METHOD1(send_system_mock, void (uint16_t));
    MOCK_METHOD1(send_consumer_mock, void (uint16_t));
private:
    static uint8_t keyboard_leds(void);
    static void send_keyboard(report_keyboard_t *report);
    static void send_mouse(report_mouse_t* report);
    static void send_system(uint16_t data);
    static void send_consumer(uint16_t data);
    host_driver_t m_driver;
    static TestDriver* m_this;
};


#endif /* TESTS_TEST_COMMON_TEST_DRIVER_H_ */
