#include "Boat.h"

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
		unsigned int bMaxNumber = GetMaxPassengersCount() + plane.GetMaxPassengersCount();
		Boatplane bp(bMaxNumber);
		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));
		}

		for (size_t i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(i));
		}

		// friend class로 처리하는게 맞는걸까?
		mPassengerCount = 0;
		plane.mPassengerCount = 0;

		return bp;
	}

	unsigned int Boat::GetDiveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		double speed = 800 - 10 * x;

		if (speed > 20)
		{
			return static_cast<unsigned int>(speed + 0.5);
		}

		return 20;
	}

	// 수정이 필요할지도?
	unsigned int Boat::GetMaxSpeed() const
	{
		return GetDiveSpeed();
	}

	void Boat::Move()
	{

	}
}