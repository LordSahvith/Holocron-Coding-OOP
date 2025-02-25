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
    Player();
    Player(std::string name);
    Player(std::string name, int health, int xp);
};
