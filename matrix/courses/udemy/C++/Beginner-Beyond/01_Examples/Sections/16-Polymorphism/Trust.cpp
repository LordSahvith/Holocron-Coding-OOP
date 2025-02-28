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