#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList& list);
    LinkedList(int arr[], int size);
    LinkedList& operator=(const LinkedList& list);
    ~LinkedList();

    void insert(int x);
    void remove(int x);
    Node* getHead() const;
    Node* getTail() const;

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    void clear();
};

#endif