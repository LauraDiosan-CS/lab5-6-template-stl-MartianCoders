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
	void showBySign(const char*, string, int);
public:
	UI();
	UI(Controler& service);
	void runUI();
};