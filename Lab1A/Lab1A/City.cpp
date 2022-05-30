#include "City.h"
#include <iostream>
using namespace std;

CityCar::~CityCar()
{
	for (int i = 0; i < count; ++i) {
		delete cars[i];
	}
}

// Pass Car insert
bool CityCar::insert(const string& tp, bool sr, long n, const string& prod)
{
	if (count < cars.max_size()) {
		cars.push_back(new PassCar(tp, sr, n, prod));
		count++;
		return true;
	}
	return false;
}

// Truck insert
bool CityCar::insert(int a, double t, long n, const string& prod)
{
	if (count < cars.max_size()) {
		cars.push_back(new Truck(a, t, n, prod));
		count++;
		return true;
	}
	return false;
}

void CityCar::display() const
{
	for (int i = 0; i < count; ++i) {
		cars[i]->display();
	}
}
