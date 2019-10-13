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
		mDiveSpeed = 500 * static_cast<double>(log((x + 150) / 150.0)) + 30;
		mDiveSpeed = static_cast<unsigned int>(mDiveSpeed + 0.5);

		return mDiveSpeed;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mSailSpeed = 550 - x / 10;
		mSailSpeed = static_cast<unsigned int>(mSailSpeed + 0.5);
		if (mSailSpeed > 200)
		{
			return mSailSpeed;
		}

		return 200;
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		if (mDiveSpeed > mSailSpeed)
		{
			return mDiveSpeed;
		}

		return mSailSpeed;
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
		}
	}
}