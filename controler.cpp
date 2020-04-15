#include "controler.h"
#include "repositoryF.h"

Controler::Controler() {
	this->controler = new Repository<Cookie>();
}

Controler::Controler(Repository<Cookie>* storage) {
	this->controler = storage;
}

Controler::~Controler() {
}

void Controler::addElement(int ID, string name, string ingr, double price) {
	std::vector<Cookie> storage = this->controler->getAll();
	bool exists = false;
	for (unsigned int i = 0; i < storage.size(); i++)
		if (storage[i].getID() == ID)
			exists = true;
	if (exists == false)
		this->controler->addCookie(Cookie(ID, name, ingr, price));
}

void Controler::deleteElement(int ID) {
	std::vector<Cookie> storage = this->controler->getAll();
	for (unsigned int i = 0; i < storage.size(); i++)
		if (storage[i].getID() == ID)
			this->controler->deleteCookie(storage[i]);
}

void Controler::updateElement(int ID, string name, string ingr, double price) {
	this->controler->updateCookie(Cookie(ID, name, ingr, price));
}

int Controler::getSize() {
	return this->controler->getSize();
}

vector<Cookie> Controler::getAll() {
	return this->controler->getAll();
}

std::map<string, std::pair<unsigned int, double>> Controler::averPriceIngr() {
	std::string split = ",";

	std::map<string, std::pair<unsigned int, double>> ingredients;

	std::vector<Cookie> storage = this->controler->getAll();

	for (auto it = storage.begin(); it != storage.end(); it++) {
		std::string elements = (*it).getIngr();
		size_t pos = 0;
		std::string token;
		if ((pos = elements.find(split)) != std::string::npos)
			while ((pos = elements.find(split)) != std::string::npos) {
				token = elements.substr(0, pos);
				auto ing = ingredients.find(token);
				if (ing == ingredients.end())
					ingredients.insert(std::make_pair(token, std::make_pair(1, (*it).getPrice())));
				else {
					ing->second.first++;
					ing->second.second = ing->second.second + (*it).getPrice();
				}
				elements.erase(0, pos + split.length());
			}
		auto ing = ingredients.find(elements);
		if (ing == ingredients.end())
			ingredients.insert(std::make_pair(elements, std::make_pair(1, (*it).getPrice())));
		else {
			ing->second.first++;
			ing->second.second = ing->second.second + (*it).getPrice();
		}


	}
	return ingredients;
}