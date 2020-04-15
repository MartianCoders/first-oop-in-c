#pragma once
#include "repository.h"
#include "cookie.h"
#include <map>

class Controler {
private:
	Repository<Cookie>* controler;
public:
	/* Constructor & Destructor */
	Controler(); // Default
	Controler(Repository<Cookie>*); // Copy storage from another
	~Controler(); // Destructor

	/* CRUD */
	void addElement(int, string, string, double); // Creates a Cookie object and add it in storage (In: ID, name, ingr, price)
	void deleteElement(int); // Delete an element from storage using ID (In: ID)
	void updateElement(int, string, string, double); // Creates a Cookie object and update in storage (In: ID, name, ingr, price)

	int getSize(); // Returns size of storage
	vector<Cookie> getAll(); // Retunrs storage pointer

	/* Functionalities */
	std::map<string, std::pair<unsigned int, double>> averPriceIngr(); // Returns map (Key:ingredient - pair<counter, sum_prices>) object with ingredients from storage (Out: ingredients)

};