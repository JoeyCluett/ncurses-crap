#include "lib/NuiUtility.hpp"
#include "lib/NuiSingleLineInput.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	NuiUtility_StartNcurses();
	int colorRedBlue = 
			NuiUtility_InitColorPair(COLOR_RED, COLOR_BLUE);

	NuiSingleLineInput nuisli(colorRedBlue);
	nuisli
		._X_(0.0f)
		._Y_(1.0f, -3)
		._W_(1.0f)
		._H_(0.0f, 3)
		.done();

	NuiPartition::refresh();
	refresh();

	string input_str = nuisli.getInput();	

	endwin();
	cout << input_str << endl;

	return 0;
}
