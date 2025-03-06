#include "Enemy.h"

Enemy::Enemy(Texture2D idleTexture, Texture2D runTexture, Vector2 position, float& scale)
    : Texture{idleTexture}, Idle{idleTexture}, Run{runTexture}, WorldPosition{position}, Scale{&scale}
{
    SpriteWidth = Texture.width / SpriteCount;
    SpriteHeight = Texture.height;
}

void Enemy::Tick(float DeltaTime)
{
    WorldPositionLastFrame = WorldPosition;

    // update animation frame
    HandleAnimation(DeltaTime);

    // draw character
    DrawTexturePro(Texture, GetSource(), GetCollisionRec(), Vector2{}, 0.0f, WHITE);
}

void Enemy::HandleAnimation(float& DeltaTime)
{
    // update animation frame
    RunningTime += DeltaTime;
    if (RunningTime >= UpdateTime)
    {
        Frame++;
        RunningTime = 0.0f;
        if (Frame > MaxFrames)
        {
            Frame = 0;
        }
    }
}

Rectangle Enemy::GetSource() const
{
    return Rectangle{Frame * SpriteWidth, 0.0f, RightLeft * SpriteWidth, SpriteHeight};
}

Rectangle Enemy::GetCollisionRec() const
{
    return Rectangle{ScreenPosition.x, ScreenPosition.y, *Scale * SpriteWidth, *Scale * SpriteHeight};
}

Vector2 Enemy::GetWorldPosition() const
{
    return WorldPosition;
}

void Enemy::UndoMovement()
{
    WorldPosition = WorldPositionLastFrame;
}