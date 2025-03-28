#include "LinkedListLogger.h"
#include "Logger.h"
#include <iostream>

LinkedListLogger::LinkedListLogger(const LinkedList& list)
{
    this->list = &list;  // Store a pointer instead of a reference
}

std::string LinkedListLogger::toString() const
{
    if (!list) 
    {
        return "[ERROR] LinkedListLogger is referencing a null LinkedList.";
    }

    Node* temp = list->getHead();
    if (!temp)
    {
        return "List is empty.";
    }

    std::string output = "List contents: ";
    while (temp)
    {
        output += std::to_string(temp->data) + " ";
        temp = temp->next;
    }

    return output;
}