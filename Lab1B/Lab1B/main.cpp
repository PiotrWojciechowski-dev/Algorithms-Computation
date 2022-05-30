// Lab1B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Product.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void record();

int main()
{
    // Product Testing
    Product p1(12345, "Apple"), p2;
    p1.printer(); // Object defined product
    p2.printer(); // Default constructed prodcut
    p2.setName("Grapes"); // Testing getter and setter on p2
    p2.setCode(23456);
    p2.printer(); // Output the new p2

    // Prepacked food testing:
    PrepackedFood pf1(3.50, 23456, "Beef burgers"), pf2;
    pf1.printer();
    //pf2.scanner(); // Test scanner
    pf2.printer();

    // Fresh food testing
    FreshFood ff1(1, 2.29, 11932, "Tomatoes"), ff2;
    ff1.printer();
    //ff2.scanner();
    ff2.printer(); 
    cout << endl;

    char resp;
    record();
    while(true) {
        cout << "\nDo you want to scan a new customer (Y/N)? ";
        cin >> resp;
        if (tolower(resp) == 'y') {
            record();
        }
        else {
            cout << endl << "Ending Program...";
            break;
        }
    }
    return 0;
}

void record()
{
    vector<Product*> products(100);
    int choice, count = 0;
    double total = 0.0;
    const int MAX_PRODUCTS = products.size();
    // Changed from products.size() so each iteration isn't calling that function
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        do {
            cout << "\nPlease select the next item?" << "\n\n";
            cout << setw(7) << "0" << setw(12) << " = No more items\n";
            cout << setw(7) << "1" << setw(12) << " = Fresh food item\n";
            cout << setw(7) << "2" << setw(12) << " = Prepacked item\n";
            cout << "Enter your choice: ";
            cin >> choice;
        } while (choice < 0 && choice >= 3);

        if (choice == 0) {break;}

        switch (choice) {
            case 1:
                {
                products[i] = new FreshFood;
                products[i]->scanner();
                // Getting the getters for the derrived class was the hardest part of the lab
                // Solved it by using dynamic_cast and downcasting the Product* to FreshFood*.
                // Cast is executed at run-time so works well with polymorphic classes
                // Base-to-derived casting only works with polymorphic types
                FreshFood* FreshFoodPtr = dynamic_cast<FreshFood*>(products[i]);
                total += FreshFoodPtr->getPrice() * FreshFoodPtr->getWeight();
                count++;
                break;
                }
            case 2:
                {
                products[i] = new PrepackedFood;
                products[i]->scanner();
                PrepackedFood* PrepackedFoodPtr = dynamic_cast<PrepackedFood*>(products[i]);
                total += PrepackedFoodPtr->getPrice();
                count++;
                break;
                }  
        }
    }

    for (int i = 0; i < count; i++) {
        products[i]->printer();
    }
    cout << endl << string(25, '*');
    cout << fixed << setprecision(2) << "\nTotal price: " << total << endl;

}
