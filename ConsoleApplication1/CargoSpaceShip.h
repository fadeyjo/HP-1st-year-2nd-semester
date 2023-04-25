#pragma once

#include "SpaceShip.h"

namespace GEV
{
	class CargoSpaceShip: public SpaceShip
	{
	private:

	public:
		static CargoSpaceShip* cargoSpaceShips;
		static int countCargoSpaceShips;
		void print(SpaceShip* spaceShips, int countSpaceShips) override;
	};
}