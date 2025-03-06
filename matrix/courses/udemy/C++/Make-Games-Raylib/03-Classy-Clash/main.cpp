#include "raylib.h"
#include "raymath.h"

class Map
{
  public:
    Map(Texture2D map, Vector2 pos, float scale, float speed)
        : MapImage{map}, Position{pos}, Scale{scale}, Speed{speed} {};
    Texture2D GetMap() const { return MapImage; }
    int GetMapWidth() const
    {
        return MapImage.width * Scale;
    }
    int GetMapHeight() const
    {
        return MapImage.height * Scale;
    }
    Vector2 GetPosition() const
    {
        return Position;
    }
    void SetPosition(Vector2 pos)
    {
        Position = pos;
    }
    float GetScale() const
    {
        return Scale;
    }
    float GetSpeed() const
    {
        return Speed;
    }

  private:
    Texture2D MapImage;
    Vector2 Position;
    float Scale;
    float Speed;
};

int main()
{
    // setup window
    const int WINDOW_WIDTH{750};
    const int WINDOW_HEIGHT{500};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Classy Clash");

    // Map Settings
    const Texture2D MAIN_MAP = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 mapPos{0.0f, 0.0f};
    const float MAP_SCALE{4.0f};
    float cameraSpeed{4.0f};
    Map MainMap{MAIN_MAP, mapPos, MAP_SCALE, cameraSpeed};

    // Character Settings
    Texture2D knightIdle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knightRun = LoadTexture("characters/knight_run_spritesheet.png");
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{(float)WINDOW_WIDTH / 2.0f - (MAP_SCALE * (0.5f * (float)knight.width / 6.0f)),
                      (float)WINDOW_HEIGHT / 2.0f - (MAP_SCALE * (0.5f * (float)knight.height))};
    float rightLeft{1.0f}; // 1: right, -1: left
    // animation variables
    float runningTime{0.0f};
    int frame{0};
    const int maxFrames{6};
    const float updateTime{1.0f / 12.0f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Vector2 direction{};
        if (IsKeyDown(KEY_A) && MainMap.GetPosition().x < 0)
        {
            direction.x -= 1.0f;
            rightLeft = -1.0f;
        }
        if (IsKeyDown(KEY_D) && MainMap.GetPosition().x > -(MainMap.GetMapWidth() - WINDOW_WIDTH))
        {
            direction.x += 1.0f;
            rightLeft = 1.0f;
        }
        if (IsKeyDown(KEY_W) && MainMap.GetPosition().y < 0)
        {
            direction.y -= 1.0f;
        }
        if (IsKeyDown(KEY_S) && MainMap.GetPosition().y > -(MainMap.GetMapHeight() - WINDOW_HEIGHT))
        {
            direction.y += 1.0f;
        }

        if (Vector2Length(direction) != 0.0f)
        {
            Vector2 newPos = Vector2Subtract(MainMap.GetPosition(), Vector2Scale(Vector2Normalize(direction), cameraSpeed));
            MainMap.SetPosition(newPos);
            knight = knightRun;
        }
        else
        {
            knight = knightIdle;
        }

        // draw map
        DrawTextureEx(MainMap.GetMap(), MainMap.GetPosition(), 0, MAP_SCALE, WHITE);

        // update animation frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.0f;
            if (frame > maxFrames)
            {
                frame = 0;
            }
        }

        // draw character
        Rectangle source{frame * (float)knight.width / 6.0f, 0.0f, rightLeft * ((float)knight.width / 6.0f),
                         (float)knight.height};
        Rectangle destination{knightPos.x, knightPos.y, MAP_SCALE * (knight.width / 6.0f), MAP_SCALE * (knight.height)};
        DrawTexturePro(knight, source, destination, Vector2{}, 0.0f, WHITE);

        EndDrawing();
    }

    CloseWindow();
}