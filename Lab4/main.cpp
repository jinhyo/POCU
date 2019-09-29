#include <cassert>
#include <iostream>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;

int main()
{
	PolyLine pl1;
	pl1.AddPoint(1.4f, 2.7f);
	pl1.AddPoint(3.5f, 2.1f);
	pl1.AddPoint(5.5f, 5.9f);
	pl1.AddPoint(-2.2f, 4.0f);
	pl1.AddPoint(4.6f, -1.3f);
	pl1.AddPoint(6.0f, 4.5f);

	bool bRemoved = pl1.RemovePoint(4);

	assert(bRemoved);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	pl1.TryGetMinBoundingRectangle(&minP, &maxP);

	assert(minP.GetX() == -2.2f);
	assert(minP.GetY() == 2.1f);
	assert(maxP.GetX() == 6.0f);
	assert(maxP.GetY() == 5.9f);

	return 0;
}

