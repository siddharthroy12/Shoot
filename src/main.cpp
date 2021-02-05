#include "raylib.h"
#include "Globals.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include <vector>
#include <iostream>
#include <cmath>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    SetTraceLogLevel(LOG_TRACE);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shoot!");

    Player* player = new Player();
    std::vector<Enemy*> enemies;
    std::vector<Bullet*> bullets;
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
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bullets.push_back(new Bullet(player->getPosition(), player->head));
        }
        if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            bullets.push_back(new Bullet(player->getPosition(), player->head));
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
            if (e != NULL) {
                if (CheckCollisionRecs(player->hitbox, e->hitbox)) {
                //std::cout << "Collide" << std::endl;
                }
            }
        }

        if (bullets.size() > 0) {
            for (Bullet*& b : bullets) {
                if (b != NULL) {
                    for (Enemy*& e : enemies) {
                        if (e != NULL) {
                            if (b != NULL ) {
                                if (CheckCollisionRecs(b->hitbox, e->hitbox)) {
                                    delete e;
                                    e = NULL;
                                    delete b;
                                    b = NULL;
                                }
                            }
                            
                        }
                    }
                }
            }
        }
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (Enemy* e : enemies) {
                if (e != NULL) {
                    e->render(player->getPosition());
                }   
            }

            if (bullets.size() > 0) {
                for (Bullet* b : bullets) {
                    if (b != NULL) {
                        b->render();
                    }
                }
            }

            player->render();
            
            tmp = atan2(GetMousePosition().y - player->getPosition().y, GetMousePosition().x - player->getPosition().x);
            player->rotation = (tmp * 180 / PI) + 90;
            
            if (showDebug) {
                DrawRectangleLinesEx(player->hitbox, 2, RED);
                for (Enemy* e : enemies) {
                    if (e != NULL) {
                        DrawRectangleLinesEx(e->hitbox, 2, RED);
                    }
                }
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    for (Enemy* e : enemies) {
        if (e != NULL) {
            delete e;
        }
    }
    for (Bullet* b : bullets) {
        if (b != NULL) {
            delete b;
        }
    }
    delete player;
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}