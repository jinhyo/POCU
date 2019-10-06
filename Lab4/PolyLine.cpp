#include <cstring>
#include <cmath>
#include <cfloat>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mIndex(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mIndex(other.mIndex)
	{
		for (size_t i = 0; i < mIndex; i++)
		{
			mContents[i] = new Point(other.mContents[i]->GetX(), other.mContents[i]->GetY());
		}
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mIndex; i++)
		{
			delete mContents[i];
		}
	}
	const PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		if (this == &other)
		{
			return *this;
		}

		for (size_t i = 0; i < mIndex; i++)
		{
			delete mContents[i];
		}

		mIndex = other.mIndex;

		for (size_t i = 0; i < mIndex; i++)
		{
			mContents[i] = new Point(other.mContents[i]->GetX(), other.mContents[i]->GetY());
		}

		return *this;
	}


	bool PolyLine::AddPoint(float x, float y)
	{
		if (mIndex >= 10)
		{
			return false;
		}

		else
		{
			mContents[mIndex] = new Point(x, y);
			mIndex++;
			return true;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mIndex >= 10)
		{
			return false;
		}

		if (point == nullptr)
		{
			return false;
		}

		mContents[mIndex++] = point;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mIndex)
		{
			return false;
		}

		delete mContents[i];
		mIndex--;

		for (size_t index = i; index < mIndex; index++)
		{
			mContents[index] = mContents[index + 1];
		}

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mIndex >= 10)
		{
			return false;
		}

		float minX = mContents[0]->GetX();
		float minY = mContents[0]->GetY();
		float maxX = mContents[0]->GetX();
		float maxY = mContents[0]->GetY();

		// 최소 & 최대값 선정
		for (size_t i = 0; i < mIndex; i++)
		{
			if (minX > mContents[i]->GetX())
			{
				minX = mContents[i]->GetX();
			}

			if (minY > mContents[i]->GetY())
			{
				minY = mContents[i]->GetY();
			}

			if (maxX < mContents[i]->GetX())
			{
				maxX = mContents[i]->GetX();
			}

			if (maxY < mContents[i]->GetY())
			{
				maxY = mContents[i]->GetY();
			}
		}
		
		*outMin = Point(minX, minY);
		*outMax = Point(maxX, maxY);

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mIndex)
		{
			return nullptr;
		}

		return mContents[i];
	}
}