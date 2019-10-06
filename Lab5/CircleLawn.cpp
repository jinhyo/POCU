#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int length)
		: Lawn()
	{
		mRadius = length;
	}

	inline unsigned int CircleLawn::GetArea() const
	{
		double tmp = PI * mRadius * mRadius;
		return static_cast<unsigned int>(tmp + 0.5);

	}
}