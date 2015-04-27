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
	    ~graphics();
        string getStringInput();
    protected:
    private:
        
};

#endif // GRAPHICS_H
