#include "Car.h"
#include <iostream>
using namespace std;

// Car Constructer
Car::Car(long n, const string& prod) : nr(n), producer(prod) {}

Car::~Car()
{
	cout << "\nDestroying an object of type Car" << endl;
}

void Car::display(void) const
{
	cout << "---------------------------- ";
	cout << "\nCar number: " << nr;
	cout << "\nProducer: " << producer;
}

// Pass Car Constructer
PassCar::PassCar(const string& tp, bool sd, int n, const string& h) : Car(n, h), passCarType(tp), sunRoof(sd) {}

PassCar::~PassCar()
{
	cout << "\nDestroying an object of type PassCar" << endl;
}

void PassCar::display() const
{
	cout << "\nPass Car details" << endl;
	Car::display();
	cout << "\nType: " << passCarType;
	cout << "\nSun Roof: ";
	if (sunRoof) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

// Truck Constructer
Truck::Truck(int noa, double c, int n, const string& h) :Car(n,h), numberofAxles(noa), loadCapacity(c) {}

Truck::~Truck()
{
	cout << "\nDestroying an object of type Truck" << endl;
}

void Truck::display() const
{
	cout << "\nTruck details" << endl;
	Car::display();
	cout << "\nNumber of Axles: " << numberofAxles;
	cout << "\nLoad Capacity: " << loadCapacity << endl;

}

