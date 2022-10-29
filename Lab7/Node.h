#pragma once
#include "NodeInterface.h"

class Node : public NodeInterface {
    public:
        Node * leftChild;
        Node * rightChild;
        int data;

        Node(int value) {
            data = value;
            leftChild = NULL;
            rightChild = NULL;
        }

        ~Node() {}

        int getData() const;
        NodeInterface * getLeftChild() const;
        NodeInterface * getRightChild() const;
};