#include "Car.h"
#include <iostream>

Car::Car(const string& mk, const string& mdl) : make(mk), model(mdl) {}

bool Car::operator==(const Car& car) const
{
	return (make == car.make) && (model == car.model);
}

