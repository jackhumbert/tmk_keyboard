/*
 * This software is experimental and a work in progress.
 * Under no circumstances should these files be used in relation to any critical system(s).
 * Use of these files is at your own risk.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This files are free to use from http://engsta.com/stm32-flash-memory-eeprom-emulator/ by
 * Artur F.
 *
 * Modifications for QMK and STM32F303 by Yiancar
 *
 * This library assumes 8-bit data locations. To add a new MCU, please provide the flash
 * page size and the total flash size in Kb. The number of available pages must be a multiple
 * of 2. Only half of the pages account for the total EEPROM size.
 * This library also assumes that the pages are not used by the firmware.
 */

#pragma once

#include <ch.h>
#include <hal.h>
#include "flash_stm32.h"

// HACK ALERT. This definition may not match your processor
// To Do. Work out correct value for EEPROM_PAGE_SIZE on the STM32F103CT6 etc
#if defined(EEPROM_EMU_STM32F303xC)
#    define MCU_STM32F303CC
#elif defined(EEPROM_EMU_STM32F103xB)
#    define MCU_STM32F103RB
#elif defined(EEPROM_EMU_STM32F072xB)
#    define MCU_STM32F072CB
#elif defined(EEPROM_EMU_STM32F042x6)
#    define MCU_STM32F042K6
#else
#    error "not implemented."
#endif

#ifndef EEPROM_PAGE_SIZE
#    if defined(MCU_STM32F103RB) || defined(MCU_STM32F042K6)
#        define FEE_PAGE_SIZE (uint16_t)0x400  // Page size = 1KByte
#        define FEE_DENSITY_PAGES 8            // How many pages are used
#    elif defined(MCU_STM32F103ZE) || defined(MCU_STM32F103RE) || defined(MCU_STM32F103RD) || defined(MCU_STM32F303CC) || defined(MCU_STM32F072CB)
#        define FEE_PAGE_SIZE (uint16_t)0x800  // Page size = 2KByte
#        define FEE_DENSITY_PAGES 4            // How many pages are used
#    else
#        error "No MCU type specified. Add something like -DMCU_STM32F103RB to your compiler arguments (probably in a Makefile)."
#    endif
#endif

#ifndef EEPROM_START_ADDRESS
#    if defined(MCU_STM32F103RB) || defined(MCU_STM32F072CB)
#        define FEE_MCU_FLASH_SIZE 128  // Size in Kb
#    elif defined(MCU_STM32F042K6)
#        define FEE_MCU_FLASH_SIZE 32  // Size in Kb
#    elif defined(MCU_STM32F103ZE) || defined(MCU_STM32F103RE)
#        define FEE_MCU_FLASH_SIZE 512  // Size in Kb
#    elif defined(MCU_STM32F103RD)
#        define FEE_MCU_FLASH_SIZE 384  // Size in Kb
#    elif defined(MCU_STM32F303CC)
#        define FEE_MCU_FLASH_SIZE 256  // Size in Kb
#    else
#        error "No MCU type specified. Add something like -DMCU_STM32F103RB to your compiler arguments (probably in a Makefile)."
#    endif
#endif

/* Start of the emulated eeprom flash area */
#define FEE_PAGE_BASE_ADDRESS ((uint32_t)(0x8000000 + FEE_MCU_FLASH_SIZE * 1024 - FEE_DENSITY_PAGES * FEE_PAGE_SIZE))
/* End of the emulated eeprom flash area */
#define FEE_LAST_PAGE_ADDRESS (FEE_PAGE_BASE_ADDRESS + (FEE_PAGE_SIZE * FEE_DENSITY_PAGES))
/* Size of emulated eeprom */
#define FEE_DENSITY_BYTES 1024
/* Flash word value after erase */
#define FEE_EMPTY_WORD ((uint16_t)0xFFFF)

_Static_assert(FEE_DENSITY_PAGES * FEE_PAGE_SIZE >= FEE_DENSITY_BYTES * 8,
    "flash memory for emulated eeprom is too small; for correct functionality ensure it is at least 8x FEE_DENSITY_BYTES");

#if defined(DYNAMIC_KEYMAP_EEPROM_MAX_ADDR) && (DYNAMIC_KEYMAP_EEPROM_MAX_ADDR >= FEE_DENSITY_BYTES)
#error emulated eeprom: DYNAMIC_KEYMAP_EEPROM_MAX_ADDR is greater than the FEE_DENSITY_BYTES available
#endif

void     EEPROM_Init(void);
void     EEPROM_Erase(void);
void     EEPROM_WriteDataByte(uint16_t Address, uint8_t DataByte);
uint8_t  EEPROM_ReadDataByte(uint16_t Address);
