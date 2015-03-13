#include "card.h"
#include <string>
#include <utility>


// Global definitions for card constants
// IN GLOBAL SCOPE
const int card::NUMSUIT = 4;
const int card::NUMVALUE = 14;

const std::string allsuits[card::NUMSUIT] = {"Hearts","Diamonds","Clubs","Spades"};
const std::pair <std::string,int> allvalues[card::NUMVALUE] =
    {
    std::make_pair(std::string("One"),1),
    std::make_pair(std::string("Two"),2),
    std::make_pair(std::string("Three"),3),
    std::make_pair(std::string("Four"),4),
    std::make_pair(std::string("Five"),5),
    std::make_pair(std::string("Six"),6),
    std::make_pair(std::string("Seven"),7),
    std::make_pair(std::string("Eight"),8),
    std::make_pair(std::string("Nine"),9),
    std::make_pair(std::string("Ten"),10),
    std::make_pair(std::string("Jack"),10),
    std::make_pair(std::string("Queen"),10),
    std::make_pair(std::string("King"),10),
    std::make_pair(std::string("Ace"),0) //Flag value for an Ace to be handled
    };

card::card(int suitIndex,int valueIndex)
{
    this -> suit = allsuits[suitIndex];
    this -> nameValue = allvalues[valueIndex].first;
    this -> value = allvalues[valueIndex].second;
}

int card::getValue()
{
    return this->value;
}

std::string card::toString()
{
    return nameValue + " of " + suit;
}

card::~card()
{
    //dtor
}
