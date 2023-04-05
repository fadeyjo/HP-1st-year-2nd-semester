#pragma once

#include "Menu.h"
#include <string>
#include <fstream>
#include "Employee.h"
#include "Astronaut.h"
#include "Human.h"
#include <iostream>

namespace GEV
{
	std::ostream& operator<<(std::ostream& out, const Human* human);
	std::istream& operator>>(std::istream& in, Human& human);
	bool operator>(const Human& human1, const Human& human2);
	bool operator<(const Human& human1, const Human& human2);
	void exit();
	void logIn();
	void registrationAsAdmin();
	void registrationAsUser();
	void createAdminMenu();
	void createDataBaseEmployee();
	void createDataBaseAstronauts();
	void deleteInDataBaseEmployee();
	void deleteInDataBaseAstronauts();
	void redactDataBaseEmployee();
	void redactDataBaseAstronauts();
	void sortUpEmployee();
	void sortDownEmployee();
	void sortUpAstronauts();
	void sortDownAstronauts();
	void filtrEmployeeSpaceSuitS1();
	void filtrAstronautsSpaceSuitS1();
	void filtrEmployeeSpaceSuitS2();
	void filtrAstronautsSpaceSuitS2();
	void filtrEmployeeSpaceSuitS3();
	void filtrAstronautsSpaceSuitS3();
	void filtrEmployeeSpaceSuitS4();
	void filtrAstronautsSpaceSuitS4();
	void addEmployee();
	void addAstronauts();
	void printEmployee();
	void printAstronauts();
	std::string getName(Human& human);
	std::string getSurname(Human& human);
	int getAge(Human& human);
	std::string getLogin(Human& human);
	std::string getPassword(Human& human);
	SpaceSuit getSpaceSuit(Human& human);
}