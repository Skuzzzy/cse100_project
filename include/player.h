#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include <string>

class player
{
    public:
        player();
        virtual ~player();

        virtual bool requestCard() = 0;
        virtual void requestBet() = 0;

        int getCurrentBet();
        int getChips();
        void addChips(int chipsToAdd);
        void addCardToHand(card cta);
        void clearHand();
        std::string getHandString();
        int getHandValue();
        bool hasBust();
    protected:
        hand playerHand;
        int currentBet;
        int chips;
    private:

};

#endif // PLAYER_H
