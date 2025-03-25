#include "LinkedList.h"
#include "Node.h"
#include "Logger.h"
#include <iostream>

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    Logger::log(DEBUG, "LinkedList default constructor called.");
}

// Copy Constructor: Creates a deep copy of another LinkedList
LinkedList::LinkedList(const LinkedList& list)
{
    head = tail = nullptr;
    Node* temp = list.head;
    while (temp)
    {
        insert(temp->data);
        temp = temp->next;
    }

    Logger::log(DEBUG, "LinkedList copy constructor called.");
}

// Parameterized Constructor: Initializes LinkedList from an array
LinkedList::LinkedList(int arr[], int size)
{
    head = tail = nullptr;
    for (int i = 0; i < size; i++)
    {
        insert(arr[i]);
    }

    Logger::log(DEBUG, "LinkedList parametrized constructor called.");
}

// Assignment Operator Overload
LinkedList& LinkedList::operator=(const LinkedList& list)
{
    if (this != &list)  // Standard self-assignment check
    {
        clear();  // Free existing list

        Node* temp = list.head;
        while (temp)
        {
            insert(temp->data);
            temp = temp->next;
        }
    }

    Logger::log(DEBUG, "LinkedList operator constructor called.");

    return *this;
}

// Destructor: Clears all nodes
LinkedList::~LinkedList()
{
    clear();
    Logger::log(DEBUG, "LinkedList destructor called.");
}

// Insert a new node at the end of the list
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

// Remove a node with value `x`, logs output via parameter
void LinkedList::remove(int x)
{
    if (!head)
    {
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
            break;
        }
        prev = cur;
        cur = cur->next;
    }
}

// Clears all nodes in the list
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

// Getter for head
Node* LinkedList::getHead() const
{
    return head;
}

// Getter for tail
Node* LinkedList::getTail() const
{
    return tail;
}