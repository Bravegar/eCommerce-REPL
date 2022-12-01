#include "Menu.h"
#include <iostream>

#include <string>
enum state {
	main_menu = 0,
	filter_specific_card,
	filter_by_type,
	filter_by_rarity,
	filter_by_price
};
using namespace std;
 Menu::Menu()
{
	
	 this->option = 9999;
	 this->quit = false;
	 this->menuSize = 2;
}

void Menu::display_main_menu()
{

	cout << "********************************************" << endl;
	cout << "Please select from the following options: " << endl;
	cout << "1. Search for a Specific Card" << endl;
	cout << "2. Filter Cards by Type" << endl;
	cout << "3. Filter Cards by Rarity" << endl;
	cout << "4. Filter Cards by Price" << endl;
	cin >> this->option;

	


}
