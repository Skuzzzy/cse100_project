#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <string>

class hand
{
    public:
        hand();
        virtual ~hand();

        void addCard(card cardToAdd);
        int calculateHandValue();

        void clearHand();

        bool hasBust();

        std::string toString();
    protected:
    private:
};

#endif // HAND_H
