#ifndef LINKEDLISTLOGGER_H
#define LINKEDLISTLOGGER_H

#include "LinkedList.h"
#include <iostream>

class LinkedList;
class LinkedListLogger
{
public:
    explicit LinkedListLogger(LinkedList& list);
    void print();

private:
    LinkedList& list;
};

#endif