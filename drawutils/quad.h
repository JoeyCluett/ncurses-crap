#pragma once

/*
    quad_t is similar to rectangle in that you can draw 
    filled rectangles. however, quad_t also has an angle 
    component so that you can draw rotated rectangles as well
*/

#include <iostream>
#include "core.h"
#include "triangle.h"
#include "line.h"

struct poly_t {
    float x1, y1, x2, y2, x3, y3, x4, y4;
};

std::ostream& operator<<(std::ostream& os, poly_t p) {
    os << "poly_t[ x1: " << p.x1 << ", y1: " << p.y1 
    << ", x2: " << p.x2 << ", y2: " << p.y2 
    << ", x3: " << p.x3 << ", y3: " << p.y3 
    << ", x4: " << p.x4 << ", y4: " << p.y4 << " ]";
    return os;
}

poly_t rotate(poly_t p, float a) {
    float sin_a = sinf(a);
    float cos_a = cosf(a);

    float tmp_x1 = p.x1 * cos_a - p.y1 * sin_a;
    float tmp_y1 = p.x1 * sin_a + p.y1 * cos_a;

    float tmp_x2 = p.x2 * cos_a - p.y2 * sin_a;
    float tmp_y2 = p.x2 * sin_a + p.y2 * cos_a;

    float tmp_x3 = p.x3 * cos_a - p.y3 * sin_a;
    float tmp_y3 = p.x3 * sin_a + p.y3 * cos_a;

    float tmp_x4 = p.x4 * cos_a - p.y4 * sin_a;
    float tmp_y4 = p.x4 * sin_a + p.y4 * cos_a;

    return {
        tmp_x1, tmp_y1, 
        tmp_x2, tmp_y2, 
        tmp_x3, tmp_y3, 
        tmp_x4, tmp_y4
    };
}

poly_t scale(poly_t p, float s) {
    return {
        p.x1 * s, p.y1 * s,
        p.x2 * s, p.y2 * s,
        p.x3 * s, p.y3 * s,
        p.x4 * s, p.y4 * s
    };
}

poly_t translate(poly_t p, float x, float y) {
    return {
        p.x1 + x, p.y1 + y,
        p.x2 + x, p.y2 + y,
        p.x3 + x, p.y3 + y,
        p.x4 + x, p.y4 + y
    };
}

void draw_quad(core_window_t& win, poly_t q, int color) {
    draw_line(win, {q.x1, q.y1, q.x2, q.y2}, color);
    draw_line(win, {q.x2, q.y2, q.x3, q.y3}, color);
    draw_line(win, {q.x3, q.y3, q.x4, q.y4}, color);
    draw_line(win, {q.x4, q.y4, q.x1, q.y1}, color);
}

void fill_quad(core_window_t& win, poly_t q, int color) {
    fill_triangle(win, {q.x1, q.y1, q.x2, q.y2, q.x3, q.y3}, color);
    fill_triangle(win, {q.x1, q.y1, q.x3, q.y3, q.x4, q.y4}, color);
}
