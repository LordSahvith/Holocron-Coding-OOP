#include "Player.h"
#include <iostream>

int Player::PlayerCount = 0;

Player::Player(std::string name, int health, int xp) : Name{name}, Health{health}, XP{xp}
{
    ++PlayerCount;
}

Player::Player(const Player& source) : Player{source.Name, source.Health, source.XP}
{
}

Player::~Player()
{
    --PlayerCount;
}

std::string Player::GetName() const
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

int Player::GetPlayerCount()
{
    return PlayerCount;
}