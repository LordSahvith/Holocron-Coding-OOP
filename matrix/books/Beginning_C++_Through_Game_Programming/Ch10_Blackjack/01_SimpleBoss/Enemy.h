// Enemy Class Header

class Enemy
{
  public:
    Enemy(int damage = 10);
    virtual ~Enemy();
    void virtual Taunt() const;
    void virtual Attack() const;

  protected:
    int* Damage;
};