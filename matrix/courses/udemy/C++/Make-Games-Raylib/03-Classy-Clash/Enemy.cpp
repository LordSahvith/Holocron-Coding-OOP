#include "Enemy.h"
#include "Character.h"
#include "raymath.h"

Enemy::Enemy(Texture2D idleTexture, Texture2D runTexture, Vector2 position, float& scale)
{
    Texture = idleTexture;
    Idle = idleTexture;
    Run = runTexture;
    WorldPosition = position;
    Scale = &scale;
    SpriteWidth = Texture.width / SpriteCount;
    SpriteHeight = Texture.height;
    Speed = 3.5f;
}

void Enemy::Tick(float DeltaTime)
{
    if (!GetIsAlive())
        return;

    Velocity = Vector2Subtract(Target->GetScreenPosition(), GetScreenPosition());
    BaseCharacter::Tick(DeltaTime);

    if (CheckCollisionRecs(Target->GetCollisionRec(), GetCollisionRec()))
    {
        Target->TakeDamage(DamagePerSecond * DeltaTime);
    }
}

Vector2 Enemy::GetScreenPosition() const
{
    return Vector2Subtract(WorldPosition, Target->GetWorldPosition());
}

void Enemy::SetTarget(Character* character)
{
    Target = character;
}