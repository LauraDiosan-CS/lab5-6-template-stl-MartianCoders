#include "controler.h"

Controler::Controler() {}

Controler::Controler(const Repository<Cookie>& storage) {
	this->controler = storage;
}

Controler::~Controler() {
}

void Controler::addElement(int ID, const char* name, const char* ingr, double price) {
	std::vector<Cookie> storage = this->controler.getAll();
	bool exists = false;
	for (unsigned int i = 0; i < storage.size(); i++)
		if (storage[i].getID() == ID)
			exists = true;
	if (exists == false)
		this->controler.addCookie(Cookie(ID, name, ingr, price));
}

void Controler::deleteElement(int ID) {
	std::vector<Cookie> storage = this->controler.getAll();
	for (unsigned int i = 0; i < storage.size(); i++)
		if (storage[i].getID() == ID)
			this->controler.deleteCookie(storage[i]);
}

void Controler::updateElement(int ID, const char* name, const char* ingr, double price) {
	this->controler.updateCookie(Cookie(ID, name, ingr, price));
}

int Controler::getSize() {
	return this->controler.getSize();
}

vector<Cookie> Controler::getAll() {
	return this->controler.getAll();
}