#ifndef __JJC__NUI__SCROLLING__OUTPUT__H__
#define __JJC__NUI__SCROLLING__OUTPUT__H__

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

#include "NuiUtility.hpp"
#include "NuiPartition.hpp"
#include "NuiUpdate.hpp"

#include <vector>
#include <string>

class NuiScrollingOutput : public NuiPartition, public NuiUpdate {
private:
	std::vector<std::string> str_list;
	int max_strs = 0;  // specified by user

public:
	NuiScrollingOutput(int color_pair);

	void setMaxStrs(int max_strs) { this->max_strs = max_strs; }

	NuiScrollingOutput& addString(const std::string& txt_str);

	// inherited virtual method
	void ui_update(void);
};

NuiScrollingOutput::NuiScrollingOutput(int color_pair) : NuiPartition(color_pair), NuiUpdate() {
	keypad(this->win, TRUE);
}

NuiScrollingOutput& NuiScrollingOutput::addString(const std::string& txt_str) {
	
}

void NuiScrollingOutput::ui_update(void) {
	box(this->win, 0, 0);

	int num_lines = this->h -2;
	if(num_lines <= 0)
		return;

	clean();
	wmove(this->win, 1, 1);

	for(int i = 0; i < str_list.size() && i < num_lines; i++)
		waddstr(this->win, str_list[i].c_str());
}

#endif // __JJC__NUI__SCROLLING__OUTPUT__H__