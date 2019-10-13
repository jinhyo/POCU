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

	Vehicle::~Vehicle()
	{
		// if문 없을 때는 아래의 오류가 발생함
		if (mPassengers != NULL)
		{
			// 이걸 하면 Boatplane&& other 해제에서 왜 오류가 나는 이유를 모르겠음
			for (size_t i = 0; i < mPassengerCount; i++)
			{
				delete mPassengers[i];
			}

			// delete[] & mPassengers; ???
			delete[] mPassengers;
		}
		
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengerCount >= mMaxPassengerNumber)
		{
			return false;
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
		for (size_t j = i; j < mPassengerCount - 1; j++)
		{
			mPassengers[j] = mPassengers[j + 1];
		}
		mPassengerCount--;

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