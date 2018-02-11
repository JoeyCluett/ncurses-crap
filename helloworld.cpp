#include <iostream>
#include <ncurses.h>

using namespace std;

int main(int argc, char* argv[]) {
	initscr(); // start curses mode
	start_color(); // start color functionality

	// disable line buffering and enable special keys (F1, F2, arrow keys, etc.)
	raw();
	keypad(stdscr, TRUE);
	noecho();

	// initialize color pair
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_RED); // foreground, background

	// print string with color information
	printw("A big string");
	mvchgat(0, 0, -1, A_BOLD, 2, NULL);
	//                        ^ color index

	refresh(); // print to real screen
	getch(); // wait for user input
	endwin(); // end curses mode

	return 0;

}