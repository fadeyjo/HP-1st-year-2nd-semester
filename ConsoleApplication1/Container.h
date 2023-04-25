#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "Iterator.h"

namespace GEV
{
	class IteratorString;

	class Container
	{
	private:
		std::string* records;
		int size;
	public:
		void createRecords();
		IteratorString begin();
		IteratorString end();
	};
}