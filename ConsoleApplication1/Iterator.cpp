#include "Iterator.h"

namespace GEV
{
	IteratorString::IteratorString(std::string* str)
	{
		this->str = str;
	}

	IteratorString::IteratorString(const IteratorString& iteratorString)
	{
		this->str = iteratorString.str;
	}

	std::string IteratorString::operator*()
	{
		return *(this->str);
	}

	IteratorString& IteratorString::operator++()
	{
		this->str++;
		return *this;
	}

	bool IteratorString::operator!=(const IteratorString& other)
	{
		return str != other.str;
	}
}