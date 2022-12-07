#pragma once
class Menu
{
	int option;
	bool quit;
	int menuSize;
	

public:

	Menu();
	void display_main_menu();
	void display_menu_option(int);
	void display_single_card(Card);
};

