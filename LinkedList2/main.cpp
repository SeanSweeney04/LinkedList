#include "LinkedList.h"
#include "LinkedListLogger.h"
#include "Logger.h"
#include <iostream>

int main()
{
    Logger logger("linkedlist_log.txt");  // Create Logger instance

    logger.log(LogLevel::INFO, "Program started.");

    LinkedList l1(logger);
    LinkedListLogger l1Logger(l1);  // Create a LinkedListLogger instance

    for (int i = 0; i < 5; i++) {
        l1.insert(i);
    }

    std::cout << "Original List (l1): ";
    l1Logger.print();  // Use instance method

    logger.log(LogLevel::INFO, "Removing 2 from l1...");
    l1.remove(2);
    l1Logger.print();

    logger.log(LogLevel::INFO, "Removing head (0) from l1...");
    l1.remove(0);
    l1Logger.print();

    logger.log(LogLevel::INFO, "Removing tail (4) from l1...");
    l1.remove(4);
    l1Logger.print();

    logger.log(LogLevel::INFO, "Trying to remove a non-existent value (10)...");
    l1.remove(10);
    l1Logger.print();

    logger.log(LogLevel::INFO, "Copying l1 into l2...");
    LinkedList l2(l1, logger);
    LinkedListLogger l2Logger(l2);
    l2Logger.print();

    logger.log(LogLevel::INFO, "Program ended.");
    return 0;
}
