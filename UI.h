#pragma once
#include "controler.h"

class UI {
private:
	Controler controler;
	void showBaseMenu();
	void showHELP();
	void addUI(string);
	void updateUI(string);
	void deleteUI(string);
	void showAllUI();
	void showBySign(string, string, int);
	void averPriceIngr();
public:
	UI();
	UI(Controler& service);
	~UI();
	void runUI();
};