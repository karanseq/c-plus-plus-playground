#include <iostream>

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
