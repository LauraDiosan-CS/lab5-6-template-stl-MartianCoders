#include "repositoryF.h"

RepositoryF<Cookie>::RepositoryF():Repository<Cookie>() {
	this->fileName = NULL;
}

RepositoryF<Cookie>::RepositoryF(const char* fileName) {
	this->fileName = new char[strlen(fileName) + 1];
	strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
	this->loadFile();
}

RepositoryF<Cookie>::~RepositoryF() {}

void RepositoryF<Cookie>::addCookie(Cookie c) {
	Repository<Cookie>::addCookie(c);
	this->saveFile();
}

void RepositoryF<Cookie>::updateCookie(Cookie c) {
	Repository<Cookie>::updateCookie(c);
	this->saveFile();
}

void RepositoryF<Cookie>::deleteCookie(Cookie c) {
	Repository<Cookie>::deleteCookie(c);
}

vector<Cookie> RepositoryF<Cookie>::getAll() {
	return Repository<Cookie>::getAll();
}

int RepositoryF<Cookie>::getSize() {
	return Repository<Cookie>::getSize();
}

template<>
void RepositoryF<Cookie>::loadFile()
{
	if (this->fileName != NULL)
	{
		Repository<Cookie>::clear();
		ifstream f(this->fileName);
		int ID;
		char* name = new char[20];
		char* ingr = new char[20];
		double price;
		while (!f.eof())
		{
			f >> ID >> name >> ingr >> price;
			if (strlen(name) > 0)
			{
				Repository<Cookie>::addCookie(Cookie(ID, name, ingr, price));
			}
		}
		delete[] name;
		delete[] ingr;
		name = NULL;
		ingr = NULL;
		f.close();
	}
}

template<>
void RepositoryF<Cookie>::saveFile()
{
	if (this->fileName != NULL)
	{
		ofstream f(this->fileName);
		for (unsigned int i = 0; i < Repository<Cookie>::getSize(); i++)
		{
			f << Repository<Cookie>::getAll()[i];
		}
		f.close();
	}
}
