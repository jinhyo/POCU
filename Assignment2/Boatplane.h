#pragma once

#include "IFlyable.h"
#include "ISailable.h"
#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"


namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(Boatplane&& other);
		Boatplane& operator=(Boatplane&& other);

		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;
		void Move();

		~Boatplane();

	private:
		mutable double mFlySpeed;
		mutable double mSailSpeed;
	};
}