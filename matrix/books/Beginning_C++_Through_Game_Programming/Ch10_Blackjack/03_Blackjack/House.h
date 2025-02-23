// House Class Header

#include "GenericPlayer.h"

class House : public GenericPlayer
{
  public:
    House(const string& name = "");
    virtual ~House();

    // indicates whther house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;

    // flips over first card
    void FlipFirstCard();
};