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

void keyboard_post_init_user(void) {
    /* #ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom(); // enables Rgb, without saving settings
    rgblight_sethsv_noeeprom(255, 255, 255); // sets the color to teal/cyan without saving
    #endif */
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
                babble_led_user();
            }
            break;
        }
        #endif
        #ifdef BABL_WINDOWS
        case set_babblepaste_win: {
            if (babble_mode != BABL_WINDOWS_MODE) {
                set_babble_mode(BABL_WINDOWS_MODE);
                babble_led_user();
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

void babble_led_user(void) {
/*
#ifdef RGBLIGHT_ENABLE
#  ifdef USE_BABBLEPASTE

#    ifdef BABL_WINDOWS
    if (babble_mode == BABL_WINDOWS_MODE) {
        if (BABL_LED_INDEX > 0) {
            rgblight_setrgb_at(RGBLIGHT_COLOR_MS, BABL_LED_INDEX);
        } else {
            rgblight_setrgb(RGBLIGHT_COLOR_MS);
        }
    }
#    endif
#    ifdef BABL_READMUX
    if (babble_mode == BABL_READMUX_MODE) {
        if (BABL_LED_INDEX > 0) {
            rgblight_setrgb_at(RGBLIGHT_COLOR_READMUX, BABL_LED_INDEX);
        } else {
            rgblight_setrgb(RGBLIGHT_COLOR_READMUX);
        }
    }
#    endif
#    ifdef BABL_MAC
    if (babble_mode == BABL_MAC_MODE) {
        if (BABL_LED_INDEX > 0) {
            rgblight_setrgb_at(RGBLIGHT_COLOR_MAC, BABL_LED_INDEX);
        } else {
            rgblight_setrgb(RGBLIGHT_COLOR_MAC);
        }
    }
#    endif
#    ifdef BABL_VI
    if (babble_mode == BABL_VI_MODE) {
        if (BABL_LED_INDEX > 0) {
            rgblight_setrgb_at(RGBLIGHT_COLOR_VI, BABL_LED_INDEX);
        } else {
            rgblight_setrgb(RGBLIGHT_COLOR_VI);
        }
    }
#    endif
#    ifdef BABL_EMACS
    if (babble_mode == BABL_EMACS_MODE) {
        if (BABL_LED_INDEX > 0) {
            rgblight_setrgb_at(RGBLIGHT_COLOR_EMACS, BABL_LED_INDEX);
        } else {
            rgblight_setrgb(RGBLIGHT_COLOR_EMACS);
        }
    }
#    endif
#    ifdef BABL_CHROMEOS
    if (babble_mode == BABL_CHROMEOS_MODE) {
        if (BABL_LED_INDEX > 0) {
            rgblight_setrgb_at(RGBLIGHT_COLOR_CHROMEOS, BABL_LED_INDEX);
        } else {
            rgblight_setrgb(RGBLIGHT_COLOR_CHROMEOS);
        }
    }
#    endif
#    ifdef BABL_LINUX
    if (babble_mode == BABL_LINUX_MODE) {
        if (BABL_LED_INDEX > 0) {
            rgblight_setrgb_at(RGBLIGHT_COLOR_LINUX, BABL_LED_INDEX);
        } else {
            rgblight_setrgb(RGBLIGHT_COLOR_LINUX);
        }
    }
#    endif
#  endif  // bablepaste
#endif  // rgblight_enable
*/
}
