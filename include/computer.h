#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class computer : public player
{
    public:
        computer(int chips);
        virtual ~computer();

        bool requestCard();
        void requestBet();
    protected:
    private:
};

#endif // COMPUTER_H
