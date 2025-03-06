#include "raylib.h"
#include "raymath.h"
#include "Character.h"

struct Map
{
    Texture2D Texture{LoadTexture("nature_tileset/WorldMap.png")};
    Vector2 Position{0.0f, 0.0f};
    float Scale{4.0f};
};

int main()
{
    // setup window
    const int WINDOW_WIDTH{750};
    const int WINDOW_HEIGHT{500};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Classy Clash");

    // Create Map Object
    Map MainMap;

    // Create Character Object
    Character Knight{WINDOW_WIDTH, WINDOW_HEIGHT, MainMap.Scale};
    Knight.SetScreenWidth(WINDOW_WIDTH);
    Knight.SetScreenHeight(WINDOW_HEIGHT);
    Knight.SetScreenPosition(WINDOW_WIDTH, WINDOW_HEIGHT);
    Knight.SetScale(MainMap.Scale);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw Map
        MainMap.Position = Vector2Scale(Knight.GetWorldPosition(), -1.0f);
        DrawTextureEx(MainMap.Texture, MainMap.Position, 0.0f, MainMap.Scale, WHITE);

        // Draw Character
        Knight.Tick(GetFrameTime());

        EndDrawing();
    }

    CloseWindow();
}