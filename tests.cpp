#include <iostream>
#include <assert.h>
#include <sstream>
#include <map>
#include "cookie.h"
#include "tests.h"
#include "repository.h"
#include "repositoryF.h"
#include "controler.h"


void test_cookie() {
	Cookie c1(1, "briosa", "nimic", 100);
	assert(c1.getID() == 1);
	assert(c1.getName() == "briosa");
	assert(c1.getIngr() == "nimic");
	assert(c1.getPrice() == 100);
	
	Cookie c2(2, "tort", "apa", 150);

	Cookie c3;
	c1 = c2;
	assert(c1 == c2);
	assert(c1 != c2 == false);
	c1.setName("acadea");
	assert(c1 != c2);
	assert(c1 == c2 == false);

	std::stringstream string;
	string << c1;
	assert(string.str() == "2 acadea apa 150\n");
}

void test_repository() {
	Repository<Cookie> storage;
	Repository<Cookie> storage2(storage);
	Cookie c(1, "briosa", "nimic", 100);
	storage.addCookie(c);
	assert(storage.getSize() == 1);
	Cookie c2(1, "mancare", "nimic", 150);
	storage.updateCookie(c2);
	assert(storage.getAll()[0] == c2);
	storage.deleteCookie(c2);
	assert(storage.getSize() == 0);
}

void test_repositoryF() {
	RepositoryF<Cookie> storage2;
	RepositoryF<Cookie> storage("test.txt");
	Cookie c(1, "briosa", "nimic", 100);
	storage.addCookie(c);
	assert(storage.getSize() == 1);
	Cookie c2(1, "mancare", "nimic", 150);
	storage.updateCookie(c2);
	assert(storage.getAll()[0] == c2);
	storage.deleteCookie(c2);
	assert(storage.getSize() == 0);
	storage.clear();
}

void test_controler() {
	Repository<Cookie>* storage;
	storage = new RepositoryF<Cookie>("test.txt");
	Controler controler(storage);
	controler.addElement(1, "briosa", "nimic", 150);
	assert(controler.getSize() == 1);
	controler.deleteElement(1);
	assert(controler.getSize() == 0);
	controler.addElement(1, "tort", "da", 100);
	assert(controler.getSize() == 1);
	controler.deleteElement(1);
	assert(controler.getSize() == 0);
	controler.addElement(1, "briosa", "nimic", 150);
	controler.updateElement(1, "tort", "da", 100);
	assert(controler.getAll()[0].getName() == "tort");
	assert(controler.getAll()[0].getIngr() == "da");
	assert(controler.getAll()[0].getPrice() == 100);
	controler.deleteElement(1);

	test_func1(controler);
}

void test_func1(Controler controler) {
	controler.addElement(1, "tort", "zahar, lapte", 20);
	controler.addElement(2, "placinta", "zahar,mere", 35);
	controler.addElement(3, "salata", "mere, portocale", 40);
	controler.addElement(4, "random", "banane", 55);
	controler.addElement(5, "random", "banane", 22);
	std::map<string, std::pair<unsigned int, double>> ingr = controler.averPriceIngr();
	auto it = ingr.find("zahar");
	assert(it->second.first == 2);
	assert(it->second.second == 55);
	it = ingr.find("banane");
	assert(it->second.first == 2);
	assert(it->second.second == 77);

	controler.deleteElement(1);
	controler.deleteElement(2);
	controler.deleteElement(3);
	controler.deleteElement(4);
	controler.deleteElement(5);

}



void test_all() {
	test_cookie();
	test_repository();
	test_repositoryF();
	test_controler();
}
