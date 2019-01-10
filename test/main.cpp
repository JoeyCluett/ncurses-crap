#include <drawutils/drawutils.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    core_window_t cw;

    draw_triangle(cw, {0.1, 0.1, 0.9, 0.1, 0.5, 0.9}, core_color_white);

    cw.flip();
    cw.get_char();

    return 0;
}
