#include "cookie.h"
Cookie::Cookie() {
	this->ID = 0;
	this->price = 0;
	this->name = NULL;
	this->ingr = NULL;
}

Cookie::Cookie(int ID, const char* name, const char* ingr, double price) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->ingr = new char[strlen(ingr) + 1];
	strcpy_s(this->ingr, strlen(ingr) + 1, ingr);
	this->ID = ID;
	this->price = price;
}

Cookie::Cookie(const Cookie& c) {
	this->name = new char[strlen(c.name) + 1];
	this->ingr = new char[strlen(c.ingr) + 1];
	strcpy_s(this->name, strlen(c.name) + 1, c.name);
	strcpy_s(this->ingr, strlen(c.ingr) + 1, c.ingr);
	this->ID = c.ID;
	this->price = c.price;
}

Cookie::~Cookie() {	
	if (this->name != NULL)
		delete[] this->name;
	if (this->ingr != NULL)
		delete[] this->ingr;
}

int Cookie::getID() {
	return this->ID;
}

char* Cookie::getName() {
	return this->name;
}

char* Cookie::getIngr() {
	return this->ingr;
}

double Cookie::getPrice() {
	return this->price;
}

void Cookie::setID(int ID2) {
	this->ID = ID2;
}

void Cookie::setName(const char* name2) {
	if (this->name != NULL)
		delete[] this->name;
	this->name = new char[strlen(name2) + 1];
	strcpy_s(this->name, strlen(name2) + 1, name2);
}

void Cookie::setIngr(const char* ingr2) {
	if (this->ingr != NULL)
		delete[] this->ingr;
	this->ingr = new char[strlen(ingr2) + 1];
	strcpy_s(this->ingr, strlen(ingr2) + 1, ingr2);
}

void Cookie::setPrice(double price2) {
	this->price = price2;
}

Cookie& Cookie::operator=(const Cookie& c) {
	this->setName(c.name);
	this->setIngr(c.ingr);
	this->setID(c.ID);
	this->setPrice(c.price);
	return *this;

}

bool Cookie::operator==(const Cookie& c) const {
	if (strcmp(this->name, c.name) == 0 && strcmp(this->ingr, c.ingr) == 0 && this->ID == c.ID && this->price == c.price)
		return true;
	return false;
}

bool Cookie::operator!=(const Cookie& c) const {
	if (strcmp(this->name, c.name) == 0 && strcmp(this->ingr, c.ingr) == 0 && this->ID == c.ID && this->price == c.price)
		return false;
	return true;
}

ostream& operator<<(ostream& os, const Cookie& c) {
	os << c.ID << ' ' << c.name << ' ' << c.ingr << ' ' << c.price << endl;
	return os;
}
