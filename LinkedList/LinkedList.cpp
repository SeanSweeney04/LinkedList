// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "Logger.h"
using namespace std;

// Node class constructor: Initializes a node with given data and sets next to NULL

Node::Node(int x)
{
    data = x;
    next = NULL;
}

// Default constructor for LinkedList: Initializes head and tail as NULL
LinkedList:: LinkedList() { 
    head = tail = NULL; 
    Logger::log(LogLevel::INFO, "LinkedList created.");
}

// Copy constructor: Creates a deep copy of the given LinkedList
LinkedList::LinkedList(const LinkedList& list)
{
    Logger::log(LogLevel::INFO, "Copy Constructor called.");
    // If the original list is empty, set head and tail to NULL   
    if (list.head == NULL) {
        this->head = this->tail = NULL;
        return;
    }
    Node* temp = list.head;
    // Traverse the original list and copy each node
    while (temp != NULL) {
        Node* newNode = new Node(temp->data);

        if (head == NULL) { // If the new list is empty, set head and tail to the first node
            head = newNode;
            tail = newNode;
        }
        else { // Append the new node at the end
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }
}
// Function to insert a new node with value 'x' at the end of the list
void LinkedList::insert(int x)
{
    Logger::log(LogLevel::INFO, "Inserting: " + std::to_string(x));
    Node* temp = new Node(x);
    // If the list is empty, set the new node as head

    if (head == NULL) {
        head = temp;
        return;
    }
    else {
        Node* t = head;
        // Traverse to the last node
        while (t->next != NULL) {
            t = t->next;
        }
        // Attach the new node at the end
        t->next = temp;
    }
}
// Function to remove the first occurrence of node with value 'x'
void LinkedList::remove(int x) {
    if (!head) {
        Logger::log(LogLevel::WARNING, "Attempted to remove from an empty list.");
        return;
    }
    
    // If the node to be deleted is the head
    if (head->data == x) {
        Logger::log(LogLevel::INFO, "Removing head: " + std::to_string(x));
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;
    Node* cur = head->next;

    // Traverse the list to find the node with value 'i'
    while (cur) {
        if (cur->data == x) {
            Logger::log(LogLevel::INFO, "Removing: " + std::to_string(x));
            prev->next = cur->next; // Bypass the node
            if (cur == tail) tail = prev; // Update tail if needed
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    Logger::log(LogLevel::WARNING, "Element not found: " + std::to_string(x));

}

// Function to print all nodes in the linked list
void LinkedList::print()
{
    Logger::log(LogLevel::INFO, "Destructor called.");
    Node* temp = this->head;
    // Traverse and print each node
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

// Destructor: Deletes all nodes to free memory


LinkedList::~LinkedList() {
    cout << "Destructor called\n";
    Node* cur = this->head;
    // Traverse and delete each node
    while (cur != NULL) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}



