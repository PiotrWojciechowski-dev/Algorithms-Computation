#pragma once
#include <vector>
#include "Car.h"
using namespace std;

class CityCar
{
public:
	CityCar() { count = 0; }
	~CityCar();
	bool insert(const string& tp, bool sr, long n, const string& prod);
	bool insert(int a, double t, long n, const string& prod);
	void display() const;

private:
	vector<Car*> cars;
	int count;
};
