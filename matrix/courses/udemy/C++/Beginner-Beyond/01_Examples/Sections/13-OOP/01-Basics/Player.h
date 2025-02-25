#pragma once

#include <string>

class Player
{
  private:
    // attributes
    std::string Name;
    int health;
    int xp;

  public:
    // methods
    void Talk(std::string textToSay)
    {
        std::cout << Name << " says " << textToSay << std::endl;
    }
    bool IsDead();
};
