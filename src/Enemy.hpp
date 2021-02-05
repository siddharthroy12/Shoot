#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "raylib.h"
#include "Globals.hpp"

class Enemy {
    Texture texture;
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
    Vector2 position = { 0.0f, 0.0f };
    int speed = 2;
    int rotation = 0;
    Vector2 head = { 1.0f, 1.0f };

    public:
        Enemy();
        ~Enemy();
        Rectangle hitbox;
        void render(Vector2 playerPosition);
        Vector2 getPosition();
        void setPosition(Vector2 position);
};

#endif