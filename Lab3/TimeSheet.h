#pragma once

#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& rhs);
		~TimeSheet();
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		char* mName;
		unsigned int mMaxEntries;
		int* mTime;
		int mIndex;
		int mLen;
		// 필요에 따라 private 변수와 메서드를 추가하세요.
	};
}