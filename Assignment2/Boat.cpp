#include "Boat.h"
#include "Airplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		// 수정
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		for (size_t i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(i));
		}

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));
		}

		// friend class로 처리하는게 맞는걸까?
		mPassengerCount = 0;
		plane.mPassengerCount = 0;

		return bp;
	}

	unsigned int Boat::GetSailSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		double speed = static_cast <double>(800 - 10.0 * x);

		if (speed > 20)
		{
			return static_cast<unsigned int>(speed + 0.5);
		}

		return 20;
	}

	// 수정이 필요할지도?
	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	void Boat::Move()
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

		if (mBreakCount == 1)
		{
			mMoveCount = 0;
			mBreakCount = 0;
		}
	}

}