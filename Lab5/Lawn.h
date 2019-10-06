#pragma once

#include "eGrassType.h"

namespace lab5
{
	class Lawn
	{
		friend class CircleLawn;
		friend class EquilateralTriangleLawn;
		friend class RectangleLawn;
		friend class SquareLawn;

	public:
		Lawn();
		Lawn(unsigned int width, unsigned int height);
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

	private:
		const float PI = 3.14;
		unsigned int mWidth = 0;
		unsigned int mHeight = 0;
		unsigned int mLength = 0;
		unsigned int mRadius = 0;
	};
}