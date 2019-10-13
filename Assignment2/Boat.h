#pragma once

#include "Airplane.h"
#include "Boatplane.h"
#include "IFlyable.h"
#include "IDivable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Airplane;

	class Boat : public IDivable, public Vehicle
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		Boatplane operator+(Airplane& plane);

		unsigned int GetMaxSpeed() const;
		unsigned int GetDiveSpeed() const;
		void Move();

	};
}