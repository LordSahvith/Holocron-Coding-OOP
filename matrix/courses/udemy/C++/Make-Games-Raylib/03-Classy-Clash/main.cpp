#include "raylib.h"
#include "raymath.h"

struct Map
{
    Texture2D Texture{LoadTexture("nature_tileset/WorldMap.png")};
    Vector2 Position{0.0f, 0.0f};
    float Scale{4.0f};
};

class Character
{
  public:
    Vector2 GetWorldPosition() const;
    void SetScreenPosition(int windowWidth, int windowHeight);
    void SetScreenWidth(int windowWidth);
    void SetScreenHeight(int windowHeight);
    void SetScale(float amount);
    void Tick(float DeltaTime);

  private:
    Texture2D Texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D Idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D Run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 ScreenPosition{0.0f, 0.0f};
    Vector2 WorldPosition{0.0f, 0.0f};
    int ScreenWidth{};
    int ScreenHeight{};
    float RightLeft{1.0f};
    float RunningTime{0.0f};
    int Frame{0};
    const int MaxFrames{6};
    const float UpdateTime{1.0f / 12.0f};
    const float Speed{4.0f};
    float Scale{0.0f};
};

Vector2 Character::GetWorldPosition() const
{
    return WorldPosition;
}

void Character::SetScreenPosition(int width, int height)
{
    ScreenPosition = {(float)width / 2.0f - (4.0f * (0.5f * (float)Texture.width / 6.0f)),
                      (float)height / 2.0f - (4.0f * (0.5f * (float)Texture.height))};
}

void Character::SetScreenWidth(int width)
{
    ScreenWidth = width;
}

void Character::SetScreenHeight(int height)
{
    ScreenHeight = height;
}

void Character::SetScale(float amount)
{
    Scale = amount;
}

void Character::Tick(float DeltaTime)
{
    Vector2 direction{};
    if (IsKeyDown(KEY_A) && WorldPosition.x > 0.00001f)
    {
        direction.x -= 1.0f;
        RightLeft = -1.0f;
    }
    if (IsKeyDown(KEY_D) && WorldPosition.x < (Scale * ScreenWidth) - ScreenWidth)
    {
        direction.x += 1.0f;
        RightLeft = 1.0f;
    }
    if (IsKeyDown(KEY_W) && WorldPosition.y > 0.00001f)
    {
        direction.y -= 1.0f;
    }
    if (IsKeyDown(KEY_S) && WorldPosition.y < (Scale * ScreenHeight) -  ScreenHeight)
    {
        direction.y += 1.0f;
    }

    if (Vector2Length(direction) != 0.0f)
    {
        WorldPosition = Vector2Add(WorldPosition, Vector2Scale(Vector2Normalize(direction), Speed));
        Texture = Run;
    }
    else
    {
        Texture = Idle;
    }

    // update animation frame
    RunningTime += DeltaTime;
    if (RunningTime >= UpdateTime)
    {
        Frame++;
        RunningTime = 0.0f;
        if (Frame > MaxFrames)
        {
            Frame = 0;
        }
    }

    // draw character
    Rectangle source{Frame * ((float)Texture.width / 6.0f), 0.0f, RightLeft * ((float)Texture.width / 6.0f),
                     (float)Texture.height};
    Rectangle destination{ScreenPosition.x, ScreenPosition.y, (4.0f * (Texture.width / 6.0f)), (4.0f * Texture.height)};
    DrawTexturePro(Texture, source, destination, Vector2{}, 0.0f, WHITE);
}

int main()
{
    // setup window
    const int WINDOW_WIDTH{750};
    const int WINDOW_HEIGHT{500};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Classy Clash");

    // Create Map Object
    Map MainMap;

    // Create Character Object
    Character Knight;
    Knight.SetScreenWidth(WINDOW_WIDTH);
    Knight.SetScreenHeight(WINDOW_HEIGHT);
    Knight.SetScreenPosition(WINDOW_WIDTH, WINDOW_HEIGHT);
    Knight.SetScale(MainMap.Scale);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw Map
        MainMap.Position = Vector2Scale(Knight.GetWorldPosition(), -1.0f);
        DrawTextureEx(MainMap.Texture, MainMap.Position, 0, MainMap.Scale, WHITE);

        // Draw Character
        Knight.Tick(GetFrameTime());

        EndDrawing();
    }

    CloseWindow();
}