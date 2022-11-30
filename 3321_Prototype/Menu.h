#pragma once
class Menu
{
	int option;
	bool quit;
	int menuSize;
	vector<state> stateStack;

public:

	Menu();
	void display_main_menu();
};

