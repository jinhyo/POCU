#pragma once

#include <cmath>

#include "Vehicle.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public IDivable, public Vehicle
	{
	public:
		UBoat();
		~UBoat();

		unsigned int GetDiveSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;

	private:
		// mutable 써도 되나?
		mutable double mDiveSpeed;
		mutable double mSailSpeed;
	};
}