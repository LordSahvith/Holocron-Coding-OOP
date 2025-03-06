#include "Character.h"
#include "raymath.h"

Character::Character(int width, int height, float& scale)
{
    Texture = LoadTexture("characters/knight_idle_spritesheet.png");
    Idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Run = LoadTexture("characters/knight_run_spritesheet.png");
    SpriteWidth = Texture.width / SpriteCount;
    SpriteHeight = Texture.height;
    ScreenWidth = width;
    ScreenHeight = height;
    Scale = &scale;
    WorldPosition = Vector2{0.0f, 0.0f};
    WorldPositionLastFrame = WorldPosition;
}

void Character::Tick(float DeltaTime)
{
    HandleInput();

    BaseCharacter::Tick(DeltaTime);
}

Vector2 Character::GetScreenPosition() const
{
    return Vector2{ScreenWidth / 2.0f - (*Scale * 0.5f * SpriteWidth),
                   ScreenHeight / 2.0f - (*Scale * 0.5f * SpriteHeight)};
}

void Character::HandleInput()
{
    if (IsKeyDown(KEY_A))
    {
        Velocity.x -= 1.0f;
    }
    if (IsKeyDown(KEY_D))
    {
        Velocity.x += 1.0f;
    }
    if (IsKeyDown(KEY_W))
    {
        Velocity.y -= 1.0f;
    }
    if (IsKeyDown(KEY_S))
    {
        Velocity.y += 1.0f;
    }
}

int Character::GetScreenWidth() const
{
    return ScreenWidth;
}

int Character::GetScreenHeight() const
{
    return ScreenHeight;
}

float* Character::GetScale() const
{
    return Scale;
}
