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

    // copy constructor
    Player(const Player& source);

    // destructor
    ~Player();

    std::string GetName();
    int GetHealth();
    int GetXP();

    void DisplayPlayer(Player p);
};
