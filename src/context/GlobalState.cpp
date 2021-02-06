#include "GlobalState.hpp"
#include "../screens/GameScreen.hpp"

GlobalState::GlobalState() {
    this->rootNode = new GameScreen(NULL);
}

GlobalState::~GlobalState() {
    delete rootNode;
    rootNode = NULL;
}