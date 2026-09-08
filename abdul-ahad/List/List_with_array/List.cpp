#include "List.h"
#include <iostream>
#include "sorting.h"

bool ListArr::isFull(){
  if (size >= length) {
    return true;
  }else{
    return false;
  }
}
void ListArr::copy(ListArr& obj){
  *this = obj; 
}
void ListArr::clear(){
  for (int i = 0; i < length; ++i) {
    arr[i] = -1;
  }
  this->size = 0;
  this->curr= 0;
}
void ListArr::insert(int pos, int x){
  if (isFull()) {
    std::cerr << "The size of the array is full. " << std::endl;
    return;
  }
  if(curr + pos > size || pos < 0){ // I am allowing it to insert the thing one place more than the size of the array
    std::cerr << "Dude!!!! you are going out of range. Chill out. Print the current size of the list first and insert the element at the end of the list if you want" << std::endl;
    return;
  }
  if (curr + pos == size) {//Adding the element at the last position
    arr[size] = x;
  }else {
    //Here we will need to do the shifting things 
    for (int i = size - 1; i >= pos; --i) {
      arr[i + 1] = arr[i];
    }
    arr[pos] = x;
  }
  size++;
  //Now let's do some sorting baby!!!!!!!!
  //bubbleSort(arr, size);

}
void ListArr::remove(int pos){
  if (curr + pos < 0 && curr + pos >= size) {
    std::cerr << "Dude this shit is out of range" << std::endl;
    return;
  }
  if (curr + pos < size - 1) { //I did -1 cuz at the last element we don't need to do any sort of shifting
                               //Do the shifting thingy 
    for (int i = pos; i < size; ++i) {
      arr[i] = arr[i + 1];
    }
  }
  size--;
}
int ListArr::get(int pos){
  if (curr + pos < 0 && curr + pos >= size) {
    std::cerr << "Dude this shit is out of range" << std::endl;
    return -1;
  }
  return arr[curr + pos];
}
void ListArr::update(int x, int pos){
  if (curr + pos < 0 && curr + pos >= size) {
    std::cerr << "Dude this shit is out of range" << std::endl;
    return;
  }
  arr[pos] = x;
}
bool ListArr::find(int x){
  bool flag = false;
  int i;
  for (i = 0; i < size; ++i) {
    if (arr[i] == x) 
      flag = true; 
    break;
  }
  if (flag) {
    curr = i; 
    return true;
  }else {
    return false;
  }
}

int ListArr::LENGTH(){
  return size;
}
void ListArr::print(){
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

