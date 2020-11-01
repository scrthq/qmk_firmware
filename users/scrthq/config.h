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

#define MACRO_DELAY 30

#ifndef TAPPING_TOGGLE
#define TAPPING_TOGGLE  3
#endif

#ifdef TAPPING_TERM
	#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 200
//if no chord during tapping term, do the keystroke
//#define RETRO_TAPPING

#define USE_BABBLEPASTE

// All options
#define BABL_MOVE // Uncomment to add basic cursor movement
#define BABL_OSKEYS // This adds Cut, paste, window movement and common OS shortcuts
#define BABL_BROWSER // Browser shortcuts, with Chrome/Firefox as the default.
// edit the appropriate OS config file to enable Safari, Edge, vimpirator &etc.
#define BABL_APP // Application specific settings this has sub-options.
//#define BABL_APP_CELLS // spreadsheets and tables
#define BABL_APP_EDITOR // Fancy editor commands
#define BABL_APP_WINDOWSPLITTING // splitting frames & windows

//All OSes
#define BABL_WINDOWS
#define BABL_VI
#define BABL_MAC
