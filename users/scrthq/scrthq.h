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

#include "babblePaste.h"

#include QMK_KEYBOARD_H
#include "quantum.h"

// clang-format off
// Custom keycodes
enum userspace_custom_keycodes {
    USERSPACE_KEYCODE_START = 50000,
    LOWER,
    RAISE,
    MOFO,
    VRSN,
    SHRUG,
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5,
    USERSPACE_KEYCODE_END
};
// clang-format on

/* Define layer names */
enum userspace_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _HOLDA,
    _HOLDF,
    _HOLDJ,
    _BABBLE,
    _NUMPAD,
    _SYMBOLS,
    _EMPTY,
};

enum tap_dance_declarations {
    SPENT,
};

typedef union {
    uint32_t   raw;
    struct {
        bool   babblepaste_mode : 1;
    };
} userspace_config_t;

userspace_config_t userspace_config;
