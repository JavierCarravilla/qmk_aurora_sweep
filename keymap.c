/* Copyright 2023 Javier Carravilla
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

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum custom_keycodes {
  DBG_EVA = SAFE_RANGE,
  SEL_COL
};

enum layer_names {
   _QWERTY,
   _HOMEROW_MACOS,
   _FUNCTIONS,
   _NUMBERS,
   _SYMBOLS,
   _MOUSE,
   _CONFIG
};

// Left-hand home rows mods
#define LALT_KS LALT_T(KC_S)
#define LSFT_KD LSFT_T(KC_D)
//Linux
#define LCTL_KF LCTL_T(KC_F)
//MacOS
#define LCTL_KA LCTL_T(KC_A)
#define LGUI_KF LGUI_T(KC_F)

// Right-hand home rows mods
#define LALT_KL LALT_T(KC_L)
#define RSFT_KK RSFT_T(KC_K)
//Linux
#define RCTL_KJ RCTL_T(KC_J)
//MacOS
#define RGUI_KJ RGUI_T(KC_J)
#define RCTL_SC RCTL_T(KC_SCLN)


// Tap dance functions
void dance_prt_scr(tap_dance_state_t *state, void *user_data) {
    bool is_mac = IS_LAYER_ON(_HOMEROW_MACOS);

    if (state->count == 1) {
        if (is_mac) {
            tap_code16(G(S(KC_5)));
        } else {
            tap_code16(C(S(KC_PSCR)));
        }
    } else {
        if (is_mac) {
            tap_code16(G(S(KC_4)));
        } else {
            tap_code16(S(KC_PSCR));
        }
    }
}

void dance_refresh_browser(tap_dance_state_t *state, void *user_data) {
    bool is_mac = IS_LAYER_ON(_HOMEROW_MACOS);

    if (state->count == 1) {
        if (is_mac) {
            tap_code16(G(KC_R));
        } else {
            tap_code16(C(KC_R));
        }
    } else {
        if (is_mac) {
            tap_code16(S(G(KC_R)));
        } else {
            tap_code16(C(S(KC_R)));
        }
    }
}

// Tap Dance definitions
enum {
  TD_PLS_STR,
  TD_MIN_SLH,
  TD_PRT_SCR,
  TD_RFS_BWR,
  TD_MAC_CTL,
  TD_QUO_DBL
};

tap_dance_action_t tap_dance_actions[] = {
  // + on single tap and * with double
  [TD_PLS_STR] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_ASTR),
  // - on single tap amd / on double
  [TD_MIN_SLH] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_SLSH),
  // Print screen to clipboard on single tap and store it with double
  [TD_PRT_SCR] = ACTION_TAP_DANCE_FN(dance_prt_scr),
  // F5 on single tap, SHIFT + F5 on double
  [TD_RFS_BWR] = ACTION_TAP_DANCE_FN(dance_refresh_browser),
  // KC_LPAD on single tap, KC_MCTL on double
  [TD_MAC_CTL] = ACTION_TAP_DANCE_DOUBLE(KC_LPAD, KC_MCTL),
  // Space on single quote, doubles on double
  [TD_QUO_DBL] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
};

//Tap dance alias
#define PLS_STR TD(TD_PLS_STR)
#define MIN_SLH TD(TD_MIN_SLH)
#define PRT_SCR TD(TD_PRT_SCR)
#define RFS_BWR TD(TD_RFS_BWR)
#define MAC_CTL TD(TD_MAC_CTL)
#define QUO_DBL TD(TD_QUO_DBL)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_split_3x5_2(
        //|--------------------------------------------|       |---------------------------------------------|
            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
            KC_A,    LALT_KS, LSFT_KD, LCTL_KF, KC_G,           KC_H,    RCTL_KJ, RSFT_KK,  LALT_KL, KC_SCLN,
            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
        //|--------------------------------------------|       |---------------------------------------------|
                                  MO(_NUMBERS), KC_SPC,        LT(_FUNCTIONS, KC_ENT), MO(_SYMBOLS)
                             //|-----------------------|       |-------------------|
   ),

   [_HOMEROW_MACOS] = LAYOUT_split_3x5_2(
        //|--------------------------------------------|       |--------------------------------------------|
            _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,
            LCTL_KA, _______, _______, LGUI_KF, _______,        _______, RGUI_KJ, _______, _______, RCTL_SC,
            _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,
        //|--------------------------------------------|       |--------------------------------------------|
                                       _______, _______,        _______, _______
                        //|----------------------------|       |----------------------------|
   ),

   [_FUNCTIONS] = LAYOUT_split_3x5_2(
        //|--------------------------------------------|       |--------------------------------------------|
            QK_GESC, _______, _______, RFS_BWR, PRT_SCR,        G(KC_GRV), G(S(KC_LBRC)), G(S(KC_RBRC)), _______, KC_BSPC,
             KC_TAB, _______, _______, _______, C(KC_LEFT),     C(KC_RIGHT), _______, _______, _______, _______,
            _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,
        //|--------------------------------------------|       |--------------------------------------------|
                                    XXXXXXX, _______,           MO(_FUNCTIONS),XXXXXXX
                        //|----------------------------|       |----------------------------|
   ),

   [_NUMBERS] = LAYOUT_split_3x5_2(
        //|--------------------------------------------|       |--------------------------------------------|
           KC_1,     KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
           _______, _______, _______, _______,  XXXXXXX,        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, QUO_DBL,
           PLS_STR,  MIN_SLH, KC_LPRN, KC_RPRN, KC_EQL,         KC_HOME, KC_PGDN, KC_PGUP, KC_END,   MAC_CTL,
        //|--------------------------------------------|       |--------------------------------------------|
                                      _______, QK_LLCK,         _______, MO(_CONFIG)
                       //|-----------------------------|       |----------------------------|
   ),

   [_SYMBOLS] = LAYOUT_split_3x5_2(
        //|--------------------------------------------|       |-------------------------------------------|
            KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        //|--------------------------------------------|       |-------------------------------------------|
                                   MO(_CONFIG),QK_LLCK,         _______, _______
                       //|-----------------------------|       |----------------------------|
   ),

   [_MOUSE] = LAYOUT_split_3x5_2(
        //|--------------------------------------------|       |-------------------------------------------|
            RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU,        RM_SPDU, MS_BTN1, MS_WHLU, MS_BTN2, XXXXXXX,
            XXXXXXX, MS_BTN2, KC_NO  , MS_BTN1, XXXXXXX,        MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX,
            XXXXXXX, RM_PREV, RM_HUED, RM_SATD, RM_VALD,        RM_SPDD, MS_WHLL, MS_WHLD, MS_WHLR, XXXXXXX,
        //|--------------------------------------------|       |-------------------------------------------|
                                       _______, QK_LLCK,        MO(_MOUSE), _______

                       //|-----------------------------|       |----------------------------|
   ),

  [_CONFIG] = LAYOUT_split_3x5_2(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, UG_NEXT,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  UG_HUED, UG_SATD, UG_VALD, UG_PREV,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, XXXXXXX,        XXXXXXX, _______
)

};

// https://docs.qmk.fm/features/os_detection
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            if (IS_LAYER_OFF(_HOMEROW_MACOS)) {
              layer_on(_HOMEROW_MACOS);
            }
            break;
        case OS_WINDOWS:
            if (IS_LAYER_ON(_HOMEROW_MACOS)) {
              layer_off(_HOMEROW_MACOS);
            }
            break;
        case OS_LINUX:
            if (IS_LAYER_ON(_HOMEROW_MACOS)) {
              layer_off(_HOMEROW_MACOS);
            }
            break;
        case OS_UNSURE:
            break;
    }

    return true;
}

//Overriding the delete key https://docs.qmk.fm/features/key_overrides#simple-example
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
  &delete_key_override
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_CYAN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

//Encoder
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    switch (get_highest_layer(layer_state)) {

        // BASE -> Scroll
        case _HOMEROW_MACOS:
            if (clockwise) {
                tap_code(MS_WHLU);
            } else {
                tap_code(MS_WHLD);
            }
            break;
        case _QWERTY:
            if (clockwise) {
                tap_code(MS_WHLU);
            } else {
                tap_code(MS_WHLD);
            }
            break;

        // _FUNCTIONS -> Zoom
        case _FUNCTIONS:
            if (clockwise) {
                tap_code16(LGUI(KC_MINS));   // Cmd +
            } else {
                tap_code16(LGUI(KC_EQL));  // Cmd -
            }
            break;

        // MEDIA -> Volumen
        case _SYMBOLS:
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
            break;
    }

    return false;
}
#endif

