#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

using namespace std;

class graphics
{
    public:
	    graphics();
	    void refreshNcurses();
        void clearNcurses();
        void print(string str);
        void clrPrint(string str);
        void pause();
	    ~graphics();
        string getStringInput();
        string intToString(int i);
    protected:
    private:
        
};

#endif // GRAPHICS_H
