#include <ncurses.h>
#include "lib/NuiAll.hpp"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	NuiUtility_StartNcurses();

	int colorBlackRed     = NuiUtility_InitColorPair(COLOR_GREEN, COLOR_WHITE);
	int colorRedBlack     = NuiUtility_InitColorPair(COLOR_RED, COLOR_BLACK);
	int colorBlackMagenta = NuiUtility_InitColorPair(COLOR_BLACK, COLOR_MAGENTA);

	NuiSingleLineInput nuisli(colorBlackRed);
	nuisli
		._X_(0.0f)
		._Y_(1.0f, -3)
		._W_(1.0f)
		._H_(0.0f, 3)
		.done();

	NuiSingleLineOutput nuislo(colorRedBlack);
	nuislo
		._X_(0.0f)
		._Y_(0.0f)
		._W_(1.0f)
		._H_(0.0f, 3)
		.done();

	NuiUpdate::CUR();

	bool exit = false;
	while(!exit) {
		string txt_input = nuisli.getInput();
		
		if(txt_input == "exit" || txt_input == "EXIT")
			exit = true;

		nuislo.setText(txt_input);
		nuisli.clearText();

		NuiUpdate::CUR();
	}

	endwin();

	return 0;
}
