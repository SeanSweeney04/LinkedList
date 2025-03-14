#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef> 
#include "Node.h"
#include "Logger.h"
#include "LinkedListLogger.h"

class LinkedList
{

public:
    LinkedList(Logger& logger);
    LinkedList(const LinkedList& list, Logger& logger);
    LinkedList(int arr[], int size, Logger& logger);
    LinkedList& operator=(const LinkedList& list);

    void insert(int x);
    void remove(int x);


    ~LinkedList();

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    void clear();
    Logger& logger;
    friend class LinkedListLogger;
};

#endif
