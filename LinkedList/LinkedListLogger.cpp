#include "LinkedListLogger.h"
#include "Logger.h"
#include <iostream>

extern Logger logger;

LinkedListLogger::LinkedListLogger(LinkedList& list)
{
    this->list = &list;  // ✅ Store a pointer instead of a reference
}

void LinkedListLogger::print()
{
    if (list == nullptr)
    {
        logger.log(LogLevel::ERROR, "Error: LinkedListLogger is referencing a null LinkedList.");
        return;
    }

    Node* temp = list->getHead();

    if (temp == nullptr)
    {
        logger.log(LogLevel::INFO, "List is empty.");
        return;
    }

    std::string logMessage = "List contents: ";
    while (temp != nullptr)
    {
        logMessage += std::to_string(temp->data) + " ";
        temp = temp->next;
    }

    logger.log(LogLevel::INFO, logMessage);
}