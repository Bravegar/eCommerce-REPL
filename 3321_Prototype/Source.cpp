#include <iostream>
#include "Menu.h"
void test123();
int main()
{
	Menu menu;

	menu.display_main_menu();

	return 0;
}
void test123()
{
	std::cout << 123 << std::endl;
}