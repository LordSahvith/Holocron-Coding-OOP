#include "Prop.h"
#include "raymath.h"

Prop::Prop(Texture2D texture, Vector2 worldPosition, float& scale)
    : Texture{texture}, WorldPosition{worldPosition}, Scale{&scale}
{
}

void Prop::Render(Vector2 knightPosition)
{
    Vector2 ScreenPosition{Vector2Subtract(WorldPosition, knightPosition)};
    DrawTextureEx(Texture, ScreenPosition, 0.0f, *Scale, WHITE);   
}