#include QMK_KEYBOARD_H
#include "scrthq.h"
#include "scrthq_os_keys.h"
#include "scrthq_layouts.h"
#include "scrthq_key_definitions.h"
#include <stdio.h>

extern bool     is_alt_tab_active;
extern uint16_t alt_tab_timer;
extern bool     is_ctl_tab_active;
extern uint16_t ctl_tab_timer;
extern uint16_t tab_time_limit;

__attribute__((weak)) uint8_t get_os(void) { return 1; }
__attribute__((weak)) void    set_os(uint8_t os);
__attribute__((weak)) void    store_userspace_config(void);

#define SECTAB LT(_SECRETS, KC_TAB)
#define FNGAME LT(_OSKEYS, KC_ESC)
#define ESCLOW LT(_LOWER, KC_ESC)
#define LEFTHI LT(_RAISE, KC_LEFT)
#define GOFUNC MO(_FUNCTION)
#define ALTSPC LALT_T(KC_SPC)
#define CTLSPC LCTL_T(KC_SPC)
#define HOLDQUOT LT(_OSKEYS, KC_QUOT)

// clang-format off
#define DEFAULT_LAYER(LAYER, R4C4, R4C6) \
    [LAYER] = LAYOUT( \
        SECTAB,    KC_Q,       KC_W,      KC_E,      KC_R,       KC_T,          KC_Y,      KC_U,      KC_I,       KC_O,    KC_P,     KC_BSPC, \
        HOLDMINS,  KC_A,       HOLDS,     HOLDD,     HOLDF,      KC_G,          KC_H,      HOLDJBAB,  HOLDK,      KC_L,    KC_SCLN,  HOLDQUOT, \
        KC_LSPO,   KC_Z,       KC_X,      KC_C,      KC_V,       KC_B,          KC_N,      KC_M,      KC_COMM,    KC_DOT,  KC_SLSH,  KC_RSPC, \
        OS_DEDENT, OS_INDENT,  KC_LGUI,   R4C4,      OUTRSPCLO,  R4C6,          KC_ENT,    LEFTHI,    HOLDRIGHT,  KC_MEH,  OS_LDSKTP, OS_RDSKTP \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | `~/ESC | 1      | 2      | 3      | 4      | 5      |        |  |        | 6      | 7      | 8      | 9      | 0      | Bckspc |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Tab    | Q      | W      | E      | R      | T      |        |  |        | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Caps   | A      | S      | D      | F      | G      | Play   |  | MN BTN | H      | J      | K      | L      | :      | Enter  |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Shft[  | Z      | X      | C      | V      | B      | {      |  | }      | N      | M      | ,      | .      | /      | Shft]  |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Ctrl-  | Win    | Alt    | Del    | Space  |        | ADJ    |  | FN     |        | Space  | '"     | Alt    | App    | Ctrl=  |
     * '--------+--------+--------+--------|--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     */
    DEFAULT_LAYER(_QWERTY, CTLGRV, ALTSPC),
    DEFAULT_LAYER(_MACBASE, ALTGRV, CTLSPC),

    [_GAMING] = LAYOUT(
        KC_TAB,   KC_Q,      KC_W,     KC_E,    KC_R,    KC_T,                KC_Y,      KC_U,    KC_I,      KC_O,    KC_P,    _______,
        FNGAME,   KC_A,      KC_S,     KC_D,    KC_F,    KC_G,                KC_H,      KC_J,    KC_K,      KC_L,    KC_SCLN, _______,
        KC_LSFT,  KC_Z,      KC_X,     KC_C,    KC_V,    KC_B,                KC_N,      KC_M,    KC_COMM,   KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTRL, KC_2,      KC_1,     KC_LALT, MO(_LOWER), KC_SPC,           KC_ENT,    LEFTHI,  HOLDRIGHT, KC_MEH,  KC_RALT, GOHOME
    ),

    [_LOWER] = LAYOUT(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_ESC,  _______, _______, KC_SLSH, KC_MINS, KC_EQL,                  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_BSLS, KC_LBRC, KC_RBRC,                 _______, _______, _______, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, _______,                 _______, GOFUNC,  _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_DELETE,
        _______, _______, _______, _______, _______, _______,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU, KC_BSLASH,
        _______, _______, _______, _______, _______, _______,                  _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_VOLD, _______,
        _______, _______, _______, _______, GOFUNC,  _______,                  _______, _______, _______, _______, _______, KC_WAKE
    ),

    [_FUNCTION] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PIPE,
        KC_CAPS,  _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
        SH_RESET, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______
    ),

    [_SECRETS] = LAYOUT(
        _______,    KC_F1,   _______, _______, _______, _______,               _______,  _______, _______, _______, _______, _______,
        _______,    SCRT1,   SCRT2,   SCRT3,   SCRT4,   SCRT5,                 SCRT6,    SCRT7,   SCRT8,   SCRT9,   SCRT10,  _______,
        _______,    _______, _______, _______, _______, _______,               SS_EMAIL, _______, _______, _______, _______, _______,
        SH_RESET,   _______, _______, _______, _______, SCRT13,                SCRT14,   SCRT15,  SCRT16,  _______, _______, _______
    ),

    [_OSKEYS] = LAYOUT(
        _______, OS_WIN,    OS_DELWRD, OS_MAC,    OS_RELOAD, OS_ROPNTB,             OS_REDO,   OS_OLIST,  OS_ULIST,   OS_ZMOUT,   OS_ZMIN,    LCTL(KC_W),
        _______, OS_SELALL, OS_SAVE,   OS_DEVTLS, OS_FIND,   OS_CLIPPY,             OS_FNDREP, _______,   LCTL(KC_C), OS_MULSEL,  _______,    _______,
        _______, OS_UNDO,   OS_CUT,    OS_COPY,   OS_PASTE,  OS_PSTPLN,             OS_NEWTAB, OS_LNGSEL, _______,    OS_BLKCMNT, OS_LINCMNT, _______,
        _______, OS_DEDENT, OS_INDENT, OS_LDSKTP, OS_RDSKTP, OS_MCTL,               OS_END,    OS_L1WD,   OS_R1WD,    OS_PRSCRN,  OS_LDSKTP,  OS_RDSKTP
    ),
    [_HOLDF] = LAYOUT(
        _______, _______, RLDTERM,    _______,  RLDWIND,   MEH(KC_T),                 _______,  _______,  _______,   _______,   KC_LBRC,  KC_RBRC,
        _______, KC_UNDS, MEH(KC_S),  DLRUNDER, LSA(KC_F), _______,                   _______,  KC_PLUS,  KC_EQUAL,  OS_MULSEL, KC_LCBR,  KC_RCBR,
        _______, _______, _______,    _______,  _______,   _______,                   _______,  OS_LNGSEL,  _______, _______,   KC_LPRN,  KC_RPRN,
        _______, KC_F5,   KC_F8,      _______,  OS_L1WD,   OS_R1WD,                   OS_FOLDA, OS_FOLDR, OS_FOLD,   OS_UNFOLD, OS_UFLDR, OS_UFLDA
    ),
    [_NUMPAD] = LAYOUT(
        _______, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),        _______, KC_7, KC_8,    KC_9,    _______, _______,
        _______, _______,    _______,    _______,    G(KC_SPC),  _______,           _______, KC_4, KC_5,    KC_6,    _______, _______,
        _______, _______,    _______,    _______,    _______,    _______,           _______, KC_1, KC_2,    KC_3,    _______, _______,
        _______, KC_F5,      KC_F8,      _______,    OS_HOME,    OS_END,            KC_0,    KC_0, _______, _______, _______, _______
    ),
    [_SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______,   _______,           _______, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______,
        _______, _______, _______, _______, _______,   TO(_GAMING),       _______, KC_DLR,  KC_PERC, KC_CIRC, _______, _______,
        _______, _______, _______, _______, _______,   _______,           _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______,
        _______, KC_F5,   KC_F8,   _______, OS_STRDOC, OS_ENDDOC,         KC_RPRN, KC_RPRN, _______, _______, _______, _______
    ),

    [_MEDIA] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLU, KC_VOLD, GOHOME
    ),

    [_DFUMODE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, GOHOME
    )
    /* Blank
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * |        |        |        |        |        |        |        |  |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |  |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |  |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |  |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |  |        |        |        |        |        |        |        |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     *
    [_CHANGEME] = LAYOUT(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______
    )
     */
};
