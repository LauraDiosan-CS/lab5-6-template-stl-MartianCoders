#include "cookie.h"

Cookie::Cookie() {
	this->name = NULL;
}

Cookie::Cookie(int ID, const char* name, const char* ing, double price) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->ingredients = new char[strlen(ing) + 1];
	strcpy_s(this->ingredients, strlen(ing) + 1, ing);
	this->ID = ID;
	this->price = price;
}

Cookie::~Cookie() {
	if (this->name)
		delete[] this->name;
	this->name = NULL;
	if (this->ingredients)
		delete[] this->ingredients;
	this->ingredients = NULL;
}

void Cookie::setID(int ID) {
	this->ID = ID;
}

void Cookie::setName(const char* name) {
	if (this->name)
		delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Cookie::setIng(const char* ing) {
	if (this->ingredients)
		delete[] this->ingredients;
	this->ingredients = new char[strlen(ing) + 1];
	strcpy_s(this->ingredients, strlen(ing) + 1, ing);
}

void Cookie::setPrice(double price) {
	this->price = price;
}

int Cookie::getID() {
	return this->ID;
}

double Cookie::getPrice() {
	return this->price;
}

char* Cookie::getName() {
	return this->name;
}

char* Cookie::getIng() {
	return this->ingredients;
}

Cookie& Cookie::operator=(const Cookie& c) {
	this->setID(c.ID);
	this->setName(c.name);
	this->setIng(c.ingredients);
	this->setPrice(c.price);
	return *this;
}

bool Cookie::operator==(const Cookie& c) {
	return strcmp(this->name, c.name) == 0 && strcmp(this->ingredients, c.ingredients) == 0 && this->ID == c.ID && this->price == c.price;
}

ostream& operator<<(ostream& os, const Cookie& c) {
	os << c.ID << ' ' << c.name << ' ' << c.ingredients << ' ' << c.price;
	return os;
}