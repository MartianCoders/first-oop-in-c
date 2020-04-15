#include "cookie.h"
Cookie::Cookie() {
	this->ID = 0;
	this->price = 0;
}

Cookie::Cookie(int ID, string name, string ingr, double price) {
	this->name = name;
	this->ingr = ingr;
	this->ID = ID;
	this->price = price;
}

Cookie::Cookie(const Cookie& c) {
	this->name = c.name;
	this->ingr = c.ingr;
	this->ID = c.ID;
	this->price = c.price;
}

Cookie::~Cookie() {
}

int Cookie::getID() {
	return this->ID;
}

string Cookie::getName() {
	return this->name;
}

string Cookie::getIngr() {
	return this->ingr;
}

double Cookie::getPrice() {
	return this->price;
}

void Cookie::setID(int ID2) {
	this->ID = ID2;
}

void Cookie::setName(string name2) {
	this->name = name2;
}

void Cookie::setIngr(string ingr2) {
	this->ingr = ingr2;
}

void Cookie::setPrice(double price2) {
	this->price = price2;
}

Cookie& Cookie::operator=(const Cookie& c) {
	this->setName(c.name);
	this->setIngr(c.ingr);
	this->setID(c.ID);
	this->setPrice(c.price);
	return *this;

}

bool Cookie::operator==(const Cookie& c) const {
	if (this->name == c.name && this->ingr == c.ingr && this->ID == c.ID && this->price == c.price)
		return true;
	return false;
}

bool Cookie::operator!=(const Cookie& c) const {
	if (this->name == c.name && this->ingr == c.ingr && this->ID == c.ID && this->price == c.price)
		return false;
	return true;
}

ostream& operator<<(ostream& os, const Cookie& c) {
	os << c.ID << ' ' << c.name << ' ' << c.ingr << ' ' << c.price << endl;
	return os;
}
