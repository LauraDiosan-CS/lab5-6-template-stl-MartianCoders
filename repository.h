#pragma once
#include "cookie.h"
#include <vector>

template <class T>
class Repository {
private:
	vector<T> storage;
public:
	/* Constructor & Destructor */
	Repository(); // Defalut
	Repository(const Repository<T>&); // Given storage
	~Repository(); // Destructor

	/* CRUD */
	virtual void addCookie(Cookie); // Add element Cookie (In: object Cookie)
	virtual void updateCookie(Cookie); // Update old Cookie with new Cookie (In: old object Cookie, new object Cookie)
	virtual void deleteCookie(Cookie); // Delete a Cookie element from storage (In: object COokie do delete)

	/* Get's */
	int getSize(); // Return size of storage (Out: size const)
	std::vector<T> getAll(); // Returns pointer of storage (Out: storage)
	
	void clear(); // Clear storage

};