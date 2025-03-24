#include "Temp.h"
#include "Logger.h"
#include "LinkedListLogger.h"

Temp::Temp()
{
    for (int i = 0; i < 3; ++i)
    {
        LinkedList list;
        list.insert(i + 1);

        lists.push_back(list); 
    }
}

Temp::Temp(const Temp& other)
{
    lists = std::vector<LinkedList>(); 
    for (const auto& list : other.lists)
    {
        LinkedList copy = list;        
        lists.push_back(copy);
    }
    Logger::log(DEBUG, "Temp copy constructor called.");
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