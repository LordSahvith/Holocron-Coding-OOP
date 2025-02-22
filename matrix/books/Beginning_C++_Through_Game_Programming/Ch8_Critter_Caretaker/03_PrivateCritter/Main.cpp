// Private Critter
// Demonstrates setting member access levels

#include <iostream>

using namespace std;

class Critter
{
  public:
    Critter(int hunger = 0);
    int GetHunger() const;
    void SetHunger(int hunger);

  private:
    int m_Hunger;
};

Critter::Critter(int hunger)
{
    cout << "A new critter has been born!" << endl;
    m_Hunger = hunger;
}

int Critter::GetHunger() const
{
    return m_Hunger;
}

void Critter::SetHunger(int hunger)
{
    if (hunger < 0)
    {
        cout << "You can't set a critter's hunger to a negative number.\n\n";
    }
    else
    {
        m_Hunger = hunger;
    }
}

int main()
{
    Critter Critter1(4);
    // cout << Critter1.m_hunger; // illegal, m_hunger is private
    cout << "Calling GetHunger(): " << Critter1.GetHunger() << "\n\n";

    cout << "Calling SetHunger(-1).\n";
    Critter1.SetHunger(-1);

    cout << "Calling SetHunger(9).\n";
    Critter1.SetHunger(9);

    cout << "Calling GetHunger(): " << Critter1.GetHunger() << "\n\n";

    return 0;
}