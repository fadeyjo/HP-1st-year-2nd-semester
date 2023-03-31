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
	class Employee: public Human
	{
	public:
		static int countEmployee;
		static Employee* employee;
		void setSpaceSuit() override;
		void print(Human* human, int count) override;
	private:

	};
}