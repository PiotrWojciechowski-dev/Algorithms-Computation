#include "templates.h"
#include "car.h"
#include <iostream>

int main()
{
    // Part A - Testing
    cout << "Part A - Testing\n";
    cout << string(18, '*') << endl;
    int intArr[] = { 6, 1, 9, 12, 20 };
    double dblArr[] = { 7.3, 2.9, 19.1, 3.3, 15.2};

    // Calculates length of array
    int size = sizeof(intArr) / sizeof(intArr[0]);

    insertionSort(intArr, size);
    display(intArr, size);

    size = sizeof(dblArr) / sizeof(dblArr[0]);
    insertionSort(dblArr, size);
    display(dblArr, size);

    // Part B - Testing
    cout << "\nPart B - Testing\n";
    cout << string(18, '*') << endl;
    char char1 = 'b';
    char char2 = 'c';
    cout << "char1 = 'b' == char2 = 'c': " << boolalpha << isEqualTo(char1, char2) << endl;

    int a = 1, b = 1;
    cout << "a = '1' == b = '1': " << boolalpha << isEqualTo(a, b) << endl;

    Car car1("Ford", "Mustang");
    Car car2("Toyota", "Prius");
    Car car3("Ford", "Mustang");

    cout << "\ncar1 == car2: " << boolalpha << isEqualTo(car1, car2) << endl;
    cout << "car1 == car3: " << boolalpha << isEqualTo(car1, car3) << endl;
    return 0;
}