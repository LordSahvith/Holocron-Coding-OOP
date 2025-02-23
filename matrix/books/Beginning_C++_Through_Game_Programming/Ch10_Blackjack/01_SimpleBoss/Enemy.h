// Enemy Class Header

class Enemy
{
  public:
    Enemy(int damage = 10);
    void virtual Taunt() const;
    void virtual Attack() const;

  protected:
    int Damage;
};