#include "Container.h"

namespace GEV
{
	void Container::createRecords()
	{
		std::cout << "—колько записей вы хотите сделать: ";
		std::cin >> this->size;
		this->records = new std::string[this->size];
		for (int i = 0; i < this->size; i++)
		{
			std::cout << "¬ведите " << i + 1 << " запись:" << std::endl;
			char* record = new char[256] {};
			std::cin.ignore(1, '\n');
			std::cin.getline(record, 256, '\n');
			this->records[i] = record;
			std::cout << std::endl << std::endl;
		}
	}

	IteratorString Container::begin()
	{
		return IteratorString(this->records);
	}

	IteratorString Container::end()
	{
		return IteratorString(this->records + this->size);
	}
}