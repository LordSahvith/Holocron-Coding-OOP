// Player Class

#include "Player.h"
#include <iostream>

using std::cin;
using std::cout;

Player::Player(const string& name) : GenericPlayer(name)
{
}

Player::~Player()
{
}

bool Player::IsHitting() const
{
    cout << Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (toupper(response) == 'Y');
}

void Player::Win() const
{
    cout << Name << " wins!\n";
}

void Player::Lose() const
{
    cout << Name << " loses.\n";
}

void Player::Push() const
{
    cout << Name << " pushes.\n";
}