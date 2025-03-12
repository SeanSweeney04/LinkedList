#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

#include "Node.h"

class LinkedList {

private:
    Node* head = NULL;
    Node* tail = NULL;

public:
    LinkedList();
    LinkedList(const LinkedList& list);
  
    void insert(int x);
    void remove(int x);
    void print();
   
    ~LinkedList();
};

#endif

