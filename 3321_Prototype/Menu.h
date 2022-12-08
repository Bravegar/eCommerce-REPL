#pragma once
#include <vector>
#include "Card.h"
class Menu
{
	int option;
	bool quit;
	int menuSize;
	std::vector<Card> cardList;

public:

	Menu();
	void display_main_menu();
	void display_menu_option(int);
	void display_all_cards();
	void single_card_display(int, std::vector<Card>);
	void init_cards();
	void addCard();
	std::vector<Card> FilterCardListByPrice();
	void displayCardList(std::vector<Card>);
	std::vector<Card> FilterCardListByName();
	std::vector<Card> FilterCardListByType();
};

