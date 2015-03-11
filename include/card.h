#ifndef CARD_H
#define CARD_H
#include <string>

class card
{
    public:
        static const int NUMSUIT;
        static const int NUMVALUE;

        card(int suitIndex,int valueIndex);

        int getValue();
        std::string toString();

        virtual ~card();
    protected:
    private:
        std::string suit;
        std::string nameValue;
        int value;
};

#endif // CARD_H
