#include <iostream>
#include <cmath>

#include "TimeSheet.h"

using namespace std;

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		:mMaxEntries(maxEntries)
		, mIndex(0)
	{
		mTime = new int[mMaxEntries]();
		mLen = strlen(name) + 1;
		mName = new char[mLen];
		strcpy_s(mName, mLen, name);
	}

	TimeSheet::TimeSheet(const TimeSheet& rhs)
	{
		mLen = rhs.mLen;
		mName = new char[mLen];
		strcpy_s(mName, mLen, rhs.mName);
	}

	TimeSheet::~TimeSheet()
	{
		delete mTime;
		delete mName;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours < 1 || timeInHours>10)
		{
			cout << "정확한 시간을 입력하시오" << endl;
		}
		if (mIndex > mMaxEntries)
		{
			cout << "최대 근무 일수를 초과했습니다." << endl;
		}
		mTime[mIndex++] = timeInHours;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index > mMaxEntries - 1)
		{
			cout << "최대 근무 일수를 초과했습니다." << endl;
		}

		if (mTime[index] == 0)
		{
			return -1;
		}

		return mTime[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int total=0;
		for (size_t i = 0; i < mMaxEntries; i++)
		{
			total += mTime[i];
		}
		return total;
	}

	float TimeSheet::GetAverageTime() const
	{
		int wdays=0;
		for (size_t i = 0; i < mMaxEntries; i++)
		{
			if (mTime[i] != 0)
			{
				wdays++;
			}
		}

		float average = (float)TimeSheet::GetTotalTime() / wdays;
		return average;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		int wdays = 0;
		float num = 0;
		for (size_t i = 0; i < mMaxEntries; i++)
		{
			if (mTime[i] != 0)
			{
				wdays++;
			}
		}

		float average = (float)TimeSheet::GetTotalTime() / wdays;
		for (size_t i = 0; i < mMaxEntries; i++)
		{
			if (mTime[i] != 0)
			{
				num += pow((mTime[i] - average), 2) / wdays;
			}
		}

		return sqrt(num);
	}

	const std::string& TimeSheet::GetName() const
	{
		string name = mName;
		return name;
	}
}