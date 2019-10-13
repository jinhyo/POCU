#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
	}

	Sedan::~Sedan()
	{
		RemoveTrailer();
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		// 트레일러를 추가한다는 건 무게만 추가하면 되는걸까?
		if (mTrailerWeight > 0)
		{
			return false;
		}

		mTrailerPointer = trailer;
		mTrailerWeight = trailer->GetWeight();

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailerWeight == 0)
		{
			return false;
		}

		mTrailerWeight = 0;
		delete mTrailerPointer;
		return true;
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight() + mTrailerWeight;

		if (x <= 80)
		{
			return 480;
		}

		else if (x > 80 && x <= 160)
		{
			return 458;
		}

		else if (x > 160 && x <= 260)
		{
			return 400;
		}

		else if (x > 260 && x <= 350)
		{
			return 380;
		}

		else if (x > 350)
		{
			return 300;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	void Sedan::Move()
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

		else if (mTrailerWeight == 0)
		{
			if (mBreakCount == 1)
			{
				mMoveCount = 0;
			}
		}

		else if (mTrailerWeight != 0)
		{
			if (mBreakCount == 2)
			{
				mMoveCount = 0;
				mBreakCount = 0;
			}
		}
	}
}