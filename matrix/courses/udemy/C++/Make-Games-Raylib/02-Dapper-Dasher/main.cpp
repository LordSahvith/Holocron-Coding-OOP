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

    Scarfy();
};

struct Nebula
{
    int spriteCount;
    Texture2D sprites;
    Rectangle rectangle;
    Vector2 position;
    int velocity;

    Nebula();
};

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

    // Create Nebula
    Nebula nebula;

    // Create Character
    Scarfy scarfy;

    // acceleration due to gravity (pixels/sec) / sec
    const int gravity{1'000};

    // Amount of time to update animation
    const float updateTime{1.0 / 12.0};
    float runningTime{0};

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

        HandleAnimation(scarfy, runningTime, updateTime, deltaTime, frame);

        DrawTextureRec(nebula.sprites, nebula.rectangle, nebula.position, WHITE);
        DrawTextureRec(scarfy.sprites, scarfy.rectangle, scarfy.position, WHITE);

        EndDrawing();
    }

    UnloadTexture(nebula.sprites);
    UnloadTexture(scarfy.sprites);
    CloseWindow();
}

Nebula::Nebula()
{
    spriteCount = 8;
    sprites = LoadTexture("textures/12_nebula_spritesheet.png");
    rectangle.width = sprites.width / spriteCount;
    rectangle.height = sprites.height / spriteCount;
    rectangle.x = 0;
    rectangle.y = 0;
    position.x = GetScreenWidth() / 2 - rectangle.width / 2; // center in x coordinates
    position.y = GetScreenHeight() - rectangle.height;       // set on "ground"
    velocity = 0;
}

Scarfy::Scarfy()
{
    spriteCount = 6;
    sprites = LoadTexture("textures/scarfy.png");
    rectangle.width = sprites.width / spriteCount;
    rectangle.height = sprites.height;
    rectangle.x = 0;
    rectangle.y = 0;
    position.x = GetScreenWidth() / 2 - rectangle.width / 2; // center in x coordinates
    position.y = GetScreenHeight() - rectangle.height;       // set on "ground"
    velocity = 0;
    jumpVelocity = -600; // pixels per second
    isInAir = false;
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
    runningTime += deltaTime;

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
