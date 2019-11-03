#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::Boatplane(Boatplane&& other)
	{
		mMaxPassengerNumber = other.mMaxPassengerNumber;
		mPassengerCount = other.mPassengerCount;
		mPassengers = other.mPassengers;

		// �̰� �ʿ��Ѱ��� �ƴ��� �𸣰���
		for (size_t i = 0; i < mPassengerCount; i++)
		{
			other.mPassengers[i] = NULL;
		}

		other.mPassengers = NULL;
	}

	Boatplane& Boatplane::operator=(Boatplane&& other)
	{
		mMaxPassengerNumber = other.mMaxPassengerNumber;
		mPassengerCount = other.mPassengerCount;
		mPassengers = other.mPassengers;

		for (size_t i = 0; i < mPassengerCount; i++)
		{
			other.mPassengers[i] = NULL;
		}
		other.mPassengers = NULL;

		return *this;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mFlySpeed = 150.0 * exp((-1.0 * x + 500.0) / 300.0);
		mFlySpeed = static_cast<unsigned int>(round(mFlySpeed));

		return static_cast<unsigned int>(mFlySpeed);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight();
		mSailSpeed = 800.0 - 1.7 * x;
		mSailSpeed = static_cast<unsigned int>(round(mSailSpeed));

		// �ڵ� ����
		return mSailSpeed > 20 ? mSailSpeed : 20;
	}

	// ������ �ʿ�������?
	unsigned int Boatplane::GetMaxSpeed() const
	{
		// �ڵ� ����
		return GetFlySpeed() > GetSailSpeed() ? mFlySpeed : mSailSpeed;
	}

	void Boatplane::Move()
	{
		if (mMoveCount < 1)
		{
			mMoveCount++;
			mDistance += GetMaxSpeed();
			return;
		}

		if (mMoveCount == 1)
		{
			mBreakCount++;
		}

		if (mBreakCount == 3)
		{
			mMoveCount = 0;
			mBreakCount = 0;
		}
	}
}