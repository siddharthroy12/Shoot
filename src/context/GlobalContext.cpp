#include "GlobalState.hpp"

GlobalState* globalState;

void initGlobalState() {
    globalState = new GlobalState();
}

void cleanGlobalState() {
    delete globalState;
    globalState = NULL;
}