#include "LinkedList.h"
#include "Node.h"
#include "Logger.h"
#include <iostream>

extern Logger logger;

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;

    logger.log(LogLevel::DEBUG, "LinkedList default constructor called.");
}

// ✅ Copy Constructor: Creates a deep copy of another LinkedList
LinkedList::LinkedList(const LinkedList& list)
{
    head = tail = nullptr;
    Node* temp = list.head;
    while (temp)
    {
        insert(temp->data);
        temp = temp->next;
    }

    logger.log(LogLevel::DEBUG, "LinkedList copy constructor called.");
}

// ✅ Parameterized Constructor: Initializes LinkedList from an array
LinkedList::LinkedList(int arr[], int size)
{
    head = tail = nullptr;
    for (int i = 0; i < size; i++)
    {
        insert(arr[i]);
    }

    logger.log(LogLevel::DEBUG, "LinkedList parameterized constructor called.");
}

// ✅ Assignment Operator Overload
LinkedList& LinkedList::operator=(const LinkedList& list)
{
    if (this != &list)  // ✅ Standard self-assignment check
    {
        clear();  // Free existing list

        Node* temp = list.head;
        while (temp)
        {
            insert(temp->data);
            temp = temp->next;
        }

        logger.log(LogLevel::DEBUG, "LinkedList assignment operator called.");
    }

    return *this;
}

// ✅ Destructor: Clears all nodes
LinkedList::~LinkedList()
{
    clear();

    logger.log(LogLevel::DEBUG, "LinkedList destructor called.");
}

// ✅ Insert a new node at the end of the list
void LinkedList::insert(int x)
{
    Node* temp = new Node(x);
    if (head == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

// ✅ Remove a node with value `x`, logs output via parameter
void LinkedList::remove(int x)
{
    if (!head)
    {
        logger.log(LogLevel::ERROR, "Attempting to remove from an empty list.");
        return;
    }

    if (head->data == x)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        if (!head)
        {
            tail = nullptr;
        }
        return;
    }

    Node* prev = head;
    Node* cur = head->next;

    while (cur)
    {
        if (cur->data == x)
        {
            prev->next = cur->next;

            if (cur == tail)
            {
                tail = prev;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    logger.log(LogLevel::WARNING, "Element not found: " + std::to_string(x));
}

// ✅ Clears all nodes in the list
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
}

// ✅ Getter for head
Node* LinkedList::getHead() const
{
    return head;
}

// ✅ Getter for tail
Node* LinkedList::getTail() const
{
    return tail;
}