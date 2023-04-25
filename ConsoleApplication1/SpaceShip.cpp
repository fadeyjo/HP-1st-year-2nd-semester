#include "SpaceShip.h"

namespace GEV
{
	std::string SpaceShip::getName()
	{
		return this->name;
	}

	double SpaceShip::getWeight()
	{
		return this->weight;
	}

	Condition SpaceShip::getCondition()
	{
		return this->condition;
	}

	std::string SpaceShip::getDate()
	{
		return this->date;
	}

	std::string SpaceShip::getTime()
	{
		return this->time;
	}

	Astronaut SpaceShip::getPilot()
	{
		return this->pilot;
	}
}