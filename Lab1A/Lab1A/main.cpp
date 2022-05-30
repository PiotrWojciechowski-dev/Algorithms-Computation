// Lab1A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <iomanip>
#include "car.h"
#include "City.h"
using namespace std;

char menu() {
    char choice;
    cout << string(12, '*') << "Car Rental Management" << string(12, '*') << "\n\n";
    cout << setw(13) << "P" << setw(23) << "= Add a passenger car\n";
    cout << setw(13) << "T" << setw(15) << "= Add a truck\n";
    cout << setw(13) << "D" << setw(20) << "= Display all cars\n";
    cout << setw(13) << "Q" << setw(8) << "= Quit\n\n";
    cout << "Your choice:";
    cin >> choice; 
    return tolower(choice);
}

void getPassCar(string& tp, bool& sd, long& n, string& prod) {
    char q;
    cout << "\nEnter passenger car data:" << endl;
    cout << "Car type: ";
    cin >> tp;
    cout << "Sun roof (Y/N): ";
    do {
        cin >> q;
        if (tolower(q) == 'y') {
            sd = true;
        }
        else {
            sd = false;
        }
    } while (q != 'y' && q != 'n');
    cout << "Car number: ";
    cin >> n;
    cout << "Producer: ";
    cin >> prod;
}

void getTruck(int& noa, double& c, long& n, string& prod) {
    cout << "\nEnter truck data:" << endl;
    cout << "Number of axles: ";
    cin >> noa;
    cout << "Weight in kg: ";
    cin >> c;
    cout << "Car number: ";
    cin >> n;
    cout << "Producer: ";
    cin >> prod; 
}

int main()
{
    CityCar car;
    string tp, prod;
    bool sd;
    int noa;    
    long n;  
    double c;
    char choice;
    PassCar toyota("Avalon", false, 3421, "Toyota");
    toyota.display();
    Truck lorry(3, 1000, 1221, "Ford");
    lorry.display();
    cout << endl;

    do {
        choice = menu();
        switch (choice) {
        case 'p': 
            getPassCar(tp, sd, n, prod);
            car.insert(tp, sd, n, prod);
            break;
        case 't':
            getTruck(noa, c, n, prod);
            car.insert(noa, c, n, prod);
            break;
        case 'd':
            car.display();
            break;
        }
        cout << endl;
    } while (choice != 'q');

    return 0;
}

