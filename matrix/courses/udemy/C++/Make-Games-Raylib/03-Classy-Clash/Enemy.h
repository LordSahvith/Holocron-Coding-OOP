#pragma once

#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
  public:
    Enemy(Texture2D idleTexture, Texture2D runTexture, Vector2 position, float& scale);
    virtual void Tick(float DeltaTime) override;
};