#pragma once

#include "raylib.h"

class Enemy
{
  public:
    Enemy(Texture2D idleTexture, Texture2D runTexture, Vector2 position, float& scale);
    void Tick(float DeltaTime);
    Vector2 GetWorldPosition() const;
    void HandleAnimation(float& DeltaTime);
    Rectangle GetCollisionRec() const;
    Rectangle GetSource() const;
    void UndoMovement();

    // void HandleInput(Vector2& direction);
    // int GetScreenWidth() const;
    // int GetScreenHeight() const;
    // float* GetScale() const;

  private:
    Texture2D Texture;
    Texture2D Idle;
    Texture2D Run;
    Vector2 ScreenPosition;
    Vector2 WorldPosition;
    Vector2 WorldPositionLastFrame;
    int ScreenWidth;
    int ScreenHeight;
    float* Scale;
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