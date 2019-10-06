#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int length)
		: Lawn()
	{
		mWidth = length;
		mHeight = length;
	}

	inline unsigned int SquareLawn::GetArea() const
	{
		return mWidth * mHeight;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		double tmp1 = (mWidth * 2 + mHeight * 2) / 0.25;
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
			return (mWidth * 2 + mHeight * 2) * 6;

		case SPRUCE:
			return (mWidth * 2 + mHeight * 2) * 7;

		default:
			return 0;
			break;
		}
	}
}