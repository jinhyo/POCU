#pragma once

#include <limits>
#include <queue>
#include <type_traits>

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		T GetSum();

		void Enqueue(T number);
		double GetAverage();
		double GetVariance();
		double GetStandardDeviation();
		unsigned GetCount();

	private:
		queue<T> mQ1;
		queue<T> mQ2;
		queue<T> mMaxQ;
		queue<T> mMinQ;
		T mSum;
		double mBeforeVariance;
	};

	template <typename T>
	assignment3::SmartQueue<T>::SmartQueue()
		: mSum(0)
	{
		// 간단한 방법은 없나?
		if (is_same<T, char>::value)
		{
			mMaxQ.push(CHAR_MIN);
			mMinQ.push(CHAR_MAX);
		}

		else if (is_same<T, short>::value)
		{
			mMaxQ.push(SHRT_MIN);
			mMinQ.push(SHRT_MAX);
		}

		else if (is_same<T, int>::value)
		{
			mMaxQ.push(INT_MIN);
			mMinQ.push(INT_MAX);
		}

		else if (is_same<T, long>::value)
		{
			mMaxQ.push(LONG_MIN);
			mMinQ.push(LONG_MAX);
		}

		else if (is_same<T, long long>::value)
		{
			mMaxQ.push(LLONG_MIN);
			mMinQ.push(LLONG_MAX);
		}

		else if (is_same<T, unsigned char>::value)
		{
			mMaxQ.push(0);
			mMinQ.push(UCHAR_MAX);
		}

		else if (is_same<T, unsigned short>::value)
		{
			mMaxQ.push(0);
			mMinQ.push(USHRT_MAX);
		}

		else if (is_same<T, unsigned int>::value)
		{
			mMaxQ.push(0);
			mMinQ.push(UINT_MAX);
		}

		else if (is_same<T, unsigned long>::value)
		{
			mMaxQ.push(0);
			mMinQ.push(ULONG_MAX);
		}

		else if (is_same<T, unsigned long long>::value)
		{
			mMaxQ.push(0);
			mMinQ.push(ULLONG_MAX);
		}

		else if (is_same<T, unsigned long long>::value)
		{
			mMaxQ.push(0);
			mMinQ.push(ULLONG_MAX);
		}

		else if (is_same<T, float>::value)
		{
			mMaxQ.push(FLT_MIN);
			mMinQ.push(FLT_MAX);
		}

		else if (is_same<T, double>::value)
		{
			mMaxQ.push(DBL_MIN);
			mMinQ.push(DBL_MAX);
		}

		else if (is_same<T, long double>::value)
		{
			mMaxQ.push(LDBL_MIN);
			mMinQ.push(LDBL_MAX);
		}
	}

	template <typename T>
	void assignment3::SmartQueue<T>::Enqueue(T number)
	{
		mQ1.push(number);

		if (mMaxQ.back() < number)
		{
			mMaxQ.push(number);
		}

		else
		{
			mMaxQ.push(mMaxQ.back());
		}

		if (mMinQ.back() > number)
		{
			mMinQ.push(number);
		}

		else
		{
			mMinQ.push(mMinQ.back());
		}

		mSum += number;
		double average = static_cast<double>(mSum) / mQ1.size();
		mBeforeVariance = 0;

		unsigned temp = mQ1.size();
		for (size_t i = 0; i < temp; i++)
		{
			mBeforeVariance += (mQ1.front() - average) * (mQ1.front() - average);
			mQ2.push(mQ1.front());
			mQ1.pop();
		}

		temp = mQ2.size();
		for (size_t i = 0; i < temp; i++)
		{
			mQ1.push(mQ2.front());
			mQ2.pop();
		}
	}

	template <typename T>
	T assignment3::SmartQueue<T>::Peek()
	{
		return mQ1.front();
	}

	template <typename T>
	T assignment3::SmartQueue<T>::Dequeue()
	{
		mMaxQ.pop();
		mMinQ.pop();
		T dequeueReturn = mQ1.front();
		mSum -= mQ1.front();
		mQ1.pop();

		double average = static_cast<double>(mSum) / mQ1.size();
		mBeforeVariance = 0;

		unsigned temp = mQ1.size();
		for (size_t i = 0; i < temp; i++)
		{
			mBeforeVariance += (mQ1.front() - average) * (mQ1.front() - average);
			mQ2.push(mQ1.front());
			mQ1.pop();
		}

		temp = mQ2.size();
		for (size_t i = 0; i < temp; i++)
		{
			mQ1.push(mQ2.front());
			mQ2.pop();
		}

		return dequeueReturn;
	}

	template <typename T>
	T assignment3::SmartQueue<T>::GetMax()
	{
		return mMaxQ.back();
	}

	template <typename T>
	T assignment3::SmartQueue<T>::GetMin()
	{
		return mMinQ.back();
	}

	template <typename T>
	T assignment3::SmartQueue<T>::GetSum()
	{
		return mSum;
	}

	template <typename T>
	double assignment3::SmartQueue<T>::GetAverage()
	{
		double average = static_cast<double>(mSum) / mQ1.size();
		average = static_cast<int>((average + 0.0005) * 1000);

		return static_cast<double>(average) / 1000;
	}

	template <typename T>
	double assignment3::SmartQueue<T>::GetVariance()
	{
		double variance = mBeforeVariance / mQ1.size();
		variance = static_cast<int>((variance + 0.0005) * 1000);

		return static_cast<double>(variance) / 1000;
	}

	template <typename T>
	double assignment3::SmartQueue<T>::GetStandardDeviation()
	{
		double sd = sqrt(mBeforeVariance / mQ1.size());
		sd = static_cast<int>((sd + 0.0005) * 1000);

		return static_cast<double>(sd) / 1000;
	}

	template <typename T>
	unsigned assignment3::SmartQueue<T>::GetCount()
	{
		return mQ1.size();
	}
}