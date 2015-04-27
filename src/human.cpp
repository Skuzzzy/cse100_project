#include "human.h"

#include <iostream>
#include "graphics.h"
#include <string>
#include <sstream>

using namespace std;

human::human(int chips) : player(chips)
{
    // Just using this to call parent constructor
}

bool human::requestCard()
{
    graphics g;
    g.print("Another card?(N/y): ");
    string choice = g.getStringInput();
    if(choice == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void human::requestBet()
{
    graphics g;
    g.print("Place your bet: ");
    string choice = g.getStringInput();
    
    stringstream ss(choice);

    int c;
    ss >> c;

    while(getChips() < c)
    {
        g.print("You bet too much, please bet no more than " + g.intToString(getChips()) + string(" chips.") + string("\n"));
        g.print("Place your bet: ");
        choice = g.getStringInput();
        g.print(choice);
        stringstream s(choice);
        ss >> c;
    }
    
    currentBet = c;
}

human::~human()
{
    //dtor
}
