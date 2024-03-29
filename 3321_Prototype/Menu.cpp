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
	 is_admin = false;
}

 void Menu::display_main_menu()
 {
	 while (!this->quit)
	 {
		 std::cout << "********************************************" << std::endl;
		 std::cout << "Please select from the following options: " << std::endl;
		 std::cout << "1. Filter Cards by Name" << std::endl;
		 std::cout << "2. Filter Cards by Type" << std::endl;
		 std::cout << "3. Filter Cards by Price" << std::endl;
		 std::cout << "4. Add New Card for Sale" << std::endl;
		 std::cout << "5. Display All Cards for Sale" << std::endl;
		 std::cout << "6. Display All Users" << std::endl;
		 std::cout << "7. Display Cart" << std::endl;
		 std::cout << "9. For Admin Commands" << std::endl;
		 std::cout << "0. Quit" << std::endl;
		 std::cin >> this->option;

		 this->display_menu_option(this->option);

	 }
 }
 void Menu::display_admin_menu()
 {
	 if (!is_admin)
	 {
		 std::cout << "Insufficient Privileges!" << std::endl;
		 display_main_menu();
	}
	 int selection;
	 std::cout << "0. Return to main menu" << std::endl;
	 std::cout << "1. Display All Users" << std::endl;
	 std::cin >> selection;
	 switch (selection)
	 {
	 default:
		 display_admin_menu();
		 break;
	 case 0:
		 display_main_menu();
		 break;
	 case 1:
		 display_all_users();
		 break;
	 

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
		displayCardList(FilterCardListByPrice());
		break;
	case 4:
		addCard();
		break;
	case 5:
		display_all_cards();
		break;
	case 6:
		display_all_users();
		break;
	case 7:
		display_cart();
		break;
	case 9:
		if (user_is_admin())
		{
			display_admin_menu();
		}
		else
		{
			std::cout << "Sorry insufficient privileges!" << std::endl;
		}
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

void Menu::display_all_users()
{

	//Loops through all users in userList vector and displays them as selections.
	for (int i = 0; i < this->userList.size(); i++)
	{
		std::cout << i + 1 << ". ";
		std::cout << userList[i].getFName() << " " << userList[i].getLName() << std::endl;
	}

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
	
	if (select == 1) {
		cart.push_back(cards[selection]);
		std::cout << "Card added to cart" << std::endl;
	}
}
void Menu::display_cart() {

	double total = 0;
	
	if (cart.empty()) {
		std::cout << "Your shopping cart is empty" << std::endl;
		return;
	}
	for (int i = 0; i < this->cart.size(); i++)
	{
		std::cout << i + 1 << ". ";
		std::cout << cart[i].getPokemonName() << " : $" << cart[i].getPrice() << std::endl;
		total += cart[i].getPrice();
	}
	std::cout << "Your total is : $" << total << std::endl;
	std::cout << "Would you like to check out? (y/n)" << std::endl;
	
	std::string choice;
	std:: cin >> choice;

	if (choice == "y") {
		std::cout << "Please enter your payment information" << std::endl;
		std::cout << "Card number:" << std::endl;
		std::cin >> choice;
		std::cout << "Expiration Date:" << std::endl;
		std::cin >> choice;
		std::cout << "Security Code:" << std::endl;
		std::cin >> choice;
		std::cout << "Name on Card:" << std::endl;
		std::cin >> choice;
		std::cout << "Thank you for your purchase!" << std::endl;
		cart.clear();
	}
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
	infile.close();
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
void Menu::create_new_user()
{
	std::string userName, password, fName, lName, email, address, phoneNumber;

	std::cout << "What is your first name?" << std::endl;
	std::cin >> fName;
	std::cout << "What is your last name?" << std::endl;
	std::cin >> lName;
	std::cout << "What will be your email?" << std::endl;
	std::cin >> email;
	std::cout << "What is your address?" << std::endl;
	std::cin >> address;
	std::cout << "What will be your username?" << std::endl;
	std::cin >> userName;
	std::cout << "What will be your password?" << std::endl;
	std::cin >> password;
	std::cout << "What is your phone number?" << std::endl;
	std::cin >> phoneNumber;
	if (check_user_exists(userName))
	{
		std::cout << "Sorry this user already exists!" << std::endl;
		display_login_menu();
	}
	userList.push_back(User(fName, lName, email, address, userName, password, phoneNumber));
	std::fstream iFile;
	iFile.open("users.csv", std::ios::app);
	iFile << fName << "," << lName << "," << email << "," << address << "," << userName << "," << password << "," << phoneNumber << "\n";
	iFile.close();
	display_login_menu();
}
bool Menu::user_login(std::string user, std::string pass)
{
	for (int i = 0; i < userList.size(); i++)
	{
		if (user == userList[i].getUsername() && pass == userList[i].getPassword())
		{
			return true;
		}
	}
	return false;
}
void Menu::init_user_list()
{
	std::fstream iFile;
	iFile.open("users.csv");
	std::string buff;
	while (getline(iFile, buff))
	{
		std::stringstream ss(buff);
		std::string fName, lName, email, address, user, pass, phone;
		getline(ss, fName, ',');
		getline(ss, lName, ',');
		getline(ss, email, ',');
		getline(ss, address, ',');
		getline(ss, user, ',');
		getline(ss, pass, ',');
		getline(ss, phone, ',');

		userList.push_back(User(fName, lName, email, address, user, pass, phone));
	}
	iFile.close();
	return;
	
}
bool Menu::check_user_exists(std::string userName)
{
	for (int i = 0; i < userList.size(); i++)
	{
		if (userName == userList[i].getUsername())
			return true;
	}
	return false;
}
void Menu::display_login_menu()
{
	std::string user, pass;
	std::cout << "**************************************************" << std::endl;
	std::cout << "Please enter your username...." << std::endl;
	std::cin >> user;
	std::cout << "Please enter your password...." << std::endl;
	std::cin >> pass;
	if (user_login(user, pass))
	{
		display_main_menu();
	}
	else
	{
		char confirmation;
		std::cout << "Would you like to create a new account?(Y/N)" << std::endl; //Error checking
		std::cin >> confirmation;
		if (confirmation == 'Y' || confirmation == 'y')
		{
			create_new_user();
		}
		else
		{
			display_login_menu();
		}
	}

}


bool Menu::user_is_admin()
{
	std::string user, pass;
	std::cout << "Enter username" << std::endl;
	std::cin >> user;
	std::cout << "Enter password" << std::endl;
	std::cin >> pass;

	for (int i = 0; i < adminList.size(); i++)
	{
		if (user == adminList[i].getUsername() && pass == adminList[i].getPassword())
		{
			is_admin = true;
			return true;
		}
	}
}
void Menu::init_admin_list()
{
	adminList.push_back(User());
	adminList[0].setUsername("brave");
	adminList[0].setPassword("123");
	
}
