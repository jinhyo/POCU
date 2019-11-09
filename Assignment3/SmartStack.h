#pragma once

#include <limits>
#include <stack>
#include <type_traits>

using namespace std;

namespace assignment3
{

	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();
		// Push 단계에서 Max, Min, Sum값 저장 필요

		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		T GetSum();

		double GetAverage();
		unsigned GetCount();
		void Push(T number);
		double GetVariance();
		double GetStandardDeviation();

	private:
		stack<T> mMaxStack;
		stack<T> mMinStack;
		stack<T> st1;
		stack<T> st2;
		T mSum;
		double mBeforeVariance;
	};

}

// 완료
template <typename T>
assignment3::SmartStack<T>::SmartStack()
	: mBeforeVariance(0)
	, mSum(0)
{
	// 간단한 방법은 없나?
	if (is_same<T, char>::value)
	{
		mMaxStack.push(CHAR_MIN);
		mMinStack.push(CHAR_MAX);
	}

	else if (is_same<T, short>::value)
	{
		mMaxStack.push(SHRT_MIN);
		mMinStack.push(SHRT_MAX);
	}

	else if (is_same<T, int>::value)
	{
		mMaxStack.push(INT_MIN);
		mMinStack.push(INT_MAX);
	}

	else if (is_same<T, long>::value)
	{
		mMaxStack.push(LONG_MIN);
		mMinStack.push(LONG_MAX);
	}

	else if (is_same<T, long long>::value)
	{
		mMaxStack.push(LLONG_MIN);
		mMinStack.push(LLONG_MAX);
	}

	else if (is_same<T, unsigned char>::value)
	{
		mMaxStack.push(0);
		mMinStack.push(UCHAR_MAX);
	}

	else if (is_same<T, unsigned short>::value)
	{
		mMaxStack.push(0);
		mMinStack.push(USHRT_MAX);
	}

	else if (is_same<T, unsigned int>::value)
	{
		mMaxStack.push(0);
		mMinStack.push(UINT_MAX);
	}

	else if (is_same<T, unsigned long>::value)
	{
		mMaxStack.push(0);
		mMinStack.push(ULONG_MAX);
	}

	else if (is_same<T, unsigned long long>::value)
	{
		mMaxStack.push(0);
		mMinStack.push(ULLONG_MAX);
	}

	else if (is_same<T, unsigned long long>::value)
	{
		mMaxStack.push(0);
		mMinStack.push(ULLONG_MAX);
	}

	else if (is_same<T, float>::value)
	{
		mMaxStack.push(FLT_MIN);
		mMinStack.push(FLT_MAX);
	}

	else if (is_same<T, double>::value)
	{
		mMaxStack.push(DBL_MIN);
		mMinStack.push(DBL_MAX);
	}

	else if (is_same<T, long double>::value)
	{
		mMaxStack.push(LDBL_MIN);
		mMinStack.push(LDBL_MAX);
	}
}

// 완료
template <typename T>
void assignment3::SmartStack<T>::Push(T number)
{
	st1.push(number);

	if (mMaxStack.top() < number)
	{
		mMaxStack.push(number);
	}

	else
	{
		mMaxStack.push(mMaxStack.top());
	}

	if (mMinStack.top() > number)
	{
		mMinStack.push(number);
	}

	else
	{
		mMinStack.push(mMinStack.top());
	}

	mSum += number;
	double average = static_cast<double>(mSum) / st1.size();
	mBeforeVariance = 0;

	unsigned temp = st1.size();
	for (size_t i = 0; i < temp; i++)
	{
		mBeforeVariance += (st1.top() - average) * (st1.top() - average);
		st2.push(st1.top());
		st1.pop();
	}

	temp = st2.size();
	for (size_t i = 0; i < temp; i++)
	{
		st1.push(st2.top());
		st2.pop();
	}
}

// 완료
template <typename T>
T assignment3::SmartStack<T>::Pop()
{
	mMaxStack.pop();
	mMinStack.pop();
	T popReturn = st1.top();
	mSum -= st1.top();
	st1.pop();

	double average = static_cast<double>(mSum) / st1.size();
	mBeforeVariance = 0;

	unsigned temp = st1.size();
	for (size_t i = 0; i < temp; i++)
	{
		mBeforeVariance += (st1.top() - average) * (st1.top() - average);
		st2.push(st1.top());
		st1.pop();
	}

	temp = st2.size();
	for (size_t i = 0; i < temp; i++)
	{
		st1.push(st2.top());
		st2.pop();
	}

	return popReturn;
}

// 완료
template <typename T>
T assignment3::SmartStack<T>::Peek()
{
	return st1.top();
}

// 완료
template <typename T>
T assignment3::SmartStack<T>::GetMax()
{
	return mMaxStack.top();
}

// 완료
template <typename T>
T assignment3::SmartStack<T>::GetMin()
{
	return mMinStack.top();
}

// 완료
template <typename T>
T assignment3::SmartStack<T>::GetSum()
{
	return mSum;
}

// 완료
template <typename T>
double assignment3::SmartStack<T>::GetAverage()
{
	double average = static_cast<double>(mSum) / st1.size();
	average = static_cast<int>((average + 0.0005) * 1000);
	return static_cast<double>(average) / 1000;
}

// 완료
template <typename T>
unsigned assignment3::SmartStack<T>::GetCount()
{
	return st1.size();
}

// 완료
template <typename T>
double assignment3::SmartStack<T>::GetVariance()
{
	double variance = mBeforeVariance / st1.size();
	variance = static_cast<int>((variance + 0.0005) * 1000);

	return static_cast<double>(variance) / 1000;
}

// 완료
template <typename T>
double assignment3::SmartStack<T>::GetStandardDeviation()
{
	double sd = sqrt(mBeforeVariance / st1.size());
	sd = static_cast<int>((sd + 0.0005) * 1000);
	
	return static_cast<double>(sd) / 1000;
}