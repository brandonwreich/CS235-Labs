#include "Node.h"
#include "BSTInterface.h"

class BST : public BSTInterface {
    protected:
        Node * root;

    public:
        BST() {root = NULL;};
        ~BST() {clear();};

        NodeInterface * getRootNode() const;
        bool add(int data);
        bool add_node(Node*& n, int value);
        bool remove(int data);
        bool remove_node(Node*& n, int value);
        void clear();
        void clear_tree(Node* n);
};