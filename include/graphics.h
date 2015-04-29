#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

using namespace std;

void screenStart();
void screenEnd();


void refreshNcurses();
void clearNcurses();
void print(string str);
void clrPrint(string str);
void pause();

string getStringInput();
string intToString(int i);

#endif // GRAPHICS_H
