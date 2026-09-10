//***********************************************************
// Author: M. Faizan
// This class specifies the members to implement the basic
// properties of array-based lists.
//***********************************************************

#pragma once

#include <iostream>
using namespace std;

template <typename T>
class ArrayList
{
private:
    T* list;
    int length;
    int maxSize;

public:
    ArrayList(int size = 100);
    // Constructor
    // Create the array of specified size.
    // Default array size is 100
    // The list points to the array, length = 0,
    // and maxSize = size;

    ArrayList(const ArrayList<T> &otherList);
    // Copy constructor
    // Called when
    // 1. Object is intialized from the existing one.
    // 2. Pass by value in the functions
    // 3. returning the object (sometimes)

    ArrayList<T> &operator=(const ArrayList<T> &otherList);
    // Overload assignment Operator
    // Works during the copy assignment

    bool isEmpty() const;
    // Determine whether list is empty or not

    bool isFull() const;
    // Determine Whether list is full or not

    int listSize() const;
    // Determine the number of element in list

    int maxListSize() const;
    // Determine the size of list

    void print() const;
    // Output the elements of the list

    bool isItemAtEqual(int position, const T &item) const;
    // Determine whether the item is same at the specified position

    void insertAt(int position, const T& insertedItem);
    // To insert an item at the specified position
    // If the list is full, an appropriate message will be displayed.

    void insertEnd(const T& insertItem);
    // To insert an item at the end of the list
    // If the list is full, an appropriate message will be dispayed.

    void insert(const T& insertItem);
    // To insert an item at the end of the list
    // BUT first check whether it is in the list or not
    // If the item is already or list is full appropriate
    // message will be displayed

    void remove(const T& remItem);
    // To remove the item from the list
    // If the found then removed and length
    // will be decremented by one

    void removeAt(int position);
    // To remove the item from the list at the specific position
    // If location is out fo range then appropriate message will be shown

    void retrieveAt(int position, T& retItem) const;
    // To retrieve element at the specific position
    // If the location is out of range then
    // appropriate message will be shown

    void replaceAt(int position, const T& repItem);
    // Replace the element at the position specified
    // If location is out of range then
    // appropriate message will be shwon

    void clearList();
    // Remove all the elements from the list
    // The new size will become zero

    int seqSearch(const T& searchItem) const;
    // To search the list for a given item
    // If location is found then return the location
    // of the array otherwise return -1

    ~ArrayList();
    // Destructor
    // Deallocates the memory occupied by the array.
};

// Include template definition at the bottom of header

#include "../src/ArrayList.tpp"