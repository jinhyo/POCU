#pragma once

#include "FixedVector.h"

template <size_t N>
class FixedVector<bool, N>
{
public:
	FixedVector<bool, N>();

	bool Add(bool);
	bool Remove(bool);
	const bool Get(unsigned index);
	int GetIndex(bool);
	size_t GetSize();
	size_t GetCapacity();

	const bool operator[](unsigned index);

private:
	unsigned mSize;
	bool mArray[N];

};

template <size_t N>
FixedVector<bool, N>::FixedVector()
	: mSize(0)
{
}

template <size_t N>
bool FixedVector<bool, N>::Add(bool data)
{
	if (mSize >= N)
	{
		return false;
	}
	mArray[mSize++] = data;

	return true;
}

template <size_t N>
bool FixedVector<bool, N>::Remove(bool data)
{
	unsigned i = 0;
	for (; i < mSize; i++)
	{
		if (mArray[i] == data)
		{
			for (; i < mSize - 1; i++)
			{
				mArray[i] = mArray[i + 1];
			}
			mSize--;

			return true;
		}
	}

	return false;
}

template <size_t N>
const bool FixedVector<bool, N>::Get(unsigned index)
{
	return mArray[index];
}

template <size_t N>
int FixedVector<bool, N>::GetIndex(bool data)
{
	for (size_t i = 0; i < mSize; i++)
	{
		if (mArray[i] == data)
		{
			return i;
		}
	}

	return -1;
}

template <size_t N>
size_t FixedVector<bool, N>::GetSize()
{
	return mSize;
}

template <size_t N>
size_t FixedVector<bool, N>::GetCapacity()
{
	return N;
}

template <size_t N>
const bool FixedVector<bool, N>::operator[](unsigned index)
{
	return mArray[index];
}
