#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "raylib.h"
#include "../Globals.hpp"
#include "../Node.hpp"
#include <string>

class Enemy : public Node {
    Texture texture;
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
    Vector2 position = { 0.0f, 0.0f };
    int speed = 2;
    int rotation = 0;
    Vector2 head = { 1.0f, 1.0f };

    public:
        Enemy(Node* parent);
        char* name() { return "Enemy"; }
        ~Enemy();
        Rectangle hitbox;
        void render();
        void update();
        Vector2 getPosition();
        void setPosition(Vector2 position);
};

#endif