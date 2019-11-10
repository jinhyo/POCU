#pragma once

#include <limits>
#include <queue>
#include <stack>
#include <type_traits>

namespace assignment3
{
	
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack() = delete;
		QueueStack(unsigned maxStackSize);

		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		T GetSum();

		void Enqueue(T number);
		double GetAverage();
		unsigned GetCount();
		unsigned GetStackCount();

	private:
		queue<stack<T>> mQ1;
		queue<stack<T>> mQ2;
		queue<stack<T>> mMaxQ;
		queue<stack<T>> mMinQ;
		T mSum;
		unsigned mCount;
		unsigned mMaxStackSize;
		double mBeforeVariance;

	};
	

	template <typename T>
	assignment3::QueueStack<T>::QueueStack(unsigned maxStackSize)
		: mCount(0)
		, mSum(0)
		, mMaxStackSize(maxStackSize)
	{
	}

	template <typename T>
	T assignment3::QueueStack<T>::Peek();

	template <typename T>
	T assignment3::QueueStack<T>::Dequeue();

	template <typename T>
	T assignment3::QueueStack<T>::GetMax()
	{
		if (mQ1.size() == 0)
		{
			if (is_same<T, char>::value)
			{
				return CHAR_MIN;
			}

			else if (is_same<T, short>::value)
			{
				return SHRT_MIN;
			}

			else if (is_same<T, int>::value)
			{
				return  INT_MIN;
			}

			else if (is_same<T, long>::value)
			{
				return LONG_MIN;
			}

			else if (is_same<T, long long>::value)
			{
				return LLONG_MIN;
			}

			else if (is_same<T, unsigned char>::value)
			{
				return 0;
			}

			else if (is_same<T, unsigned short>::value)
			{
				return 0;
			}

			else if (is_same<T, unsigned int>::value)
			{
				return 0;
			}

			else if (is_same<T, unsigned long>::value)
			{
				mMaxQ.push(0);
			}

			else if (is_same<T, unsigned long long>::value)
			{
				return 0;
			}

			else if (is_same<T, unsigned long long>::value)
			{
				return 0;
			}

			else if (is_same<T, float>::value)
			{
				return FLT_MIN;
			}

			else if (is_same<T, double>::value)
			{
				return DBL_MIN;
			}

			else if (is_same<T, long double>::value)
			{
				return LDBL_MIN;
			}
		}
		
		else

	}

	template <typename T>
	T assignment3::QueueStack<T>::GetMin()
	{
		if (mQ1.size() == 0)
		{
			if (is_same<T, char>::value)
			{
				return CHAR_MAX;
			}

			else if (is_same<T, short>::value)
			{
				return SHRT_MAX;
			}

			else if (is_same<T, int>::value)
			{
				return INT_MAX;
			}

			else if (is_same<T, long>::value)
			{
				return LONG_MAX;
			}

			else if (is_same<T, long long>::value)
			{
				return LLONG_MAX;
			}

			else if (is_same<T, unsigned char>::value)
			{
				return UCHAR_MAX;
			}

			else if (is_same<T, unsigned short>::value)
			{
				return USHRT_MAX;
			}

			else if (is_same<T, unsigned int>::value)
			{
				return UINT_MAX;
			}

			else if (is_same<T, unsigned long>::value)
			{
				return ULONG_MAX;
			}

			else if (is_same<T, unsigned long long>::value)
			{
				return ULLONG_MAX;
			}

			else if (is_same<T, unsigned long long>::value)
			{
				return ULLONG_MAX;
			}

			else if (is_same<T, float>::value)
			{
				return FLT_MAX;
			}

			else if (is_same<T, double>::value)
			{
				return DBL_MAX;
			}

			else if (is_same<T, long double>::value)
			{
				return LDBL_MAX;
			}
		}

		else

	}

	template <typename T>
	T assignment3::QueueStack<T>::GetSum()
	{
		return mSum;
	}

	template <typename T>
	void assignment3::QueueStack<T>::Enqueue(T number)
	{

	}

	template <typename T>
	double assignment3::QueueStack<T>::GetAverage()
	{

	}

	template <typename T>
	unsigned assignment3::QueueStack<T>::GetCount()
	{
		return mCount;
	}

	template <typename T>
	unsigned assignment3::QueueStack<T>::GetStackCount()
	{
		return mQ1.size();
	}

}
