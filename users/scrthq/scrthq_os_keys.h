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


Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and jeebak & algernon's keymap
*/

#pragma once
#include "quantum.h"

/// Hacks to make it easier to create sendstring macros (using from BabblePaste)

enum os_types {
    _OS_MACOS = 0,
    _OS_WINDOWS,
    _OS_LINUX,
};

//"outer" versions wrap text
#    define OMCTL(arg) SS_DOWN(X_LCTRL) arg SS_UP(X_LCTRL)
#    define OMGUI(arg) SS_DOWN(X_LGUI) arg SS_UP(X_LGUI)
#    define OMALT(arg) SS_DOWN(X_LALT) arg SS_UP(X_LALT)
#    define OMSFT(...) SS_DOWN(X_LSHIFT) __VA_ARGS__ SS_UP(X_LSHIFT)
//"inner" versions wrap a key tap
#    define IMCTL(arg) SS_DOWN(X_LCTRL) SS_TAP(arg) SS_UP(X_LCTRL)
#    define IMGUI(arg) SS_DOWN(X_LGUI) SS_TAP(arg) SS_UP(X_LGUI)
#    define IMALT(arg) SS_DOWN(X_LALT) SS_TAP(arg) SS_UP(X_LALT)
#    define IMSFT(arg) SS_DOWN(X_LSHIFT) SS_TAP(arg) SS_UP(X_LSHIFT)

#    if defined(NEW_SAFE_RANGE)
#        define _OSKEY_START NEW_SAFE_RANGE
#    else
#        if defined(KEYMAP_SAFE_RANGE)
#            define _OSKEY_START KEYMAP_SAFE_RANGE
#        else
#            define _OSKEY_START SAFE_RANGE
#        endif
#    endif

enum os_keys {
    START = _OSKEY_START,

    _OSKEY_STORE_CONFIG,
    _OSKEY_SET_MAC,
    _OSKEY_SET_WIN,
    _OSKEY_SET_LIN,

    _OS_APP_FILE_LANGUAGE_SELECT,
    _OS_APP_FOLD_ALL,
    _OS_APP_FOLD_RECURSIVELY,
    _OS_APP_MULTI_SELECT,
    _OS_APP_SAVE,
    _OS_APP_UNFOLD_ALL,
    _OS_APP_UNFOLD_RECURSIVELY,
    _OS_BROWSER_BUL_LIST,
    _OS_BROWSER_CLOSE_TAB,
    _OS_BROWSER_DEV_TOOLS,
    _OS_BROWSER_NEW_TAB,
    _OS_BROWSER_NUM_LIST,
    _OS_BROWSER_RELOAD,
    _OS_BROWSER_REOPEN_LAST_TAB,
    _OS_BROWSER_ZOOM_IN,
    _OS_BROWSER_ZOOM_OUT,
    _OS_CLIP_HISTORY,
    _OS_COPY,
    _OS_CUT,
    _OS_DEDENT,
    _OS_DEL_LEFT_WORD,
    _OS_FIND_REPLACE,
    _OS_FIND,
    _OS_GO_END_DOC,
    _OS_GO_END_LINE,
    _OS_GO_LEFT_WORD,
    _OS_GO_RIGHT_WORD,
    _OS_GO_START_DOC,
    _OS_GO_START_LINE,
    _OS_INDENT,
    _OS_PASTE_PLAIN,
    _OS_PASTE,
    _OS_REDO,
    _OS_SCREENCAPTURE,
    _OS_SELECT_ALL,
    _OS_UNDO,

    _OSKEY_END,
};
