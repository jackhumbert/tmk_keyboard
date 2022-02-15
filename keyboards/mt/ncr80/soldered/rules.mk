# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
BOOTMAGIC_ENABLE = yes     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes          # Enable N-Key Rollover
BACKLIGHT_ENABLE = yes     # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no      # Enable Bluetooth
AUDIO_ENABLE = no          # Audio output

LAYOUTS = tkl_ansi tkl_iso tkl_ansi_wkl tkl_iso_wkl
