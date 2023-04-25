#include "Functions.h"

namespace GEV
{
	void createDataBaseCargoSpaceShips()
	{
		std::cout << "Сколько грузовых кораблей вы хотите ввести: ";
		std::cin >> CargoSpaceShip::countCargoSpaceShips;
		CargoSpaceShip::cargoSpaceShips = new CargoSpaceShip[CargoSpaceShip::countCargoSpaceShips];
		for (int i = 0; i < CargoSpaceShip::countCargoSpaceShips; i++)
		{
			CargoSpaceShip newCargoSpaceShip;
			std::cin >> newCargoSpaceShip;
			CargoSpaceShip::cargoSpaceShips[i] = newCargoSpaceShip;
			std::cout << std::endl;
		}
		std::ofstream fout("CargoSpaceShips.txt", std::ofstream::app);
		for (int i = 0; i < CargoSpaceShip::countCargoSpaceShips; i++)
		{
			fout << CargoSpaceShip::cargoSpaceShips[i];
		}
		fout.close();
	}

	void createDataBaseHighSpeedSpaceShips()
	{
		std::cout << "Сколько высокоскоростных кораблей вы хотите ввести: ";
		std::cin >> HighSpeedSpaceShip::countHighSpeedSpaceShips;
		HighSpeedSpaceShip::highSpeedSpaceShips = new HighSpeedSpaceShip[HighSpeedSpaceShip::countHighSpeedSpaceShips];
		for (int i = 0; i < HighSpeedSpaceShip::countHighSpeedSpaceShips; i++)
		{
			HighSpeedSpaceShip newHighSpeedSpaceShip;
			std::cin >> newHighSpeedSpaceShip;
			HighSpeedSpaceShip::highSpeedSpaceShips[i] = newHighSpeedSpaceShip;
			std::cout << std::endl;
		}
		std::ofstream fout("HighSpeedSpaceShips.txt", std::ofstream::app);
		for (int i = 0; i < HighSpeedSpaceShip::countHighSpeedSpaceShips; i++)
		{
			fout << HighSpeedSpaceShip::highSpeedSpaceShips[i];
		}
		fout.close();
	}

	std::ostream& operator<<(std::ostream& out, const SpaceShip& spaceShip)
	{
		std::string condition;
		switch (spaceShip.condition)
		{
		case readyToLunch:
		{
			condition = "Готов к вылету";
			break;
		}
		case broken:
		{
			condition = "Сломан";
			break;
		}
		case repair:
		{
			condition = "Ремонтируется";
			break;
		}
		default:
		{
			condition = "Вылет запланирован";
			break;
		}
		}
		out <<  "Название: " << spaceShip.name << std::endl << "Масса : " << spaceShip.weight << std::endl << "Состояние: " << condition << std::endl << std::endl << "Информация о пилоте: " << spaceShip.pilot;
		return out;
	}
	std::istream& operator>>(std::istream& in, SpaceShip& spaceShip)
	{
		std::cout << "Название корабля: ";
		in >> spaceShip.name;
		std::cout << std::endl;
		std::cout << "Масса: ";
		in >> spaceShip.weight;
		std::cout << std::endl;
		std::cout << "Выберите текущее состояние корабля. Возможные варианты:" << std::endl;
		std::cout << "[1]    Запланировать вылет." << std::endl;
		std::cout << "[2]    В ремонте." << std::endl;
		std::cout << "[3]    Сломан." << std::endl;
		std::cout << "[4]    Готов к вылету." << std::endl;
		std::cout << "Текущее состояние: ";
		int command = 0;
		std::cin >> command;
		switch (command)
		{
		case 1:
		{
			spaceShip.condition = launhPlanned;
			std::cout << "Планировка вылета:" << std::endl;
			std::cout << "Дата вылета (ДД.ММ.ГГГГ): ";
			std::cin >> spaceShip.date;
			std::cout << "Время вылета (например, 12:38): ";
			std::cin >> spaceShip.time;
			break;
		}
		case 2:
		{
			spaceShip.condition = repair;
			spaceShip.date = "";
			spaceShip.time = "";
			break;
		}
		case 3:
		{
			spaceShip.condition = broken;
			spaceShip.date = "";
			spaceShip.time = "";
			break;
		}
		default:
		{
			std::string day = std::to_string(rand() %  31 + 1);
			std::string month = std::to_string(rand() % 12 + 1);
			std::string year = std::to_string(rand() % 1001 + 2024);
			std::string hour = std::to_string(rand() % 24+1);
			std::string minutes = std::to_string(rand() % 61);
			std::string date = day + '.' + month + '.' + year;
			std::string time = hour + ':' + minutes;
			spaceShip.date = date;
			spaceShip.time = time;
			spaceShip.condition = readyToLunch;
			break;
		}
		}
		std::cout << "Выбор пилота. Возможные пилоты:" << std::endl;
		Astronaut print;
		print.print(Astronaut::astronauts, Astronaut::countAstronauts);
		std::cout << "Номер пилота: ";
		std::cin >> command;
		spaceShip.pilot = Astronaut::astronauts[command - 1];
		return in;
	}

	bool operator>(const Human& human1, const Human& human2)
	{
		return human1.age > human2.age;
	}

	bool operator<(const Human& human1, const Human& human2)
	{
		return human1.age < human2.age;
	}

	std::ostream& operator<<(std::ostream& out, const Human& human)
	{
		std::string spaceSuit;
		switch (human.spaceSuit)
		{
		case S1:
		{
			spaceSuit = "S1";
			break;
		}
		case S2:
		{
			spaceSuit = "S2";
			break;
		}
		case S3:
		{
			spaceSuit = "S3";
			break;
		}
		default:
		{
			spaceSuit = "S4";
			break;
		}
		}
		out << "Имя: " << human.name << std::endl << "Фамилия: " << human.surname << std::endl << "Возраст: " << human.age << std::endl << "Скафандр: " << spaceSuit << std::endl << std::endl;
		return out;
	}

	std::istream& operator>>(std::istream& in, Human& human)
	{
		std::cout << "Имя: ";
		in >> human.name;
		std::cout << std::endl;
		std::cout << "Фамилия: ";
		in >> human.surname;
		std::cout << std::endl;
		std::cout << "Возраст: ";
		in >> human.age;
		std::cout << std::endl;
		std::cout << "Логин: ";
		in >> human.login;
		std::cout << std::endl;
		std::cout << "Пароль: ";
		in >> human.password;
		std::cout << std::endl;
		std::cout << "Выберите скафандр. Возможные варианты:" << std::endl;
		std::cout << "[1]    S1." << std::endl;
		std::cout << "[2]    S2." << std::endl;
		std::cout << "[3]    S3." << std::endl;
		std::cout << "[4]    S4." << std::endl;
		std::cout << "Скафандр: ";
		int command = 0;
		std::cin >> command;
		switch (command)
		{
		case 1:
		{
			human.spaceSuit = S1;
			break;
		}
		case 2:
		{
			human.spaceSuit = S2;
			break;
		}
		case 3:
		{
			human.spaceSuit = S3;
			break;
		}
		default:
		{
			human.spaceSuit = S4;
			break;
		}
		}
		return in;
	}

	void exit()
	{
		Menu::exitFromMenu = true;
	}

	void logIn()
	{
		std::cout << "Авторизация." << std::endl;
		std::cout << "Логин: ";
		std::string login;
		std::cin >> login;
		std::cout << "Пароль: ";
		std::string password;
		std::cin >> password;
		std::string loginTXT;
		std::string passwordTXT;
		bool isFind = false;
		std::ifstream fin("AdminTools.txt");
		while (!fin.eof() and !isFind)
		{
			fin >> loginTXT;
			fin >> passwordTXT;
			if ((loginTXT == login) and (passwordTXT == password))
			{
				Menu::visitor = admin;
				isFind = true;
				break;
			}
		}
		fin.close();
		if (!isFind)
		{
			std::ifstream fin1("UserTools.txt");
			while (!fin1.eof() and !isFind)
			{
				fin1 >> loginTXT;
				fin1 >> passwordTXT;
				if ((loginTXT == login) and (passwordTXT == password))
				{
					Menu::visitor = user;
					isFind = true;
					break;
				}
			}
			fin1.close();
		}
		system("cls");
		if (!isFind)
		{
			std::cout << "Нет данных о посетителе. Повторите попытку!" << std::endl;
			system("pause");
			system("cls");
			Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
		}
		else
		{
			if (Menu::visitor == admin)
			{
				std::cout << "Вы зашли как админ." << std::endl;
				system("pause");
				system("cls");
				createAdminMenu();
				Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
			}
			else
			{
				std::cout << "Вы зашли как пользователь." << std::endl;
				system("pause");
				system("cls");
				createUserMenu();
				Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
			}
		}
	}

	void registrationAsAdmin()
	{
		std::cout << "Регистрация админа." << std::endl;
		std::cout << "Логин: ";
		std::string login;
		std::cin >> login;
		std::cout << "Пароль: ";
		std::string password;
		std::cin >> password;
		std::ofstream fout("AdminTools.txt", std::ofstream::app);
		fout << '\n' << '\n' << login << '\n' << password;
		fout.close();
		system("cls");
		std::cout << "Вы зарегистрировали админа." << std::endl;
		system("pause");
		system("cls");
		Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
	}

	void registrationAsUser()
	{
		std::cout << "Регистрация пользователя." << std::endl;
		std::cout << "Логин: ";
		std::string login;
		std::cin >> login;
		std::cout << "Пароль: ";
		std::string password;
		std::cin >> password;
		std::ofstream fout("UserTools.txt", std::ofstream::app);
		fout << '\n' << '\n' << login << '\n' << password;
		fout.close();
		system("cls");
		std::cout << "Вы зарегистрировали пользователя." << std::endl;
		system("pause");
		system("cls");
		Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
	}

	void createAdminMenu()
	{
		int countAdminMenuItems = 8;
		Menu** adminMenu = new Menu * [countAdminMenuItems];

		int countCreateDataBaseMenuItems = 4;
		Menu** createDataBaseMenu = new Menu * [countCreateDataBaseMenuItems];
		createDataBaseMenu[0] = new Menu(createDataBaseEmployee, new char[255] {"[1]    Создание базы данных сотрудников."});
		createDataBaseMenu[1] = new Menu(createDataBaseAstronauts, new char[255] {"[2]    Создание базы данных астронавтов."});
		createDataBaseMenu[2] = new Menu(createDataBaseCargoSpaceShips, new char[255] {"[3]    Создание базы данных грузовых кораблей."});
		createDataBaseMenu[3] = new Menu(createDataBaseHighSpeedSpaceShips, new char[255] {"[4]    Создание базы данных высокоскоростных кораблей."});
		adminMenu[0] = new Menu(createDataBaseMenu, new char[255] {"[1]    Создание баз данных."}, countCreateDataBaseMenuItems);

		int countDeleteMenuItems = 4;
		Menu** deleteMenu = new Menu * [countDeleteMenuItems];
		deleteMenu[0] = new Menu(deleteInDataBaseEmployee, new char[255] {"[1]    Удаление из базы данных сотрудников."});
		deleteMenu[1] = new Menu(deleteInDataBaseAstronauts, new char[255] {"[2]    Удаление из базы данных астронавтов."});
		deleteMenu[2] = new Menu(deleteInDataBaseCargo, new char[255] {"[3]    Удаление из базы данных грузовых кораблей."});
		deleteMenu[3] = new Menu(deleteInDataBaseHighSpeed, new char[255] {"[4]    Удаление из базы данных высокоскоростных кораблей."});
		adminMenu[1] = new Menu(deleteMenu, new char[255] {"[2]    Удаление из баз данных."}, countDeleteMenuItems);

		int countRedactMenuItems = 4;
		Menu** redactMenu = new Menu * [countRedactMenuItems];
		redactMenu[0] = new Menu(redactDataBaseEmployee, new char[255] {"[1]    Редактирование базы данных сотрудников."});
		redactMenu[1] = new Menu(redactDataBaseAstronauts, new char[255] {"[2]    Редактирование базы данных астронавтов."});
		redactMenu[2] = new Menu(redactDataBaseCargo, new char[255] {"[3]    Редактирование базы данных грузовых кораблей."});
		redactMenu[3] = new Menu(redactDataBaseHighSpeed, new char[255] {"[4]    Редактирование базы данных высокоскоростных кораблей."});

		adminMenu[2] = new Menu(redactMenu, new char[255] {"[3]    Редактирование баз данных."}, countRedactMenuItems);

		int countSortMenuItems = 4;
		Menu** sortMenu = new Menu * [countSortMenuItems];
		int countSortEmployeeMenuItems = 2;
		Menu** sortEmployeeMenu = new Menu * [countSortEmployeeMenuItems];
		sortEmployeeMenu[0] = new Menu(sortUpEmployee, new char[255] {"[1]    Сортировка по возрастанию."});
		sortEmployeeMenu[1] = new Menu(sortDownEmployee, new char[255] {"[2]    Сортировка по убыванию."});
		sortMenu[0] = new Menu(sortEmployeeMenu, new char[255] {"[1]    Сортировка базы данных сотрудников."}, countSortEmployeeMenuItems);
		int countSortAstronautsMenuItems = 2;
		Menu** sortAstronautsMenu = new Menu * [countSortAstronautsMenuItems];
		sortAstronautsMenu[0] = new Menu(sortUpAstronauts, new char[255] {"[1]    Сортировка по возрастанию."});
		sortAstronautsMenu[1] = new Menu(sortDownAstronauts, new char[255] {"[2]    Сортировка по убыванию."});
		sortMenu[1] = new Menu(sortAstronautsMenu, new char[255] {"[2]    Сортировка базы данных астронавтов."}, countSortAstronautsMenuItems);
		int countSortCargoMenuItems = 2;
		Menu** sortCargoMenu = new Menu * [countSortCargoMenuItems];
		sortCargoMenu[0] = new Menu(sortUpCargo, new char[255] {"[1]    Сортировка по возрастанию."});
		sortCargoMenu[1] = new Menu(sortDownCargo, new char[255] {"[2]    Сортировка по убыванию."});
		sortMenu[2] = new Menu(sortCargoMenu, new char[255] {"[3]    Сортировка базы данных грузовых кораблей."}, countSortCargoMenuItems);
		int countSortHighSpeedMenuItems = 2;
		Menu** sortHighSpeedMenu = new Menu * [countSortHighSpeedMenuItems];
		sortHighSpeedMenu[0] = new Menu(sortUpHighSpeed, new char[255] {"[1]    Сортировка по возрастанию."});
		sortHighSpeedMenu[1] = new Menu(sortDownHighSpeed, new char[255] {"[2]    Сортировка по убыванию."});
		sortMenu[3] = new Menu(sortHighSpeedMenu, new char[255] {"[3]    Сортировка базы данных высокоскоростных кораблей."}, countSortHighSpeedMenuItems);
		adminMenu[3] = new Menu(sortMenu, new char[255] {"[4]    Сортировка баз данных."}, countSortMenuItems);

		int countFiltrMenuItems = 4;
		Menu** filtrMenu = new Menu * [countFiltrMenuItems];
		int countFiltrEmployeeMenuItems = 4;
		Menu** filtrEmployeeMenu = new Menu * [countFiltrEmployeeMenuItems];
		filtrEmployeeMenu[0] = new Menu(filtrEmployeeSpaceSuitS1, new char[255] {"[1]    Фильтрация сотрудников по скафандру типа S1."});
		filtrEmployeeMenu[1] = new Menu(filtrEmployeeSpaceSuitS2, new char[255] {"[2]    Фильтрация сотрудников по скафандру типа S2."});
		filtrEmployeeMenu[2] = new Menu(filtrEmployeeSpaceSuitS3, new char[255] {"[3]    Фильтрация сотрудников по скафандру типа S3."});
		filtrEmployeeMenu[3] = new Menu(filtrEmployeeSpaceSuitS4, new char[255] {"[4]    Фильтрация сотрудников по скафандру типа S4."});
		filtrMenu[0] = new Menu(filtrEmployeeMenu, new char[255] {"[1]    Фильтрация базы данных сотрудников по скафандру."}, countFiltrEmployeeMenuItems);
		
		int countFiltrAstronautsMenuItems = 4;
		Menu** filtrAstronautsMenu = new Menu * [countFiltrAstronautsMenuItems];
		filtrAstronautsMenu[0] = new Menu(filtrAstronautsSpaceSuitS1, new char[255] {"[1]    Фильтрация астронавтов по скафандру типа S1."});
		filtrAstronautsMenu[1] = new Menu(filtrAstronautsSpaceSuitS2, new char[255] {"[2]    Фильтрация астронавтов по скафандру типа S2."});
		filtrAstronautsMenu[2] = new Menu(filtrAstronautsSpaceSuitS3, new char[255] {"[3]    Фильтрация астронавтов по скафандру типа S3."});
		filtrAstronautsMenu[3] = new Menu(filtrAstronautsSpaceSuitS4, new char[255] {"[4]    Фильтрация астронавтов по скафандру типа S4."});
		filtrMenu[1] = new Menu(filtrAstronautsMenu, new char[255] {"[2]    Фильтрация базы данных астронавтов по скафандру."}, countFiltrAstronautsMenuItems);
		
		int countFiltrCargoMenuItems = 4;
		Menu** filtrCargoMenu = new Menu * [countFiltrCargoMenuItems];
		filtrCargoMenu[0] = new Menu(filtrCargoReadyToLaunch, new char[255] {"[1]    Фильтрация грузовых кораблей, готовых к вылету."});
		filtrCargoMenu[1] = new Menu(filtrCargoBroken, new char[255] {"[2]    Фильтрация сломанных грузовых кораблей."});
		filtrCargoMenu[2] = new Menu(filtrCargoLaunchPlanned, new char[255] {"[3]    Фильтрация грузовых кораблей, у которых можно запланировать запуск."});
		filtrCargoMenu[3] = new Menu(filtrCargoRepair, new char[255] {"[4]    Фильтрация грузовых кораблей, находящихся в ремонте."});
		filtrMenu[2] = new Menu(filtrCargoMenu, new char[255] {"[3]    Фильтрация базы данных грузовых кораблей."}, countFiltrCargoMenuItems);
		
		int countFiltrHighSpeedMenuItems = 4;
		Menu** filtrHighSpeedMenu = new Menu * [countFiltrHighSpeedMenuItems];
		filtrHighSpeedMenu[0] = new Menu(filtrHighSpeedReadyToLaunch, new char[255] {"[1]    Фильтрация высокоскоростных кораблей, готовых к вылету."});
		filtrHighSpeedMenu[1] = new Menu(filtrHighSpeedBroken, new char[255] {"[2]    Фильтрация сломанных высокоскоростных кораблей."});
		filtrHighSpeedMenu[2] = new Menu(filtrHighSpeedLaunchPlanned, new char[255] {"[3]    Фильтрация высокоскоростных кораблей, у которых можно запланировать запуск."});
		filtrHighSpeedMenu[3] = new Menu(filtrHighSpeedRepair, new char[255] {"[4]    Фильтрация высокоскоростных кораблей, находящихся в ремонте."});
		filtrMenu[3] = new Menu(filtrHighSpeedMenu, new char[255] {"[4]    Фильтрация базы данных высокоскоростных кораблей."}, countFiltrHighSpeedMenuItems);
		
		adminMenu[4] = new Menu(filtrMenu, new char[255] {"[5]    Фильтрация баз данных."}, countFiltrMenuItems);

		int countAddMenuItems = 4;
		Menu** addMenu = new Menu * [countAddMenuItems];
		addMenu[0] = new Menu(addEmployee, new char[255] {"[1]    Добавление в базу данных сотрудников."});
		addMenu[1] = new Menu(addAstronauts, new char[255] {"[2]    Добавление в базу данных астронавтов."});
		addMenu[2] = new Menu(addCargo, new char[255] {"[3]    Добавление в базу данных грузовых кораблей."});
		addMenu[3] = new Menu(addHighSpeed, new char[255] {"[4]    Добавление в базу данных высокоскоростных кораблей."});
		adminMenu[5] = new Menu(addMenu, new char[255] {"[6]    Добавление в базы данных."}, countAddMenuItems);

		adminMenu[6] = new Menu(exit, new char[255] {"[7]    Выход."});

		int countPrintMenuItems = 4;
		Menu** printMenu = new Menu * [countPrintMenuItems];
		printMenu[0] = new Menu(printEmployee, new char[255] {"[1]    Вывод базы данных сотрудников."});
		printMenu[1] = new Menu(printAstronauts, new char[255] {"[2]    Вывод базы данных астронавтов."});
		printMenu[2] = new Menu(printCargo, new char[255] {"[3]    Вывод базы данных грузовых кораблей."});
		printMenu[3] = new Menu(printHighSpeed, new char[255] {"[4]    Вывод базы данных высокоскоростных кораблей."});
		adminMenu[7] = new Menu(printMenu, new char[255] {"[8]    Вывод баз данных."}, countPrintMenuItems);

		Menu::countLastMenuItems = countAdminMenuItems;
		Menu::lastMenu = adminMenu;
	}

	void createUserMenu()
	{
		int countUserMenuItems = 2;
		Menu** userMenu = new Menu * [countUserMenuItems];
		
		userMenu[0] = new Menu(writeTheAction, new char[255] {"[1]    Запись действий в журнал."});

		userMenu[1] = new Menu(exit, new char[255] {"[2]    Выход."});

		Menu::countLastMenuItems = countUserMenuItems;
		Menu::lastMenu = userMenu;
	}

	void writeTheAction()
	{
		Container records;
		records.createRecords();
		std::ofstream fout("Records.txt", std::ofstream::app);
		int i = 1;
		for (std::string str : records)
		{
			fout << "Запись " << i << ":" << std::endl << str << std::endl << std::endl;
			i++;
		}
		fout.close();
		std::cout << "Вы записали ваши действия в журнал." << std::endl;
		system("pause");

	}

	void createDataBaseEmployee()
	{
		std::cout << "Сколько сотрудников вы хотите ввести: ";
		std::cin >> Employee::countEmployee;
		Employee::employee = new Employee[Employee::countEmployee];
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			Employee newEmployee;
			std::cin >> newEmployee;
			Employee::employee[i] = newEmployee;
			std::cout << std::endl;
		}
		std::ofstream fout("Employee.txt", std::ofstream::app);
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			fout << Employee::employee[i];
		}
		fout.close();
	}

	void createDataBaseAstronauts()
	{
		std::cout << "Сколько астронавтов вы хотите ввести: ";
		std::cin >> Astronaut::countAstronauts;
		Astronaut::astronauts = new Astronaut[Astronaut::countAstronauts];
		for (int i = 0; i < Astronaut::countAstronauts; i++)
		{
			Astronaut newAstronaut;
			std::cin >> newAstronaut;
			Astronaut::astronauts[i] = newAstronaut;
			std::cout << std::endl;
		}
		std::ofstream fout("Astronauts.txt", std::ofstream::app);
		for (int i = 0; i < Astronaut::countAstronauts; i++)
		{
			fout << Astronaut::astronauts[i];
		}
		fout.close();
	}

	void deleteInDataBaseEmployee()
	{
		std::cout << "Удаление сотрудника из базы данных." << std::endl << std::endl;
		Employee print;
		print.print(Employee::employee, Employee::countEmployee);
		std::cout << "Введите номер сотрудника, которого вы хотите удалить из базы данных: ";
		int command = 0;
		std::cin >> command;
		Employee::countEmployee--;
		Employee* newEmployee = new Employee[Employee::countEmployee];
		int i = 0;
		while (i != command - 1)
		{
			newEmployee[i] = Employee::employee[i];
			i++;
		}
		while (i != Employee::countEmployee)
		{
			newEmployee[i] = Employee::employee[i + 1];
			i++;
		}
		delete[] Employee::employee;
		Employee::employee = newEmployee;
		system("cls");
		std::cout << "Вы удалили одного сотрудника из базы данных." << std::endl;
		system("pause");
	}

	void deleteInDataBaseAstronauts()
	{
		std::cout << "Удаление астронавта из базы данных." << std::endl << std::endl;
		Astronaut print;
		print.print(Astronaut::astronauts, Astronaut::countAstronauts);
		std::cout << "Введите номер астронавта, которого вы хотите удалить из базы данных: ";
		int command = 0;
		std::cin >> command;
		Astronaut::countAstronauts--;
		Astronaut* newAstronauts = new Astronaut[Astronaut::countAstronauts];
		int i = 0;
		while (i != command - 1)
		{
			newAstronauts[i] = Astronaut::astronauts[i];
			i++;
		}
		while (i != Astronaut::countAstronauts)
		{
			newAstronauts[i] = Astronaut::astronauts[i + 1];
			i++;
		}
		delete[] Astronaut::astronauts;
		Astronaut::astronauts = newAstronauts;
		system("cls");
		std::cout << "Вы удалили одного астронавта из базы данных." << std::endl;
		system("pause");
	}

	void deleteInDataBaseCargo()
	{
		std::cout << "Удаление грузового корабля из базы данных." << std::endl << std::endl;
		CargoSpaceShip print;
		print.print(CargoSpaceShip::cargoSpaceShips, CargoSpaceShip::countCargoSpaceShips);
		std::cout << "Введите номер грузового корабля, которого вы хотите удалить из базы данных: ";
		int command = 0;
		std::cin >> command;
		CargoSpaceShip::countCargoSpaceShips--;
		CargoSpaceShip* newCargoSpaceShips = new CargoSpaceShip[CargoSpaceShip::countCargoSpaceShips];
		int i = 0;
		while (i != command - 1)
		{
			newCargoSpaceShips[i] = CargoSpaceShip::cargoSpaceShips[i];
			i++;
		}
		while (i != CargoSpaceShip::countCargoSpaceShips)
		{
			newCargoSpaceShips[i] = CargoSpaceShip::cargoSpaceShips[i + 1];
			i++;
		}
		delete[] CargoSpaceShip::cargoSpaceShips;
		CargoSpaceShip::cargoSpaceShips = newCargoSpaceShips;
		system("cls");
		std::cout << "Вы удалили один грузовой корабль из базы данных." << std::endl;
		system("pause");
	}

	void deleteInDataBaseHighSpeed()
	{
		std::cout << "Удаление высокоскоростного корабля из базы данных." << std::endl << std::endl;
		HighSpeedSpaceShip print;
		print.print(HighSpeedSpaceShip::highSpeedSpaceShips, HighSpeedSpaceShip::countHighSpeedSpaceShips);
		std::cout << "Введите номер грузового корабля, которого вы хотите удалить из базы данных: ";
		int command = 0;
		std::cin >> command;
		HighSpeedSpaceShip::countHighSpeedSpaceShips--;
		HighSpeedSpaceShip* newHighSpeedSpaceShips = new HighSpeedSpaceShip[HighSpeedSpaceShip::countHighSpeedSpaceShips];
		int i = 0;
		while (i != command - 1)
		{
			newHighSpeedSpaceShips[i] = HighSpeedSpaceShip::highSpeedSpaceShips[i];
			i++;
		}
		while (i != HighSpeedSpaceShip::countHighSpeedSpaceShips)
		{
			newHighSpeedSpaceShips[i] = HighSpeedSpaceShip::highSpeedSpaceShips[i + 1];
			i++;
		}
		delete[] HighSpeedSpaceShip::highSpeedSpaceShips;
		HighSpeedSpaceShip::highSpeedSpaceShips = newHighSpeedSpaceShips;
		system("cls");
		std::cout << "Вы удалили один высокоскоростной корабль корабль из базы данных." << std::endl;
		system("pause");
	}

	void redactDataBaseEmployee()
	{
		std::cout << "Редактирование базы данных сотрудников." << std::endl << std::endl;
		Employee print;
		print.print(Employee::employee, Employee::countEmployee);
		std::cout << "Введите номер сотрудника, которого вы хотите отредактировать: ";
		int command = 0;
		std::cin >> command;
		system("cls");
		std::cout << "Старые данные:" << std::endl;
		std::cout << Employee::employee[command - 1] << std::endl;
		std::cout << "Введите новые данные:" << std::endl;
		Employee newEmployee;
		std::cin >> newEmployee;
		Employee::employee[command - 1] = newEmployee;
		system("pause");
	}

	void redactDataBaseAstronauts()
	{
		std::cout << "Редактирование базы данных астронавтов." << std::endl << std::endl;
		Astronaut print;
		print.print(Astronaut::astronauts, Astronaut::countAstronauts);
		std::cout << "Введите номер сотрудника, которого вы хотите отредактировать: ";
		int command = 0;
		std::cin >> command;
		system("cls");
		std::cout << "Старые данные:" << std::endl;
		std::cout << Astronaut::astronauts[command - 1] << std::endl;
		std::cout << "Введите новые данные:" << std::endl;
		Astronaut newAstronaut;
		std::cin >> newAstronaut;
		Astronaut::astronauts[command - 1] = newAstronaut;
		system("pause");
	}

	void redactDataBaseCargo()
	{
		std::cout << "Редактирование базы данных грузовых кораблей." << std::endl << std::endl;
		CargoSpaceShip print;
		print.print(CargoSpaceShip::cargoSpaceShips, CargoSpaceShip::countCargoSpaceShips);
		std::cout << "Введите номер грузового корабля, который вы хотите отредактировать: ";
		int command = 0;
		std::cin >> command;
		system("cls");
		std::cout << "Старые данные:" << std::endl;
		std::cout << CargoSpaceShip::cargoSpaceShips[command - 1] << std::endl;
		std::cout << "Введите новые данные:" << std::endl;
		CargoSpaceShip newCargoSpaceShip;
		std::cin >> newCargoSpaceShip;
		CargoSpaceShip::cargoSpaceShips[command - 1] = newCargoSpaceShip;
		system("pause");
	}

	void redactDataBaseHighSpeed()
	{
		std::cout << "Редактирование базы данных высокоскоростных кораблей." << std::endl << std::endl;
		HighSpeedSpaceShip print;
		print.print(HighSpeedSpaceShip::highSpeedSpaceShips, HighSpeedSpaceShip::countHighSpeedSpaceShips);
		std::cout << "Введите номер высокоскоростного корабля, который вы хотите отредактировать: ";
		int command = 0;
		std::cin >> command;
		system("cls");
		std::cout << "Старые данные:" << std::endl;
		std::cout << HighSpeedSpaceShip::highSpeedSpaceShips[command - 1] << std::endl;
		std::cout << "Введите новые данные:" << std::endl;
		HighSpeedSpaceShip newHighSpeedSpaceShip;
		std::cin >> newHighSpeedSpaceShip;
		HighSpeedSpaceShip::highSpeedSpaceShips[command - 1] = newHighSpeedSpaceShip;
		system("pause");
	}

	void sortUpEmployee()
	{
		std::cout << "Сортировка базы данных сотрудников по возрастанию возраста:" << std::endl << std::endl;
		for (int i = 1; i < Employee::countEmployee; i++)
		{
			for (int j = 0; j < (Employee::countEmployee - 1); j++)
			{
				if (Employee::employee[j] > Employee::employee[j + 1])
				{
					Employee bufEmployee = Employee::employee[j];
					Employee::employee[j] = Employee::employee[j + 1];
					Employee::employee[j + 1] = bufEmployee;
				}
			}
		}
		Employee print;
		print.print(Employee::employee, Employee::countEmployee);
	}

	void sortDownEmployee()
	{
		std::cout << "Сортировка базы данных сотрудников по убыванию возраста:" << std::endl << std::endl;
		for (int i = 1; i < Employee::countEmployee; i++)
		{
			for (int j = 0; j < (Employee::countEmployee - 1); j++)
			{
				if (Employee::employee[j] < Employee::employee[j + 1])
				{
					Employee bufEmployee = Employee::employee[j];
					Employee::employee[j] = Employee::employee[j + 1];
					Employee::employee[j + 1] = bufEmployee;
				}
			}
		}
		Employee print;
		print.print(Employee::employee, Employee::countEmployee);
	}

	void sortUpAstronauts()
	{
		std::cout << "Сортировка базы данных астронавтов по возрастанию возраста:" << std::endl << std::endl;
		for (int i = 1; i < Astronaut::countAstronauts; i++)
		{
			for (int j = 0; j < (Astronaut::countAstronauts - 1); j++)
			{
				if (Astronaut::astronauts[j] > Astronaut::astronauts[j + 1])
				{
					Astronaut bufAstronaut = Astronaut::astronauts[j];
					Astronaut::astronauts[j] = Astronaut::astronauts[j + 1];
					Astronaut::astronauts[j + 1] = bufAstronaut;
				}
			}
		}
		Astronaut print;
		print.print(Astronaut::astronauts, Astronaut::countAstronauts);
	}
	void sortDownAstronauts()
	{
		std::cout << "Сортировка базы данных астронавтов по убыванию возраста:" << std::endl << std::endl;
		for (int i = 1; i < Astronaut::countAstronauts; i++)
		{
			for (int j = 0; j < (Astronaut::countAstronauts - 1); j++)
			{
				if (Astronaut::astronauts[j] < Astronaut::astronauts[j + 1])
				{
					Astronaut bufAstronaut = Astronaut::astronauts[j];
					Astronaut::astronauts[j] = Astronaut::astronauts[j + 1];
					Astronaut::astronauts[j + 1] = bufAstronaut;
				}
			}
		}
		Astronaut print;
		print.print(Astronaut::astronauts, Astronaut::countAstronauts);
	}

	void sortUpCargo()
	{
		std::cout << "Сортировка базы данных грузовых кораблей по возрастанию массы:" << std::endl << std::endl;
		for (int i = 1; i < CargoSpaceShip::countCargoSpaceShips; i++)
		{
			for (int j = 0; j < (CargoSpaceShip::countCargoSpaceShips - 1); j++)
			{
				if (CargoSpaceShip::cargoSpaceShips[j] > CargoSpaceShip::cargoSpaceShips[j + 1])
				{
					CargoSpaceShip bufAstronaut = CargoSpaceShip::cargoSpaceShips[j];
					CargoSpaceShip::cargoSpaceShips[j] = CargoSpaceShip::cargoSpaceShips[j + 1];
					CargoSpaceShip::cargoSpaceShips[j + 1] = bufAstronaut;
				}
			}
		}
		CargoSpaceShip print;
		print.print(CargoSpaceShip::cargoSpaceShips, CargoSpaceShip::countCargoSpaceShips);
	}

	void sortDownCargo()
	{
		std::cout << "Сортировка базы данных грузовых кораблей по убыванию массы:" << std::endl << std::endl;
		for (int i = 1; i < CargoSpaceShip::countCargoSpaceShips; i++)
		{
			for (int j = 0; j < (CargoSpaceShip::countCargoSpaceShips - 1); j++)
			{
				if (CargoSpaceShip::cargoSpaceShips[j] < CargoSpaceShip::cargoSpaceShips[j + 1])
				{
					CargoSpaceShip bufAstronaut = CargoSpaceShip::cargoSpaceShips[j];
					CargoSpaceShip::cargoSpaceShips[j] = CargoSpaceShip::cargoSpaceShips[j + 1];
					CargoSpaceShip::cargoSpaceShips[j + 1] = bufAstronaut;
				}
			}
		}
		CargoSpaceShip print;
		print.print(CargoSpaceShip::cargoSpaceShips, CargoSpaceShip::countCargoSpaceShips);
	}

	void sortUpHighSpeed()
	{
		std::cout << "Сортировка базы данных высокоскоростных кораблей по возрастанию массы:" << std::endl << std::endl;
		for (int i = 1; i < HighSpeedSpaceShip::countHighSpeedSpaceShips; i++)
		{
			for (int j = 0; j < (HighSpeedSpaceShip::countHighSpeedSpaceShips - 1); j++)
			{
				if (HighSpeedSpaceShip::highSpeedSpaceShips[j] > HighSpeedSpaceShip::highSpeedSpaceShips[j + 1])
				{
					HighSpeedSpaceShip bufAstronaut = HighSpeedSpaceShip::highSpeedSpaceShips[j];
					HighSpeedSpaceShip::highSpeedSpaceShips[j] = HighSpeedSpaceShip::highSpeedSpaceShips[j + 1];
					HighSpeedSpaceShip::highSpeedSpaceShips[j + 1] = bufAstronaut;
				}
			}
		}
		HighSpeedSpaceShip print;
		print.print(HighSpeedSpaceShip::highSpeedSpaceShips, HighSpeedSpaceShip::countHighSpeedSpaceShips);
	}

	void sortDownHighSpeed()
	{
		std::cout << "Сортировка базы данных высокоскоростных кораблей по убыванию массы:" << std::endl << std::endl;
		for (int i = 1; i < HighSpeedSpaceShip::countHighSpeedSpaceShips; i++)
		{
			for (int j = 0; j < (HighSpeedSpaceShip::countHighSpeedSpaceShips - 1); j++)
			{
				if (HighSpeedSpaceShip::highSpeedSpaceShips[j] < HighSpeedSpaceShip::highSpeedSpaceShips[j + 1])
				{
					HighSpeedSpaceShip bufAstronaut = HighSpeedSpaceShip::highSpeedSpaceShips[j];
					HighSpeedSpaceShip::highSpeedSpaceShips[j] = HighSpeedSpaceShip::highSpeedSpaceShips[j + 1];
					HighSpeedSpaceShip::highSpeedSpaceShips[j + 1] = bufAstronaut;
				}
			}
		}
		HighSpeedSpaceShip print;
		print.print(HighSpeedSpaceShip::highSpeedSpaceShips, HighSpeedSpaceShip::countHighSpeedSpaceShips);
	}

	bool operator>(const SpaceShip& spaceShip1, const SpaceShip& spaceShip2)
	{
		return spaceShip1.weight > spaceShip2.weight;
	}

	bool operator<(const SpaceShip& spaceShip1, const SpaceShip& spaceShip2)
	{
		return spaceShip1.weight < spaceShip2.weight;
	}

	void filtrEmployeeSpaceSuitS1()
	{
		std::cout << "База данных сотрудников отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			if (Employee::employee[i].getSpaceSuit() == S1)
			{
				std::string spaceSuit = "S1";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) <<  Employee::employee[i].getName()/*getName(Employee::employee[i])*/ << std::setw(10) << "|" << std::setw(12) << Employee::employee[i].getSurname() << std::setw(12) << "|" << std::setw(12) << Employee::employee[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrAstronautsSpaceSuitS1()
	{
		std::cout << "База данных астронавтов отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Astronaut::countAstronauts; i++)
		{
			if (Astronaut::astronauts[i].getSpaceSuit() == S1)
			{
				std::string spaceSuit = "S1";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << Employee::employee[i].getName() << std::setw(10) << "|" << std::setw(12) << Employee::employee[i].getSurname() << std::setw(12) << "|" << std::setw(12) << Employee::employee[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrEmployeeSpaceSuitS2()
	{
		std::cout << "База данных сотрудников отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			if (Employee::employee[i].getSpaceSuit() == S2)
			{
				std::string spaceSuit = "S2";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << Employee::employee[i].getName() << std::setw(10) << "|" << std::setw(12) << Employee::employee[i].getSurname() << std::setw(12) << "|" << std::setw(12) << Employee::employee[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrAstronautsSpaceSuitS2()
	{
		std::cout << "База данных астронавтов отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Astronaut::countAstronauts; i++)
		{
			if (Astronaut::astronauts[i].getSpaceSuit() == S2)
			{
				std::string spaceSuit = "S2";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << Astronaut::astronauts[i].getName() << std::setw(10) << "|" << std::setw(12) << Astronaut::astronauts[i].getSurname() << std::setw(12) << "|" << std::setw(12) << Astronaut::astronauts[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrEmployeeSpaceSuitS3()
	{
		std::cout << "База данных сотрудников отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			if (Employee::employee[i].getSpaceSuit() == S3)
			{
				std::string spaceSuit = "S3";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << Employee::employee[i].getName() << std::setw(10) << "|" << std::setw(12) << Employee::employee[i].getSurname() << std::setw(12) << "|" << std::setw(12) << Employee::employee[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrAstronautsSpaceSuitS3()
	{
		std::cout << "База данных астронавтов отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Astronaut::countAstronauts; i++)
		{
			if (Astronaut::astronauts[i].getSpaceSuit() == S3)
			{
				std::string spaceSuit = "S3";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << Astronaut::astronauts[i].getName() << std::setw(10) << "|" << std::setw(12) << Astronaut::astronauts[i].getSurname() << std::setw(12) << "|" << std::setw(12) << Astronaut::astronauts[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrEmployeeSpaceSuitS4()
	{
		std::cout << "База данных сотрудников отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			if (Employee::employee[i].getSpaceSuit() == S4)
			{
				std::string spaceSuit = "S4";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << Employee::employee[i].getName() << std::setw(10) << "|" << std::setw(12) << Employee::employee[i].getSurname() << std::setw(12) << "|" << std::setw(12) << Employee::employee[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrAstronautsSpaceSuitS4()
	{
		std::cout << "База данных астронавтов отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Astronaut::countAstronauts; i++)
		{
			if (Astronaut::astronauts[i].getSpaceSuit() == S4)
			{
				std::string spaceSuit = "S4";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << Astronaut::astronauts[i].getName()<< std::setw(10) << "|" << std::setw(12) << Astronaut::astronauts[i].getSurname() << std::setw(12) << "|" << std::setw(12) << Astronaut::astronauts[i].getAge()<< std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrCargoReadyToLaunch()
	{
		std::cout << "Отфильтрованная база данных грузовых кораблей:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя корабля        |        Состояние        |        Дата        |        Время        |        Имя пилота        |        Фамилия пилота        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < CargoSpaceShip::countCargoSpaceShips; i++)
		{
			if (CargoSpaceShip::cargoSpaceShips[i].getCondition() == readyToLunch)
			{
				std::string condition = "Готов к вылету";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(14) << CargoSpaceShip::cargoSpaceShips[i].getName() << std::setw(14) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(11) << CargoSpaceShip::cargoSpaceShips[i].getDate() << std::setw(10) << "|" << std::setw(11) << CargoSpaceShip::cargoSpaceShips[i].getTime() << std::setw(11) << "|" << std::setw(14) << CargoSpaceShip::cargoSpaceShips[i].getPilot().getName() << std::setw(13) << "|" << std::setw(15) << CargoSpaceShip::cargoSpaceShips[i].getPilot().getSurname() << std::setw(16) << "|" << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrCargoBroken()
	{
		std::cout << "Отфильтрованная база данных грузовых кораблей:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя корабля        |        Состояние        |        Дата        |        Время        |        Имя пилота        |        Фамилия пилота        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < CargoSpaceShip::countCargoSpaceShips; i++)
		{
			if (CargoSpaceShip::cargoSpaceShips[i].getCondition() == broken)
			{
				std::string condition = "Сломан";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(14) << CargoSpaceShip::cargoSpaceShips[i].getName() << std::setw(14) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(11) << CargoSpaceShip::cargoSpaceShips[i].getDate() << std::setw(10) << "|" << std::setw(11) << CargoSpaceShip::cargoSpaceShips[i].getTime() << std::setw(11) << "|" << std::setw(14) << CargoSpaceShip::cargoSpaceShips[i].getPilot().getName() << std::setw(13) << "|" << std::setw(15) << CargoSpaceShip::cargoSpaceShips[i].getPilot().getSurname() << std::setw(16) << "|" << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrCargoLaunchPlanned()
	{
		std::cout << "Отфильтрованная база данных грузовых кораблей:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя корабля        |        Состояние        |        Дата        |        Время        |        Имя пилота        |        Фамилия пилота        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < CargoSpaceShip::countCargoSpaceShips; i++)
		{
			if (CargoSpaceShip::cargoSpaceShips[i].getCondition() == launhPlanned)
			{
				std::string condition = "";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(14) << CargoSpaceShip::cargoSpaceShips[i].getName() << std::setw(14) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(11) << CargoSpaceShip::cargoSpaceShips[i].getDate() << std::setw(10) << "|" << std::setw(11) << CargoSpaceShip::cargoSpaceShips[i].getTime() << std::setw(11) << "|" << std::setw(14) << CargoSpaceShip::cargoSpaceShips[i].getPilot().getName() << std::setw(13) << "|" << std::setw(15) << CargoSpaceShip::cargoSpaceShips[i].getPilot().getSurname() << std::setw(16) << "|" << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrCargoRepair()
	{
		std::cout << "Отфильтрованная база данных грузовых кораблей:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя корабля        |        Состояние        |        Дата        |        Время        |        Имя пилота        |        Фамилия пилота        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < CargoSpaceShip::countCargoSpaceShips; i++)
		{
			if (CargoSpaceShip::cargoSpaceShips[i].getCondition() == repair)
			{
				std::string condition = "Ремонт";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(14) << CargoSpaceShip::cargoSpaceShips[i].getName() << std::setw(14) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(11) << CargoSpaceShip::cargoSpaceShips[i].getDate() << std::setw(10) << "|" << std::setw(11) << CargoSpaceShip::cargoSpaceShips[i].getTime() << std::setw(11) << "|" << std::setw(14) << CargoSpaceShip::cargoSpaceShips[i].getPilot().getName() << std::setw(13) << "|" << std::setw(15) << CargoSpaceShip::cargoSpaceShips[i].getPilot().getSurname() << std::setw(16) << "|" << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrHighSpeedReadyToLaunch()
	{
		std::cout << "Отфильтрованная база данных высокоскоростных кораблей:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя корабля        |        Состояние        |        Дата        |        Время        |        Имя пилота        |        Фамилия пилота        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < HighSpeedSpaceShip::countHighSpeedSpaceShips; i++)
		{
			if (HighSpeedSpaceShip::highSpeedSpaceShips[i].getCondition() == readyToLunch)
			{
				std::string condition = "Готов к вылету";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(14) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getName() << std::setw(14) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(11) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getDate() << std::setw(10) << "|" << std::setw(11) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getTime() << std::setw(11) << "|" << std::setw(14) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getPilot().getName() << std::setw(13) << "|" << std::setw(15) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getPilot().getSurname() << std::setw(16) << "|" << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrHighSpeedBroken()
	{
		std::cout << "Отфильтрованная база данных высокоскоростных кораблей:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя корабля        |        Состояние        |        Дата        |        Время        |        Имя пилота        |        Фамилия пилота        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < HighSpeedSpaceShip::countHighSpeedSpaceShips; i++)
		{
			if (HighSpeedSpaceShip::highSpeedSpaceShips[i].getCondition() == broken)
			{
				std::string condition = "Сломан";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(14) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getName() << std::setw(14) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(11) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getDate() << std::setw(10) << "|" << std::setw(11) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getTime() << std::setw(11) << "|" << std::setw(14) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getPilot().getName() << std::setw(13) << "|" << std::setw(15) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getPilot().getSurname() << std::setw(16) << "|" << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrHighSpeedLaunchPlanned()
	{
		std::cout << "Отфильтрованная база данных высокоскоростных кораблей:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя корабля        |        Состояние        |        Дата        |        Время        |        Имя пилота        |        Фамилия пилота        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < HighSpeedSpaceShip::countHighSpeedSpaceShips; i++)
		{
			if (HighSpeedSpaceShip::highSpeedSpaceShips[i].getCondition() == broken)
			{
				std::string condition = "";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(14) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getName() << std::setw(14) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(11) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getDate() << std::setw(10) << "|" << std::setw(11) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getTime() << std::setw(11) << "|" << std::setw(14) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getPilot().getName() << std::setw(13) << "|" << std::setw(15) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getPilot().getSurname() << std::setw(16) << "|" << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void filtrHighSpeedRepair()
	{
		std::cout << "Отфильтрованная база данных высокоскоростных кораблей:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя корабля        |        Состояние        |        Дата        |        Время        |        Имя пилота        |        Фамилия пилота        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < HighSpeedSpaceShip::countHighSpeedSpaceShips; i++)
		{
			if (HighSpeedSpaceShip::highSpeedSpaceShips[i].getCondition() == broken)
			{
				std::string condition = "Ремонт";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(14) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getName() << std::setw(14) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(11) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getDate() << std::setw(10) << "|" << std::setw(11) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getTime() << std::setw(11) << "|" << std::setw(14) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getPilot().getName() << std::setw(13) << "|" << std::setw(15) << HighSpeedSpaceShip::highSpeedSpaceShips[i].getPilot().getSurname() << std::setw(16) << "|" << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	void addEmployee()
	{
		std::cout << "Сколько вы хотите добавить сотрудников: ";
		int count = 0;
		std::cin >> count;
		Employee::countEmployee += count;
		Employee* newEmployee = new Employee[Employee::countEmployee];
		for (int i = 0; i < (Employee::countEmployee - count); i++)
		{
			newEmployee[i] = Employee::employee[i];
		}
		for (int i = 0; i < count; i++)
		{
			std::cin >> newEmployee[i+Employee::countEmployee-count];
		}
		delete[] Employee::employee;
		Employee::employee = newEmployee;
	}

	void addAstronauts()
	{
		std::cout << "Сколько вы хотите добавить астронавтов: ";
		int count = 0;
		std::cin >> count;
		Astronaut::countAstronauts += count;
		Astronaut* newAstronauts = new Astronaut[Astronaut::countAstronauts];
		for (int i = 0; i < (Astronaut::countAstronauts - count); i++)
		{
			newAstronauts[i] = Astronaut::astronauts[i];
		}
		for (int i = 0; i < count; i++)
		{
			std::cin >> newAstronauts[i + Astronaut::countAstronauts - count];
		}
		delete[] Astronaut::astronauts;
		Astronaut::astronauts = newAstronauts;
	}

	void addCargo()
	{
		std::cout << "Сколько вы хотите добавить грузовых кораблей: ";
		int count = 0;
		std::cin >> count;
		CargoSpaceShip::countCargoSpaceShips += count;
		CargoSpaceShip* newCargoSpaceShips = new CargoSpaceShip[CargoSpaceShip::countCargoSpaceShips];
		for (int i = 0; i < (CargoSpaceShip::countCargoSpaceShips - count); i++)
		{
			newCargoSpaceShips[i] = CargoSpaceShip::cargoSpaceShips[i];
		}
		for (int i = 0; i < count; i++)
		{
			std::cin >> newCargoSpaceShips[i + CargoSpaceShip::countCargoSpaceShips - count];
		}
		delete[] CargoSpaceShip::cargoSpaceShips;
		CargoSpaceShip::cargoSpaceShips = newCargoSpaceShips;
	}

	void addHighSpeed()
	{
		std::cout << "Сколько вы хотите добавить высокоскоростных кораблей: ";
		int count = 0;
		std::cin >> count;
		HighSpeedSpaceShip::countHighSpeedSpaceShips += count;
		HighSpeedSpaceShip* newHighSpeedSpaceShips = new HighSpeedSpaceShip[HighSpeedSpaceShip::countHighSpeedSpaceShips];
		for (int i = 0; i < (HighSpeedSpaceShip::countHighSpeedSpaceShips - count); i++)
		{
			newHighSpeedSpaceShips[i] = HighSpeedSpaceShip::highSpeedSpaceShips[i];
		}
		for (int i = 0; i < count; i++)
		{
			std::cin >> newHighSpeedSpaceShips[i + HighSpeedSpaceShip::countHighSpeedSpaceShips - count];
		}
		delete[] HighSpeedSpaceShip::highSpeedSpaceShips;
		HighSpeedSpaceShip::highSpeedSpaceShips = newHighSpeedSpaceShips;
	}

	void printEmployee()
	{
		Employee print;
		print.print(Employee::employee, Employee::countEmployee);
	}

	void printAstronauts()
	{
		Astronaut print;
		print.print(Astronaut::astronauts, Astronaut::countAstronauts);
	}

	void printHighSpeed()
	{
		HighSpeedSpaceShip print;
		print.print(HighSpeedSpaceShip::highSpeedSpaceShips, HighSpeedSpaceShip::countHighSpeedSpaceShips);
	}

	void printCargo()
	{
		CargoSpaceShip print;
		print.print(CargoSpaceShip::cargoSpaceShips, CargoSpaceShip::countCargoSpaceShips);
	}
}