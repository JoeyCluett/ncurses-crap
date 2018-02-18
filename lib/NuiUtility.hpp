#ifndef __JJC__NUI__UTILITY__H__
#define __JJC__NUI__UTILITY__H__

/*
	This is free and unencumbered software released into the public domain.

	Anyone is free to copy, modify, publish, use, compile, sell, or
	distribute this software, either in source code form or as a compiled
	binary, for any purpose, commercial or non-commercial, and by any
	means.

	In jurisdictions that recognize copyright laws, the author or authors
	of this software dedicate any and all copyright interest in the
	software to the public domain. We make this dedication for the benefit
	of the public at large and to the detriment of our heirs and
	successors. We intend this dedication to be an overt act of
	relinquishment in perpetuity of all present and future rights to this
	software under copyright law.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
	OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
	ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.

	For more information, please refer to <http://unlicense.org/>
*/

#include <string.h>
#include <string>
#include <map>
#include <ncurses.h>

enum NuiWindowMethod {
	// NUI will try to make everything fit according to given dimensions
	NuiWindowMethod_Absolute  = 0, // give specific size (i.e. 3 rows, 3 columns)
	NuiWindowMethod_Relative  = 1, // give normalized percent (0.1 for 1/10th of screen space)
	NuiWindowMethod_Remaining = 2  // give this window all remaining space
};

enum NuiWindowGravity {
	NuiWindowGravity_Up    = 0, 
	NuiWindowGravity_Down  = 1,
	NuiWindowGravity_Left  = 2,
	NuiWindowGravity_Right = 3
};

void NuiUtility_MainWindowSize(int& y, int& x) {
	getmaxyx(stdscr, y, x);
}

void NuiUtility_WindowSize(WINDOW* win, int& y, int& x) {
	getmaxyx(win, y, x);
}

void NuiUtility_StartNcurses(void) {
	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();
}

// color pair utilities
int NuiUtility_InitColorPair(int text_color, int background_color) {
	static int index = 0;
	index = index % 7;
	index++;
	init_pair(index, text_color, background_color);
	return index;
}

#endif // __JJC__NUI__UTILITY__H__