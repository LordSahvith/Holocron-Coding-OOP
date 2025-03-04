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
void UpdateBackground(Texture2D& imageRef, float& xPos, float& deltaTime, int speed);

int main()
{
    // setup window
    const int windowDimensions[]{768, 576}; // background images width's * 3
    InitWindow(windowDimensions[0], windowDimensions[1], "Dapper Dash");

    // setup Frames Per Second (FPS)
    SetTargetFPS(60);

    // Setup Nebulae
    const int nebulaeCount{15};
    Nebula nebulae[nebulaeCount]{};

    for (int i = 0; i < nebulaeCount; i++)
    {
        nebulae[i].position.x = GetScreenWidth() + (400 * GetRandomValue(i, i + i));
        nebulae[i].updateTime = 1.0 / GetRandomValue(12.0, 20.0);
    }

    float finishLine{nebulae[nebulaeCount - 1].position.x};

    // Create Character
    Scarfy scarfy;

    Texture2D background = LoadTexture("textures/far-buildings.png");
    float bgX{0};
    Texture2D midground = LoadTexture("textures/back-buildings.png");
    float mgX{0};
    Texture2D foreground = LoadTexture("textures/foreground.png");
    float fgX{0};

    // acceleration due to gravity (pixels/sec) / sec
    const int gravity{1'000};

    // delta time (time since last frame)
    float deltaTime{GetFrameTime()};
    bool collision{false};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        UpdateBackground(background, bgX, deltaTime, 20);
        UpdateBackground(midground, mgX, deltaTime, 40);
        UpdateBackground(foreground, fgX, deltaTime, 80);

        // delta time (time since last frame)
        deltaTime = GetFrameTime();

        // Update and Animate each Nebulae
        for (Nebula& nebula : nebulae)
        {
            UpdatePosition(nebula.position.x, nebula.velocity, deltaTime);
            HandleAnimation(nebula, deltaTime); // pass value as reference
        }

        // Scarfy Functionality
        HandleGravity(scarfy, gravity, deltaTime);
        HandleJump(scarfy);
        UpdatePosition(scarfy.position.y, scarfy.velocity, deltaTime);

        if (!scarfy.isInAir)
        {
            HandleAnimation(scarfy, deltaTime);
        }

        // Loop and draw each nebulae and check for collision
        for (Nebula nebula : nebulae)
        {
            float padding{20};
            Rectangle nebulaRect{nebula.position.x + padding, nebula.position.y + padding,
                                 nebula.rectangle.width - (padding * 2), nebula.rectangle.height - (padding * 2)};

            Rectangle scarfyRect{scarfy.position.x + padding, scarfy.position.y + padding,
                                 scarfy.rectangle.width - (padding * 2), scarfy.rectangle.height - (padding * 2)};

            if (CheckCollisionRecs(nebulaRect, scarfyRect))
            {
                collision = true;
            }

            if (!collision)
            {
                DrawTextureRec(nebula.sprites, nebula.rectangle, nebula.position, WHITE);
            }
        }

        if (collision)
        {
            // lose game
            DrawText("Game Over!", GetScreenWidth() / 2 - 75, GetScreenHeight() / 2, 40, RED);
        }
        else if (scarfy.position.x >= finishLine)
        {
            // Win game
            DrawText("You Won!", GetScreenWidth() / 2 - 75, GetScreenHeight() / 2, 40, BLUE);
        }
        else
        {
            DrawTextureRec(scarfy.sprites, scarfy.rectangle, scarfy.position, WHITE);
        }

        // move finish line with nebulae
        UpdatePosition(finishLine, nebulae[0].velocity, deltaTime);

        EndDrawing();
    }

    // loop and unload each nebula
    for (Nebula& nebula : nebulae)
    {
        UnloadTexture(nebula.sprites);
    }

    UnloadTexture(scarfy.sprites);
    UnloadTexture(background);
    UnloadTexture(midground);
    UnloadTexture(foreground);
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

void UpdateBackground(Texture2D& imageRef, float& xPos, float& deltaTime, int speed)
{
    int scale{3};
    // reset background image
    xPos -= speed * deltaTime;

    if (xPos <= -imageRef.width * scale)
    {
        xPos = 0.0;
    }

    // draw the imageRef
    Vector2 imageRef1Position = {xPos, 0.0};
    DrawTextureEx(imageRef, imageRef1Position, 0.0, scale, WHITE);
    Vector2 imageRef2Position = {xPos + imageRef.width * scale, 0.0};
    DrawTextureEx(imageRef, imageRef2Position, 0.0, scale, WHITE);
}
