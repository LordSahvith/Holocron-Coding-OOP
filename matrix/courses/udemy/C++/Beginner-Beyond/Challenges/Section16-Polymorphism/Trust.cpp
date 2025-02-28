#include <iostream>
#include "Trust.h"

Trust::~Trust()
{
    std::cout << "Trust Destructor." << std::endl;
}

void Trust::withdraw(double amount)
{
    std::cout << "Trust Withdraw." << std::endl;
}

void Trust::deposit(double amount)
{
    std::cout << "Trust Deposit." << std::endl;
}

void Trust::print(std::ostream& os) const
{
    os << "Trust Display.";
}