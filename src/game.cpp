#include <iostream>

#include "game.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "graphics.h"

using namespace std;

game::game(int numHumanPlayers, int startingChips)
{
    //g.getStringInput();

    g.print("Chips\n");
    g.clrPrint("Chips");

    dealer = new computer(-1);

    for(int i=0; i<numHumanPlayers; i++)
    {
        playerList.push_back(new human(startingChips));
    }

    startGame();
}

void game::startGame()
{
    bool continueGame = true;
    while(continueGame) // Main game loop
    {
        // Everyone gets two cards at the start
        dealCards();

        // Get player bets
        getPlayerBets();

        // Get player decision regarding hitting or staying
        getPlayerDecisions();

        // Get dealer decision on hitting or staying
        getDealerDecision();

        // Now see if each player won and distribute earnings
        checkWins();

        // Checking game loop
        continueGame = checkContinue();

        // Clean up for next round
        resetHands();
    }
}

void game::dealCards()
{
    g.clrPrint("Dealing cards\n");
    (*dealer).addCardToHand(blackjackDeck.popCard());
    (*dealer).addCardToHand(blackjackDeck.popCard());
    for(int i =0; i<static_cast<int>(playerList.size()); i++)
    {
        (*playerList[i]).addCardToHand(blackjackDeck.popCard());
        (*playerList[i]).addCardToHand(blackjackDeck.popCard());
    }
    g.print("Cards have been dealt\n");
}

void game::getPlayerBets()
{
    g.clrPrint("Place your bets!\n");
    for(int i =0; i<static_cast<int>(playerList.size()); i++)
    {
        g.print("Your hand: " + (*playerList[i]).getHandString() + string("\n"));
        (*playerList[i]).requestBet();
        g.print("You bet " + (*playerList[i]).getCurrentBet() + string("\n"));
    }
}

void game::getPlayerDecisions()
{
    for(int i =0; i<static_cast<int>(playerList.size()); i++)
    {
        g.print(string("\n") + "Your hand: " + (*playerList[i]).getHandString() + string("\n"));
        bool hit = (*playerList[i]).requestCard();
        while(hit == true)
        {
            (*playerList[i]).addCardToHand(blackjackDeck.popCard());
            g.print("Your hand: " + (*playerList[i]).getHandString() + string("\n"));
            hit = (*playerList[i]).requestCard();
        }
        g.print("Player decision complete" + string("\n\n"));
    }
}

void game::getDealerDecision()
{
    g.print("Dealers hand: " + (*dealer).getHandString() + "\n");
    bool hit = (*dealer).requestCard();
    while(hit == true)
    {
        (*dealer).addCardToHand(blackjackDeck.popCard());
        g.print("Dealers hand: " + (*dealer).getHandString() + "\n");
        hit = (*dealer).requestCard();
    }
    g.print("Dealer decision complete" + string("\n\n"));
}

void game::checkWins()
{
    int dealerHandValue = (*dealer).getHandValue();

    for(int i =0; i<static_cast<int>(playerList.size()); i++)
    {
        int playerHandValue = (*playerList[i]).getHandValue();
        if(playerHandValue > 21 || ((dealerHandValue > playerHandValue) && dealerHandValue <= 21))
        {
            //Player loses
            (*playerList[i]).addChips((-1)*((*playerList[i]).getCurrentBet()));
            g.print("You bet: " + (*playerList[i]).getCurrentBet() + string("\n"));
            g.print("You lost! your current chip total is: " + (*playerList[i]).getChips() + string("\n"));
        }
        else
        {
            // Player wins
            (*playerList[i]).addChips((*playerList[i]).getCurrentBet());
            g.print("You bet: " + (*playerList[i]).getCurrentBet() + string("\n"));
            g.print("You won! your current chip total is: " + (*playerList[i]).getChips() + string("\n"));
        }
    }
}

bool game::checkContinue()
{
    g.print("Play another round? 1/0: ");
    int decision;
    cin >> decision;
    if(decision == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void game::resetHands()
{
    for(int i =0; i<static_cast<int>(playerList.size()); i++)
    {
        (*playerList[i]).clearHand();
    }

    (*dealer).clearHand();
}

game::~game()
{

}
