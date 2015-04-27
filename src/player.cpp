#include "player.h"

int player::getCurrentBet()
{
    return currentBet;
}

int player::getChips()
{
    return chips;
}

void player::addChips(int chipsToAdd)
{
    chips += chipsToAdd;
}

void player::addCardToHand(card cta)
{
    playerHand.addCard(cta);
}

void player::clearHand()
{
    playerHand.clearHand();
}

std::string player::getHandString()
{
    return player::playerHand.toString();
}

int player::getHandValue()
{
    return playerHand.calculateHandValue();
}

bool player::hasBust()
{
    return playerHand.hasBust();
}

player::player(int chips)
{
    player::chips = chips;
}

player::~player()
{
    //dtor
}
