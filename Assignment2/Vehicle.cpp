#include "Vehicle.h"
#include <algorithm>

namespace assignment2
{
	Vehicle::Vehicle()
	{
	}

	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengerNumber(maxPassengersCount)
	{
		mPassengers = new const Person * [mMaxPassengerNumber];
	}

	// 추가 코드
	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengerNumber(other.mMaxPassengerNumber)
		, mPassengerCount(other.mPassengerCount)
	{
		mPassengers = new const Person * [mMaxPassengerNumber];
		for (size_t i = 0; i < mPassengerCount; i++)
		{
			const char* name = other.mPassengers[i]->GetName();
			const unsigned weight = other.mPassengers[i]->GetWeight();
			mPassengers[i] = new Person(name, weight);
		}
	}

	Vehicle::~Vehicle()
	{
		// if문 없을 때는 아래의 오류가 발생함(없어도 정상적으로 작동 해야함)
		/*if (mPassengers != NULL)
		{*/
			// 이걸 하면 Boatplane&& other 해제에서 왜 오류가 나는 이유를 모르겠음
			for (size_t i = 0; i < mPassengerCount; i++)
			{
				delete mPassengers[i];
			}

			// delete[] & mPassengers; ???
			delete[] mPassengers;
		//}
		
	}
	
	// 추가 코드
	Vehicle& Vehicle::operator = (const Vehicle& other)
	{
		if (this == &other)
		{
			return *this;
		}

		for (size_t i = 0; i < mPassengerCount; i++)
		{
			delete mPassengers[i];
		}
		delete mPassengers;

		mMaxPassengerNumber = other.GetMaxPassengersCount();
		mPassengerCount = other.GetPassengersCount();
		mPassengers = new const Person * [mMaxPassengerNumber];

		for (size_t i = 0; i < mMaxPassengerNumber; i++)
		{
			const char* name = other.mPassengers[i]->GetName();
			const unsigned weight = other.mPassengers[i]->GetWeight();
			mPassengers[i] = new Person(name, weight);
		}
		
		return *this;
	}


	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengerCount >= mMaxPassengerNumber)
		{
			return false;
		}
		
		// 추가 코드
		if (person == nullptr)
		{
			return false;
		}

		// 추가 코드
		for (unsigned i = 0; i < mPassengerCount; i++)
		{
			if (mPassengers[i] == person)
			{
				return false;
			}
		}

		mPassengers[mPassengerCount++] = person;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mPassengerCount <= i)
		{
			return false;
		}
		
		delete mPassengers[i];
		mPassengerCount--;

		// i < mPassengerCount - 1 에서 i < mPassengerCount로 수정하고
		// mPassengerCount--를 for문 아래에서 위로 올림
		for (; i < mPassengerCount; i++)
		{
			mPassengers[i] = mPassengers[i + 1];
		}

		// mPassengers[i] = nullptr; // 다른사람의 코드에서는 존재함(왜 필요하지?)

		return true;
	}

	unsigned int Vehicle::GetDistance() const
	{
		return mDistance;
	}


	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengerCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengerNumber;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPassengerCount <= i)
		{
			return NULL;
		}

		return mPassengers[i];
	}

	// 추가 코드(어디에 쓰는걸까?: 다른 개체에 추가하는 함수인듯)
	/*
	void Vehicle::TransferPassengers(Vehicle& dest)
	{
		for (unsigned i = 0; i < mPassengersCount; i++)
		{
			dest.mPassengers[dest.mPassengersCount] = mPassengers[i];
			++dest.mPassengersCount;

			mPassengers[i] = nullptr;
		}

		mPassengersCount = 0;
	}
	*/
	unsigned int Vehicle::GetMaxPassengersWeight() const
	{
		unsigned int totalWeight = 0;
		for (size_t i = 0; i < mPassengerCount; i++)
		{
			totalWeight += mPassengers[i]->GetWeight();
		}

		return totalWeight;
	}

	unsigned int Vehicle::GetMoveCount() const
	{
		return mMoveCount;
	}

}