#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina::DeusExMachina()
	{
	}

	DeusExMachina::~DeusExMachina()
	{
		for (size_t i = 0; i < mMachineCount; i++)
		{
			delete mMachineList[i];
		}
		delete[] mMachineList;
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusMachineCount > 0)
		{
			return mDeusMachine;
		}

		mDeusMachine = new DeusExMachina;
		mDeusMachineCount++;
		return mDeusMachine;
	}

	void DeusExMachina::Travel() const
	{
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mMachineCount < 10)
		{
			mMachineList[mMachineCount++] = vehicle;
			return true;
		}

		return false;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i < mMachineCount)
		{
			delete mMachineList[i];
			for (size_t j = i; j < mMachineCount - 1; j++)
			{
				mMachineList[i] = mMachineList[i + 1];
			}
			mMachineCount--;

			return true;
		}
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}

	unsigned int DeusExMachina::mDeusMachineCount = 0;
	DeusExMachina* DeusExMachina::mDeusMachine = NULL;
}