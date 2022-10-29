#include "Node.h"
#include <iostream>

int Node::getData() const {
    return data;
}

NodeInterface * Node::getLeftChild() const {
    return leftChild;
}

NodeInterface * Node::getRightChild() const {
    return rightChild;
}