#pragma once

#include "raylib.h"

class BaseCharacter
{
  public:
    BaseCharacter();
    Vector2 GetWorldPosition() const;
    Rectangle GetCollisionRec() const;
    Rectangle GetSource() const;
    void HandleAnimation(float& DeltaTime);
    void UndoMovement();

  protected:
    Texture2D Texture;
    Texture2D Idle;
    Texture2D Run;
    Vector2 ScreenPosition;
    Vector2 WorldPosition;
    Vector2 WorldPositionLastFrame;
    int ScreenWidth;
    int ScreenHeight;
    float* Scale;
    float SpriteWidth;
    float SpriteHeight;

    float RightLeft{1.0f};
    float RunningTime{0.0f};
    int Frame{0};
    int MaxFrames{6};
    float UpdateTime{1.0f / 12.0f};
    float Speed{4.0f};
    float SpriteCount{6.0f};
};