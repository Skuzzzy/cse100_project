#include "human.h"
#include <iostream>

using namespace std;

human::human(int chips) : player(chips)
{
    //ctor
}

bool human::requestCard()
{
    cout << endl << getHandString() << endl;
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
