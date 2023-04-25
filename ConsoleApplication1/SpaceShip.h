#pragma once

#include <string>
#include "Astronaut.h"

namespace GEV
{
	enum Condition
	{
		readyToLunch,
		broken,
		launhPlanned,
		repair
	};
	class SpaceShip
	{
	private:
		std::string name;
		double weight;
		Condition condition;
		std::string date;
		std::string time;
		Astronaut pilot;
	public:
		virtual void print(SpaceShip* spaceShips, int countSpaceShips) = 0;
		friend std::ostream& operator<<(std::ostream& out, const SpaceShip& spaceShip);
		friend std::istream& operator>>(std::istream& in, SpaceShip& spaceShip);
		friend bool operator>(const SpaceShip& spaceShip1, const SpaceShip& spaceShip2);
		friend bool operator<(const SpaceShip& spaceShip1, const SpaceShip& spaceShip2);
		std::string getName();
		double getWeight();
		Condition getCondition();
		std::string getDate();
		std::string getTime();
		Astronaut getPilot();
	};
}
