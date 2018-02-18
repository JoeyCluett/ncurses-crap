#ifndef __JJC__NUI__LAYOUT__H__
#define __JJC__NUI__LAYOUT__H__

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

class NuiLayout {
private:
	int x = 0, y = 0, h = 0, w = 0;

public:
	// get window parameters
	int getX(void) { return x; }
	int getY(void) { return y; }
	int getH(void) { return h; }
	int getW(void) { return w; }

	void setPos(float x, float y, float h, float w);
};

void NuiLayout::setPos(float x, float y, float h, float w) {
	int rows, columns;
	getmaxyx(stdscr, rows, columns);
	float f_rows    = rows;
	float f_columns = columns;

	this->w = (int)(f_columns * w);
	this->h = (int)(f_rows * h);
	this->x = (int)(f_columns * x);
	this->y = (int)(f_rows * y);
}

#endif // __JJC__NUI__LAYOUT__H__
