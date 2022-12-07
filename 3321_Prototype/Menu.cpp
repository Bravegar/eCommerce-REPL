#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
enum state {
	main_menu = 0,
	filter_specific_card,
	filter_by_type,
	filter_by_rarity,
	filter_by_price
};

 Menu::Menu()
{
	
	 this->option = 9999;
	 this->quit = false;
	 this->menuSize = 2;
}

 void Menu::display_main_menu()
 {
	 while (!this->quit)
	 {
		 std::cout << "********************************************" << std::endl;
		 std::cout << "Please select from the following options: " << std::endl;
		 std::cout << "1. Search for a Specific Card" << std::endl;
		 std::cout << "2. Filter Cards by Type" << std::endl;
		 std::cout << "3. Filter Cards by Rarity" << std::endl;
		 std::cout << "4. Filter Cards by Price" << std::endl;
		 std::cout << "5. Add New Card for Sale" << std::endl;
		 std::cout << "6. Display All Cards for Sale" << std::endl;
		 std::cout << "0. Quit" << std::endl;
		 std::cin >> this->option;

		 this->display_menu_option(this->option);

	 }
 }
void Menu::display_menu_option(int option)
{
	switch (option)
	{
	default:
		std::cout << "default" << std::endl;
		break;
	case 0:
		this->quit = true;
		break;
	case 1:
		std::cout << 1 << std::endl;
		break;
	case 2:
		std::cout << 2 << std::endl;
		break;
	case 3:
		std::cout << 3 << std::endl;
		break;
	case 4:
		std::cout << 4 << std::endl;
		break;
	case 5:
		addCard();
		break;
	case 6:
		display_all_cards();
		break;

	}
}
void Menu::display_all_cards()
{
	int selection;
	for (int i = 0; i < this->cardList.size(); i ++ )
	{
		std::cout << i << ". ";
		std::cout << cardList[i].getPokemonName() << " " << std::endl;
	}
	std::cout << "Please enter a selection..." << std::endl;
	std::cin >> selection;
	single_card_display(selection);
}
void Menu::single_card_display(int selection)
{
	int select;
	cardList[selection].display();
	std::cout << "1. Purchase" << std::endl;
	std::cout << "2. Main Menu" << std::endl;
	std::cin >> select;
}
void Menu::init_cards()
{
	for (int i = 0; i < 100; i++)
	{
		cardList.push_back(Card("name",20.00));
	}
}
void Menu::addCard()
{
	std::string setID;
	int cardID;
	double price;
	std::string name, type;
	std::cout << "Please enter a card name..." << std::endl;
	std::cin >> name;
	std::cout << "Please enter a card type..." << std::endl;
	std::cin >> type;
	std::cout << "Please enter a card price..." << std::endl;
	std::cin >> price;
	std::cout << "Please enter the cards Set ID" << std::endl;
	std::cin >> setID;
	std::cout << "Please enter the cards Card ID" << std::endl;
	std::cin >> cardID;
	cardList.push_back(Card(setID, cardID, price, name, type));
}