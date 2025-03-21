#include "Temp.h"
#include "Logger.h"

Temp::Temp()
{
    lists.emplace_back();  // Stack
    lists.emplace_back();  // Another stack

    LinkedList* heapList = new LinkedList();
    lists.push_back(std::move(*heapList));  // Move into vector
    delete heapList;
}

Temp& Temp::operator=(const Temp& other)
{
    if (this != &other)
    {
        lists = other.lists;
    }
    return *this;
}

// Getter to allow external iteration
std::vector<LinkedList>& Temp::getLists()
{
    return lists;
}