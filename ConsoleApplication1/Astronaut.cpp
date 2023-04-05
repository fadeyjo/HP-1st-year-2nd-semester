#include "Astronaut.h"

namespace GEV
{
	void Astronaut::print(Human* human, int count)
	{
		std::cout << "База данных астронавтов:" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < countAstronauts; i++)
		{
			std::string spaceSuit;
			if (astronauts[i].getSpaceSuit() == S1)
			{
				spaceSuit = "S1";
			}
			else
			{
				spaceSuit = "S2";
			}
			std::cout << "|" << std::setw(9) << i+1 << std::setw(9) << "|" << std::setw(10) << astronauts[i].getName() << std::setw(10)  << "|" << std::setw(12) << astronauts[i].getSurname() << std::setw(12) << "|" << std::setw(12) << astronauts[i].getAge() << std::setw(12) << "|" << std::setw(13) << spaceSuit << std::setw(12) << "|" << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		}
		system("pause");
	}
}