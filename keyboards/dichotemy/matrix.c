/*
Copyright 2012 Jun Wako
Copyright 2014 Jack Humbert

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
#if defined(__AVR__)
#include <avr/io.h>
#endif
#include "wait.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "timer.h"

#if (MATRIX_COLS <= 8)
#    define print_matrix_header()  print("\nr/c 01234567\n")
#    define print_matrix_row(row)  print_bin_reverse8(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop(matrix[i])
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse16(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop16(matrix[i])
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse32(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop32(matrix[i])
#    define ROW_SHIFTER  ((uint32_t)1)
#endif

#define MAIN_ROWMASK 0xFFF0;
#deinfe LOWER_ROWMASK 0x1F80;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

__attribute__ ((weak))
void matrix_init_quantum(void) {
    matrix_init_kb();
}

__attribute__ ((weak))
void matrix_scan_quantum(void) {
    matrix_scan_kb();
}

__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

inline
uint8_t matrix_rows(void) {
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void) {
    return MATRIX_COLS;
}

void matrix_init(void) {

    matrix_init_quantum();
}

uint8_t matrix_scan(void)
{
    SERIAL_UART_INIT();

    uint32_t timeout = 0;

    //the s character requests the RF slave to send the matrix
    SERIAL_UART_DATA = 's';

    //trust the external keystates entirely, erase the last data
    uint8_t uart_data[7] = {0};

    //there are 10 bytes corresponding to 10 columns, and an end byte
    for (uint8_t i = 0; i < 7; i++) {
        //wait for the serial data, timeout if it's been too long
        //this only happened in testing with a loose wire, but does no
        //harm to leave it in here
        while(!SERIAL_UART_RXD_PRESENT){
            timeout++;
            if (timeout > 10000){
                break;
            }
        } 
        uart_data[i] = SERIAL_UART_DATA;
    }

    //check for the end packet, the key state bytes use the LSBs, so 0xE0
    //will only show up here if the correct bytes were recieved
    if (uart_data[6] == 0x96) { //this is an arbitrary binary checksum (10010110)
        //shifting and transferring the keystates to the QMK matrix variable
		//bits 1-12 are row 1, 13-24 are row 2, 25-36 are row 3,
		//bits 37-42 are row 4 (only 6 wide, 1-3 are 0, and 10-12 are 0)
		//bits 43-48 are row 5 (same as row 4)
		/* ASSUMING MSB FIRST */
		matrix[0] = (uint16_t) uart_data[0] << 8 | (uint16_t) uart_data[1] & MAIN_ROWMASK;
		matrix[1] = (uint16_t) uart_data[1] << 12 | (uint16_t) uart_data[2] << 4;
		matrix[2] = (uint16_t) uart_data[3] << 8 | (uint16_t) uart_data[4] & MAIN_ROWMASK;
		matrix[3] = (uint16_t) uart_data[4] << 9 | (uint16_t) uart_data[5] << 1 & LOWER_ROWMASK;
		matrix[4] = (uint16_t) uart_data[5] << 7 & LOWER_ROWMASK;
		/* OK, TURNS OUT THAT WAS A BAD ASSUMPTION */
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
			//I've unpacked these into the mirror image of what QMK expects them to be, so...
			matrix[i] = ((matrix[i] * 0x0802LU & 0x22110LU) | (matrix[i] * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16;
			//bithack mirror!  Doesn't make any sense, but works - and efficiently.
        }
    }


    matrix_scan_quantum();
    return 1;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print_matrix_header();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        print_matrix_row(row);
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += matrix_bitpop(i);
    }
    return count;
}
