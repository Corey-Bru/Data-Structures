// Lab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void initializeArray(int arr[], int size) {
    for (int i{ 0 }; i < size; i++) {
        int number = std::rand() % size + 1;
        arr[i] = number;
    }
}

void printArray(int arr[], int size) {
    //int size = sizeof(arr);
    for (int i{ 0 }; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//Source referenced: https://www.geeksforgeeks.org/bubble-sort-in-cpp/
/*
How it works:
    Starts with the first element in the array and compares it to the next one, if it's larger, they swap. This
    continues until each element in the array has been checked.

Example: 
    [5, 3, 8, 4, 6]
        Compare 5 and 3, swap if 5 is larger
    [3, 5, 8, 4, 6]
        Compare 5 and 8, swap if 5 is larger
    [3, 5, 8, 4, 6]
        Compare 8 and 4, swap if 8 is larger
    [3, 5, 4, 8, 6]
        Compare 8 and 6, swap if 8 is larger
    [3, 5, 4, 6, 8]
        Repeat steps until all sorted...
*/
void bubbleSort(int arr[]) {
    int size = sizeof(arr);
    for (int i{ 0 }; i < size - 1; i++) {
        for (int j{ 0 }; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Source referenced: https://www.geeksforgeeks.org/cpp-program-for-insertion-sort/
/*
How it works:

*/
void insertionSort(int arr[]) {
    int key;
    int j;
    int i;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}
void merge(int left[], int leftSize, int right[], int rightSize, int arr[]) {

    int i = 0;
    int l = 0;
    int r = 0;

    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            arr[i] = left[l];
            i++;
            l++;
        }
        else {
            arr[i] = right[r];
            i++;
            r++;
        }
    }
    while (l < leftSize) {
        arr[i] = left[l];
        i++;
        l++;
    }
    while (r < rightSize) {
        arr[i] = right[r];
        i++;
        r++;
    }
    //printArray(arr, sizeof(arr));

}
void mergeSort(int arr[], int size) {
    
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    int* left = new int[mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
        //std::cout << left[i] << " ";
    }
    int* right = new int[size - mid];
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
       // std::cout << right[i] << " ";
    }
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(left,mid, right,size - mid, arr);
    delete[] left;
    delete[] right;
}
void quickSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    int piv = arr[size - 1];
    int i = -1;
    for (int j = 0; j < size - 1; j++) {
       if (arr[j] < piv) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
           
        }
    
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[size - 1];
    arr[size - 1] = temp;

    quickSort(arr, i);
    quickSort(arr + i + 1, size - i - 1);
    
}

void countingSort(int arr[], int size) {
    int* count = new int[size]();
    int* valChecked = new int[size]();
    bool seen = 0;
    for (int i = 0; i < size; i++) {
        seen = 0;
        for (int z = 0; z < size; z++) {
            if (arr[i] == valChecked[z]) {
                seen = 1;
                break;
            }
        }
        valChecked[i] = arr[i];
        if (seen) {
            continue;
        }
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count[i] += 1;
            }
        }
    }
    int dex = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[dex] = valChecked[i];
            dex++;
       }
    }
    delete[] count;
    delete[] valChecked;
}
int main()
{
    int arr10[10];
    int arr100[100];
    int arr500[500];
    int arr5000[5000];
    int arr25000[25000];
    int arr1000000[100000];

    initializeArray(arr10, 10);
    std::cout << "Printing array of 10 random numbers: " << std::endl;
    printArray(arr10, 10);
    std::cout << "Insertion sorting array: " << std::endl;
    /*insertionSort(arr10);
    printArray(arr10);*/
    //int size = sizeof(arr10);
    countingSort(arr10, 10);
    printArray(arr10, 10);
}
