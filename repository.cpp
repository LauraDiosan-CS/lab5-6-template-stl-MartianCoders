#include "repository.h"

Repository<Cookie>::Repository() {}

Repository<Cookie>::~Repository() {
	this->storage.clear();
}

void Repository<Cookie>::addCookie(Cookie c) {
	this->storage.push_back(c);
}

void Repository<Cookie>::updateCookie(Cookie& c1, Cookie& c2) {
	for (int i = 0; i < this->storage.size(); i++)
		if (this->storage[i] == c1)
			c1 = c2;
}
void Repository<Cookie>::deleteCookie(Cookie& c) {
	for(int i = 0; i < this->storage.size(); i++)
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

