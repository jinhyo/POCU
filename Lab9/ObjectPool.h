#pragma once
#include <vector>

using namespace std;

namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool() = default;
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& other) = delete;
		~ObjectPool();

		ObjectPool& operator=(const ObjectPool& other) = delete;

		T* Get();
		void Return(T* instance);
		void SetMaxPoolSize(size_t size);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t mMaxPoolSize;
		size_t mPoolCount;
		vector<T*> mInstancePool;
	};

	template<typename T>
	lab9::ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
		mInstancePool.reserve(mMaxPoolSize);
	}

	template<typename T>
	lab9::ObjectPool<T>::~ObjectPool()
	{
		for (auto itr = mInstancePool.begin(); itr != mInstancePool.end(); itr++)
		{
			delete (*itr);
		}

		mInstancePool.clear();
	}

	template<typename T>
	T* lab9::ObjectPool<T>::Get()
	{
		if (mInstancePool.empty())
		{
			return new T;
		}

		else
		{
			T* resource = mInstancePool.front();
			mInstancePool.erase(mInstancePool.begin());

			return resource;
		}
	}

	template<typename T>
	void lab9::ObjectPool<T>::Return(T* instance)
	{
		if (mInstancePool.size() >= mMaxPoolSize)
		{
			delete instance;
		}

		else
		{
			mInstancePool.push_back(instance);
		}
	}

	template<typename T>
	void lab9::ObjectPool<T>::SetMaxPoolSize(size_t size)
	{
		mMaxPoolSize = size;
	}

	template<typename T>
	size_t lab9::ObjectPool<T>::GetFreeObjectCount()
	{
		return mInstancePool.size();
	}

	template<typename T>
	size_t lab9::ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}
