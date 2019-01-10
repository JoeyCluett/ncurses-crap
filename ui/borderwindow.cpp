#include <ncurses.h>

#define HEIGHT 10
#define WIDTH  20
#define Y 10
#define X 10

int main(int argc, char* argv[]) {
	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();

	init_pair(1, COLOR_YELLOW, COLOR_RED);
	init_pair(2, COLOR_CYAN, COLOR_WHITE);

	bkgd(COLOR_PAIR(1));
	box(stdscr, 0, 0);
  
	WINDOW* win = newwin(HEIGHT, WIDTH, Y, X);
	wbkgd(win, COLOR_PAIR(2));
	box(win, 0, 0);

	refresh();
	wrefresh(win);

	int ch = getch();
 
	endwin();
	return 0;
}
