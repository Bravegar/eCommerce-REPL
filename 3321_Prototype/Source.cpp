#include <iostream>
#include "Menu.h"

int main()
{
	Menu menu;
	menu.init_cards();
	menu.init_user_list();
	menu.display_all_users();
	menu.display_login_menu();
	

	return 0;
}