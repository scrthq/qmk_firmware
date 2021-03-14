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
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif
#ifdef RAW_ENABLE
#include "raw_hid.h"
#endif

#include "scrthq_layouts.h"
#include "scrthq_key_definitions.h"

#ifdef USE_BABBLEPASTE
extern uint8_t babble_mode;
#endif

#ifdef TAP_DANCE_ENABLE
    qk_tap_dance_action_t tap_dance_actions[] = {
        [SPENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
        [SPACELO] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, LOWER),
        [SPACEHI] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, RAISE),
        [BBLGUI] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LT(_BABBLE,KC_LGUI)),
    };
#endif

void set_layer_led_user(void) {
    #ifdef RGBLIGHT_ENABLE
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                #ifdef USE_BABBLEPASTE
                    switch (babble_mode) {
                        case BABL_WINDOWS_MODE:
                            rgblight_sethsv(30,255,255);
                            break;
                        case BABL_MAC_MODE:
                            rgblight_sethsv(122,255,255);
                            break;
                        default:
                            rgblight_sethsv(250,255,255);
                            break;
                    }
                #else
                    rgblight_sethsv(122,255,255);
                #endif
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
                break;
        }
    #endif
}

void keyboard_post_init_user(void) {
    set_layer_led_user();
}

#ifdef RAW_ENABLE
void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t *command_data = &(data[1]);
    #ifdef CONSOLE_ENABLE
        uint8_t *command_id   = &(data[0]);
        uprintf("HID COM ID: [%u], DATA: [%u]\n", *command_id, *command_data);
    #endif
    switch (*command_data) {
        #ifdef USE_BABBLEPASTE
        #ifdef BABL_MAC
        case set_babblepaste_mac: {
            if (babble_mode != BABL_MAC_MODE) {
                set_babble_mode(BABL_MAC_MODE);
                set_layer_led_user();
            }
            break;
        }
        #endif
        #ifdef BABL_WINDOWS
        case set_babblepaste_win: {
            if (babble_mode != BABL_WINDOWS_MODE) {
                set_babble_mode(BABL_WINDOWS_MODE);
                set_layer_led_user();
            }
            break;
        }
        default: {
            break;
        }
        #endif
        #endif
    }
    raw_hid_send(data, length);
}
#endif
