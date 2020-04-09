#include "repository.h"

Repository<Cookie>::Repository() {

}



Repository<Cookie>::Repository(const Repository<Cookie>& repo) {
	this->storage.clear();
	for (unsigned int i = 0; i < repo.storage.size(); i++)
		this->storage.push_back(repo.storage[i]);
}

Repository<Cookie>::~Repository() {}

void Repository<Cookie>::addCookie(Cookie c) {
	this->storage.push_back(c);

}

void Repository<Cookie>::updateCookie(Cookie c) {
	for (unsigned int i = 0; i < this->storage.size(); i++)
		if (this->storage[i].getID() == c.getID())
		{
			storage[i].setName(c.getName());
			storage[i].setIngr(c.getIngr());
			storage[i].setPrice(c.getPrice());
		
		}
}
void Repository<Cookie>::deleteCookie(Cookie c) {
	for (unsigned int i = 0; i < this->storage.size(); i++)
		if (this->storage[i] == c)
		{
			this->storage[i] = this->storage[this->storage.size() - 1];
			this->storage.pop_back();
			
		}
}

vector<Cookie> Repository<Cookie>::getAll() {
	return this->storage;
}

int Repository<Cookie>::getSize() {
	return this->storage.size();
}

void Repository<Cookie>::clear() {
	this->storage.clear();
}
