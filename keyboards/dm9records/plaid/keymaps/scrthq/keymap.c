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

[_QWERTY] = LAYOUT_scrthq(
    _________________QWERTY_L1_________________,        _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________,        _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________,        _________________QWERTY_R3_________________,
    ____________OLKB_QWERTY_L4_________________,        ____________OLKB_QWERTY_R4_________________
),

[_LOWER] = LAYOUT_scrthq(
    __________________LOWER_L1_________________,        __________________LOWER_R1_________________,
    __________________LOWER_L2_________________,        __________________LOWER_R2_________________,
    __________________LOWER_L3_________________,        __________________LOWER_R3_________________,
    _____________OLKB_LOWER_L4_________________,        _____________OLKB_LOWER_R4_________________
),

[_RAISE] = LAYOUT_scrthq(
    KC_GRV,  KC_1,     KC_2,       KC_3,       KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_BSPC,
    KC_ESC,  _______,  _______,    _______,    _______,  _______,  _______,  KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______, _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______, _______,  KC_SLSH,  _______,
    _______, _______,  C(KC_LBRC), C(KC_RBRC), _______,  TD_SPENT, TD_SPENT, _______,  B_L1W,   B_PGDN,   B_PGUP,   B_R1W
),

[_FUNCTION] = LAYOUT_scrthq(
    RESET,       KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  B_SCAP,
    KC_CAPS,     KC_SECRET_1,  KC_SECRET_2,  KC_SECRET_3,  KC_SECRET_4,  KC_SECRET_5,  _______,  _______,  _______,  _______,  _______, _______,
    _______,     _______,  _______,  _______,  _______,  SHRUG,  VRSN,  MOFO,     _______,  _______,  B_PGUP,  _______,
    TO(_BABBLE), _______,  _______,  _______,  _______,  KC_ENT,   KC_ENT,   _______,  B_GSOL,  B_GEND,    B_GTOP,  B_GEOL
),

[_HOLDA] = LAYOUT_scrthq(
    ___________________6_BLANK_________________, ___________________6_BLANK_________________,
    ___________________6_BLANK_________________, ___________________6_BLANK_________________,
    ___________________6_BLANK_________________, ___________________6_BLANK_________________,
    ____________OLKB_HOLD_A_L4_________________, ___________________6_BLANK_________________
),

[_HOLDF] = LAYOUT_scrthq(
    KC_TILD,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_CAPS,     _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______,     _______, _______, _______, _______, _______, _______, _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN,
    TO(_QWERTY), _______, _______, _______, _______, KC_ENT,  KC_ENT,  _______, B_L1W, B_PGDN,  B_PGUP,  B_R1W
),

[_HOLDJ] = LAYOUT_scrthq(
    KC_GRV,      B_VI,     B_WIN,    B_MAC,    B_BRLD,  B_ROTB,   B_REDO,  B_NLIST,  B_BLIST, B_ZOUT,   B_ZIN,    B_SCAP,
    KC_TAB,      B_SELALL, B_SAVE,   B_BDEV,   B_FIND,  _______,  _______, KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,     B_UNDO,   B_CUT,    B_COPY,   B_PASTE, B_MODE,   B_NTAB,  _______,  _______, _______,  KC_SLSH,  _______,
    TO(_QWERTY), _______,  B_INDENT, B_DEDENT, _______, KC_ENT,   KC_ENT,  _______,  B_GSOL,  B_PGDN,   B_PGUP,   B_GEOL
),

[_BABBLE] = LAYOUT_scrthq(
    TO(_QWERTY), B_MAC,    B_WIN,    _______,  B_BRLD,  B_ROTB,  B_REDO,   B_NLIST,  B_BLIST,  B_ZOUT,  B_ZIN,    B_SCAP,
    _______,     B_SELALL, B_SAVE,   B_BDEV,   B_FIND,  _______, _______,  _______,  _______, _______,  B_INDENT, B_DEDENT,
    _______,     B_UNDO,   B_CUT,    B_COPY,   B_PASTE, B_MODE,  B_NTAB,  B_CTAB,    _______, _______,  _______,  _______,
    _______,     _______,  B_INDENT, B_DEDENT, _______, KC_ENT,  KC_ENT,   _______,  B_GSOL, B_PGDN,    B_PGUP,   B_GEOL
),

[_NUMPAD] = LAYOUT_scrthq(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_7,     KC_8,     KC_9,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_4,     KC_5,     KC_6,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,     KC_2,     KC_3,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_TRNS,  KC_TRNS,  KC_0,     _______,  _______,  _______,  _______
),

[_SYMBOLS] = LAYOUT_scrthq(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_TRNS,  KC_TRNS,  LSFT(KC_0), _______,    _______,    _______,  _______
)

};

bool led_update_user(led_t led_state) {
    /* writePin(LED_RED, led_state.caps_lock); */
    return false;
}

void keyboard_post_init_user(void) {
    writePin(LED_GREEN, 1);
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QWERTY:
        writePin(LED_GREEN, 1);
        writePin(LED_RED, 0);
        break;
    case _LOWER:
        writePin(LED_GREEN, 0);
        writePin(LED_RED, 1);
        break;
    case _RAISE:
        writePin(LED_GREEN, 1);
        writePin(LED_RED, 1);
        break;
    case _FUNCTION:
        writePin(LED_GREEN, 1);
        writePin(LED_RED, 0);
        break;
    case _HOLDF:
        writePin(LED_GREEN, 1);
        writePin(LED_RED, 1);
        break;
    case _HOLDJ:
        writePin(LED_GREEN, 0);
        writePin(LED_RED, 0);
        break;
    case _BABBLE:
        writePin(LED_GREEN, 1);
        writePin(LED_RED, 1);
        break;
    default: //  for any other layers, or the default layer
        writePin(LED_GREEN, 1);
        writePin(LED_RED, 0);
        break;
    }
    return state;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: " + get_highest_layer(layer_state) + "\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
