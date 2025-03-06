#pragma once

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
  public:
    Character(int screenWidth, int screenHeight, float& scale);
    virtual void Tick(float DeltaTime) override;
    void HandleInput(Vector2& direction);
    int GetScreenWidth() const;
    int GetScreenHeight() const;
    float* GetScale() const;
};