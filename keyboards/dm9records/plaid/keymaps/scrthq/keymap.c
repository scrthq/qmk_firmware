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

#define HOLDF LT(_HOLDF,KC_F)
#define HOLDJ LT(_HOLDJ,KC_J)
#define HOLDS LT(_SYMBOLS,KC_S)
#define HOLDD LT(_NUMPAD,KC_D)
#define HOLDMINS LT(_BABBLE,KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |     |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
/* [0] = LAYOUT_plaid_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_RALT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
), */
[_QWERTY] = LAYOUT_plaid_grid(
    KC_TAB,        KC_Q,        KC_W,       KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
    HOLDMINS,      KC_A,        HOLDS,      HOLDD,   HOLDF,  KC_G,    KC_H,    HOLDJ,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSPO,       CTL_T(KC_Z), KC_X,       KC_C,    KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    CTL_T(KC_GRV), KC_LGUI,     MEH(KC_NO), KC_RALT, LOWER,  KC_SPC,  KC_SPC,  RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_plaid_grid(
    KC_TILD,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    S(KC_MINS), _______, _______, _______, _______, _______,  _______,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______,    _______, _______, _______, _______, _______,  _______,  _______, KC_LT,   KC_GT,   KC_QUES, _______,
    _______,    _______, _______, _______, _______, TD_SPENT, TD_SPENT, _______, B_L1W,   B_PGDN,  B_PGUP,  B_R1W
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | DEL  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* [2] = LAYOUT_plaid_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, B_PGUP, B_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
), */
[_RAISE] = LAYOUT_plaid_grid(
    KC_GRV,  KC_1,     KC_2,       KC_3,       KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_BSPC,
    KC_ESC,  _______,  _______,    _______,    _______,  _______,  _______,  KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______, _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______, _______,  KC_SLSH,  _______,
    _______, _______,  C(KC_LBRC), C(KC_RBRC), _______,  TD_SPENT, TD_SPENT, _______,  B_L1W,   B_PGDN,   B_PGUP,   B_R1W
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_plaid_grid(
    RESET,       KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  B_SCAP,
    KC_CAPS,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
    _______,     _______,  _______,  _______,  _______,  _______,  _______,  MOFO,     _______,  _______,  B_PGUP,  _______,
    TO(_BABBLE), _______,  _______,  _______,  _______,  KC_ENT,   KC_ENT,   _______,  B_GSOL,  B_GEND,    B_GTOP,  B_GEOL
),

/* Hold F
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_HOLDF] = LAYOUT_plaid_grid(
    KC_TILD,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_CAPS,     _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______,     _______, _______, _______, _______, _______, _______, _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN,
    TO(_QWERTY), _______, _______, _______, _______, KC_ENT,  KC_ENT,  _______, B_L1W, B_PGDN,  B_PGUP,  B_R1W
),

/* Hold J
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_HOLDJ] = LAYOUT_plaid_grid(
    KC_GRV,      B_VI,     B_WIN,    B_MAC,    B_BRLD,  B_ROTB,   B_REDO,  B_NLIST,  B_BLIST, B_ZOUT,   B_ZIN,    B_SCAP,
    KC_TAB,      B_SELALL, B_SAVE,   B_BDEV,   B_FIND,  _______,  _______, KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,     B_UNDO,   B_CUT,    B_COPY,   B_PASTE, B_MODE,   B_NTAB,  _______,  _______, _______,  KC_SLSH,  _______,
    TO(_QWERTY), _______,  B_INDENT, B_DEDENT, _______, KC_ENT,   KC_ENT,  _______,  B_GSOL,  B_PGDN,   B_PGUP,   B_GEOL
),

/* BabblePaste Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BABBLE] = LAYOUT_plaid_grid(
    TO(_QWERTY), B_MAC,    B_WIN,    _______,  B_BRLD,  B_ROTB,  B_REDO,   B_NLIST,  B_BLIST,  B_ZOUT,  B_ZIN,    B_SCAP,
    _______,     B_SELALL, B_SAVE,   B_BDEV,   B_FIND,  _______, _______,  _______,  _______, _______,  B_INDENT, B_DEDENT,
    _______,     B_UNDO,   B_CUT,    B_COPY,   B_PASTE, B_MODE,  B_NTAB,  B_CTAB,    _______, _______,  _______,  _______,
    _______,     _______,  B_INDENT, B_DEDENT, _______, KC_ENT,  KC_ENT,   _______,  B_GSOL, B_PGDN,    B_PGUP,   B_GEOL
),


/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_plaid_grid(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_7,     KC_8,     KC_9,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_4,     KC_5,     KC_6,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,     KC_2,     KC_3,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_TRNS,  KC_TRNS,  KC_0,     _______,  _______,  _______,  _______
),


/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_plaid_grid(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_TRNS,  KC_TRNS,  LSFT(KC_0), _______,    _______,    _______,  _______
),


/* Empty template
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EMPTY] = LAYOUT_plaid_grid(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
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
