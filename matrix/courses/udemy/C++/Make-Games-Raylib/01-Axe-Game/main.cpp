#include "raylib.h"

int main()
{
    // Window
    int width{500};
    int height{400};
    InitWindow(width, height, "Axe Game");

    // Game Setup
    SetTargetFPS(60);

    // Circle Coordinates
    int circleX{width / 2};
    int circleY{height / 2};

    // Player Settings
    int playerSpeed{5};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(circleX, circleY, 25, RED);

        if (IsKeyDown(KEY_D)) // move right
        {
            circleX += playerSpeed;
        }

        if (IsKeyDown(KEY_A)) // move left
        {
            circleX -= playerSpeed;
        }

        if (IsKeyDown(KEY_W)) // move up
        {
            circleY -= playerSpeed;
        }

        if (IsKeyDown(KEY_S)) // move down
        {
            circleY += playerSpeed;
        }

        EndDrawing();
    }

    return 0;
}