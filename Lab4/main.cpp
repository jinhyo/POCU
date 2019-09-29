#include <cassert>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;

int main()
{
	

	PolyLine pl1;
	

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	pl1.TryGetMinBoundingRectangle(&minP, &maxP);

	assert(minP.GetX() == -2.2f);
	assert(minP.GetY() == 2.1f);
	assert(maxP.GetX() == 6.0f);
	assert(maxP.GetY() == 5.9f);

	return 0;
}