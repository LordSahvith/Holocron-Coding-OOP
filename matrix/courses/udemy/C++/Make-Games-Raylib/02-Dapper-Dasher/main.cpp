#include "raylib.h"

struct Scarfy
{
    int spriteCount;
    Texture2D sprites;
    Rectangle rectangle;
    Vector2 position;
    int velocity;
    int jumpVelocity;
    bool isInAir;
};

void SetupCharacter(Scarfy& scarfyRef);
void HandleGravity(Scarfy& scarfyRef, const int& gravity, float& deltaTime);
void HandleJump(Scarfy& scarfyRef);
void HandleAnimation(Scarfy& scarfyRef, float& runningTime, const float& updateTime, float& deltaTime, int& frame);

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

    // Amount of time to update animation
    const float updateTime{1.0 / 12.0};
    float runningTime{0};

    // Setup Character
    Scarfy scarfy;
    SetupCharacter(scarfy);

    // animation frame
    int frame{0};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // delta time (time since last frame)
        float deltaTime{GetFrameTime()};

        HandleGravity(scarfy, gravity, deltaTime);

        HandleJump(scarfy);

        // update position
        scarfy.position.y += scarfy.velocity * deltaTime;

        runningTime += deltaTime;
        HandleAnimation(scarfy, runningTime, updateTime, deltaTime, frame);

        DrawTextureRec(scarfy.sprites, scarfy.rectangle, scarfy.position, WHITE);

        EndDrawing();
    }

    UnloadTexture(scarfy.sprites);
    CloseWindow();
}

void SetupCharacter(Scarfy& scarfyRef)
{
    scarfyRef.spriteCount = 6;
    scarfyRef.sprites = LoadTexture("textures/scarfy.png");
    scarfyRef.rectangle.width = scarfyRef.sprites.width / scarfyRef.spriteCount;
    scarfyRef.rectangle.height = scarfyRef.sprites.height;
    scarfyRef.rectangle.x = 0;
    scarfyRef.rectangle.y = 0;
    scarfyRef.position.x = GetScreenWidth() / 2 - scarfyRef.rectangle.width / 2; // center in x coordinates
    scarfyRef.position.y = GetScreenHeight() - scarfyRef.rectangle.height;       // set on "ground"
    scarfyRef.velocity = 0;
    scarfyRef.jumpVelocity = -600; // pixels per second
    scarfyRef.isInAir = false;
}

void HandleGravity(Scarfy& scarfyRef, const int& gravity, float& deltaTime)
{
    // perform ground check
    if (scarfyRef.position.y >= GetScreenHeight() - scarfyRef.rectangle.height)
    {
        // on ground
        scarfyRef.velocity = 0;
        scarfyRef.isInAir = false;
    }
    else
    {
        // in air
        scarfyRef.velocity += gravity * deltaTime;
        scarfyRef.isInAir = true;
    }
}

void HandleJump(Scarfy& scarfyRef)
{
    // Jump
    if (IsKeyPressed(KEY_SPACE) && !scarfyRef.isInAir)
    {
        scarfyRef.velocity += scarfyRef.jumpVelocity;
    }
}

void HandleAnimation(Scarfy& scarfyRef, float& runningTime, const float& updateTime, float& deltaTime, int& frame)
{
    if (runningTime >= updateTime)
    {
        runningTime = 0.0;

        // update animation frame
        scarfyRef.rectangle.x = frame * scarfyRef.rectangle.width;
        frame++;

        // reset frame if end of sprites
        if (frame > scarfyRef.spriteCount - 1)
        {
            frame = 0;
        }
    }
}
