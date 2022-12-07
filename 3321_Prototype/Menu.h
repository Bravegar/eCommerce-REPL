#pragma once
#include <vector>
#include "Card.h"
class Menu
{
	int option;
	bool quit;
	int menuSize;
	std::vector<Card> test;

public:

	Menu();
	void display_main_menu();
	void display_menu_option(int);
	void display_all_cards();
	void single_card_display(int);
	void init_cards();
	void addCard();
};

