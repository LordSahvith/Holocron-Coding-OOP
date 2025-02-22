// Static Critter
// Demonstrates static member variables and functions

#include <iostream>

using namespace std;

class Critter
{
  public:
    static int s_Total; // static member variable declaration

    Critter(int hunger = 0);
    static int GetTotal(); // static member functin prototype

  private:
    int m_Hunger;
};

int Critter::s_Total = 0; // Static Member variable initialization

Critter::Critter(int hunger):
    m_Hunger(hunger)
{
    cout << "A new critter has been born!" << endl;
    ++s_Total;
}

int Critter::GetTotal() // Static member function definition
{
    return s_Total;
}

int main()
{
    cout << "The total number of critters is: " << Critter::s_Total << "\n\n";

    Critter Critter1, Critter2, Critter3;

    cout << "\nThe total number of critters is: " << Critter::s_Total << "\n\n";

    return 0;
}