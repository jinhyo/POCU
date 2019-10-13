#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mDriveSpeed = pow((x / 15.0), 3.0) * -1 + 2 * x + 400;
		mDriveSpeed = static_cast<unsigned int>(mDriveSpeed + 0.5);

		if (mDriveSpeed > 0)
		{
			return mDriveSpeed;
		}

		return 0;
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return mDriveSpeed;
	}

	void Motorcycle::Move()
	{

	}
}