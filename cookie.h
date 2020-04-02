#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Cookie {
private:
	int ID;
	char* name;
	char* ingredients;
	double price;
public:
	Cookie();
	Cookie(int, const char*, const char*, double);
	~Cookie();

	void setID(int);
	void setName(const char*);
	void setIng(const char*);
	void setPrice(double);

	int getID();
	char* getName();
	char* getIng();
	double getPrice();

	Cookie& operator=(const Cookie&);

	bool operator<(const Cookie&);
	bool operator>(const Cookie&);
	bool operator==(const Cookie&);
	bool operator!=(const Cookie&);

	friend ostream& operator<<(ostream&, const Cookie&);
};