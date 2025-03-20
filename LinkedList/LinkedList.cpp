#include "LinkedList.h"
#include "Node.h"
#include <iostream>

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;

    std::cout << "[DEBUG] LinkedList default constructor called." << std::endl;
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

    std::cout << "[DEBUG] LinkedList copy constructor called." << std::endl;
}

// ✅ Parameterized Constructor: Initializes LinkedList from an array
LinkedList::LinkedList(int arr[], int size)
{
    head = tail = nullptr;
    for (int i = 0; i < size; i++)
    {
        insert(arr[i]);
    }

    std::cout << "[DEBUG] LinkedList parameterized constructor called." << std::endl;
}

// ✅ Assignment Operator Overload
LinkedList& LinkedList::operator=(const LinkedList& list)
{
    if (this == &list)
    {
        return *this;  // Avoid self-assignment
    }

    clear();  // Free existing list

    Node* temp = list.head;
    while (temp)
    {
        insert(temp->data);
        temp = temp->next;
    }

    std::cout << "[DEBUG] LinkedList assignment operator called." << std::endl;

    return *this;
}

// ✅ Destructor: Clears all nodes
LinkedList::~LinkedList()
{
    clear();

    std::cout << "[DEBUG] LinkedList destructor called." << std::endl;
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
        std::cerr << "Warning: Attempted to remove from an empty list." << std::endl;
        return;
    }

    if (head->data == x)
    {
        std::cout << "Removing head: " << x << std::endl;
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
            std::cout << "Removing: " << x << std::endl;
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

    std::cerr << "Warning: Element not found: " << x << std::endl;
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