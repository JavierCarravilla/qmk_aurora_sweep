#pragma once

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

#define RGBLIGHT_HUE_STEP	8
#define RGBLIGHT_SAT_STEP	8
#define RGBLIGHT_VAL_STEP	8
#define RGBLIGHT_SLEEP true

// Layer look auto turn off
#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.

// Word Cap
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* Mouse */
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL

/* Delay antes de repetir movimiento */
#define MOUSEKEY_DELAY 500

/* Intervalo base entre movimientos */
#define MOUSEKEY_INTERVAL 20

/* Velocidad máxima */
#define MOUSEKEY_MAX_SPEED 4

/* Tiempo hasta velocidad máxima */
#define MOUSEKEY_TIME_TO_MAX 80

/* Wheel */

#define MOUSEKEY_WHEEL_DELAY 100
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_MAX_SPEED 3
#define MOUSEKEY_WHEEL_TIME_TO_MAX 60

