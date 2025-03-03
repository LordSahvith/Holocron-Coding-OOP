#include "raylib.h"

int main()
{
    int width{500};
    int height{400};
    InitWindow(width, height, "Axe Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        int xPos{width / 2};
        int yPos{height / 2};
        DrawCircle(xPos, yPos, 25, RED);
        
        EndDrawing();
    }

    return 0;
}