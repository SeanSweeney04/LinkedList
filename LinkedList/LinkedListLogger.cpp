#include "LinkedListLogger.h"

// ? Constructor stores reference to LinkedList
LinkedListLogger::LinkedListLogger(LinkedList& list) : list(list) {}

// ? Instance-based print method (no static keyword)
void LinkedListLogger::print() 
{
    Node* temp = list.head;  // ? Access head directly (LinkedList is a friend class)
    while (temp != nullptr) 
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}