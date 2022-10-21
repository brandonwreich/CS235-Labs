#include "LinkedListInterface.h"

template<typename T>
class LinkedList : public LinkedListInterface {
    struct Node {
        T item;
        Node* next;
    };

private:
    Node* head;
    Node* tail;
    int size;

public:
    void insertHead(T value) {
        Node newNode = new Node(value);

        newNode.next = head;
        head = newNode;
    }

    void insertTail(T value) {
        Node newNode = new Node(value);

        if(head==NULL) {
            head = new Node(value);
            return;
        }

        tail->next = newNode;
        tail = newNode;

    }

    void insertAfter(T value, T insertionNode) {
        if(insertionNode == NULL) {
            std::cout << "Previous value needed" << std::endl;
            return;
        }

        Node newNode = new Node(value);
        newNode.next = insertionNode.next;
        insertionNode.next = newNode;



    }

    void remove(T value) {

    }

    void clear(T value) {

    }

    T at(int index) {
        return NULL;
    }

    int size() {
        
    }

    string toString() {
        return "";
    }
};