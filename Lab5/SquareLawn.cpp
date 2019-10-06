#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int length)
		: Lawn()
	{
		mLength = length;
	}


	inline unsigned int SquareLawn::GetArea() const
	{
		return mLength * mLength;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		double tmp1 = (mLength * 4) / 0.25;
		unsigned int tmp2 = static_cast<unsigned int>(tmp1);
		if (tmp1 == static_cast<double>(tmp2))
		{
			return tmp2;
		}

		return tmp2 + 1;
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR:
			return (mLength * 4) * 6;

		case SPRUCE:
			return (mLength * 4) * 7;

		default:
			break;
		}
	}
}