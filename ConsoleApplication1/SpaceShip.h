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
		//virtual void print(SpaceShip* spaceShips, int countSpaceShips) = 0;
		friend std::ostream& operator<<(std::ostream& out, const SpaceShip& spaceShip);
		friend std::istream& operator>>(std::istream& in, SpaceShip& spaceShip);
	};
}
