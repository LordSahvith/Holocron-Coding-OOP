// Constructor Critter
// Demonstrates constructors

#include <iostream>

using namespace std;

class Critter
{
  public:
    int m_Hunger;

    Critter(int hunger = 0); // Constructor
    void Greet();
};

Critter::Critter(int hunger)
{
    cout << "A new critter has been born!" << endl;
    m_Hunger = hunger;
}

void Critter::Greet()
{
    cout << "Hi, I'm a critter. My hunger level is: " << m_Hunger << endl;
}

int main()
{
    Critter critter1(7);
    critter1.Greet();

    return 0;
}