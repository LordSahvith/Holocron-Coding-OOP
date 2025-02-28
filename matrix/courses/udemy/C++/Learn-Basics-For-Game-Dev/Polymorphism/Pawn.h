#pragma once

#include "Actor.h"

class Pawn : public Actor
{
  public:
    virtual void BeginPlay() override;

    virtual ~Pawn();

    void PawnsMethod();
};