#pragma once
#include <string>
using namespace std;

class Car {
private:
	string make;
	string model;

public:
	Car(const string& mk = "", const string& mdl = "");
	bool operator ==(const Car&) const;
};