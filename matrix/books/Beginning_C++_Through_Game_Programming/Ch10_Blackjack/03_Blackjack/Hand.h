// Hand Class Header
#pragma once

#include <vector>

using std::vector;

class Card;

class Hand
{
  public:
    Hand();
    virtual ~Hand();

    // ads a card to the hand
    void Add(Card* card);

    // clears had of all cards
    void Clear();

    // gets hand total value, intelligently treats aces as 1 or 11
    int GetTotal() const;

  protected:
    vector<Card*> Cards;
};