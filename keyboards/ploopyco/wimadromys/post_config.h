#pragma once

// Enable syncing of charybdis config
#ifdef CHARYBDIS_CONFIG_SYNC
#    define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC
#endif

/* Mouse config. */

#ifndef MOUSEKEY_MOVE_DELTA
#    ifndef MK_KINETIC_SPEED
#        define MOUSEKEY_MOVE_DELTA 5
#    else // MK_KINETIC_SPEED
#        define MOUSEKEY_MOVE_DELTA 25
#    endif // !MK_KINETIC_SPEED
#endif     // !MOUSEKEY_MOVE_DELTA

#ifndef MOUSEKEY_DELAY
#    ifndef MK_KINETIC_SPEED
#        define MOUSEKEY_DELAY 300
#    else // MK_KINETIC_SPEED
#        define MOUSEKEY_DELAY 8
#    endif // !MK_KINETIC_SPEED
#endif     // !MOUSEKEY_DELAY

#ifndef MOUSEKEY_INTERVAL
#    ifndef MK_KINETIC_SPEED
#        define MOUSEKEY_INTERVAL 50
#    else // MK_KINETIC_SPEED
#        define MOUSEKEY_INTERVAL 20
#    endif // !MK_KINETIC_SPEED
#endif     // !MOUSEKEY_INTERNAL

#ifndef MOUSEKEY_MAX_SPEED
#    define MOUSEKEY_MAX_SPEED 7
#endif // !MOUSEKEY_MAX_SPEED

#ifndef MOUSEKEY_TIME_TO_MAX
#    define MOUSEKEY_TIME_TO_MAX 60
#endif // !MOUSEKEY_TIME_TO_MAX

#ifndef MOUSEKEY_INITIAL_SPEED
#    define MOUSEKEY_INITIAL_SPEED 100
#endif // !MOUSEKEY_INITIAL_SPEED

#ifndef MOUSEKEY_BASE_SPEED
#    define MOUSEKEY_BASE_SPEED 1000
#endif // !MOUSEKEY_BASE_SPEED

#ifndef MOUSEKEY_DECELERATED_SPEED
#    define MOUSEKEY_DECELERATED_SPEED 400
#endif // !MOUSEKEY_DECELERATED_SPEED

#ifndef MOUSEKEY_ACCELERATED_SPEED
#    define MOUSEKEY_ACCELERATED_SPEED 3000
#endif // !MOUSEKEY_ACCELERATED_SPEED

/* Mouse scroll config. */

#ifndef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY 15
#endif // !MOUSEKEY_WHEEL_DELAY

#ifndef MOUSEKEY_WHEEL_DELTA
#    define MOUSEKEY_WHEEL_DELTA 1
#endif // !MOUSEKEY_WHEEL_DELTA

#ifndef MOUSEKEY_WHEEL_INTERVAL
#    define MOUSEKEY_WHEEL_INTERVAL 50
#endif // !MOUSEKEY_WHEEL_INTERVAL

#ifndef MOUSEKEY_WHEEL_MAX_SPEED
#    define MOUSEKEY_WHEEL_MAX_SPEED 8
#endif // !MOUSEKEY_WHEEL_MAX_SPEED

#ifndef MOUSEKEY_WHEEL_TIME_TO_MAX
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 80
#endif // !MOUSEKEY_WHEEL_TIME_TO_MAX

#ifndef MOUSEKEY_WHEEL_INITIAL_MOVEMENTS
#    define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 8
#endif // !MOUSEKEY_WHEEL_INITIAL_MOVEMENTS

#ifndef MOUSEKEY_WHEEL_BASE_MOVEMENTS
#    define MOUSEKEY_WHEEL_BASE_MOVEMENTS 48
#endif // !MOUSEKEY_WHEEL_BASE_MOVEMENTS

#ifndef MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS
#    define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
#endif // !MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS

#ifndef MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS
#    define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8
#endif // !MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS
