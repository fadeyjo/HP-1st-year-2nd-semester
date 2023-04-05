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
		static int countEmployee;
		static Employee* employee;
		void print(Human* human, int count) override;
	private:

	};
}