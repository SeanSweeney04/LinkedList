#include "LinkedList.h"
#include <iostream>
#include "Logger.h"

int main() {
    Logger::enableFileLogging("linkedlist_log.txt");

    Logger::log(LogLevel::INFO, "Program started.");
    LinkedList l1;
    for (int i = 0; i < 5; i++) {
        l1.insert(i);
    }

    std::cout << "Original List (l1): ";
    l1.print();

    // Removing a middle element (2)
    std::cout << "Removing 2 from l1...\n";
    l1.remove(2);
    std::cout << "List after removing 2: ";
    l1.print();

    // Removing the head (0)
    std::cout << "Removing head (0) from l1...\n";
    l1.remove(0);
    std::cout << "List after removing head: ";
    l1.print();

    // Removing the tail (4)
    std::cout << "Removing tail (4) from l1...\n";
    l1.remove(4);
    std::cout << "List after removing tail: ";
    l1.print();

    // Attempt to remove a non-existent value (10)
    std::cout << "Trying to remove a non-existent value (10)...\n";
    l1.remove(10);
    std::cout << "List after trying to remove 10: ";
    l1.print();

    // Copying l1 into l2 (testing copy constructor)
    std::cout << "Copying l1 into l2...\n";
    LinkedList l2 = l1;
    std::cout << "Copied List (l2): ";
    l2.print();

    // Testing if modifying l1 affects l2
    std::cout << "Removing 3 from l1...\n";
    l1.remove(3);
    std::cout << "List l1 after removal: ";
    l1.print();
    std::cout << "List l2 should remain unchanged: ";
    l2.print();

    // Testing empty list case
    LinkedList l4;
    std::cout << "Printing an empty list (l4): ";
    l4.print();
    std::cout << "Trying to remove from an empty list...\n";
    l4.remove(1);
    std::cout << "List after trying to remove from empty: ";
    l4.print();

    // Dynamic allocation and deletion (Testing Destructor)
    std::cout << "Creating a dynamic linked list l3...\n";
    LinkedList* l3 = new LinkedList();
    l3->insert(100);
    l3->insert(200);
    std::cout << "Dynamic List (l3): ";
    l3->print();
    delete l3; // Destructor should be called

    return 0;
}