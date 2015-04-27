#include <curses.h>
#include <string>
#include <iostream>
#include <sstream>

#include "graphics.h"

using namespace std;

graphics::graphics()
{
    initscr();
}

string graphics::intToString(int i)
{
    stringstream ss;
	ss << i;
	return ss.str();
}

string graphics::getStringInput()
{
    string input;
    nocbreak();
    echo();
    int ichar = getch();
    while ( ichar != '\n' )
    {
        input.push_back(ichar);
        ichar = getch();
    }
    return input;
}

void graphics::refreshNcurses()
{
    refresh();
}

void graphics::pause()
{
    print("Press enter to continue" + string("\n"));
    cbreak();
    noecho();
    getch();
}

void graphics::clearNcurses()
{
    clear();
}

void graphics::print(string str)
{
    printw(str.c_str());;
    refresh();
}

void graphics::clrPrint(string str)
{
    clear();
    printw(str.c_str());;
    refresh();
}

graphics::~graphics()
{
    endwin();
}
