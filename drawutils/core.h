#pragma once

#include <ncurses.h>
#include <string>

const int core_color_red   = 1;
const int core_color_green = 2;
const int core_color_blue  = 3;
const int core_color_white = 4;
const int core_color_black = 5;

class core_window_t {
private:
    int rows = 0;
    int columns = 0;

public:
    core_window_t(void) {
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();

        getmaxyx(stdscr, this->rows, this->columns);

        // setup the colors used in this API
        start_color();
        init_pair(core_color_red,   COLOR_RED,   COLOR_RED);
        init_pair(core_color_green, COLOR_GREEN, COLOR_GREEN);
        init_pair(core_color_blue,  COLOR_BLUE,  COLOR_BLUE);
        init_pair(core_color_white, COLOR_WHITE, COLOR_WHITE);
        init_pair(core_color_black, COLOR_BLACK, COLOR_BLACK);
    }

    // de-init ncurses subsystem
    ~core_window_t(void) {
        endwin();
    }

    void clear_screen(void) {
        for(int y = 0; y < this->rows; y++) {
            for(int x = 0; x < this->columns; x++)
                this->draw_char_at(y, x, ' ');
        }
    }

    int num_rows(void) { return this->rows; }
    int num_columns(void) { return this->columns; }
    void set_attribute(int attr) { attron(attr); }
    void reset_attribute(int attr) { attroff(attr); }
    int get_char(void) { return getch(); }
    void print_string(std::string str) { printw(str.c_str()); }
    void print_char(int c) { printw("%c", c); }
    void flip(void) { refresh(); }
    void draw_char_at(int y, int x, int ch) { mvaddch(y, x, ch); }
};

float mapFloat(
        float input, 
        float input_start,  float input_end, 
        float output_start, float output_end) {

    return output_start 
            + ((output_end - output_start) 
            / (input_end - input_start)) 
            * (input - input_start);
}
