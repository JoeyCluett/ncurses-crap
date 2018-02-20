#include "lib/NuiUtility.hpp"
#include "lib/NuiSingleLineInput.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

vector<string> str_vec;

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

	NuiPartition::cleanAll();
	NuiUpdate::update_all();
	NuiPartition::refresh();

	// capture strings until 'exit' is typed
	bool exit = false;
	while(!exit) {
		string input_str = nuisli.getInput();
		if(input_str == "exit")
			exit = true;

		str_vec.push_back(input_str);
		nuisli.clearText();
	}

	endwin();

	for(int i = 0; i < str_vec.size(); i++)
		cout << str_vec[i] << endl;

	return 0;
}


