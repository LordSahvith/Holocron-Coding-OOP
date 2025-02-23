// Hand Class

#include "Card.h"
#include "Hand.h"

Hand::Hand()
{
    Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* card)
{
    Cards.push_back(card);
}

void Hand::Clear()
{
    // iterate through vector, freeing all memory on the heap
    vector<Card*>::iterator CardIterator = Cards.begin();
    for (CardIterator = Cards.begin(); CardIterator != Cards.end(); ++CardIterator)
    {
        delete *CardIterator;
        *CardIterator = 0;
    }

    // clear vector of pointers
    Cards.clear();
}

int Hand::GetTotal() const
{
    if (Cards.empty())
    {
        return 0;
    }

    // check for face down
    if (Cards[0]->GetValue() == 0)
    {
        return 0;
    }

    // add up card values, treat each ace as 1
    int total = 0;
    vector<Card*>::const_iterator CardIterator;
    for (CardIterator = Cards.begin(); CardIterator != Cards.end(); ++CardIterator)
    {
        total += (*CardIterator)->GetValue();
    }

    // determine if hand contains ace
    bool containsAce = false;
    for (CardIterator = Cards.begin(); CardIterator != Cards.end(); ++CardIterator)
    {
        if ((*CardIterator)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // if hand contains ace and total is low enough, treat ace as 11
    if (containsAce && total <= 11)
    {
        // add 10 since we already added 1
        total += 10;
    }

    return total;
}