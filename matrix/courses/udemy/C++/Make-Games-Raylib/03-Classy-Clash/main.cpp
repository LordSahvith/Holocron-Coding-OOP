#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

struct Map
{
    Map(float& scale)
    {
        Scale = &scale;
    };
    Texture2D Texture{LoadTexture("nature_tileset/WorldMap.png")};
    Vector2 Position{0.0f, 0.0f};
    float* Scale;
};

int main()
{
    // setup window
    const int WINDOW_WIDTH{750};
    const int WINDOW_HEIGHT{500};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Classy Clash");

    // scale for map and character images
    float scale{4.0f};

    // Create Map Object
    Map MainMap{scale};

    // Create Character Object
    Character Knight{WINDOW_WIDTH, WINDOW_HEIGHT, scale};

    // Create Props
    Prop Props[2]{
        Prop{LoadTexture("nature_tileset/Rock.png"), Vector2{700, 400}, scale},
        Prop{LoadTexture("nature_tileset/Log.png"), Vector2{500, 400}, scale},
    };

    Enemy Goblins[1]{Enemy{LoadTexture("characters/goblin_idle_spritesheet.png"),
                           LoadTexture("characters/goblin_run_spritesheet.png"), Vector2{400, 400}, scale}};

    // Set Goblin's Character Target
    for (Enemy& goblin : Goblins)
    {
        goblin.SetTarget(&Knight);
    }

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw Map
        MainMap.Position = Vector2Scale(Knight.GetWorldPosition(), -1.0f);
        DrawTextureEx(MainMap.Texture, MainMap.Position, 0.0f, *MainMap.Scale, WHITE);

        // Check Map Bounds
        if (Knight.GetWorldPosition().y < 0.0f || Knight.GetWorldPosition().x < 0.0f ||
            Knight.GetWorldPosition().x > (*Knight.GetScale() * Knight.GetScreenWidth()) - Knight.GetScreenWidth() ||
            Knight.GetWorldPosition().x > (*Knight.GetScale() * Knight.GetScreenHeight()) - Knight.GetScreenHeight())
        {
            Knight.UndoMovement();
        }

        // Draw Props
        for (Prop& prop : Props)
        {
            prop.Render(Knight.GetWorldPosition());
            if (CheckCollisionRecs(prop.GetCollisionRec(Knight.GetWorldPosition()), Knight.GetCollisionRec()))
            {
                Knight.UndoMovement();
            }
        }

        // Draw Goblins
        for (Enemy& goblin : Goblins)
        {
            goblin.Tick(GetFrameTime());
        }

        // Draw Character
        Knight.Tick(GetFrameTime());

        EndDrawing();
    }

    CloseWindow();
}