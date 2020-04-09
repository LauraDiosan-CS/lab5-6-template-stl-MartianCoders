#pragma once
#include "repository.h"

class Controler {
private:
	Repository<Cookie>* controler;
public:
	/* Constructor & Destructor */
	Controler(); // Default
	Controler(Repository<Cookie>*); // Copy storage from another
	~Controler(); // Destructor

	/* CRUD */
	void addElement(int, const char*, const char*, double); // Creates a Cookie object and add it in storage (In: ID, name, ingr, price)
	void deleteElement(int); // Delete an element from storage using ID (In: ID)
	void updateElement(int, const char*, const char*, double); // Creates a Cookie object and update in storage (In: ID, name, ingr, price)

	int getSize(); // Returns size of storage
	vector<Cookie> getAll(); // Retunrs storage pointer
};