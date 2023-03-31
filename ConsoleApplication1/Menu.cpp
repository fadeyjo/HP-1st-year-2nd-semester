#include "Menu.h"

namespace GEV
{
	Menu::~Menu()
	{
		delete[] this->title;
		delete[] this->subMenu;
	}
	Menu::Menu(void(*action)(), char* title)
	{
		this->action = action;
		this->title = title;
		this->isSubMenu = false;
	}
	Menu::Menu(Menu** subMenu, char* title, int countMenuItems)
	{
		this->subMenu = subMenu;
		this->title = title;
		this->countSubMenuItems = countMenuItems;
		this->isSubMenu = true;
	}
	Menu::Menu() {}
	void Menu::runMenu(Menu** menu, int countMenuItems)
	{
		while (!exit)
		{
			printMenu(menu, countMenuItems);
			std::cout << "¬ведите команду: ";
			int command = 0;
			std::cin >> command;
			system("cls");
			switch (command)
			{
			case 1:
			{
				if (menu[0]->isSubMenu)
				{
					runSubMenu(menu[0]->subMenu, menu[0]->countSubMenuItems);
				}
				else
				{
					menu[0]->action();
				}
				break;
			}
			case 2:
			{
				if (menu[1]->isSubMenu)
				{
					runSubMenu(menu[1]->subMenu, menu[1]->countSubMenuItems);
				}
				else
				{
					menu[1]->action();
				}
				break;
			}
			case 3:
			{
				if (menu[2]->isSubMenu)
				{
					runSubMenu(menu[2]->subMenu, menu[2]->countSubMenuItems);
				}
				else
				{
					menu[2]->action();
				}
				break;
			}
			case 4:
			{
				if (menu[3]->isSubMenu)
				{
					runSubMenu(menu[3]->subMenu, menu[3]->countSubMenuItems);
				}
				else
				{
					menu[3]->action();
				}
				break;
			}
			case 5:
			{
				if (menu[4]->isSubMenu)
				{
					runSubMenu(menu[4]->subMenu, menu[4]->countSubMenuItems);
				}
				else
				{
					menu[4]->action();
				}
				break;
			}
			case 6:
			{
				if (menu[5]->isSubMenu)
				{
					runSubMenu(menu[5]->subMenu, menu[5]->countSubMenuItems);
				}
				else
				{
					menu[5]->action();
				}
				break;
			}
			case 7:
			{
				if (menu[6]->isSubMenu)
				{
					runSubMenu(menu[6]->subMenu, menu[6]->countSubMenuItems);
				}
				else
				{
					menu[6]->action();
				}
				break;
			}
			default:
			{
				if (menu[7]->isSubMenu)
				{
					runSubMenu(menu[7]->subMenu, menu[7]->countSubMenuItems);
				}
				else
				{
					menu[7]->action();
				}
				break;
			}
			}
			system("cls");
		}
	}
	void Menu::runSubMenu(Menu** menu, int countMenuItems)
	{
		printMenu(menu, countMenuItems);
		std::cout << "¬ведите команду: ";
		int command = 0;
		std::cin >> command;
		system("cls");
		switch (command)
		{
		case 1:
		{
			if (menu[0]->isSubMenu)
			{
				runSubMenu(menu[0]->subMenu, menu[0]->countSubMenuItems);
			}
			else
			{
				menu[0]->action();
			}
			break;
		}
		case 2:
		{
			if (menu[1]->isSubMenu)
			{
				runSubMenu(menu[1]->subMenu, menu[1]->countSubMenuItems);
			}
			else
			{
				menu[1]->action();
			}
			break;
		}
		case 3:
		{
			if (menu[2]->isSubMenu)
			{
				runSubMenu(menu[2]->subMenu, menu[2]->countSubMenuItems);
			}
			else
			{
				menu[2]->action();
			}
			break;
		}
		case 4:
		{
			if (menu[3]->isSubMenu)
			{
				runSubMenu(menu[3]->subMenu, menu[3]->countSubMenuItems);
			}
			else
			{
				menu[3]->action();
			}
			break;
		}
		case 5:
		{
			if (menu[4]->isSubMenu)
			{
				runSubMenu(menu[4]->subMenu, menu[4]->countSubMenuItems);
			}
			else
			{
				menu[4]->action();
			}
			break;
		}
		case 6:
		{
			if (menu[5]->isSubMenu)
			{
				runSubMenu(menu[5]->subMenu, menu[5]->countSubMenuItems);
			}
			else
			{
				menu[5]->action();
			}
			break;
		}
		case 7:
		{
			if (menu[6]->isSubMenu)
			{
				runSubMenu(menu[6]->subMenu, menu[6]->countSubMenuItems);
			}
			else
			{
				menu[6]->action();
			}
			break;
		}
		default:
		{
			if (menu[7]->isSubMenu)
			{
				runSubMenu(menu[7]->subMenu, menu[7]->countSubMenuItems);
			}
			else
			{
				menu[7]->action();
			}
			break;
		}
		}
	}
	void Menu::printMenu(Menu** menu, int countMenuItems)
	{
		for (int i = 0; i < countMenuItems; i++)
		{
			std::cout << menu[i]->getTitle() << std::endl;
		}
	}
	char* Menu::getTitle()
	{
		return this->title;
	}
}