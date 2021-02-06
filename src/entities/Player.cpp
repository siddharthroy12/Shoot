#include "../Globals.hpp"
#include "Player.hpp"
#include <cmath>

Player::Player(Node* parent) : Node(parent) {
    this->texture = LoadTexture("assets/player.png");
    this->sourceRec = { 0.0f, 0.0f, texture.width, texture.height };
    this->destRec = { this->position.x, this->position.y, texture.width*5, texture.height*5};
    this->origin = { (texture.width*5) /2, (texture.height*5)/2 };
    this->hitbox = { this->position.x - ((texture.width*3) / 2), this->position.y - ((texture.height*3) /2), texture.width*3, texture.height*3};
}

void Player::render() {
    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, WHITE);
}

void Player::update() {
    float tmp = atan2(GetMousePosition().y -position.y, GetMousePosition().x - position.x);
    rotation = (tmp * 180 / PI) + 90;
    this->head.x = cos(tmp);
    this->head.y = sin(tmp);

    if (IsKeyDown(KEY_W)) {
        this->moveUp();
    }
    if (IsKeyDown(KEY_S)) {
        this->moveDown();
    }
    if (IsKeyDown(KEY_D)) {
        this->moveRight();
    }
    if (IsKeyDown(KEY_A)) {
        this->moveLeft();
    }

    if (this->getPosition().x < ((this->hitbox.width/2))) {
        this->setPosition({ ((this->hitbox.width/2)), this->getPosition().y });
    }
        
    if (this->getPosition().x > (SCREEN_WIDTH - (this->hitbox.width/2))) {
        this->setPosition({ (SCREEN_WIDTH - (this->hitbox.width/2)), this->getPosition().y });
    }

    if (this->getPosition().y > (SCREEN_HEIGHT - (this->hitbox.height/2))) {
        this->setPosition({ this->getPosition().x, (SCREEN_HEIGHT - (this->hitbox.height/2)) });
    }

    if (this->getPosition().y < ((this->hitbox.height/2))) {
        this->setPosition({ this->getPosition().x, ((this->hitbox.height/2)) });
    }
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