#pragma once
#include <iostream>

namespace GEV
{
	enum Visitor
	{
		admin,
		user
	};
	class Menu
	{
	private:
		char* title;
		void(*action)();
		Menu** subMenu;
		int countSubMenuItems;
		bool isSubMenu;
	public:
		Menu(void(*action)(), char* title);
		Menu(Menu** subMenu, char* title, int countSubMenuItems);
		Menu();
		~Menu();
		static bool exitFromMenu;
		static Visitor visitor;
		static Menu** lastMenu;
		static int countLastMenuItems;
		static void runSubMenu(Menu** subMenu, int countSubMenuItems);
		static void runMenu(Menu** menu, int countMenuItems);
		static void printMenu(Menu** menu, int countMenuItems);
		char* getTitle();
	};
}