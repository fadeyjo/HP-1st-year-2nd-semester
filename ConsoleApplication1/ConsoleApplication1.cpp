#include <iostream>
#include <Windows.h>
#include "Functions.h"
#include "Menu.h"
#include "Employee.h"
#include "Astronaut.h"

using namespace std;
using namespace GEV;

bool Menu::exit = false;
Visitor Menu::visitor;
Menu** Menu::lastMenu;
int Menu::countLastMenuItems;
int Astronaut::countAstronauts;
int Employee::countEmployee;
Astronaut* Astronaut::astronauts;
Employee* Employee::employee;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int countStartMenuItems = 3;
	Menu** startMenu = new Menu * [countStartMenuItems];

	startMenu[0] = new Menu(logIn, new char[255] {"[1]    Авторизация."});

	int countRegistrationMenuItems = 2;
	Menu** registrationMenu = new Menu * [countRegistrationMenuItems];
	registrationMenu[0] = new Menu(registrationAsAdmin, new char[255] {"[1]    Регистрация админа."});
	registrationMenu[1] = new Menu(registrationAsUser, new char[255] {"[2]    Регистрация пользователя."});

	startMenu[1] = new Menu(registrationMenu, new char[255] {"[2]    Регистрация."}, countRegistrationMenuItems);

	startMenu[2] = new Menu(exit, new char[255] {"[3]    Выход."});

	Menu::lastMenu = startMenu;
	Menu::countLastMenuItems = countStartMenuItems;

	Menu::runMenu(startMenu, countStartMenuItems);

	return 0;
}