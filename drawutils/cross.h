#pragma once

#include <iostream>
#include "core.h"
#include "line.h"

// important to remember that this x/y is the center of the cross

struct cross_t {
    float x, y, h, w;
};

std::ostream& operator<<(std::ostream& os, cross_t c) {
    os << "cross_t[ x: " << c.x << ", y: " << c.y 
    << ", h: " << c.h << ", w: " << c.w << " ]";
    return os;
}

void draw_cross(core_window_t& win, cross_t c, int color) {
    float x1 = c.x - (c.w / 2.0f);
    float y1 = c.y - (c.h / 2.0f);
    float x2 = x1 + c.w;
    float y2 = y1 + c.h;

    draw_line(win, {x1, y1, x2, y2}, color);

    x1 = c.x + (c.w / 2.0f);
    y1 = c.y - (c.h / 2.0f);
    x2 = c.x - (c.w / 2.0f);
    y2 = c.y + (c.h / 2.0f);

    draw_line(win, {x1, y1, x2, y2}, color);
}
