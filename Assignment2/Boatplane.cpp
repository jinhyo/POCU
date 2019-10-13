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

		for (size_t i = 0; i < mPassengerCount; i++)
		{
			other.mPassengers[i] = NULL;
		}
		other.mPassengers = NULL;

		return *this;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mFlySpeed = 150 * static_cast<double>(pow(M_E, (-1.0 * x + 500) / 300.0));
		mFlySpeed = static_cast<unsigned int>(mFlySpeed + 0.5);

		return static_cast<unsigned int>(mFlySpeed);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mSailSpeed = 800 - 1.7 * x;
		mSailSpeed = static_cast<unsigned int>(mSailSpeed + 0.5);

		if (mSailSpeed > 20)
		{
			return static_cast<unsigned int>(mSailSpeed);
		}

		return 20;
	}

	// 수정이 필요할지도?
	unsigned int Boatplane::GetMaxSpeed() const
	{
		if (GetFlySpeed() > GetSailSpeed())
		{
			return static_cast<unsigned int>(mFlySpeed);
		}

		return static_cast<unsigned int>(mSailSpeed);
	}

	void Boatplane::Move()
	{
		if (mMoveCount < 1)
		{
			mMoveCount++;
			mDistance += GetMaxSpeed();
			return;
		}

		if (mMoveCount == 1)
		{
			mBreakCount++;
		}

		if (mBreakCount == 3)
		{
			mMoveCount = 0;
		}
	}
}