#include "hand.h"
#include <vector>
#include "card.h"

std::vector<card> cards;

hand::hand()
{
    cards.reserve(12); // At 12 cards the player will always bust
}

void hand::addCard(card cardToAdd)
{
    cards.push_back(cardToAdd);
}

void hand::clearHand()
{
    cards.clear();
}

int hand::calculateHandValue()
{
    int value = 0;
    int aceCount = 0;

    for(int i =0; i<cards.size(); i++)
    {
        value += cards[i].getValue();

        if(cards[i].getValue() == 0)
        {
            aceCount++;
        }
    }

    //Handle aces
    if(aceCount > 0)
    {
        int diff = 21 - value;
        if(diff < 11) //If one ace considered 11 will make the hand go over, they must all be 1 valued
        {
            value += (aceCount*1);
        }
        else if(diff >= 11)
        {
            if(aceCount == 1)
            {
                value += (aceCount*11);
            }
            else
            {
                value += (11)+((aceCount-1)*1);
            }
        }
    }
    return value;
}

bool hand::hasBust()
{
    return (calculateHandValue()>21);
}

std::string hand::toString()
{
    std::string handString;
    for(int i =0; i<cards.size(); i++)
    {
        handString.append("[" + cards[i].toString() + "]");
    }
    return handString;
}

hand::~hand()
{
    //dtor
}
