#include <iostream>
#include "../include/ArrayList.h"

using namespace std;

int main()
{
    // Create an ArrayList with maximum size 5
    ArrayList<int> list(5);

    cout << "Initially:\n";
    cout << "Empty: " << list.isEmpty() << endl;
    cout << "Full: " << list.isFull() << endl;
    cout << "Size: " << list.listSize() << endl;
    cout << "Max Size: " << list.maxListSize() << endl;

    // insertEnd()

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    cout << "\nAfter insertEnd(10, 20, 30):\n";
    list.print();
    cout << endl;

    // insertAt()

    list.insertAt(1, 15);

    cout << "\nAfter insertAt(1, 15):\n";
    list.print();
    cout << endl;

    // insert()

    list.insert(40);

    cout << "\nAfter insert(40):\n";
    list.print();
    cout << endl;

    // Try inserting duplicate
    list.insert(20);

    // isEmpty / isFull

    cout << "\nIs Empty: " << list.isEmpty() << endl;
    cout << "Is Full: " << list.isFull() << endl;

    // listSize / maxListSize

    cout << "List Size: " << list.listSize() << endl;
    cout << "Max List Size: " << list.maxListSize() << endl;

    // isItemAtEqual()

    cout << "\nIs item at position 1 equal to 15? "
         << list.isItemAtEqual(1, 15) << endl;

    // seqSearch()

    cout << "Position of 30: "
         << list.seqSearch(30) << endl;

    cout << "Position of 100: "
         << list.seqSearch(100) << endl;

    // retrieveAt()

    int value;

    list.retrieveAt(2, value);

    cout << "\nRetrieved value at position 2: "
         << value << endl;

    // replaceAt()

    list.replaceAt(2, 35);

    cout << "\nAfter replaceAt(2, 35):\n";
    list.print();
    cout << endl;

    // removeAt()
    list.removeAt(1);

    cout << "\nAfter removeAt(1):\n";
    list.print();
    cout << endl;

    // remove()
    list.remove(40);

    cout << "\nAfter remove(40):\n";
    list.print();
    cout << endl;

    // Copy Constructor
    ArrayList<int> list2(list);

    cout << "\nlist2 after copy constructor:\n";
    list2.print();
    cout << endl;

    // Copy Assignment Operator
    ArrayList<int> list3(10);

    list3.insertEnd(100);
    list3.insertEnd(200);

    cout << "\nlist3 before assignment:\n";
    list3.print();
    cout << endl;

    list3 = list;

    cout << "list3 after list3 = list:\n";
    list3.print();
    cout << endl;

    // clearList()
    list.clearList();

    cout << "\nAfter clearList():\n";
    list.print();
    cout << endl;

    cout << "Is Empty: " << list.isEmpty() << endl;
    cout << "Size: " << list.listSize() << endl;

    return 0;
}