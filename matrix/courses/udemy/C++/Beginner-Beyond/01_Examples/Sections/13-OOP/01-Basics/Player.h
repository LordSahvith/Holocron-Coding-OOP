#pragma once

#include <string>

class Player
{
  private:
    // attributes
    std::string Name;
    int Health;
    int XP;

  public:
    // methods
    Player(std::string name = "None", int health = 100, int xp = 0);
};
