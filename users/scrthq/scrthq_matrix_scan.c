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

#include "scrthq.h"
#include "scrthq_os_keys.h"
#include "scrthq_key_definitions.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_ctl_tab_active = false;
uint16_t ctl_tab_timer = 0;
uint16_t tab_time_limit = 1200;

bool has_layer_changed = false;
static uint8_t current_layer;

__attribute__((weak)) uint8_t get_os(void) {return 1;}
__attribute__((weak)) void set_layer_led_user(void) { return; }

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > tab_time_limit) {
            uint8_t os_target  = get_os();
            switch (os_target) {
                case 0:
                    unregister_code(KC_LGUI);
                    break;
                default:
                    unregister_code(KC_LALT);
                    break;
            }
            is_alt_tab_active = false;
        }
    }
    if (is_ctl_tab_active) {
        if (timer_elapsed(ctl_tab_timer) > tab_time_limit) {
            unregister_code(KC_LCTL);
            is_ctl_tab_active = false;
        }
    }

    if (current_layer == layer) {
        has_layer_changed = false;
    } else {
        has_layer_changed = true;
        current_layer = layer;
    }
    if (has_layer_changed) {
        set_layer_led_user();
    }
}
