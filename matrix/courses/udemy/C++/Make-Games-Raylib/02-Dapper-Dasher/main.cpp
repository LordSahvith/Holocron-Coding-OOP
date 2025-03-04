#include "raylib.h"

struct Scarfy
{
    Texture2D sprites;
    Rectangle rectangle;
    Vector2 position;
    int velocity;
    int jumpVelocity;
    bool isInAir;
};

int main()
{
    // setup window
    const int screenWidth{750};
    const int screenHeight{500};
    InitWindow(screenWidth, screenHeight, "Dapper Dash");

    // setup Frames Per Second (FPS)
    SetTargetFPS(60);

    // acceleration due to gravity (pixels/sec) / sec
    const int gravity{1'000};

    // get character sprite
    Scarfy scarfy;
    scarfy.sprites = LoadTexture("textures/scarfy.png");
    scarfy.rectangle.width = scarfy.sprites.width / 6; // there are 6 sprites
    scarfy.rectangle.height = scarfy.sprites.height;
    scarfy.rectangle.x = 0;
    scarfy.rectangle.y = 0;
    scarfy.position.x = screenWidth / 2 - scarfy.rectangle.width / 2; // center in x coordinates
    scarfy.position.y = screenHeight - scarfy.rectangle.height;       // set on "ground"
    scarfy.velocity = 0;
    scarfy.jumpVelocity = -600; // pixels per second
    scarfy.isInAir = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // delta time (time since last frame)
        float deltaTime{GetFrameTime()};

        // perform ground check
        if (scarfy.position.y >= screenHeight - scarfy.rectangle.height)
        {
            // on ground
            scarfy.velocity = 0;
            scarfy.isInAir = false;
        }
        else
        {
            // in air
            scarfy.velocity += gravity * deltaTime;
            scarfy.isInAir = true;
        }

        // Jump
        if (IsKeyPressed(KEY_SPACE) && !scarfy.isInAir)
        {
            scarfy.velocity += scarfy.jumpVelocity;
        }

        // update position
        scarfy.position.y += scarfy.velocity * deltaTime;

        DrawTextureRec(scarfy.sprites, scarfy.rectangle, scarfy.position, WHITE);

        EndDrawing();
    }

    UnloadTexture(scarfy.sprites);
    CloseWindow();
}