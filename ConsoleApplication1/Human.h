#pragma once

#include <string>

namespace GEV
{
	enum SpaceSuit
	{
		S1,
		S2
	};
	class Human
	{
	public:
		void setName(std::string name);
		void setSurname(std::string name);
		void setAge(int age);
		virtual void setSpaceSuit() = 0;
		std::string getName();
		std::string getSurname();
		int getAge();
		SpaceSuit getSpaceSuit();
		virtual void print(Human* human, int count) = 0;
		SpaceSuit spaceSuit;
		friend std::ostream& operator<<(std::ostream& out, const Human& human);
		friend std::istream& operator>>(std::istream& in, Human& human);
		friend bool operator>(const Human& human1, const Human& human2);
		friend bool operator<(const Human& human1, const Human& human2);
		void setLogin(std::string login);
		void setPassword(std::string password);
	private:
		std::string name;
		std::string surname;
		int age;
		std::string login;
		std::string password;
	};
}