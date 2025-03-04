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
bool Collision(Shape& shapeRef1, Shape& shapeRef2);

int main()
{
    // Window
    InitWindow(500, 400, "Axe Game");

    // Game Setup
    SetTargetFPS(60);

    // Circle
    Shape circle{25, 25, 25, 25, 5, RED};

    // Rectangle
    Shape rectangle{(GetScreenWidth() / 2), (GetScreenHeight() / 2), 50, 50, 10, BLUE};

    bool gameOver{false};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (!gameOver)
        {

            DrawCircle(circle.xPos, circle.yPos, circle.width, circle.color);
            DrawRectangle(rectangle.xPos, rectangle.yPos, rectangle.width, rectangle.height, rectangle.color);

            PlayerMovement(circle);

            rectangle.yPos += rectangle.moveSpeed;
            if (rectangle.GetBottomEdge(rectangle.height) >= GetScreenHeight() || rectangle.GetTopEdge(0) <= 0)
            {
                rectangle.moveSpeed = -rectangle.moveSpeed;
            }

            if (Collision(circle, rectangle))
            {
                gameOver = true;
            }

            // if (circle.GetRightEdge(circle.width) == GetScreenWidth())
            // {
            //     gameOver = true;
            // }
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

bool Collision(Shape& shapeRef1, Shape& shapeRef2)
{
    int shape1Top = shapeRef1.GetTopEdge(shapeRef1.height);
    int shape1Right = shapeRef1.GetRightEdge(shapeRef1.width);
    int shape1Bottom = shapeRef1.GetBottomEdge(shapeRef1.height);
    int shape1Left = shapeRef1.GetLeftEdge(shapeRef1.width);

    int shape2Top = shapeRef2.GetTopEdge(0);
    int shape2Right = shapeRef2.GetRightEdge(shapeRef2.width);
    int shape2Bottom = shapeRef2.GetBottomEdge(shapeRef2.height);
    int shape2Left = shapeRef2.GetLeftEdge(0);

    if (shape2Bottom >= shape1Bottom && shape2Top <= shape1Top && shape2Left <= shape1Left &&
        shape2Right >= shape1Right)
    {
        return true;
    }

    return false;
}
