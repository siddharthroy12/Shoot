#include "Globals.hpp"
#include "Enemy.hpp"
#include <cmath>
#include <iostream>

Enemy::Enemy() {
    this->texture = LoadTexture("assets/enemy.png");
    this->sourceRec = { 0.0f, 0.0f, texture.width, texture.height };
    this->destRec = { this->position.x, this->position.y, texture.width*5, texture.height*5};
    this->origin = { (texture.width*5) /2, (texture.height*5)/2 };
    this->hitbox = { this->position.x - ((texture.width*3) / 2), this->position.y - ((texture.height*3) /2), texture.width*3, texture.height*3};
    std::cout << speed << std::endl;
}

void Enemy::render(Vector2 playerPosition) {
    float tmp = atan2(playerPosition.y -position.y, playerPosition.x - position.x);
    rotation = (tmp * 180 / PI) + 90;
    this->head.x = cos(tmp);
    this->head.y = sin(tmp);
    this->setPosition({ this->getPosition().x + (head.x * speed), this->getPosition().y + (head.y * speed) });
    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, WHITE);
}

Vector2 Enemy::getPosition() { return this-> position; }

void Enemy::setPosition(Vector2 position) {
    this->position = position;
    this->destRec = { this->position.x, this->position.y, texture.width*5, texture.height*5};
    this->hitbox = { this->position.x - ((texture.width*3) / 2), this->position.y - ((texture.height*3) /2), texture.width*3, texture.height*3};
}

Enemy::~Enemy() {
    UnloadTexture(this->texture);
}