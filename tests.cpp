#include <iostream>
#include <assert.h>
#include <sstream>
#include "cookie.h"
#include "tests.h"
#include "repository.h"
#include "repositoryF.h"
#include "controler.h"

void test_cookie() {
	Cookie c1(1, "briosa", "nimic", 100);
	assert(c1.getID() == 1);
	assert(strcmp(c1.getName(), "briosa") == 0);
	assert(strcmp(c1.getIngr(), "nimic") == 0);
	assert(c1.getPrice() == 100);
	
	Cookie c2(2, "tort", "apa", 150);

	Cookie c3;
	c1 = c2;
	assert(c1 == c2);
	assert(c1 != c2 == false);
	c1.setName("acadea");
	assert(c1 != c2);
	assert(c1 == c2 == false);

	std::stringstream string;
	string << c1;
	assert(string.str() == "2 acadea apa 150\n");
}

void test_repository() {
	Repository<Cookie> storage;
	Cookie c(1, "briosa", "nimic", 100);
	storage.addCookie(c);
	assert(storage.getSize() == 1);
	Cookie c2(1, "mancare", "nimic", 150);
	storage.updateCookie(c2);
	assert(storage.getAll()[0] == c2);
	storage.deleteCookie(c2);
	assert(storage.getSize() == 0);
}

void test_repositoryF() {
	RepositoryF<Cookie> storage("test.txt");
	Cookie c(1, "briosa", "nimic", 100);
	storage.addCookie(c);
	assert(storage.getSize() == 1);
	Cookie c2(1, "mancare", "nimic", 150);
	storage.updateCookie(c2);
	assert(storage.getAll()[0] == c2);
	storage.deleteCookie(c2);
	assert(storage.getSize() == 0);
	storage.clear();
}

void test_controler() {
	Repository<Cookie>* storage;
	storage = new RepositoryF<Cookie>("data.txt");
	Controler controler(storage);
	controler.addElement(1, "briosa", "nimic", 150);
	assert(controler.getSize() == 1);
	controler.addElement(1, "tort", "da", 100);
	assert(controler.getSize() == 1);
	controler.deleteElement(1);
	assert(controler.getSize() == 0);
	controler.addElement(1, "briosa", "nimic", 150);
	controler.updateElement(1, "tort", "da", 100);
	assert(strcmp(controler.getAll()[0].getName(), "tort") == 0);
	assert(strcmp(controler.getAll()[0].getIngr(), "da") == 0);
	assert(controler.getAll()[0].getPrice() == 100);
	controler.deleteElement(1);
}

void test_all() {
	test_cookie();
	test_repository();
	test_repositoryF();
	//test_controler();
}
