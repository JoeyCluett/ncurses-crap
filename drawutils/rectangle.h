#pragma once

#include "core.h"

// rectangle_t is restricted to axis-aligned 
// operations. if you need to rotate four 
// sided shapes, use quad_t

struct rectangle_t {
    float x, y, h, w;

    rectangle_t(float x, float y, float h, float w) {
        this->x = x;
        this->y = y;
        this->h = h;
        this->w = w;
    }
};

void draw_rectangle(core_window_t& win, rectangle_t r, int color) {
    int x = mapFloat(r.x, 0.0f, 1.0f, 0, win.num_columns());
    int y = mapFloat(r.y, 0.0f, 1.0f, 0, win.num_rows());
    int w = mapFloat(r.w, 0.0f, 1.0f, 0, win.num_columns());
    int h = mapFloat(r.h, 0.0f, 1.0f, 0, win.num_rows());

    int min_x = x;
    int max_x = x + w;
    int min_y = y;
    int max_y = y + h;

    win.set_attribute(COLOR_PAIR(color));

    for(int j : {min_y, max_y}) {
        for(int i = min_x; i <= max_x; i++)
            win.draw_char_at(j, i, 'X');
    }

    for(int i : {min_x, max_x}) {
        for(int j = min_y; j <= max_y; j++)
            win.draw_char_at(j, i, 'X');
    }

    win.reset_attribute(COLOR_PAIR(color));
}

void fill_rectangle(core_window_t& win, rectangle_t r, int color) {
    int x = mapFloat(r.x, 0.0f, 1.0f, 0, win.num_columns());
    int y = mapFloat(r.y, 0.0f, 1.0f, 0, win.num_rows());
    int w = mapFloat(r.w, 0.0f, 1.0f, 0, win.num_columns());
    int h = mapFloat(r.h, 0.0f, 1.0f, 0, win.num_rows());

    int max_x = x + w;
    int max_y = y + h;

    win.set_attribute(COLOR_PAIR(color));

    for(int i = x; i <= max_x; i++) {
        for(int j = y; j <= max_y; j++) {
            win.draw_char_at(j, i, ' ');
        }
    }

    win.reset_attribute(COLOR_PAIR(color));
}
