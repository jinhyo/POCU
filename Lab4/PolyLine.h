#pragma once

#include "Point.h"

namespace lab4
{
	class PolyLine
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		~PolyLine();

		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;

		const PolyLine& operator=(const PolyLine& other);
		const Point* operator[](unsigned int i) const;

	private:
		Point* mContents[10];
		int mIndex = 0;
	};
}