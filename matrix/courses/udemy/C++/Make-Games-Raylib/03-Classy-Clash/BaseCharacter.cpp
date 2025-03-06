#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::Tick(float DeltaTime)
{    
    WorldPositionLastFrame = WorldPosition;

    // update animation frame
    HandleAnimation(DeltaTime);

    // draw character
    DrawTexturePro(Texture, GetSource(), GetCollisionRec(), Vector2{}, 0.0f, WHITE);
}

Vector2 BaseCharacter::GetWorldPosition() const
{
    return WorldPosition;
}

Rectangle BaseCharacter::GetCollisionRec() const
{
    return Rectangle{ScreenPosition.x, ScreenPosition.y, *Scale * SpriteWidth, *Scale * SpriteHeight};
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