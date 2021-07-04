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
#include "scrthq_os_keys.h"
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
#    include "rgblight.h"
#endif
#ifdef RAW_ENABLE
#    include "raw_hid.h"
#endif

#include "scrthq_layouts.h"
#include "scrthq_key_definitions.h"

// ---------------------------------------------------------

userspace_config_t runtime_userspace_config;
userspace_config_t stored_userspace_config;

void store_userspace_config(void) {
    stored_userspace_config.raw = runtime_userspace_config.raw;
    eeconfig_update_user(stored_userspace_config.raw);
}

void set_os(uint8_t os) {
    runtime_userspace_config.os_target = os;
    store_userspace_config();

#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE)
    switch (os) {
        case _OS_MACOS:
            set_unicode_input_mode(UC_OSX);
            break;
        case _OS_LINUX:
            set_unicode_input_mode(UC_LNX);
            break;
        case _OS_WINDOWS:
            set_unicode_input_mode(UC_WIN);
            break;
    }
#endif
}

uint8_t get_os(void) {
    return runtime_userspace_config.os_target;
}

void matrix_init_user(void) {
    stored_userspace_config.raw  = eeconfig_read_user();
    runtime_userspace_config.raw = stored_userspace_config.raw;

    set_os(runtime_userspace_config.os_target);
}

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    [SPENT]   = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
    [SPACELO] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, LOWER),
    [SPACEHI] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, RAISE),
    [BBLGUI]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LT(_OSKEYS, KC_LGUI)),
};
#endif

void set_layer_led_user(void) {
#ifdef RGBLIGHT_ENABLE
    uint8_t os_target  = get_os();
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            switch (os_target) {
                case _OS_MACOS:
                    rgb_matrix_mode(RGB_MATRIX_CYCLE_PINWHEEL);
                    // rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 1);
                    // rgblight_sethsv(30, 255, 255);
                    break;
                default:
                    rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
                    // rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
                    // rgblight_sethsv(122, 255, 255);
                    break;
            }
            break;
        case _OSKEYS:
            rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
            // rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 1);
            // rgblight_sethsv(140, 255, 255);
            break;
        case _FUNCTION:
            rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
            // rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 4);
            // rgblight_sethsv(202, 255, 255);
            break;
        case _GAMING:
            rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
            // rgblight_mode_noeeprom(1); // RGBLIGHT_MODE_STATIC_LIGHT
            // // rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 2);
            // rgblight_sethsv(255, 255, 255);
            break;
        default:
            rgb_matrix_mode(RGB_MATRIX_HUE_WAVE);
            // rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 7);
            // rgblight_sethsv(255, 255, 255);
            break;
    }
#endif
}

void keyboard_post_init_user(void) {
    // rgblight_set_speed(255);
    // set_layer_led_user();
    if (!touch_encoder_toggled()) touch_encoder_toggle();
}

// #ifdef RAW_ENABLE
void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t os_target  = get_os();
    uint8_t *command_data = &(data[1]);
#    ifdef CONSOLE_ENABLE
    uint8_t *command_id = &(data[0]);
    uprintf("HID COM ID: [%u], DATA: [%u]\n", *command_id, *command_data);
#    endif
    switch (*command_data) {
        case set_os_mac: {
            if (os_target != _OS_MACOS) {
                set_os(_OS_MACOS);
                // set_layer_led_user();
            }
            break;
        }
        case set_os_win: {
            if (os_target != _OS_WINDOWS) {
                set_os(_OS_WINDOWS);
                // set_layer_led_user();
            }
            break;
        }
        default: {
            break;
        }
    }
    raw_hid_send(data, length);
}
// #endif
