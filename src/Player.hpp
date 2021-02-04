#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "Globals.hpp"

class Player {
    Texture texture;
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
    Vector2 position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    int speed = 3;
    
    public:
        Player();
        ~Player();
        Rectangle hitbox;
        int rotation = 0;
        void render();
        Vector2 getPosition();
        void setPosition(Vector2 position);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};

#endif