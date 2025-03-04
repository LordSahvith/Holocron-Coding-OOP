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
    Nebula(int xPos, float time);
};

void HandleGravity(Scarfy& scarfyRef, const int& gravity, float& deltaTime);
void HandleJump(Scarfy& scarfyRef);
void HandleAnimation(Actor& actorRef, float& deltaTime);
void UpdatePosition(float& position, int& velocity, float& deltaTime);

int main()
{
    // setup window
    const int windowDimensions[]{750, 500};
    InitWindow(windowDimensions[0], windowDimensions[1], "Dapper Dash");

    // setup Frames Per Second (FPS)
    SetTargetFPS(60);

    // Create Nebula (startPosX, updateTime)
    Nebula nebula(GetScreenWidth(), (1.0 / 12.0));
    Nebula nebula2(GetScreenWidth() + 300, (1.0 / 16.0));

    std::vector<Nebula*> nebulae{};
    nebulae.push_back(&nebula);
    nebulae.push_back(&nebula2);

    // Create Character
    Scarfy scarfy;

    // acceleration due to gravity (pixels/sec) / sec
    const int gravity{1'000};

    // delta time (time since last frame)
    float deltaTime{GetFrameTime()};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // delta time (time since last frame)
        deltaTime = GetFrameTime();

        for (Nebula* neb : nebulae)
        {
            UpdatePosition(neb->position.x, neb->velocity, deltaTime);
            HandleAnimation(*neb, deltaTime);
        }

        // // update nebula position
        // UpdatePosition(nebula.position.x, nebula.velocity, deltaTime);
        // HandleAnimation(nebula, deltaTime);

        // // update nebula position
        // UpdatePosition(nebula2.position.x, nebula2.velocity, deltaTime);
        // HandleAnimation(nebula2, deltaTime);

        // Scarfy Functionality
        HandleGravity(scarfy, gravity, deltaTime);
        HandleJump(scarfy);

        // update character position
        UpdatePosition(scarfy.position.y, scarfy.velocity, deltaTime);

        if (!scarfy.isInAir)
        {
            HandleAnimation(scarfy, deltaTime);
        }

        DrawTextureRec(nebulae[0]->sprites, nebulae[0]->rectangle, nebulae[0]->position, WHITE);
        DrawTextureRec(nebulae[1]->sprites, nebulae[1]->rectangle, nebulae[1]->position, RED);
        DrawTextureRec(scarfy.sprites, scarfy.rectangle, scarfy.position, WHITE);

        EndDrawing();
    }

    UnloadTexture(nebula.sprites);
    UnloadTexture(nebula2.sprites);
    UnloadTexture(scarfy.sprites);
    CloseWindow();
}

Nebula::Nebula(int xPos, float time)
{
    spriteCount = 8;
    sprites = LoadTexture("textures/12_nebula_spritesheet.png");
    // rectangle = (x, y, width, height);
    rectangle = {0, 0, float(sprites.width / spriteCount), float(sprites.height / spriteCount)};
    position = {float(xPos),                                  // set outside rightside of screen
                float(GetScreenHeight() - rectangle.height)}; // set on ground
    velocity = -200;                                          // pixels per second
    updateTime = time;
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
