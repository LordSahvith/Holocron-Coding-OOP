#include "Character.h"
#include "raymath.h"

Character::Character(int width, int height, float& scale)
{
    Texture = LoadTexture("characters/knight_idle_spritesheet.png");
    Idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Run = LoadTexture("characters/knight_run_spritesheet.png");
    Weapon = LoadTexture("characters/weapon_sword.png");
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
    if (!GetIsAlive())
        return;

    HandleInput();

    BaseCharacter::Tick(DeltaTime);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (RightLeft > 0.0f)
    {
        origin = {0.0f, Weapon.height * *Scale};
        offset = {35.0f, 55.0f};
        WeaponCollisionRec = {GetScreenPosition().x + offset.x,
                              GetScreenPosition().y + offset.y - Weapon.height * *Scale, Weapon.width * *Scale,
                              Weapon.height * *Scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.0f : 0.0f;
    }
    else
    {
        origin = {Weapon.width * *Scale, Weapon.height * *Scale};
        offset = {25.0f, 55.0f};
        WeaponCollisionRec = {GetScreenPosition().x + offset.x - Weapon.width * *Scale,
                              GetScreenPosition().y + offset.y - Weapon.height * *Scale, Weapon.width * *Scale,
                              Weapon.height * *Scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.0f : 0.0f;
    }

    // Draw Sword
    Rectangle Source{0.0f, 0.0f, static_cast<float>(Weapon.width) * RightLeft, static_cast<float>(Weapon.height)};
    Rectangle Destination{GetScreenPosition().x + offset.x, GetScreenPosition().y + offset.y, Weapon.width * *Scale,
                          Weapon.height * *Scale};
    DrawTexturePro(Weapon, Source, Destination, origin, rotation, WHITE);

    DrawRectangleLines(WeaponCollisionRec.x, WeaponCollisionRec.y, WeaponCollisionRec.width, WeaponCollisionRec.height,
                       RED);
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

Rectangle Character::GetWeaponCollisionRec()
{
    return WeaponCollisionRec;
}

float Character::GetHealth() const
{
    return Health;
}

void Character::TakeDamage(float damage)
{
    Health -= damage;

    if (Health < 0)
    {
        SetIsAlive(false);
    }
}
