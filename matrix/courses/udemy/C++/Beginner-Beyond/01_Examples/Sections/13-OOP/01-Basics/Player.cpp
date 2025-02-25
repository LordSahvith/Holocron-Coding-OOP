#include "Player.h"

Player::Player() : Player{"None", 100, 0}
{
}

Player::Player(std::string name) : Player{name, 100, 0}
{
}

Player::Player(std::string name, int health, int xp) : Name{name}, Health{health}, XP{xp}
{
}