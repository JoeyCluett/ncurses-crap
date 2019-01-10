#ifndef __JJC__NUI__REFRESH__H__
#define __JJC__NUI__REFRESH__H__

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
#include <vector>

class NuiUpdate {
public:
	NuiUpdate(void);

	static void CUR(void);

	// using ui_update instead of refresh to avoid ambiguous
	// function calls to ncurses refresh function
	virtual void ui_update(void) = 0;

	// update all NuiUpdate objects
	static void update_all(void);
};

// polymorphise
static std::vector<NuiUpdate*> ui_update_vec;

NuiUpdate::NuiUpdate(void) {
	ui_update_vec.push_back(this);
}

void NuiUpdate::update_all(void) {
	for(int i = 0; i < ui_update_vec.size(); i++) {
		ui_update_vec[i]->ui_update();
	}
}

void NuiUpdate::CUR(void) {
	NuiPartition::cleanAll();
	NuiUpdate::update_all();
	NuiPartition::refresh();
}

#endif // __JJC__NUI__REFRESH__H__

