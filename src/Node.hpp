#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

class Node {
    private:
        bool deleteOnNextRender = false;
    public:
    virtual void pause();
    virtual void update() = 0;
    virtual void render() = 0;
    void _pause();
    void _update();
    void _render();
    
    Node(Node *parent);
    void deleteThis();
    bool paused = false;
    virtual char* name() { return "Node"; }
    std::vector<Node*> childrens;
    Node* getChildren(char *name);
    Node* parent;
    
    virtual ~Node();
    Node* updateAndRender();
};

#endif