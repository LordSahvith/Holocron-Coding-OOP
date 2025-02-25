#include "Player.h"

Player::Player() : Name{"None"}, Health{100}, XP{0}
{
}

Player::Player(std::string name) : Name{name}, Health{100}, XP{0}
{
}

Player::Player(std::string name, int health, int xp) : Name{name}, Health{health}, XP{xp}
{
}