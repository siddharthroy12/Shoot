#ifndef BULLET_HPP
#define BULLET_HPP

#include "raylib.h"

class Bullet {
    int size = 10;
    int speed = 20;
    Vector2 direction = { 0.0f, 0.0f };

    public:
        Rectangle hitbox = { 0.0f, 0.0f, size, size };
        void render();
        Bullet(Vector2 pos, Vector2 dir);
        ~Bullet();
};

#endif