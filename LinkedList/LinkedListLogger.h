#ifndef LINKEDLISTLOGGER_H
#define LINKEDLISTLOGGER_H

#include "LinkedList.h"
#include <iostream>

class LinkedListLogger
{
public:
    explicit LinkedListLogger(const LinkedList& list);
    std::string toString() const;

private:
    const LinkedList* list;
};

#endif