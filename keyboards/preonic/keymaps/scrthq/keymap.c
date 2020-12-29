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
#include "muse.h"
#include "scrthq.h"
#include "scrthq_layouts.h"
#include "scrthq_key_definitions.h"

/* #if (!defined(LAYOUT_scrthq_5x12))
    #define LAYOUT_scrthq_5x12(...)      LAYOUT_ortho_5x12(__VA_ARGS__)
#endif */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    _________________QWERTY_L1_________________,        _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________,        _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________,        _________________QWERTY_R3_________________,
    ____________OLKB_QWERTY_L4_________________,        ____________OLKB_QWERTY_R4_________________
),

[_LOWER] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    __________________LOWER_L1_________________,        __________________LOWER_R1_________________,
    __________________LOWER_L2_________________,        __________________LOWER_R2_________________,
    __________________LOWER_L3_________________,        __________________LOWER_R3_________________,
    _____________OLKB_LOWER_L4_________________,        _____________OLKB_LOWER_R4_________________
),

[_RAISE] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    __________________RAISE_L1_________________,        __________________RAISE_R1_________________,
    __________________RAISE_L2_________________,        __________________RAISE_R2_________________,
    __________________RAISE_L3_________________,        __________________RAISE_R3_________________,
    _____________OLKB_RAISE_L4_________________,        _____________OLKB_RAISE_R4_________________
),

[_FUNCTION] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    RESET,       KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  B_SCAP,
    KC_CAPS,     KC_SECRET_1,  KC_SECRET_2,  KC_SECRET_3,  KC_SECRET_4,  KC_SECRET_5,  _______,  _______,  _______,  _______,  _______, _______,
    _______,     _______,  _______,  _______,  _______,  SHRUG,  VRSN,  MOFO,     _______,  _______,  B_PGUP,  _______,
    TO(_BABBLE), _______,  _______,  _______,  _______,  KC_ENT,   KC_ENT,   _______,  B_GSOL,  B_GEND,    B_GTOP,  B_GEOL
),

[_HOLDA] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________, ___________________6_XXXXX_________________,
    ___________________6_BLANK_________________, ___________________6_BLANK_________________,
    ___________________6_BLANK_________________, ___________________6_BLANK_________________,
    ___________________6_BLANK_________________, ___________________6_BLANK_________________,
    ____________OLKB_HOLD_A_L4_________________, ___________________6_BLANK_________________
),

[_HOLDF] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    KC_TILD,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_CAPS,     _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______,     _______, _______, _______, _______, _______, _______, _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN,
    TO(_QWERTY), _______, _______, _______, _______, KC_ENT,  KC_ENT,  _______, B_L1W, B_PGDN,  B_PGUP,  B_R1W
),

[_HOLDJ] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    KC_GRV,      B_VI,     B_WIN,    B_MAC,    B_BRLD,  B_ROTB,   B_REDO,  B_NLIST,  B_BLIST, B_ZOUT,   B_ZIN,    B_SCAP,
    KC_TAB,      B_SELALL, B_SAVE,   B_BDEV,   B_FIND,  _______,  _______, KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,     B_UNDO,   B_CUT,    B_COPY,   B_PASTE, B_MODE,   B_NTAB,  _______,  _______, _______,  KC_SLSH,  _______,
    TO(_QWERTY), _______,  B_INDENT, B_DEDENT, _______, KC_ENT,   KC_ENT,  _______,  B_GSOL,  B_PGDN,   B_PGUP,   B_GEOL
),

[_BABBLE] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    TO(_QWERTY), B_MAC,    B_WIN,    _______,  B_BRLD,  B_ROTB,  B_REDO,   B_NLIST,  B_BLIST,  B_ZOUT,  B_ZIN,    B_SCAP,
    _______,     B_SELALL, B_SAVE,   B_BDEV,   B_FIND,  _______, _______,  _______,  _______, _______,  B_INDENT, B_DEDENT,
    _______,     B_UNDO,   B_CUT,    B_COPY,   B_PASTE, B_MODE,  B_NTAB,  B_CTAB,    _______, _______,  _______,  _______,
    _______,     _______,  B_INDENT, B_DEDENT, _______, KC_ENT,  KC_ENT,   _______,  B_GSOL, B_PGDN,    B_PGUP,   B_GEOL
),

[_NUMPAD] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_7,     KC_8,     KC_9,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_4,     KC_5,     KC_6,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,     KC_2,     KC_3,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_TRNS,  KC_TRNS,  KC_0,     _______,  _______,  _______,  _______
),

[_SYMBOLS] = LAYOUT_scrthq_5x12(
    ___________________6_XXXXX_________________,        ___________________6_XXXXX_________________,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_TRNS,  KC_TRNS,  LSFT(KC_0), _______,    _______,    _______,  _______
)

};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
