#pragma once

#include "SpaceShip.h"

namespace GEV
{
	class HighSpeedSpaceShip:public SpaceShip
	{
	private:

	public:
		static HighSpeedSpaceShip* highSpeedSpaceShips;
		static int countHighSpeedSpaceShips;
		void print(SpaceShip* spaceShips, int countSpaceShips) override;
	};
}