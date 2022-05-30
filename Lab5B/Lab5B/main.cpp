#include <iostream>
#include <random>
#include <Windows.h>
using namespace std;

int quickSortDivide(int* theArray, int size);
void optimizedQuickSort(int* theArray, int size);
void insertionSort(int arr[], int low, int n);
void quickSort(int* theArray, int size);
double get_wall_time();
double get_cpu_time();

int main()
{
    random_device seed;
    mt19937 gen{ seed() }; // seed the generator
    uniform_int_distribution<> dist{ 1,1000 }; // set min and max
    const int size = 250000;
    int* theArray = new int[size];
    for (int i = 0; i < size; i++) {
        theArray[i] = dist(gen);
    }
    // Start timers
    double ArrWall = get_wall_time();
    double ArrCpu = get_cpu_time();
    optimizedQuickSort(theArray, size - 1);
    //  Stop timers
    double ArrWallEnd = get_wall_time();
    double ArrCpuEnd = get_cpu_time();
    cout << "\nWall Time = " << ArrWallEnd - ArrWall << endl;
    cout << "CPU Time  = " << ArrCpuEnd - ArrCpu << endl << endl;
    cout << endl;
    delete[] theArray;
    /*
    //delete[] theArray;
    const int size2 = 100000;
    int* theArray2 = new int[size2];
    for (int i = 0; i < size2; i++) {
        theArray2[i] = i;
    }
    // Start timers
    double ArrWall2 = get_wall_time();
    double ArrCpu2 = get_cpu_time();
    optimizedQuickSort(theArray2, size);
    //  Stop timers
    double ArrWall2End = get_wall_time();
    double ArrCpu2End = get_cpu_time();
    cout << "Wall Time = " << ArrWall2End - ArrWall2 << endl;
    cout << "CPU Time  = " << ArrCpu2End - ArrCpu2 << endl;
    delete[] theArray2;
    */
    return 0;
}

int quickSortDivide(int* theArray, int size) {
    int pivot = theArray[size];
    int index = -1;
    for (int j = 0; j < size; j++) {
        if (theArray[j] <= pivot) {
            index++;
            swap(theArray[index], theArray[j]);
            
        }
    }
    swap(theArray[index + 1], theArray[size]); 
    return (index + 1);
}

void optimizedQuickSort(int* theArray, int size)
{
    int start = 0;
    // base case
    while (size > start) {
        if (size - start < 10) {
            insertionSort(theArray, start, size);
            break;
        }
        else {
            int pivotIndex = start + quickSortDivide(&theArray[start], size - start);
            if ((pivotIndex - start) <= (size - pivotIndex)) {
                optimizedQuickSort(&theArray[start], pivotIndex - start - 1);
                start = pivotIndex + 1;
            }
            else {
                optimizedQuickSort(&theArray[pivotIndex + 1], size - (pivotIndex + 1));
                size = pivotIndex - 1;
            }
        }
    }
}

void insertionSort(int arr[], int low, int n)
{
    // Start from the second element (the element at index 0
    // is already sorted)
    for (int i = low + 1; i <= n; i++)
    {
        int value = arr[i];
        int j = i;

        // find index `j` within the sorted subset `arr[0…i-1]`
        // where element `arr[i]` belongs
        while (j > low && arr[j - 1] > value)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        // note that subarray `arr[j…i-1]` is shifted to
        // the right by one position, i.e., `arr[j+1…i]`

        arr[j] = value;
    }
}

void quickSort(int* theArray, int size)
{
    // base case
    if (size <= 1) {
        return;
    }
    int pivotIndex = quickSortDivide(theArray, size);
    quickSort(theArray, pivotIndex - 1);
    quickSort(&theArray[pivotIndex + 1], size - (pivotIndex + 1));
}


double get_wall_time() {
    LARGE_INTEGER time, freq;
    if (!QueryPerformanceFrequency(&freq)) {
        //  Handle error
        return 0;
    }
    if (!QueryPerformanceCounter(&time)) {
        //  Handle error
        return 0;
    }
    return (double)time.QuadPart / freq.QuadPart;
}

double get_cpu_time() {
    FILETIME a, b, c, d;
    if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0) {
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
            (double)(d.dwLowDateTime |
                ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }
    else {
        //  Handle error
        return 0;
    }
}
