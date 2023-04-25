#pragma once

#include "Human.h"
#include <iostream>
#include <iomanip>
#include <string>

namespace GEV
{
	class Employee: public Human
	{
	public:
		void print(Human* human, int count) override;
		static int countEmployee;
		static Employee* employee;
	private:

	};
}