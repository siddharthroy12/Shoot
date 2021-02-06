#include "GameScreen.hpp"
#include "../entities/Player.hpp"
#include "../entities/Enemy.hpp"
#include "../entities/Bullet.hpp"
#include <string>

GameScreen::GameScreen(Node *parent) : Node(NULL) {
    childrens.push_back(new Player(this));
}

void GameScreen::update() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        this->paused = true;
    }

    if (IsKeyPressed(KEY_K)) {
        this->childrens.push_back(new Enemy(this));
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        this->childrens.push_back(new Bullet(this));
    }
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        this->childrens.push_back(new Bullet(this));
    }

    if (GetRandomValue(0, 30) == 0) {
        this->childrens.push_back(new Enemy(this));
    }

}

void GameScreen::render() {
    ClearBackground(WHITE);

    DrawText(std::to_string(this->kills).c_str(), 6, 30, 30, RED);
}

void GameScreen::pause() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        this->paused = false;
    }
}

GameScreen::~GameScreen() {
}
