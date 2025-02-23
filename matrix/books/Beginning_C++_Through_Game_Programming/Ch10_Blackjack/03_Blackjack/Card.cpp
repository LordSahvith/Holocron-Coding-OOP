// Card Class

#include "Card.h"

Card::Card(rank r, suit s, bool ifu)
{
    Rank = r;
    Suit = s;
    isFaceUp = ifu;
}

int Card::GetValue() const
{
    int value = 0;

    if (isFaceUp)
    {
        // value si number showing on card
        value = Rank;

        // value is 10 for face cards
        if (value > 10)
        {
            value = 10;
        }
    }

    return value;
}

void Card::Flip()
{
    isFaceUp = !isFaceUp;
}