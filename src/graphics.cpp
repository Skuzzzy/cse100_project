#include <curses.h>
#include <string>
#include <iostream>
#include <sstream>

#include "graphics.h"

using namespace std;

void screenStart()
{
    initscr();
}

string intToString(int i)
{
    stringstream ss;
	ss << i;
	return ss.str();
}

string getStringInput()
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

void refreshNcurses()
{
    refresh();
}

void pause()
{
    print("Press enter to continue" + string("\n"));
    cbreak();
    noecho();
    getch();
}

void clearNcurses()
{
    clear();
}

void print(string str)
{
    printw(str.c_str());;
    refresh();
}

void clrPrint(string str)
{
    clear();
    printw(str.c_str());;
    refresh();
}

void screenEnd()
{
    endwin();
}
