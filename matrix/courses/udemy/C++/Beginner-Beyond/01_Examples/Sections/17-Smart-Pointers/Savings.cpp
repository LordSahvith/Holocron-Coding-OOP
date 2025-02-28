#include <iostream>
#include "Savings.h"

Savings::~Savings()
{
    std::cout << "Savings Destructor." << std::endl;
}

void Savings::withdraw(double amount)
{
    std::cout << "Savings Withdraw." << std::endl;
}

void Savings::deposit(double amount)
{
    std::cout << "Savings Deposit." << std::endl;
}

void Savings::print(std::ostream& os) const
{
    os << "Savings Display.";
}