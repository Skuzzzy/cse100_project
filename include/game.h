#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "human.h"
#include "deck.h"
#include "graphics.h"

#include <vector>

class game
{
    public:
        game(int numHumanPlayers, int startingChips);

        virtual ~game();
    protected:
    private:
        player* dealer;
        deck blackjackDeck;
        std::vector<player*> playerList;

        void startGame();
        void dealCards();
        void getPlayerBets();
        void getPlayerDecisions();
        void getDealerDecision();
        void checkWins();
        bool checkContinue();
        void resetHands();
};

#endif // GAME_H
