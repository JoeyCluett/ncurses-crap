#include <drawutils/drawutils.h>
#include "player_tile.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void draw_grid_onscreen(core_window_t& win, int rows, int cols, int color);

int main(int argc, char* argv[]) {

    core_window_t cw;
    rectangle_t r{0.1f, 0.1f, 0.4f, 0.4f};
    vertex_t center_punch[8][8];

    const int rows = 40;
    const int columns = 90;

    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            center_punch[x][y] = {
                mapFloat(x, 0, 8, 0.0625f, 1.0625f),
                mapFloat(y, 0, 8, 0.0625f, 1.0625f)
            };
        }
    }

    draw_grid_onscreen(cw, rows, columns, core_color_blue);

    cw.flip();
    cw.get_char();

    return 0;
}

void draw_grid_onscreen(core_window_t& win, int rows, int cols, int color) {

    for(int x = 1; x < cols; x++) {
        float mapped_x = mapFloat(x, 0, cols, 0.0f, 1.0f);
        draw_line(win, {mapped_x, 0.0f, mapped_x, 1.0f}, color);
    }

    for(int y = 1; y < rows; y++) {
        float mapped_y = mapFloat(y, 0, rows, 0.0f, 1.0f);
        draw_line(win, {0.0f, mapped_y, 1.0f, mapped_y}, color);
    }
/*
    for(int i = 1; i < 8; i++) {
        float mapped_i = mapFloat(i, 0, 8, 0.0f, 1.0f);
        
        // horizontal line
        draw_line(win, {mapped_i, 0.0f, mapped_i, 1.0f}, color);
    
        // vertical line
        draw_line(win, {0.0f, mapped_i, 1.0f, mapped_i}, color);
    }
*/
}