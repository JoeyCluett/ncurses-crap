#pragma once

#include <drawutils/drawutils.h>

class player_tile_t {
public:
    triangle_t base;
    line_t back;
    line_t mid;

    float x, y;
    float theta;

    int base_color, line_color;

    player_tile_t(int base_color, int line_color) {
        this->base_color = base_color;
        this->line_color = line_color;

        base = { -0.1f, -0.1f, 0.0f, 0.1f, 0.1f, -0.1f };
        back = {-0.1f, -0.1f, 0.1f, -0.1f};
        mid = {0.0f, -0.1f, 0.0f, 0.1f};
    }

    void draw(core_window_t& win) {
        fill_triangle(win, translate(rotate(this->base, theta), x, y), this->base_color);
        draw_line(win, translate(rotate(this->back, theta), x, y), this->line_color);
        draw_line(win, translate(rotate(this->mid, theta), x, y), this->line_color);
    }
};
