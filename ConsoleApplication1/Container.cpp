#include "Container.h"

namespace GEV
{
	void Container::createRecords()
	{
		std::cout << "Сколько записей вы хотите сделать: ";
		//std::cin >> this->size;
		do
		{
			try
			{
				if (!(std::cin >> this->size)) throw 1;
				if (std::cin.peek() != '\n') throw 2;
				if (this->size < 1) throw 3;
			}
			catch (int i)
			{
				if (i == 1) std::cin.clear();
				while (std::cin.get() != '\n');
				std::cerr << "Некорректный ввод. Повторите ввод.\n";
				continue;
			}
			break;
		} while (true);
		this->records = new std::string[this->size];
		for (int i = 0; i < this->size; i++)
		{
			std::cout << "Введите " << i + 1 << " запись:" << std::endl;
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