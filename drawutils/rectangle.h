#pragma once

#include "core.h"

struct rectangle_t {
    float x, y, h, w;

    rectangle_t(float x, float y, float h, float w) {
        this->x = x;
        this->y = y;
        this->h = h;
        this->w = w;
    }
};

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
