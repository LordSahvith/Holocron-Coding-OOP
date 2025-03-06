#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::Tick(float DeltaTime)
{
    WorldPositionLastFrame = WorldPosition;

    // update animation frame
    HandleAnimation(DeltaTime);

    if (Vector2Length(Velocity) != 0.0f)
    {
        WorldPosition = Vector2Add(WorldPosition, Vector2Scale(Vector2Normalize(Velocity), Speed));
        Velocity.x < 0.0f ? RightLeft = -1.0f : RightLeft = 1.0f;
        Texture = Run;
    }
    else
    {
        Texture = Idle;
    }

    Velocity = {0.0f, 0.0f};

    // draw character
    DrawTexturePro(Texture, GetSource(), GetCollisionRec(), Vector2{}, 0.0f, WHITE);
}

Vector2 BaseCharacter::GetWorldPosition() const
{
    return WorldPosition;
}

Rectangle BaseCharacter::GetCollisionRec() const
{
    return Rectangle{GetScreenPosition().x, GetScreenPosition().y, *Scale * SpriteWidth, *Scale * SpriteHeight};
}

Rectangle BaseCharacter::GetSource() const
{
    return Rectangle{Frame * SpriteWidth, 0.0f, RightLeft * SpriteWidth, SpriteHeight};
}

void BaseCharacter::HandleAnimation(float& DeltaTime)
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

void BaseCharacter::UndoMovement()
{
    WorldPosition = WorldPositionLastFrame;
}