/*
Copyright 2020 Nate Ferrell <@scrthq>

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

#pragma once
#include QMK_KEYBOARD_H

#include "action.h"
#include "version.h"
#include "eeprom.h"

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

// Custom keycodes
/* enum userspace_custom_keycodes {
    // Double keys
    MOFO = USER_START,
    LOWER,
    RAISE
}; */

/* Define layer names */
enum userspace_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _HOLDF,
  _HOLDJ,
  _BABBLE,
  _NUMPAD,
  _SYMBOLS,
  _EMPTY
};

enum tap_dance_declarations {
    SPENT,
};

#ifdef TAP_DANCE_ENABLE
// Tap dance config shared between my keyboards
#define TD_SPENT  TD(SPENT)
#else
#define TD_SPENT  KC_ENT
#endif

/* #define HOLDF LT(_HOLDF,KC_F)
#define HOLDJ LT(_HOLDJ,KC_J)
#define HOLDS LT(_SYMBOLS,KC_S)
#define HOLDD LT(_NUMPAD,KC_D)
#define HOLDMINS LT(_BABBLE,KC_MINS)
 */
#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH



#define ___________________BLANK___________________       _______, _______, _______, _______, _______
#define ___________________BLOCK___________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
