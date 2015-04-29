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
    print("Another card?(N/y): ");
    string choice = getStringInput();
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
    print("Place your bet: ");
    string choice = getStringInput();
    
    stringstream ss(choice);

    int c;
    ss >> c;

    while(getChips() < c)
    {
        print("You bet too much, please bet no more than " + intToString(getChips()) + string(" chips.") + string("\n"));
        print("Place your bet: ");
        choice = getStringInput();
        print(choice);
        stringstream s(choice);
        ss >> c;
    }
    
    currentBet = c;
}

human::~human()
{
    //dtor
}
