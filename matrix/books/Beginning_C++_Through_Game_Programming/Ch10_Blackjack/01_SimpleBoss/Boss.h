// Boss Class Header

#include "Enemy.h"

class Boss : public Enemy
{
  public:
    Boss(int damage = 30, int damageMultiplier = 3);
    virtual ~Boss();
    void virtual Taunt() const;
    void virtual Attack() const;
    void SpecialAttack() const;

  private:
    int* DamageMultiplier;
};