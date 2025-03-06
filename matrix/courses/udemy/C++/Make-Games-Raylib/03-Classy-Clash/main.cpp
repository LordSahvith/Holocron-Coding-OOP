#include "raylib.h"
#include "raymath.h"

int main()
{
    // setup window
    const int WINDOW_WIDTH{750};
    const int WINDOW_HEIGHT{500};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Classy Clash");

    const Texture2D MAIN_MAP = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    const float MAP_SCALE{4.0};
    float cameraSpeed{4.0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Vector2 direction{};
        if (IsKeyDown(KEY_A) && mapPos.x < 0)
            direction.x -= 1.0;
        if (IsKeyDown(KEY_D) && mapPos.x > -(MAIN_MAP.width * MAP_SCALE - WINDOW_WIDTH))
            direction.x += 1.0;
        if (IsKeyDown(KEY_W) && mapPos.y < 0)
            direction.y -= 1.0;
        if (IsKeyDown(KEY_S) && mapPos.y > -(MAIN_MAP.height * MAP_SCALE - WINDOW_HEIGHT))
            direction.y += 1.0;

        if (Vector2Length(direction) != 0.0)
        {
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), cameraSpeed));
        }

        DrawTextureEx(MAIN_MAP, mapPos, 0, MAP_SCALE, WHITE);

        EndDrawing();
    }

    CloseWindow();
}