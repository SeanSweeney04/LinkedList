#include "LinkedList.h"
#include "LinkedListLogger.h"
#include "Logger.h"
#include "Temp.h"
#include <iostream>

using namespace std;

Logger logger("linkedlist_log.txt");  //Global Logger instance

int main()
{
    logger.log(LogLevel::INFO, "=========================================");
    logger.log(LogLevel::INFO, "TEST SUITE STARTED");
    logger.log(LogLevel::INFO, "=========================================");

    logger.log(LogLevel::INFO, "Test 01: Creating and inserting elements into l1.");
    LinkedList l1;
    logger.log(LogLevel::DEBUG, "LinkedList default constructor called.");
    LinkedListLogger l1Logger(l1);

    for (int i = 0; i < 5; i++)
    {
        l1.insert(i);
    }

    logger.log(LogLevel::INFO, "Original List (l1): " + l1Logger.toString());
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 02: Removing elements from l1.");
    l1.remove(2);
    logger.log(LogLevel::INFO, "Removed 2 from l1.");
    logger.log(LogLevel::INFO, l1Logger.toString());

    l1.remove(0);
    logger.log(LogLevel::INFO, "Removed 0 from l1.");
    logger.log(LogLevel::INFO, l1Logger.toString());

    l1.remove(4);
    logger.log(LogLevel::INFO, "Removed 4 from l1.");
    logger.log(LogLevel::INFO, l1Logger.toString());
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 03: Trying to remove a non-existent value (10).");
    l1.remove(10);
    logger.log(LogLevel::WARNING, "Element 10 not found in l1.");
    logger.log(LogLevel::INFO, l1Logger.toString());
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 04: Copying l1 into l2 (Copy Constructor).");
    LinkedList l2(l1);
    LinkedListLogger l2Logger(l2);
    logger.log(LogLevel::INFO, l1Logger.toString());
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 05: Assigning l1 to l3 (Assignment Operator).");
    LinkedList l3;
    l3 = l1;
    LinkedListLogger l3Logger(l3);
    logger.log(LogLevel::INFO, l1Logger.toString());
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 06: Passing LinkedList by VALUE.");
    {
        LinkedList tempList = l1;  // Pass-by-value creates a new object
        tempList.insert(99);
        logger.log(LogLevel::INFO, "Inside pass-by-value (should NOT affect original list)");
        LinkedListLogger loggerInstance(tempList);
        logger.log(LogLevel::INFO, loggerInstance.toString());
    }
    logger.log(LogLevel::INFO, "Original l1 after pass-by-value:");
    logger.log(LogLevel::INFO, l1Logger.toString());
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 07: Passing LinkedList by REFERENCE.");
    {
        LinkedList& refList = l1;  // Pass-by-reference, modifies original list
        refList.insert(100);
        logger.log(LogLevel::INFO, "Inside pass-by-reference (should affect original list)");
        LinkedListLogger loggerInstance(refList);
        logger.log(LogLevel::INFO, loggerInstance.toString());
    }
    logger.log(LogLevel::INFO, "Original l1 after pass-by-reference:");
    logger.log(LogLevel::INFO, l1Logger.toString());
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 08: Passing LinkedList by POINTER.");
    {
        LinkedList* ptrList = &l1;  // Pass-by-pointer, modifies original list
        ptrList->insert(101);
        logger.log(LogLevel::INFO, "Inside pass-by-pointer (should affect original list)");
        LinkedListLogger loggerInstance(*ptrList);
        logger.log(LogLevel::INFO, loggerInstance.toString());
    }
    logger.log(LogLevel::INFO, "Original l1 after pass-by-pointer:");
    logger.log(LogLevel::INFO, l1Logger.toString());
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "================== Temp Test ==================");

    Temp temp;
    logger.log(LogLevel::INFO, "Filling LinkedLists inside Temp with test data...");
    int value = 1;
    for (auto& list : temp.getLists())
    {
        list.insert(value++);
        list.insert(value++);
    }

    logger.log(LogLevel::INFO, "Logging contents of all lists in Temp:");
    int index = 1;
    for (const auto& list : temp.getLists())
    {
        logger.log(LogLevel::INFO, "List #" + std::to_string(index++));
        LinkedListLogger listLogger(list);
        logger.log(LogLevel::INFO, listLogger.toString());
    }

    logger.log(LogLevel::INFO, "=========================================");
    logger.log(LogLevel::INFO, "TEST SUITE ENDED");
    logger.log(LogLevel::INFO, "=========================================");

    return 0;
}