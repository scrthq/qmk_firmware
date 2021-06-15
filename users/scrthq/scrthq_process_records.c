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
#include "scrthq_os_keys.h"
#include "scrthq.h"

#include "action.h"
#include "version.h"
#include "eeprom.h"

extern userspace_config_t runtime_userspace_config;
extern userspace_config_t stored_userspace_config;

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool send_os_key(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) void set_os(uint8_t os);
__attribute__((weak)) void store_userspace_config(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool    pressed = record->event.pressed;

#ifdef CONSOLE_ENABLE
    uprintf("PU: kc: [%u], col: [%u], row: [%u], pressed: [%u]\n", keycode, record->event.key.col, record->event.key.row, pressed);
#endif
    if (keycode > _OSKEY_START && keycode < _OSKEY_END) {
        if (pressed) {
            send_os_key(keycode, record);
        } else {
            return true;
        }
    }
    switch (keycode) {
        case EPRM:  // Resets EEPROM
            if (pressed) {
                eeconfig_init();
                default_layer_set(1UL << eeconfig_read_default_layer());
                layer_state_set(layer_state);
                set_os(_OS_MACOS);
                store_userspace_config();
            }
            return false;
            break;
        case QWERTY:
            if (pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
#ifdef UNICODE_ENABLE
        case SHRUG:
            bool is_shifted = get_mods() & MOD_MASK_SHIFT;
            if (pressed) {
                send_unicode_string((is_shifted ? "¯\\_(ツ)_/¯" : "ಠ_ಠ"));
            }
            return false;
            break;
#endif
        case MOFO:
            if (pressed) {
                SEND_STRING("Mofo from QMK!");
            }
            return false;
            break;
        case LOWER:
            if (pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _FUNCTION);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _FUNCTION);
            }
            return false;
            break;
        case RAISE:
            if (pressed) {
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
