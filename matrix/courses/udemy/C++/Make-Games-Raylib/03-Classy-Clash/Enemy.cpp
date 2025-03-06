#include "Enemy.h"

Enemy::Enemy(Texture2D idleTexture, Texture2D runTexture, Vector2 position, float& scale)
{
    Texture = idleTexture;
    Idle = idleTexture;
    Run = runTexture;
    WorldPosition = position;
    Scale = &scale;
    SpriteWidth = Texture.width / SpriteCount;
    SpriteHeight = Texture.height;
}

void Enemy::Tick(float DeltaTime)
{
    BaseCharacter::Tick(DeltaTime);
}