#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
	{
		// mContents���� ��� �ִ� ������ ���� NULL�� �ʱ�ȭ
		memset(mContents, NULL, sizeof(Point*) * 10);
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		for (size_t i = 0; i < 10; i++)
		{
			// Point ������ �Ҵ� ���� ���� ��Ҹ� Ȯ���ϸ� Ż��
			if (mContents[i] == NULL)
			{
				break;
			}

			// ���� ����
			mContents[i] = new Point(other[i]->GetX(), other[i]->GetY());
		}
	}

	const PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		for (size_t i = 0; i < 10; i++)
		{
			// Point ������ �Ҵ� ���� ���� ��Ҹ� Ȯ���ϸ� Ż��
			if (mContents[i] == NULL)
			{
				break;
			}

			// ���� ����
			mContents[i] = new Point(other[i]->GetX(), other[i]->GetY());
		}

		return *this;
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < 10; i++)
		{
			// Point ������ �Ҵ� ���� ���� ��Ҹ� Ȯ���ϸ� Ż��
			if (mContents[i] == NULL)
			{
				break;
			}
			
			delete mContents[i];
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mIndex >= 10)
		{
			return false;
		}

		else
		{
			mContents[mIndex++] = new Point(x, y);
			return true;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mIndex >= 10)
		{
			return false;
		}

		mContents[mIndex++] = const_cast<Point*>(point);

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= 0 && i < 10)
		{
			if (mContents[i] == NULL)
			{
				return false;
			}

			// ���� �� �迭 ������: 
			// �迭�� �߰� �κ��� ������ ��� ������ ��ҵ��� ��ĭ�� �������� �̵�
			delete mContents[i];
			for (size_t index = i; index < 9; index++)
			{
				mContents[index] = mContents[index + 1];
			}
			mContents[9] = NULL;
			mIndex--;

			return true;
		}

		else
		{
			return false;
		}
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		// mContents�� �ִ� Point�� �ΰ� �̸��� ��� false
		// mContents���� ��� �ִ� ������ ���� NULL
		if (mContents[1] == NULL)
		{
			return false;
		}

		float minX = LLONG_MAX;
		float minY = LLONG_MAX;
		float maxX = LLONG_MIN;
		float maxY = LLONG_MIN;

		// �ּ� & �ִ밪 ����
		for (size_t i = 0; i < 10; i++)
		{
			if (mContents[i] == NULL)
			{
				break;
			}

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

		// ���� �ʿ�
		Point* min = new Point(minX, minY);
		Point* max = new Point(maxX, maxY);

		memcpy_s(outMin, sizeof(Point), min, sizeof(Point));
		memcpy_s(outMax, sizeof(Point), max, sizeof(Point*));

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		return mContents[i];
	}
}