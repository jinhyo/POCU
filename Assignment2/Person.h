#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		~Person();

		const char* GetName() const;
		unsigned int GetWeight() const;

	private:
		const char* mName;
		int mWeight;
	};
}