#ifndef SCREEN_HPP
#define SCREEN_HPP

class Screen {
    public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual ~Screen() { };
};

#endif