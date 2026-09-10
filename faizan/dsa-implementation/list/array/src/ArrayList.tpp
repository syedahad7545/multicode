#include "../include/ArrayList.h"
#include <iostream>
using namespace std;

template <typename T>
ArrayList<T>::ArrayList(int size)
{
    list = new T[size];
    length = 0;
    maxSize = size;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &otherList)
{

    length = otherList.length;
    maxSize = otherList.maxSize;
    list = new T[maxSize];
    for (int i = 0; i < otherList.length; i++)
    {
        list[i] = otherList.list[i];
    }
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList<T> &otherList)
{
    if (this != &otherList)
    {
        delete[] list;
        length = otherList.length;
        maxSize = otherList.maxSize;
        list = new T[maxSize];
        for (int i = 0; i < otherList.length; i++)
        {
            list[i] = otherList.list[i];
        }
    }
    return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const
{
    return (length == 0);
}

template <typename T>
bool ArrayList<T>::isFull() const
{
    return (maxSize == length);
}

template <typename T>
int ArrayList<T>::listSize() const
{
    return length;
}

template <typename T>
int ArrayList<T>::maxListSize() const
{
    return maxSize;
}

template <typename T>
void ArrayList<T>::print() const
{
    cout << "{ ";
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << "}";
}

template <typename T>
bool ArrayList<T>::isItemAtEqual(int position, const T &item) const
{
    return (list[position] == item);
}

template <typename T>
void ArrayList<T>::insertAt(int position, const T &insertedItem)
{
    if (position < 0 || position > length)
    {
        cout << "The position of the item to be inserted,"
             << " out of range" << endl;
    }
    else if (length == maxSize)
    {
        cout << "Cannot insert in a full list" << endl;
    }
    else
    {
        // Optimized Method

        for (int i = length; i > position; i--)
        {
            list[i] = list[i - 1];
        }
        list[position] = insertedItem;
        length += 1;

        // IMPLEMENTED BY ME (not an optimized method)
        // int tempListSize = length - position;
        // T* tempList = new T[tempListSize];
        // for (int i = position; i < length; i++)
        // {
        //     tempList[i - position] = list[i];
        // }
        // list[position] = item;
        // for (int i = position + 1; i < length + 1; i++)
        // {
        //     list[i] = tempList[i - position - 1];
        // }

        // delete[] tempList;
        // length += 1;
    }
}

template <typename T>
void ArrayList<T>::insertEnd(const T &insertItem)
{
    if (length == maxSize)
    {
        cout << "Cannot Insert in a full list" << endl;
    }
    else
    {
        list[length] = insertItem;
        length += 1;
    }
}

template <typename T>
void ArrayList<T>::insert(const T &insertItem)
{

    if (length == maxSize)
    {
        cout << "Cannot insert in a full list" << endl;
    }
    else
    {
        bool isFound = false;
        for (int i = 0; i < length; i++)
        {
            if (insertItem == list[i])
            {
                isFound = true;
                break;
            }
        }

        if (isFound)
        {
            cout << "Element is already present in the list" << endl;
        }
        else
        {
            list[length] = insertItem;
            length += 1;
        }
    }
}

template <typename T>
void ArrayList<T>::remove(const T &remItem)
{

    int i;
    for (i = 0; i < length; i++)
    {
        if (remItem == list[i])
        {
            break;
            // value of i is our index at which we have to remove the item
        }
    }

    //item was not found
    if(i == length){
        return; 
    }

    for (int j = i; j < length - 1; j++)
    {
        list[j] = list[j + 1];
    }

    length -= 1;
}

template <typename T>
void ArrayList<T>::removeAt(int position)
{
    if (position < 0 || position >= length)
    {
        cout << "Position is out of range" << endl;
    }
    else
    {

        for (int j = position ; j < length - 1; j++)
        {
            list[j] = list[j + 1];
        }

        length -= 1;
    }
}

template <typename T>
void ArrayList<T>::retrieveAt(int position, T &retItem) const
{
    if (position < 0 || position >= length)
    {
        cout << "Position is out of range" << endl;
    }
    else
    {
        retItem = list[position];
    }
}

template <typename T>
void ArrayList<T>::replaceAt(int position, const T &repItem)
{
    if (position < 0 || position >= length)
    {
        cout << "Position is out of range" << endl;
    }
    else
    {
        list[position] = repItem;
    }
}

template <typename T>
void ArrayList<T>::clearList()
{
    length = 0;
}

template <typename T>
int ArrayList<T>::seqSearch(const T &searchItem) const
{
    for (int i = 0; i < length; i++)
    {
        if (list[i] == searchItem)
        {
            return i;
        }
    }

    return -1;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] list;
}