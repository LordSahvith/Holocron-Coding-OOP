// House Class

#include "Card.h"
#include "House.h"
#include <iostream>

using std::cout;

House::House(const string& name) : GenericPlayer(name)
{
}

House::~House()
{
}

bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
    if (!(Cards.empty()))
    {
        Cards[0]->Flip();
    }
    else
    {
        cout << "No card to flip.\n";
    }
}