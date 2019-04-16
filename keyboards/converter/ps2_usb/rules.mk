MCU = atmega32u4
F_CPU ?= 16000000
ARCH = AVR8
F_USB ?= $(F_CPU)
OPT_DEFS += -DSUSPEND_MODE_STANDBY
BOOTLOADER_SIZE = 4096

BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE ?= yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE ?= yes
NKRO_ENABLE ?= yes

#PS2_USE_USART ?= no
PS2_USE_INT ?= yes
#PS2_USE_BUSYWAIT ?= no

CUSTOM_MATRIX ?= yes

SRC = matrix.c led.c

LAYOUTS = 104_ansi 105_iso ibm_f_at
