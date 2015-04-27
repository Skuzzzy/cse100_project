#include "graphics.h"
#include <curses.h>

graphics::graphics()
{
    initscr();
}

void graphics::refreshNcurses()
{
    printw("Hello World !!!");
    refresh();
}

graphics::~graphics()
{
    endwin();
}
