#pragma once
#include "cookie.h"
#include "repository.h"
#include <vector>

template <class T>
class RepositoryF: public Repository<T> {
private:
	char* fileName;
public:
	/* Constructor & Destructor */
	RepositoryF(); // Defalut
	RepositoryF(const char*); // By given fileName (In: fileName) 
	RepositoryF(const RepositoryF<T>&); // Copy storage
	~RepositoryF(); // Destructor

	/* CRUD */
	void addCookie(Cookie); // Add element Cookie (In: object Cookie)
	void updateCookie(Cookie); // Update old Cookie with new Cookie (In: old object Cookie, new object Cookie)
	void deleteCookie(Cookie); // Delete a Cookie element from storage (In: object COokie do delete)

	/* Get's */
	char* getFile(); // Returns fileName pointer (Out: fileName)
	int getSize(); // Return size of storage (Out: size const)
	std::vector<T> getAll(); // Returns pointer of storage (Out: storage)

	/* File operations */
	void saveFile(); // Save data
	void loadFile(); // Load data
};