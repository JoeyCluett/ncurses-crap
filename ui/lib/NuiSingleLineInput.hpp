#ifndef __JJC__NUI__SINGLE__LINE__INPUT__H__
#define __JJC__NUI__SINGLE__LINE__INPUT__H__

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
#include "NuiUtility.hpp"
#include "NuiPartition.hpp"
#include "NuiUpdate.hpp"
#include <string.h>
#include <string>

class NuiSingleLineInput : public NuiPartition, public NuiUpdate {
protected:

public:
	NuiSingleLineInput(int color_pair);
	std::string getInput(void);
	void clearText(void);

	// inherited virtual method
	void ui_update(void);
};

// define the virtual function from NuiUpdate
// for this class, put an outline
void NuiSingleLineInput::ui_update(void) {
	box(this->win, 0, 0);
}

NuiSingleLineInput::NuiSingleLineInput(int color_pair) : NuiPartition(color_pair), NuiUpdate() {
	keypad(this->win, TRUE);
}

std::string NuiSingleLineInput::getInput(void) {
	int _getY = this->h / 2;
	//if(this->h % 2)
		//_getY++;

	wmove(this->win, _getY, 1);
	wrefresh(this->win);

	char buf[128];
	wgetstr(this->win, buf);
	std::string input_str = buf;
	return input_str;
}

void NuiSingleLineInput::clearText(void) {
	clean();
	ui_update();
	wrefresh(this->win);
}

#endif // __JJC__NUI__SINGLE__LINE__INPUT__H__