#include "LinkedListLogger.h"
#include <iostream>

LinkedListLogger::LinkedListLogger(LinkedList& list)
{
    this->list = &list;  // ✅ Store a pointer instead of a reference
}

void LinkedListLogger::print()
{
    if (list == nullptr)
    {
        std::cout << "Error: LinkedListLogger is referencing a null LinkedList." << std::endl;
        return;
    }

    Node* temp = list->getHead();

    if (temp == nullptr)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}