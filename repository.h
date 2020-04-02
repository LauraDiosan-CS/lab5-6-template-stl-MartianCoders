#pragma once
#include "cookie.h"

#include <vector>

template <class Cookie>
class Repository {
private:
	std::vector<Cookie> storage;
public:
	/* Constructor & Destructor */
	Repository();
	~Repository();

	void setFile(const char* file); // Set file name to read data (In: file name)
	
	/* CRUD */
	void addCookie(Cookie); // Add element Cookie (In: object Cookie)
	void updateCookie(Cookie&, Cookie&); // Update old Cookie with new Cookie (In: old object Cookie, new object Cookie)
	void deleteCookie(Cookie&); // Delete a Cookie element from storage (In: object COokie do delete)
	
	int getSize(); // Return size of storage (Out: size const)
	std::vector<Cookie> getAll(); // Returns pointer of storage (Out: storage)
};