#pragma once

#include "IFenceable.h"
#include "Lawn.h"

namespace lab5
{
	class SquareLawn : public Lawn, public IFenceable
	{
	public:
		SquareLawn(unsigned int length);

		inline unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	};
}
