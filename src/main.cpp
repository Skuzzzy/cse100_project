#include <iostream>
#include "card.h"
#include "hand.h"
#include "human.h"
#include "deck.h"
#include "game.h"

using namespace std;

int main()
{
    /*
    card a(3,3);
    card b(3,13);
    card c(3,10);

    cout << c.toString() << endl;

    hand h;
    h.addCard(a);

    h.addCard(b);
    h.addCard(c);

    cout << h.calculateHandValue() << endl;

    cout << h.toString() << endl;

    hand qwe;
    cout << "*" << qwe.toString() << "*" << endl;

    qwe.addCard(a);

    cout << "*" << h.toString() << "*" << endl;

    human asd(50);

    cout << asd.getChips();

    asd.addCardToHand(a);
    asd.addCardToHand(b);

    asd.requestCard();

    deck d;

    cout << d.popCard().toString() << endl;
    */

    game bjg(1,50);

    return 0;
}
