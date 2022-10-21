#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinkedListInterface.h"
using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
public:
    class Node {
    public:
        T data;
        Node *next;

        Node(T value) {
            data = value;
            next = NULL;
        }
    };

    int listSize;
    Node *head;
    Node *tail;

    LinkedList(void) {
        listSize = 0;
        head = NULL;
        tail = NULL;
    };

    virtual ~LinkedList(void) {
        clear();
        };

	void insertHead(T value) {
        Node *newNode = new Node(value);

        if(listSize == 0) {
            newNode->next = NULL;
            head = newNode;
            tail = newNode;

            listSize++;
            return;
        }
        if(!checkList(value)) {
            newNode->next = head;
            head = newNode;

            listSize++;
        }
    }

	void insertTail(T value) {
        Node *newNode = new Node(value);

        if(listSize == 0) {
            newNode->next = NULL;
            head = newNode;
            tail = newNode;

            listSize++;
            return;
        }

        if(!checkList(value)) {
            tail->next = newNode;
            tail = newNode;
            newNode->next = NULL;

            listSize++;
        }
    }

	void insertAfter(T value, T insertionNode) {
        if(listSize == 0) {
            return;
        }

        Node *newNode = new Node(value);
        Node *current = head;

        if(!checkList(value)) {
            while(current->next != NULL) {
                if(current->data == insertionNode) {
                    newNode->next = current->next;
                    current->next = newNode;

                    listSize++;
                    return;
                }

                current = current->next;
            }

            if(current == tail && current->value == insertionNode) {
                tail->next = newNode;
                newNode->next = NULL;
                tail = newNode;

                listSize++;
                return;
            }
        }

    }

	void remove(T value) {
        Node *current = head;
        Node *previous = NULL;

        if(listSize == 0) {
            return;
        }

        if(checkList(value)) {
            while(current->next != NULL) {
                if(current->data == value) {
                    if(head == current) {
                        head = head->next;

                        delete current;
                        listSize--;
                        return;
                    }

                    previous->next = current->next;

                    delete current;
                    listSize--;
                    return;
                }

                previous = current;
                current = current->next;
            }

            if (listSize == 1) {
                previous == current;
            }

            tail = previous;
            tail->next = NULL;

            delete current;
            listSize--;

            if(listSize == 0) {
                head = NULL;
                tail = NULL;
            }
        }
    }

	void clear() {
        Node *current = head;
        Node *previous = NULL;

        if(listSize == 0) {
            return;
        }

        while(current->next != NULL) {
            previous = current;
            current = current->next;

            delete previous;
        }

        delete current;

        head = NULL;
        tail = NULL;
        listSize = 0;
    }

	T at(int index) {
        Node *current = head;

        if(index >= listSize || index < 0) {
            throw out_of_range;
        }

        for(int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

	int size() {
        return listSize;
    }

	string toString() {
        stringstream ss;
        Node *current = head;

        if(listSize == 0){
            return ss.str();
        }

        while(current->next != NULL) {
            ss << " " << current->data;
            current = current->next;
        }

        ss << " " << current->data;

        return ss.str();
    }

    bool checkList(T value) {
        Node* current = head;

        while(current->value != value) {
            if(current->next == NULL) {
                return false;
            }

            current = current->next;
        }

        return true;
    }
};
