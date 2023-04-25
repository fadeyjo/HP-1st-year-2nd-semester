#pragma once

#include "Human.h"
#include <iostream>
#include <iomanip>
#include <string>


namespace GEV
{
	class Astronaut: public Human
	{
	public:
		void print(Human* human, int count) override;
		static Astronaut* astronauts;
		static int countAstronauts;
	private:

	};
}