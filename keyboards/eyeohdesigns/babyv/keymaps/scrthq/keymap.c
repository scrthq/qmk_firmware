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
#include "scrthq_layouts.h"
#include "scrthq_key_definitions.h"
#include <stdio.h>

bool has_layer_changed = false;
static uint8_t current_layer;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_ctl_tab_active = false;
uint16_t ctl_tab_timer = 0;
uint16_t tab_time_limit = 1200;

#ifdef USE_BABBLEPASTE
extern uint8_t babble_mode;
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_1u(
        FNTAB,      KC_Q,     KC_W,     KC_E,      KC_R,     KC_T,           KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        HOLDMINS,   KC_A,     HOLDS,    HOLDD,     HOLDF,    KC_G,           KC_H,      HOLDJBAB,   HOLDK,      KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSPO,    HOLDZ,    KC_X,     KC_C,      KC_V,     KC_B,           KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSPC,
        CTLGRV,                         KC_LALT,   OUTRSPCLO,KC_LGUI,        HOLDLEFT,   OUTRENTHI, HOLDRIGHT,                          FNESC
    ),

    [_LOWER] = LAYOUT_1u(
        KC_TILD,    KC_EXLM,   KC_AT,        KC_HASH,   KC_DLR,    KC_PERC,         KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL,
        KC_ESC,     _______,   _______,      _______,   _______,   _______,         _______,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE,
        _______,    _______,   _______,      _______,   _______,   _______,         _______,    _______,    KC_LT,      KC_GT,      KC_QUES,    _______,
        _______,                             _______,   _______,   _______,         _______,    _______,    _______,                            _______
    ),

    [_RAISE] = LAYOUT_1u(
        KC_GRV,     KC_1,       KC_2,        KC_3,      KC_4,      KC_5,            KC_6,       KC_7,      KC_8,       KC_9,       KC_0,       KC_PIPE,
        KC_ESC,     _______,    _______,     _______,   _______,   _______,         KC_LEFT,    KC_DOWN,   KC_UP,      KC_RGHT,    _______,    KC_BSLASH,
        _______,    _______,    _______,     _______,   _______,   _______,         _______,    _______,   _______,    _______,    _______,    _______,
        _______,                             _______,   _______,   _______,         _______,    _______,   _______,                            _______
    ),

    [_FUNCTION] = LAYOUT_1u(
        RESET,      KC_F1,      KC_F2,       KC_F3,     KC_F4,     KC_F5,           KC_F6,      KC_F7,     KC_F8,      KC_F9,      KC_F10,     KC_F11,
        KC_CAPS,    SCRT1,      SCRT2,       SCRT3,     SCRT4,     SCRT5,           SCRT6,      SCRT7,     SCRT8,      SCRT9,      SCRT10,     KC_F12,
        _______,    _______,    _______,     _______,   _______,   _______,         SS_EMAIL,   _______,   _______,    _______,    _______,    KC_F13,
        RESET,                               _______,   _______,   _______,         _______,    _______,   _______,                            _______
    ),

    [_BABBLE] = LAYOUT_1u(
        _______,    B_WIN,      B_DLW,       B_MAC,     B_BRLD,    B_ROTB,          B_REDO,     B_NLIST,    B_BLIST,   B_ZOUT,     B_ZIN,      B_SCAP,
        _______,    B_SELALL,   B_SAVE,      B_BDEV,    B_FIND,    B_CLIPHIST,      B_RPLACE,   _______,    KC_EQUAL,  B_MSEL,     _______,    _______,
        _______,    B_UNDO,     B_CUT,       B_COPY,    B_PASTE,   B_PSTPLN,        B_NTAB,     B_CTAB,     _______,   _______,    _______,    _______,
        HYPR(KC_LEFT),                       B_INDENT,  B_DEDENT,  HYPR(KC_RGHT),   HYPR(KC_LEFT), _______, _______,                           HYPR(KC_RGHT)
    ),

    [_HOLDF] = LAYOUT_1u(
        KC_PLUS,    KC_EQUAL,   SGUI(KC_W),  _______,   SGUI(KC_R),MEH(KC_T),       _______,    _______,    _______,   _______,    KC_LBRC,    KC_RBRC,
        KC_DLR,     KC_UNDS,    MEH(KC_S),   DLRUNDER,  _______,   _______,         DLRUNDER,   _______,    _______,   B_MSEL,     KC_LCBR,    KC_RCBR,
        LSFT(KC_8), KC_SLASH,   _______,     _______,   _______,   _______,         _______,    B_LSEL,     _______,   _______,    KC_LPRN,    KC_RPRN,
        KC_F5,                               KC_F8,     B_GSOL,    B_GEOL,          B_FOLDALL,  B_FOLDREC,  B_UFOLDREC,                        B_UFOLDALL
    ),

    [_NUMPAD] = LAYOUT_1u(
        _______,    LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),     _______,    KC_7,       KC_8,      KC_9,       _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,        _______,    KC_4,       KC_5,      KC_6,       _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,        _______,    KC_1,       KC_2,      KC_3,       _______,    _______,
        _______,                            _______,    B_L1W,      B_R1W,          _______,    KC_0,       KC_0,                              TO(_QWERTY)
    ),

    [_SYMBOLS] = LAYOUT_1u(
        RGB_TOG,    RGB_HUI,    RGB_HUD,    _______,    _______,    _______,        _______,    LSFT(KC_7), LSFT(KC_8),LSFT(KC_9), _______,    _______,
        RGB_MOD,    RGB_SAI,    RGB_SAD,    _______,    _______,    TO(_GAMING),    _______,    LSFT(KC_4), LSFT(KC_5),LSFT(KC_6), _______,    KC_MINUS,
        RGB_RMOD,   RGB_VAI,    RGB_VAD,    _______,    _______,    _______,        _______,    LSFT(KC_1), LSFT(KC_2),LSFT(KC_3), _______,    _______,
        _______,                            _______,    B_GTOP,     B_GEND,      BABL_CUR_MODE, LSFT(KC_0), LSFT(KC_0),                        TO(_QWERTY)
    ),

    [_GAMING] = LAYOUT_1u(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,           KC_F1,      KC_7,       KC_8,      KC_9,       _______,    _______,
        KC_ESCAPE,  KC_A,       KC_S,       KC_D,       KC_F,       KC_G,           KC_F2,      KC_4,       KC_5,      KC_6,       _______,    _______,
        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,           KC_F3,      KC_1,       KC_2,      KC_3,       _______,    _______,
        KC_LCTRL,                           KC_LALT,    KC_SPACE,   KC_1,           KC_F4,      KC_0,       KC_0,                              TO(_QWERTY)
    )
};

void matrix_scan_user(void) {
#ifdef RGBLIGHT_ENABLE
    uint8_t layer = biton32(layer_state);

    if (current_layer == layer) {
        has_layer_changed = false;
    } else {
        has_layer_changed = true;
        current_layer = layer;
    }
    if (has_layer_changed) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                rgblight_sethsv(122,255,255);
                break;
            case _LOWER:
                rgblight_sethsv(189,255,255);
                break;
            case _RAISE:
                rgblight_sethsv(199,255,255);
                break;
            case _FUNCTION:
                rgblight_sethsv(202,255,255);
                break;
            //case _HOLDA:
            //    rgblight_sethsv(000,255,255);
            //    break;
            case _HOLDJ:
                rgblight_sethsv(180,255,255);
                break;
            case _HOLDF:
                rgblight_sethsv(26,255,255);
                break;
            case _BABBLE:
                rgblight_sethsv(140,255,255);
                break;
            case _NUMPAD:
                rgblight_sethsv(90,255,255);
                break;
            case _SYMBOLS:
                rgblight_sethsv(156,255,255);
                break;
            case _CODE:
                rgblight_sethsv(138,255,255);
                break;
            case _GAMING:
                rgblight_sethsv(255,255,255);
                break;
            default:
                rgblight_sethsv(000,255,255);
        }
    }
#endif
}
