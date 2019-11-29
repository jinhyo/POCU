#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(Storage<T>&& other);

		Storage<T>& operator=(Storage<T>&& other);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mArray; // 자동으로 nullptr로 초기화 
		unsigned int mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mLength(length)
	{
		mArray = std::make_unique<T[]>(length); // 자동으로 0으로 초기화됨
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		:mLength(length)
	{
		mArray = std::make_unique<T[]>(mLength);
		for (size_t i = 0; i < mLength; i++)
		{
			mArray[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage<T>&& other)
	{
		mLength = other.mLength;
		mArray.swap(other.mArray);
		other.mLength = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other)
	{
		if (this != &other)
		{
			mLength = other.mLength;
			mArray.swap(other.mArray);
			other.mLength = 0;
		}

		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mLength)
		{
			mArray[index] = data;
			return true;
		}

		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
	/*	std::unique_ptr<T[]> temp = std::make_unique<T[]>(mLength);
		temp = std::move(mArray);
		return std::move(temp);*/
		return mArray;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}