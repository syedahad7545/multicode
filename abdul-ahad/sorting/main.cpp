#include <iostream>
#include "sorting.h"

void show(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << std::endl;
  }
}
int main() {
  const int size = 5;
  //int arr[] = {5,1,2,3,4};
  int arr[] = {5,4,3,2,1};
  insertionSort(arr, size);

  show(arr, size);
  return 0;
}
