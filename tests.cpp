#include "cookie.h"
#include "repository.h"
#include "tests.h"

#include <vector>
#include <assert.h>

void test_cookie() {
	Cookie c1(1, "placinta", "lapte mere", 200);
	assert(c1.getID() == 1);
	assert(strcmp(c1.getName(), "placinta") == 0);
	assert(strcmp(c1.getIng(), "lapte mere") == 0);
	assert(c1.getPrice() == 200);

	Cookie c2(2, "briosa", "nimic", 100);
	c1 = c2;
	assert(c1.getID() == 2);
}

void test_repository() {
	Repository<Cookie> storage;
	Cookie c(1, "da", "nimic", 100);
	storage.addCookie(c);
	assert(storage.getSize() == 1);
	Cookie c2(2, "nu", "nimic", 150);
	storage.updateCookie(c, c2);
	assert(storage.getAll()[0] == c2);
	storage.deleteCookie(c2);
	assert(storage.getSize() == 0);

}