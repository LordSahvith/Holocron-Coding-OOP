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