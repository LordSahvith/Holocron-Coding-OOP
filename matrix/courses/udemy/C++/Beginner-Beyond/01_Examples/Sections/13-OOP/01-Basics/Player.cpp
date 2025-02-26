#include "Player.h"
#include <iostream>

Player::Player(std::string name, int health, int xp) : Name{name}, Health{health}, XP{xp}
{
}

Player::Player(const Player& source) : Player{source.Name, source.Health, source.XP}
{
    std::cout << "Copy Constructor - made copy of: " << source.Name << std::endl;
}

Player::~Player()
{
    std::cout << "Destructor called for " << Name << std::endl;
}

std::string Player::GetName()
{
    return Name;
}

int Player::GetHealth()
{
    return Health;
}

int Player::GetXP()
{
    return XP;
}