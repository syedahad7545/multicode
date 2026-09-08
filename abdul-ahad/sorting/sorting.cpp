#include "sorting.h"

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; ++i) { // outerLoop runs n - 1 times
    for (int j = 0; j < n - 1 - i; ++j) { // inner loop runs from 0 to n - 1 - i times
      if (arr[j] < arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
  //This one is the optimized version of the above bubble sort algo
  //This one is optimized for the best case where the array is already sorted
  //so if in the first pass no swap occur then it means that the array was already sorted and we don't have to 
  //run this for n - 1 elements of the array.

  //for (int i = 0; i < n - 1; ++i) { // outerLoop runs n - 1 times
  //    bool isSwap = false;
  //    for (int j = 0; j < n - 1 - i; ++j) { // inner loop runs from 0 to n - 1 - i times
  //        if (arr[j] < arr[j + 1]) {
  //            swap(arr[j], arr[j + 1]);
  //            isSwap = true;
  //        }
  //    }
  //    if (!isSwap) {
  //        return;
  //    }
  //}

}

void selectionSort(int arr[], int n) {
  /*
   ** simple algo which is used to sort the array in terms of sorted and unsorted
   ** portion of the array
   */
  //for (int i = 0; i < n - 1; ++i) {
  //    for (int j = i; j < n - 1; ++j) {
  //        if (arr[i] > arr[j + 1]) {
  //            swap(arr[i] , arr[j + 1]);
  //        }
  //    }
  //}
  /*
   ** A good optimized version of this algo is to delay the swap to the end of the loop
   */
  for (int i = 0; i < n - 1; ++i) {
    int largest_idx = i;
    for (int j = i; j < n - 1; ++j) {
      if (arr[largest_idx] < arr[j + 1]) {
        largest_idx = j + 1;
      }
    }
    swap(arr[largest_idx], arr[i]);
  }
};

void insert(int *arr, int i, int j, int size) {
  int element = arr[i];

  for (int s = i; s < size - 1; ++s) { //removes the element from it's current position and moves the elements to the left
    arr[s] = arr[s+1];
  }

  int cond;
  if(j == 0){
    cond = j + 1; //if the element is smaller than the first element then this case. In this case j == 0 (The first element)
  }else {
    cond = j + 2; // This is for the avg case where the element is larger than the element at j
  }
  for (int l = size - 1; l >= cond; --l){ //Make the position for the element which is going to be inserted here
    arr[l] = arr[l - 1];
  } 

  if(j == 0){
    cond = j; //The new element will be inserted in place of the first element of the array 
  }else {
    cond = j + 1; //The new element is going to be in front of the element from whose it is greater
  }
  arr[cond] = element; 
}

void insertionSort(int *arr, int size) {
  /*
     NOTE: There is also a good and easy version of this using the swap method but
     that doesn't work on linked list. However this method will
     work with linked lists aswell(I hope so, didn't try it myself tho :p)
     */
  for (int i = 1; i < size; ++i) {//This is the forward moving
    for (int j = i - 1; j >= 0; --j) {//This starts from the current and moves backward
      if (arr[i] > arr[j]) {
        insert(arr, i, j, size);
        break;
      } else {
        if (j == 0) {
          insert(arr, i, j, size);
        }
      }
    }
  }
}

//This is for sorting the const char* in an array
const char **sortedCharacterPointerArray(const char *list[], int size) {char letter[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

    /*
The position array is a 2-D array where the rows are representing all the
english alphabets and the cols represent the index of the elements starting with those letters
*/

//init the array with -1
    int pos[26][size];
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < size; ++j) {
            pos[i][j] = -1;
        }
    }
// populating the position array with the the indexes of the elements
    for (int i = 0; i < 26; ++i) {
        int idx = 0;
        for (int j = 0; j < size; ++j) {
            if (list[j][0] == letter[i] ||(list[j][0] == letter[i] + 32) ) {
                pos[i][idx] = j;
                idx++;
            }
        }
    }

    //The resulting array with sorted elements of the same size as the original array
    const char** res = new const char*[size];
    bool flag = true; int idx = 0;
    //populating the res array with the sorted indices from the pos array
    for (int i = 0; i < 26 && flag == true; ++i) {
        for (int j = 0; j < size; ++j) {
            if (pos[i][j] != -1) {
                res[idx] = list[pos[i][j]];
                idx++;
                if (idx == size)
                    flag = false;
                break;
            }
        }
    }
    return res;
}
