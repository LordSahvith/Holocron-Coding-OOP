// Basic Classes and Objects

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
  private:
    // attributes
    string Name;
    int health;
    int xp;

  public:
    // methods
    void Talk(string textToSay)
    {
        cout << Name << " says " << textToSay << endl;
    }
    bool IsDead();
};

class Account
{
  private:
    // attributes
    string Name;
    double Balance;

  public:
    // methods
    string GetName();
    void SetName(string name);
    void SetBalance(double amount);
    bool Deposit(double amount);
    bool Withdraw(double amount);
};

string Account::GetName()
{
    return Name;
}

void Account::SetName(string name)
{
    Name = name;
}

void Account::SetBalance(double amount)
{
    Balance = amount;
}

bool Account::Deposit(double amount)
{
    Balance += amount;
    cout << "Deposit" << endl;
    return true;
}

bool Account::Withdraw(double amount)
{
    if (Balance - amount >= 0)
    {
        Balance -= amount;
        cout << "Withdraw" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Account SavithAccount;
    SavithAccount.SetName("Savith");
    SavithAccount.SetBalance(1000.0);

    if (SavithAccount.Deposit(200.0))
    {
        cout << "Deposit OK." << endl;
    }
    else
    {
        cout << "Deposit error." << endl;
    }

    if (SavithAccount.Withdraw(500.0))
    {
        cout << "Withdrawl OK." << endl;
    }
    else
    {
        cout << "Insuffient funds." << endl;
    }

    if (SavithAccount.Withdraw(1500.0))
    {
        cout << "Withdrawl OK." << endl;
    }
    else
    {
        cout << "Insuffient funds." << endl;
    }

    return 0;
}