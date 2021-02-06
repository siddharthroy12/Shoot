#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "../screens/GameScreen.hpp"

Bullet::Bullet(Node* parent) : Node(parent) {
    Player* tmp = (Player*) parent->getChildren("Player");
    
    hitbox.x = tmp->getPosition().x - (size / 2);
    hitbox.y = tmp->getPosition().y - (size / 2);
    direction = tmp->head;
}

void Bullet::render() {
    DrawRectangleRec(hitbox, { 34, 32, 52, 255 });
}

void Bullet::update() {
    hitbox.x += direction.x * speed;
    hitbox.y += direction.y * speed;

    if (
        (this->hitbox.x < -20) ||
        (this->hitbox.x > (SCREEN_WIDTH + 20)) ||
        (this->hitbox.y < -20) ||
        (this->hitbox.y > (SCREEN_HEIGHT + 20))
        ) {
        this->deleteThis();
    }

    for (Node* child : parent->childrens) {
        if (child != NULL) {
            if (child->name() == "Enemy") {
                Enemy* tmp = (Enemy*) child;
                if (CheckCollisionRecs(this->hitbox, tmp->hitbox)) {
                    ((GameScreen*) parent)->kills++;
                    child->deleteThis();
                    this->deleteThis();
                }
            }
        }
    }
}

Bullet::~Bullet() {
}