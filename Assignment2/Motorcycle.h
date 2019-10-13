#pragma once
#include "IDrivable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;

	private:
		mutable double mDriveSpeed;
	};
}