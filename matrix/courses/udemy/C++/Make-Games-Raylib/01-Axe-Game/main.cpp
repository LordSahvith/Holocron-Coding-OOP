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
    int windowWidth{500};
    int windowHeight{400};
    InitWindow(windowWidth, windowHeight, "Axe Game");

    // Game Setup
    SetTargetFPS(60);

    // Circle Coordinates
    int circleX{windowWidth / 2};
    int circleY{windowHeight / 2};
    int circleRadius{25};
    Shape circle{circleX, circleY, circleRadius, circleRadius, 5, RED};

    // Rectangle Coordinates
    int rectX{windowWidth / 2};
    int rectY{windowHeight / 2};
    int rectWidth{50};
    int rectHeight{50};
    Shape rectangle{rectX, rectY, rectWidth, rectHeight, 10, RED};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(circle.xPos, circle.yPos, circle.width, RED);
        DrawRectangle(rectangle.xPos, rectangle.yPos, rectangle.width, rectangle.height, BLUE);

        PlayerMovement(circle);

        rectangle.yPos += rectangle.moveSpeed;
        if (rectangle.GetBottomEdge(rectangle.height) >= GetScreenHeight() || rectangle.GetTopEdge(0) <= 0)
        {
            rectangle.moveSpeed = -rectangle.moveSpeed;
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
