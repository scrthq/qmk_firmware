#include QMK_KEYBOARD_H
#include "scrthq.h"
#include "scrthq_os_keys.h"
#include "scrthq_layouts.h"
#include "scrthq_key_definitions.h"
#include <stdio.h>

extern bool is_alt_tab_active;
extern uint16_t alt_tab_timer;
extern bool is_ctl_tab_active;
extern uint16_t ctl_tab_timer;
extern uint16_t tab_time_limit;

__attribute__((weak)) uint8_t get_os(void) {return 1;}
__attribute__((weak)) void set_os(uint8_t os);
__attribute__((weak)) void store_userspace_config(void);

#define HOLDDEDENT LT(_MEDIA, _OS_DEDENT)
#define FNGAME LT(_OSKEYS, KC_ESC)

// clang-format off
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
     *      Encoder 1         Encoder 2                                                                  Encoder 3         Encoder 4
     * .-----------------------------------.                                                        .-----------------------------------.
     * | VolUp  | VolDn  | VolUp  | VolDn  |                                                        | PgUp   | PgDn   | PgUp   | PgDn   |
     * |--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
     * | VolDn  | VolUp  | Next   | Play   | Prev   | Touch Encoder          Touch Encoder | RgbHuI | RgbHuD | RgbMdD | RgbTog | RgbMdI |
     * '--------+--------+--------+--------+--------'                                      '--------+--------+--------+--------+--------'
     */
    [_QWERTY] = LAYOUT(
        FNESC,    KC_1,       KC_2,      KC_3,    KC_4,    KC_5,      XXXXXXX,    XXXXXXX,   KC_6,      KC_7,      KC_8,     KC_9,    KC_0,     KC_BSPC,
        FNTAB,    KC_Q,       KC_W,      KC_E,    KC_R,    KC_T,      XXXXXXX,    XXXXXXX,   KC_Y,      KC_U,      KC_I,     KC_O,    KC_P,     KC_BSLS,
        HOLDMINS, KC_A,       HOLDS,     HOLDD,   HOLDF,   KC_G,      KC_F12,     OS_PRSCRN, KC_H,      HOLDJBAB,  HOLDK,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSPO,  HOLDZ,      KC_X,      KC_C,    KC_V,    KC_B,      OS_L1WD,    OS_R1WD,   KC_N,      KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSPC,
        CTLGRV,   HOLDDEDENT, OS_INDENT, KC_LGUI, KC_LALT, OUTRSPCLO, XXXXXXX,    XXXXXXX,   OUTRENTHI, KC_LEFT,   HOLDRIGHT,MYMEH,   KC_RALT,  CTLGRV,

        KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD,                                      KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_DOWN,
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                        RGB_HUI, RGB_HUD, RGB_RMOD,RGB_TOG, RGB_MOD
    ),

    [_LOWER] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, OS_HOME,       OS_END,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, OS_HOME,       OS_END,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        KC_ESC,  _______, _______, _______, _______, _______, _______,       _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
        _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, KC_LT,   KC_GT,   KC_QUES, _______,
        _______, _______, _______, _______, _______, _______, _______,       _______, KC_ESC,  _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    OS_HOME,    OS_END,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    OS_HOME,    OS_END,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
        KC_CAPS, _______, _______, _______, _______, _______, _______,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BSLASH,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    RESET,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        RESET,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
        RESET,   SCRT1,   SCRT2,   SCRT3,   SCRT4,   SCRT5,   _______,    RESET,   SCRT6,   SCRT7,   SCRT8,   SCRT9,   SCRT10,  _______,
        _______, _______, _______, _______, _______, _______, SCRT13,     _______, SS_EMAIL,_______, _______, _______, _______, _______,
        _______, KC_F5,   KC_F8,   _______, _______, _______, XXXXXXX,    XXXXXXX, SCRT14,  SCRT15,  SCRT16,  _______, _______, _______,

        _______, _______, _______, _______,                                                          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______
    ),
    [_OSKEYS] = LAYOUT(
        _______, OS_WIN,    OS_DELWRD, OS_MAC,    OS_RELOAD, OS_ROPNTB, _______,       _______,   OS_REDO,   OS_OLIST,  OS_ULIST,  OS_ZMOUT,   OS_ZMIN,    OS_PRSCRN,
        _______, OS_WIN,    OS_DELWRD, OS_MAC,    OS_RELOAD, OS_ROPNTB, _______,       _______,   OS_REDO,   OS_OLIST,  OS_ULIST,  OS_ZMOUT,   OS_ZMIN,    OS_PRSCRN,
        _______, OS_SELALL, OS_SAVE,   OS_DEVTLS, OS_FIND,   OS_CLIPPY, _______,       _______,   OS_FNDREP, _______,   KC_EQUAL,  OS_MULSEL,  _______,    _______,
        _______, OS_UNDO,   OS_CUT,    OS_COPY,   OS_PASTE,  OS_PSTPLN, OS_HOME,       OS_END,    OS_NEWTAB, OS_CLSTAB, _______,   OS_BLKCMNT, OS_LINCMNT, _______,
        _______, OS_DEDENT, OS_INDENT, _______,   OS_LDSKTP, OS_RDSKTP, _______,       _______,   KC_ESC,    OS_LDSKTP, OS_RDSKTP, _______,    _______,    _______,

        _______, _______, _______, _______,                                                          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______
    ),
    [_HOLDF] = LAYOUT(
        _______, _______, _______,    _______,  _______, _______,   _______,    _______, _______,  _______,  _______,   _______,   _______,  _______,
        _______, _______, RLDTERM,    _______,  RLDWIND, MEH(KC_T), _______,    _______, _______,  _______,  _______,   _______,   KC_LBRC,  KC_RBRC,
        KC_CAPS, KC_UNDS, MEH(KC_S),  DLRUNDER, _______, _______,   _______,    _______, _______,  _______,  KC_EQUAL,  OS_MULSEL, KC_LCBR,  KC_RCBR,
        _______, _______, _______,    _______,  _______, _______,   _______,    _______, _______,  OS_LNGSEL,  _______, _______,   KC_LPRN,  KC_RPRN,
        _______, KC_F5,   KC_F8,      _______,  OS_L1WD, OS_R1WD,   XXXXXXX,    XXXXXXX, OS_FOLDA, OS_FOLDR, OS_FOLD,   OS_UNFOLD, OS_UFLDR, OS_UFLDA,

        _______, _______, _______, _______,                                                          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______
    ),
    [_NUMPAD] = LAYOUT(
        _______, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), _______,         _______, _______, KC_7, KC_8,    KC_9,    _______, _______,
        _______, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), _______,         _______, _______, KC_7, KC_8,    KC_9,    _______, _______,
        _______, _______,    _______,    _______,    _______,    _______,    _______,         _______, _______, KC_4, KC_5,    KC_6,    _______, _______,
        _______, _______,    _______,    _______,    _______,    _______,    _______,         _______, _______, KC_1, KC_2,    KC_3,    _______, _______,
        _______, KC_F5,      KC_F8,      _______,    OS_HOME,    OS_END,     XXXXXXX,         _______, KC_0,    KC_0, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______
    ),
    [_SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______,   _______,     _______,    _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______,   _______,     _______,    _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______,
        _______, _______, _______, _______, _______,   TO(_GAMING), _______,    _______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______, _______,
        _______, _______, _______, _______, _______,   _______,     _______,    _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______,
        _______, KC_F5,   KC_F8,   _______, OS_STRDOC, OS_ENDDOC,   XXXXXXX,    _______, KC_RPRN, KC_RPRN, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______
    ),
    [_GAMING] = LAYOUT(
        FNESC,    KC_1,      KC_2,     KC_3,    KC_4,    KC_5,     KC_F1,        GOHOME,   KC_6,      KC_7,    KC_8,      KC_9,    KC_0,    _______,
        KC_TAB,   KC_Q,      KC_W,     KC_E,    KC_R,    KC_T,     KC_F2,        KC_RCBR,  KC_Y,      KC_U,    KC_I,      KC_O,    KC_P,    _______,
        FNGAME,   KC_A,      KC_S,     KC_D,    KC_F,    KC_G,     KC_F3,        KC_RPRN,  KC_H,      KC_J,    KC_K,      KC_L,    KC_SCLN, _______,
        KC_LSFT,  KC_Z,      KC_X,     KC_C,    KC_V,    KC_B,     KC_F4,        KC_RBRC,  KC_N,      KC_M,    KC_COMM,   KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTRL, XXXXXXX,   XXXXXXX,  XXXXXXX, KC_LALT, KC_SPC,   XXXXXXX,      XXXXXXX,  OUTRENTHI, KC_LEFT, HOLDRIGHT, MYMEH,   KC_RALT, GOHOME,

        KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD,                                      KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_DOWN,
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                        RGB_HUI, RGB_HUD, RGB_RMOD,RGB_TOG, RGB_MOD
    ),

    /* _MEDIA
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | F12    | F1     | F2     | F3     | F4     | F5     |        |  | GOHOME | F6     | F7     | F8     | F9     | F10    | F11    |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | SPDI   | SAI    | VAI    | HUI    | RGBMD  |        |  |        |        | PrtScr | ScrLck | PseBrk |        |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | SPDD   | SAD    | VAD    | HUD    | RGBRMD |        |  |        |        | Ins    | Home   | PgUp   |        |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | RGBRST |        |        |        | RGBTOG |        |  |        |        | Del    | End    | PgDn   |        |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | GOHOME |        |        |        |        |        |  |        | Play   | Prev   | Next   | VolUp  | VolDn  | GOHOME |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     *      Encoder 1         Encoder 2                                                                  Encoder 3         Encoder 4
     * .-----------------------------------.                                                        .-----------------------------------.
     * |        |        |        |        |                                                        |        |        |        |        |
     * |--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
     * |        |        |        |        |        | Touch Encoder          Touch Encoder |        |        |        |        |        |
     * '--------+--------+--------+--------+--------'                                      '--------+--------+--------+--------+--------'
     */
    [_MEDIA] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    GOHOME,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, RGB_SPI, RGB_SAI, RGB_VAI, RGB_HUI, RGB_MOD, _______,    _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______,
        _______, RGB_SPD, RGB_SAD, RGB_VAD, RGB_HUD, RGB_RMOD,_______,    _______, _______, KC_INS,  OS_HOME, KC_PGUP, _______, _______,
        _______, _______, _______, _______, _______, RGB_TOG, _______,    _______, _______, KC_DEL,  OS_END,  KC_PGDN, _______, _______,
        _______, _______, _______, _______, _______, TCH_TOG, _______,    _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLU, KC_VOLD, GOHOME,

        _______, _______, _______, _______,                                                          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______
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
     *      Encoder 1         Encoder 2                                                                  Encoder 3         Encoder 4
     * .-----------------------------------.                                                        .-----------------------------------.
     * |        |        |        |        |                                                        |        |        |        |        |
     * |--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
     * |        |        |        |        |        | Touch Encoder          Touch Encoder |        |        |        |        |        |
     * '--------+--------+--------+--------+--------'                                      '--------+--------+--------+--------+--------'
     *
    [_CHANGEME] = LAYOUT(
        _______,  _______,   _______,  _______,   _______,  _______,  _______,     _______,  _______,   _______,  _______,   _______,  _______,  _______,
        _______,  _______,   _______,  _______,   _______,  _______,  _______,     _______,  _______,   _______,  _______,   _______,  _______,  _______,
        _______,  _______,   _______,  _______,   _______,  _______,  _______,     _______,  _______,   _______,  _______,   _______,  _______,  _______,
        _______,  _______,   _______,  _______,   _______,  _______,  _______,     _______,  _______,   _______,  _______,   _______,  _______,  _______,
        _______,  _______,   _______,  _______,   _______,  _______,  _______,     _______,  _______,   _______,  _______,   _______,  _______,  _______,

        _______,  _______,   _______,  _______,                                                                   _______,   _______,  _______,  _______,
        _______,  _______,   _______,  _______,  _______,                                               _______,  _______,   _______,  _______,  _______
    )
     */
};



#if defined(OLED_DRIVER_ENABLE)
static void render_rgbkb_logo(void) {
    static const char PROGMEM font_icon[] = {
        0x9b,0x9c,0x9d,0x9e,0x9f,
        0xbb,0xbc,0xbd,0xbe,0xbf,
        0xdb,0xdc,0xdd,0xde,0xdf,0
    };
    oled_write_P(font_icon, false);
}

static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void render_rgb_menu(void) {
    static char buffer[53] = {0};
    snprintf(buffer, sizeof(buffer), "Hue   %3d Satur %3d Value %3d Speed %3d Mode  %3d ",
    rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode);
    oled_write(buffer, false);
}

static void render_layer(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("LYR: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwert"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Games"), false);
            break;
        case _FUNCTION:
            oled_write_ln_P(PSTR("Funct"), false);
            break;
        case _OSKEYS:
            oled_write_ln_P(PSTR("OSKey"), false);
            break;
        case _HOLDF:
            oled_write_ln_P(PSTR("HoldF"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("Numpd"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Smbls"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
            break;
    }
}

static void render_os(void) {
    oled_write_P(PSTR("OS:  "), false);
    uint8_t os_target  = get_os();
    switch (os_target) {
        case _OS_MACOS:
            oled_write_P(PSTR("MacOS"), false);
            break;
        case _OS_WINDOWS:
            oled_write_P(PSTR("Win10"), false);
            break;
        case _OS_LINUX:
            oled_write_P(PSTR("Linux"), false);
            break;
    }
}

static void render_leds(void) {
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NumLk")     : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CapLk")    : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("ScrLk")  : PSTR("     "), false);
}

static void render_touch(void) {
    // Host Touch LED Status
    oled_write_P(!touch_encoder_toggled() ? PSTR("Touch")  : PSTR("     "), false);
    oled_write_P(touch_encoder_calibrating() ? PSTR("Clbrt")  : PSTR("     "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer();
        oled_write_P(PSTR("-----"), false);
        render_os();
        oled_write_P(PSTR("-----"), false);
        render_leds();
        oled_write_P(PSTR("-----"), false);
        render_touch();
        oled_set_cursor(0, 12);
        render_rgbkb_logo();
    }
    else {
        switch (get_highest_layer(layer_state)) {
            case _MEDIA:
                render_rgb_menu();
                break;
            default:
                break;
        }
        oled_set_cursor(0, 12);
        render_qmk_logo();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
#endif
