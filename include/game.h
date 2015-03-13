#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "human.h"
#include "deck.h"

#include <vector>

class game
{
    public:
        game(int numHumanPlayers, int startingChips);

        virtual ~game();
    protected:
    private:
        human dealer;
        deck blackjackDeck;
        std::vector<human> playerList;

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
