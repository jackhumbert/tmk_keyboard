# Enable Bootmagic Lite to consistently reset to bootloader and clear EEPROM.
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

# Enable media keys on all keyboards.
EXTRAKEY_ENABLE = yes

# Enable N-key rollover on all keyboards. In addition to its intended
# functionality, as of July 2020, this is required for Chrome OS to process
# media keys. (It appears that Chrome OS filters out key events from the second
# USB endpoint's consumer and system control devices unless that endpoint also
# reports a keyboard or mouse device.)
NKRO_ENABLE = yes

# Enable link-time optimization to reduce binary size.
LTO_ENABLE = yes

# Include common utilities shared across all our keymaps.
SRC += bcat.c

# Include additional utilities that extend optional QMK features only enabled
# on some keyboards.
ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += bcat_oled.c
	WPM_ENABLE = yes  # for WPM and animated "keyboard pet" widgets
endif
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += bcat_rgblight.c
endif

# Disable unwanted build options on all keyboards. (Mouse keys are turned off
# due to https://github.com/qmk/qmk_firmware/issues/8323, and the rest are
# turned off to reduce firmware size.)
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = no
TERMINAL_ENABLE = no

# Disable unwanted hardware options on all keyboards. (Some keyboards turn
# these features on by default even though they aren't actually required.)
MIDI_ENABLE = no
SLEEP_LED_ENABLE = no

# Disable other unused options on all keyboards.
AUTO_SHIFT_ENABLE = no
COMBO_ENABLE = no
KEY_LOCK_ENABLE = no
LEADER_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no
UCIS_ENABLE = no
UNICODEMAP_ENABLE = no
UNICODE_ENABLE = no
