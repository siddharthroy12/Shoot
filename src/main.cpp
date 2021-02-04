#include "raylib.h"
#include "Globals.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <vector>
#include <iostream>
#include <cmath>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    SetTraceLogLevel(LOG_NONE);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shoot!");

    Player* player = new Player();
    std::vector<Enemy*> enemies;
    enemies.push_back(new Enemy());

    float tmp;
    bool showDebug = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_G)) {
            showDebug = !showDebug;
        }
        if (IsKeyPressed(KEY_K)) {
            enemies.push_back(new Enemy());
        }
        if (IsKeyDown(KEY_W)) {
            player->moveUp();
        }
        if (IsKeyDown(KEY_S)) {
            player->moveDown();
        }
        if (IsKeyDown(KEY_D)) {
            player->moveRight();
        }
        if (IsKeyDown(KEY_A)) {
            player->moveLeft();
        }

        if (player->getPosition().x < ((player->hitbox.width/2))) {
            player->setPosition({ ((player->hitbox.width/2)), player->getPosition().y });
        }
        
        if (player->getPosition().x > (SCREEN_WIDTH - (player->hitbox.width/2))) {
            player->setPosition({ (SCREEN_WIDTH - (player->hitbox.width/2)), player->getPosition().y });
        }

        if (player->getPosition().y > (SCREEN_HEIGHT - (player->hitbox.height/2))) {
            player->setPosition({ player->getPosition().x, (SCREEN_HEIGHT - (player->hitbox.height/2)) });
        }

        if (player->getPosition().y < ((player->hitbox.height/2))) {
            player->setPosition({ player->getPosition().x, ((player->hitbox.height/2)) });
        }

        for (Enemy* e : enemies) {
            if (CheckCollisionRecs(player->hitbox, e->hitbox)) {
                //std::cout << "Collide" << std::endl;
            }
        }
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (Enemy* e : enemies) {
                e->render(player->getPosition());
            }

            player->render();
            
            tmp = atan2(GetMousePosition().y - player->getPosition().y, GetMousePosition().x - player->getPosition().x);
            player->rotation = (tmp * 180 / PI) + 90;
            
            if (showDebug) {
                DrawRectangleLinesEx(player->hitbox, 2, RED);
                for (Enemy* e : enemies) {
                    DrawRectangleLinesEx(e->hitbox, 2, RED);
                }
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    for (Enemy* e : enemies) {
        delete e;
    }
    delete player;
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}