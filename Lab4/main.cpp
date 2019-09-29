#include <cassert>
#include <iostream>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;
using namespace std;

int main()
{
	cout << "- PolyLine::TryGetMinBoundingRectangle() -" << endl;
	PolyLine pl;
	pl.AddPoint(1.4f, 2.8f);
	pl.AddPoint(3.7f, 2.5f);
	pl.AddPoint(5.5f, 5.5f);
	pl.AddPoint(-2.9f, 4.1f);
	pl.AddPoint(4.3f, -1.0f);
	pl.AddPoint(6.2f, 4.4f);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	assert(pl.TryGetMinBoundingRectangle(&minP, &maxP) == true); // min: [-2.9f, -1.0f], max: [6.2f, 5.5f]
	cout << "min: " << minP.GetX() << ", " << minP.GetY() << endl;
	assert(minP.GetX() == -2.9f && minP.GetY() == -1.0f);
	cout << "max: " << maxP.GetX() << ", " << maxP.GetY() << endl;
	assert(maxP.GetX() == 6.2f && maxP.GetY() == 5.5f);

	cout << "- PolyLine::TryGetMinBoundingRectangle() - END -" << endl;

	system("pause");
	return 0;
}

