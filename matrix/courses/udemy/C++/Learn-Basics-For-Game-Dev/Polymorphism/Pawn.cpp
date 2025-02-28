#include <iostream>
#include "Pawn.h"

void Pawn::BeginPlay()
{
    std::cout << "Pawn BeginPlay() called. \n";
}

Pawn::~Pawn()
{
    std::cout << "Pawn Destructor called. \n";
}

void Pawn::PawnsMethod()
{
    std::cout << "Can't be called from a Base Class Pointer (ex. Object*). \n";
}