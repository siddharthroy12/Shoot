#ifndef GLOBAL_CONTEXT_HPP
#define GLOBAL_CONTEXT_HPP

#include "GlobalState.hpp"

extern GlobalState* globalState;

extern void initGlobalState();

extern void cleanGlobalState();

#endif