#include "raylib.h"

int main()
{
    // setup window
    const int screenWidth{750};
    const int screenHeight{500};
    InitWindow(screenWidth, screenHeight, "Dapper Dash");

    // setup Frames Per Second (FPS)
    SetTargetFPS(60);

    // acceleration due to gravity (pixels/frame) / frame
    const int gravity{1};

    // rectangle
    const int width{50};
    const int height{80};
    int yPos{screenHeight - height};
    int velocity{10};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // perform ground check
        if (yPos >= screenHeight - height)
        {
            velocity = 0;
        }
        else
        {
            velocity += gravity;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            velocity -= 10;
        }

        // update position
        yPos += velocity;

        DrawRectangle(screenWidth / 2, yPos, width, height, RED);

        EndDrawing();
    }

    CloseWindow();
}