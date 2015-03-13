#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class human : public player
{
    public:
        human(int chips);
        virtual ~human();

        bool requestCard();
        void requestBet();
    protected:
    private:
};

#endif // HUMAN_H
