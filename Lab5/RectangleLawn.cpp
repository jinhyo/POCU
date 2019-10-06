#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: SquareLawn(width)
	{
		mHeight = height;
	}

}