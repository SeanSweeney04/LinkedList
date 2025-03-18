#include <iostream>
#include <cstddef> 

#include "LinkedList.h"
#include "Node.h"
#include "Logger.h"

using namespace std;

// Node class constructor: Initializes a node with given data and sets next to nullptr
Node::Node(int x)
{
    data = x;
    next = nullptr;
}

// Getter for head
Node* LinkedList::getHead() const
{
    return head;
}

//Getter for tail
Node* LinkedList::getTail() const
{
    return tail;
}

// Default constructor for LinkedList: Initializes head and tail as nullptr
LinkedList::LinkedList(Logger& logger) : _logger(logger)
{
    head = tail = nullptr;
    logger.log(LogLevel::INFO, "LinkedList created.");
}

// Copy constructor: Creates a deep copy of the given LinkedList
LinkedList::LinkedList(const LinkedList& list, Logger& logger) : _logger(logger) 
{
    head = tail = nullptr;
    Node* temp = list.head;
    while (temp) 
    {
        insert(temp->data);
        temp = temp->next;
    }
    logger.log(LogLevel::INFO, "Copy Constructor called.");
}

LinkedList::LinkedList(int arr[], int size, Logger& logger) : _logger(logger)
{
    head = tail = nullptr;
    for (int i = 0; i < size; i++) 
    {
        insert(arr[i]);
    }
    logger.log(LogLevel::INFO, "LinkedList created using parameterized constructor.");
}

// Assignment Operator Overload
LinkedList& LinkedList::operator=(const LinkedList& list)
{
    if (this == &list) 
    {
        return *this;  // Avoid self-assignment
    }

    _logger.log(LogLevel::INFO, "Assignment Operator called.");

    // Clear existing list
    clear();

    // Copy from the given list
    Node* temp = list.head;
    while (temp) 
    {
        insert(temp->data);
        temp = temp->next;
    }

    return *this;
}

// Destructor: Deletes all nodes to free memory
LinkedList::~LinkedList()
{
    _logger.log(LogLevel::INFO, "Destructor called.");
    clear();
}

// Function to insert a new node with value 'x' at the end of the list
void LinkedList::insert(int x)
{
    _logger.log(LogLevel::INFO, "Inserting: " + std::to_string(x));
    Node* temp = new Node(x);
    if (head == NULL) 
    {
        head = temp;
        return;
    }
    else {
        Node* t = head;
        while (t->next != NULL) 
        {
            t = t->next;
        }
        t->next = temp;
    }
}

// Function to remove the first occurrence of node with value 'x'
void LinkedList::remove(int x)
{
    if (!head)
    {
        _logger.log(LogLevel::WARNING, "Attempted to remove from an empty list.");
        return;
    }

    // If the node to be deleted is the head
    if (head->data == x)
    {
        _logger.log(LogLevel::INFO, "Removing head: " + std::to_string(x));
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;
    Node* cur = head->next;

    // Traverse the list to find the node with value 'i'
    while (cur)
    {
        if (cur->data == x)
        {
            _logger.log(LogLevel::INFO, "Removing: " + std::to_string(x));
            prev->next = cur->next; // Bypass the node
            if (cur == tail)
            {
                tail = prev; // Update tail if needed
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    _logger.log(LogLevel::WARNING, "Element not found: " + std::to_string(x));
}

// Helper function to clear the list (used in destructor and operator=)
void LinkedList::clear()
{
    Node* cur = head;
    while (cur) 
    {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    head = tail = nullptr;
};