#ifndef BULLET_HPP
#define BULLET_HPP

#include "raylib.h"
#include "../Node.hpp"
#include <string>

class Bullet : public Node {
    int size = 10;
    int speed = 20;
    Vector2 direction = { 0.0f, 0.0f };

    public:
        char* name() { return "Bullet"; }
        Rectangle hitbox = { 0.0f, 0.0f, size, size };
        void render();
        void update();
        Bullet(Node* parent);
        ~Bullet();
};

#endif