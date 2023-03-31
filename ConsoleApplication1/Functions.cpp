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
		out << "���: " << human.name << endl << "�������: " << human.surname << endl << "�������: " << human.age << endl << "��������: " << spaceSuit << endl << endl;
		return out;
	}
	std::istream& operator>>(std::istream& in, Human& human)
	{
		cout << "���: ";
		in >> human.name;
		cout << "�������: ";
		in >> human.surname;
		cout << "�������: ";
		in >> human.age;
		cout << "�����: ";
		in >> human.login;
		cout << "������: ";
		in >> human.password;
		return in;
	}
	void exit()
	{
		Menu::exit = true;
	}

	void logIn()
	{
		cout << "�����������." << endl;
		cout << "�����: ";
		string login;
		cin >> login;
		cout << "������: ";
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
			cout << "��� ������ � ����������. ��������� �������!" << endl;
			system("pause");
			system("cls");
			Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
		}
		else
		{
			if (Menu::visitor == admin)
			{
				cout << "�� ����� ��� �����." << endl;
				system("pause");
				system("cls");
				createAdminMenu();
				Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
			}
			else
			{
				cout << "�� ����� ��� ������������." << endl;
				system("pause");
				system("cls");

			}
		}
	}

	void registrationAsAdmin()
	{
		cout << "����������� ������." << endl;
		cout << "�����: ";
		string login;
		cin >> login;
		cout << "������: ";
		string password;
		cin >> password;
		std::ofstream fout("AdminTools.txt", std::ofstream::app);
		fout << '\n' << '\n' << login << '\n' << password;
		fout.close();
		system("cls");
		cout << "�� ���������������� ������." << endl;
		system("pause");
		system("cls");
		Menu::runMenu(Menu::lastMenu, Menu::countLastMenuItems);
	}

	void registrationAsUser()
	{
		cout << "����������� ������������." << endl;
		cout << "�����: ";
		string login;
		cin >> login;
		cout << "������: ";
		string password;
		cin >> password;
		std::ofstream fout("UserTools.txt", std::ofstream::app);
		fout << '\n' << '\n' << login << '\n' << password;
		fout.close();
		system("cls");
		cout << "�� ���������������� ������������." << endl;
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
		createDataBaseMenu[0] = new Menu(createDataBaseEmployee, new char[255] {"[1]    �������� ���� ������ �����������."});
		createDataBaseMenu[1] = new Menu(createDataBaseAstronauts, new char[255] {"[2]    �������� ���� ������ �����������."});
		adminMenu[0] = new Menu(createDataBaseMenu, new char[255] {"[1]    �������� ��� ������."}, countCreateDataBaseMenuItems);

		int countDeleteMenuItems = 2;
		Menu** deleteMenu = new Menu * [countDeleteMenuItems];
		deleteMenu[0] = new Menu(deleteInDataBaseEmployee, new char[255] {"[1]    �������� �� ���� ������ �����������."});
		deleteMenu[1] = new Menu(deleteInDataBaseAstronauts, new char[255] {"[2]    �������� �� ���� ������ �����������."});
		adminMenu[1] = new Menu(deleteMenu, new char[255] {"[2]    �������� �� ��� ������."}, countDeleteMenuItems);

		int countRedactMenuItems = 2;
		Menu** redactMenu = new Menu * [countRedactMenuItems];
		redactMenu[0] = new Menu(redactDataBaseEmployee, new char[255] {"[1]    �������������� ���� ������ �����������."});
		redactMenu[1] = new Menu(redactDataBaseAstronauts, new char[255] {"[2]    �������������� ���� ������ �����������."});
		adminMenu[2] = new Menu(redactMenu, new char[255] {"[3]    �������������� ��� ������."}, countRedactMenuItems);

		int countSortMenuItems = 2;
		Menu** sortMenu = new Menu * [countSortMenuItems];
		int countSortEmployeeMenuItems = 2;
		Menu** sortEmployeeMenu = new Menu * [countSortEmployeeMenuItems];
		sortEmployeeMenu[0] = new Menu(sortUpEmployee, new char[255] {"[1]    ���������� �� �����������."});
		sortEmployeeMenu[1] = new Menu(sortDownEmployee, new char[255] {"[2]    ���������� �� ��������."});
		sortMenu[0] = new Menu(sortEmployeeMenu, new char[255] {"[1]    ���������� ���� ������ �����������."}, countSortEmployeeMenuItems);
		int countSortAstronautsMenuItems = 2;
		Menu** sortAstronautsMenu = new Menu * [countSortAstronautsMenuItems];
		sortAstronautsMenu[0] = new Menu(sortUpAstronauts, new char[255] {"[1]    ���������� �� �����������."});
		sortAstronautsMenu[1] = new Menu(sortDownAstronauts, new char[255] {"[2]    ���������� �� ��������."});
		sortMenu[1] = new Menu(sortAstronautsMenu, new char[255] {"[2]    ���������� ���� ������ �����������."}, countSortAstronautsMenuItems);
		adminMenu[3] = new Menu(sortMenu, new char[255] {"[4]    ���������� ��� ������."}, countSortMenuItems);

		int countFiltrMenuItems = 2;
		Menu** filtrMenu = new Menu * [countFiltrMenuItems];
		int countFiltrEmployeeMenuItems = 2;
		Menu** filtrEmployeeMenu = new Menu * [countFiltrEmployeeMenuItems];
		filtrEmployeeMenu[0] = new Menu(filtrUpEmployee, new char[255] {"[1]    ��������� �� ������ ������� ��������."});
		filtrEmployeeMenu[1] = new Menu(filtrDownEmployee, new char[255] {"[2]    ���������� �� ������� ������� ��������."});
		filtrMenu[0] = new Menu(sortEmployeeMenu, new char[255] {"[1]    ���������� ���� ������ �����������."}, countFiltrEmployeeMenuItems);
		int countFiltrAstronautsMenuItems = 2;
		Menu** filtrAstronautsMenu = new Menu * [countFiltrAstronautsMenuItems];
		filtrAstronautsMenu[0] = new Menu(filtrUpAstronauts, new char[255] {"[1]    ��������� �� ������ ������� ��������."});
		filtrAstronautsMenu[1] = new Menu(filtrDownAstronauts, new char[255] {"[2]    ���������� �� ������� ������� ��������."});
		filtrMenu[1] = new Menu(filtrAstronautsMenu, new char[255] {"[2]    ���������� ���� ������ �����������."}, countFiltrAstronautsMenuItems);
		adminMenu[4] = new Menu(filtrMenu, new char[255] {"[5]    ���������� ��� ������."}, countFiltrMenuItems);

		int countAddMenuItems = 2;
		Menu** addMenu = new Menu * [countAddMenuItems];
		addMenu[0] = new Menu(addEmployee, new char[255] {"[1]    ���������� � ���� ������ �����������."});
		addMenu[1] = new Menu(addAstronauts, new char[255] {"[2]    ���������� � ���� ������ �����������."});
		adminMenu[5] = new Menu(addMenu, new char[255] {"[6]    ���������� � ���� ������."}, countAddMenuItems);

		adminMenu[6] = new Menu(exit, new char[255] {"[7]    �����."});

		int countPrintMenuItems = 2;
		Menu** printMenu = new Menu * [countPrintMenuItems];
		printMenu[0] = new Menu(printEmployee, new char[255] {"[1]    ����� ���� ������ �����������."});
		printMenu[1] = new Menu(printAstronauts, new char[255] {"[2]    ����� ���� ������ �����������."});
		adminMenu[7] = new Menu(printMenu, new char[255] {"[8]    ����� ��� ������."}, countPrintMenuItems);

		Menu::countLastMenuItems = countAdminMenuItems;
		Menu::lastMenu = adminMenu;
	}

	void createDataBaseEmployee()
	{
		cout << "������ ����������� �� ������ ������: ";
		cin >> Employee::countEmployee;
		Employee::employee = new Employee[Employee::countEmployee];
		for (int i = 0; i < Employee::countEmployee; i++)
		{
			cout << "���: ";
			string name;
			cin >> name;
			Employee::employee[i].setName(name);

			cout << "�������: ";
			string surname;
			cin >> surname;
			Employee::employee[i].setSurname(surname);

			cout << "�������: ";
			int age;
			cin >> age;
			Employee::employee[i].setAge(age);

			Employee::employee[i].setSpaceSuit();

			cout << "�����: ";
			string login;
			cin >> login;
			Employee::employee[i].setLogin(login);

			cout << "������: ";
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
		cout << "������ ����������� �� ������ ������: ";
		cin >> Astronaut::countAstronauts;
		Astronaut::astronauts = new Astronaut[Astronaut::countAstronauts];
		for (int i = 0; i < Astronaut::countAstronauts; i++)
		{
			cout << "���: ";
			string name;
			cin >> name;
			Astronaut::astronauts[i].setName(name);

			cout << "�������: ";
			string surname;
			cin >> surname;
			Astronaut::astronauts[i].setSurname(surname);

			cout << "�������: ";
			int age;
			cin >> age;
			Astronaut::astronauts[i].setAge(age);

			Astronaut::astronauts[i].setSpaceSuit();

			cout << "�����: ";
			string login;
			cin >> login;
			Astronaut::astronauts[i].setLogin(login);

			cout << "������: ";
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
		cout << "�������� ���������� �� ���� ������." << endl << endl;
		Employee print;
		print.print(Employee::employee, Employee::countEmployee);
		cout << "������� ����� ����������, �������� �� ������ ������� �� ���� ������: ";
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
		cout << "�� ������� ������ ���������� �� ���� ������." << endl;
		system("pause");
	}

	void deleteInDataBaseAstronauts()
	{
		cout << "�������� ���������� �� ���� ������." << endl << endl;
		Astronaut print;
		print.print(Astronaut::astronauts, Astronaut::countAstronauts);
		cout << "������� ����� ����������, �������� �� ������ ������� �� ���� ������: ";
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
		cout << "�� ������� ������ ���������� �� ���� ������." << endl;
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
		cout << "���������� ���� ������ ����������� �� ����������� ��������:" << endl << endl;
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
		cout << "���������� ���� ������ ����������� �� �������� ��������:" << endl << endl;
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
		cout << "���������� ���� ������ ����������� �� ����������� ��������:" << endl << endl;
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
		cout << "���������� ���� ������ ����������� �� �������� ��������:" << endl << endl;
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
		cout << "������� �� ������ �������� �����������: ";
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
		cout << "������� �� ������ �������� �����������: ";
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