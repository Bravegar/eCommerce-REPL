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
	std::vector<Card> cart;
	std::vector<User> adminList;
	bool is_admin;

public:

	Menu();
	void display_main_menu();
	void display_menu_option(int);
	void display_all_cards();
	void display_all_users();
	void single_card_display(int, std::vector<Card>);
	void display_cart();
	void init_cards();
	void addCard();
	std::vector<Card> FilterCardListByPrice();
	void displayCardList(std::vector<Card>);
	std::vector<Card> FilterCardListByName();
	std::vector<Card> FilterCardListByType();
	void display_login_menu();
	bool check_user_exists(std::string userName);
	void init_user_list();
	bool user_login(std::string, std::string);
	void create_new_user();
	bool user_is_admin();
	void display_admin_menu();
	void init_admin_list();
};

