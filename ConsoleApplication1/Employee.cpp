#include "Employee.h"

namespace GEV
{
	void Employee::print(Human* human, int count)
	{
		std::cout << "База данных сотрудников:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < countEmployee; i++)
		{
			std::string spaceSuit;
			switch (employee[i].getSpaceSuit())
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
			std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << employee[i].getName() << std::setw(10) << "|" << std::setw(12) << employee[i].getSurname() << std::setw(12) << "|" << std::setw(12) << employee[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		}
		system("pause");
	}
}