/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
Copyright 2017 Erin Call <hello@erincall.com>
Copyright 2024 Adam Coleman <gephorian@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "wait.h"
#include "action_layer.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "i2c_master.h"
#include "timer.h"

#define I2C_TIMEOUT 100

#define I2C_ADDR        (0b0100000<<1)
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13

void init_expander(void);

/* Set 0 if debouncing isn't needed */

#ifndef DEBOUNCE
#   define DEBOUNCE 5
#endif

#if (DEBOUNCE > 0)
    static uint16_t debouncing_time;
    static bool debouncing = false;
#endif

#ifdef MATRIX_MASKED
    extern const matrix_row_t matrix_mask[];
#endif

#if (DIODE_DIRECTION == ROW2COL) || (DIODE_DIRECTION == COL2ROW)
static const uint8_t onboard_row_pins[MATRIX_ROWS] = MATRIX_ONBOARD_ROW_PINS;
static const uint8_t onboard_col_pins[MATRIX_COLS] = MATRIX_ONBOARD_COL_PINS;
static const bool col_expanded[MATRIX_COLS] = COL_EXPANDED;
#endif

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

static matrix_row_t matrix_debouncing[MATRIX_ROWS];

#if (DIODE_DIRECTION == COL2ROW)
    static const uint8_t expander_col_pins[MATRIX_COLS] = MATRIX_EXPANDER_COL_PINS;
    static void init_cols(void);
    static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row);
    static void unselect_rows(void);
    static void select_row(uint8_t row);
    static void unselect_row(uint8_t row);
#elif (DIODE_DIRECTION == ROW2COL)
    static const uint8_t expander_row_pins[MATRIX_ROWS] = MATRIX_EXPANDER_ROW_PINS;
    static void init_rows(void);
    static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col);
    static void unselect_cols(void);
    static void select_col(uint8_t col);
    static void unselect_col(uint8_t col);
#endif

static uint8_t expander_reset_loop;
uint8_t expander_status;
uint8_t expander_input_pin_mask;
bool i2c_initialized = false;

__attribute__ ((weak))
void matrix_init_user(void) {}

__attribute__ ((weak))
void matrix_scan_user(void) {}

__attribute__ ((weak))
void matrix_init_kb(void) {
  matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
  matrix_scan_user();
}

void matrix_init_custom(void)
{
    init_expander();

#if (DIODE_DIRECTION == COL2ROW)
    unselect_rows();
    init_cols();
#elif (DIODE_DIRECTION == ROW2COL)
    unselect_cols();
    init_rows();
#endif

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }

    matrix_init_kb();
}

void init_expander(void) {
    if (! i2c_initialized) {
        i2c_init();
        wait_ms(1000);
    }

    if (! expander_input_pin_mask) {
#if (DIODE_DIRECTION == COL2ROW)
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (col_expanded[col]) {
                expander_input_pin_mask |= (1 << expander_col_pins[col]);
            }
        }
#elif (DIODE_DIRECTION == ROW2COL)
        for (int row = 0; row < MATRIX_ROWS; row++) {
            expander_input_pin_mask |= (1 << expander_row_pins[row]);
        }
#endif
    }

    /*
    Pin direction and pull-up depends on both the diode direction
    and on whether the column register is GPIOA or GPIOB
    +-------+---------------+---------------+
    |       | ROW2COL       | COL2ROW       |
    +-------+---------------+---------------+
    | GPIOA | input, output | output, input |
    +-------+---------------+---------------+
    | GPIOB | output, input | input, output |
    +-------+---------------+---------------+
    */

#if (EXPANDER_COL_REGISTER == GPIOA)
#   if (DIODE_DIRECTION == COL2ROW)
    uint8_t data[] = { expander_input_pin_mask, 0};
#   elif (DIODE_DIRECTION == ROW2COL)
    uint8_t data[] = { 0, expander_input_pin_mask};
#   endif
#elif (EXPANDER_COL_REGISTER == GPIOB)
#   if (DIODE_DIRECTION == COL2ROW)
    uint8_t data[] = { 0, expander_input_pin_mask};
#   elif (DIODE_DIRECTION == ROW2COL)
    uint8_t data[] = { expander_input_pin_mask, 0};
#   endif
#endif
    expander_status = i2c_writeReg(I2C_ADDR, IODIRA, data, sizeof(data), I2C_TIMEOUT);

    if (!expander_status) {
        // set pull-up
        // - unused  : off : 0
        // - input   : on  : 1
        // - driving : off : 0
        expander_status = i2c_writeReg(I2C_ADDR, GPPUA, data, sizeof(data), I2C_TIMEOUT);
    }

}

bool matrix_scan_custom(matrix_row_t current_matrix[])
{
    bool matrix_changed = false;
    if (expander_status) { // if there was an error
        if (++expander_reset_loop == 0) {
            // since expander_reset_loop is 8 bit - we'll try to reset once in 255 matrix scans
            // this will be approx bit more frequent than once per second
            print("trying to reset expander\n");
            init_expander();
            if (expander_status) {
                print("left side not responding\n");
            } else {
                print("left side attached\n");
            }
        }
    }

#if (DIODE_DIRECTION == COL2ROW)
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
#       if (DEBOUNCE > 0)
            matrix_changed = read_cols_on_row(matrix_debouncing, current_row);

            if (matrix_changed) {
                debouncing = true;
                debouncing_time = timer_read();
            }
#       else
            read_cols_on_row(matrix, current_row);
#       endif
    }

#elif (DIODE_DIRECTION == ROW2COL)
    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++) {
#       if (DEBOUNCE > 0)
            matrix_changed = read_rows_on_col(matrix_debouncing, current_col);

            if (matrix_changed) {
                debouncing = true;
                debouncing_time = timer_read();
            }
#       else
            read_rows_on_col(matrix, current_col);
#       endif

    }
#endif

#   if (DEBOUNCE > 0)
        if (debouncing && (timer_elapsed(debouncing_time) > DEBOUNCE)) {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
            debouncing = false;
        }
#   endif

    return matrix_changed;
}

#if (DIODE_DIRECTION == COL2ROW)

static void init_cols(void) {
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        if (! col_expanded[x]) {
            uint8_t pin = onboard_col_pins[x];
            _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // IN
            _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // HI
        }
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selection to stabilize
    select_row(current_row);
    wait_us(30);

    // Read columns from expander, unless it's in an error state
    if (! expander_status) {
        uint8_t data;
        i2c_readReg(I2C_ADDR, EXPANDER_COL_REGISTER, &data, 1, I2C_TIMEOUT);
        current_matrix[current_row] |= (~data) & expander_input_pin_mask;
    }

    // Read columns from onboard pins
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        if (! col_expanded[col_index]) {
            uint8_t pin = onboard_col_pins[col_index];
            uint8_t pin_state = (_SFR_IO8(pin >> 4) & _BV(pin & 0xF));
            current_matrix[current_row] |= pin_state ? 0 : (((matrix_row_t)1) << col_index);
        }
    }

    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

static void select_row(uint8_t row) {
    // select on expander, unless it's in an error state
    if (! expander_status) {
        // set active row low  : 0
        // set other rows hi-Z : 1
        uint8_t data = 0xFF & ~(1<<row);
        i2c_writeReg(I2C_ADDR, EXPANDER_ROW_REGISTER, &data, 1, I2C_TIMEOUT);
    }

    // select on teensy
    uint8_t pin = onboard_row_pins[row];
    _SFR_IO8((pin >> 4) + 1) |=  _BV(pin & 0xF); // OUT
    _SFR_IO8((pin >> 4) + 2) &= ~_BV(pin & 0xF); // LOW
}

static void unselect_row(uint8_t row)
{
    // No need to explicitly unselect expander pins--their I/O state is
    // set simultaneously, with a single bitmask sent to i2c_write. When
    // select_row selects a single pin, it implicitly unselects all the
    // other ones.

    // unselect on teensy
    uint8_t pin = onboard_row_pins[row];
    _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // OUT
    _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // LOW
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        unselect_row(x);
    }
}

#elif (DIODE_DIRECTION == ROW2COL)

static void init_rows(void)
{
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        uint8_t pin = onboard_row_pins[x];
        _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // IN
        _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // HI
    }
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col)
{
    bool matrix_changed = false;

    uint8_t column_state = 0;

    //select col and wait for selection to stabilize
    select_col(current_col);
    wait_us(30);

    if (current_col < 6) {
        // read rows from expander
        if (expander_status) {
            // it's already in an error state; nothing we can do
            return false;
        }

        i2c_writeReg(I2C_ADDR, EXPANDER_ROW_REGISTER, &column_state, 1, I2C_TIMEOUT);
        column_state = ~column_state;
    } else {
        for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
            if ((_SFR_IO8(onboard_row_pins[current_row] >> 4) & _BV(onboard_row_pins[current_row] & 0xF)) == 0) {
                column_state |= (1 << current_row);
            }
        }
    }

    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        // Store last value of row prior to reading
        matrix_row_t last_row_value = current_matrix[current_row];

        if (column_state & (1 << current_row)) {
            // key closed; set state bit in matrix
            current_matrix[current_row] |= (((matrix_row_t)1) << current_col);
        } else {
            // key open; clear state bit in matrix
            current_matrix[current_row] &= ~(((matrix_row_t)1) << current_col);
        }

        // Determine whether the matrix changed state
        if ((last_row_value != current_matrix[current_row]) && !(matrix_changed))
        {
            matrix_changed = true;
        }
    }

    unselect_col(current_col);

    return matrix_changed;
}

static void select_col(uint8_t col)
{
    if (col_expanded[col]) {
        /* // select on expander */
        /* if (expander_status) { // if there was an error */
            /* // do nothing */
        /* } else { */
            /* // set active col low  : 0 */
            /* // set other cols hi-Z : 1 */
            /* expander_status = i2c_start(I2C_ADDR_WRITE);          if (expander_status) goto out; */
            /* expander_status = i2c_write(EXPANDER_COL_REGISTER);   if (expander_status) goto out; */
            /* expander_status = i2c_write(0xFF & ~(1<<col));        if (expander_status) goto out; */
        /* out: */
            /* i2c_stop(); */
        /* } */

        if (! expander_status) {
            // set active row low  : 0
            // set other rows hi-Z : 1
            uint8_t data = 0xFF & ~(1<<col);
            i2c_writeReg(I2C_ADDR, EXPANDER_ROW_REGISTER, &data, 1, I2C_TIMEOUT);
        }

    } else {
        // select on teensy
        uint8_t pin = onboard_col_pins[col];
        _SFR_IO8((pin >> 4) + 1) |=  _BV(pin & 0xF); // OUT
        _SFR_IO8((pin >> 4) + 2) &= ~_BV(pin & 0xF); // LOW
    }
}

static void unselect_col(uint8_t col)
{
    if (col_expanded[col]) {
        // No need to explicitly unselect expander pins--their I/O state is
        // set simultaneously, with a single bitmask sent to i2c_write. When
        // select_col selects a single pin, it implicitly unselects all the
        // other ones.
    } else {
        // unselect on teensy
        uint8_t pin = onboard_col_pins[col];
        _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // IN
        _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // HI
    }
}

static void unselect_cols(void)
{
    for(uint8_t x = 0; x < MATRIX_COLS; x++) {
        unselect_col(x);
    }
}
#endif
