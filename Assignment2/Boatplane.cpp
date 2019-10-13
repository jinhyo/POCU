#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::Boatplane(Boatplane&& other)
	{
		mMaxPassengerNumber = other.mMaxPassengerNumber;
		mPassengerCount = other.mPassengerCount;
		mPassengers = other.mPassengers;

		// 이게 필요한건지 아닌지 모르겠음
		for (size_t i = 0; i < mPassengerCount; i++)
		{
			other.mPassengers[i] = NULL;
		}

		other.mPassengers = NULL;
	}

	Boatplane& Boatplane::operator=(Boatplane&& other)
	{
		mMaxPassengerNumber = other.mMaxPassengerNumber;
		mPassengerCount = other.mPassengerCount;
		mPassengers = other.mPassengers;

		/*for (size_t i = 0; i < mPassengerCount; i++)
		{
			other.mPassengers[i] = NULL;
		}*/
		other.mPassengers = NULL;

		return *this;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mFlySpeed = 150 * pow(M_E, (-1 * x + 500) / 300.0);
		mFlySpeed = static_cast<unsigned int>(mFlySpeed + 0.5);

		return mFlySpeed;
	}

	unsigned int Boatplane::GetDiveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mDiveSpeed = 800 - 1.7 * x;
		mDiveSpeed = static_cast<unsigned int>(mDiveSpeed + 0.5);

		if (mDiveSpeed > 20)
		{
			return mDiveSpeed;
		}

		return 20;
	}

	// 수정이 필요할지도?
	unsigned int Boatplane::GetMaxSpeed() const
	{
		if (mFlySpeed > mDiveSpeed)
		{
			return mFlySpeed;
		}

		return mDiveSpeed;
	}

	void Boatplane::Move()
	{

	}
}