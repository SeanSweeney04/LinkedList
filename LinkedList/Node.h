#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int x);

   
    int getData() const;
    void setData(int x);

    
    Node* getNext() const;
    void setNext(Node* nextNode);

private:
    int data;
    Node* next;
};

#endif
