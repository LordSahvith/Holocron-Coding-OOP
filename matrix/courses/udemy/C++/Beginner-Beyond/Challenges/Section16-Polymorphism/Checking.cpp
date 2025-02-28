#include <iostream>
#include "Checking.h"

Checking::~Checking()
{
    std::cout << "Checking Destructor." << std::endl;
}

void Checking::withdraw(double amount)
{
    std::cout << "Checking Withdraw." << std::endl;
}

void Checking::deposit(double amount)
{
    std::cout << "Checking Deposit." << std::endl;
}

void Checking::print(std::ostream& os) const
{
    os << "Checking Display.";
}