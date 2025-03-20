#include "LinkedList.h"
#include "LinkedListLogger.h"
#include "Logger.h"
#include <iostream>

using namespace std;

Logger logger("linkedlist_log.txt");  // ✅ Global Logger instance

int main()
{
    logger.log(LogLevel::INFO, "=========================================");
    logger.log(LogLevel::INFO, "TEST SUITE STARTED");
    logger.log(LogLevel::INFO, "=========================================");

    logger.log(LogLevel::INFO, "Test 01: Creating and inserting elements into l1.");
    cout << "\nTest 01: Creating and inserting elements into l1" << endl;
    LinkedList l1;
    LinkedListLogger l1Logger(l1);

    for (int i = 0; i < 5; i++)
    {
        l1.insert(i);
    }

    logger.log(LogLevel::INFO, "Original List (l1):");
    l1Logger.print();
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 02: Removing elements from l1.");
    cout << "\nTest 02: Removing elements from l1" << endl;
    l1.remove(2);
    logger.log(LogLevel::INFO, "Removed 2 from l1.");
    l1Logger.print();

    l1.remove(0);
    logger.log(LogLevel::INFO, "Removed 0 from l1.");
    l1Logger.print();

    l1.remove(4);
    logger.log(LogLevel::INFO, "Removed 4 from l1.");
    l1Logger.print();
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 03: Trying to remove a non-existent value (10).");
    cout << "\nTest 03: Trying to remove a non-existent value (10)" << endl;
    l1.remove(10);
    logger.log(LogLevel::WARNING, "Element 10 not found in l1.");
    l1Logger.print();
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 04: Copying l1 into l2 (Copy Constructor).");
    cout << "\nTest 04: Copying l1 into l2 (Copy Constructor)" << endl;
    LinkedList l2(l1);
    LinkedListLogger l2Logger(l2);
    l2Logger.print();
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 05: Assigning l1 to l3 (Assignment Operator).");
    cout << "\nTest 05: Assigning l1 to l3 (Assignment Operator)" << endl;
    LinkedList l3;
    l3 = l1;
    LinkedListLogger l3Logger(l3);
    l3Logger.print();
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 06: Passing LinkedList by VALUE.");
    cout << "\nTest 06: Passing LinkedList by VALUE" << endl;
    {
        LinkedList tempList = l1;  // ✅ Pass-by-value creates a new object
        tempList.insert(99);
        logger.log(LogLevel::INFO, "Inside pass-by-value (should NOT affect original list)");
        LinkedListLogger loggerInstance(tempList);
        loggerInstance.print();
    }
    logger.log(LogLevel::INFO, "Original l1 after pass-by-value:");
    l1Logger.print();
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 07: Passing LinkedList by REFERENCE.");
    cout << "\nTest 07: Passing LinkedList by REFERENCE" << endl;
    {
        LinkedList& refList = l1;  // ✅ Pass-by-reference, modifies original list
        refList.insert(100);
        logger.log(LogLevel::INFO, "Inside pass-by-reference (should affect original list)");
        LinkedListLogger loggerInstance(refList);
        loggerInstance.print();
    }
    logger.log(LogLevel::INFO, "Original l1 after pass-by-reference:");
    l1Logger.print();
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "Test 08: Passing LinkedList by POINTER.");
    cout << "\nTest 08: Passing LinkedList by POINTER" << endl;
    {
        LinkedList* ptrList = &l1;  // ✅ Pass-by-pointer, modifies original list
        ptrList->insert(101);
        logger.log(LogLevel::INFO, "Inside pass-by-pointer (should affect original list)");
        LinkedListLogger loggerInstance(*ptrList);
        loggerInstance.print();
    }
    logger.log(LogLevel::INFO, "Original l1 after pass-by-pointer:");
    l1Logger.print();
    logger.log(LogLevel::INFO, "-----------------------------------------");

    logger.log(LogLevel::INFO, "=========================================");
    logger.log(LogLevel::INFO, "TEST SUITE ENDED");
    logger.log(LogLevel::INFO, "=========================================");

    return 0;
}