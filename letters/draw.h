#pragma once

#include <drawutils/drawutils.h>
#include "alphabet.h"
#include <string>

#define LINE_DRAW_PREFIX void

LINE_DRAW_PREFIX draw_top(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y, x+0.05, y}, color); }
LINE_DRAW_PREFIX draw_bottom(core_window_t& win, float x, float y, int color) { draw_top(win, x, y+0.1f, color); }
LINE_DRAW_PREFIX draw_middle_left(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y+0.05f, x+0.025f, y+0.05f}, color); }
LINE_DRAW_PREFIX draw_middle_right(core_window_t& win, float x, float y, int color) { draw_line(win, {x+0.025, y+0.05f, x+0.05f, y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_far_left(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y, x, y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_mid_left(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y, x+0.025f, y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_middle(core_window_t& win, float x, float y, int color) { draw_line(win, {x+0.025f, y, x+0.025f, y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_mid_right(core_window_t& win, float x, float y, int color) { draw_line(win, {x+0.025, y, x, y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_far_right(core_window_t& win, float x, float y, int color) { draw_line(win, {x+0.025f, y, x+0.025f, y+0.05f}, color); }

void display_string(core_window_t& win, std::string str, float x, float y, int color) {
    float x_offset = 0.0f;
    
    for(char c : str) {
        std::initializer_list<int>& segments = letter_lut.at(c);

        for(int seg : segments) {
            switch(seg) {
                case l_top:
                    draw_top(win, x+x_offset, y, color); break;
                case l_bottom:
                    draw_bottom(win, x+x_offset, y, color); break;
                case l_middle_left:
                    draw_middle_left(win, x+x_offset, y, color); break;
                case l_middle_right:
                    draw_middle_right(win, x+x_offset, color); break;
                case l_upper_far_left:
                case l_upper_mid_left:
                case l_upper_middle:
                case l_upper_mid_right:
                case l_upper_far_right:
                case l_lower_far_left:
                case l_lower_mid_left:
                case l_lower_middle:
                case l_lower_mid_right:
                case l_lower_far_right:
                case l_all_middle:
                    draw_middle_left(win, x+x_offset, y, color);
                    draw_middle_right(win, x+x_offset, y, color);
                    break;
                case l_all_left:
                case l_all_right:
                case l_vertical_center:
                default:
                    exit(1);
            }
        }

        x_offset += 0.053f;
    }
}
