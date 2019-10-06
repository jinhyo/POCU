#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::Lawn(unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		switch (grassType)
		{
		case BERMUDA:
			return GetArea() * 8;
			break;

		case BAHIA:
			return GetArea() * 5;
			break;

		case BENTGRASS:
			return GetArea() * 3;
			break;

		case PERENNIAL_RYEGRASS:
		{
			double tmp1 = GetArea() * 2.5;
			return static_cast<unsigned int>(tmp1 + 0.5);
			break;
		}

		case ST_AUGUSTINE:
		{
			double tmp = GetArea() * 4.5;
			return static_cast<unsigned int>(tmp + 0.5);
			break;
		}

		default:
			return 0;
			break;
		}
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double tmp1 = GetArea() / 0.3;
		int tmp2 = static_cast<int>(tmp1);
		if (tmp1 == static_cast<double>(tmp2))
		{
			return tmp2;
		}

		return tmp2 + 1;
	}
}