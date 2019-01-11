#include <drawutils/drawutils.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    core_window_t cw;

    draw_triangle(cw, {0.1, 0.1, 0.9, 0.1, 0.5, 0.9}, core_color_white);

    fill_rectangle(cw, {0.25, 0.25, 0.5, 0.5}, core_color_green);

    cw.flip();
    cw.get_char();

    return 0;
}
