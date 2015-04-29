#include "computer.h"
#include <iostream>

computer::computer(int chips) : player(chips)
{
    // Just using this to call parent constructor
}

bool computer::requestCard()
{
    if(getHandValue() > 11)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void computer::requestBet()
{
    currentBet = static_cast<int>(chips*0.2); // The Computer will always bet a certain portion of their chips
}

computer::~computer()
{
    //dtor
}
