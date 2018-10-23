BOOTMAGIC_ENABLE ?= yes	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= no	# Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes	# Audio control and System control(+450)
CONSOLE_ENABLE ?= no	# Console for debug(+400)
COMMAND_ENABLE ?= no    # Commands for debug and configuration
SLEEP_LED_ENABLE ?= no  # Breathing sleep LED during USB suspend
NKRO_ENABLE ?= yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE ?= yes  # Enable keyboard backlight functionality
AUDIO_ENABLE ?= no
RGBLIGHT_ENABLE ?= yes
UNICODE_ENABLE ?= yes



ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

SPACE_CADET_ENABLE = yes  # add option for PR #3885, space cadet feature is going to disable default.
