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

#if (!defined(LAYOUT) && defined(KEYMAP))
    #define LAYOUT KEYMAP
#endif

#define LAYOUT_scrthq_ergodox(...)          LAYOUT_ergodox_pretty(__VA_ARGS__)
#ifdef LAYOUT
    #define LAYOUT_scrthq(...)              LAYOUT(__VA_ARGS__)
#endif
#define LAYOUT_scrthq_5x12(...)             LAYOUT_ortho_5x12(__VA_ARGS__)

#define LAYOUT_adelais( \
    K1E, K00, K01, K02, K03, K04, K05, K06,         K07,K08,K09, K0A, K0B, K0C, K0D, K0E,\
    K2E, K10, K11, K12, K13, K14, K15,              K16,K17,K18, K19, K1A, K1B, K1C, K1D,\
    K3E, K20, K21, K22, K23, K24, K25,              K26,K27,K28, K29, K2A, K2B, K2D,\
         K30,      K32, K33, K34, K35, K36,         K37,K38,K39, K3A, K3B, K3D, K3C, K4D,\
         K40,      K42,      K44,      K46,             K48,     K4A,               K4E \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D,   K2E   }, \
    { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E   }, \
    { K40,   KC_NO, K42,   KC_NO, K44,   KC_NO, K46,   KC_NO, K48,   KC_NO, K4A,   KC_NO, KC_NO, K4D,   K4E   }, \
}

#define LAYOUT_scrthq_adelais(...)          LAYOUT_adelais(__VA_ARGS__)

#define LAYOUT_kyria( \
    L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29, L30, L31, R32, R33, R34, R35, R36, R37, R38, R39, \
                   L40, L41, L42, L43, L44, R45, R46, R47, R48, R49 \
) \
{ \
    { KC_NO, KC_NO, L05,   L04,   L03,   L02,   L01,   L00   }, \
    { KC_NO, KC_NO, L17,   L16,   L15,   L14,   L13,   L12   }, \
    { L31,   L30,   L29,   L28,   L27,   L26,   L25,   L24   }, \
    { L44,   L43,   L42,   L41,   L40,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, R06,   R07,   R08,   R09,   R10,   R11   }, \
    { KC_NO, KC_NO, R18,   R19,   R20,   R21,   R22,   R23   }, \
    { R32,   R33,   R34,   R35,   R36,   R37,   R38,   R39   }, \
    { R45,   R46,   R47,   R48,   R49,   KC_NO, KC_NO, KC_NO }, \
}
#define LAYOUT_scrthq_kyria(...)          LAYOUT_kyria(__VA_ARGS__)
