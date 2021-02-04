#include "Globals.hpp"
#include "Player.hpp"

Player::Player() {
    this->texture = LoadTexture("assets/player.png");
    this->sourceRec = { 0.0f, 0.0f, texture.width, texture.height };
    this->destRec = { this->position.x, this->position.y, texture.width*5, texture.height*5};
    this->origin = { (texture.width*5) /2, (texture.height*5)/2 };
    this->hitbox = { this->position.x - ((texture.width*3) / 2), this->position.y - ((texture.height*3) /2), texture.width*3, texture.height*3};
}

void Player::render() {
    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, WHITE);
}

Vector2 Player::getPosition() { return this-> position; }

void Player::setPosition(Vector2 position) {
    this->position = position;
    this->destRec = { this->position.x, this->position.y, texture.width*5, texture.height*5};
    this->hitbox = { this->position.x - ((texture.width*3) / 2), this->position.y - ((texture.height*3) /2), texture.width*3, texture.height*3};
}

void Player::moveUp() {
    this->position.y -= this->speed;
    this->setPosition(this->position);
}
void Player::moveDown() {
    this->position.y += this->speed;
    this->setPosition(this->position);
}

void Player::moveRight() {
    this->position.x += this->speed;
    this->setPosition(this->position);
}
void Player::moveLeft() {
    this->position.x -= this->speed;
    this->setPosition(this->position);
}

Player::~Player() {
    UnloadTexture(this->texture);
}