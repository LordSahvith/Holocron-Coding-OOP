#include "raylib.h"

struct Actor
{
    int spriteCount;
    Texture2D sprites;
    Rectangle rectangle;
    Vector2 position;
    int velocity;
    const float updateTime{1.0 / 12.0};
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

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // delta time (time since last frame)
        float deltaTime{GetFrameTime()};

        HandleGravity(scarfy, gravity, deltaTime);

        HandleJump(scarfy);

        // update nebula position
        UpdatePosition(nebula.position.x, nebula.velocity, deltaTime);
        HandleAnimation(nebula, deltaTime);

        // update character position
        UpdatePosition(scarfy.position.y, scarfy.velocity, deltaTime);

        if (!scarfy.isInAir)
        {
            HandleAnimation(scarfy, deltaTime);
        }

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
    // rectangle = (x, y, width, height);
    rectangle = {0, 0, float(sprites.width / spriteCount), float(sprites.height / spriteCount)};
    position = {float(GetScreenWidth()),                      // set outside rightside of screen
                float(GetScreenHeight() - rectangle.height)}; // set on ground
    velocity = -200;                                          // pixels per second
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
