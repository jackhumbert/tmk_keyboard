# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = halfkay

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
POINTING_DEVICE_ENABLE  = no
MOUSEKEY_ENABLE         = no  # Mouse keys(+4700)
EXTRAKEY_ENABLE         = yes # Audio control and System control(+450)
CONSOLE_ENABLE          = no  # Console for debug(+8000)
COMMAND_ENABLE          = no  # Commands for debug and configuration
CUSTOM_MATRIX           = yes # Custom matrix file for the Dactyl
NKRO_ENABLE             = yes # USB Nkey Rollover
UNICODE_ENABLE          = yes # Unicode
SWAP_HANDS_ENABLE       = yes # Allow swapping hands of keyboard
SLEEP_LED_ENABLE        = no
RGBLIGHT_ENABLE         = no

# project specific files
QUANTUM_LIB_SRC += i2c_master.c
SRC += matrix.c
