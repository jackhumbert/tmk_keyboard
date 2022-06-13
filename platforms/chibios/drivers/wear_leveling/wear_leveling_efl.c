// Copyright 2022 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdbool.h>
#include <hal.h>
#include "timer.h"
#include "wear_leveling.h"
#include "wear_leveling_internal.h"

static flash_offset_t base_offset = UINT32_MAX;

#if defined(WEAR_LEVELING_EFL_FIRST_SECTOR)
static flash_sector_t first_sector = WEAR_LEVELING_EFL_FIRST_SECTOR;
#else  // defined(WEAR_LEVELING_EFL_FIRST_SECTOR)
static flash_sector_t first_sector = UINT16_MAX;
#endif // defined(WEAR_LEVELING_EFL_FIRST_SECTOR)

static flash_sector_t sector_count = UINT16_MAX;
static BaseFlash *    flash;

bool backing_store_init(void) {
    bs_dprintf("Init\n");
    flash = (BaseFlash *)&EFLD1;

    const flash_descriptor_t *desc    = flashGetDescriptor(flash);
    uint32_t                  counter = 0;

#if defined(WEAR_LEVELING_EFL_FIRST_SECTOR)

    // Work out how many sectors we want to use, working forwards from the first sector specified
    for (flash_sector_t i = 0; i < desc->sectors_count - first_sector; ++i) {
        counter += flashGetSectorSize(flash, first_sector + i);
        if (counter >= (WEAR_LEVELING_BACKING_SIZE)) {
            sector_count = i + 1;
            base_offset  = flashGetSectorOffset(flash, first_sector);
            break;
        }
    }
    if (sector_count == UINT16_MAX) {
        // We didn't get the required number of sectors. Can't do anything here. Fault.
        chSysHalt("Invalid sector count intended to be used with wear_leveling");
    }

#else // defined(WEAR_LEVELING_EFL_FIRST_SECTOR)

    // Work out how many sectors we want to use, working backwards from the end of the flash
    for (flash_sector_t i = 0; i < desc->sectors_count; ++i) {
        first_sector = desc->sectors_count - i - 1;
        counter += flashGetSectorSize(flash, first_sector);
        if (counter >= (WEAR_LEVELING_BACKING_SIZE)) {
            sector_count = i + 1;
            base_offset  = flashGetSectorOffset(flash, first_sector);
            break;
        }
    }

#endif // defined(WEAR_LEVELING_EFL_FIRST_SECTOR)

    return true;
}

bool backing_store_unlock(void) {
    bs_dprintf("Unlock\n");
    return eflStart(&EFLD1, NULL) == HAL_RET_SUCCESS;
}

bool backing_store_erase(void) {
#ifdef WEAR_LEVELING_DEBUG_OUTPUT
    uint32_t start = timer_read32();
#endif

    bool          ret = true;
    flash_error_t status;
    for (int i = 0; i < sector_count; ++i) {
        // Kick off the sector erase
        status = flashStartEraseSector(flash, first_sector + i);
        if (status != FLASH_NO_ERROR && status != FLASH_BUSY_ERASING) {
            ret = false;
        }

        // Wait for the erase to complete
        status = flashWaitErase(flash);
        if (status != FLASH_NO_ERROR && status != FLASH_BUSY_ERASING) {
            ret = false;
        }
    }

    bs_dprintf("Backing store erase took %ldms to complete\n", ((long)(timer_read32() - start)));
    return ret;
}

bool backing_store_write(uint32_t address, backing_store_int_t value) {
    uint32_t offset = (base_offset + address);
    bs_dprintf("Write ");
    wl_dump(offset, &value, sizeof(value));
    value = ~value;
    return flashProgram(flash, offset, sizeof(value), (const uint8_t *)&value) == FLASH_NO_ERROR;
}

bool backing_store_lock(void) {
    bs_dprintf("Lock  \n");
    eflStop(&EFLD1);
    return true;
}

bool backing_store_read(uint32_t address, backing_store_int_t *value) {
    uint32_t             offset = (base_offset + address);
    backing_store_int_t *loc    = (backing_store_int_t *)offset;
    *value                      = ~(*loc);
    bs_dprintf("Read  ");
    wl_dump(offset, loc, sizeof(value));
    return true;
}
