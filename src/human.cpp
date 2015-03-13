#include "human.h"
#include <iostream>

human::human(int chips) : player(chips)
{
    // Just using this to call parent constructor
}

bool human::requestCard()
{
    std::cout << "Another card?(1/0): ";
    int choice;
    std::cin >> choice;
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
    std::cout << "Place your bet: ";
    int choice;
    std::cin >> choice;
    currentBet = choice;
}

human::~human()
{
    //dtor
}
