#pragma once

namespace GEV
{
	template<typename T>
	class SearchMinMax
	{
	private:
		T* people;
		int countPeople;
	public:
		SearchMinMax(T* people, int countPeople)
		{
			this->people = people;
			this->countPeople = countPeople;
		}

		T maxWeigth()
		{
			T max = this->people[0];
			for (int i = 1; i < this->countPeople; i++)
			{
				if (this->people[i] > max)
				{
					max = this->people[i];
				}
			}
			return max;
		}

		T minWeigth()
		{
			T min = this->people[0];
			for (int i = 1; i < this->countPeople; i++)
			{
				if (this->people[i] < min)
				{
					min = this->people[i];
				}
			}
			return min;
		}
	};
}