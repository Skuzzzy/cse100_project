#include "human.h"
#include <iostream>

using namespace std;

human::human()
{
    // What...
}

human::human(int chips) : player(chips)
{
    // Just using this to call parent constructor
}

bool human::requestCard()
{
    cout << "Another card?(1/0): ";
    int choice;
    cin >> choice;
    if(choice == 1)
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
    cout << "Place your bet: ";
    int choice;
    cin >> choice;
    currentBet = choice;
}

human::~human()
{
    //dtor
}
