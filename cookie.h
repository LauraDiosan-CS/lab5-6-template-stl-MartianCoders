#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Cookie {
private:
	int ID;
	char* name;
	char* ingr;
	double price;
public:
	Cookie();
	Cookie(int, const char*, const char*, double);
	Cookie(const Cookie&);
	~Cookie();

	int getID();
	char* getName();
	char* getIngr();
	double getPrice();

	void setID(int);
	void setName(const char*);
	void setIngr(const char*);
	void setPrice(double);

	Cookie& operator=(const Cookie&);
	bool operator==(const Cookie&) const;
	bool operator!=(const Cookie&) const;

	friend ostream& operator<<(ostream&, const Cookie&);
};