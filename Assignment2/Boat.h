#pragma once

#include "Airplane.h"
#include "Boatplane.h"
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Airplane;

	class Boat : public ISailable, public Vehicle
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		Boatplane operator+(Airplane& plane);

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		void Move();

	};
}