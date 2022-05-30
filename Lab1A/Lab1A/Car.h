#pragma once
#include <string>
using namespace std;

class Car
{
private:
	long nr;
	string producer;

public:
	Car(long n = 0L, const string& prod = "");
	virtual ~Car(); // Virtual Destructor
	// Access methods:
	long getNr(void) const { return nr; }
	void setNr( long n ) { nr = n; }
	const string& getProd() const{ return producer; }
	void setProd(const string& p){ producer = p; }
	virtual void display( void ) const; // Display a car
};

class PassCar : public Car // Derived class
{
private:
	string passCarType;
	bool sunRoof;

public: // Constructor:
	PassCar(const string& tp, bool sd, int n = 0, const string& h = "");
	~PassCar();
	// Access methods:
	const string& getType() const{ return passCarType; }
	void setType( const string s) { passCarType = s; }
	bool getSunRoof() const { return sunRoof; }
	void setSunRoof( bool b ) { sunRoof = b; }
	void display() const; 
};

class Truck : public Car // Derived class
{
private:
	int numberofAxles;
	double loadCapacity;

public: // Constructor:
	Truck(int noa, double c, int n = 0, const string& h = "");
	~Truck();
	// Access methods:
	int getNumAxles(void) const { return numberofAxles; }
	void setNumAxles(int noa) { numberofAxles = noa; }
	double getCapacity(void) const { return loadCapacity; }
	void setCapacity(double c) { loadCapacity = c; }
	void display() const;
};