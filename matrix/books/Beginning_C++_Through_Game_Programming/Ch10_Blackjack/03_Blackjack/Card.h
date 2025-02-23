// Card Class Header
#pragma once

#include <iostream>

using std::ostream;

class Card
{
  public:
    enum rank
    {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

    enum suit
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };

    // overloading << operator so can send Card object to standard output
    friend ostream& operator<<(ostream& os, const Card& card);

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);

    // returns the value of card, 1-11
    int GetValue() const;

    // Flips a card; if face up, becomes face down and vice versa
    void Flip();

  private:
    rank Rank;
    suit Suit;
    bool isFaceUp;
};