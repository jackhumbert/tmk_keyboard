# MCU name
MCU = atmega32u4

BOOTLOADER = caterina
F_CPU = 8000000


# Build Options
#   change yes to no to disable
#

# Build Options
#   change yes to no to disable
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no            # MIDI controls
UNICODE_ENABLE = no         # Unicode
AUDIO_ENABLE = no           # Audio output on port C6
LAYOUTS = 666
RGBLIGHT_ENABLE = yes
BLUETOOTH = AdafruitBLE
OLED_DRIVER_ENABLE = yes
