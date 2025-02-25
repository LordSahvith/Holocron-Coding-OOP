#include "Account.h"

std::string Account::GetName()
{
    return Name;
}

void Account::SetName(std::string name)
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
    return true;
}

bool Account::Withdraw(double amount)
{
    if (Balance - amount >= 0)
    {
        Balance -= amount;
        return true;
    }
    else
    {
        return false;
    }
}