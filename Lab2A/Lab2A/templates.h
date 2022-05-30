#pragma once
#include <iostream>
using namespace std;

template<typename T>
void insertionSort(T* arrPtr, int size) {
    int i, j;
    T key;
    for (i = 1; i < size; i++)
    {
        key = arrPtr[i];
        j = i - 1;

        /* Move elements of arrPtr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arrPtr[j] > key)
        {
            arrPtr[j + 1] = arrPtr[j];
            j = j - 1;
        }
        arrPtr[j + 1] = key;
    }
}

template<typename T>
void display(T* arrPtr, int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arrPtr[i] << " ";
    cout << endl;
}

template<typename T>
bool isEqualTo(T arg1, T arg2) {
    if (arg1 == arg2) { return true; }
    return false;
}