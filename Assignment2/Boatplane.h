#pragma once

#include "IFlyable.h"
#include "IDivable.h"
#include "Vehicle.h"


namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public IDivable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(Boatplane&& other);
		Boatplane& operator=(Boatplane&& other);

		unsigned int GetFlySpeed() const;
		unsigned int GetDiveSpeed() const;
		unsigned int GetMaxSpeed() const;
		void Move();

		~Boatplane();

	private:
		mutable double mFlySpeed;
		mutable double mDiveSpeed;
	};
}