// Simple Critter
// Demonstrates creating a new type (class)

#include <iostream>

using namespace std;

class Critter // class Definition - defines a new type, Critter
{
  public:
    int m_Hunger; // data member
    void Greet(); // member function prototype
};

void Critter::Greet() // member function definition
{
    cout << "Hi, I'm a critter. My hunger level is: " << m_Hunger << endl;
}

int main()
{
    Critter critter1;
    Critter critter2;

    critter1.m_Hunger = 9;
    cout << "critter1's hunger level is: " << critter1.m_Hunger << endl;

    critter2.m_Hunger = 3;
    cout << "critter2's hunger level is: " << critter2.m_Hunger << endl;

    critter1.Greet();
    critter2.Greet();

    return 0;
}