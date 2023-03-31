#pragma once

#include "Human.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::setw;

namespace GEV
{
	class Astronaut: public Human
	{
	public:
		static Astronaut* astronauts;
		static int countAstronauts;
		void setSpaceSuit() override;
		void print(Human* human, int count) override;
	private:

	};
}