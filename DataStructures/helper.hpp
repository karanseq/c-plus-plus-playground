#include <assert.h>
#include <iostream>
#include <stdint.h>

#include "linked_list.h"

template<typename T>
void PrintLinkedList(LinkIterator<T> i_front)
{
    using namespace std;
    while (i_front)
    {
        cout << *i_front << " ";
        ++i_front;
    }
    cout << endl;
}

uint32_t GetHashFromString(const char* i_key)
{
    assert(i_key);

    uint32_t hash = 0;
    uint32_t i = 0;
    while ((i_key + i) && *(i_key + i) != '\0')
    {
        hash = hash * 256 + int(*(i_key + i));
        ++i;
    }

    return hash;
}
