#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Cookie {
private:
	int ID;
	char* name;
	char* ingr;
	double price;
public:
	/* Constructors & Destructor */
	Cookie(); // Default
	Cookie(int, const char*, const char*, double); // Given data (In: ID, name, ingr, price)
	Cookie(const Cookie&); // Copy
	~Cookie(); // Destructor

	/* Get's*/
	int getID(); // Returns ID (Out: ID)
	char* getName(); // Returns name pointer (Out: name)
	char* getIngr(); // Returns ingr pointer (Out: ingr)
	double getPrice(); // Returns price (Out: price)

	/* Set's */
	void setID(int); // Set ID (In: ID)
	void setName(const char*); // Set name (In: name)
	void setIngr(const char*); // Set ingr (In: ingr)
	void setPrice(double); // Set price (In: price)

	Cookie& operator=(const Cookie&);
	bool operator==(const Cookie&) const;
	bool operator!=(const Cookie&) const;

	friend ostream& operator<<(ostream&, const Cookie&);
};