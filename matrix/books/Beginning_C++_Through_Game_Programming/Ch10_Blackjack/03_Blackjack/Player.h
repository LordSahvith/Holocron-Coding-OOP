// Player Class Header

#include "GenericPlayer.h"

class Player : public GenericPlayer
{
  public:
    Player(const string& name = "");
    virtual ~Player();

    // return whether or not the player want another hit
    virtual bool IsHitting() const;

    // announces that the player wins
    void Win() const;

    // announces that the player loses
    void Lose() const;

    // announces that he player pushes
    void Push() const;
};