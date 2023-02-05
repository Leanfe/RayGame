#include <raylib.h>
#include <string>

#include "ui/ResizeHelper.h"

using namespace std;
using namespace UI;

int main()
{
    // Initialize window and set screen width and height
    int screenWidth = 2560;
    int screenHeight = 1440;

    InitWindow(screenWidth, screenHeight, "Hello world");

    // Calculate the position of the string "Hello world"

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    ToggleFullscreen();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw "Hello world" in the center of the screen
        BeginDrawing();
        ClearBackground(RAYWHITE);


        Vector2 pos = ResizeHelper().getCenterForMessage(screenWidth, screenHeight, "Hello world");
        DrawText("Hello world", pos.x, pos.y, 20, BLACK);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
