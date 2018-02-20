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
#include <string.h>
#include <string>

class NuiSingleLineInput : public NuiPartition {
protected:

public:
	NuiSingleLineInput(int color_pair);
	std::string getInput(void);
	void clearText(void);
};

NuiSingleLineInput::NuiSingleLineInput(int color_pair) : NuiPartition(color_pair) {
	keypad(this->win, TRUE);
}

std::string NuiSingleLineInput::getInput(void) {
	int _getY = this->h / 2;
	//if(this->h % 2)
		//_getY++;

	wmove(this->win, _getY, 1);
	wrefresh(this->win);

	std::string str_input = "";

	// build string until user presses newline
	while(str_input.length() < this->getW()-2) {
		char ch = (char)wgetch(this->win);
		if(ch == '\n') {
			return str_input;
		}
		str_input += ch;
	}
}

void NuiSingleLineInput::clearText(void) {

}

#endif // __JJC__NUI__SINGLE__LINE__INPUT__H__