#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

 Menu::Menu()
{
	//Initializer for Menu Class
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
		 std::cout << "1. Filter Cards by Name" << std::endl;
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
		displayCardList(FilterCardListByName());
		break;
	case 2:
		displayCardList(FilterCardListByType());
		break;
	case 3:
		std::cout << 3 << std::endl;
		break;
	case 4:
		displayCardList(FilterCardListByPrice());
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
	//Loops through all cards in cardList vector and displays them as selections.
	for (int i = 0; i < this->cardList.size(); i ++ )
	{
		std::cout << i+1 << ". ";
		std::cout << cardList[i].getPokemonName() << " " << std::endl;
	}
	std::cout << "Please enter a selection..." << std::endl;	
	std::cin >> selection;
	single_card_display(selection-1, cardList);
}
void Menu::single_card_display(int selection, std::vector<Card> cards)
{
	int select;
	if (selection >= cards.size())
	{
		std::cout << "No data associated with that selection. Returning to main menu" << std::endl;
		return;
	}
	cards[selection].display();
	std::cout << "1. Purchase" << std::endl;
	std::cout << "2. Main Menu" << std::endl;
	std::cin >> select;
}
void Menu::init_cards()
{
	std::fstream infile;
	infile.open("cards.csv");
	std::string buff;
	getline(infile, buff); //Used to clear headers for columns in cards.csv file
	//Loop to gather pokemon card data from file.
	while (getline(infile, buff))
	{
		std::stringstream test(buff);
		std::string setID, name, type;
		std::string cardID, numBeingSold;
		std::string price;
		getline(test, cardID, ',');
		getline(test, setID, ',');
		getline(test, price, ',');
		getline(test, name, ',');
		getline(test, type, ',');
		getline(test, numBeingSold, ',');
		cardList.push_back(Card(setID, stoi(cardID), stod(price), name, type, stoi(numBeingSold)));
	}

}
void Menu::addCard()
{
	std::string setID;
	int cardID, numToSell;
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
	std::cout << "How many cards will you be selling?" << std::endl;
	std::cin >> numToSell;
	cardList.push_back(Card(setID, cardID, price, name, type, numToSell));
}
std::vector<Card> Menu::FilterCardListByPrice()
{
	double minPrice, maxPrice;
	std::cout << "Please enter a minimum price to search for..." << std::endl;
	std::cin >> minPrice;
	std::cout << "Please enter a maximum price to search for..." << std::endl;
	std::cin >> maxPrice;
	std::vector<Card> filteredList;
	for (int i = 0; i < cardList.size(); i++)
	{
		if (cardList[i].getPrice() > minPrice && cardList[i].getPrice() < maxPrice) //Checks if price at cardList index i is above and below the min/max prices set by user input
			filteredList.push_back(cardList[i]);
	}

	return filteredList;
}
void Menu::displayCardList(std::vector<Card> filteredList)
{
	int selection;
	for (int i = 0; i < filteredList.size(); i++)
	{
		std::cout << i+1 << ". " << filteredList[i].getPokemonName() << std::endl; //Add an i to start at 1 when displaying to user.
	}
	std::cout << "Please enter a selection..." << std::endl;
	std::cin >> selection;
	single_card_display(selection - 1, filteredList); //Revert the 1 added to i to correctly select the proper index from vector
}
std::vector<Card> Menu::FilterCardListByName()
{

	std::string search;
	std::cout << "Please enter a name to search for..." << std::endl;
	std::cin >> search;
	
	std::vector<Card> filteredList;
	for (int i = 0; i < cardList.size(); i++)
	{
		if (cardList[i].getPokemonName().find(search) != std::string::npos)
			filteredList.push_back(cardList[i]);
	}
	
	return filteredList;
}
std::vector<Card> Menu::FilterCardListByType()
{

	std::string search;
	std::cout << "Please enter a type to search for..." << std::endl;
	std::cin >> search;

	std::vector<Card> filteredList;
	for (int i = 0; i < cardList.size(); i++)
	{
		if (cardList[i].getType().find(search) != std::string::npos)
			filteredList.push_back(cardList[i]);
	}

	return filteredList;
}