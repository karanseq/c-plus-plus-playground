#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "helper.hpp"
#include "linked_list.h"

int main()
{
    using namespace std;

    cout << "The data structures suite..." << endl;
    cout << "----------------------------" << endl;

    srand(time(0));

    {
        LinkedList<int> list;

        list.PushFront(rand() % 100);
        list.PushFront(rand() % 100);
        list.PushFront(rand() % 100);
        list.PushFront(rand() % 100);
        list.PushFront(rand() % 100);

        PrintLinkedList<int>(list.Front());
    }

    cout << endl;

    {
        LinkedList<int> list;
        
        list.PushFront(30);
        PrintLinkedList<int>(list.Front());
        list.PushBack(40);
        PrintLinkedList<int>(list.Front());
        list.PushFront(20);
        PrintLinkedList<int>(list.Front());
        list.PushBack(50);
        PrintLinkedList<int>(list.Front());
        list.PushFront(10);
        PrintLinkedList<int>(list.Front());

        list.PopFront();
        PrintLinkedList<int>(list.Front());
        list.PopFront();
        PrintLinkedList<int>(list.Front());
        list.PopFront();
        PrintLinkedList<int>(list.Front());
        list.PopFront();
        PrintLinkedList<int>(list.Front());
        list.PopFront();

        PrintLinkedList<int>(list.Front());
    }

    return 0;
}
