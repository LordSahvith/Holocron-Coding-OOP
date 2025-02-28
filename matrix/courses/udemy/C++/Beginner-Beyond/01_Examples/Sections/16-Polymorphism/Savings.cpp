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