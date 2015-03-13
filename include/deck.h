#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class deck
{
    public:
        deck();
        virtual ~deck();

        card popCard();
    protected:
    private:
        void generateDeck();

        std::vector<card> cards;
};

#endif // DECK_H
