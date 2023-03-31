#include "Astronaut.h"

namespace GEV
{
	void Astronaut::setSpaceSuit()
	{
		this->spaceSuit = S2;
	}
	void Astronaut::print(Human* human, int count)
	{
		cout << "База данных астронавтов:" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
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
			cout << "|" << setw(9) << i+1 << setw(9) << "|" << setw(10) << astronauts[i].getName() << setw(10)  << "|" << setw(12) << astronauts[i].getSurname() << setw(12) << "|" << setw(12) << astronauts[i].getAge() << setw(12) << "|" << setw(13) << spaceSuit << setw(12) << "|" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		}
		system("pause");
	}
}