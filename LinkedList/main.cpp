#include <iostream>
#include "LinkedList.h"
#include "LinkedListLogger.h"
#include "Logger.h"
#include "Temp.h"

using namespace std;

Temp passTemp(Temp temp_val, Temp& temp_ref)
{
    Logger::log(DEBUG, "Inside passTemp()");

    // optional: modify them, or log contents
    Logger::log(INFO, "Inside passTemp - logging temp_val:");
    for (const auto& list : temp_val.getLists())
    {
        LinkedListLogger logger(list);
        Logger::log(INFO, logger.toString());
    }

    Logger::log(INFO, "Inside passTemp - logging temp_ref:");
    for (const auto& list : temp_ref.getLists())
    {
        LinkedListLogger logger(list);
        Logger::log(INFO, logger.toString());
    }

    Logger::log(DEBUG, "Leaving passTemp() with a return by value");

    return temp_val;
}

int main()
{
    Logger::initialize("linkedlist_log.txt");
    {
        Logger::log(INFO, "=========================================");
        Logger::log(INFO, "TEST SUITE STARTED");
        Logger::log(INFO, "=========================================");
        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 01: Creating and inserting elements into l1.");
            LinkedList l1;
            LinkedListLogger l1Logger(l1);

            for (int i = 0; i < 5; i++)
            {
                l1.insert(i);
            }

            Logger::log(INFO, "Original List (l1): " + l1Logger.toString());
        }
        
        Logger::log(INFO, "");

        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 02: Removing elements from l1.");
            LinkedList l1;
            LinkedListLogger l1Logger(l1);

            for (int i = 0; i < 5; i++)
            {
                l1.insert(i);
            }
            l1.remove(2);
            Logger::log(INFO, "Removed 2 from l1.");
            Logger::log(INFO, l1Logger.toString());

            l1.remove(0);
            Logger::log(INFO, "Removed 0 from l1.");
            Logger::log(INFO, l1Logger.toString());

            l1.remove(4);
            Logger::log(INFO, "Removed 4 from l1.");
            Logger::log(INFO, l1Logger.toString());
        }

        Logger::log(INFO, "");

        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 03: Trying to remove a non-existent value (10).");
            LinkedList l1;
            LinkedListLogger l1Logger(l1);

            for (int i = 0; i < 5; i++)
            {
                l1.insert(i);
            }
            Logger::log(WARNING, "Element 10 not found in l1.");
            Logger::log(INFO, l1Logger.toString());
           
        }
   
        Logger::log(LogLevel::INFO, "");

        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 04: Copying l1 into l2 (Copy Constructor).");
            LinkedList l1;
            LinkedListLogger l1Logger(l1);

            for (int i = 0; i < 5; i++)
            {
                l1.insert(i);
            }
            LinkedList l2(l1);
            LinkedListLogger l2Logger(l2);
            Logger::log(INFO, l1Logger.toString());
        }

        Logger::log(LogLevel::INFO, "");

        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 05: Assigning l1 to l3 (Assignment Operator).");
            LinkedList l1;
            LinkedListLogger l1Logger(l1);

            for (int i = 0; i < 5; i++)
            {
                l1.insert(i);
            }
            LinkedList l3;
            l3 = l1;
            LinkedListLogger l3Logger(l3);
            Logger::log(INFO, l1Logger.toString());
        }

        Logger::log(LogLevel::INFO, "");

        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 06: Passing LinkedList by VALUE.");
            LinkedList l1;
            LinkedListLogger l1Logger(l1);

            for (int i = 0; i < 5; i++)
            {
                l1.insert(i);
            }
            LinkedList tempList = l1;  // Pass-by-value creates a new object
            tempList.insert(99);
            Logger::log(INFO, "Inside pass-by-value (should NOT affect original list)");
            LinkedListLogger loggerVal(tempList);
            Logger::log(INFO, loggerVal.toString());
            Logger::log(INFO, "Original l1 after pass-by-value:");
            Logger::log(INFO, l1Logger.toString());
        }

        Logger::log(LogLevel::INFO, "");

        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 07: Passing LinkedList by REFERENCE.");
            LinkedList l1;
            LinkedListLogger l1Logger(l1);

            for (int i = 0; i < 5; i++)
            {
                l1.insert(i);
            }
            LinkedList& refList = l1;  // Pass-by-reference, modifies original list
            refList.insert(100);
            Logger::log(INFO, "Inside pass-by-reference (should affect original list)");
            LinkedListLogger loggerTemp(refList);
            Logger::log(INFO, loggerTemp.toString());
            Logger::log(INFO, "Original l1 after pass-by-reference:");
            Logger::log(INFO, l1Logger.toString());
        }

        Logger::log(LogLevel::INFO, "");

        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 08: Passing LinkedList by POINTER.");
            LinkedList l1;
            LinkedListLogger l1Logger(l1);

            for (int i = 0; i < 5; i++)
            {
                l1.insert(i);
            }
            LinkedList* ptrList = &l1;  // Pass-by-pointer, modifies original list
            ptrList->insert(101);
            Logger::log(INFO, "Inside pass-by-pointer (should affect original list)");
            LinkedListLogger loggerPointer(*ptrList);
            Logger::log(INFO, loggerPointer.toString());
            Logger::log(INFO, "Original l1 after pass-by-pointer:");
            Logger::log(INFO, l1Logger.toString());
        }

        Logger::log(LogLevel::INFO, "");

        {
            Logger::log(INFO, "-----------------------------------------");
            Logger::log(INFO, "Test 09: Passing Temp instance by value and reference");

            Temp t1;  // default constructor
            Temp t2 = t1;

            Temp t3 = passTemp(t1, t2);
        }

        Logger::log(LogLevel::INFO, "");
	}

    {
        Logger::log(INFO, "=========================================");
        Logger::log(INFO, "TEST SUITE ENDED");
        Logger::log(INFO, "=========================================");
    }
    return 0;
}