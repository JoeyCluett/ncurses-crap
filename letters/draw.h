#pragma once

#include <drawutils/drawutils.h>
#include "alphabet.h"
#include <string>

#define LINE_DRAW_PREFIX void

static const float x_scale = 0.6f;

namespace letter {

LINE_DRAW_PREFIX draw_top(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y, x+(0.05f * x_scale), y}, color); }
LINE_DRAW_PREFIX draw_bottom(core_window_t& win, float x, float y, int color) { draw_top(win, x, y+0.1f, color); }
LINE_DRAW_PREFIX draw_middle_left(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y+0.05f, x+(0.025f * x_scale), y+0.05f}, color); }
LINE_DRAW_PREFIX draw_middle_right(core_window_t& win, float x, float y, int color) { draw_line(win, {x+(0.025f * x_scale), y+0.05f, x+(0.05f * x_scale), y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_far_left(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y, x, y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_mid_left(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y, x+(0.025f * x_scale), y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_middle(core_window_t& win, float x, float y, int color) { draw_line(win, {x+(0.025f * x_scale), y, x+(0.025f * x_scale), y+0.05f}, color); }
LINE_DRAW_PREFIX draw_upper_mid_right(core_window_t& win, float x, float y, int color) { draw_line(win, {x+(0.025f * x_scale), y+0.05f, x+(0.05f * x_scale), y}, color); }
LINE_DRAW_PREFIX draw_upper_far_right(core_window_t& win, float x, float y, int color) { draw_line(win, {x+(0.05f * x_scale), y, x+(0.05f * x_scale), y+0.05f}, color); }
LINE_DRAW_PREFIX draw_lower_far_left(core_window_t& win, float x, float y, int color) { draw_line(win, {x, y+0.05f, x, y+0.1f}, color); }
LINE_DRAW_PREFIX draw_lower_mid_left(core_window_t& win, float x, float y, int color) { draw_line(win, {x+(0.025f * x_scale), y+0.05f, x, y+0.1f}, color); }
LINE_DRAW_PREFIX draw_lower_middle(core_window_t& win, float x, float y, int color) { draw_line(win, {x+(0.025f * x_scale), y+0.05f, x+(0.025f * x_scale), y+0.1f}, color); }
LINE_DRAW_PREFIX draw_lower_mid_right(core_window_t& win, float x, float y, int color) { draw_line(win, {x+(0.025f * x_scale), y+0.05f, x+(0.05f * x_scale), y+0.1f}, color); }
LINE_DRAW_PREFIX draw_lower_far_right(core_window_t& win, float x, float y, int color) { draw_line(win, {x+(0.05f * x_scale), y+0.05f, x+(0.05f * x_scale), y+0.1f}, color); }

void display_string(core_window_t& win, std::string str, float x, float y, int color) {
    float x_offset = 0.0f;
    
    for(char c : str) {
        const std::initializer_list<const int>& segments = letter_lut.at(c);

        for(int seg : segments) {
            switch(seg) {
                case l_top:    draw_top(win, x+x_offset, y, color); break;
                case l_bottom: draw_bottom(win, x+x_offset, y, color); break;
                case l_middle_left: draw_middle_left(win, x+x_offset, y, color); break;
                case l_middle_right: draw_middle_right(win, x+x_offset, y, color); break;
                case l_upper_far_left: draw_upper_far_left(win, x+x_offset, y, color); break;
                case l_upper_mid_left: draw_upper_mid_left(win, x+x_offset, y, color); break;
                case l_upper_middle: draw_upper_middle(win, x+x_offset, y, color); break;
                case l_upper_mid_right: draw_upper_mid_right(win, x+x_offset, y, color); break;
                case l_upper_far_right: draw_upper_far_right(win, x+x_offset, y, color); break;
                case l_lower_far_left: draw_lower_far_left(win, x+x_offset, y, color); break;
                case l_lower_mid_left: draw_lower_mid_left(win, x+x_offset, y, color); break;
                case l_lower_middle: draw_lower_middle(win, x+x_offset, y, color); break;
                case l_lower_mid_right: draw_lower_mid_right(win, x+x_offset, y, color); break;
                case l_lower_far_right: draw_lower_far_right(win, x+x_offset, y, color); break;
                case l_all_middle:
                    draw_middle_left(win, x+x_offset, y, color);
                    draw_middle_right(win, x+x_offset, y, color);
                    break;
                case l_all_left:
                    draw_upper_far_left(win, x+x_offset, y, color);
                    draw_lower_far_left(win, x+x_offset, y, color);
                    break;
                case l_all_right:
                    draw_upper_far_right(win, x+x_offset, y, color);
                    draw_lower_far_right(win, x+x_offset, y, color);
                    break;
                case l_vertical_center:
                    draw_upper_middle(win, x+x_offset, y, color);
                    draw_lower_middle(win, x+x_offset, y, color);
                    break;
                default:
                    exit(1);
            }
        }

        x_offset += 0.045f;
    }
}

} // end of namespace letter