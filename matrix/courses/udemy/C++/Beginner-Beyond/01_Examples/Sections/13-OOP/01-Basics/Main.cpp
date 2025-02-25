// Basic Classes and Objects

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
  public:
    // attributes
    string name;
    int health;
    int xp;

    // methods
    void Talk(string textToSay)
    {
        cout << name << " says " << textToSay << endl;
    }
    bool IsDead();
};

class Account
{
  public:
    // attributes
    string name;
    double balance;

    // methods
    bool Deposit(double bal)
    {
        balance += bal;
        cout << "Deposit" << endl;
        return true;
    }
    bool Withdraw(double bal)
    {
        balance -= bal;
        cout << "Withdraw" << endl;
        return true;
    }
};

int main()
{
    Player Savith;

    Savith.name = "Savith";
    Savith.health = 100;
    Savith.xp = 4;

    Player* Enemy = new Player;
    (*Enemy).name = "Enemy";
    (*Enemy).health = 100;
    Enemy->xp = 16;
    Enemy->Talk("I will destroy you!");

    Account SavithAccount;
    SavithAccount.name = "Savith's Account";
    SavithAccount.balance = 40000.00;

    SavithAccount.Deposit(1000.0);
    SavithAccount.Withdraw(400.0);

    return 0;
}