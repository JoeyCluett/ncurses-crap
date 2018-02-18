#ifndef __JJC__NUI__PARTITION__H__
#define __JJC__NUI__PARTITION__H__

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

#include <ncurses.h>
#include <vector>
#include "NuiUtility.hpp"

/*
	The root window for all windows is stdscr
*/

class NuiPartition {
private:
	WINDOW* win = NULL;
	int x = 0, y = 0, w = 0, h = 0;
	int xoff = 0, yoff = 0, woff = 0, hoff = 0;
	float _x = -1, _y = -1, _w = -1, _h = -1;

	int color_pair = -1;

public:
	static std::vector<WINDOW*> window_vec;
	static void refresh(void);

	NuiPartition(int color_pair); // color pairs need to be initialized beforehand

	WINDOW* getWindow(void) { return win; }

	// get window parameters
	int getX(void) { return x; }
	int getY(void) { return y; }
	int getH(void) { return h; }
	int getW(void) { return w; }

	NuiPartition& _X_(float x, int offset = 0) { _x = x; xoff = offset; return *this; }
	NuiPartition& _Y_(float y, int offset = 0) { _y = y; yoff = offset; return *this; }
	NuiPartition& _H_(float h, int offset = 0) { _h = h; hoff = offset; return *this; }
	NuiPartition& _W_(float w, int offset = 0) { _w = w; woff = offset; return *this; }

	NuiPartition& done(void);
	NuiPartition& outline(void);

};

NuiPartition::NuiPartition(int color_pair) {
	this->color_pair = color_pair;
}

void NuiPartition::refresh(void) {
	for(int i = 0; i < window_vec.size(); i++) 
		wrefresh(window_vec[i]);
	//refresh();
}

NuiPartition& NuiPartition::outline(void) {
	wborder(this->win, '|', '|', '-', '-', '+', '+', '+', '+');
	return *this;
}

NuiPartition& NuiPartition::done(void) {
	int rows, columns;
	getmaxyx(stdscr, rows, columns);
	float f_rows    = rows;
	float f_columns = columns;

	this->w = (int)(f_columns * _w);
	this->h = (int)(f_rows * _h);
	this->x = (int)(f_columns * _x);
	this->y = (int)(f_rows * _y);

	this->w += this->woff;
	this->h += this->hoff;
	this->x += this->xoff;
	this->y += this->yoff;

	win = newwin(this->h, this->w, this->y, this->x);
	window_vec.push_back(win);
	wbkgd(win, COLOR_PAIR(this->color_pair));

	return *this;
}

// holds all WINDOW pointers for refresh phase
std::vector<WINDOW*> NuiPartition::window_vec = std::vector<WINDOW*>();

#endif // __JJC__NUI__PARTITION__H__