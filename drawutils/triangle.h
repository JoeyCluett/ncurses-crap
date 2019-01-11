#pragma once

#include "core.h"
#include "line.h"

struct triangle_t {
    float x1, y1, x2, y2, x3, y3;

    triangle_t(float x1, float y1, float x2, float y2, float x3, float y3) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
    }

};

void draw_triangle(core_window_t& cw, triangle_t tri, int color) {
    draw_line(cw, {tri.x1, tri.y1, tri.x2, tri.y2}, color);
    draw_line(cw, {tri.x2, tri.y2, tri.x3, tri.y3}, color);
    draw_line(cw, {tri.x3, tri.y3, tri.x1, tri.y1}, color);
}

void fill_triangle(core_window_t& win, triangle_t tri, int color) {
    // sort the vertices in increasing y-order

    if(tri.y2 < tri.y1) {
        
    }

    if(tri.y3 < tri.y2) {

    }

}