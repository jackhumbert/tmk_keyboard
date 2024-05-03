/* Copyright 2023 Vladislav Kucheriavykh
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

#include "keyboard_report_util.hpp"
#include "keycode.h"
#include "keycodes.h"
#include "test_common.hpp"
#include "action_tapping.h"
#include "test_keymap_key.hpp"

using testing::_;
using testing::InSequence;

class RetroTapKeyRoll : public TestFixture {};

TEST_F(RetroTapKeyRoll, retro_tap_key_roll_normal_to_left_shift) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_hold_key = KeymapKey(0, 1, 0, SFT_T(KC_P));
    auto       regular_key      = KeymapKey(0, 2, 0, KC_A);

    set_keymap({mod_tap_hold_key, regular_key});

    EXPECT_REPORT(driver, (KC_A));
    regular_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    mod_tap_hold_key.press();
    idle_for(TAPPING_TERM);
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A, KC_LEFT_SHIFT));
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    regular_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    EXPECT_REPORT(driver, (KC_P));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_hold_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(RetroTapKeyRoll, retro_tap_key_roll_normal_to_left_gui) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_hold_key = KeymapKey(0, 1, 0, LGUI_T(KC_P));
    auto       regular_key      = KeymapKey(0, 2, 0, KC_A);

    set_keymap({mod_tap_hold_key, regular_key});

    EXPECT_REPORT(driver, (KC_A));
    regular_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    mod_tap_hold_key.press();
    idle_for(TAPPING_TERM);
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A, KC_LEFT_GUI));
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LEFT_GUI));
    regular_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LGUI, DUMMY_MOD_NEUTRALIZER_KEYCODE));
    EXPECT_REPORT(driver, (KC_LEFT_GUI));
    EXPECT_EMPTY_REPORT(driver);
    EXPECT_REPORT(driver, (KC_P));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_hold_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}
TEST_F(RetroTapKeyRoll, retro_tap_key_roll_left_shift_to_left_gui) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_hold_gui   = KeymapKey(0, 1, 0, LGUI_T(KC_P));
    auto       mod_tap_hold_lshft = KeymapKey(0, 2, 0, SFT_T(KC_A));

    set_keymap({mod_tap_hold_gui, mod_tap_hold_lshft});

    EXPECT_NO_REPORT(driver);
    mod_tap_hold_lshft.press();
    idle_for(TAPPING_TERM);
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    mod_tap_hold_gui.press();
    idle_for(TAPPING_TERM);
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_LEFT_GUI));
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LEFT_GUI));
    mod_tap_hold_lshft.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LGUI, DUMMY_MOD_NEUTRALIZER_KEYCODE));
    EXPECT_REPORT(driver, (KC_LEFT_GUI));
    EXPECT_EMPTY_REPORT(driver);
    EXPECT_REPORT(driver, (KC_P, KC_LEFT_SHIFT));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_hold_gui.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}
