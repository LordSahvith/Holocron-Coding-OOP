#pragma once

#include <string>

class Player
{
  private:
    // attributes
    std::string Name;
    int Health;
    int XP;

    static int PlayerCount;

  public:
    // methods
    Player(std::string name = "None", int health = 100, int xp = 0);

    // copy constructor
    Player(const Player& source);

    // destructor
    ~Player();

    std::string GetName() const;
    int GetHealth();
    int GetXP();

    static int GetPlayerCount(); // belongs to class, not instances
};
