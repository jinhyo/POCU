#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int total = 0;
		if (v.size() < 1)
		{
			return 0;
		}

		for (size_t i = 0; i < v.size(); i++)
		{
			total += v[i];
		}
		return total;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() < 1)
		{
			// UINT_MAX
			return static_cast<unsigned int>(-1);
		}

		int min = v[0];
		for (size_t i = 1; i < v.size(); i++)
		{
			if (v[i] < min)
			{
				min = v[i];
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() < 1)
		{
			// 수정 필요
			return INT_MIN;
		}

		int max = v[0];
		for (size_t i = 1; i < v.size(); i++)
		{
			if (v[i] > max)
			{
				max = v[i];
			}
		}

		return max;
	}
	

	float Average(const std::vector<int>& v)
	{
		if (v.size() < 1)
		{
			return 0;
		}

		float total = 0.0f;
		float average = 0.0f;
		for (size_t i = 0; i < v.size(); i++)
		{
			total += v[i];
		}
		average = total / v.size();

		return average;
	}

	/*int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() < 1)
		{
			return 0;
		}

		int majorityCount = 0;
		int majority = 0;
		for (size_t i = 0; i < v.size() - 1; i++)
		{
			int count = 0;
			for (size_t j = i + 1; j < v.size(); j++)
			{
				if (v[i] == v[j])
				{
					++count;
				}
			}
			if (majorityCount < count)
			{
				majorityCount = count;
				majority = v[i];
			}
		}
		return majority;
	}*/

	void SortDescending(std::vector<int>& v)
	{
		for (size_t i = 0; i < v.size() - 1; i++)
		{
			for (size_t j = i + 1; j < v.size(); j++)
			{
				int temp;
				if (v[i] - v[j] < 0)
				{
					temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
		}
	}

}