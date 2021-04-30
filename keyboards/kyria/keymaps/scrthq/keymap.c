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

extern bool is_alt_tab_active;
extern uint16_t alt_tab_timer;
extern bool is_ctl_tab_active;
extern uint16_t ctl_tab_timer;
extern uint16_t tab_time_limit;

#ifdef USE_BABBLEPASTE
extern uint8_t babble_mode;
#endif

__attribute__((weak)) void babble_mode_increment(void);
__attribute__((weak)) void babble_mode_decrement(void);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_scrthq_kyria(
        FNTAB,    KC_Q,   KC_W,   KC_E,  KC_R,  KC_T,                                         KC_Y, KC_U,  KC_I,  KC_O,  KC_P,    KC_BSPC,
        HOLDMINS, KC_A,   HOLDS,  HOLDD, HOLDF, KC_G,                                         KC_H, HOLDJBAB, HOLDK, KC_L,  KC_SCLN, KC_QUOT,
    KC_LSPO,  HOLDZ,  KC_X,   KC_C,  KC_V,  KC_B,   KC_NO,  FNESC,              KC_MS_BTN1, KC_MS_BTN2, KC_N, KC_M,  KC_COMM,KC_DOT,KC_SLSH,KC_RSPC,
                    TG(_SYMBOLS), CTLGRV,  OUTRSPCLO, KC_LALT,  KC_LGUI,        MYMEH, KC_LEFT,  OUTRENTHI, HOLDRIGHT, TG(_SYMBOLS)
    ),

    [_LOWER] = LAYOUT_scrthq_kyria(
        KC_TILD,    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                                               KC_CIRC,    KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_DEL,
        KC_ESC,    _______,   _______,   _______,   _______,   _______,                                              _______,    KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   KC_PIPE,
        _______,    _______,   _______,   _______,   _______,   _______,  _______,  _______,      _______,  _______,  _______,    _______,   KC_LT,     KC_GT,     KC_QUES,   _______,
                            _______,   _______,  _______, _______,  _______,                                          _______,  _______,  _______,  _______, TO(_QWERTY)
    ),

    [_RAISE] = LAYOUT_scrthq_kyria(
        KC_GRV,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                                 KC_6,       KC_7,      KC_8,      KC_9,      KC_0,      KC_PIPE,
        KC_ESC,      _______,   _______,   _______,   _______,   _______,                                              KC_LEFT,    KC_DOWN,   KC_UP,     KC_RGHT,   _______,   KC_BSLASH,
        _______,     _______,   _______,   _______,   _______,   _______,   _______, _______,      _______,  _______,  _______,    _______,   _______,   _______,   _______,   _______,
                                _______,   _______,   _______,   _______, _______,                               _______,    _______,   _______,   _______,   TO(_QWERTY)
    ),

    [_FUNCTION] = LAYOUT_scrthq_kyria(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_CAPS, SCRT1,   SCRT2,   SCRT3,   SCRT4,   SCRT5,                                             SCRT6,   SCRT7,   SCRT8,   SCRT9,   SCRT10,  KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, SS_EMAIL,_______, _______, _______, _______, KC_F13,
                                _______,  RESET,     SS_EMAIL,DLRUNDER,SCRT13,        _______, SCRT14,  SCRT15,  SCRT16,  TO(_QWERTY)
    ),

    [_BABBLE] = LAYOUT_scrthq_kyria(
        _______, B_WIN,    B_DLW,  B_MAC, B_BRLD, B_ROTB,                                      B_REDO,   B_NLIST, B_BLIST,  B_ZOUT,  B_ZIN,   B_SCAP,
        _______, B_SELALL, B_SAVE, B_BDEV, B_FIND, B_CLIPHIST,                                 B_RPLACE, _______, KC_EQUAL, B_MSEL,  _______, _______,
        _______, B_UNDO,   B_CUT,  B_COPY, B_PASTE, B_PSTPLN, B_GSOL, B_GEOL,       B_GSOL, B_GEOL, B_NTAB,  B_CTAB,_______, _______, _______, _______,
                    _______, B_INDENT, B_DEDENT, HYPR(KC_LEFT), HYPR(KC_RGHT),      HYPR(KC_LEFT), _______, HYPR(KC_RGHT),_______,  TO(_QWERTY)
    ),

    [_HOLDF] = LAYOUT_scrthq_kyria(
        KC_PLUS, KC_EQUAL, SGUI(KC_W), _______, SGUI(KC_R), MEH(KC_T),                                         _______, _______, _______, _______, KC_LBRC, KC_RBRC,
        KC_DLR,  KC_UNDS, MEH(KC_S),     DLRUNDER,  _______,    _______,                                       DLRUNDER, _______, _______, B_MSEL,  KC_LCBR, KC_RCBR,
        LSFT(KC_8),KC_SLASH, _______, _______, _______, _______, _______, _______,       _______, _______, _______, B_LSEL,  _______, _______, KC_LPRN, KC_RPRN,
                                _______, KC_F5, KC_F8, B_GSOL, B_GEOL,                   B_FOLDALL, B_FOLDREC, B_UFOLDREC, B_UFOLDALL, TO(_QWERTY)
    ),

    [_NUMPAD] = LAYOUT_scrthq_kyria(
        _______, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),                               _______, KC_7,     KC_8,     KC_9, _______, _______,
        _______, _______, _______, _______, _______, _______,                                              _______, KC_4,     KC_5,     KC_6, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_1,     KC_2,     KC_3, _______, _______,
                                _______, _______, _______, B_L1W, B_R1W,                 _______, _______, KC_0, KC_0, TO(_QWERTY)
    ),

    [_SYMBOLS] = LAYOUT_scrthq_kyria(
        RGB_TOG,  _______, _______, _______, _______, _______,                                                _______, LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9), _______, _______,
        RGB_MOD,  _______, _______, _______, _______, TO(_GAMING),                                            _______, LSFT(KC_4),     LSFT(KC_5),     LSFT(KC_6), _______, KC_MINUS,
        RGB_RMOD, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3), _______, _______,
                                TO(_QWERTY), RESET, _______, B_GTOP, B_GEND,              _______, _______, LSFT(KC_0), LSFT(KC_0), TO(_QWERTY)
    ),

    [_GAMING] = LAYOUT_scrthq_kyria(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R, KC_T,                                     KC_Y, KC_U,  KC_I,  KC_O,  KC_P,    KC_BSPC,
        KC_ESCAPE,KC_A,   KC_S,    KC_D,    KC_F, KC_G,                                     KC_H, HOLDJBAB, HOLDK, KC_L,  KC_SCLN, KC_QUOT,
        KC_LSHIFT,KC_Z,   KC_X,    KC_C,    KC_V, KC_B,     KC_3,    KC_2,    FNESC, MYMEH, KC_N, KC_M,  KC_COMM,KC_DOT,KC_SLSH,KC_RSPC,
                        TO(_QWERTY), KC_LCTRL, KC_SPACE, KC_LALT, KC_1,      HOLDRGUI, HOLDLEFT,  OUTRENTHI, HOLDRIGHT, TO(_QWERTY)
    )
};

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_status(void) {
    // Host Keyboard Layer Status
    //oled_write_ln_P(PSTR(" ~ ~ Kyria x QMK ~ ~"), false);
    oled_write_P(PSTR("\n\nLayer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("FUNCTION"), false);
            break;
        //case _HOLDA:
        //    oled_write_P(PSTR("HOLD A"), false);
        //    break;
        case _HOLDJ:
            oled_write_P(PSTR("HOLD J"), false);
            break;
        case _HOLDF:
            oled_write_P(PSTR("HOLD F"), false);
            break;
        case _BABBLE:
            oled_write_P(PSTR("BABBLE"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPAD"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("SYMBOLS"), false);
            break;
        //case _ENCODER:
        //    oled_write_P(PSTR("ENCODER"), false);
        //    break;
        case _CODE:
            oled_write_P(PSTR("CODE"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("GAMING"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }

    #ifdef USE_BABBLEPASTE
    oled_write_P(PSTR("\n\nBabble: "), false);
    switch (babble_mode) {
        case BABL_WINDOWS_MODE:
            oled_write_P(PSTR("Windows  "), false);
            break;
        case BABL_MAC_MODE:
            oled_write_P(PSTR("macOS    "), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }
    #endif
    //#ifdef RGBLIGHT_ENABLE
    //static char rgbStatusLine1[26] = {0};
    //snprintf(rgbStatusLine1, sizeof(rgbStatusLine1), "\n\nRGB Mode: %d", rgblight_get_mode());
    //oled_write_ln(rgbStatusLine1, false);
    //static char rgbStatusLine2[26] = {0};
    //snprintf(rgbStatusLine2, sizeof(rgbStatusLine2), "h:%d s:%d v:%d", rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
    //oled_write_ln(rgbStatusLine2, false);
    //#endif
}

/* layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _GAMING:
        rgblight_sethsv(90, 255, 255);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv(255, 255, 255);
        break;
    }
    return state;
} */

void oled_task_user(void) {
    render_status();
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _BABBLE: case _HOLDJ: // _BABBLE and _HOLDJ layers -- change BabblePaste mode
            if (index == 0) { /* First encoder */
                if (clockwise) {
                    babble_mode_increment();
                } else {
                    babble_mode_decrement();
                }
                break;
            } else if (index == 1) {/* Second encoder */
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            }
        case _FUNCTION: case _RAISE: // _FUNCTION and _RAISE layers -- change RGB mode
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
            break;
        case _LOWER: case _CODE: // _LOWER and _CODE layers -- Ctrl+Tab
            if (!is_ctl_tab_active) {
                is_ctl_tab_active = true;
                register_code(KC_LCTL);
            }
            ctl_tab_timer = timer_read();
            if (clockwise) {
                tap_code16(KC_TAB);
            } else {
                tap_code16(S(KC_TAB));
            }
            break;
        default: // everything else, do alt-tab
            if (index == 1) { /* Second encoder */
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    #ifdef USE_BABBLEPASTE
                    switch (babble_mode) {
                        case BABL_MAC_MODE:
                            register_code(KC_LGUI);
                            break;
                        default:
                            register_code(KC_LALT);
                            break;
                    }
                    #else
                    register_code(KC_LALT);
                    #endif
                }
                alt_tab_timer = timer_read();
                if (clockwise) {
                    tap_code16(KC_TAB);
                } else {
                    tap_code16(S(KC_TAB));
                }
            } else if (index == 0) { /* First encoder */
                if (clockwise) {
                    #ifdef MOUSEKEY_ENABLE
                        tap_code(KC_MS_WH_DOWN);
                    #else
                        tap_code(KC_PGDN);
                    #endif
                } else {
                    #ifdef MOUSEKEY_ENABLE
                        tap_code(KC_MS_WH_UP);
                    #else
                        tap_code(KC_PGUP);
                    #endif
                }
            }
            break;
    }
}
#endif
