#include <iostream>
#include "card.h"
#include "hand.h"

using namespace std;

int main()
{
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

    return 0;
}
