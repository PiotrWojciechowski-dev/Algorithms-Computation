#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Product::Product(long code, const string& name) : barcode(code), prodName(name) {}

Product::~Product() {}

void Product::scanner()
{
	cout << "Product name: ";
	cin >> prodName;
	cout << "Barcode: ";
	cin >> barcode;
}

void Product::printer(void) const
{
	cout << string(30, '*');
	cout << "\nProduct name: " << prodName;
	cout << "\nBarcode: " << barcode << endl;
}

PrepackedFood::PrepackedFood(double price, long code, const string& name) : Product(code, name), unitPrice(price) {}

void PrepackedFood::scanner()
{
	cout << "\nEnter prepacked food information:\n";
	Product::scanner();
	cout << "Price per unit: ";
	cin >> unitPrice;
}

void PrepackedFood::printer(void) const
{
	cout << "\nPrepacked food details:" << endl;
	Product::printer();
	cout << fixed << setprecision(2) << "Price per unit: " << unitPrice << endl;
}

FreshFood::FreshFood(double kg, double price, long code, const string& name) : Product(code, name), weight(kg), kiloPrice(price) {}

void FreshFood::scanner()
{
	cout << "\nEnter fresh food information:\n";
	Product::scanner();
	cout << "Weight in kg: ";
	cin >> weight;
	cout << "Price per kilo: ";
	cin >> kiloPrice;
}

void FreshFood::printer(void) const
{
	cout << "\nFresh food details:" << endl;
	Product::printer();
	cout << "Weight in kg: " << weight;
	cout << "\nPrice per kilo: " << kiloPrice << endl;
}
