#pragma once

#include "raylib.h"
#include "BaseCharacter.h"

class Character;

class Enemy : public BaseCharacter
{
  public:
    Enemy(Texture2D idleTexture, Texture2D runTexture, Vector2 position, float& scale);
    virtual void Tick(float DeltaTime) override;
    virtual Vector2 GetScreenPosition() const override;
    void SetTarget(Character* character);

    private:
      Character* Target;
};