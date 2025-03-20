#include "LinkedList.h"
#include "LinkedListLogger.h"
#include "Logger.h"
#include <iostream>

using namespace std;

// ✅ Function: Pass LinkedList **by value** (should NOT modify original)
void modifyListByValue(LinkedList list, Logger& logger)
{
    list.insert(99);
    std::cout << "Inside modifyListByValue (should NOT affect original list): ";
    LinkedListLogger loggerInstance(list);
    loggerInstance.print();
}

// ✅ Function: Pass LinkedList **by reference** (should modify original)
void modifyListByReference(LinkedList& list, Logger& logger)
{
    list.insert(100);
    std::cout << "Inside modifyListByReference (should affect original list): ";
    LinkedListLogger loggerInstance(list);
    loggerInstance.print();
}

// ✅ Function: Pass LinkedList **by pointer** (should modify original)
void modifyListByPointer(LinkedList* list, Logger& logger)
{
    if (list)
    {
        list->insert(101);
        std::cout << "Inside modifyListByPointer (should affect original list): ";
        LinkedListLogger loggerInstance(*list);
        loggerInstance.print();
    }
}

int main()
{
    Logger logger("linkedlist_log.txt");

    std::cout << "=========================================\n";
    logger.log(LogLevel::INFO, "TEST SUITE STARTED");
    std::cout << "=========================================\n";

    // ✅ Test 01: Creating and inserting elements
    logger.log(LogLevel::INFO, "Test 01: Creating and inserting elements into l1.");
    LinkedList l1;
    LinkedListLogger l1Logger(l1);

    for (int i = 0; i < 5; i++)
    {
        l1.insert(i);
    }

    std::cout << "\nOriginal List (l1): ";
    l1Logger.print();
    std::cout << "-----------------------------------------\n";

    // ✅ Test 02: Removing elements (pass Logger to remove())
    logger.log(LogLevel::INFO, "Test 02: Removing elements from l1.");
    l1.remove(2, logger.getLogFile());
    l1Logger.print();

    l1.remove(0, logger.getLogFile());
    l1Logger.print();

    l1.remove(4, logger.getLogFile());
    l1Logger.print();
    std::cout << "-----------------------------------------\n";

    // ✅ Test 03: Trying to remove a non-existent value
    logger.log(LogLevel::INFO, "Test 03: Trying to remove a non-existent value (10).");
    l1.remove(10, logger.getLogFile());
    l1Logger.print();
    std::cout << "-----------------------------------------\n";

    // ✅ Test 04: Copy Constructor
    logger.log(LogLevel::INFO, "Test 04: Copying l1 into l2 (Copy Constructor).");
    LinkedList l2(l1);
    LinkedListLogger l2Logger(l2);
    l2Logger.print();
    std::cout << "-----------------------------------------\n";

    // ✅ Test 05: Assignment Operator
    logger.log(LogLevel::INFO, "Test 05: Assigning l1 to l3 (Assignment Operator).");
    LinkedList l3;
    l3 = l1;
    LinkedListLogger l3Logger(l3);
    l3Logger.print();
    std::cout << "-----------------------------------------\n";

    // ✅ Test 06: Passing by Value
    logger.log(LogLevel::INFO, "Test 06: Passing LinkedList by VALUE.");
    std::cout << "\nTesting passing LinkedList by value:\n";
    modifyListByValue(l1, logger);
    std::cout << "Original l1 after modifyListByValue: ";
    l1Logger.print();
    std::cout << "-----------------------------------------\n";

    // ✅ Test 07: Passing by Reference
    logger.log(LogLevel::INFO, "Test 07: Passing LinkedList by REFERENCE.");
    std::cout << "\nTesting passing LinkedList by reference:\n";
    modifyListByReference(l1, logger);
    std::cout << "Original l1 after modifyListByReference: ";
    l1Logger.print();
    std::cout << "-----------------------------------------\n";

    // ✅ Test 08: Passing by Pointer
    logger.log(LogLevel::INFO, "Test 08: Passing LinkedList by POINTER.");
    std::cout << "\nTesting passing LinkedList by pointer:\n";
    modifyListByPointer(&l1, logger);
    std::cout << "Original l1 after modifyListByPointer: ";
    l1Logger.print();
    std::cout << "-----------------------------------------\n";

    std::cout << "=========================================\n";
    logger.log(LogLevel::INFO, "TEST SUITE ENDED");
    std::cout << "=========================================\n";

    return 0;
}