/* Name: main.c
 * Project: hid-mouse, a very simple HID example
 * Author: Christian Starkjohann
 * Creation Date: 2008-04-07
 * Tabsize: 4
 * Copyright: (c) 2008 by OBJECTIVE DEVELOPMENT Software GmbH
 * License: GNU GPL v2 (see License.txt), GNU GPL v3 or proprietary (CommercialLicense.txt)
 * This Revision: $Id: main.c 790 2010-05-30 21:00:26Z cs $
 */
#include <stdint.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>  /* for sei() */
#include <avr/pgmspace.h>   /* required by usbdrv.h */
#include <util/delay.h>     /* for _delay_ms() */
#include "usbdrv.h"
#include "usart_print.h"        /* This is also an example for using debug macros */
#include "usb_keycodes.h"
#include "matrix_skel.h"
#include "keymap_skel.h"
#include "mousekey.h"
#include "layer.h"
#include "print.h"
#include "debug.h"
#include "sendchar.h"
#include "host.h"
#include "host_vusb.h"
#include "timer.h"
#include "led.h"
#include "keyboard.h"

#define DEBUGP_INIT() do { DDRC = 0xFF; } while (0)
#define DEBUGP(x) do { PORTC = x; } while (0)

//static uint8_t last_led = 0;
int main(void)
{
    DEBUGP_INIT();
    wdt_enable(WDTO_1S);
    /* Even if you don't use the watchdog, turn it off here. On newer devices,
     * the status of the watchdog (on/off, period) is PRESERVED OVER RESET!
     */

    /* RESET status: all port bits are inputs without pull-up.
     * That's the way we need D+ and D-. Therefore we don't need any
     * additional hardware initialization.
     */
    odDebugInit();
    usbInit();

    print_enable = true;
    debug_enable = true;
    keyboard_init();

    /* enforce re-enumeration, do this while interrupts are disabled! */
    usbDeviceDisconnect();
    uint8_t i = 0;
    while(--i){             /* fake USB disconnect for > 250 ms */
        wdt_reset();
        _delay_ms(1);
    }
    usbDeviceConnect();
    sei();

    //uint8_t fn_bits = 0;
    while (1) {                /* main event loop */
        wdt_reset();
        usbPoll();
        keyboard_proc();
        host_vusb_keyboard_send();
    }
}
