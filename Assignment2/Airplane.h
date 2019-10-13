#pragma once

#include "Boat.h"
#include "Boatplane.h"
#include "IDrivable.h"
#include "IFlyable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Boat;

	class Airplane : public IFlyable, public IDrivable, public Vehicle
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		Boatplane operator+(Boat& boat);

		unsigned int GetFlySpeed() const;
		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;
		void Move();

	private:
		mutable double mDriveSpeed;
		mutable double mFlySpeed;
		unsigned int mMaxPassengersNumber;
	};
}