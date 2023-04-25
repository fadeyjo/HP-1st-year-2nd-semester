#pragma once

#include "Container.h"
#include <string>

namespace GEV
{
	class IteratorString: public std::iterator<std::input_iterator_tag, std::string>
	{
		friend class Container;
	private:
		IteratorString(std::string* str);
		std::string* str;
	public:
		IteratorString(const IteratorString& iteratorString);
		std::string operator*();
		IteratorString& operator++();
		bool operator!=(const IteratorString& other);
	};
}