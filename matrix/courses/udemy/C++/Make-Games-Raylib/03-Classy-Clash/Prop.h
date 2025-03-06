#pragma once

#include "raylib.h"

class Prop
{
  public:
    Prop(Texture2D texture, Vector2 worldPosition, float& scale);
    void Render(Vector2 knightPosition);

  private:
    Texture2D Texture;
    Vector2 WorldPosition;
    float* Scale;
};