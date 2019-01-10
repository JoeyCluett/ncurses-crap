#pragma once

#include <ncurses.h>
#include <string>

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
    }

    // de-init ncurses subsystem
    ~core_window_t(void) {
        endwin();
    }

    int num_rows(void) {
        return this->rows;
    }

    int num_columns(void) {
        return this->columns;
    }

    void set_bold(void) {
        attron(A_BOLD);
    }

    void reset_bold(void) {
        attroff(A_BOLD);
    }

    void set_attribute(int attr) {
        attron(attr);
    }

    void reset_attribute(int attr) {
        attroff(attr);
    }

    int get_char(void) {
        return getch();
    }

    void print_string(std::string str) {
        printw(str.c_str());
    }

    void print_char(int c) {
        printw("%c", c);
    }

    void flip(void) {
        refresh();
    }

    void draw_char_at(int y, int x, int ch) {
        mvaddch(y, x, ch);
    }

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
