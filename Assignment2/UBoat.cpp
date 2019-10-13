#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mDiveSpeed = 500 * static_cast<double>(log((x + 150.0) / 150.0)) + 30;
		mDiveSpeed = static_cast<unsigned int>(mDiveSpeed + 0.5);

		return static_cast<unsigned int>(mDiveSpeed);
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mSailSpeed = 550 - static_cast<double>(x / 10.0);
		mSailSpeed = static_cast<unsigned int>(mSailSpeed + 0.5);
		if (mSailSpeed > 200)
		{
			return static_cast<unsigned int>(mSailSpeed);
		}

		return 200;
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		if (GetDiveSpeed() > GetSailSpeed())
		{
			return static_cast<unsigned int>(mDiveSpeed);
		}

		return static_cast<unsigned int>(mSailSpeed);
	}

	void UBoat::Move()
	{
		if (mMoveCount < 2)
		{
			mMoveCount++;
			mDistance += GetMaxSpeed();
			return;
		}

		if (mMoveCount == 2)
		{
			mBreakCount++;
		}

		if (mBreakCount == 4)
		{
			mMoveCount = 0;
			mBreakCount = 0;
		}
	}
}