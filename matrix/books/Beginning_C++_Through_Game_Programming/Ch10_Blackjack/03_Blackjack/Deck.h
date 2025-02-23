// Deck Class Header

#include "Hand.h"

class GenericPlayer;

class Deck : public Hand
{
  public:
    Deck();
    virtual ~Deck();

    // Create a standard deck of 52 cards
    void Populate();

    // Shuffle Cards
    void Shuffle();

    // Deal one card to hand
    void Deal(Hand& hand);

    // Give additional cards to a GenericPlayer
    void AdditionalCards(GenericPlayer& genericPlayer);
};