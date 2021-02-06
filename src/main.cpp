#include "raylib.h"
#include "Globals.hpp"
#include "./context/GlobalContext.hpp"
#include "Node.hpp"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    SetTraceLogLevel(LOG_NONE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shoot!");
    SetExitKey(0);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    initGlobalState();
    //---------------------------------------------------------------------------------------



    // Main game loop
    while ((!WindowShouldClose()) && globalState != NULL)    // Detect window close button or ESC key
    {
        BeginDrawing();
            globalState->rootNode->updateAndRender();
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    cleanGlobalState();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}