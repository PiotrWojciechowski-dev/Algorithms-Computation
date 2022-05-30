#include <iostream>
using namespace std;

int quickSortDivide(int* theArray, int size);
void quickSort(int *theArray, int size);
void mergeSort(int arrayToSort[], int startIndex, int lengthToSort);
void merge(int arraySortedInTwoHalves[], int startIndex, int length);

int main()
{
    const int size = 12;
    int theArray[size] = { 15, 19, 34, 41, 27, 13, 9, 11, 44, 15, 1, 4 };
    int theArray2[size] = { 15, 19, 34, 41, 27, 13, 9, 11, 44, 15, 1, 4 };
    cout << "Array before quick sort\n";
    for (const auto &i : theArray) {
        cout << i << " ";
    }
    cout << endl;
    quickSort(theArray, size);
    cout << "Array after quick sort\n";
    for (const auto& i : theArray) {
        cout << i << " ";
    }
    cout << "\n\nArray before merge sort\n";
    for (const auto &i : theArray2) {
        cout << i << " ";
    }
    cout << endl;
    mergeSort(theArray2, 0, size - 1);
    cout << "Array after merge sort\n";
    for (const auto& i : theArray2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

int quickSortDivide(int* theArray, int size) {

    // Set the pivot to the first element
    int pivot = *theArray;
    // Set index i to 1 i.e second element
    int index = 1;
    // Loop over the current size
    for (int j = 1; j < size; j++) {
        // if the element at j is less than or equal to the pivot
        // switch the element at index with j
        // increment index;
        if (theArray[j] <= pivot) {
            swap(theArray[index], theArray[j]);
            index++;
        }
    }
    // Once all the necessary swaps are made all the elements that are lesser than pivot
    // should be on the left and larger elements should be on the right.
    swap(theArray[0], theArray[index - 1]);  //put the pivot element in its proper place.
    // Return the correct pivot index
    return index - 1;
}

// Time complexity is O(n log n)
void quickSort(int* theArray, int size)
{
    // base case
    if (size <= 1) {
        return;
    }
    // partitioning the array and get the index of the partition
    int pivotIndex = quickSortDivide(theArray, size);
    // sort the left side of the partition each time decreasing the size
    quickSort(theArray, pivotIndex); 
    // sort the right side of the partition unti the size is 1
    quickSort(theArray + pivotIndex + 1, size - pivotIndex - 1);
}

// Time complexity is O(n log n)
void mergeSort(int arrayToSort[], int startIndex, int lengthToSort)
{
    // base case
    if (startIndex >= lengthToSort) {
        return;
    }
    // Find the mid point of an array
    int mid = (startIndex + lengthToSort) / 2;
    // Continue to divide the left array until it is of size 1
    mergeSort(arrayToSort, startIndex, mid);
    // Continue to divide the right array until it is of size 1
    mergeSort(arrayToSort, mid + 1, lengthToSort);
    // merge back the array
    merge(arrayToSort, startIndex, lengthToSort);
}

void merge(int arraySortedInTwoHalves[], int startIndex, int length)
{

    int size = (length - startIndex) + 1;
    // pointer to dynamic array
    int* temp = new int[size];
    // mid point for current array
    int mid = (startIndex + length) / 2;
    // index of left array
    int i = startIndex;
    // index of right array
    int j = mid + 1;
    // index of temp array
    int k = 0;
    // While there are elements in both sides
    // iterate over and check which element in both arrays is smaller
    // Once checked add it to temp array
    while (i <= mid && j <= length) {
        if (arraySortedInTwoHalves[i] < arraySortedInTwoHalves[j]) {
            temp[k] = arraySortedInTwoHalves[i];
            i++;
        }
        else {
            temp[k] = arraySortedInTwoHalves[j];
            j++;
        }
        k++;
    }
    // If the right arrray has reached its end
    // store the rest of the numbers in the left array
    // in temp array
    while (i <= mid)
    {
        temp[k] = arraySortedInTwoHalves[i];
        i++;
        k++;
    }
    // Vice versa if the left arrray has reached its end
    // store remaing elements in temp
    while (j <= length)
    {
        temp[k] = arraySortedInTwoHalves[j];
        j++;
        k++;
    }
    // Copy values of temp value back to orginal array
    for (k = 0; k < size; k++) { 
        arraySortedInTwoHalves[startIndex + k] = temp[k];
    }
    // delete the temp array
    delete[] temp;
}
