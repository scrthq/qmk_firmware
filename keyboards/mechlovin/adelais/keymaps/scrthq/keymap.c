/* Copyright 2020 Takuya Urakawa (dm9records.com)
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
#include "scrthq.h"
#include "scrthq_layouts.h"
#include "scrthq_key_definitions.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_all(
    KC_ESC,     KC_GRAVE, KC_1,  KC_2,    KC_3,  KC_4,  KC_5, KC_6,     KC_7,   KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC,
    KC_PGUP,    KC_TAB,   KC_Q,  KC_W,    KC_E,  KC_R,  KC_T,           KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,
    KC_PGDN,    HOLDMINS, HOLDA, HOLDS,   HOLDD, HOLDF, KC_G,           KC_H,   HOLDJ, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENTER,
                KC_LSPO,         HOLDZ,   KC_X,  KC_C,  KC_V, KC_B,     MYMEH,  KC_N,  KC_M,    KC_COMM, KC_DOT,  FNESC,   KC_RSPC,  KC_SLSH,
                CTLGRV,          KC_RALT,        OUTRSPCLO,   KC_LGUI,          OUTRSPCHI,      HOLDRGUI,                            CTLRGHT
),

[_BABBLE] = LAYOUT_all(
    RESET,      ___,      ___,   ___,     ___,   ___,    ___,   ___,     ___,    ___,   ___,     ___,     B_ZOUT,  B_ZIN,   B_SCAP,   B_SCAP,
    ___,        ___,      B_MAC, B_WIN,   B_MAC, B_BRLD, B_ROTB,         B_REDO,B_NLIST,B_BLIST, ___,     ___,     B_INDENT,B_DEDENT, ___,
    B_SCAP,     ___,      B_SELALL,B_SAVE,B_BDEV,B_FIND,  ___,           ___,    ___,   ___,     ___,     ___,     ___,     ___,
                ___,             B_UNDO,  B_CUT, B_COPY,B_PASTE,B_MODE,  ___,    B_NTAB,B_CTAB,  ___,     ___,     ___,     ___,      ___,
                ___,             ___,            ___,           ___,             ___,            ___,                                 CTLLEFT
),

[_HOLDJ] = LAYOUT_all(
    RGB_TOG,    ___,      ___,   ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     B_ZOUT,  B_ZIN,   B_SCAP,   B_SCAP,
    RGB_MOD,    ___,      ___, SGUI(KC_W),___,SGUI(KC_R),___,           ___,    ___,   ___,     ___,     ___,     B_INDENT,B_DEDENT, ___,
    RGB_RMOD,   ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   ___,     ___,     ___,     ___,     ___,
                ___,             ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
                ___,             ___,            B_INDENT,     B_DEDENT,        ___,            ___,                                 ___
),

[_HOLDA] = LAYOUT_all(
    ___,        ___,      ___,   ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     B_ZOUT,  B_ZIN,   B_SCAP,   B_SCAP,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   ___,     ___,     ___,     B_INDENT,B_DEDENT, ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   ___,     ___,     ___,     ___,     ___,
                ___,             ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
                KC_F5,           KC_F8,          ___,          ___,             ___,            ___,                                 ___
),

[_HOLDF] = LAYOUT_all(
    ___,        ___,      ___,   ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   KC_UP,   ___,     ___,     KC_LBRC, KC_RBRC,  ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,   KC_LEFT,KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR, ___,
                ___,             ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     KC_LPRN, ___,     ___,      KC_RPRN,
                ___,             ___,            ___,          ___,             ___,            ___,                                 ___
),

[_FUNCTION] = LAYOUT_all(
    RESET,      ___,      KC_F1, KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6,   KC_F7,  KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___,      ___,
    B_MAC,      ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
    B_WIN,      KC_CAPS,  SCRT1, SCRT2,  SCRT3,  SCRT4, SCRT5,          SCRT6,  SCRT7, SCRT8,   SCRT9,   SCRT10,  ___,     ___,
                ___,             ___,     ___,   ___,   ___,   ___,     ___,    SS_EMAIL,___,   ___,     ___,     ___,     ___,      ___,
                ___,             ___,            ___,          ___,             ___,            ___,                                 ___
),

[_LOWER] = LAYOUT_all(
    ___,        ___,      ___,   ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     ___,     ___,     KC_DEL,   KC_DEL,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   KC_UP,   ___,     ___,     KC_LBRC, KC_RBRC,  ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,   KC_LEFT,KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR, ___,
                ___,             ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     KC_LPRN, ___,     ___,      KC_RPRN,
                ___,             ___,            ___,          ___,             ___,            ___,                                 ___
),

[_RAISE] = LAYOUT_all(
    ___,        ___,      ___,   ___,     ___,   ___,   ___,   ___,     ___,    ___,    ___,    ___,     ___,     ___,     KC_DEL,   KC_DEL,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,    ___,    ___,     ___,     ___,     ___,      ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT, ___,     ___,     ___,
                ___,             ___,     ___,   ___,   ___,   ___,     ___,    ___,    ___,    ___,     ___,     ___,     ___,      ___,
                ___,             ___,            ___,          ___,             ___,            ___,                                 ___
),

[_NUMPAD] = LAYOUT_all(
    ___,        ___,      ___,   ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   ___,     ___,     ___,     ___,     ___,
                ___,             ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
                ___,             ___,            ___,          ___,             ___,            ___,                                 ___
),

[_SYMBOLS] = LAYOUT_all(
    ___,        ___,      ___,   ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
    ___,        ___,      ___,   ___,     ___,   ___,   ___,            ___,    ___,   ___,     ___,     ___,     ___,     ___,
                ___,             ___,     ___,   ___,   ___,   ___,     ___,    ___,   ___,     ___,     ___,     ___,     ___,      ___,
                ___,             ___,            ___,          ___,             ___,            ___,                                 ___
),

};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RGHT);
        }
    }
    else if (index == 2) {
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
}
#endif
