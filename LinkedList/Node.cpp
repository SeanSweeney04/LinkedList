#include "Node.h"

// Constructor: Initializes the node with a given value and sets next to nullptr
Node::Node(int x)
{
    data = x;
    next = nullptr;
}

// Getter for data
int Node::getData() const
{
    return data;
}

// Setter for data
void Node::setData(int x)
{
    data = x;
}

// Getter for next node
Node* Node::getNext() const
{
    return next;
}

// Setter for next node
void Node::setNext(Node* nextNode)
{
    next = nextNode;
}
