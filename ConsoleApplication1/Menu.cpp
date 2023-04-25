#include "Menu.h"

namespace GEV
{
	Menu::~Menu()
	{
		delete[] this->title;
		delete[] this->subMenu;
		delete this->lastMenu;
	}

	Menu::Menu(void(*action)(), char* title)
	{
		this->action = action;
		this->title = title;
		this->isSubMenu = false;
	}

	Menu::Menu(Menu** subMenu, char* title, int countSubMenuItems)
	{
		this->subMenu = subMenu;
		this->title = title;
		this->countSubMenuItems = countSubMenuItems;
		this->isSubMenu = true;
	}

	Menu::Menu() {}

	void Menu::runMenu(Menu** menu, int countMenuItems)
	{
		while (!exitFromMenu)
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
			case 8:
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
			default:
			{
				if (menu[8]->isSubMenu)
				{
					runSubMenu(menu[8]->subMenu, menu[8]->countSubMenuItems);
				}
				else
				{
					menu[8]->action();
				}
				break;
			}
			}
			system("cls");
		}
	}
	void Menu::runSubMenu(Menu** subMenu, int countSubMenuItems)
	{
		printMenu(subMenu, countSubMenuItems);
		std::cout << "¬ведите команду: ";
		int command = 0;
		std::cin >> command;
		system("cls");
		switch (command)
		{
		case 1:
		{
			if (subMenu[0]->isSubMenu)
			{
				runSubMenu(subMenu[0]->subMenu, subMenu[0]->countSubMenuItems);
			}
			else
			{
				subMenu[0]->action();
			}
			break;
		}
		case 2:
		{
			if (subMenu[1]->isSubMenu)
			{
				runSubMenu(subMenu[1]->subMenu, subMenu[1]->countSubMenuItems);
			}
			else
			{
				subMenu[1]->action();
			}
			break;
		}
		case 3:
		{
			if (subMenu[2]->isSubMenu)
			{
				runSubMenu(subMenu[2]->subMenu, subMenu[2]->countSubMenuItems);
			}
			else
			{
				subMenu[2]->action();
			}
			break;
		}
		case 4:
		{
			if (subMenu[3]->isSubMenu)
			{
				runSubMenu(subMenu[3]->subMenu, subMenu[3]->countSubMenuItems);
			}
			else
			{
				subMenu[3]->action();
			}
			break;
		}
		case 5:
		{
			if (subMenu[4]->isSubMenu)
			{
				runSubMenu(subMenu[4]->subMenu, subMenu[4]->countSubMenuItems);
			}
			else
			{
				subMenu[4]->action();
			}
			break;
		}
		case 6:
		{
			if (subMenu[5]->isSubMenu)
			{
				runSubMenu(subMenu[5]->subMenu, subMenu[5]->countSubMenuItems);
			}
			else
			{
				subMenu[5]->action();
			}
			break;
		}
		case 7:
		{
			if (subMenu[6]->isSubMenu)
			{
				runSubMenu(subMenu[6]->subMenu, subMenu[6]->countSubMenuItems);
			}
			else
			{
				subMenu[6]->action();
			}
			break;
		}
		default:
		{
			if (subMenu[7]->isSubMenu)
			{
				runSubMenu(subMenu[7]->subMenu, subMenu[7]->countSubMenuItems);
			}
			else
			{
				subMenu[7]->action();
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