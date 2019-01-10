#include <drawutils/drawutils.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    core_window_t cw;

    auto c = cw.get_char();

    if(c == KEY_F(1)) {
        cw.print_string("F1 pressed");
    }
    else {
        cw.print_string("Pressed key is ");
        //cw.set_bold();
        cw.set_attribute(A_BOLD);
        cw.print_char(c);
        cw.reset_attribute(A_BOLD);
        //cw.reset_bold();
    }

    cw.flip();
    cw.get_char();

    return 0;
}
