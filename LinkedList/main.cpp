#include "LinkedList.h"
#include "LinkedListLogger.h"
#include "Logger.h"
#include <iostream>

using namespace std;

// ✅ Function: Pass LinkedList **by value** (should NOT modify original)
void modifyListByValue(LinkedList list)
{
    cout << "\n[DEBUG] Entering modifyListByValue()" << endl;
    list.insert(99);
    cout << "Inside modifyListByValue (should NOT affect original list): ";
    LinkedListLogger logger(list);
    logger.print();
    cout << "[DEBUG] Exiting modifyListByValue()\n" << endl;
}

// ✅ Function: Pass LinkedList **by reference** (should modify original)
void modifyListByReference(LinkedList& list)
{
    cout << "\n[DEBUG] Entering modifyListByReference()" << endl;
    list.insert(100);
    cout << "Inside modifyListByReference (should affect original list): ";
    LinkedListLogger logger(list);
    logger.print();
    cout << "[DEBUG] Exiting modifyListByReference()\n" << endl;
}

// ✅ Function: Pass LinkedList **by pointer** (should modify original)
void modifyListByPointer(LinkedList* list)
{
    cout << "\n[DEBUG] Entering modifyListByPointer()" << endl;
    if (list)
    {
        list->insert(101);
        cout << "Inside modifyListByPointer (should affect original list): ";
        LinkedListLogger logger(*list);
        logger.print();
    }
    cout << "[DEBUG] Exiting modifyListByPointer()\n" << endl;
}

int main()
{
    Logger logger("linkedlist_log.txt");

    cout << "\n=========================================" << endl;
    logger.log(LogLevel::INFO, "TEST SUITE STARTED");
    cout << "=========================================\n" << endl;

    // ✅ Test 01: Creating and inserting elements
    logger.log(LogLevel::INFO, "Test 01: Creating and inserting elements into l1.");
    cout << "\nTest 01: Creating and inserting elements into l1" << endl;
    LinkedList l1;
    LinkedListLogger l1Logger(l1);

    for (int i = 0; i < 5; i++)
    {
        l1.insert(i);
    }

    cout << "\nOriginal List (l1): ";
    l1Logger.print();
    cout << "-----------------------------------------\n" << endl;

    // ✅ Test 02: Removing elements
    logger.log(LogLevel::INFO, "Test 02: Removing elements from l1.");
    cout << "\nTest 02: Removing elements from l1" << endl;
    l1.remove(2);
    l1Logger.print();

    l1.remove(0);
    l1Logger.print();

    l1.remove(4);
    l1Logger.print();
    cout << "-----------------------------------------\n" << endl;

    // ✅ Test 03: Trying to remove a non-existent value
    logger.log(LogLevel::INFO, "Test 03: Trying to remove a non-existent value (10).");
    cout << "\nTest 03: Trying to remove a non-existent value (10)" << endl;
    l1.remove(10);
    l1Logger.print();
    cout << "-----------------------------------------\n" << endl;

    // ✅ Test 04: Copy Constructor
    logger.log(LogLevel::INFO, "Test 04: Copying l1 into l2 (Copy Constructor).");
    cout << "\nTest 04: Copying l1 into l2 (Copy Constructor)" << endl;
    LinkedList l2(l1);
    LinkedListLogger l2Logger(l2);
    l2Logger.print();
    cout << "-----------------------------------------\n" << endl;

    // ✅ Test 05: Assignment Operator
    logger.log(LogLevel::INFO, "Test 05: Assigning l1 to l3 (Assignment Operator).");
    cout << "\nTest 05: Assigning l1 to l3 (Assignment Operator)" << endl;
    LinkedList l3;
    l3 = l1;
    LinkedListLogger l3Logger(l3);
    l3Logger.print();
    cout << "-----------------------------------------\n" << endl;

    // ✅ Test 06: Passing by Value
    logger.log(LogLevel::INFO, "Test 06: Passing LinkedList by VALUE.");
    cout << "\nTest 06: Passing LinkedList by VALUE" << endl;
    modifyListByValue(l1);
    cout << "Original l1 after modifyListByValue: ";
    l1Logger.print();
    cout << "-----------------------------------------\n" << endl;

    // ✅ Test 07: Passing by Reference
    logger.log(LogLevel::INFO, "Test 07: Passing LinkedList by REFERENCE.");
    cout << "\nTest 07: Passing LinkedList by REFERENCE" << endl;
    modifyListByReference(l1);
    cout << "Original l1 after modifyListByReference: ";
    l1Logger.print();
    cout << "-----------------------------------------\n" << endl;

    // ✅ Test 08: Passing by Pointer
    logger.log(LogLevel::INFO, "Test 08: Passing LinkedList by POINTER.");
    cout << "\nTest 08: Passing LinkedList by POINTER" << endl;
    modifyListByPointer(&l1);
    cout << "Original l1 after modifyListByPointer: ";
    l1Logger.print();
    cout << "-----------------------------------------\n" << endl;

    cout << "=========================================" << endl;
    logger.log(LogLevel::INFO, "TEST SUITE ENDED");
    cout << "=========================================\n" << endl;

    return 0;
}