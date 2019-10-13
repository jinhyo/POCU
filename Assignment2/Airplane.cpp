#include <cmath>

#include "Airplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		unsigned int bMaxNumber = GetMaxPassengersCount() + boat.GetMaxPassengersCount();
		Boatplane bp(bMaxNumber);
		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));
			mPassengers[i] = NULL;
		}

		for (size_t i = 0; i < boat.GetPassengersCount(); i++)
		{
			bp.AddPassenger(boat.GetPassenger(i));
			boat.mPassengers[i] = NULL;
		}

		
		// friend class로 처리하는게 맞는걸까?
		mPassengerCount = 0;
		boat.mPassengerCount = 0;

		return bp;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mFlySpeed = 200 * pow(M_E, (-1 * x + 800) / 500.0);
		mFlySpeed = static_cast<unsigned int>(mFlySpeed + 0.5);

		return mFlySpeed;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mDriveSpeed = 4 * pow(M_E, (-1 * x + 400) / 70.0);
		mDriveSpeed = static_cast<unsigned int>(mDriveSpeed + 0.5);

		return mDriveSpeed;
	}

	// 수정이 필요할지도?
	unsigned int Airplane::GetMaxSpeed() const
	{
		if (mFlySpeed > mDriveSpeed)
		{
			return mFlySpeed;
		}

		return mDriveSpeed;
	}
}