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
    void SetScreenPosition(int windowWidth, int windowHeight);
    void SetScreenWidth(int windowWidth);
    void SetScreenHeight(int windowHeight);
    void SetScale(float amount);
    void HandleInput(Vector2& direction);

  private:
    Texture2D Texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D Idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D Run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 ScreenPosition{0.0f, 0.0f};
    Vector2 WorldPosition{0.0f, 0.0f};
    int ScreenWidth{0};
    int ScreenHeight{0};
    float RightLeft{1.0f};
    float RunningTime{0.0f};
    int Frame{0};
    int MaxFrames{6};
    float UpdateTime{1.0f / 12.0f};
    float Speed{4.0f};
    float Scale{0.0f};
    float SpriteCount{6.0f};
    float SpriteWidth{0.0f};
    float SpriteHeight{0.0f};
};