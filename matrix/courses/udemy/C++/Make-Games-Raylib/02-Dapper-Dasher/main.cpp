#include "raylib.h"
#include <vector>

struct Actor
{
    int spriteCount;
    Texture2D sprites;
    Rectangle rectangle;
    Vector2 position;
    int velocity;
    float updateTime;
    float runningTime{0};
    int frame{0};
};

struct Scarfy : public Actor
{
    int jumpVelocity;
    bool isInAir;

    Scarfy();
};

struct Nebula : public Actor
{
    Nebula();
};

void HandleGravity(Scarfy& scarfyRef, const int& gravity, float& deltaTime);
void HandleJump(Scarfy& scarfyRef);
void HandleAnimation(Actor& actorRef, float& deltaTime);
void UpdatePosition(float& position, int& velocity, float& deltaTime);

int main()
{
    // setup window
    const int windowDimensions[]{768, 576};
    InitWindow(windowDimensions[0], windowDimensions[1], "Dapper Dash");

    // setup Frames Per Second (FPS)
    SetTargetFPS(60);

    // Setup Nebulae
    const int nebulaeCount{10};
    Nebula nebulae[nebulaeCount]{};

    for (int i = 0; i < nebulaeCount; i++)
    {
        int rand = GetRandomValue(300, 350) * i;
        nebulae[i].position.x = GetScreenWidth() + (rand);
        nebulae[i].updateTime = 1.0 / GetRandomValue(12.0, 20.0);
    }

    // Create Character
    Scarfy scarfy;

    Texture2D background = LoadTexture("textures/far-buildings.png");
    float bgX{0};

    // acceleration due to gravity (pixels/sec) / sec
    const int gravity{1'000};

    // delta time (time since last frame)
    float deltaTime{GetFrameTime()};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // reset background image
        bgX -= 20 * deltaTime;

        if (bgX <= -background.width * 2)
        {
            bgX = 0.0;
        }

        // draw the background
        Vector2 background1Position = {bgX, 0.0};
        DrawTextureEx(background, background1Position, 0.0, 3.0, WHITE);
        Vector2 background2Position = {bgX + background.width * 2, 0.0};
        DrawTextureEx(background, background2Position, 0.0, 3.0, WHITE);

        // delta time (time since last frame)
        deltaTime = GetFrameTime();

        // Update and Animate each Nebulae
        for (int i = 0; i < nebulaeCount; i++)
        {
            UpdatePosition(nebulae[i].position.x, nebulae[i].velocity, deltaTime);
            HandleAnimation(nebulae[i], deltaTime); // pass value as reference
        }

        // Scarfy Functionality
        HandleGravity(scarfy, gravity, deltaTime);
        HandleJump(scarfy);
        UpdatePosition(scarfy.position.y, scarfy.velocity, deltaTime);

        if (!scarfy.isInAir)
        {
            HandleAnimation(scarfy, deltaTime);
        }

        // Loop and draw each nebulae
        for (int i = 0; i < nebulaeCount; i++)
        {
            DrawTextureRec(nebulae[i].sprites, nebulae[i].rectangle, nebulae[i].position, WHITE);
        }

        DrawTextureRec(scarfy.sprites, scarfy.rectangle, scarfy.position, WHITE);

        EndDrawing();
    }

    // loop and unload each nebula
    for (int i = 0; i < nebulaeCount; i++)
    {
        UnloadTexture(nebulae[i].sprites);
    }

    UnloadTexture(scarfy.sprites);
    UnloadTexture(background);
    CloseWindow();
}

Nebula::Nebula()
{
    spriteCount = 8;
    sprites = LoadTexture("textures/12_nebula_spritesheet.png");
    // rectangle = (x, y, width, height);
    rectangle = {0, 0, float(sprites.width / spriteCount), float(sprites.height / spriteCount)};
    position = {float(0),                                     // set outside rightside of screen
                float(GetScreenHeight() - rectangle.height)}; // set on ground
    velocity = -200;                                          // pixels per second
    updateTime = 0;
}

Scarfy::Scarfy()
{
    spriteCount = 6;
    sprites = LoadTexture("textures/scarfy.png");
    // rectangle = (x, y, width, height);
    rectangle = {0, 0, float(sprites.width / spriteCount), float(sprites.height)};
    position = {float(GetScreenWidth() / 2 - rectangle.width / 2), // center in x coordinates
                float(GetScreenHeight() - rectangle.height)};      // set on "ground"
    velocity = 0;
    updateTime = 1.0 / 12.0;
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

void HandleAnimation(Actor& actorRef, float& deltaTime)
{
    actorRef.runningTime += deltaTime;

    if (actorRef.runningTime >= actorRef.updateTime)
    {
        actorRef.runningTime = 0.0;

        // update animation frame
        actorRef.rectangle.x = actorRef.frame * actorRef.rectangle.width;
        actorRef.frame++;

        // reset frame if end of sprites
        if (actorRef.frame > actorRef.spriteCount - 1)
        {
            actorRef.frame = 0;
        }
    }
}

void UpdatePosition(float& position, int& velocity, float& deltaTime)
{
    // update position
    position += velocity * deltaTime;
}
