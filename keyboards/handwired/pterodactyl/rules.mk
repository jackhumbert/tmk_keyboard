# MCU name
MCU = atmega32u4

# Processor frequency
F_CPU = 8000000

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE        = no  # Virtual DIP switch configuration(+1000)
MIDI_ENABLE             = no  # MIDI support (+2400 to 4200)
POINTING_DEVICE_ENABLE  = no
MOUSEKEY_ENABLE         = no  # Mouse keys(+4700)
EXTRAKEY_ENABLE         = yes # Audio control and System control(+450)
CONSOLE_ENABLE          = yes  # Console for debug(+8000)
COMMAND_ENABLE          = no  # Commands for debug and configuration
CUSTOM_MATRIX           = yes # Custom matrix file for the Pterodactyl
NKRO_ENABLE             = yes # USB Nkey Rollover
UNICODE_ENABLE          = yes # Unicode
SWAP_HANDS_ENABLE       = no # Allow swapping hands of keyboard
SLEEP_LED_ENABLE        = no
API_SYSEX_ENABLE        = no
RGBLIGHT_ENABLE         = no
BLUETOOTH               = AdafruitBLE

SRC += matrix.c
QUANTUM_LIB_SRC += i2c_master.c
