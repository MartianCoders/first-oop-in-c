#include "UI.h"

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

UI::UI() {}

UI::UI(Controler& service) {
	this->controler = service;
}

UI::~UI() {}

void UI::showBaseMenu() {
	std::cout << '\n';
	std::cout << "Type 'help' for commands info";
	std::cout << '\n';
}
void UI::showHELP() {
	std::cout << "\n";
	std::cout << "show | Afisare\n";
	std::cout << "----\n";
	std::cout << "add {ID} {name} {ingr} {price}\n";
	std::cout << "----\n";
	std::cout << "update {ID to update} {newName} {newIngr} {newPrice}\n";
	std::cout << "----\n";
	std::cout << "delete {ID}\n";
	std::cout << "----\n";
	std::cout << "func1 - Average price per ingredient";
}

void UI::showAllUI() {
	vector<Cookie> storage = this->controler.getAll();
	for (unsigned int i = 0; i < storage.size(); i++)
		std::cout << storage[i];
}


void UI::addUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* name = new char[token.length() + 1];
	strcpy_s(name, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* ingr = new char[token.length() + 1];
	strcpy_s(ingr, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	double price = stoi(token);

	this->controler.addElement(ID, name, ingr, price);
	delete[] ingr;
	delete[] name;
	name = NULL;
	ingr = NULL;
}

void UI::updateUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	string name = token.c_str();

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	string ingr = token.c_str();

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	double price = stoi(token);

	this->controler.updateElement(ID, name, ingr, price);
}

void UI::deleteUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	this->controler.deleteElement(ID);
}

void UI::averPriceIngr() {
	std::map<string, std::pair<unsigned int, double>> ingredients = this->controler.averPriceIngr();
	for (auto it = ingredients.begin(); it != ingredients.end(); it++)
		std::cout << it->first << ": " << it->second.second / (int)it->second.first << endl;
}

void UI::runUI() {
	bool run = true;
	string cmd;
	while (run) {
		this->showBaseMenu();
		getline(cin, cmd);
		if (cmd.find("help") != string::npos)
			this->showHELP();
		if (cmd.find("show") != string::npos)
			this->showAllUI();
		if (cmd.find("add") != string::npos)
			this->addUI(cmd);
		if (cmd.find("delete") != string::npos)
			this->deleteUI(cmd);
		if (cmd.find("update") != string::npos)
			this->updateUI(cmd);
		if (cmd.find("exit") != string::npos)
			run = false;
		if (cmd.find("func1") != string::npos)
			this->averPriceIngr();
	}
}