#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

struct Map
{
    Map(float& scale)
    {
        Scale = &scale;
    };
    Texture2D Texture{LoadTexture("nature_tileset/WorldMap.png")};
    Vector2 Position{0.0f, 0.0f};
    float* Scale;
};

int main()
{
    // setup window
    const int WINDOW_WIDTH{750};
    const int WINDOW_HEIGHT{500};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Classy Clash");

    // scale for map and character images
    float scale{4.0f};

    // Create Map Object
    Map MainMap{scale};

    // Create Character Object
    Character Knight{WINDOW_WIDTH, WINDOW_HEIGHT, scale};

    // Create Prop Object
    Texture2D rockTexture{LoadTexture("nature_tileset/Rock.png")};
    Prop Rock{rockTexture, Vector2{4.0f, 4.0f}, scale};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw Map
        MainMap.Position = Vector2Scale(Knight.GetWorldPosition(), -1.0f);
        DrawTextureEx(MainMap.Texture, MainMap.Position, 0.0f, *MainMap.Scale, WHITE);

        // Draw Rock
        Rock.Render(Knight.GetWorldPosition());

        // Draw Character
        Knight.Tick(GetFrameTime());

        EndDrawing();
    }

    CloseWindow();
}