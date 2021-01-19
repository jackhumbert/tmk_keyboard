/* Copyright 2020 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This file was auto-generated by:
 *    `qmk chibios-confupdate -i keyboards/handwired/twadlee/tp69/chconf.h -r platforms/chibios/common/configs/chconf.h`
 */

#pragma once

#define CH_CFG_ST_FREQUENCY 1000

#define CH_CFG_ST_TIMEDELTA 0

#define CH_CFG_TIME_QUANTUM 20

#define CH_CFG_USE_TM FALSE

#define CH_CFG_USE_MEMCORE TRUE

#define CH_CFG_USE_FACTORY FALSE

#define CH_CFG_FACTORY_OBJECTS_REGISTRY TRUE

#define CH_CFG_FACTORY_GENERIC_BUFFERS TRUE

#define CH_CFG_FACTORY_SEMAPHORES TRUE

#define CH_CFG_FACTORY_MAILBOXES TRUE

#define CH_CFG_FACTORY_OBJ_FIFOS TRUE

#define CH_CFG_FACTORY_PIPES TRUE

#define CH_DBG_SYSTEM_STATE_CHECK TRUE

#define CH_DBG_ENABLE_CHECKS TRUE

#define CH_DBG_ENABLE_ASSERTS TRUE

#define CH_DBG_ENABLE_STACK_CHECK TRUE

#define CH_DBG_FILL_THREADS TRUE

#define CH_CFG_SYSTEM_EXTRA_FIELDS /* Add threads custom fields here.*/

#define CH_CFG_SYSTEM_INIT_HOOK() \
        { /* Add threads initialization code here.*/ }

#define CH_CFG_THREAD_EXTRA_FIELDS /* Add threads custom fields here.*/

#define CH_CFG_THREAD_INIT_HOOK(tp) \
        { /* Add threads initialization code here.*/ }

#define CH_CFG_THREAD_EXIT_HOOK(tp) \
        { /* Add threads finalization code here.*/ }

#define CH_CFG_CONTEXT_SWITCH_HOOK(ntp, otp) \
        { /* Context switch code here.*/ }

#define CH_CFG_IRQ_PROLOGUE_HOOK() \
        { /* IRQ prologue code here.*/ }

#define CH_CFG_IRQ_EPILOGUE_HOOK() \
        { /* IRQ epilogue code here.*/ }

#define CH_CFG_IDLE_ENTER_HOOK() \
        { /* Idle-enter code here.*/ }

#define CH_CFG_IDLE_LEAVE_HOOK() \
        { /* Idle-leave code here.*/ }

#define CH_CFG_IDLE_LOOP_HOOK() \
        { /* Idle loop code here.*/ }

#define CH_CFG_SYSTEM_TICK_HOOK() \
        { /* System tick event code here.*/ }

#define CH_CFG_SYSTEM_HALT_HOOK(reason) \
        { /* System halt code here.*/ }

#define CH_CFG_TRACE_HOOK(tep) \
        { /* Trace code here.*/ }

#include_next <chconf.h>

