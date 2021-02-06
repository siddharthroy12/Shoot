#include "Node.hpp"

Node::Node(Node *parent) {
    this->parent = parent;
}

void Node::pause() {

}

void Node::_pause() {
    this->pause();
    for (Node* child : this->childrens) {
        if (child != NULL) {
            child->_pause();
        }
    }
}

void Node::_render() {
    this->render();
    for (Node* child : this->childrens) {
        if (child != NULL) {
            child->_render();
        }
    }
}

Node* Node::updateAndRender() {
    if (deleteOnNextRender) {
        delete this;
        return NULL;
    }

    if (this->paused) {
        this->_pause();
        this->_render();
    } else {
        this->update();
        this->render();

        for (Node*& child : this->childrens) {
            if (child != NULL) {
                child = child->updateAndRender();
            }
        }
    }

    return this;
}

Node* Node::getChildren(char* name) {
    for (Node* child : this->childrens) {
        if (child != NULL) {
            if (child->name() == name) {
                return child;
            }
        }   
    }
    return NULL;
}

void Node::deleteThis() {
    this->deleteOnNextRender = true;
}

Node::~Node() {
    for (Node*& child : this->childrens) {
        if (child != NULL) {
            delete child;
            child = NULL;
        }
    }
}