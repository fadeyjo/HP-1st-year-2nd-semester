#include "Functions.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

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
		string spaceSuit;
		if (human.spaceSuit == S1)
		{
			spaceSuit = "S1";
		}
		else
		{
			spaceSuit = "S2";
		}
		out << "Имя: " << human.name << endl << "Фамилия: " << human.surname << endl << "Возраст: " << human.age << endl << "Скафандр: " << spaceSuit << endl << endl;
		return out;
	}
	std::istream& operator>>(std::istream& in, Human& human)
	{
		cout << "Имя: ";
		in >> human.name;
		cout << "Фамилия: ";
		in >> human.surname;
		cout << "Возраст: ";
		in >> human.age;
		cout << "Логин: ";
		in >> human.login;
		cout << "Пароль: ";
		in >> human.password;
		return in;
	}
	void exit()
	{
		Menu::exit = true;
	}

	void logIn()
	{
		cout << "Авторизация." << endl;
		cout << "Логин: ";
		string login;
		cin >> login;
		cout << "Пароль: ";
		string password;
		cin >> password;
		string loginTXT;
		string passwordTXT;
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
			cout << "Нет данных о посетителе. Повторите попытку!" << endl;
			system("pause");
			system("cls");
			Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
		}
		else
		{
			if (Menu::visitor == admin)
			{
				cout << "Вы зашли как админ." << endl;
				system("pause");
				system("cls");
				createAdminMenu();
				Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
			}
			else
			{
				cout << "Вы зашли как пользователь." << endl;
				system("pause");
				system("cls");

			}
		}
	}

	void registrationAsAdmin()
	{
		cout << "Регистрация админа." << endl;
		cout << "Логин: ";
		string login;
		cin >> login;
		cout << "Пароль: ";
		string password;
		cin >> password;
		std::ofstream fout("AdminTools.txt", std::ofstream::app);
		fout << '\n' << '\n' << login << '\n' << password;
		fout.close();
		system("cls");
		cout << "Вы зарегистрировали админа." << endl;
		system("pause");
		system("cls");
		Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
	}

	void registrationAsUser()
	{
		cout << "Регистрация пользователя." << endl;
		cout << "Логин: ";
		string login;
		cin >> login;
		cout << "Пароль: ";
		string password;
		cin >> password;
		std::ofstream fout("UserTools.txt", std::ofstream::app);
		fout << '\n' << '\n' << login << '\n' << password;
		fout.close();
		system("cls");
		cout << "Вы зарегистрировали пользователя." << endl;
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
		int countFiltrEmployeeMenuItems = 2;
		Menu** filtrEmployeeMenu = new Menu * [countFiltrEmployeeMenuItems];
		filtrEmployeeMenu[0] = new Menu(filtrUpEmployee, new char[255] {"[1]    Фильрация по нижней границе возраста."});
		filtrEmployeeMenu[1] = new Menu(filtrDownEmployee, new char[255] {"[2]    Фильтрация по верхней границе возраста."});
		filtrMenu[0] = new Menu(sortEmployeeMenu, new char[255] {"[1]    Фильтрация базы данных сотрудников."}, countFiltrEmployeeMenuItems);
		int countFiltrAstronautsMenuItems = 2;
		Menu** filtrAstronautsMenu = new Menu * [countFiltrAstronautsMenuItems];
		filtrAstronautsMenu[0] = new Menu(filtrUpAstronauts, new char[255] {"[1]    Фильрация по нижней границе возраста."});
		filtrAstronautsMenu[1] = new Menu(filtrDownAstronauts, new char[255] {"[2]    Фильтрация по верхней границе возраста."});
		filtrMenu[1] = new Menu(filtrAstronautsMenu, new char[255] {"[2]    Фильтрация базы данных астронавтов."}, countFiltrAstronautsMenuItems);
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
		cout << "Склько сотрудников вы хотите ввести: ";
		cin >> Employee::countEmployee;
		Employee::employee = new Employee[Employee::countEmployee];
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			cout << "Имя: ";
			string name;
			cin >> name;
			Employee::employee[i].setName(name);

			cout << "Фамилия: ";
			string surname;
			cin >> surname;
			Employee::employee[i].setSurname(surname);

			cout << "Возраст: ";
			int age;
			cin >> age;
			Employee::employee[i].setAge(age);

			Employee::employee[i].setSpaceSuit();

			cout << "Логин: ";
			string login;
			cin >> login;
			Employee::employee[i].setLogin(login);

			cout << "Пароль: ";
			string password;
			cin >> password;
			Employee::employee[i].setPassword(password);

			cout << endl;
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
		cout << "Склько астронавтов вы хотите ввести: ";
		cin >> Astronaut::countAstronauts;
		Astronaut::astronauts = new Astronaut[Astronaut::countAstronauts];
		for (int i = 0; i < Astronaut::countAstronauts; i++)
		{
			cout << "Имя: ";
			string name;
			cin >> name;
			Astronaut::astronauts[i].setName(name);

			cout << "Фамилия: ";
			string surname;
			cin >> surname;
			Astronaut::astronauts[i].setSurname(surname);

			cout << "Возраст: ";
			int age;
			cin >> age;
			Astronaut::astronauts[i].setAge(age);

			Astronaut::astronauts[i].setSpaceSuit();

			cout << "Логин: ";
			string login;
			cin >> login;
			Astronaut::astronauts[i].setLogin(login);

			cout << "Пароль: ";
			string password;
			cin >> password;
			Astronaut::astronauts[i].setPassword(password);

			cout << endl;
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
		cout << "Удаление сотрудника из базы данных." << endl << endl;
		Employee print;
		print.print(Employee::employee, Employee::countEmployee);
		cout << "Введите номер сотрудника, которого вы хотите удалить из базы данных: ";
		int command = 0;
		cin >> command;
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
		cout << "Вы удалили одного сотрудника из базы данных." << endl;
		system("pause");
	}

	void deleteInDataBaseAstronauts()
	{
		cout << "Удаление астронавта из базы данных." << endl << endl;
		Astronaut print;
		print.print(Astronaut::astronauts, Astronaut::countAstronauts);
		cout << "Введите номер астронавта, которого вы хотите удалить из базы данных: ";
		int command = 0;
		cin >> command;
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
		cout << "Вы удалили одного астронавта из базы данных." << endl;
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
		cout << "Сортировка базы данных сотрудников по возрастанию возраста:" << endl << endl;
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
		cout << "Сортировка базы данных сотрудников по убыванию возраста:" << endl << endl;
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
		cout << "Сортировка базы данных астронавтов по возрастанию возраста:" << endl << endl;
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
		cout << "Сортировка базы данных астронавтов по убыванию возраста:" << endl << endl;
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
	void filtrUpEmployee()
	{

	}
	void filtrDownEmployee()
	{

	}
	void filtrUpAstronauts()
	{

	}
	void filtrDownAstronauts()
	{

	}
	void addEmployee()
	{
		cout << "Сколько вы хотите добавить сотрудников: ";
		int count = 0;
		cin >> count;
		Employee::countEmployee += count;
		Employee* newEmployee = new Employee[Employee::countEmployee];
		for (int i = 0; i < (Employee::countEmployee - count); i++)
		{
			newEmployee[i] = Employee::employee[i];
		}
		for (int i = 0; i < count; i++)
		{
			cin >> newEmployee[i+Employee::countEmployee-count];
		}
		delete[] Employee::employee;
		Employee::employee = newEmployee;
	}
	void addAstronauts()
	{
		cout << "Сколько вы хотите добавить астронавтов: ";
		int count = 0;
		cin >> count;
		Astronaut::countAstronauts += count;
		Astronaut* newAstronauts = new Astronaut[Astronaut::countAstronauts];
		for (int i = 0; i < (Astronaut::countAstronauts - count); i++)
		{
			newAstronauts[i] = Astronaut::astronauts[i];
		}
		for (int i = 0; i < count; i++)
		{
			cin >> newAstronauts[i + Astronaut::countAstronauts - count];
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