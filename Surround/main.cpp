#include <drawutils/drawutils.h>
#include <iostream>
#include <utility>
#include <unistd.h>

#define ROWS 15
#define COLUMNS 22

using namespace std;

// this draws the background needed for the game
void draw_game_board(core_window_t& win);

// pretty generic function for drawing a grid onscreen
void draw_grid_onscreen(core_window_t& win, int rows, int cols, int color);

int main(int argc, char* argv[]) {

    int input_char;

    

    {
        core_window_t win;



        // for now, the entirety of the game is 
        // moving a selector around the field    
        
        bool looping = true;
        while(looping) {
            // background
            draw_game_board(win);
        
            // GAME LOGIC

        
        }
        
        //draw_game_board(win);
        //win.flip();
        //win.get_char();
    }

    cout << input_char << endl;

    return 0;
}

void draw_game_board(core_window_t& win) {
    draw_grid_onscreen(win, ROWS, COLUMNS, core_color_white);
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

}
