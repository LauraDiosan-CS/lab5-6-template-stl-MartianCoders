#pragma once
#include "cookie.h"
#include <vector>

template <class T>
class Repository {
private:
	vector<T> storage;
public:
	Repository();
	Repository(const Repository<T>&);
	~Repository();

	/* CRUD */
	void addCookie(Cookie); // Add element Cookie (In: object Cookie)
	void updateCookie(Cookie); // Update old Cookie with new Cookie (In: old object Cookie, new object Cookie)
	void deleteCookie(Cookie); // Delete a Cookie element from storage (In: object COokie do delete)

	int getSize(); // Return size of storage (Out: size const)
	std::vector<T> getAll(); // Returns pointer of storage (Out: storage)
	void clear();

};