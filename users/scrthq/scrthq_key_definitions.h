/*
Copyright 2020 Nate Ferrell <nate@scrthq.com> <@scrthq>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "scrthq.h"

#ifdef USE_BABBLEPASTE
    #include "babblePaste.h"
#endif

#define XXX     KC_NO

// Rename mouse keys with 7 letters
#ifdef MOUSEKEY_ENABLE
    #define MO_S_N  KC_MS_WH_UP
    #define MO_S_S  KC_MS_WH_DOWN
    #define MO_S_E  KC_MS_WH_RIGHT
    #define MO_S_W  KC_MS_WH_LEFT
    #define MO_N    KC_MS_UP
    #define MO_S    KC_MS_DOWN
    #define MO_E    KC_MS_RIGHT
    #define MO_W    KC_MS_LEFT
    #define MO_CL_L KC_MS_BTN1
    #define MO_CL_R KC_MS_BTN2
    #define MO_CL_M KC_MS_BTN3
    #define MO_CL_4 KC_MS_BTN4
    #define MO_CL_5 KC_MS_BTN5
    #define MO_AC_0 KC_MS_ACCEL0
    #define MO_AC_1 KC_MS_ACCEL1
    #define MO_AC_2 KC_MS_ACCEL2
#else
    #define MO_S_N  KC_NO
    #define MO_S_S  KC_NO
    #define MO_S_E  KC_NO
    #define MO_S_W  KC_NO
    #define MO_N    KC_NO
    #define MO_S    KC_NO
    #define MO_E    KC_NO
    #define MO_W    KC_NO
    #define MO_CL_L KC_NO
    #define MO_CL_R KC_NO
    #define MO_CL_M KC_NO
    #define MO_CL_1 KC_NO
    #define MO_CL_2 KC_NO
    #define MO_AC_0 KC_NO
    #define MO_AC_1 KC_NO
    #define MO_AC_2 KC_NO
#endif

#if defined(BABBLE_END_RANGE)
    #define USER_START BABBLE_END_RANGE
#else
    #if defined(KEYMAP_SAFE_RANGE)
        #define USER_START KEYMAP_SAFE_RANGE
    #else
        #define USER_START SAFE_RANGE
    #endif
#endif

#ifdef TAP_DANCE_ENABLE
    #define TD_SPENT  TD(SPENT)
#else
    #define TD_SPENT  KC_ENT
#endif

#define HOLDA     LT(_HOLDA,KC_A)
#define HOLDF     LT(_HOLDF,KC_F)
#define HOLDJ     LT(_HOLDJ,KC_J)
#define HOLDS     LT(_SYMBOLS,KC_S)
#define HOLDD     LT(_NUMPAD,KC_D)
#define HOLDMINS  LT(_BABBLE,KC_MINS)
#define HOLDZ     CTL_T(KC_Z)
#define CTLGRV    CTL_T(KC_GRV)
#define MYMEH     MEH(KC_NO)

#ifdef KEYBOARD_dm9records_plaid
    #define BSSLSH   KC_BSPC
    #define DELSLSH  KC_DEL
#else
    #define BSSLSH   KC_BSLASH
    #define DELSLSH  KC_BSLASH
#endif

#define ___________________6_BLANK_________________   _______,    _______,   _______,   _______,   _______,   _______

// QWERTY (default) Layer
#define _________________QWERTY_L0_________________   KC_EQUAL,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5      // Not used on 40% boards like Plaid/Planck
#define _________________QWERTY_L1_________________   KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T
#define _________________QWERTY_L2_________________   HOLDMINS,   HOLDA,     HOLDS,     HOLDD,     HOLDF,     KC_G
#define _________________QWERTY_L3_________________   KC_LSPO,    HOLDZ,     KC_X,      KC_C,      KC_V,      KC_B
#define ____________OLKB_QWERTY_L4_________________   CTLGRV,     KC_LGUI,   MYMEH,     KC_RALT,   LOWER,     KC_SPC

#define _________________QWERTY_R0_________________   KC_6,       KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC   // Not used on 40% boards like Plaid/Planck
#define _________________QWERTY_R1_________________   KC_Y,       KC_U,      KC_I,      KC_O,      KC_P,      BSSLSH    // Use backspace here if this is a 40% board, otherwise use backslash
#define _________________QWERTY_R2_________________   KC_H,       HOLDJ,     KC_K,      KC_L,      KC_SCLN,   KC_QUOT
#define _________________QWERTY_R3_________________   KC_N,       KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSPC
#define ____________OLKB_QWERTY_R4_________________   KC_SPC,     RAISE,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT

// Lower Layer
#define __________________LOWER_L0_________________   KC_ESC,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5      // Not used on 40% boards like Plaid/Planck
#define __________________LOWER_L1_________________   KC_TILD,    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC
#define __________________LOWER_L2_________________   _______,    _______,   _______,   _______,   _______,   _______
#define __________________LOWER_L3_________________   _______,    _______,   _______,   _______,   _______,   _______
#define _____________OLKB_LOWER_L4_________________   _______,    _______,   _______,   _______,   _______,   TD_SPENT

#define __________________LOWER_R0_________________   KC_6,       KC_7,      KC_8,      KC_9,      KC_0,      KC_DEL   // Not used on 40% boards like Plaid/Planck
#define __________________LOWER_R1_________________   KC_CIRC,    KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   DELSLSH
#define __________________LOWER_R2_________________   _______,    KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   KC_PIPE
#define __________________LOWER_R3_________________   _______,    _______,   KC_LT,     KC_GT,     KC_QUES,   _______
#define _____________OLKB_LOWER_R4_________________   TD_SPENT,   _______,   B_L1W,     B_PGDN,    B_PGUP,    B_R1W

// Raise Layer
#define __________________RAISE_L0_________________   KC_GRV,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5      // Not used on 40% boards like Plaid/Planck
#define __________________RAISE_L1_________________   KC_GRV,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5
#define __________________RAISE_L2_________________   KC_ESC,     _______,   _______,   _______,   _______,   _______
#define __________________RAISE_L3_________________   _______,    _______,   _______,   _______,   _______,   _______
#define _____________OLKB_RAISE_L4_________________   _______,    _______,   B_INDENT,  B_DEDENT,  _______,   TD_SPENT

#define __________________RAISE_R0_________________   KC_6,       KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC   // Not used on 40% boards like Plaid/Planck
#define __________________RAISE_R1_________________   KC_6,       KC_7,      KC_8,      KC_9,      KC_0,      BSSLSH
#define __________________RAISE_R2_________________   _______,    KC_MINS,   KC_EQL,    KC_LBRC,   KC_RBRC,   KC_BSLS
#define __________________RAISE_R3_________________   _______,    _______,   _______,   _______,   KC_SLSH,   _______
#define _____________OLKB_RAISE_R4_________________   TD_SPENT,   _______,   B_L1W,     B_PGDN,    B_PGUP,    B_R1W


// HOLD A Layer (Just used for debugging key location familiarty for now)
#define ____________OLKB_HOLD_A_L4_________________   KC_F5,      KC_F8,     _______,   _______,   _______,   _______
