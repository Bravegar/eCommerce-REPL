#pragma once
#include <vector>
#include "Card.h"
#include "User.h"
class Menu
{
	int option;
	bool quit;
	int menuSize;
	std::vector<Card> cardList;
	std::vector<User> userList;

public:

	Menu();
	void display_login_menu();
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
	void create_new_user();
	bool user_login(std::string, std::string);
	void init_user_list();
	bool check_user_exists(std::string);

};

