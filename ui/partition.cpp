#include <ncurses.h>

// custom Ncurses UI stuff
#include "lib/NuiUtility.hpp"
#include "lib/NuiPartition.hpp"

int main(int argc, char* argv[]) {

	NuiUtility_StartNcurses();

	int color1 = NuiUtility_InitColorPair(COLOR_RED,   COLOR_RED);
	int color2 = NuiUtility_InitColorPair(COLOR_CYAN,  COLOR_CYAN);
	int color3 = NuiUtility_InitColorPair(COLOR_GREEN, COLOR_GREEN);
	int color4 = NuiUtility_InitColorPair(COLOR_BLUE,  COLOR_BLUE);

	NuiPartition nuipartition1(color1); 
	NuiPartition nuipartition2(color2);
	NuiPartition nuipartition3(color3);
	NuiPartition nuipartition4(color1);
	NuiPartition nuipartition5(color4);

	nuipartition1
			._X_(0.0f)
			._Y_(0.0f)
			._W_(0.5f)
			._H_(0.1f)
			.done();

	nuipartition2
			._X_(0.5f)
			._Y_(0.0f)
			._W_(0.5f)
			._H_(0.5f)
			.done();
	
	nuipartition3
			._X_(0.5f)
			._Y_(0.5f, 1)
			._W_(0.5f)
			._H_(0.5f)
			.done();

	nuipartition4
			._X_(0.0f)
			._Y_(1.0f, -3)
			._W_(0.5f)
			._H_(0.0f, 3)
			.done(); 

	nuipartition5
			._X_(0.0f)
			._Y_(0.1f, 1)
			._W_(0.5f)
			._H_(0.9f, -3)
			.done();

	// refresh the windows
	NuiPartition::refresh();

	refresh();
	int ch = getch();
	endwin();
	return 0;
}

