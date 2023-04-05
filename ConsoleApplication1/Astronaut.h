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
		static Astronaut* astronauts;
		static int countAstronauts;
		void print(Human* human, int count) override;
	private:

	};
}