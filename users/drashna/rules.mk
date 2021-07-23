SRC += drashna.c \
       process_records.c

ifneq ($(PLATFORM),CHIBIOS)
    LTO_ENABLE        = yes
endif
SPACE_CADET_ENABLE    = no
GRAVE_ESC_ENABLE      = no

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
    ifeq ($(strip $(NO_SECRETS)), lite)
        OPT_DEFS += -DNO_SECRETS
    endif
endif

CUSTOM_TAP_DANCE ?= yes
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
        SRC += tap_dances.c
    endif
endif

CUSTOM_RGBLIGHT ?= yes
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    ifeq ($(strip $(CUSTOM_RGBLIGHT)), yes)
        SRC += rgb_stuff.c
        ifeq ($(strip $(RGBLIGHT_TWINKLE)), yes)
            OPT_DEFS += -DRGBLIGHT_TWINKLE
        endif
        ifeq ($(strip $(RGBLIGHT_NOEEPROM)), yes)
            OPT_DEFS += -DRGBLIGHT_NOEEPROM
        endif
        ifeq ($(strip $(RGBLIGHT_STARTUP_ANIMATION)), yes)
            OPT_DEFS += -DRGBLIGHT_STARTUP_ANIMATION
        endif
    endif
endif

CUSTOM_RGB_MATRIX ?= yes
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    ifeq ($(strip $(CUSTOM_RGB_MATRIX)), yes)
        SRC += rgb_matrix_stuff.c
    endif
endif

KEYLOGGER_ENABLE ?= no
ifdef CONSOLE_ENABLE
    ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
        OPT_DEFS += -DKEYLOGGER_ENABLE
    endif
endif

ifeq ($(strip $(MAKE_BOOTLOADER)), yes)
    OPT_DEFS += -DMAKE_BOOTLOADER
endif

# At least until build.mk or the like drops, this is here to prevent
# VUSB boards from enabling NKRO, as they do not support it. Ideally
# this should be handled per keyboard, but until that happens ...
ifeq ($(strip $(PROTOCOL)), VUSB)
    NKRO_ENABLE       = no
endif

CUSTOM_OLED_DRIVER ?= yes
ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    ifeq ($(strip $(CUSTOM_OLED_DRIVER)), yes)
        SRC += oled_stuff.c
    endif
endif

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
    SRC += drivers/sensors/pimoroni_trackball.c
    QUANTUM_LIB_SRC += i2c_master.c
endif

CUSTOM_SPLIT_TRANSPORT ?= yes
ifeq ($(strip $(SPLIT_KEYBOARD)), yes)
    QUANTUM_LIB_SRC += transport_sync.c
    # ifneq ($(strip $(SPLIT_TRANSPORT)), custom)
    #     ifeq ($(strip $(CUSTOM_SPLIT_TRANSPORT)), yes)
    #         SPLIT_TRANSPORT = custom
    #         QUANTUM_LIB_SRC += drashna_transport.c
    #         OPT_DEFS += -DDRASHNA_CUSTOM_TRANSPORT
    #         # Unused functions are pruned away, which is why we can add multiple drivers here without bloat.
    #         ifeq ($(PLATFORM),AVR)
    #             ifneq ($(NO_I2C),yes)
    #                 QUANTUM_LIB_SRC += i2c_master.c \
    #                                 i2c_slave.c
    #             endif
    #         endif

    #         SERIAL_DRIVER ?= bitbang
    #         OPT_DEFS += -DSERIAL_DRIVER_$(strip $(shell echo $(SERIAL_DRIVER) | tr '[:lower:]' '[:upper:]'))
    #         ifeq ($(strip $(SERIAL_DRIVER)), bitbang)
    #             QUANTUM_LIB_SRC += serial.c
    #         else
    #             QUANTUM_LIB_SRC += serial_$(strip $(SERIAL_DRIVER)).c
    #         endif
    #     endif
    # endif
endif

# DEBUG_MATRIX_SCAN_RATE_ENABLE = api
