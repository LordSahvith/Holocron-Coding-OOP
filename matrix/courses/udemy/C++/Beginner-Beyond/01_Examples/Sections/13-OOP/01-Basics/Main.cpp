// Declare Classes and Objects

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
    // attributes
    string name{"Player"};
    int health{0};
    int xp{3};

    // methods
    void Talk(string);
    bool IsDead();
};

class Account
{
    // attributes
    string name{"Account"};
    double balance{0};

    // methods
    bool Deposit(double);
    bool Withdraw(double);
};

int main()
{
    Player Savith;
    Player Hero;

    Player Players[]{Savith, Hero};

    vector<Player> PlayerVector{Savith};
    PlayerVector.push_back(Hero);

    Player* Enemy{nullptr};
    Enemy = new Player;
    delete Enemy;

    Account SavithAcount;
    Account HeroAcount;

    return 0;
}