#include <ncurses.h>
#include "lib/NuiSingleLineInput.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	NuiUtility_StartNcurses();

	int colorRedBlue  = NuiUtility_InitColorPair(COLOR_RED, COLOR_BLUE);
	int colorRedBlack = NuiUtility_InitColorPair(COLOR_RED, COLOR_BLACK);

	
	
}