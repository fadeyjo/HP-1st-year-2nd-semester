#pragma once

#include "Menu.h"
#include <string>
#include <fstream>
#include "Employee.h"
#include "Astronaut.h"
#include "Human.h"
#include "SpaceShip.h"
#include <iostream>
#include "CargoSpaceShip.h"
#include "HighSpeedSpaceShip.h"
#include "Container.h"
#include <limits>


namespace GEV
{
	void createDataBaseHighSpeedSpaceShips();
	void createDataBaseCargoSpaceShips();
	std::ostream& operator<<(std::ostream& out, const SpaceShip& spaceShip);
	std::istream& operator>>(std::istream& in, SpaceShip& spaceShip);
	std::ostream& operator<<(std::ostream& out, const Human* human);
	std::istream& operator>>(std::istream& in, Human& human);
	bool operator>(const Human& human1, const Human& human2);
	bool operator<(const Human& human1, const Human& human2);
	void exit();
	void logIn();
	void registrationAsAdmin();
	void registrationAsUser();
	void createAdminMenu();
	void createUserMenu();
	void writeTheAction();
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
	void deleteInDataBaseCargo();
	void deleteInDataBaseHighSpeed();
	void redactDataBaseCargo();
	void redactDataBaseHighSpeed();
	void sortUpCargo();
	void sortDownCargo();
	void sortUpHighSpeed();
	void sortDownHighSpeed();
	bool operator>(const SpaceShip& spaceShip1, const SpaceShip& spaceShip2);
	bool operator<(const SpaceShip& spaceShip1, const SpaceShip& spaceShip2);
	void printHighSpeed();
	void printCargo();
	void filtrCargoReadyToLaunch();
	void filtrCargoBroken();
	void filtrCargoLaunchPlanned();
	void filtrCargoRepair();
	void filtrHighSpeedReadyToLaunch();
	void filtrHighSpeedBroken();
	void filtrHighSpeedLaunchPlanned();
	void filtrHighSpeedRepair();
	void addCargo();
	void addHighSpeed();
	void maxPropertyCargo();

	 template<typename T>
	 T maxWeigth(T* base, int count);

	 void maxPropertyHighSpeed();
}