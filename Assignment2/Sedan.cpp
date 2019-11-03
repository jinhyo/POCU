#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
	}

	// 추가 코드
	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
	{
		if (mTrailerPointer != nullptr)
		{
			mTrailerPointer = new Trailer(other.GetTrailer()->GetWeight());
		}
	}

	Sedan::~Sedan()
	{
		RemoveTrailer();
	}

	// 추가코드
	Sedan& Sedan::operator=(const Sedan& other)
	{
		if (this == &other)
		{
			return *this;
		}

		RemoveTrailer();
		mTrailerPointer = nullptr;
		if (other.GetTrailer() != nullptr)
		{
			mTrailerPointer = new Trailer(other.GetTrailer()->GetWeight());
		}

		Vehicle::operator=(other);
		return *this;
	}

	

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		// 트레일러를 추가한다는 건 무게만 추가하면 되는걸까? 
		// 그냥 포인터만 추가하고 무게는 필요할 때 가져오면 될 듯
		/*if (mTrailerPointer != nullptr)
		{
			return false;
		}*/
		//아래 코드 대신 위의 코드를 사용해도 됨

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

	const Trailer* Sedan::GetTrailer() const
	{
		return mTrailerPointer;
	}


	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight() + mTrailerWeight;

		if (x <= 80)
		{
			return 480;
		}

		if (x <= 160)
		{
			return 458;
		}

		if (x <= 260)
		{
			return 400;
		}

		if (x <= 350)
		{
			return 380;
		}

		if (x > 350)
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

	/* 이런 방식도 있음
	unsigned Sedan::GetTravelledDistance() const
	{
		unsigned distance = 0;
		for (unsigned i = 1; i <= mTravelCount; i++)
		{
			if (mTrailer == nullptr)
			{
				if (i % 6 != 0)
				{
					distance += GetMaxSpeed();
				}
			}

			else
			{
				if (i % 7 != 0 && i % 7 != 6)
				{
					distance += GetMaxSpeed();
				}
			}
		}

		return distance;
	}
	*/
}