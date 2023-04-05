#include "Functions.h"

namespace GEV
{
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

		int countCreateDataBaseMenuItems = 2;
		Menu** createDataBaseMenu = new Menu * [countCreateDataBaseMenuItems];
		createDataBaseMenu[0] = new Menu(createDataBaseEmployee, new char[255] {"[1]    Создание базы данных сотрудников."});
		createDataBaseMenu[1] = new Menu(createDataBaseAstronauts, new char[255] {"[2]    Создание базы данных астронавтов."});
		adminMenu[0] = new Menu(createDataBaseMenu, new char[255] {"[1]    Создание баз данных."}, countCreateDataBaseMenuItems);

		int countDeleteMenuItems = 2;
		Menu** deleteMenu = new Menu * [countDeleteMenuItems];
		deleteMenu[0] = new Menu(deleteInDataBaseEmployee, new char[255] {"[1]    Удаление из базы данных сотрудников."});
		deleteMenu[1] = new Menu(deleteInDataBaseAstronauts, new char[255] {"[2]    Удаление из базы данных астронавтов."});
		adminMenu[1] = new Menu(deleteMenu, new char[255] {"[2]    Удаление из баз данных."}, countDeleteMenuItems);

		int countRedactMenuItems = 2;
		Menu** redactMenu = new Menu * [countRedactMenuItems];
		redactMenu[0] = new Menu(redactDataBaseEmployee, new char[255] {"[1]    Редактирование базы данных сотрудников."});
		redactMenu[1] = new Menu(redactDataBaseAstronauts, new char[255] {"[2]    Редактирование базы данных астронавтов."});
		adminMenu[2] = new Menu(redactMenu, new char[255] {"[3]    Редактирование баз данных."}, countRedactMenuItems);

		int countSortMenuItems = 2;
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
		adminMenu[3] = new Menu(sortMenu, new char[255] {"[4]    Сортировка баз данных."}, countSortMenuItems);

		int countFiltrMenuItems = 2;
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
		filtrMenu[1] = new Menu(filtrAstronautsMenu, new char[255] {"[1]    Фильтрация базы данных сотрудников по скафандру."}, countFiltrAstronautsMenuItems);
		adminMenu[4] = new Menu(filtrMenu, new char[255] {"[5]    Фильтрация баз данных."}, countFiltrMenuItems);

		int countAddMenuItems = 2;
		Menu** addMenu = new Menu * [countAddMenuItems];
		addMenu[0] = new Menu(addEmployee, new char[255] {"[1]    Добавление в базу данных сотрудников."});
		addMenu[1] = new Menu(addAstronauts, new char[255] {"[2]    Добавление в базу данных астронавтов."});
		adminMenu[5] = new Menu(addMenu, new char[255] {"[6]    Добавление в базы данных."}, countAddMenuItems);

		adminMenu[6] = new Menu(exit, new char[255] {"[7]    Выход."});

		int countPrintMenuItems = 2;
		Menu** printMenu = new Menu * [countPrintMenuItems];
		printMenu[0] = new Menu(printEmployee, new char[255] {"[1]    Вывод базы данных сотрудников."});
		printMenu[1] = new Menu(printAstronauts, new char[255] {"[2]    Вывод базы данных астронавтов."});
		adminMenu[7] = new Menu(printMenu, new char[255] {"[8]    Вывод баз данных."}, countPrintMenuItems);

		Menu::countLastMenuItems = countAdminMenuItems;
		Menu::lastMenu = adminMenu;
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
		std::cout << "Склько астронавтов вы хотите ввести: ";
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

	void redactDataBaseEmployee()
	{

	}

	void redactDataBaseAstronauts()
	{

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

	void filtrEmployeeSpaceSuitS1()
	{
		std::cout << "База данных сотрудников отфильтрованная:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			if (getSpaceSuit(Employee::employee[i]) == S1)
			{
				std::string spaceSuit = "S1";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << getName(Employee::employee[i]) << std::setw(10) << "|" << std::setw(12) << getSurname(Employee::employee[i]) << std::setw(12) << "|" << std::setw(12) << getAge(Employee::employee[i]) << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
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
			if (getSpaceSuit(Astronaut::astronauts[i]) == S1)
			{
				std::string spaceSuit = "S1";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << getName(Astronaut::astronauts[i]) << std::setw(10) << "|" << std::setw(12) << getSurname(Astronaut::astronauts[i]) << std::setw(12) << "|" << std::setw(12) << getAge(Astronaut::astronauts[i]) << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
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
			if (getSpaceSuit(Employee::employee[i]) == S2)
			{
				std::string spaceSuit = "S2";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << getName(Employee::employee[i]) << std::setw(10) << "|" << std::setw(12) << getSurname(Employee::employee[i]) << std::setw(12) << "|" << std::setw(12) << getAge(Employee::employee[i]) << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
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
			if (getSpaceSuit(Astronaut::astronauts[i]) == S2)
			{
				std::string spaceSuit = "S2";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << getName(Astronaut::astronauts[i]) << std::setw(10) << "|" << std::setw(12) << getSurname(Astronaut::astronauts[i]) << std::setw(12) << "|" << std::setw(12) << getAge(Astronaut::astronauts[i]) << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
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
			if (getSpaceSuit(Employee::employee[i]) == S3)
			{
				std::string spaceSuit = "S3";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << getName(Employee::employee[i]) << std::setw(10) << "|" << std::setw(12) << getSurname(Employee::employee[i]) << std::setw(12) << "|" << std::setw(12) << getAge(Employee::employee[i]) << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
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
			if (getSpaceSuit(Astronaut::astronauts[i]) == S3)
			{
				std::string spaceSuit = "S3";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << getName(Astronaut::astronauts[i]) << std::setw(10) << "|" << std::setw(12) << getSurname(Astronaut::astronauts[i]) << std::setw(12) << "|" << std::setw(12) << getAge(Astronaut::astronauts[i]) << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
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
			if (getSpaceSuit(Employee::employee[i]) == S4)
			{
				std::string spaceSuit = "S4";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << getName(Employee::employee[i]) << std::setw(10) << "|" << std::setw(12) << getSurname(Employee::employee[i]) << std::setw(12) << "|" << std::setw(12) << getAge(Employee::employee[i]) << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
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
			if (getSpaceSuit(Astronaut::astronauts[i]) == S4)
			{
				std::string spaceSuit = "S4";
				std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << getName(Astronaut::astronauts[i]) << std::setw(10) << "|" << std::setw(12) << getSurname(Astronaut::astronauts[i]) << std::setw(12) << "|" << std::setw(12) << getAge(Astronaut::astronauts[i]) << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
		system("pause");
	}

	std::string getName(Human& human)
	{
		return human.name;
	}

	std::string getSurname(Human& human)
	{
		return human.surname;
	}

	int getAge(Human& human)
	{
		return human.age;
	}

	std::string getLogin(Human& human)
	{
		return human.login;
	}

	std::string getPassword(Human& human)
	{
		return human.password;
	}

	SpaceSuit getSpaceSuit(Human& human)
	{
		return human.spaceSuit;
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
}