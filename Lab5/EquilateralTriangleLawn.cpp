#include <cmath>

#include "IFenceable.h"
#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
		: Lawn()
	{
		mLength = length;
	}

	inline unsigned int EquilateralTriangleLawn::GetArea() const
	{
		double tmp = sqrt(3) / 4 * mLength * mLength;
		return static_cast<unsigned int>(tmp + 0.5);

	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		double tmp1 = (mLength * 3) / 0.25;
		unsigned int tmp2 = static_cast<unsigned int>(tmp1);
		if (tmp1 == static_cast<double>(tmp2))
		{
			return tmp2;
		}

		return tmp2 + 1;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR:
			return (mLength * 3) * 6;

		case SPRUCE:
			return (mLength * 3) * 7;

		default:
			break;
		}
	}
}