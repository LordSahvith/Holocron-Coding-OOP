#pragma once

#include "raylib.h"

class Character
{
  public:
    Character(int screenWidth, int screenHeight, float scale);
    void Tick(float DeltaTime);

    Vector2 GetWorldPosition() const;
    Rectangle GetSource() const;
    Rectangle GetDestination() const;
    void HandleInput(Vector2& direction);
    void HandleAnimation(float& DeltaTime);

  private:
    Texture2D Texture;
    Texture2D Idle;
    Texture2D Run;
    Vector2 ScreenPosition;
    Vector2 WorldPosition;
    int ScreenWidth;
    int ScreenHeight;
    float Scale;
    float RightLeft{1.0f};
    float RunningTime{0.0f};
    int Frame{0};
    int MaxFrames{6};
    float UpdateTime{1.0f / 12.0f};
    float Speed{4.0f};
    float SpriteCount{6.0f};
    float SpriteWidth{0.0f};
    float SpriteHeight{0.0f};
};