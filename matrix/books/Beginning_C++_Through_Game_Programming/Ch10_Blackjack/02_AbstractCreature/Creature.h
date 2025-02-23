// Creature Abstract Class Header

class Creature // abstract class
{
  public:
    Creature(int health = 100);
    virtual void Greet() const = 0; // Pure virtual member function
    virtual void DisplayHealth() const;

  protected:
    int Health;
};