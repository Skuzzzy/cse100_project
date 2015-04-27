#include <iostream>

#include "game.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "graphics.h"

using namespace std;

game::game(int numHumanPlayers, int startingChips)
{
    graphics g;
    
    //g.getStringInput();
    //g.refreshNcurses();
    //g.clearNcurses();
    //g.print("Chips");

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
    cout << "Dealing cards" << endl;
    (*dealer).addCardToHand(blackjackDeck.popCard());
    (*dealer).addCardToHand(blackjackDeck.popCard());
    for(int i =0; i<static_cast<int>(playerList.size()); i++)
    {
        (*playerList[i]).addCardToHand(blackjackDeck.popCard());
        (*playerList[i]).addCardToHand(blackjackDeck.popCard());
    }
    cout << "Cards have been dealt" << endl;
}

void game::getPlayerBets()
{
    cout << "Place your bets!" << endl;
    for(int i =0; i<static_cast<int>(playerList.size()); i++)
    {
        cout << "Your hand: " << (*playerList[i]).getHandString() << endl;
        (*playerList[i]).requestBet();
        cout << "You bet " << (*playerList[i]).getCurrentBet() << endl;
    }
}

void game::getPlayerDecisions()
{
    for(int i =0; i<static_cast<int>(playerList.size()); i++)
    {
        cout << endl << "Your hand: " + (*playerList[i]).getHandString() << endl;
        bool hit = (*playerList[i]).requestCard();
        while(hit == true)
        {
            (*playerList[i]).addCardToHand(blackjackDeck.popCard());
            cout << "Your hand: " + (*playerList[i]).getHandString() << endl;
            hit = (*playerList[i]).requestCard();
        }
        cout << "Player decision complete" << endl << endl;
    }
}

void game::getDealerDecision()
{
    cout << "Dealers hand: " + (*dealer).getHandString() << endl;
    bool hit = (*dealer).requestCard();
    while(hit == true)
    {
        (*dealer).addCardToHand(blackjackDeck.popCard());
        cout << "Dealers hand: " + (*dealer).getHandString() << endl;
        hit = (*dealer).requestCard();
    }
    cout << "Dealer decision complete" << endl << endl;
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
            cout << "You bet: " << (*playerList[i]).getCurrentBet() << endl;
            cout << "You lost! your current chip total is: " << (*playerList[i]).getChips() << endl;
        }
        else
        {
            // Player wins
            (*playerList[i]).addChips((*playerList[i]).getCurrentBet());
            cout << "You bet: " << (*playerList[i]).getCurrentBet() << endl;
            cout << "You won! your current chip total is: " << (*playerList[i]).getChips() << endl;
        }
    }
}

bool game::checkContinue()
{
    cout << "Play another round? 1/0: ";
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
