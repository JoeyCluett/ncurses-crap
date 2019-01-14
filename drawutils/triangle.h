#pragma once

#include "core.h"
#include "line.h"
#include "vertex.h"

struct triangle_t {
    float x1, y1, x2, y2, x3, y3;

    triangle_t(void) { ; }

    triangle_t(float x1, float y1, float x2, float y2, float x3, float y3) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
    }

};

triangle_t rotate(triangle_t tri, float a) {
    float sin_a = sinf(a);
    float cos_a = cosf(a);

    float tmp_x1 = tri.x1 * cos_a - tri.y1 * sin_a;
    float tmp_y1 = tri.x1 * sin_a + tri.y1 * cos_a;

    float tmp_x2 = tri.x2 * cos_a - tri.y2 * sin_a;
    float tmp_y2 = tri.x2 * sin_a + tri.y2 * cos_a;

    float tmp_x3 = tri.x3 * cos_a - tri.y3 * sin_a;
    float tmp_y3 = tri.x3 * sin_a + tri.y3 * cos_a;

    return {
        tmp_x1, tmp_y1, 
        tmp_x2, tmp_y2, 
        tmp_x3, tmp_y3
    };
}

triangle_t translate(triangle_t tri, float x, float y) {
    return {
        tri.x1 + x, tri.y1 + y,
        tri.x2 + x, tri.y2 + y,
        tri.x3 + x, tri.y3 + y
    };
}

triangle_t scale(triangle_t tri, float a) {
    return {
        tri.x1 * a, tri.y1 * a, 
        tri.x2 * a, tri.y2 * a, 
        tri.x3 * a, tri.y3 * a};
}

// draw three lines connecting each of the vertices
void draw_triangle(core_window_t& cw, triangle_t tri, int color) {
    draw_line(cw, {tri.x1, tri.y1, tri.x2, tri.y2}, color);
    draw_line(cw, {tri.x2, tri.y2, tri.x3, tri.y3}, color);
    draw_line(cw, {tri.x3, tri.y3, tri.x1, tri.y1}, color);
}

// surprise! filling a triangle is more involved than simply tracing it
void fill_triangle(core_window_t& win, triangle_t tri, int color) {

    // we only need the screen space coordinates
    tri.x1 = mapFloat(tri.x1, 0.0f, 1.0f, 0, win.num_columns());
    tri.y1 = mapFloat(tri.y1, 0.0f, 1.0f, 0, win.num_rows());
    tri.x2 = mapFloat(tri.x2, 0.0f, 1.0f, 0, win.num_columns());
    tri.y2 = mapFloat(tri.y2, 0.0f, 1.0f, 0, win.num_rows());
    tri.x3 = mapFloat(tri.x3, 0.0f, 1.0f, 0, win.num_columns());
    tri.y3 = mapFloat(tri.y3, 0.0f, 1.0f, 0, win.num_rows());

    // x_arr and y_arr are used to find the bounding box for the triangle being rendered
    float x_arr[3] = {tri.x1, tri.x2, tri.x3};
    if(x_arr[0] > x_arr[1]) { float t = x_arr[0]; x_arr[0] = x_arr[1]; x_arr[1] = t; }
    if(x_arr[1] > x_arr[2]) { float t = x_arr[1]; x_arr[1] = x_arr[2]; x_arr[2] = t; }
    if(x_arr[0] > x_arr[1]) { float t = x_arr[0]; x_arr[0] = x_arr[1]; x_arr[1] = t; }

    float y_arr[3] = {tri.y1, tri.y2, tri.y3};
    if(y_arr[0] > y_arr[1]) { float t = y_arr[0]; y_arr[0] = y_arr[1]; y_arr[1] = t; }
    if(y_arr[1] > y_arr[2]) { float t = y_arr[1]; y_arr[1] = y_arr[2]; y_arr[2] = t; }
    if(y_arr[0] > y_arr[1]) { float t = y_arr[0]; y_arr[0] = y_arr[1]; y_arr[1] = t; }

    // we now have a bounding box around the triangle we want 
    // to draw. use the barycentric algorithm to determine which 
    // points are inside the triangle. integer arithmetic tends 
    // to be faster than fp
    auto in_triangle = [](int_vertex_t& s, int_vertex_t& a, int_vertex_t& b, int_vertex_t& c) -> bool {
        // taken almost verbatim from StackOverflow
        int as_x = s.first - a.first;
        int as_y = s.second - a.second;
        bool s_ab = (b.first - a.first) * as_y - (b.second - a.second) * as_x > 0;
        
        if((c.first - a.first) * as_y - (c.second - a.second) * as_x > 0 == s_ab)
            return false;

        if((c.first - b.first) * (s.second - b.second) - (c.second - b.second) * (s.first - b.first) > 0 != s_ab)
            return false;

        return true;
    };

    int_vertex_t a{tri.x1, tri.y1};
    int_vertex_t b{tri.x2, tri.y2};
    int_vertex_t c{tri.x3, tri.y3};

    win.set_attribute(COLOR_PAIR(color));
    for(int j = y_arr[0]; j <= y_arr[2]; j++) {
        for(int i = x_arr[0]; i <= x_arr[2]; i++) {
            int_vertex_t v{i, j};

            if(in_triangle(v, a, b, c))
                win.draw_char_at(j, i, 'X'); // place on screen
        }
    }
    win.reset_attribute(COLOR_PAIR(color));

}