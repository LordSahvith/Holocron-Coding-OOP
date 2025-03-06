#pragma once

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
  public:
    Character(int screenWidth, int screenHeight, float& scale);
    virtual void Tick(float DeltaTime) override;
    virtual Vector2 GetScreenPosition() const override;
    void HandleInput();
    int GetScreenWidth() const;
    int GetScreenHeight() const;
    float* GetScale() const;
};