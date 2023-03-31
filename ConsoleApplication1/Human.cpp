#include "Human.h"

namespace GEV
{
	void Human::setName(std::string name)
	{
		this->name = name;
	}
	void Human::setSurname(std::string surname)
	{
		this->surname = surname;
	}
	void Human::setAge(int age)
	{
		this->age = age;
	}
	std::string Human::getName()
	{
		return this->name;
	}
	std::string Human::getSurname()
	{
		return this->surname;
	}
	int Human::getAge()
	{
		return this->age;
	}
	SpaceSuit Human::getSpaceSuit()
	{
		return this->spaceSuit;
	}
	void Human::setLogin(std::string login)
	{
		this->login = login;
	}
	void Human::setPassword(std::string password)
	{
		this->password = password;
	}
}