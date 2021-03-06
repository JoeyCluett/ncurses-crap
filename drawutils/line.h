#pragma once

#include <iostream>
#include "core.h"

// should be pretty self-explanatory
struct line_t {
    float x1, y1, x2, y2;

    line_t(void) { ; }

    line_t(float x1, float y1, float x2, float y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

std::ostream& operator<<(std::ostream& os, line_t l) {
    os << "line_t[ x1: " << l.x1 << ", y1: " << l.y1 
    << ", x2: " << l.x2 << ", y2: " << l.y2 << " ]";
    return os;
}

line_t rotate(line_t l, float a) {
    float sin_a = sinf(a);
    float cos_a = cosf(a);

    float tmp_x1 = l.x1 * cos_a - l.y1 * sin_a;
    float tmp_y1 = l.x1 * sin_a + l.y1 * cos_a;

    float tmp_x2 = l.x2 * cos_a - l.y2 * sin_a;
    float tmp_y2 = l.x2 * sin_a + l.y2 * cos_a;

    return {
        tmp_x1, tmp_y1, 
        tmp_x2, tmp_y2
    };
}

line_t translate(line_t l, float x, float y) {
    return {
        l.x1 + x, l.y1 + y, 
        l.x2 + x, l.y2 + y
    };
}

line_t scale(line_t l, float s) {
    return {
        l.x1 * s, l.y1 * s, 
        l.x2 * s, l.y2 * s
    };
}

// function for drawing straight lines
void draw_line(core_window_t& win, line_t l, int color) {
    // ready to draw in color
    win.set_attribute(COLOR_PAIR(color));

    if(l.x1 == l.x2) {
        // line is straight up and down
        int x = (int)mapFloat(l.x1, 0.0f, 1.0f, 0, win.num_columns());

        int start_y = (int)mapFloat((l.y1 < l.y2) ? l.y1 : l.y2, 0.0f, 1.0f, 0, win.num_rows());
        int end_y   = (int)mapFloat((l.y1 > l.y2) ? l.y1 : l.y2, 0.0f, 1.0f, 0, win.num_rows());
    
        for(int i = start_y; i <= end_y; i++)
            win.draw_char_at(i, x, 'X');

        win.reset_attribute(COLOR_PAIR(color));
        return;
    }
    else if(l.y1 == l.y2) {
        // line is straight across
        int y = (int)mapFloat(l.y1, 0.0f, 1.0f, 0, win.num_rows());

        // find the range onscreen where this line lies
        int start_x = (int)mapFloat((l.x1 < l.x2) ? l.x1 : l.x2, 0.0f, 1.0f, 0, win.num_columns());
        int end_x   = (int)mapFloat((l.x1 > l.x2) ? l.x1 : l.x2, 0.0f, 1.0f, 0, win.num_columns());

        for(int i = start_x; i <= end_x; i++)
            win.draw_char_at(y, i, 'X');

        win.reset_attribute(COLOR_PAIR(color));
        return;
    }


    float slope = (l.y1 - l.y2) / (l.x1 - l.x2);
    float y_intercept = l.y1 - (slope * l.x1);

    if(slope <= 2.0f) {
        // function of x : y = f(x)
        
        // find the range onscreen where this line lies
        int start_x = (int)mapFloat((l.x1 < l.x2) ? l.x1 : l.x2, 0.0f, 1.0f, 0, win.num_columns());
        int end_x   = (int)mapFloat((l.x1 > l.x2) ? l.x1 : l.x2, 0.0f, 1.0f, 0, win.num_columns());

        for(int i = start_x; i <= end_x; i++) {
            // map the input back into the function
            float in = mapFloat(i, 0, win.num_columns(), 0.0f, 1.0f);
            
            // y = mx + b
            float out = (slope * in) + y_intercept;

            // map the output back to screen coordinates
            int y = (int)mapFloat(out, 0.0f, 1.0f, 0, win.num_rows());
            win.draw_char_at(y, i, 'X');

        }

    }
    else {
        // function of y : x = f(y)

        // onscreen range of y values
        int start_y = (int)mapFloat((l.y1 < l.y2) ? l.y1 : l.y2, 0.0f, 1.0f, 0, win.num_rows());
        int end_y   = (int)mapFloat((l.y1 > l.y2) ? l.y1 : l.y2, 0.0f, 1.0f, 0, win.num_rows());
    
        for(int i = start_y; i <= end_y; i++) {
            float in = mapFloat(i, 0, win.num_rows(), 0.0f, 1.0f);

            // x = (y - b) / m
            float out = (in - y_intercept) / slope;

            int x = (int)mapFloat(out, 0.0f, 1.0f, 0, win.num_columns());
            win.draw_char_at(i, x, 'X');
        }
    }

    win.reset_attribute(COLOR_PAIR(color));
    return;
}

