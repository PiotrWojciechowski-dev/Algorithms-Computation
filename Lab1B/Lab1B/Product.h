#pragma once
#include <string>
using namespace std;

class Product {

private:
	long barcode;
	string prodName;

public:
	Product(long code = 0L, const string& name = "");
	virtual ~Product();
	void setCode(long code) { barcode = code; }
	long getCode(void) const { return barcode; }
	void setName(const string& name) { prodName = name; }
	const string& getName() const { return prodName; }
	virtual void scanner(); // Read data from keyboard
	virtual void printer(void) const; // Display a product
};

class PrepackedFood : public Product {

private:
	double unitPrice; // Price per unit

public:
	PrepackedFood(double price = 0.0, long code = 0L, const string& name = "");
	void setPrice(double price) { unitPrice = price; }
	double getPrice(void) const { return unitPrice; }
	void scanner();
	void printer(void) const; 

};

class FreshFood : public Product {

private:
	double weight;
	double kiloPrice; // Price per kilo

public:
	FreshFood(double kg = 0.0, double price = 0.0, long code = 0L, const string& name = "");
	void setWeight(double kg) { weight = kg; }
	double getWeight(void) const { return weight; }
	void setPrice(double price) { kiloPrice = price; }
	double getPrice(void) const { return kiloPrice; }
	void scanner();
	void printer(void) const;
};