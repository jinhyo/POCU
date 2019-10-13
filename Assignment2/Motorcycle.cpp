#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mDriveSpeed = -1.0 * static_cast<double>(pow((x / 15.0), 3.0)) + 2.0 * x + 400.0;
		mDriveSpeed = static_cast<unsigned int>(mDriveSpeed + 0.5);

		if (mDriveSpeed > 0)
		{
			return static_cast<unsigned int>(mDriveSpeed);
		}

		return 0;
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	void Motorcycle::Move()
	{
		if (mMoveCount < 5)
		{
			mMoveCount++;
			mDistance += GetMaxSpeed();
			return;
		}

		if (mMoveCount == 5)
		{
			mBreakCount++;
		}

		if (mBreakCount == 1)
		{
			mMoveCount = 0;
			mBreakCount = 0;
		}
	}
}