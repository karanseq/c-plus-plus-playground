#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "helper.hpp"

#include "hash_table.h"
#include "linked_list.h"

void TestLinkedList()
{
    using namespace std;
    cout << __FUNCTION__ << endl;

    LinkedList<int> list;
    LinkIterator<int> it;
    
    // test pushes
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

    // test insert in middle
    it = list.Front();
    ++it;
    ++it;
    list.Insert(it, 25);
    PrintLinkedList<int>(list.Front());

    // test erase from middle
    it = list.Front();
    ++it;
    list.Erase(it);
    PrintLinkedList<int>(list.Front());

    // test erase head
    it = list.Front();
    list.Erase(it);
    PrintLinkedList<int>(list.Front());

    // test erase tail
    it = list.Back();
    list.Erase(it);
    PrintLinkedList<int>(list.Front());

    // test pops
    list.PopFront();
    PrintLinkedList<int>(list.Front());
    list.PopBack();
    PrintLinkedList<int>(list.Front());
    list.PopFront();

    PrintLinkedList<int>(list.Front());
}

void TestHashTable()
{
    using namespace std;
    cout << __FUNCTION__ << endl;

    HashTable<const char*, uint32_t> hash_table(2, &GetHashFromString);

    hash_table.Insert("May", 111111);
    hash_table.Insert("the", 22222);
    hash_table.Insert("force", 3333);
    hash_table.Insert("be", 444);
    hash_table.Insert("with", 55);
    hash_table.Insert("you", 6);

    cout << "HashTable has " << hash_table.GetElementCount() << " elements" << endl;

    const char* key = "May";
    uint32_t value = 0;
    if (hash_table.Find(key, value))
    {
        cout << "Key=" << key << " Value=" << value << endl;
    }

    key = "balls";
    value = 0;
    if (hash_table.Find(key, value))
    {
        cout << "Key=" << key << " Value=" << value << endl;
    }
}

int main()
{
    using namespace std;

    cout << "The data structures suite..." << endl;
    cout << "----------------------------" << endl;

    srand(time(0));

    TestLinkedList();
    TestHashTable();

    return 0;
}
