#include "Employee.h"

namespace GEV
{
	void Employee::setSpaceSuit()
	{
		this->spaceSuit = S1;
	}
	void Employee::print(Human* human, int count)
	{
		cout << "База данных астронавтов:" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|        #        |        Имя        |        Фамилия        |        Возраст        |        Скафандр        |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < countEmployee; i++)
		{
			std::string spaceSuit;
			if (employee[i].getSpaceSuit() == S1)
			{
				spaceSuit = "S1";
			}
			else
			{
				spaceSuit = "S2";
			}
			cout << "|" << setw(9) << i + 1 << setw(9) << "|" << setw(10) << employee[i].getName() << setw(10) << "|" << setw(12) << employee[i].getSurname() << setw(12) << "|" << setw(12) << employee[i].getAge() << setw(12) << "|" << setw(13) << spaceSuit << setw(12) << "|" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		}
		system("pause");
	}
}