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
    int jumpVelocity{-20};
    bool isInAir{false};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // perform ground check
        if (yPos >= screenHeight - height)
        {
            // on ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // in air
            velocity += gravity;
            isInAir = true;
        }

        // Jump
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVelocity;
        }

        // update position
        yPos += velocity;

        DrawRectangle(screenWidth / 2, yPos, width, height, RED);

        EndDrawing();
    }

    CloseWindow();
}