#include "deck.h"
#include "card.h"

#include <algorithm>
#include <vector>

// Create a shuffled deck
deck::deck()
{
    generateDeck();
}

void deck::generateDeck()
{

    // Fill deck with all 52 cards
    for(int i=0;i<card::NUMSUIT;i++)
    {
        for(int j=0;j<card::NUMVALUE;j++)
        {
            card c(i,j);
            cards.push_back(c);
        }
    }

    // Shuffle Deck
    std::srand(time(0));
    std::random_shuffle(cards.begin(), cards.end());
}

// Get a card from the top of the deck
card deck::popCard()
{
    if(cards.empty())
    {
        generateDeck(); // Regenerate deck if we run out of cards
    }
    card c = cards.back();
    cards.pop_back();
    return c;
}

deck::~deck()
{

}
