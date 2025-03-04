#include "raylib.h"

int main()
{
    // setup window
    const int screenWidth{750};
    const int screenHeight{500};
    InitWindow(screenWidth, screenHeight, "Dapper Dash");

    // setup Frames Per Second (FPS)
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
}