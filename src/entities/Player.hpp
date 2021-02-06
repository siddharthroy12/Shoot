#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "../Globals.hpp"
#include "../Node.hpp"
#include <string>

class Player : public Node {
    Texture texture;
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
    Vector2 position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    int speed = 5;
    
    public:
        char* name() { return "Player"; }
        Vector2 head = { 1.0f, 1.0f };
        Player(Node* parent);
        ~Player();
        Rectangle hitbox;
        int rotation = 0;
        void render();
        void update();
        Vector2 getPosition();
        void setPosition(Vector2 position);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};

#endif