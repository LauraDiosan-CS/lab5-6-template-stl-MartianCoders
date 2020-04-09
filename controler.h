#pragma once
#include "repository.h"
class Controler {
private:
	Repository<Cookie> controler;
public:
	Controler();
	Controler(const Repository<Cookie>&);
	~Controler();

	void addElement(int, const char*, const char*, double);
	void deleteElement(int);
	void updateElement(int, const char*, const char*, double);

	int getSize();
	vector<Cookie> getAll();
};