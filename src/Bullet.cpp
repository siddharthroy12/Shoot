#include "Bullet.hpp"

Bullet::Bullet(Vector2 pos, Vector2 dir) {
    hitbox.x = pos.x - (size / 2);
    hitbox.y = pos.y - (size / 2);
    direction = dir;
}

void Bullet::render() {
    DrawRectangleRec(hitbox, BLACK);
    hitbox.x += direction.x * speed;
    hitbox.y += direction.y * speed;
}

Bullet::~Bullet() {
    
}