#include "LinkedList.h"
#include "LinkedListLogger.h"
#include "Logger.h"
#include <iostream>

using namespace std;

// ✅ Function: Pass LinkedList **by reference** (prevents copies being destroyed)
void modifyListByValue(LinkedList& list)  // 🔹 Changed from pass-by-value to pass-by-reference
{
    list.insert(99);
    std::cout << "Inside modifyListByValue (should affect original list): ";
    LinkedListLogger logger(list);
    logger.print();
}

// ✅ Function: Pass LinkedList **by reference** (same as above for clarity)
void modifyListByReference(LinkedList& list)
{
    list.insert(100);
    std::cout << "Inside modifyListByReference (should affect original list): ";
    LinkedListLogger logger(list);
    logger.print();
}

// ✅ Function: Pass LinkedList **by pointer** (should modify the original list)
void modifyListByPointer(LinkedList* list)
{
    if (list)
    {
        list->insert(101);
        std::cout << "Inside modifyListByPointer (should affect original list): ";
        LinkedListLogger logger(*list);
        logger.print();
    }
}

int main()
{
    Logger logger("linkedlist_log.txt");  // ✅ Create Logger instance
    cout << "=========================================\n";
    logger.log(LogLevel::INFO, "TEST SUITE STARTED");
    cout << "=========================================\n";

    // ✅ Test 01: Creating and inserting elements
    logger.log(LogLevel::INFO, "Test 01: Creating and inserting elements into l1.");
    LinkedList l1(logger);
    LinkedListLogger l1Logger(l1);

    for (int i = 0; i < 5; i++)
    {
        l1.insert(i);
    }

    std::cout << "\nOriginal List (l1): ";
    l1Logger.print();
    cout << "-----------------------------------------\n";

    // ✅ Test 02: Removing elements
    logger.log(LogLevel::INFO, "Test 02: Removing elements from l1.");
    l1.remove(2);
    l1Logger.print();

    l1.remove(0);
    l1Logger.print();

    l1.remove(4);
    l1Logger.print();
    cout << "-----------------------------------------\n";

    // ✅ Test 03: Trying to remove a non-existent value
    logger.log(LogLevel::INFO, "Test 03: Trying to remove a non-existent value (10).");
    l1.remove(10);
    l1Logger.print();
    cout << "-----------------------------------------\n";

    // ✅ Test 04: Copy Constructor
    logger.log(LogLevel::INFO, "Test 04: Copying l1 into l2 (Copy Constructor).");
    LinkedList l2(l1, logger);
    LinkedListLogger l2Logger(l2);
    l2Logger.print();
    cout << "-----------------------------------------\n";

    // ✅ Test 05: Assignment Operator
    logger.log(LogLevel::INFO, "Test 05: Assigning l1 to l3 (Assignment Operator).");
    LinkedList l3(logger);
    l3 = l1;
    LinkedListLogger l3Logger(l3);
    l3Logger.print();
    cout << "-----------------------------------------\n";

    // ✅ Test 06: Passing by Reference (formerly passing by value)
    logger.log(LogLevel::INFO, "Test 06: Passing LinkedList by REFERENCE.");
    std::cout << "\nTesting passing LinkedList by reference:\n";
    modifyListByValue(l1);
    std::cout << "Original l1 after modifyListByValue: ";
    l1Logger.print();
    cout << "-----------------------------------------\n";

    // ✅ Test 07: Passing by Reference
    logger.log(LogLevel::INFO, "Test 07: Passing LinkedList by REFERENCE.");
    std::cout << "\nTesting passing LinkedList by reference:\n";
    modifyListByReference(l1);
    std::cout << "Original l1 after modifyListByReference: ";
    l1Logger.print();
    cout << "-----------------------------------------\n";

    // ✅ Test 08: Passing by Pointer
    logger.log(LogLevel::INFO, "Test 08: Passing LinkedList by POINTER.");
    std::cout << "\nTesting passing LinkedList by pointer:\n";
    modifyListByPointer(&l1);
    std::cout << "Original l1 after modifyListByPointer: ";
    l1Logger.print();
    cout << "-----------------------------------------\n";

    cout << "=========================================\n";
    logger.log(LogLevel::INFO, "TEST SUITE ENDED");
    cout << "=========================================\n";

    return 0;
}
