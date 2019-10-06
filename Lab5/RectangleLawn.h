#pragma once

#include "IFenceable.h"
#include "SquareLawn.h"

namespace lab5
{
	class RectangleLawn : public SquareLawn
	{
	public:
		RectangleLawn(unsigned int width, unsigned int height);

	};
}
