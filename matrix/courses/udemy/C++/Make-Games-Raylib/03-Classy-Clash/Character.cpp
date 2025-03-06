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
    ScreenPosition = Vector2{ScreenWidth / 2.0f - (*Scale * 0.5f * SpriteWidth),
                             ScreenHeight / 2.0f - (*Scale * 0.5f * SpriteHeight)};
    WorldPosition = Vector2{0.0f, 0.0f};
    WorldPositionLastFrame = WorldPosition;
}

void Character::Tick(float DeltaTime)
{
    BaseCharacter::Tick(DeltaTime);

    Vector2 Direction{};
    HandleInput(Direction);

    if (Vector2Length(Direction) != 0.0f)
    {
        WorldPosition = Vector2Add(WorldPosition, Vector2Scale(Vector2Normalize(Direction), Speed));
        Texture = Run;
    }
    else
    {
        Texture = Idle;
    }
}

void Character::HandleInput(Vector2& direction)
{
    if (IsKeyDown(KEY_A))
    {
        direction.x -= 1.0f;
        RightLeft = -1.0f;
    }
    if (IsKeyDown(KEY_D))
    {
        direction.x += 1.0f;
        RightLeft = 1.0f;
    }
    if (IsKeyDown(KEY_W))
    {
        direction.y -= 1.0f;
    }
    if (IsKeyDown(KEY_S))
    {
        direction.y += 1.0f;
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