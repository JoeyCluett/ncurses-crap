#pragma once

#include "core.h"
#include <math.h>

struct circle_t {
    float x, y, r;
};

void draw_circle(core_window_t& win, circle_t c, int color) {
    float x = mapFloat(c.x, 0.0f, 1.0f, 0, win.num_columns());
    float y = mapFloat(c.y, 0.0f, 1.0f, 0, win.num_rows());

    int cols = win.num_columns();
    int rows = win.num_rows();
    int r = mapFloat(c.r, 0.0f, 1.0f, 0, (cols < rows) ? cols : rows);

    int num_steps = r * 2.0f * 3.14f;

    win.set_attribute(COLOR_PAIR(color));

    for(int i = 0; i <= num_steps; i++) {
        float a = mapFloat(i, 0, num_steps, 0.0f, 2.0f * M_PI);
        win.draw_char_at(y+(r*sinf(a)), x+(r*cosf(a)), 'X');
    }

    win.reset_attribute(COLOR_PAIR(color));

}

void fill_circle(core_window_t& win, circle_t c, int color) {
    int x = mapFloat(c.x, 0.0f, 1.0f, 0, win.num_columns());
    int y = mapFloat(c.y, 0.0f, 1.0f, 0, win.num_rows());

    int cols = win.num_columns();
    int rows = win.num_rows();
    int r = mapFloat(c.r, 0.0f, 1.0f, 0, (cols < rows) ? cols : rows);

    int min_x = x - r;
    int max_x = x + r;
    int min_y = y - r;
    int max_y = y + r;

    auto distance_squared = [](int x1, int y1, int x2, int y2) -> int {
        int dx = x1 - x2;
        int dy = y1 - y2;

        return (dx*dx + dy*dy);
    };

    int minimum_distance = r*r;

    // iterate through every pixel in the axis aligned 
    // area and test if it is in the circle

    win.set_attribute(COLOR_PAIR(color));

    for(int j = min_y; j <= max_y; j++) {
        for(int i = min_x; i <= max_x; i++) {
            if(distance_squared(i, j, x, y) <= minimum_distance)
                win.draw_char_at(j, i, 'X');
        }
    }

    win.reset_attribute(COLOR_PAIR(color));

}
