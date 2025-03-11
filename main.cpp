#include "LinkedList.h"
#include <iostream>

int main() {

    LinkedList l1;
    for (int i = 0; i < 5; i++) {
        l1.insert(i);
    }
   
    l1.print();
    l1.remove(2);
    // Copying l1 into l2
    LinkedList l2 = l1;
    l2.print();

    LinkedList* l3 = new LinkedList();
    delete l3;

    return 0;
}