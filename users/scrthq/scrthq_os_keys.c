/*
Copyright 2021 Nate Ferrell <nate@scrthq.com> <@scrthq>

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

#    include QMK_KEYBOARD_H
#    include "scrthq_os_keys.h"

__attribute__((weak)) void store_userspace_config(void);
__attribute__((weak)) void set_os(uint8_t os);
__attribute__((weak)) uint8_t get_os(void) {return 1;}

bool send_os_key(uint16_t keycode, keyrecord_t *record) {
    uint8_t os_target  = get_os();
    bool    pressed = record->event.pressed;
#ifdef CONSOLE_ENABLE
    switch (os_target) {
        case _OS_MACOS:
            uprintf("[MAC] Sending OS key: ");
            break;
        default:
            uprintf("[WIN] Sending OS key: ");
            break;
    }
#endif
    switch (keycode) {
        case _OSKEY_STORE_CONFIG:
#ifdef CONSOLE_ENABLE
            uprintf("_OSKEY_STORE_CONFIG\n");
#endif
            store_userspace_config();
            break;

        case _OSKEY_SET_MAC:
#ifdef CONSOLE_ENABLE
            uprintf("_OSKEY_SET_MAC\n");
#endif
            set_os(_OS_MACOS);
            break;

        case _OSKEY_SET_WIN:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_MACOS\n");
#endif
            set_os(_OS_WINDOWS);
            break;

        case _OSKEY_SET_LIN:
#ifdef CONSOLE_ENABLE
            uprintf("_OSKEY_SET_LIN\n");
#endif
            set_os(_OS_LINUX);
            break;

        case _OS_APP_LINE_COMMENT:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_LINE_COMMENT\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("/"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTL("/"));
                    break;
            }
            break;

        case _OS_MISSION_CONTROL:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_MISSION_CONTROL\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(MCHYP(X_UP));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(IMGUI(X_TAB));
                    break;
            }
            break;

        case _OS_APP_BLOCK_COMMENT:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_BLOCK_COMMENT\n");
#endif
            if (pressed) SEND_STRING(OMSFT(IMALT(X_A)));
            break;

        case _OS_APP_FILE_LANGUAGE_SELECT:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_FILE_LANGUAGE_SELECT\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("k") SS_TAP(X_M));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTL("k") SS_TAP(X_M));
                    break;
            }
            break;

        case _OS_APP_FOLD_ALL:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_FOLD_ALL\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("k0"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTL("k0"));
                    break;
            }
            break;

        case _OS_APP_FOLD_RECURSIVELY:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_FOLD_RECURSIVELY\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("k["));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTL("k["));
                    break;
            }
            break;

        case _OS_APP_MULTI_SELECT:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_MULTI_SELECT\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMSFT(IMGUI(X_L)));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(IMCTL(X_L)));
                    break;
            }
            break;

        case _OS_APP_SAVE:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_SAVE\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("s"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTL("s"));
                    break;
            }
            break;

        case _OS_APP_UNFOLD_ALL:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_UNFOLD_ALL\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("kj"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTL("kj"));
                    break;
            }
            break;

        case _OS_APP_UNFOLD_RECURSIVELY:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_UNFOLD_RECURSIVELY\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("k]"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTL("k]"));
                    break;
            }
            break;

        case _OS_APP_FOLD:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_FOLD\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMSFT(IMGUI(X_LBRACKET)));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(SS_LCTRL("[")));
                    break;
            }
            break;

        case _OS_APP_UNFOLD:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_APP_UNFOLD\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMSFT(IMGUI(X_RBRACKET)));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(SS_LCTRL("]")));
                    break;
            }
            break;

        case _OS_BROWSER_BUL_LIST:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_BUL_LIST\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMSFT(SS_LGUI("8")));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(SS_LCTRL("8")));
                    break;
            }
            break;

        case _OS_BROWSER_CLOSE_TAB:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_CLOSE_TAB\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("w"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("w"));
                    break;
            }
            break;

        case _OS_BROWSER_DEV_TOOLS:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_DEV_TOOLS\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMGUI(SS_LALT("i")));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(SS_LCTRL("i")));
                    break;
            }
            break;

        case _OS_BROWSER_NEW_TAB:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_NEW_TAB\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_T));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("t"));
                    break;
            }
            break;

        case _OS_BROWSER_NUM_LIST:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_NUM_LIST\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMSFT(SS_LGUI("7")));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(SS_LCTRL("7")));
                    break;
            }
            break;

        case _OS_BROWSER_RELOAD:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_RELOAD\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMGUI(SS_LSFT("r")));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(IMCTL(X_F5));
                    break;
            }
            break;

        case _OS_BROWSER_REOPEN_LAST_TAB:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_REOPEN_LAST_TAB\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMSFT(SS_LGUI("t")));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(IMCTL(X_T)));
                    break;
            }
            break;

        case _OS_BROWSER_ZOOM_IN:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_ZOOM_IN\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_KP_PLUS));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(IMCTL(X_EQUAL)));
                    break;
            }
            break;

        case _OS_BROWSER_ZOOM_OUT:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_BROWSER_ZOOM_OUT\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_KP_MINUS));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(IMCTL(X_MINUS));
                    break;
            }
            break;

        case _OS_CLIP_HISTORY:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_CLIP_HISTORY\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMALT(IMGUI(X_V)));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LGUI("v"));
                    break;
            }
            break;

        case _OS_COPY:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_COPY\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("c"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("c"));
                    break;
            }
            break;

        case _OS_CUT:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_CUT\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("x"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("x"));
                    break;
            }
            break;

        case _OS_INDENT:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_INDENT\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_RBRACKET));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("]"));
                    break;
            }
            break;

        case _OS_DEL_LEFT_WORD:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_DEL_LEFT_WORD\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMALT(X_BSPACE));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(IMCTL(X_BSPACE));
                    break;
            }
            break;

        case _OS_FIND_REPLACE:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_FIND_REPLACE\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMALT(IMGUI(X_F)));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("h"));
                    break;
            }
            break;

        case _OS_FIND:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_FIND\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("f"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("f"));
                    break;
            }
            break;

        case _OS_GO_END_DOC:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_GO_END_DOC\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_DOWN));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMGUI(IMCTL(X_RIGHT)));
                    break;
            }
            break;

        case _OS_GO_END_LINE:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_GO_END_LINE\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_RIGHT));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_TAP(X_END));
                    break;
            }
            break;

        case _OS_GO_LEFT_WORD:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_GO_LEFT_WORD\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMALT(X_LEFT));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(IMCTL(X_LEFT));
                    break;
            }
            break;

        case _OS_GO_RIGHT_WORD:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_GO_RIGHT_WORD\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMALT(X_RIGHT));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(IMCTL(X_RIGHT));
                    break;
            }
            break;

        case _OS_GO_START_DOC:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_GO_START_DOC\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_UP));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMGUI(IMCTL(X_LEFT)));
                    break;
            }
            break;

        case _OS_GO_START_LINE:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_GO_START_LINE\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_LEFT));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_TAP(X_HOME));
                    break;
            }
            break;

        case _OS_DEDENT:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_DEDENT\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_LBRACKET));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("["));
                    break;
            }
            break;

        case _OS_PASTE_PLAIN:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_PASTE_PLAIN\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMSFT(IMGUI(X_V)));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(OMSFT(IMCTL(X_V)));
                    break;
            }
            break;

        case _OS_PASTE:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_PASTE\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("v"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("v"));
                    break;
            }
            break;

        case _OS_REDO:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_REDO\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(OMGUI(IMSFT(X_Z)));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("y"));
                    break;
            }
            break;

        case _OS_SCREENCAPTURE:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_SCREENCAPTURE\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(IMGUI(X_PSCREEN));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_TAP(X_PSCREEN));
                    break;
            }
            break;

        case _OS_SELECT_ALL:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_SELECT_ALL\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("a"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("a"));
                    break;
            }
            break;

        case _OS_UNDO:
#ifdef CONSOLE_ENABLE
            uprintf("_OS_UNDO\n");
#endif
            switch (os_target) {
                case _OS_MACOS:
                    if (pressed) SEND_STRING(SS_LGUI("z"));
                    break;
                case _OS_WINDOWS:
                    if (pressed) SEND_STRING(SS_LCTRL("z"));
                    break;
            }
            break;
    }

    return false;
}
