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

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 300000
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK
#define SPLIT_USB_TIMEOUT 1000

#define MASTER_LEFT
#define ENCODER_DIRECTION_FLIP

//#define IGNORE_MOD_TAP_INTERRUPT
//#define TAPPING_FORCE_HOLD

//#define NO_ACTION_TAPPING
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
#ifndef NO_DEBUG
    #define NO_DEBUG
#endif

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
    #define NO_PRINT
#endif

#define OLED_FONT_END 127

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs to a circle around both halves.
    //#define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19} // Orients Kyria LEDs for a left half-right half columnar progression.
    //#define RGBLIGHT_EFFECT_RGB_TEST
    //#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    //#define RGBLIGHT_EFFECT_STATIC_GRADIENT
    //#define RGBLIGHT_SLEEP
    #ifdef RGBLIGHT_NUM
        #undef RGBLIGHT_NUM
        #define RGBLIGHT_NUM 20
    #endif
#endif

#ifdef ENCODER_ENABLE
    #define ENCODER_RESOLUTION 2
#endif
