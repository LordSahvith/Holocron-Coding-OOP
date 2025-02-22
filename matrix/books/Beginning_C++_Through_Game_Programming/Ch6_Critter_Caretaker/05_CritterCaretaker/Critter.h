#include <iostream>
#include <string>

using std::string;

class Critter
{
  public:
    Critter(string newName, int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    string GetName() const;
    void GetStats() const;

  private:
    string CritterName;
    int Hunger;
    int Boredom;

    int GetMood() const;
    void PassTime(int time = 1);
};
