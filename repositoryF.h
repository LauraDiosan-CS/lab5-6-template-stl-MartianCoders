#pragma once
#include "cookie.h"
#include "repository.h"
#include <vector>

template <class T>
class RepositoryF: public Repository<T> {
private:
	char* fileName;
public:
	RepositoryF();
	RepositoryF(const char*);
	RepositoryF(const RepositoryF<T>&);
	~RepositoryF();

	/* CRUD */
	void addCookie(Cookie); // Add element Cookie (In: object Cookie)
	void updateCookie(Cookie); // Update old Cookie with new Cookie (In: old object Cookie, new object Cookie)
	void deleteCookie(Cookie); // Delete a Cookie element from storage (In: object COokie do delete)

	char* getFile();
	int getSize(); // Return size of storage (Out: size const)
	std::vector<T> getAll(); // Returns pointer of storage (Out: storage)

	void saveFile();
	void loadFile();
};