#include "CargoSpaceShip.h"

namespace GEV
{
	void CargoSpaceShip::print(SpaceShip* spaceShips, int countSpaceShips)
	{
		std::cout << "���� ������ ��������:" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|        #        |        ��� �������        |        ���������        |        ����        |        �����        |        ��� ������        |        ������� ������        |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < countSpaceShips; i++)
		{
			std::string condition;
			switch (spaceShips[i].getCondition())
			{
			case readyToLunch:
			{
				condition = "����� � ������";
				break;
			}
			case broken:
			{
				condition = "������";
				break;
			}
			case launhPlanned:
			{
				condition = "����� ������������";
				break;
			}
			default:
			{
				condition = "� �������";
				break;
			}
			}
			std::cout << "|" << std::setw(9) << i + 1 << std::setw(9) << "|" << std::setw(10) << spaceShips[i].getName() << std::setw(10) << "|" << std::setw(12) << condition << std::setw(12) << "|" << std::setw(12) << spaceShips[i].getDate() << std::setw(12) << "|" << std::setw(13) << spaceShips[i].getTime() << std::setw(12) << "|" << std::setw(13) << spaceShips[i].getPilot().getName() << std::setw(13) << spaceShips[i].getPilot().getSurname() << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
		}
		system("pause");
	}
}