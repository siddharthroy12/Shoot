#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "../Node.hpp"
#include <string>

class GameScreen : public Node {
    private:
    public:
        int kills = 0;
        std::string name = "GameScreen";
        GameScreen(Node *parent);
        ~GameScreen();
        void render();
        void update();
        void pause();
};

#endif