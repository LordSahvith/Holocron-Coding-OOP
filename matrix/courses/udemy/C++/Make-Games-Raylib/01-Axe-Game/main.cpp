#include "raylib.h"

struct Shape
{
    int xPos;
    int yPos;
    int width;
    int height;
    int moveSpeed;
    Color color;

    int GetRightEdge(int width) const
    {
        return xPos + width;
    }
    int GetLeftEdge(int width) const
    {
        return xPos - width;
    }
    int GetTopEdge(int height) const
    {
        return yPos - height;
    }
    int GetBottomEdge(int height) const
    {
        return yPos + height;
    }
};

void PlayerMovement(Shape& shapeRef);

int main()
{
    // Window
    InitWindow(500, 400, "Axe Game");

    // Game Setup
    SetTargetFPS(60);

    // Circle
    Shape circle{(GetScreenWidth() / 2), (GetScreenHeight() / 2), 25, 25, 5, RED};

    // Rectangle
    Shape rectangle{(GetScreenWidth() / 2), (GetScreenHeight() / 2), 50, 50, 10, RED};

    bool gameOver{false};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (!gameOver)
        {

            DrawCircle(circle.xPos, circle.yPos, circle.width, RED);
            DrawRectangle(rectangle.xPos, rectangle.yPos, rectangle.width, rectangle.height, BLUE);

            PlayerMovement(circle);

            rectangle.yPos += rectangle.moveSpeed;
            if (rectangle.GetBottomEdge(rectangle.height) >= GetScreenHeight() || rectangle.GetTopEdge(0) <= 0)
            {
                rectangle.moveSpeed = -rectangle.moveSpeed;
            }

            if (circle.GetRightEdge(circle.width) == GetScreenWidth())
            {
                gameOver = true;
            }
        }
        else
        {
            DrawText("Game Over!", (GetScreenWidth() / 2), (GetScreenHeight() / 2), 20, RED);
        }

        EndDrawing();
    }

    return 0;
}

void PlayerMovement(Shape& shapeRef)
{
    if (IsKeyDown(KEY_D) && shapeRef.GetRightEdge(shapeRef.width) < GetScreenWidth()) // move right
    {
        shapeRef.xPos += shapeRef.moveSpeed;
    }

    if (IsKeyDown(KEY_A) && shapeRef.GetLeftEdge(shapeRef.width) > 0) // move left
    {
        shapeRef.xPos -= shapeRef.moveSpeed;
    }

    if (IsKeyDown(KEY_W) && shapeRef.GetTopEdge(shapeRef.height) > 0) // move up
    {
        shapeRef.yPos -= shapeRef.moveSpeed;
    }

    if (IsKeyDown(KEY_S) && shapeRef.GetBottomEdge(shapeRef.height) < GetScreenHeight()) // move down
    {
        shapeRef.yPos += shapeRef.moveSpeed;
    }
}
