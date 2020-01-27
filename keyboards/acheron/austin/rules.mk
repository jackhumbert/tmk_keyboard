# MCU name
MCU = STM32F072

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# project specific files
# VPATH += keyboards/cannonkeys/stm32f072
SRC =	keyboard.c \
      led.c

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes	    # USB Nkey Rollover
CUSTOM_MATRIX = no # Custom matrix file
# BACKLIGHT_ENABLE = yes # This is broken on 072 for some reason
# RGBLIGHT_ENABLE = yes
WS2812_DRIVER = spi
# RAW_ENABLE = yes
# DYNAMIC_KEYMAP_ENABLE = yes

DFU_ARGS = -d 0483:df11 -a 0 -s 0x08000000:leave
