#include "BST.h"
#include "Node.h"
#include "NodeInterface.h"

using namespace std;

NodeInterface * BST::getRootNode() const {
    return root;
}

bool BST::add(int data) {
    add_node(root, data);
}

bool BST::add_node(Node* n, int value) {
    if(n == NULL) {
        n = new Node(value);
        return true;
    }

    if(n->data > value) {
        return add_node(n->leftChild, value);
    }

    if(n->data < value) {
        return add_node(n->rightChild, value);
    }

    return false;
}

bool BST::remove(int data) {
    remove_node(root, data);
}

bool BST::remove_node(Node* n, int value) {
    if (n == NULL)
    {
      return false;
    }

    if (n->data > value)
    {
      return remove_node(n->leftChild, value);
    }

    if (n->data < value)
    {
      return remove_node(n->rightChild, value);
    }

    if (n->rightChild == NULL && n->leftChild == NULL) //No next of kin
    {
      delete n;
      n = NULL;
      return true;
    }

    if (n->rightChild == NULL || n->leftChild == NULL) //one child
    {
      Node* temp;
      temp = n->leftChild;
      if (n->leftChild == NULL)
      {
        temp = n->rightChild;
      }
      delete n;
      n = temp;
      return true;
    }

    Node* temp = n->leftChild;
    Node* parent = n;

    while(temp->rightChild != NULL) {
      parent = temp;
      temp = temp->rightChild;
    }

	if (n->data != parent->data) {
        parent->rightChild = temp->leftChild;
	}
	else parent->leftChild = temp->leftChild;

	n->data = temp->data;
    delete temp;
    return true;
}

void BST::clear() {
    clear_tree(root);
    root = NULL;
}

void BST::clear_tree(Node* n) {
    if (n == NULL)
    {
      return;
    }

    if (n->leftChild != NULL)
    {
        clear_tree(n->leftChild);
    }

    if (n->rightChild != NULL)
    {
      clear_tree(n->rightChild);
    }

    delete n;
}