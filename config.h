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

#define MK_C_OFFSET_0 1
#define MK_C_INTERVAL_0 12

#define MK_C_OFFSET_1 4
#define MK_C_INTERVAL_1 18

#define MK_C_OFFSET_UNMOD 13
#define MK_C_INTERVAL_UNMOD 15

#define MK_C_OFFSET_2 25
#define MK_C_INTERVAL_2 10

#define MK_W_OFFSET_0 1
#define MK_W_INTERVAL_0 160

#define MK_W_OFFSET_1 2
#define MK_W_INTERVAL_1 120

#define MK_W_OFFSET_UNMOD 4
#define MK_W_INTERVAL_UNMOD 70

#define MK_W_OFFSET_2 10
#define MK_W_INTERVAL_2 30

