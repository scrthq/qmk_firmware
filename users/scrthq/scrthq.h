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

#pragma once

#include "scrthq_os_keys.h"

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "version.h"
#include "eeprom.h"

// clang-format off
// Custom keycodes
enum scrthq_userspace_custom_keycodes {
    USERSPACE_KEYCODE_START = 50000,
    LOWER,
    RAISE,
    MOFO,
    VRSN,
    SHRUG,
    QWERTY,
    BACKLIT,
    BABL_CUR_MODE,
    EPRM,
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5,
    KC_SECRET_6,
    KC_SECRET_7,
    KC_SECRET_8,
    KC_SECRET_9,
    KC_SECRET_10,
    KC_SECRET_11,
    KC_SECRET_12,
    KC_SECRET_13,
    KC_SECRET_14,
    KC_SECRET_15,
    KC_SECRET_16,
    USERSPACE_KEYCODE_END
};
// clang-format on

/* Define layer names */
enum scrthq_userspace_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _HOLDA,
    _HOLDF,
    _HOLDJ,
    _OSKEYS,
    _NUMPAD,
    _SYMBOLS,
    _EMPTY,
    _ENCODER,
    _CODE,
    _GAMING,
};

enum scrthq_tap_dance_declarations {
    SPENT,
    SPACELO,
    SPACEHI,
    BBLGUI,
};

enum scrthq_hid_commands {
    set_os_mac = 0x01,
    set_os_win = 0x02,
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t os_target : 2;
    };
} userspace_config_t;
