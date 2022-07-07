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

uint16_t console_info_timer = 0;
uint16_t console_info_limit = 10000;

uint8_t os_target = 1;
uint8_t layer     = 1;

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
    os_target  = get_os();
    layer = biton32(layer_state);
#ifdef CONSOLE_ENABLE
    if (timer_elapsed(console_info_timer) > console_info_limit) {
        switch (biton32(default_layer_state)) {
            case _MACBASE:
                switch (os_target) {
                    case _OS_MACOS:
                        uprintf("~~~~~~ STATE ~~~~~~\nDefLayer : _MACBASE\nOSKeys   : MacOS\n~~~~~~~~~~~~~~~~~~~\n");
                        break;
                    default:
                        uprintf("~~~~~~ STATE ~~~~~~\nDefLayer : _MACBASE\nOSKeys   : Windows\n~~~~~~~~~~~~~~~~~~~\n");
                        break;
                }
                break;
            default:
                switch (os_target) {
                    case _OS_MACOS:
                        uprintf("~~~~~~ STATE ~~~~~~\nDefLayer : _QWERTY\nOSKeys   : MacOS\n~~~~~~~~~~~~~~~~~~~\n");
                        break;
                    default:
                        uprintf("~~~~~~ STATE ~~~~~~\nDefLayer : _QWERTY\nOSKeys   : Windows\n~~~~~~~~~~~~~~~~~~~\n");
                        break;
                }
                break;
        }
        console_info_timer = timer_read();
    }
#endif
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > tab_time_limit) {
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
