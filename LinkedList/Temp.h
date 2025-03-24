#ifndef TEMP_H
#define TEMP_H

#include <vector>
#include "LinkedList.h"

class Temp
{
public:
    Temp();
    Temp(const Temp& other);
    Temp& operator=(const Temp& other);

    std::vector<LinkedList>& getLists();

private:
    std::vector<LinkedList> lists;
};

#endif