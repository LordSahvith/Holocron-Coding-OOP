// Generic Player Class Header
#pragma once

#include "Hand.h"
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class GenericPlayer : public Hand
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer);

  public:
    GenericPlayer(const string& name = "");
    virtual ~GenericPlayer();

    // indicates whether or not generic player wnats to keep hitting
    virtual bool IsHitting() const = 0;

    // returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const;

    // announces that the generic player busts
    void Bust() const;

  protected:
    string Name;
};