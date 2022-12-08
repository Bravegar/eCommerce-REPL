#include <iostream>
#include "Menu.h"

int main()
{
	Menu menu;
	menu.init_cards();
	menu.init_users();
	menu.display_main_menu();

	return 0;
}