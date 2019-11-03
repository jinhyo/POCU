#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned Boatplane::GetFlySpeed() const
	{
		const unsigned TOTAL_WEIGHT = GetPassengersTotalWeight();
		const double SPEED = 150.0 * exp((-1.0 * TOTAL_WEIGHT + 500.0) / 300.0);

		return static_cast<unsigned>(round(SPEED));
	}

	unsigned Boatplane::GetSailSpeed() const
	{
		const unsigned TOTAL_WEIGHT = GetPassengersTotalWeight();
		const double SPEED = 800.0 - 1.7 * TOTAL_WEIGHT;

		return SPEED > 20 ? static_cast<unsigned>(round(SPEED)) : 20;
	}

	unsigned Boatplane::GetMaxSpeed() const
	{
		const unsigned FLY_SPEED = GetFlySpeed();
		const unsigned SAIL_SPEED = GetSailSpeed();

		return FLY_SPEED > SAIL_SPEED ? FLY_SPEED : SAIL_SPEED;
	}

	unsigned Boatplane::GetTravelledDistance() const
	{
		unsigned distance = 0;		
		for (unsigned i = 1; i <= mTravelCount; i++)
		{
			if (i % 4 == 1)
			{
				distance += GetMaxSpeed();
			}
		}
		return distance;
	}
}
