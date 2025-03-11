// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;


Node::Node(int x)
{
    data = x;
    next = NULL;
}

//Copy constructor   
LinkedList:: LinkedList() { head = tail = NULL; }
LinkedList::LinkedList(const LinkedList& list)
{
    cout << "Copy Constructor called\n";
       
    if (list.head == NULL) {
        this->head = this->tail = NULL;
        return;
    }
    Node* temp = list.head;

    while (temp != NULL) {
        Node* newNode = new Node(temp->data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }
}
void LinkedList::insert(int x)
{
       
    Node* temp = new Node(x);
    if (head == NULL) {
        head = temp;
        return;
    }
    else {
        Node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = temp;
    }
}
void LinkedList::remove(int i) {
    if (!head) return;

    if (head->data == i) {  
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;
    Node* cur = head->next;

    while (cur) {
        if (cur->data == i) {
            prev->next = cur->next;
            if (cur == tail) tail = prev; 
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void LinkedList::print()
{
    Node* temp = this->head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

//Destructor

LinkedList::~LinkedList() {
    cout << "Destructor called\n";
    Node* cur = this->head;
    while (cur != NULL) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}



