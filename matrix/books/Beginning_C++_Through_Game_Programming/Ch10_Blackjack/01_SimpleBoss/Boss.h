// Boss Class Header

#include "Enemy.h"

class Boss : public Enemy
{
  public:
    Boss();
    int DamageMultiplier;
    void SpecialAttack() const;
};