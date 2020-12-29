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

#include "action.h"
#include "version.h"
#include "eeprom.h"

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_pressed = record->event.pressed;

#ifdef CONSOLE_ENABLE
    uprintf("PU: kc: [%u], col: [%u], row: [%u], pressed: [%u]\n", keycode, record->event.key.col, record->event.key.row, is_pressed);
#endif
#ifdef USE_BABBLEPASTE
    if (keycode > BABBLE_START && keycode < BABBLE_END_RANGE) {
        if (is_pressed) {
            /* if (keycode >= BABL_DO_MAC && keycode <= BABL_DO_VI) {
                userspace_config.raw = keycode;
                eeconfig_update_user(userspace_config.raw);
            } */
            babblePaste(keycode);
        } else {
            return true;
        }
    }
#endif
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case VRSN:
            if (is_pressed) {
                send_string_with_delay_P(PSTR("# " QMK_KEYBOARD ":" QMK_KEYMAP " @ " QMK_BUILDDATE "\n"), MACRO_DELAY);
            }
            return false;
#ifdef UNICODE_ENABLE
        case SHRUG:
            bool is_shifted = get_mods() & MOD_MASK_SHIFT;
            if (is_pressed) {
                send_unicode_string((is_shifted ? "¯\\_(ツ)_/¯" : "ಠ_ಠ"));
            }
            return false;
            break;
#endif
        case MOFO:
            if (is_pressed) {
                SEND_STRING("Mofo from QMK!");
            }
            return false;
            break;
        case LOWER:
            if (is_pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _FUNCTION);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _FUNCTION);
            }
            return false;
            break;
        case RAISE:
            if (is_pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _FUNCTION);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _FUNCTION);
            }
            return false;
            break;
    }
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}
