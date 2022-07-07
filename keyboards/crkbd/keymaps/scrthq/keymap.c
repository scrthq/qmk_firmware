
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

#define LFTGUI LGUI_T(KC_LEFT)
#define LFTRSE LT(_RAISE, KC_LEFT)
#define FNGAME LT(_OSKEYS, KC_ESC)
#define HOLDQT LT(_OSKEYS, KC_QUOT)

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
     */
    [_QWERTY] = LAYOUT(
        FNTAB,    KC_Q,   KC_W,     KC_E,   KC_R,      KC_T,            KC_Y,      KC_U,      KC_I,     KC_O,    KC_P,     KC_BSPC,
        HOLDMINS, KC_A,   HOLDS,    HOLDD,  HOLDF ,    KC_G,            KC_H,      HOLDJBAB,  HOLDK,    KC_L,    KC_SCLN,  HOLDQT,
        KC_LSPO,  HOLDZ,  KC_X,     KC_C,   KC_V,      KC_B,            KC_N,      KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSPC,
                                    CTLGRV, OUTRSPCLO, KC_LALT,         KC_ENTER,  LFTRSE, HOLDRIGHT
    ),

    [_LOWER] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        KC_ESC,  _______, _______,  _______, _______, TO(_MEDIA),          KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
        _______, _______, _______,  _______, _______, _______,             KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                    _______, _______, _______,             KC_LGUI, _______,  KC_ESC
    ),

    [_RAISE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
        KC_CAPS, _______, _______,  _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BSLASH,
        _______, _______, _______,  _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10, KC_BSPC,
        _______,   SCRT1,   SCRT2,    SCRT3,   SCRT4,   SCRT5,                        SCRT6,   SCRT7,   SCRT8,   SCRT9,   SCRT10,  KC_F11,
        _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      SS_EMAIL,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
                                    SS_EMAIL, DLRUNDER, SCRT13,                       SCRT14,  SCRT15,  SCRT16
    ),
    [_OSKEYS] = LAYOUT(
        _______, OS_WIN,    OS_DELWRD,  OS_MAC,    OS_RELOAD, OS_ROPNTB,             OS_REDO,   OS_OLIST,  OS_ULIST,  OS_ZMOUT,   OS_ZMIN,    OS_PRSCRN,
        _______, OS_SELALL, OS_SAVE,    OS_DEVTLS, OS_FIND,   OS_CLIPPY,             OS_FNDREP, _______,   KC_EQUAL,  OS_MULSEL,  _______,    _______,
        _______, OS_UNDO,   OS_CUT,     OS_COPY,   OS_PASTE,  OS_PSTPLN,             OS_NEWTAB, OS_CLSTAB, _______,   OS_BLKCMNT, OS_LINCMNT, _______,
                                        OS_DEDENT, OS_INDENT, XXXXXXX,               KC_ESC,    OS_LDSKTP, OS_RDSKTP
    ),
    [_HOLDF] = LAYOUT(
        _______, _______, RLDTERM,      _______,  RLDWIND, MEH(KC_T),                _______,  _______,    _______,   _______,   KC_LBRC,  KC_RBRC,
        KC_CAPS, KC_UNDS, MEH(KC_S),    DLRUNDER, _______, _______,                  _______,  _______,    KC_EQUAL,  OS_MULSEL, KC_LCBR,  KC_RCBR,
        _______, _______, _______,      _______,  _______, _______,                  _______,  OS_LNGSEL,  _______, _______,   KC_LPRN,  KC_RPRN,
                                        OS_L1WD, OS_R1WD,  XXXXXXX,                  XXXXXXX,  OS_FOLD,    OS_UNFOLD
    ),
    [_NUMPAD] = LAYOUT(
        _______, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),        XXXXXXX,  KC_7, KC_8,    KC_9,    XXXXXXX, KC_BSPC,
        _______, XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,           XXXXXXX,  KC_4, KC_5,    KC_6,    XXXXXXX, XXXXXXX,
        _______, XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,           XXXXXXX,  KC_1, KC_2,    KC_3,    XXXXXXX, XXXXXXX,
                                        OS_HOME,    OS_END,     XXXXXXX,           KC_ENTER, KC_0, KC_0
    ),
    [_SYMBOLS] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        _______, _______, _______, _______, _______,  TO(_GAMING),       KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
        _______, _______, _______, _______, _______,  _______,           KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                    KC_F5,   KC_F8,   XXXXXXX,           KC_AT,   KC_HASH, KC_DLR
    ),
    [_GAMING] = LAYOUT(
        KC_TAB,   KC_Q,   KC_W,     KC_E,     KC_R,    KC_T,             KC_Y,      KC_U,      KC_I,      KC_O,    KC_P,    _______,
        FNGAME,   KC_A,   KC_S,     KC_D,     KC_F,    KC_G,             KC_H,      KC_J,      KC_K,      KC_L,    KC_SCLN, _______,
        KC_LSFT,  KC_Z,   KC_X,     KC_C,     KC_V,    KC_B,             KC_N,      KC_M,      KC_COMM,   KC_DOT,  KC_SLSH, GOHOME,
                                    KC_LCTRL, KC_SPC,  KC_LALT,          LFTGUI,  OUTRENTHI, HOLDRIGHT
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
        GOHOME,  RGB_SPI, RGB_SAI,  RGB_VAI, RGB_HUI, RGB_MOD,                  XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, GOHOME,
        XXXXXXX, RGB_SPD, RGB_SAD,  RGB_VAD, RGB_HUD, RGB_RMOD,                 XXXXXXX, KC_INS,  OS_HOME, KC_PGUP, XXXXXXX, XXXXXXX,
        GOHOME,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, RGB_TOG,                  XXXXXXX, KC_DEL,  OS_END,  KC_PGDN, XXXXXXX, GOHOME,
                                    KC_VOLD, KC_VOLU, TCH_TOG,                  KC_MPLY, KC_MPRV, KC_MNXT
    )
    /* Blank
     * .------------------------------------------------------               ------------------------------------------------------.
     * |        |        |        |        |        |        |               |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+               +--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |               |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+               +--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |               |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+               +--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |               |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+               +--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |               |        |        |        |        |        |        |
     * '--------+--------+--------+--------+--------+--------+               +--------+--------+--------+--------+--------+--------'
     *
    [_CHANGEME] = LAYOUT(
        _______,  _______,   _______,  _______,   _______,  _______,        _______,   _______,  _______,   _______,  _______,  _______,
        _______,  _______,   _______,  _______,   _______,  _______,        _______,   _______,  _______,   _______,  _______,  _______,
        _______,  _______,   _______,  _______,   _______,  _______,        _______,   _______,  _______,   _______,  _______,  _______,
        _______,  _______,   _______,  _______,   _______,  _______,        _______,   _______,  _______,   _______,  _______,  _______
    )
     */
};



// #if defined(OLED_DRIVER_ENABLE)
// // static void render_rgbkb_logo(void) {
// //     static const char PROGMEM font_icon[] = {
// //         0x9b,0x9c,0x9d,0x9e,0x9f,
// //         0xbb,0xbc,0xbd,0xbe,0xbf,
// //         0xdb,0xdc,0xdd,0xde,0xdf,0
// //     };
// //     oled_write_P(font_icon, false);
// // }

// // static void render_qmk_logo(void) {
// //     static const char PROGMEM qmk_logo[] = {
// //         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
// //         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
// //         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
// //     };

// //     oled_write_P(qmk_logo, false);
// // }

// // static void render_rgb_menu(void) {
// //     static char buffer[53] = {0};
// //     snprintf(buffer, sizeof(buffer), "Hue   %3d Satur %3d Value %3d Speed %3d Mode  %3d ",
// //     rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode);
// //     oled_write(buffer, false);
// // }

// static void render_layer(void) {
//     // Host Keyboard Layer Status
//     oled_write_P(PSTR("LYR: "), false);
//     switch (get_highest_layer(layer_state)) {
//         case _QWERTY:
//             oled_write_ln_P(PSTR("Qwert"), false);
//             break;
//         case _LOWER:
//             oled_write_ln_P(PSTR("Lower"), false);
//             break;
//         case _RAISE:
//             oled_write_ln_P(PSTR("Raise"), false);
//             break;
//         case _GAMING:
//             oled_write_ln_P(PSTR("Games"), false);
//             break;
//         case _FUNCTION:
//             oled_write_ln_P(PSTR("Funct"), false);
//             break;
//         case _OSKEYS:
//             oled_write_ln_P(PSTR("OSKey"), false);
//             break;
//         case _HOLDF:
//             oled_write_ln_P(PSTR("HoldF"), false);
//             break;
//         case _NUMPAD:
//             oled_write_ln_P(PSTR("Numpd"), false);
//             break;
//         case _SYMBOLS:
//             oled_write_ln_P(PSTR("Smbls"), false);
//             break;
//         case _MEDIA:
//             oled_write_ln_P(PSTR("Media"), false);
//             break;
//         default:
//             oled_write_ln_P(PSTR("?????"), false);
//             break;
//     }
// }

// static void render_os(void) {
//     oled_write_P(PSTR("OS:  "), false);
//     uint8_t os_target  = get_os();
//     switch (os_target) {
//         case _OS_MACOS:
//             oled_write_P(PSTR("MacOS"), false);
//             break;
//         case _OS_WINDOWS:
//             oled_write_P(PSTR("Win10"), false);
//             break;
//         case _OS_LINUX:
//             oled_write_P(PSTR("Linux"), false);
//             break;
//     }
// }

// static void render_leds(void) {
//     // Host Keyboard LED Status
//     led_t led_state = host_keyboard_led_state();
//     oled_write_P(led_state.num_lock ? PSTR("NumLk")     : PSTR("     "), false);
//     oled_write_P(led_state.caps_lock ? PSTR("CapLk")    : PSTR("     "), false);
//     oled_write_P(led_state.scroll_lock ? PSTR("ScrLk")  : PSTR("     "), false);
// }

// void oled_task_user(void) {
//     if (is_keyboard_master()) {
//         render_layer();
//         oled_write_P(PSTR("-----"), false);
//         render_os();
//         oled_write_P(PSTR("-----"), false);
//         render_leds();
//         // oled_set_cursor(0, 12);
//         // render_rgbkb_logo();
//     }
//     else {
//         // switch (get_highest_layer(layer_state)) {
//         //     case _MEDIA:
//         //         render_rgb_menu();
//         //         break;
//         //     default:
//         //         break;
//         // }
//         // oled_set_cursor(0, 12);
//         render_layer();
//         oled_write_P(PSTR("-----"), false);
//         render_os();
//         oled_write_P(PSTR("-----"), false);
//         render_leds();
//         // oled_set_cursor(0, 12);
//         // render_rgbkb_logo()
//     }
// }

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     return OLED_ROTATION_270;
// }
// #endif





#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

static void render_caps(void) {
    led_t led_state = host_keyboard_led_state();
    // Host Keyboard LED Status
    oled_write_P(led_state.caps_lock ? PSTR(" CAPS")    : PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("qwrty"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("raise"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("games"), false);
            break;
        case _FUNCTION:
            oled_write_ln_P(PSTR("fnctn"), false);
            break;
        case _OSKEYS:
            oled_write_ln_P(PSTR("osKey"), false);
            break;
        case _HOLDF:
            oled_write_ln_P(PSTR("holdF"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("numpd"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("symbl"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("media"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
            break;
    }
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM function_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_FUNCTION) || layer_state_is(_OSKEYS)) {
        oled_write_P(function_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

static void render_os(void) {
    uint8_t os_target  = get_os();
    switch (os_target) {
        case _OS_MACOS:
            oled_write_P(PSTR("macOS"), false);
            break;
        case _OS_WINDOWS:
            oled_write_P(PSTR("win10"), false);
            break;
        case _OS_LINUX:
            oled_write_P(PSTR("linux"), false);
            break;
    }
}

void render_status_main(void) {
    render_space();
    render_layer_state();
    render_space();
    render_os();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    render_space();
    render_caps();
}

void render_status_secondary(void) {
    render_space();
    render_logo();
    render_space();
    render_logo();
    render_space();
    render_logo();
    render_space();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif
