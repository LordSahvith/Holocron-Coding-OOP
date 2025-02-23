// Deck Class

#include "Deck.h"
#include "Card.h"
#include "GenericPlayer.h"
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

Deck::Deck()
{
    Cards.reserve(52);
    Populate();
}

Deck::~Deck()
{
}

void Deck::Populate()
{
    Clear();

    // Create Standard Deck
    for (int suit = Card::CLUBS; suit <= Card::SPADES; ++suit)
    {
        for (int rank = Card::ACE; rank <= Card::KING; ++rank)
        {
            Add(new Card(static_cast<Card::rank>(rank), static_cast<Card::suit>(suit)));
        }
    }
}

void Deck::Shuffle()
{
    random_shuffle(Cards.begin(), Cards.end());
}

void Deck::Deal(Hand& hand)
{
    if (!Cards.empty())
    {
        hand.Add(Cards.back());
        Cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.";
    }
}

void Deck::AdditionalCards(GenericPlayer& genericPlayer)
{
    cout << endl;

    // continue to deal a card as long a genericPlayer isn't busted and wants another hit
    while (!(genericPlayer.IsBusted()) && genericPlayer.IsHitting())
    {
        Deal(genericPlayer);
        cout << genericPlayer << endl;

        if (genericPlayer.IsBusted())
        {
            genericPlayer.Bust();
        }
    }
}