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
#include "scrthq_key_definitions.h"

bool has_layer_changed = false;
static uint8_t current_layer;

#ifdef USE_BABBLEPASTE
extern uint8_t babble_mode;
#endif

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    if (current_layer == layer) {
        has_layer_changed = false;
    } else {
        has_layer_changed = true;
        current_layer = layer;
    }
#ifdef RGBLIGHT_ENABLE
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

void matrix_init_user(void) {
    rgblight_sethsv(122,255,255);
}
