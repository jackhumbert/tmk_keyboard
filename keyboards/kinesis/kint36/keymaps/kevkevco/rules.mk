BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
COMMAND_ENABLE = yes
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = yes
RGBLIGHT_ENABLE = no
TAP_DANCE_ENABLE = yes
# LEADER_ENABLE = yes
FIRMWARE_FORMAT = hex
SWAP_HANDS_ENABLE = yes
NKRO_ENABLE = no 			# For QMK Apple Fn Key patch by https://gist.github.com/fauxpark/010dcf5d6377c3a71ac98ce37414c6c4
APPLE_FN_ENABLE = yes       # Enable Apple Fn key functionality
DYNAMIC_MACRO_ENABLE = yes

SRC += features/caps_word.c # Add caps_word files
# OPT_DEFS += -DCAPS_WORD_ENABLE # From Drashna
# CAPS_WORD_ENABLE = yes

# Enable Select Word Macro from https://getreuer.info/posts/keyboards/select-word/index.html
SRC += features/select_word.c

# Enable numword
SRC += features/num_word.c