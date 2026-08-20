#include <iostream>

void swap(int &a, int &b) {
    int c;
    c = a;
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

void show(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << std::endl;
    }
}
void insert(int *arr, int i, int j, int size) {
    int element = arr[i];

    for (int s = i; s < size - 1; ++s) {
        arr[s] = arr[s+1];
    }

    for (int l = size - 1; l >= j + 2; --l) {
        arr[l] = arr[l - 1];
    }
    arr[j + 1] = element;

}
void specialInsert(int *arr, int i, int j, int size) {
    int element = arr[i];

    for (int s = i; s < size - 1; ++s) {
        arr[s] = arr[s+1];
    }

    for (int l = size - 1; l >= j + 1; --l) {
        arr[l] = arr[l - 1];
    }
    arr[j + 0] = element;
}
void insertionSort(int *arr, int size) {
  /*
   *I am proud that this shit is implemented end to end without even looking at
    the code once by me
   */
    for (int i = 1; i < size; ++i) {//This is the forward moving
        for (int j = i - 1; j >= 0; --j) {//This starts from the current and moves backward
            if (arr[i] > arr[j]) {
               insert(arr, i, j, size);
               break;
          }else {
                if (j == 0) {
                    specialInsert(arr, i, j, size);
                }
            }
        }
    }
}
int main() {
    const int size = 5;
    int arr[] = {5,1,2,3,4};
    insertionSort(arr, size);

    show(arr, size);
    return 0;
}
